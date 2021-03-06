//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "kaartrichting.h"
#include "sasdm.h"
#include "studentenkaart.h"
#include "schakelstudentenkaart.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
static int huidig_collegejaar;
TKaartRichtingDlg *KaartRichtingDlg;
//---------------------------------------------------------------------
__fastcall TKaartRichtingDlg::TKaartRichtingDlg(TComponent* AOwner)
	: TForm(AOwner)
{
    String jr = CurrentYear();
    TDateTime datum = Now();
    unsigned short jar, mnd, dag;
    datum.DecodeDate(&jar, &mnd, &dag);
    huidig_collegejaar = atoi(jr.c_str());
    if (mnd < 9)
    {
        huidig_collegejaar--;
    }
    UpDown1->Position = huidig_collegejaar;
    CollegejaarLabel->Caption = String(huidig_collegejaar) + "/" + String(huidig_collegejaar + 1);

}
//---------------------------------------------------------------------
void __fastcall TKaartRichtingDlg::CancelBtnClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TKaartRichtingDlg::OKBtnClick(TObject *Sender)
{

  String categoriestring;
  if (RichtingComboBox->Text == "")
            Application->MessageBox("","U dient een studierichting te kiezen",MB_OK|MB_ICONSTOP);
  else
   {

 if (SoortReport == "Faculteit")
   {
    switch (CategorieRadioGroup->ItemIndex )
  {
   case 0: categoriestring = String(" AND inschrijving.INSCHRIJFJAAR = ")   + InschrijfjaarEdit->Text;  break;
   case 1: categoriestring = String(" AND inschrijving.INSCHRIJFJAAR = ")  + "\'" + String(huidig_collegejaar) + "\'" ;  break;
   case 2: categoriestring = "";  break;
  }
   // Eerst query maken en dan commandstring aanpassen en dataset openen

  String qstring = String("SELECT concat(naam,', ',voornaam) as namen,concat(straat,' ',huisnummer) as adres ,persoon.*, inschrijving.* , faculteit.FACULTEIT, studierichting.STUDIERICHTING from persoon ") +  " INNER JOIN inschrijving  on persoon.IDKAARTNR = inschrijving.IDKAARTNR INNER JOIN faculteit on inschrijving.FACULTEIT_ID = faculteit.FACULTEIT_ID INNER JOIN studierichting on inschrijving.STUDIERICHTING_ID = studierichting.RICHTING_ID WHERE inschrijving.STUDIERICHTING_ID like " + "\"" + KaartRichtingDlg->RichtingComboBox->KeyValue + "%" + "\"" + categoriestring +" ORDER BY NAAM" ;

  sasDataModule->studentenkaartSQLDataSet->Close(); // Flush previous query
  sasDataModule->studentenkaartClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->studentenkaartSQLDataSet->CommandText=  qstring;
  sasDataModule->studentenkaartSQLDataSet->Open();
  sasDataModule->studentenkaartClientDataSet->Active=true;
  //Application->MessageBox("", sasDataModule->studentenkaartSQLDataSet->CommandText.c_str(),MB_OK);
   studentenkaartenreport->huidig_collegejaar = huidig_collegejaar;
  studentenkaartenreport->Show();
  studentenkaartenreport->QuickRep1->Preview();
   }
  else
    {
     switch (CategorieRadioGroup->ItemIndex )
  {
   case 0: categoriestring = String(" AND schakel.SCHAKELJAAR = ")   + InschrijfjaarEdit->Text;  break;
   case 1: categoriestring = String(" AND schakel.SCHAKELJAAR = ")  + "\'" + String(huidig_collegejaar) + "\'" ;  break;
   case 2: categoriestring = "";  break;
  }
     // Eerst query maken en dan commandstring aanpassen en dataset openen
  String qstring = String("SELECT concat(naam,', ',voornaam) as namen,concat(straat,' ',huisnummer) as adres ,persoon.*, schakel.* , studierichting.STUDIERICHTING from persoon ") +  " INNER JOIN schakel  on persoon.IDKAARTNR = schakel.IDKAARTNR INNER JOIN studierichting on schakel.STUDIERICHTING_ID = studierichting.RICHTING_ID WHERE schakel.STUDIERICHTING_ID like " + "\"" + KaartRichtingDlg->RichtingComboBox->KeyValue + "%" + "\"" + categoriestring +" ORDER BY NAAM" ;

 // String qstring = String("SELECT concat(naam,', ',voornaam) as namen,concat(straat,' ',huisnummer) as adres, persoon.*, schakel.* from persoon INNER JOIN schakel on persoon.IDKAARTNR = schakel.IDKAARTNR  WHERE naam like ") + "\"" + KaartNaamDlg->NaamEdit->Text +"%" + "\"";

  sasDataModule->studentenkaartSQLDataSet->Close(); // Flush previous query
  sasDataModule->studentenkaartClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->studentenkaartSQLDataSet->CommandText=  qstring;
  sasDataModule->studentenkaartSQLDataSet->Open();
  sasDataModule->studentenkaartClientDataSet->Active=true;
  schakelstudentenkaartenreport->huidig_collegejaar = huidig_collegejaar;
  schakelstudentenkaartenreport->Show();
  schakelstudentenkaartenreport->QuickRep1->Preview();
  }
  }
}
//---------------------------------------------------------------------------

void __fastcall TKaartRichtingDlg::FormActivate(TObject *Sender)
{
    sasDataModule->StudierichtingSQLDataSet->Close();
    sasDataModule->StudierichtingClientDataSet->Active = false;
    sasDataModule->StudierichtingSQLDataSet->CommandText  = String("SELECT * FROM studierichting");
    sasDataModule->StudierichtingSQLDataSet->Open();
    sasDataModule->StudierichtingClientDataSet->Active = true;
    UpDown1->Max = huidig_collegejaar;
}
//---------------------------------------------------------------------------

void __fastcall TKaartRichtingDlg::CategorieRadioGroupClick(
      TObject *Sender)
{
   if (CategorieRadioGroup->ItemIndex == 0)
     {
       InschrijfjaarLabel ->Visible = true;
       InschrijfjaarEdit->Visible = true;
       Label5->Enabled = true;
       CollegejaarLabel->Enabled = true;
       UpDown1->Enabled = true;
     }
   else
    {
       InschrijfjaarLabel ->Visible = false;
       InschrijfjaarEdit->Visible = false;

       String jr = CurrentYear();
       TDateTime datum = Now();
       unsigned short jar, mnd, dag;
       datum.DecodeDate(&jar, &mnd, &dag);
       huidig_collegejaar = atoi(jr.c_str());
       if (mnd < 9)
        {
           huidig_collegejaar--;
        }
       UpDown1->Position = huidig_collegejaar;
       CollegejaarLabel->Caption = String(huidig_collegejaar) + "/" + String(huidig_collegejaar + 1);


       Label5->Enabled = false;
       CollegejaarLabel->Enabled = false;
       UpDown1->Enabled = false;
     }
}
//---------------------------------------------------------------------------

void __fastcall TKaartRichtingDlg::UpDown1ChangingEx(TObject *Sender,
      bool &AllowChange, short NewValue, TUpDownDirection Direction)
{
  huidig_collegejaar = NewValue;
  CollegejaarLabel->Caption = String(NewValue) + "/" + String(NewValue + 1);
}
//---------------------------------------------------------------------------

void __fastcall TKaartRichtingDlg::FormShow(TObject *Sender)
{
  if (KaartRichtingDlg->SoortReport == "Faculteit")
     KaartRichtingDlg->Caption = "Faculteit studentenkaart op studierichting";
   else
     KaartRichtingDlg->Caption = "Schakel studentenkaart op studierichting";
   UpDown1->Max = huidig_collegejaar;
}
//---------------------------------------------------------------------------

