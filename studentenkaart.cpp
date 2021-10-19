//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "sasdm.h"
#include "studentenkaart.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tstudentenkaartenreport *studentenkaartenreport;

//---------------------------------------------------------------------------
__fastcall Tstudentenkaartenreport::Tstudentenkaartenreport(TComponent* Owner)
        : TForm(Owner)
{

    /*  String("1.Adreswijzigingen aan STUZA door te geven.\n")+
        String("2.Deze kaart:\n")+
                String(" a)bij zich te hebben, wanneer hij/zij de")+
                String("   colleges, inrichting of verzameling bezoekt.")+
                String(" b)op verzoek van een controlerend ambtenaar\n")+
                String("   te tonen.\n")+
                String("3.Bij verlies opgave te doen.\n")+
                String("De vinder wordt verzocht deze kaart bij het\n")+
                String("dichtsbijzijnde politiebureau af te geven.\n")+
                String("Deze kaart is eigendom van de\n")+
                String("Anton de Kom Universiteit van Suriname ");*/

}
//---------------------------------------------------------------------------


void __fastcall Tstudentenkaartenreport::FormActivate(TObject *Sender)
{
    collegejaar->Caption = String(huidig_collegejaar )+"/"+String(huidig_collegejaar + 1);

    TColor huidige_kleur;

    sasDataModule->kleurcollegekaartClientDataSet->Active = false;
    sasDataModule->kleurcollegekaartSQLDataSet->Close();
    sasDataModule->kleurcollegekaartSQLDataSet->CommandText = "select * from kleurcollegekaart where collegejaar = " + String(huidig_collegejaar);
   // sasDataModule->kleurcollegekaartSQLDataSet->ExecSQL();
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

void __fastcall Tstudentenkaartenreport::QuickRep1AfterPreview(
      TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

