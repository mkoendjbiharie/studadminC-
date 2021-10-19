//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Certificaat.h"
#include "sasdm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCertificaatForm *CertificaatForm;
//---------------------------------------------------------------------------
__fastcall TCertificaatForm::TCertificaatForm(TComponent* Owner)
        : TForm(Owner)
{
  certificaatSQLDataSet->Close(); // Flush previous query
  certificaatClientDataSet->Active=false; // Flush previous data in set
  certificaatSQLDataSet->CommandText= "select certificaat_id,omschrijving from certificaat order by omschrijving";
  certificaatSQLDataSet->Open();
  certificaatClientDataSet->Active=true;

  CertificaatEdit->Enabled = true;

  CertificaatForm->btnwijzigen->Enabled=true;
  CertificaatForm->btnnieuw->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatForm::btnsluitenClick(TObject *Sender)
{
  CertificaatForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatForm::CertificaatDBGridCellClick(
      TColumn *Column)
{
  CertificaatForm->CertificaatEdit->Text= CertificaatDBGrid->Columns->Items[1]->Field->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatForm::ToggleButtonClick(TObject *Sender)
{
 if (CertificaatForm->ToggleButton->Caption == "wijzigen")
 {
      CertificaatForm->ToggleButton->Caption = "toevoegen";
      CertificaatForm->btnwijzigen->Enabled=false;
      CertificaatForm->btnnieuw->Enabled=true;
  }
  else
  {
      CertificaatForm->ToggleButton->Caption = "wijzigen";
      CertificaatForm->btnwijzigen->Enabled=true;
      CertificaatForm->btnnieuw->Enabled=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatForm::btnwijzigenClick(TObject *Sender)
{
  certificaatSQLDataSet->CommandType = ctQuery;
  certificaatSQLDataSet->CommandText = "UPDATE certificaat SET omschrijving=:omschrijving WHERE certificaat_ID=:certificaat_ID";
  certificaatSQLDataSet->Params->Items[0]->AsString = CertificaatForm->CertificaatEdit->Text;
  certificaatSQLDataSet->Params->Items[1]->AsString = CertificaatDBGrid->Columns->Items[0]->Field->AsString;
  certificaatSQLDataSet->ExecSQL();

  certificaatSQLDataSet->Close(); // Flush previous query
  certificaatClientDataSet->Active=false; // Flush previous data in set
  certificaatSQLDataSet->CommandText= "select certificaat_id,omschrijving from certificaat order by omschrijving";
  certificaatSQLDataSet->Open();
  certificaatClientDataSet->Active=true;

}
//----------------------------------------------------------------------
void __fastcall TCertificaatForm::btnnieuwClick(TObject *Sender)
{
  certificaatSQLDataSet->CommandType = ctQuery;
  certificaatSQLDataSet->CommandText = "INSERT INTO certificaat(omschrijving) VALUES(:omschrijving)";
  certificaatSQLDataSet->Params->Items[0]->AsString = CertificaatForm->CertificaatEdit->Text;
  certificaatSQLDataSet->ExecSQL();

  certificaatSQLDataSet->Close(); // Flush previous query
  certificaatClientDataSet->Active=false; // Flush previous data in set
  certificaatSQLDataSet->CommandText= "select certificaat_id,omschrijving from certificaat order by omschrijving";
  certificaatSQLDataSet->Open();
  certificaatClientDataSet->Active=true;
        
}
//---------------------------------------------------------------------------




void __fastcall TCertificaatForm::CertificaatDBGridKeyUp(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  CertificaatForm->CertificaatEdit->Text= CertificaatDBGrid->Columns->Items[1]->Field->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  HoofdScherm->Certificaat1->Checked = false;
}
//---------------------------------------------------------------------------

