//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "schakelstudentenkaart.h"
#include "sasdm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tschakelstudentenkaartenreport *schakelstudentenkaartenreport;

//---------------------------------------------------------------------------
__fastcall Tschakelstudentenkaartenreport::Tschakelstudentenkaartenreport(TComponent* Owner)
        : TForm(Owner)
{
  
}
//---------------------------------------------------------------------------
void __fastcall Tschakelstudentenkaartenreport::FormActivate(
      TObject *Sender)
{
 collegejaar->Caption = String(huidig_collegejaar )+"/"+String(huidig_collegejaar + 1);

    TColor huidige_kleur;

    sasDataModule->kleurcollegekaartClientDataSet->Active = false;
    sasDataModule->kleurcollegekaartSQLDataSet->Close();
    sasDataModule->kleurcollegekaartSQLDataSet->CommandText = "select * from kleurcollegekaart where collegejaar = " + String(huidig_collegejaar);
  //  sasDataModule->kleurcollegekaartSQLDataSet->ExecSQL();
    sasDataModule->kleurcollegekaartSQLDataSet->Open();
    sasDataModule->kleurcollegekaartSQLDataSet->Active = true;
    sasDataModule->kleurcollegekaartClientDataSet->Active = true;
    if (sasDataModule->kleurcollegekaartClientDataSet->IsEmpty())
    {
        Application->MessageBox("","U heeft nog geen kleur voor het nieuwe collegejaar ingesteld",MB_OK|MB_ICONSTOP);
    }
    else
    {
        byte rood = sasDataModule->kleurcollegekaartClientDataSet->FieldByName("rood")->Value;
        byte blauw = sasDataModule->kleurcollegekaartClientDataSet->FieldByName("blauw")->Value;
        byte groen = sasDataModule->kleurcollegekaartClientDataSet->FieldByName("groen")->Value;
        Kleurbalk->Brush->Color = (TColor) ((blauw << 16) + (groen << 8) + rood);
        Kleurbalk->Pen->Color = (TColor) ((blauw << 16) + (groen << 8) + rood);

    }

}
//---------------------------------------------------------------------------
void __fastcall Tschakelstudentenkaartenreport::QuickRep1AfterPreview(
      TObject *Sender)
{
 Close();        
}
//---------------------------------------------------------------------------

