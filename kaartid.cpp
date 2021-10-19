//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "kaartid.h"
#include "sasdm.h"
#include "studentenkaart.h"
#include "schakelstudentenkaart.h"

//---------------------------------------------------------------------
#pragma resource "*.dfm"
TKaartIdDlg *KaartIdDlg;
static int huidig_collegejaar;
//---------------------------------------------------------------------
__fastcall TKaartIdDlg::TKaartIdDlg(TComponent* AOwner)
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
void __fastcall TKaartIdDlg::OKBtnClick(TObject *Sender)
{
  // Eerst query maken en dan commandstring aanpassen en dataset openen
 if (SoortReport == "Faculteit")
   {

  String qstring = String("SELECT concat(straat,' ',huisnummer) as adres,persoon.*, inschrijving.*,faculteit.*,studierichting.* from persoon INNER JOIN inschrijving  on persoon.IDKAARTNR = inschrijving.IDKAARTNR INNER JOIN faculteit on inschrijving.FACULTEIT_ID = faculteit.FACULTEIT_ID INNER JOIN studierichting on inschrijving.STUDIERICHTING_ID = studierichting.RICHTING_ID WHERE IsNull(inschrijving.AFSCHRIJVINGSDATUM) AND IsNull(inschrijving.AFSTUDEERDATUM) AND persoon.IDKAARTNR like ") + "'" + KaartIdDlg->IdnummerEdit->Text + "%'" ;

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
  String qstring = String("SELECT concat(straat,' ',huisnummer) as adres,persoon.*, schakel.*,studierichting.* from persoon INNER JOIN schakel  on persoon.IDKAARTNR = schakel.IDKAARTNR  INNER JOIN studierichting on schakel.STUDIERICHTING_ID = studierichting.RICHTING_ID WHERE IsNull(schakel.AFSCHRIJVINGSDATUM) AND schakel.afgerond = '0' AND persoon.IDKAARTNR like ") + "'" + KaartIdDlg->IdnummerEdit->Text + "%'" ;

  sasDataModule->studentenkaartSQLDataSet->Close(); // Flush previous query
  sasDataModule->studentenkaartClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->studentenkaartSQLDataSet->CommandText=  qstring;
  sasDataModule->studentenkaartSQLDataSet->Open();
  sasDataModule->studentenkaartClientDataSet->Active=true;
 // Application->MessageBox("", sasDataModule->personSQLDataSet->CommandText.c_str(),MB_OK);
  schakelstudentenkaartenreport->huidig_collegejaar = huidig_collegejaar;
  schakelstudentenkaartenreport->Show();
  schakelstudentenkaartenreport->QuickRep1->Preview();
     }
}
//---------------------------------------------------------------------------

void __fastcall TKaartIdDlg::CancelBtnClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TKaartIdDlg::UpDown1ChangingEx(TObject *Sender,
      bool &AllowChange, short NewValue, TUpDownDirection Direction)
{
  huidig_collegejaar = NewValue;
  CollegejaarLabel->Caption = String(NewValue) + "/" + String(NewValue + 1);
}
//---------------------------------------------------------------------------

void __fastcall TKaartIdDlg::FormShow(TObject *Sender)
{
   if (KaartIdDlg->SoortReport == "Faculteit")
     KaartIdDlg->Caption = "Faculteit studentenkaart op idnummer";
   else
     KaartIdDlg->Caption = "Schakel studentenkaart op idnummer";
   UpDown1->Max = huidig_collegejaar;
}
//---------------------------------------------------------------------------

