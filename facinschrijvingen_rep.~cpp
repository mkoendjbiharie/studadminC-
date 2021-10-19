//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "sasdm.h"
#include "facinschrijvingen_rep.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfaculteit_inschrijvingen_report *faculteit_inschrijvingen_report;
static int huidig_collegejaar;
//---------------------------------------------------------------------------
__fastcall Tfaculteit_inschrijvingen_report::Tfaculteit_inschrijvingen_report(TComponent* Owner)
        : TForm(Owner)
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
    collegejaar->Caption = String(huidig_collegejaar)+"/"+String(huidig_collegejaar+1);
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
        collegejaar->Color = (TColor) ((blauw << 16) + (groen << 8) + rood);
    }
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


