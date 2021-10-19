//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Vooropleiding.h"
#include "sasdm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TVooropleidingForm *VooropleidingForm;
//---------------------------------------------------------------------------
__fastcall TVooropleidingForm::TVooropleidingForm(TComponent* Owner)
        : TForm(Owner)
{
  eduSQLDataSet->Close(); // Flush previous query
  eduClientDataSet->Active=false; // Flush previous data in set
  eduSQLDataSet->CommandText= "select opleiding_id,opleiding from opleiding order by opleiding";
  eduSQLDataSet->Open();
  eduClientDataSet->Active=true;

  VooropleidingEdit->Enabled = true;

  VooropleidingForm->btnwijzigen->Enabled=true;
  VooropleidingForm->btnnieuw->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TVooropleidingForm::btnsluitenClick(TObject *Sender)
{
  VooropleidingForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TVooropleidingForm::VooropleidingDBGridCellClick(
      TColumn *Column)
{
  VooropleidingForm->VooropleidingEdit->Text= VooropleidingDBGrid->Columns->Items[1]->Field->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TVooropleidingForm::ToggleButtonClick(TObject *Sender)
{
 if (VooropleidingForm->ToggleButton->Caption == "wijzigen")
 {
      VooropleidingForm->ToggleButton->Caption = "toevoegen";
      VooropleidingForm->btnwijzigen->Enabled=false;
      VooropleidingForm->btnnieuw->Enabled=true;
  }
  else
  {
      VooropleidingForm->ToggleButton->Caption = "wijzigen";
      VooropleidingForm->btnwijzigen->Enabled=true;
      VooropleidingForm->btnnieuw->Enabled=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TVooropleidingForm::btnwijzigenClick(TObject *Sender)
{
  eduSQLDataSet->CommandType = ctQuery;
  eduSQLDataSet->CommandText = "UPDATE opleiding SET opleiding=:opleiding WHERE opleiding_ID=:opleiding_ID";
  eduSQLDataSet->Params->Items[0]->AsString = VooropleidingForm->VooropleidingEdit->Text;
  eduSQLDataSet->Params->Items[1]->AsString = VooropleidingDBGrid->Columns->Items[0]->Field->AsString;
  eduSQLDataSet->ExecSQL();

  eduSQLDataSet->Close(); // Flush previous query
  eduClientDataSet->Active=false; // Flush previous data in set
  eduSQLDataSet->CommandText= "select opleiding_id,opleiding from opleiding order by opleiding";
  eduSQLDataSet->Open();
  eduClientDataSet->Active=true;

}
//----------------------------------------------------------------------
void __fastcall TVooropleidingForm::btnnieuwClick(TObject *Sender)
{
  eduSQLDataSet->CommandType = ctQuery;
  eduSQLDataSet->CommandText = "INSERT INTO opleiding(opleiding) VALUES(:opleiding)";
  eduSQLDataSet->Params->Items[0]->AsString = VooropleidingForm->VooropleidingEdit->Text;
  eduSQLDataSet->ExecSQL();

  eduSQLDataSet->Close(); // Flush previous query
  eduClientDataSet->Active=false; // Flush previous data in set
  eduSQLDataSet->CommandText= "select opleiding_ID,opleiding from opleiding order by opleiding";
  eduSQLDataSet->Open();
  eduClientDataSet->Active=true;
        
}
//---------------------------------------------------------------------------




void __fastcall TVooropleidingForm::VooropleidingDBGridKeyUp(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
  VooropleidingForm->VooropleidingEdit->Text= VooropleidingDBGrid->Columns->Items[1]->Field->AsString;
}
//---------------------------------------------------------------------------

