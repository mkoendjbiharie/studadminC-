//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sasfacdm.h"
#include "sasdm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSasFaculteitData *SasFaculteitData;
//---------------------------------------------------------------------------
__fastcall TSasFaculteitData::TSasFaculteitData(TComponent* Owner)
        : TDataModule(Owner)
{
      sasDataModule->FaculteitSQLDataSet->Active = true;
      sasDataModule->StudierichtingSQLDataSet->Active = true;
      sasDataModule->FaculteitClientDataSet->Active = true;
      sasDataModule->StudierichtingClientDataSet->Active = true;
      SasFaculteitData->vakSQLDataSet->Active = true;
      SasFaculteitData->vakClientDataSet->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TSasFaculteitData::vakDataSourceUpdateData(TObject *Sender)
{
     //  vakClientDataSet->Post();
}
//---------------------------------------------------------------------------

