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
  sasDataModule->eduSQLDataSet->Close(); // Flush previous query
  sasDataModule->eduClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->eduSQLDataSet->CommandText= "select opleiding_id,opleiding from opleiding";
  sasDataModule->eduSQLDataSet->Open();
  sasDataModule->eduClientDataSet->Active=true;

  btnopslaan->Enabled = false;
  btncancel->Enabled = false;
  VooropleidingEdit->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TVooropleidingForm::btnnieuwClick(TObject *Sender)
{
  btnopslaan->Enabled = true;
  btncancel->Enabled = true;
  VooropleidingEdit->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TVooropleidingForm::btncancelClick(TObject *Sender)
{
  VooropleidingEdit->Text = "";
  VooropleidingEdit->Enabled = false;
  btnopslaan->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TVooropleidingForm::btnopslaanClick(TObject *Sender)
{
  sasDataModule->eduSQLDataSet->CommandType = ctQuery;
  sasDataModule->eduSQLDataSet->CommandText = "INSERT INTO opleiding(opleiding) VALUES(:Vooropleiding)";
  sasDataModule->eduSQLDataSet->Params->Items[0]->AsString = VooropleidingForm->VooropleidingEdit->Text;
  sasDataModule->eduSQLDataSet->ExecSQL();

  sasDataModule->eduSQLDataSet->Close(); // Flush previous query
  sasDataModule->eduClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->eduSQLDataSet->CommandText= "select opleiding_id,opleiding from opleiding";
  sasDataModule->eduSQLDataSet->Open();
  sasDataModule->eduClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TVooropleidingForm::btnsluitenClick(TObject *Sender)
{
  VooropleidingForm->Close();
}
//---------------------------------------------------------------------------
