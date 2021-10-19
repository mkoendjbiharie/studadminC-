//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Bevolkingsgroep.h"
#include "sasdm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBevolkingsgroepForm *BevolkingsgroepForm;
//---------------------------------------------------------------------------
__fastcall TBevolkingsgroepForm::TBevolkingsgroepForm(TComponent* Owner)
        : TForm(Owner)
{
  ethnicSQLDataSet->Close(); // Flush previous query
  ethnicClientDataSet->Active=false; // Flush previous data in set
  ethnicSQLDataSet->CommandText= "select bev_id,bev_groep from bevolkingsgroep order by bev_groep";
  ethnicSQLDataSet->Open();
  ethnicClientDataSet->Active=true;

  BevolkingsgroepEdit->Enabled = true;

  BevolkingsgroepForm->btnwijzigen->Enabled=true;
  BevolkingsgroepForm->btnnieuw->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TBevolkingsgroepForm::btnsluitenClick(TObject *Sender)
{
  BevolkingsgroepForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TBevolkingsgroepForm::BevolkingsgroepDBGridCellClick(
      TColumn *Column)
{
  BevolkingsgroepForm->BevolkingsgroepEdit->Text= BevolkingsgroepDBGrid->Columns->Items[1]->Field->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TBevolkingsgroepForm::ToggleButtonClick(TObject *Sender)
{
 if (BevolkingsgroepForm->ToggleButton->Caption == "wijzigen")
 {
      BevolkingsgroepForm->ToggleButton->Caption = "toevoegen";
      BevolkingsgroepForm->btnwijzigen->Enabled=false;
      BevolkingsgroepForm->btnnieuw->Enabled=true;
  }
  else
  {
      BevolkingsgroepForm->ToggleButton->Caption = "wijzigen";
      BevolkingsgroepForm->btnwijzigen->Enabled=true;
      BevolkingsgroepForm->btnnieuw->Enabled=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TBevolkingsgroepForm::btnwijzigenClick(TObject *Sender)
{
  ethnicSQLDataSet->CommandType = ctQuery;
  ethnicSQLDataSet->CommandText = "UPDATE BEVOLKINGSGROEP SET BEV_GROEP=:BEV_GROEP WHERE BEV_ID=:BEV_ID";
  ethnicSQLDataSet->Params->Items[0]->AsString = BevolkingsgroepForm->BevolkingsgroepEdit->Text;
  ethnicSQLDataSet->Params->Items[1]->AsString = BevolkingsgroepDBGrid->Columns->Items[0]->Field->AsString;
  ethnicSQLDataSet->ExecSQL();

  ethnicSQLDataSet->Close(); // Flush previous query
  ethnicClientDataSet->Active=false; // Flush previous data in set
  ethnicSQLDataSet->CommandText= "select bev_id,bev_groep from bevolkingsgroep order by bev_groep";
  ethnicSQLDataSet->Open();
  ethnicClientDataSet->Active=true;

}
//----------------------------------------------------------------------
void __fastcall TBevolkingsgroepForm::btnnieuwClick(TObject *Sender)
{
  ethnicSQLDataSet->CommandType = ctQuery;
  ethnicSQLDataSet->CommandText = "INSERT INTO BEVOLKINGSGROEP(BEV_GROEP) VALUES(:BEV_GROEP)";
  ethnicSQLDataSet->Params->Items[0]->AsString = BevolkingsgroepForm->BevolkingsgroepEdit->Text;
  ethnicSQLDataSet->ExecSQL();

  ethnicSQLDataSet->Close(); // Flush previous query
  ethnicClientDataSet->Active=false; // Flush previous data in set
  ethnicSQLDataSet->CommandText= "select bev_id,bev_groep from bevolkingsgroep order by bev_groep";
  ethnicSQLDataSet->Open();
  ethnicClientDataSet->Active=true;
        
}
//---------------------------------------------------------------------------




void __fastcall TBevolkingsgroepForm::BevolkingsgroepDBGridKeyUp(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
  BevolkingsgroepForm->BevolkingsgroepEdit->Text= BevolkingsgroepDBGrid->Columns->Items[1]->Field->AsString;
}
//---------------------------------------------------------------------------

