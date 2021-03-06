//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "kaartbatch.h"
#include "sasdm.h"
#include "studentenkaart.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TKaartBatchDlg *KaartBatchDlg;
String idnummerstring;
static int huidig_collegejaar;
//---------------------------------------------------------------------
__fastcall TKaartBatchDlg::TKaartBatchDlg(TComponent* AOwner)
	: TForm(AOwner)
{
    idnummerstring = "";
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


 //  sasDataModule->InschrijvingSQLDataSet->CommandText = "select * from inschrijving ";
 //  sasDataModule->InschrijvingSQLDataSet->Active = true;
  // sasDataModule->InschrijvingClientDataSet->Active = true;
}
//---------------------------------------------------------------------
void __fastcall TKaartBatchDlg::OKBtnClick(TObject *Sender)
{
  int i;
  for (i = 0; i < BatchListBox->Items->Count - 1; i++)
     {
       idnummerstring +=  "'";
       idnummerstring += BatchListBox->Items->Strings[i];
       idnummerstring += "'";
       idnummerstring += ",";
     }
   if (BatchListBox->Items->Count > 0)
    {
      idnummerstring +=   "'";
      idnummerstring += BatchListBox->Items->Strings[i];
      idnummerstring += "\'";
    }

  if (idnummerstring != "")
   {
     if (SoortReport == "Faculteit")
      {
        String qstring = String("SELECT concat(straat,' ',huisnummer) as adres,persoon.*, inschrijving.*,faculteit.*,studierichting.* from persoon INNER JOIN inschrijving  on persoon.IDKAARTNR = inschrijving.IDKAARTNR INNER JOIN faculteit on inschrijving.FACULTEIT_ID = faculteit.FACULTEIT_ID INNER JOIN studierichting on inschrijving.STUDIERICHTING_ID = studierichting.RICHTING_ID WHERE IsNull(inschrijving.AFSCHRIJVINGSDATUM) AND IsNull(inschrijving.AFSTUDEERDATUM) AND persoon.IDKAARTNR IN ") + "(" + idnummerstring + ")" ;
        sasDataModule->studentenkaartSQLDataSet->Close();
        sasDataModule->studentenkaartClientDataSet->Active = false;
        sasDataModule->studentenkaartSQLDataSet->CommandText =  qstring; //"SELECT * FROM inschrijving where studienr in ("  + idnummerstring + ")";//("05ET1001", "05ET1002");
        sasDataModule->studentenkaartSQLDataSet->Open();
        sasDataModule->studentenkaartClientDataSet->Active = true;

        studentenkaartenreport->huidig_collegejaar = huidig_collegejaar;
        studentenkaartenreport->Show();
        studentenkaartenreport->QuickRep1->Preview();
        studentenkaartenreport->huidig_collegejaar = huidig_collegejaar;
      }
    else
      {
        String qstring = String("SELECT concat(straat,' ',huisnummer) as adres,persoon.*, schakel.*, studierichting.* from persoon INNER JOIN schakel  on persoon.IDKAARTNR = schakel.IDKAARTNR  INNER JOIN studierichting on schakel.STUDIERICHTING_ID = studierichting.RICHTING_ID WHERE schakel.afgerond = '0' AND IsNull(schakel.AFSCHRIJVINGSDATUM) AND persoon.IDKAARTNR IN ") + "(" + idnummerstring + ")" ;
        sasDataModule->studentenkaartSQLDataSet->Close();
        sasDataModule->studentenkaartClientDataSet->Active = false;
        sasDataModule->studentenkaartSQLDataSet->CommandText =  qstring; //"SELECT * FROM inschrijving where studienr in ("  + idnummerstring + ")";//("05ET1001", "05ET1002");
        sasDataModule->studentenkaartSQLDataSet->Open();
        sasDataModule->studentenkaartClientDataSet->Active = true;

        studentenkaartenreport->huidig_collegejaar = huidig_collegejaar;
        studentenkaartenreport->Show();
        studentenkaartenreport->QuickRep1->Preview();
        studentenkaartenreport->huidig_collegejaar = huidig_collegejaar;
      }
    BatchListBox->Clear();
    NummerListBox->Clear();
    idnummerstring = "";
    StudienrEdit->Text = "";
   }
}
//---------------------------------------------------------------------------

void __fastcall TKaartBatchDlg::VoegToeButtonClick(TObject *Sender)
{
 if (StudienrEdit->Text != "")
   {
  TLocateOptions Opts;

  Opts.Clear();
  Opts << loPartialKey;
 // Variant locvalues[2];
 // locvalues[0] = Variant("SUDIENR");
//locvalues[1] = Variant("P");
//locvalues[2] = Variant("831-431-1000");
  String nummer;
  nummer = Variant(StudienrEdit->Text);
  if (NummerListBox->Items->IndexOf(StudienrEdit->Text) == -1)
   {
     if (SoortReport == "Faculteit")
      {
        if (sasDataModule->InschrijvingClientDataSet->Locate("STUDIENR", nummer, Opts))
         {
          BatchListBox->Items->Add(sasDataModule->InschrijvingClientDataSet->FieldByName("IDKAARTNR")->AsString);
          NummerListBox->Items->Add(sasDataModule->InschrijvingClientDataSet->FieldByName("STUDIENR")->AsString);
         }
      }
     else
      {
        if (sasDataModule->SchakelClientDataSet->Locate("STUDIENR", nummer, Opts))
         {
          BatchListBox->Items->Add(sasDataModule->SchakelClientDataSet->FieldByName("IDKAARTNR")->AsString);
          NummerListBox->Items->Add(sasDataModule->SchakelClientDataSet->FieldByName("STUDIENR")->AsString);
         }
      }
   }
  }
}
//---------------------------------------------------------------------------


void __fastcall TKaartBatchDlg::CancelBtnClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TKaartBatchDlg::VerwijderButtonClick(TObject *Sender)
{
  int index;
  index = NummerListBox->ItemIndex;
  NummerListBox->DeleteSelected();
  BatchListBox->ItemIndex = index;
  BatchListBox->DeleteSelected();
}
//---------------------------------------------------------------------------


void __fastcall TKaartBatchDlg::UpDown1ChangingEx(TObject *Sender,
      bool &AllowChange, short NewValue, TUpDownDirection Direction)
{
  huidig_collegejaar = NewValue;
  CollegejaarLabel->Caption = String(NewValue) + "/" + String(NewValue + 1);
}

//---------------------------------------------------------------------------


void __fastcall TKaartBatchDlg::FormShow(TObject *Sender)
{
 BatchListBox->Clear();
  NummerListBox->Clear();
  idnummerstring = "";
  StudienrEdit->Text = "";
  sasDataModule->InschrijvingClientDataSet->Active = false;
  sasDataModule->InschrijvingSQLDataSet->Close();
  sasDataModule->InschrijvingSQLDataSet->CommandText = "select * from inschrijving ORDER BY STUDIENR ASC";
  sasDataModule->InschrijvingSQLDataSet->Open();
  sasDataModule->InschrijvingClientDataSet->Active = true;
  sasDataModule->SchakelClientDataSet->Active = false;
  sasDataModule->SchakelSQLDataSet->Close();
  sasDataModule->SchakelSQLDataSet->CommandText = "select * from schakel ORDER BY STUDIENR ASC";
  sasDataModule->SchakelSQLDataSet->Open();
  sasDataModule->SchakelClientDataSet->Active = true;
   if (KaartBatchDlg->SoortReport == String("Faculteit"))
     KaartBatchDlg->Caption = "Batch van faculteit studentenkaarten";
   else
     KaartBatchDlg->Caption = "Batch van schakel studentenkaarten";
   UpDown1->Max = huidig_collegejaar;
}
//---------------------------------------------------------------------------

