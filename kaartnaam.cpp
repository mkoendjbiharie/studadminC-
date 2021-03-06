//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "kaartnaam.h"
#include "Unit1.h"
#include "sasdm.h"
#include "studentenkaart.h"
#include "schakelstudentenkaart.h"
#include "Main.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TKaartNaamDlg *KaartNaamDlg;
static int huidig_collegejaar;
//---------------------------------------------------------------------
__fastcall TKaartNaamDlg::TKaartNaamDlg(TComponent* AOwner)
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
void __fastcall TKaartNaamDlg::CancelBtnClick(TObject *Sender)
{
  Close();
}

//---------------------------------------------------------------------
void __fastcall TKaartNaamDlg::OKBtnClick(TObject *Sender)
{
  if (SoortReport == "Faculteit")
   {
   // Eerst query maken en dan commandstring aanpassen en dataset openen
  String qstring = String("SELECT concat(naam,', ',voornaam) as namen,concat(straat,' ',huisnummer) as adres, persoon.*, inschrijving.*, faculteit.*, studierichting.* from persoon INNER JOIN inschrijving on persoon.IDKAARTNR = inschrijving.IDKAARTNR INNER JOIN faculteit on inschrijving.FACULTEIT_ID = faculteit.FACULTEIT_ID INNER JOIN studierichting on inschrijving.STUDIERICHTING_ID = studierichting.RICHTING_ID WHERE naam like ") + "\"" + KaartNaamDlg->NaamEdit->Text +"%" + "\"";
 //String qstring = String("SELECT concat(naam,', ',voornaam) as namen,concat(straat,' ',huisnummer) as adres ,persoon.*, inschrijving.* , faculteit.FACULTEIT, studierichting.STUDIERICHTING from persoon ") +  " INNER JOIN inschrijving  on persoon.IDKAARTNR = inschrijving.IDKAARTNR INNER JOIN faculteit on inschrijving.FACULTEIT_ID = faculteit.FACULTEIT_ID INNER JOIN studierichting on inschrijving.STUDIERICHTING_ID = studierichting.RICHTING_ID WHERE inschrijving.STUDIERICHTING_ID like " + "\"" + KaartRichtingDlg->RichtingComboBox->KeyValue + "%" + "\"" + categoriestring +" ORDER BY NAAM" ;

  sasDataModule->studentenkaartSQLDataSet->Close(); // Flush previous query
  sasDataModule->studentenkaartClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->studentenkaartSQLDataSet->CommandText=  qstring;
  sasDataModule->studentenkaartSQLDataSet->Open();
  sasDataModule->studentenkaartClientDataSet->Active=true;
 // Application->MessageBox("", sasDataModule->personSQLDataSet->CommandText.c_str(),MB_OK);
   studentenkaartenreport->huidig_collegejaar = huidig_collegejaar;
  studentenkaartenreport->Show();
  studentenkaartenreport->QuickRep1->Preview();
   }
  else
   {
     // Eerst query maken en dan commandstring aanpassen en dataset openen
  String qstring = String("SELECT concat(naam,', ',voornaam) as namen,concat(straat,' ',huisnummer) as adres, persoon.*, schakel.* from persoon INNER JOIN schakel on persoon.IDKAARTNR = schakel.IDKAARTNR  WHERE naam like ") + "\"" + KaartNaamDlg->NaamEdit->Text +"%" + "\"";
 //String qstring = String("SELECT concat(naam,', ',voornaam) as namen,concat(straat,' ',huisnummer) as adres ,persoon.*, inschrijving.* , faculteit.FACULTEIT, studierichting.STUDIERICHTING from persoon ") +  " INNER JOIN inschrijving  on persoon.IDKAARTNR = inschrijving.IDKAARTNR INNER JOIN faculteit on inschrijving.FACULTEIT_ID = faculteit.FACULTEIT_ID INNER JOIN studierichting on inschrijving.STUDIERICHTING_ID = studierichting.RICHTING_ID WHERE inschrijving.STUDIERICHTING_ID like " + "\"" + KaartRichtingDlg->RichtingComboBox->KeyValue + "%" + "\"" + categoriestring +" ORDER BY NAAM" ;

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
//---------------------------------------------------------------------------

void __fastcall TKaartNaamDlg::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   HoofdScherm->Opnaam1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TKaartNaamDlg::UpDown1ChangingEx(TObject *Sender,
      bool &AllowChange, short NewValue, TUpDownDirection Direction)
{
  huidig_collegejaar = NewValue;
  CollegejaarLabel->Caption = String(NewValue) + "/" + String(NewValue + 1);
}
//---------------------------------------------------------------------------

void __fastcall TKaartNaamDlg::FormShow(TObject *Sender)
{
  if (KaartNaamDlg->SoortReport == "Faculteit")
     KaartNaamDlg->Caption = "Faculteit studentenkaart op naam";
   else
     KaartNaamDlg->Caption = "Schakel studentenkaart op naam";
   UpDown1->Max = huidig_collegejaar;
}
//---------------------------------------------------------------------------

