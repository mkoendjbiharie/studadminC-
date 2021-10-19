//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "inschrijving_fac.h"
#include "inschrijvingenfaculteit.h"
#include "studentenkaart.h"
#include "sasdm.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TInschrijvingfaculteitForm *InschrijvingfaculteitForm;
extern THoofdScherm *HoofdScherm;
static int huidig_collegejaar;
//---------------------------------------------------------------------------
__fastcall TInschrijvingfaculteitForm::TInschrijvingfaculteitForm(TComponent* Owner)
        : TForm(Owner)
{
  CollegejaarUpDown->Thousands = 0;
}
//---------------------------------------------------------------------------
void __fastcall TInschrijvingfaculteitForm::CloseButtonClick(
      TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TInschrijvingfaculteitForm::DBLookupComboBox1Click(
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

void __fastcall TInschrijvingfaculteitForm::Button1Click(TObject *Sender)
{
    String geslachtstring, studentenstring;
    String qstring;
    if (DBLookupComboBox1->Text == ""||DBLookupComboBox2->Text == "")
     { Application->MessageBox("","U dient een richting te kiezen", MB_OK |MB_ICONSTOP); return;}
    switch( RadioGroup1->ItemIndex)
     {
    case 0: studentenstring = String(" AND inschrijving.INSCHRIJFJAAR <> ") + String(huidig_collegejaar) ; break;
    case 1: studentenstring = String(" AND inschrijving.INSCHRIJFJAAR = ") + String(huidig_collegejaar) ; break;
    case 2: studentenstring = " ";break;
      }

    switch( RadioGroup2->ItemIndex)
     {
    case 0:  geslachtstring = " AND persoon.GESLACHT = 'm' "; break;
    case 1:  geslachtstring = " AND persoon.GESLACHT = 'v' "; break;
    case 2:  geslachtstring = " "; break;
      }
    //Application->MessageBox(String(huidig_collegejaar).c_str(),String(huidig_collegejaar).c_str() ,MB_OK);
    String jaarstring;
    if (CollegejaarEdit->Text != "") jaarstring = String(" AND inschrijving.INSCHRIJFJAAR = ") + CollegejaarEdit->Text.ToInt();
    else jaarstring = "";
    qstring = String("SELECT concat(naam,', ',voornaam) as namen,concat(straat,' ',huisnummer) as adres ,persoon.*, inschrijving.* , faculteit.FACULTEIT, studierichting.STUDIERICHTING,opleiding.opleiding FROM persoon INNER JOIN inschrijving on persoon.IDKAARTNR = inschrijving.IDKAARTNR INNER JOIN faculteit on inschrijving.FACULTEIT_ID = faculteit.FACULTEIT_ID INNER JOIN studierichting on inschrijving.STUDIERICHTING_ID = studierichting.RICHTING_ID inner join opleiding on opleiding.opleiding_id=persoon.opleiding_id WHERE inschrijving.STUDIERICHTING_ID LIKE ") + "'%" + DBLookupComboBox2->KeyValue + "%'" + jaarstring + studentenstring + geslachtstring +" ORDER BY NAAM ";
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

void __fastcall TInschrijvingfaculteitForm::RadioGroup1Click(
      TObject *Sender)
{
    if (RadioGroup1->ItemIndex == 0)
     { CollegejaarLabel ->Visible = true;
       CollegejaarEdit->Visible = true;
       CollegejaarEdit->Text=huidig_collegejaar;
 //      char buf[10];
  //     CollegejaarEdit->Text = itoa(huidig_collegejaar, buf  , 10);

       CollegejaarUpDown->Visible = true;
      }
      else
     { CollegejaarLabel ->Visible = false;
       CollegejaarEdit->Visible = false;
        char buf[10];
 // CollegejaarEdit->Text = itoa(huidig_collegejaar, buf  , 10);

       CollegejaarEdit->Text="";
       CollegejaarUpDown->Visible = false;
      }
}
//-------------------------------------------------------------------------

void __fastcall TInschrijvingfaculteitForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    HoofdScherm->Inschrijvingen1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TInschrijvingfaculteitForm::FormCreate(TObject *Sender)
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
      CollegejaarLabel ->Visible = false;
       CollegejaarEdit->Visible = false;
       CollegejaarUpDown->Visible = false;

  CollegejaarEdit->Text="";
}
//---------------------------------------------------------------------------

