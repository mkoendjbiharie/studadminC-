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
  sasDataModule->ethnicSQLDataSet->Close(); // Flush previous query
  sasDataModule->ethnicClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->ethnicSQLDataSet->CommandText= "select bev_id, bev_groep from Bevolkingsgroep";
  sasDataModule->ethnicSQLDataSet->Open();
  sasDataModule->ethnicClientDataSet->Active=true;

  btnopslaan->Enabled = false;
  btncancel->Enabled = false;
  BevolkingsgroepEdit->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TBevolkingsgroepForm::btnnieuwClick(TObject *Sender)
{
  btnopslaan->Enabled = true;
  btncancel->Enabled = true;
  BevolkingsgroepEdit->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TBevolkingsgroepForm::btncancelClick(TObject *Sender)
{
  BevolkingsgroepEdit->Text = "";
  BevolkingsgroepEdit->Enabled = false;
  btnopslaan->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TBevolkingsgroepForm::btnopslaanClick(TObject *Sender)
{
  sasDataModule->ethnicSQLDataSet->CommandType = ctQuery;
  sasDataModule->ethnicSQLDataSet->CommandText = "INSERT INTO Bevolkingsgroep(Bev_groep) VALUES(:Bevolkingsgroep)";
  sasDataModule->ethnicSQLDataSet->Params->Items[0]->AsString = BevolkingsgroepForm->BevolkingsgroepEdit->Text;
  sasDataModule->ethnicSQLDataSet->ExecSQL();

  sasDataModule->ethnicSQLDataSet->Close(); // Flush previous query
  sasDataModule->ethnicClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->ethnicSQLDataSet->CommandText= "select bev_id,Bev_groep from Bevolkingsgroep";
  sasDataModule->ethnicSQLDataSet->Open();
  sasDataModule->ethnicClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TBevolkingsgroepForm::btnsluitenClick(TObject *Sender)
{
  BevolkingsgroepForm->Close();
}
//---------------------------------------------------------------------------


