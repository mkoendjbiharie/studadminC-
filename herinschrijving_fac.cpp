//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "herinschrijving_fac.h"
#include "inschrijvingenfaculteit.h"
#include "sasdm.h"
#include "main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

static int huidig_collegejaar;
THerinschrijvingfaculteitForm *HerinschrijvingfaculteitForm;
extern THoofdScherm *HoofdScherm;

//---------------------------------------------------------------------------
__fastcall THerinschrijvingfaculteitForm::THerinschrijvingfaculteitForm(TComponent* Owner)
        : TForm(Owner)
{
    CollegejaarUpDown->Thousands = 0;
}

//---------------------------------------------------------------------------
void __fastcall THerinschrijvingfaculteitForm::CloseButtonClick(
      TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall THerinschrijvingfaculteitForm::DBLookupComboBox1Click(
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

void __fastcall THerinschrijvingfaculteitForm::Button1Click(TObject *Sender)
{
    String geslachtstring;
    String qstring;
    if (DBLookupComboBox1->Text == ""||DBLookupComboBox2->Text == "")
     { Application->MessageBox("","U dient een richting te kiezen", MB_OK |MB_ICONSTOP); return;}


    switch( RadioGroup2->ItemIndex)
     {
    case 0:  geslachtstring = " AND persoon.GESLACHT = 'm' "; break;
    case 1:  geslachtstring = " AND persoon.GESLACHT = 'v' "; break;
    case 2:  geslachtstring = " "; break;
      }
    //Application->MessageBox(String(huidig_collegejaar).c_str(),String(huidig_collegejaar).c_str() ,MB_OK);
    String jaarstring;
    if (CollegejaarEdit->Text != "") jaarstring = String(" AND herinschrijving.JAAR = ") + CollegejaarEdit->Text.ToInt();
    else jaarstring = "";
    qstring = String("SELECT concat(naam,', ',voornaam) as namen,concat(straat,' ',huisnummer) as adres ,persoon.*, inschrijving.* , faculteit.FACULTEIT, studierichting.STUDIERICHTING,opleiding.opleiding, herinschrijving.STUDIENR FROM persoon INNER JOIN inschrijving on persoon.IDKAARTNR = inschrijving.IDKAARTNR INNER JOIN faculteit on inschrijving.FACULTEIT_ID = faculteit.FACULTEIT_ID INNER JOIN studierichting on inschrijving.STUDIERICHTING_ID = studierichting.RICHTING_ID inner join opleiding on opleiding.opleiding_id=persoon.opleiding_id inner join herinschrijving on herinschrijving.studienr=inschrijving.studienr WHERE inschrijving.STUDIERICHTING_ID LIKE ") + "'%" + DBLookupComboBox2->KeyValue + "%'" + jaarstring + geslachtstring +" ORDER BY NAAM ";
    //qstring = String("SELECT * FROM persoon,faculteit,inschrijving,studierichting where persoon.IDKAARTNR = inschrijving.IDKAARTNR and inschrijving.FACULTEIT_ID = faculteit.FACULTEIT_ID and inschrijving.STUDIERICHTING_ID = studierichting.RICHTING_ID ");
  sasDataModule->studentenkaartSQLDataSet->Close(); // Flush previous query
  sasDataModule->studentenkaartClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->studentenkaartSQLDataSet->CommandText=  qstring;
  sasDataModule->studentenkaartSQLDataSet->Open();
  sasDataModule->studentenkaartClientDataSet->Active=true;
  //Application->MessageBox(geslachtstring.c_str(),geslachtstring.c_str() ,MB_OK);
  //Application->MessageBox(studentenstring.c_str(),studentenstring.c_str(),MB_OK);
  //Application->MessageBox(jaarstring.c_str(),jaarstring.c_str(),MB_OK);

  inschrijvingenfaculteitreport->QuickRep1->Preview();
 // CollegejaarEdit->Clear();
}
//---------------------------------------------------------------------------

void __fastcall THerinschrijvingfaculteitForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    HoofdScherm->Herinschrijvingen1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall THerinschrijvingfaculteitForm::FormCreate(TObject *Sender)
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
  DBLookupComboBox1->Enabled = true;
  DBLookupComboBox2->Enabled = false;
  //    CollegejaarLabel ->Visible = false;
  //     CollegejaarEdit->Visible = false;
  //     CollegejaarUpDown->Visible = false;

  CollegejaarEdit->Text="";
}
//---------------------------------------------------------------------------
