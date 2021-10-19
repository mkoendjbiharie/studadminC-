//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "afschrijving_fac.h"
#include "inschrijvingenfaculteit.h"
#include "sasdm.h"
#include "sasbasictablesmod.h"
#include "main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAfschrijvingfaculteitForm *AfschrijvingfaculteitForm;
extern THoofdScherm *HoofdScherm;
static int huidig_collegejaar;
extern String categorie;
//---------------------------------------------------------------------------
__fastcall TAfschrijvingfaculteitForm::TAfschrijvingfaculteitForm(TComponent* Owner)
        : TForm(Owner)
{
  CollegejaarUpDown->Thousands = 0;
  huidig_collegejaar =  CurrentYear();
  if (categorie == "afschrijvingen")
    {
       Caption = "Afschrijvingen";
       BevolkingsgroepLabel->Visible = false;
       BevolkingsgroepDBLookupComboBox->Visible = false;
       NationaliteitLabel->Visible = false;
       NationaliteitDBLookupComboBox->Visible = false;
       VooropleidingLabel->Visible = false;
       VooropleidingDBLookupComboBox->Visible = false;
       DiplomaLabel->Visible = false;
       DiplomaDBLookupComboBox->Visible = false;
    }
  else if (categorie == "bevolkingsgroep")
     {
       Caption = "Bevolkingsgroep";
       BevolkingsgroepLabel->Visible = true;
       BevolkingsgroepDBLookupComboBox->Visible = true;
       NationaliteitLabel->Visible = false;
       NationaliteitDBLookupComboBox->Visible = false;
       VooropleidingLabel->Visible = false;
       VooropleidingDBLookupComboBox->Visible = false;
       DiplomaLabel->Visible = false;
       DiplomaDBLookupComboBox->Visible = false;
    }
  else if (categorie == "nationaliteit")
    {
       Caption = "Nationaliteit";
       BevolkingsgroepLabel->Visible = false;
       BevolkingsgroepDBLookupComboBox->Visible = false;
       NationaliteitLabel->Visible = true;
       NationaliteitDBLookupComboBox->Visible = true;
       VooropleidingLabel->Visible = false;
       VooropleidingDBLookupComboBox->Visible = false;
       DiplomaLabel->Visible = false;
       DiplomaDBLookupComboBox->Visible = false;
    }
  else if (categorie == "diploma")
    {
       Caption = "Diploma";
       BevolkingsgroepLabel->Visible = false;
       BevolkingsgroepDBLookupComboBox->Visible = false;
       NationaliteitLabel->Visible = false;
       NationaliteitDBLookupComboBox->Visible = false;
       VooropleidingLabel->Visible = false;
       VooropleidingDBLookupComboBox->Visible = false;
       DiplomaLabel->Visible = true;
       DiplomaDBLookupComboBox->Visible = true;
    }
  else if (categorie == "vooropleiding")
    {
       Caption = "Vooropleiding";
       BevolkingsgroepLabel->Visible = false;
       BevolkingsgroepDBLookupComboBox->Visible = false;
       NationaliteitLabel->Visible = false;
       NationaliteitDBLookupComboBox->Visible = false;
       VooropleidingLabel->Visible = true;
       VooropleidingDBLookupComboBox->Visible = true;
       DiplomaLabel->Visible = false;
       DiplomaDBLookupComboBox->Visible = false;
    }

  SasBasicTables->ethnicSQLDataSet->Active = true;
  SasBasicTables->ethnicClientDataSet->Active=true;
  SasBasicTables->nationalitySQLDataSet->Active = true;
  SasBasicTables->nationalityClientDataSet->Active=true;
  SasBasicTables->eduSQLDataSet->Active = true;
  SasBasicTables->eduClientDataSet->Active=true;
  SasBasicTables->prevEduSQLDataSet->Active = true;
  SasBasicTables->prevEduClientDataSet->Active=true;
  sasDataModule->diplomaSQLDataSet->Active = true;
  sasDataModule->diplomaClientDataSet->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TAfschrijvingfaculteitForm::CloseButtonClick(
      TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TAfschrijvingfaculteitForm::DBLookupComboBox1Click(
      TObject *Sender)
{    char dummy[5];
    int faculteit = DBLookupComboBox1->KeyValue;
    DBLookupComboBox2->Enabled = true;
  //  Application->MessageBox("",itoa(faculteit,dummy,10), MB_OK);
    sasDataModule->StudierichtingSQLDataSet->Close();
    sasDataModule->StudierichtingClientDataSet->Active = false;
    sasDataModule->StudierichtingSQLDataSet->CommandText  = String("SELECT * FROM studierichting WHERE FACULTEIT_ID = ") + "'" + String(faculteit) +"'";
    sasDataModule->StudierichtingSQLDataSet->Open();
    sasDataModule->StudierichtingClientDataSet->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TAfschrijvingfaculteitForm::Button1Click(TObject *Sender)
{
    if  ((Caption == "Bevolkingsgroep") && (BevolkingsgroepDBLookupComboBox->Text == ""))
      {Application->MessageBox("U heeft geen bevolkingsgroep gekozen","", MB_OK|MB_ICONWARNING);
       return;}
    else if  ((Caption == "Nationaliteit")&& (NationaliteitDBLookupComboBox->Text == ""))
      {Application->MessageBox("U heeft geen nationaliteit gekozen","", MB_OK|MB_ICONWARNING);
      return;}
    else if  ((Caption == "Diploma")&& (DiplomaDBLookupComboBox->Text == ""))
      {Application->MessageBox("U heeft geen diploma gekozen","", MB_OK|MB_ICONWARNING);
      return;}
    else if  ((Caption == "Vooropleiding")&& (VooropleidingDBLookupComboBox->Text == ""))
      {Application->MessageBox("U heeft geen vooropleiding gekozen","", MB_OK|MB_ICONWARNING);
      return;}

    String geslachtstring, categoriestring, categoriestring1;
    String qstring;
//  if (DBLookupComboBox1->Text == ""||DBLookupComboBox2->Text == "")
//     { Application->MessageBox("","U dient een richting te kiezen", MB_OK |MB_ICONSTOP); return;}

    switch( RadioGroup2->ItemIndex)
     {
    case 0:  geslachtstring = " AND persoon.GESLACHT = 'm' "; break;
    case 1:  geslachtstring = " AND persoon.GESLACHT = 'v' "; break;
    case 2:  geslachtstring = " "; break;
      }
    //Application->MessageBox(String(huidig_collegejaar).c_str(),String(huidig_collegejaar).c_str() ,MB_OK);
    String jaarstring, jaarstring1;
    if (CollegejaarEdit->Text != "")
        {
          jaarstring = String(" AND inschrijving.INSCHRIJFJAAR = ") + CollegejaarEdit->Text.ToInt();
          jaarstring1 = String(" inschrijving.INSCHRIJFJAAR = ") + CollegejaarEdit->Text.ToInt();
          if (categorie == "afschrijvingen")
          {
            categoriestring =String(" AND inschrijving.AFSCHRIJVINGSDATUM <> 'NULL'");
            categoriestring1 =String(" AND inschrijving.AFSCHRIJVINGSDATUM <> 'NULL'");
          }
         else if (categorie == "bevolkingsgroep")
          {
            categoriestring =String(" AND persoon.BEV_ID = ") + BevolkingsgroepDBLookupComboBox->KeyValue;
            categoriestring1 =String(" AND persoon.BEV_ID = ") + BevolkingsgroepDBLookupComboBox->KeyValue;
          }
         else if (categorie == "nationaliteit")
          {
            categoriestring =String(" AND persoon.NATIO_ID = ") + NationaliteitDBLookupComboBox->KeyValue;
            categoriestring1 =String(" AND persoon.NATIO_ID = ") + NationaliteitDBLookupComboBox->KeyValue;
          }
         else if (categorie == "diploma")
          {
            categoriestring =String(" AND studentcertificaat.CERTIFICAAT_ID = ") + DiplomaDBLookupComboBox->KeyValue;
            categoriestring1 =String(" AND studentcertificaat.CERTIFICAAT_ID = ") + DiplomaDBLookupComboBox->KeyValue;
          }
         else if (categorie == "vooropleiding")
          {
            categoriestring =String(" AND persoon.OPLEIDING_ID = ") + VooropleidingDBLookupComboBox->KeyValue;
            categoriestring1 =String(" AND persoon.OPLEIDING_ID = ") + VooropleidingDBLookupComboBox->KeyValue;
          }



         }
    else
        {
           jaarstring = "";
           jaarstring1 = "";
           if (categorie == "afschrijvingen")
            {
             categoriestring =String(" AND inschrijving.AFSCHRIJVINGSDATUM <> 'NULL'");
             categoriestring1 =String(" inschrijving.AFSCHRIJVINGSDATUM <> 'NULL'");
            }
         else if (categorie == "bevolkingsgroep")
          {
            categoriestring =String(" AND persoon.BEV_ID = ") + BevolkingsgroepDBLookupComboBox->KeyValue;
            categoriestring1 =String(" persoon.BEV_ID = ") + BevolkingsgroepDBLookupComboBox->KeyValue;
          }
         else if (categorie == "nationaliteit")
          {
            categoriestring =String(" AND persoon.NATIO_ID = ") + NationaliteitDBLookupComboBox->KeyValue;
            categoriestring1 =String(" persoon.NATIO_ID = ") + NationaliteitDBLookupComboBox->KeyValue;
          }
         else if (categorie == "diploma")
          {
            categoriestring =String(" AND studentcertificaat.CERTIFICAAT_ID = ") + DiplomaDBLookupComboBox->KeyValue;
            categoriestring1 =String(" studentcertificaat.CERTIFICAAT_ID = ") + DiplomaDBLookupComboBox->KeyValue;
          }
         else if (categorie == "vooropleiding")
          {
            categoriestring =String(" AND persoon.OPLEIDING_ID = ") + VooropleidingDBLookupComboBox->KeyValue;
            categoriestring1 =String(" persoon.OPLEIDING_ID = ") + VooropleidingDBLookupComboBox->KeyValue;
          }
        }
      //INNER JOIN certificaat on studentcertificaat.CERTIFICAAT_ID = certificaat.CERTIFICAAT_ID
     if (StudierichtingRadioGroup->ItemIndex == 0)
       qstring = String("SELECT concat(naam,', ',voornaam) as namen,concat(straat,' ',huisnummer) as adres ,persoon.*, inschrijving.* , faculteit.FACULTEIT, studierichting.STUDIERICHTING,opleiding.opleiding, studentcertificaat.STUDIENR FROM persoon LEFT JOIN inschrijving on persoon.IDKAARTNR = inschrijving.IDKAARTNR  LEFT JOIN faculteit on inschrijving.FACULTEIT_ID = faculteit.FACULTEIT_ID LEFT JOIN studierichting on inschrijving.STUDIERICHTING_ID = studierichting.RICHTING_ID LEFT JOIN studentcertificaat on inschrijving.STUDIENR = studentcertificaat.STUDIENR LEFT join opleiding on opleiding.opleiding_id=persoon.opleiding_id WHERE inschrijving.STUDIERICHTING_ID LIKE ") + "'%" + DBLookupComboBox2->KeyValue + "%'" + jaarstring + categoriestring + geslachtstring +" ORDER BY NAAM ";
     else
       qstring = String("SELECT concat(naam,', ',voornaam) as namen,concat(straat,' ',huisnummer) as adres ,persoon.*, inschrijving.* , faculteit.FACULTEIT, studierichting.STUDIERICHTING,opleiding.opleiding, studentcertificaat.STUDIENR FROM persoon LEFT JOIN inschrijving on persoon.IDKAARTNR = inschrijving.IDKAARTNR  LEFT JOIN faculteit on inschrijving.FACULTEIT_ID = faculteit.FACULTEIT_ID LEFT JOIN studierichting on inschrijving.STUDIERICHTING_ID=studierichting.RICHTING_ID LEFT JOIN studentcertificaat on inschrijving.STUDIENR = studentcertificaat.STUDIENR LEFT join opleiding on opleiding.opleiding_id=persoon.opleiding_id WHERE ")  + jaarstring1 + categoriestring1 + geslachtstring +" ORDER BY NAAM ";

   Application->MessageBox(qstring.c_str(), categoriestring.c_str() ,MB_OK);

    //qstring = String("SELECT * FROM persoon,faculteit,inschrijving,studierichting where persoon.IDKAARTNR = inschrijving.IDKAARTNR and inschrijving.FACULTEIT_ID = faculteit.FACULTEIT_ID and inschrijving.STUDIERICHTING_ID = studierichting.RICHTING_ID ");
  sasDataModule->studentenkaartSQLDataSet->Close(); // Flush previous query
  sasDataModule->studentenkaartClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->studentenkaartSQLDataSet->CommandText=  qstring;
  sasDataModule->studentenkaartSQLDataSet->Open();
  sasDataModule->studentenkaartClientDataSet->Active=true;
  //Application->MessageBox(studentenstring.c_str(),studentenstring.c_str(),MB_OK);
  //Application->MessageBox(jaarstring.c_str(),jaarstring.c_str(),MB_OK);

  inschrijvingenfaculteitreport->QuickRep1->Preview();
 // CollegejaarEdit->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TAfschrijvingfaculteitForm::RadioGroup1Click(
      TObject *Sender)
{
    if (RadioGroup1->ItemIndex == 0)
     { CollegejaarLabel ->Visible = true;
       CollegejaarEdit->Visible = true;
       CollegejaarEdit->Text=huidig_collegejaar;
    // char buf[10];
    // CollegejaarEdit->Text = itoa(huidig_collegejaar, buf  , 10);

       CollegejaarUpDown->Visible = true;
      }
      else
     { CollegejaarLabel ->Visible = false;
       CollegejaarEdit->Visible = false;
  //    char buf[10];
 // CollegejaarEdit->Text = itoa(huidig_collegejaar, buf  , 10);

       CollegejaarEdit->Text="";
       CollegejaarUpDown->Visible = false;
      }
}
//---------------------------------------------------------------------------

void __fastcall TAfschrijvingfaculteitForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  if (Caption == "Afschrijvingen")
     HoofdScherm->Afschrijvingen1->Checked = false;
  else if  (Caption == "Bevolkingsgroep")
     HoofdScherm->Bevolkingsgroep2->Checked = false;
  else if  (Caption == "Nationaliteit")
     HoofdScherm->Nationaliteit2->Checked = false;
  else if  (Caption == "Diploma")
     HoofdScherm->Diploma1->Checked = false;
  else if  (Caption == "Vooropleiding")
     HoofdScherm->Vooropleiding2->Checked = false;
  HoofdScherm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TAfschrijvingfaculteitForm::FormCreate(TObject *Sender)
{
  String jr = CurrentYear();
  TDateTime datum = Now();
  unsigned short jar, mnd, dag;
  datum.DecodeDate(&jar, &mnd, &dag);

  huidig_collegejaar = atoi(jr.c_str());
  if (mnd < 9) huidig_collegejaar--;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;

  sasDataModule->personSQLDataSet->Active = true;
  sasDataModule->FaculteitSQLDataSet->Active = true;
  sasDataModule->personClientDataSet->Active = true;
  sasDataModule->FaculteitClientDataSet->Active = true;

  DBLookupComboBox2->Enabled = false;
  CollegejaarLabel ->Visible = false;
  CollegejaarEdit->Visible = false;
  CollegejaarUpDown->Visible = false;
  CollegejaarEdit->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TAfschrijvingfaculteitForm::StudierichtingRadioGroupClick(
      TObject *Sender)
{
    if (StudierichtingRadioGroup->ItemIndex == 0)
     {
       FaculteitLabel->Visible = true;
       SudierichtingLabel->Visible = true;
       DBLookupComboBox1->Visible = true;
       DBLookupComboBox2->Visible = true;
      }
      else
     {
        FaculteitLabel->Visible = false;
        SudierichtingLabel->Visible = false;
        DBLookupComboBox1->Visible = false;
        DBLookupComboBox2->Visible = false;
      }
}
//---------------------------------------------------------------------------

