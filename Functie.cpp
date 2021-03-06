//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Functie.h"
#include "sasdm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFunctieForm *FunctieForm;
//---------------------------------------------------------------------------
__fastcall TFunctieForm::TFunctieForm(TComponent* Owner)
        : TForm(Owner)
{
  functieSQLDataSet->Close(); // Flush previous query
  functieClientDataSet->Active=false; // Flush previous data in set
  functieSQLDataSet->CommandText= "select functie_id,omschrijving,vergoeding,maxuren,taken from functie order by omschrijving";
  functieSQLDataSet->Open();
  functieClientDataSet->Active=true;

  //OmschrijvingEdit->Enabled = true;

  FunctieForm->btnwijzigen->Enabled=true;
  FunctieForm->btnnieuw->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TFunctieForm::btnsluitenClick(TObject *Sender)
{
  FunctieForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFunctieForm::FunctieDBGridCellClick(TColumn *Column)
{
  FunctieForm->OmschrijvingEdit->Text= FunctieDBGrid->Columns->Items[1]->Field->AsString;
  FunctieForm->VergoedingEdit->Text= FunctieDBGrid->Columns->Items[2]->Field->AsString;
  FunctieForm->MaxurenEdit->Text= FunctieDBGrid->Columns->Items[3]->Field->AsString;
  FunctieForm->TakenEdit->Text= FunctieDBGrid->Columns->Items[4]->Field->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TFunctieForm::ToggleButtonClick(TObject *Sender)
{
 if (FunctieForm->ToggleButton->Caption == "wijzigen")
 {
      FunctieForm->ToggleButton->Caption = "toevoegen";
      FunctieForm->btnwijzigen->Enabled=false;
      FunctieForm->btnnieuw->Enabled=true;
  }
  else
  {
      FunctieForm->ToggleButton->Caption = "wijzigen";
      FunctieForm->btnwijzigen->Enabled=true;
      FunctieForm->btnnieuw->Enabled=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFunctieForm::btnwijzigenClick(TObject *Sender)
{
  functieSQLDataSet->CommandType = ctQuery;
  functieSQLDataSet->CommandText = "UPDATE functie SET omschrijving=:omschrijving, vergoeding=:vergoeding, maxuren=:maxuren,taken=:taken WHERE functie_ID=:functie_ID";
  functieSQLDataSet->Params->Items[0]->AsString = FunctieForm->OmschrijvingEdit->Text;
  functieSQLDataSet->Params->Items[1]->AsString = FunctieForm->VergoedingEdit->Text;
  functieSQLDataSet->Params->Items[2]->AsString = FunctieForm->MaxurenEdit->Text;
  functieSQLDataSet->Params->Items[3]->AsString = FunctieForm->TakenEdit->Text;
  functieSQLDataSet->Params->Items[4]->AsString = FunctieDBGrid->Columns->Items[0]->Field->AsString;
  functieSQLDataSet->ExecSQL();

  functieSQLDataSet->Close(); // Flush previous query
  functieClientDataSet->Active=false; // Flush previous data in set
  functieSQLDataSet->CommandText= "select functie_id,omschrijving,vergoeding,maxuren,taken from functie order by omschrijving";
  functieSQLDataSet->Open();
  functieClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TFunctieForm::btnnieuwClick(TObject *Sender)
{
  functieSQLDataSet->CommandType = ctQuery;
  functieSQLDataSet->CommandText = "INSERT INTO functie(omschrijving,vergoeding,maxuren,taken) VALUES(:omschrijving,:vergoeding,:maxuren,:taken)";
  functieSQLDataSet->Params->Items[0]->AsString = FunctieForm->OmschrijvingEdit->Text;
  functieSQLDataSet->Params->Items[1]->AsString = FunctieForm->VergoedingEdit->Text;
  functieSQLDataSet->Params->Items[2]->AsString = FunctieForm->MaxurenEdit->Text;
  functieSQLDataSet->Params->Items[3]->AsString = FunctieForm->TakenEdit->Text;
  functieSQLDataSet->ExecSQL();

  functieSQLDataSet->Close(); // Flush previous query
  functieClientDataSet->Active=false; // Flush previous data in set
  functieSQLDataSet->CommandText= "select functie_id,omschrijving,vergoeding,maxuren,taken from functie order by omschrijving";
  functieSQLDataSet->Open();
  functieClientDataSet->Active=true;
}
//---------------------------------------------------------------------------




void __fastcall TFunctieForm::FunctieDBGridKeyUp(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  FunctieForm->OmschrijvingEdit->Text= FunctieDBGrid->Columns->Items[1]->Field->AsString;
  FunctieForm->VergoedingEdit->Text= FunctieDBGrid->Columns->Items[2]->Field->AsString;
  FunctieForm->MaxurenEdit->Text= FunctieDBGrid->Columns->Items[3]->Field->AsString;
  FunctieForm->TakenEdit->Text= FunctieDBGrid->Columns->Items[4]->Field->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TFunctieForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    HoofdScherm->Studentfunctie1->Checked = false;
}
//---------------------------------------------------------------------------

