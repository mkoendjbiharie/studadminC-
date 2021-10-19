//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "sasdm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int huidig_collegejaar;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::QuickRep1Preview(TObject *Sender)
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
    QRLabel13->Caption = String(huidig_collegejaar);

   TColor huidige_kleur;
    sasDataModule->kleurcollegekaartSQLDataSet->Close();
    sasDataModule->kleurcollegekaartSQLDataSet->CommandText = "select * from kleurcollegekaart where collegejaar = " + String(huidig_collegejaar);
    sasDataModule->kleurcollegekaartSQLDataSet->ExecSQL();
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
        QRLabel13->Color = (TColor) ((blauw << 16) + (groen << 8) + rood);
     }    
  // Form1->Show();
}
//---------------------------------------------------------------------------

