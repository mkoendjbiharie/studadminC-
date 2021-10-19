//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "sasdm.h"
#include "kleurstudentenkaart.h"
#include "Main.h"
Byte rood, groen, blauw;
Byte rood_nieuw_cj, groen_nieuw_cj, blauw_nieuw_cj;
int collegejaar;
TColor nieuwe_kleur;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGRID"
#pragma resource "*.dfm"
TKleurStudentenkaartForm *KleurStudentenkaartForm;
//---------------------------------------------------------------------------
__fastcall TKleurStudentenkaartForm::TKleurStudentenkaartForm(TComponent* Owner)
        : TForm(Owner)
{
//Toon de oude kleuren
}
//---------------------------------------------------------------------------


void __fastcall TKleurStudentenkaartForm::OpslaanButtonClick(TObject *Sender)
{
   //Voeg kleur toe
   Application->MessageBox("opslaan", "1", MB_OK);

   sasDataModule->kleurcollegekaartSQLDataSet->Close();
   sasDataModule->kleurcollegekaartSQLDataSet->CommandText = "INSERT INTO kleurcollegekaart (collegejaar, rood, groen, blauw)  VALUES (:COLLEGEJAAR, :ROOD, :GROEN, :BLAUW) ";
   sasDataModule->kleurcollegekaartSQLDataSet->Params->Items[0]->AsString  = collegejaar;
   sasDataModule->kleurcollegekaartSQLDataSet->Params->Items[1]->AsString  = rood_nieuw_cj;
   sasDataModule->kleurcollegekaartSQLDataSet->Params->Items[2]->AsString  = groen_nieuw_cj;
   sasDataModule->kleurcollegekaartSQLDataSet->Params->Items[3]->AsString  = blauw_nieuw_cj;
   //sasDataModule->kleurcollegekaartSQLDataSet->ExecSQL();
   sasDataModule->kleurcollegekaartSQLDataSet->Open();

   Application->MessageBox("opslaan", "2", MB_OK);

   Close();
}
//---------------------------------------------------------------------------

void __fastcall TKleurStudentenkaartForm::CancelButtonClick(TObject *Sender)
{
  //Maak kleurkeuze ongedaan
  Label3->Visible = false;
  Edit2->Visible = false;
  Label4->Visible = false;
  Panel2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TKleurStudentenkaartForm::NieuwButtonClick(TObject *Sender)
{

   if (collegejaar == UpDown1->Max)
     {
       Application->MessageBox("","Er is al een kleur gekozen", MB_OK|MB_ICONSTOP);
       return;
     }
 //  UpDown1->Max = collegejaar;
 //  UpDown1->Position = UpDown1->Max;
   if (ColorDialog1->Execute())
    { TColor   AColor;
      AColor   = ColorDialog1->Color;
      rood_nieuw_cj = AColor % 0x100;
      groen_nieuw_cj = (AColor / 0x100) % 0x100;
      blauw_nieuw_cj = (AColor /0x10000) % 0x100;
      Label3->Visible = true;
      Edit2->Visible = true;
      Label4->Visible = true;
      Panel2->Visible = true;
      Edit2->Text = collegejaar;
      Panel2->Color = nieuwe_kleur  = (TColor) ((blauw_nieuw_cj << 16) + (groen_nieuw_cj << 8) + rood_nieuw_cj);
       }
}
//---------------------------------------------------------------------------

void __fastcall TKleurStudentenkaartForm::FormActivate(TObject *Sender)
{
     String jr = CurrentYear();
     TDateTime datum = Now();
     unsigned short jar, mnd, dag;
     datum.DecodeDate(&jar, &mnd, &dag);

     collegejaar = atoi(jr.c_str());

     if (mnd < 9)
      {
        collegejaar--;
      }
    sasDataModule->kleurcollegekaartSQLDataSet->Close();
    sasDataModule->kleurcollegekaartSQLDataSet->CommandText = "select * from kleurcollegekaart order by collegejaar desc" ;
    //sasDataModule->kleurcollegekaartSQLDataSet->ExecSQL();
    sasDataModule->kleurcollegekaartSQLDataSet->Open();
    UpDown1->Max = sasDataModule->kleurcollegekaartSQLDataSet->FieldByName("collegejaar")->Value;


    Edit1->Text = UpDown1->Max;
    rood = sasDataModule->kleurcollegekaartSQLDataSet->FieldByName("rood")->Value;
    blauw = sasDataModule->kleurcollegekaartSQLDataSet->FieldByName("blauw")->Value;
    groen = sasDataModule->kleurcollegekaartSQLDataSet->FieldByName("groen")->Value;
    Panel1->Color = (TColor) ((blauw << 16) + (groen << 8) + rood);
}
//---------------------------------------------------------------------------

void __fastcall TKleurStudentenkaartForm::UpDown1ChangingEx(
      TObject *Sender, bool &AllowChange, short NewValue,
      TUpDownDirection Direction)
{
      if ((NewValue <= UpDown1->Max)&&(NewValue >= UpDown1->Min))
    //Zoek kleurwaarden op in tabel
   { sasDataModule->kleurcollegekaartSQLDataSet->Close();
  //   sasDataModule->kleurcollegekaartClientDataSet->Active = false;
    sasDataModule->kleurcollegekaartSQLDataSet->CommandText = "select * from kleurcollegekaart where collegejaar = " + String(NewValue);
   // sasDataModule->kleurcollegekaartSQLDataSet->ExecSQL();
     sasDataModule->kleurcollegekaartSQLDataSet->Open();
   //  sasDataModule->kleurcollegekaartClientDataSet->Active = true;
    rood = sasDataModule->kleurcollegekaartSQLDataSet->FieldByName("rood")->Value;
    blauw = sasDataModule->kleurcollegekaartSQLDataSet->FieldByName("blauw")->Value;
    groen = sasDataModule->kleurcollegekaartSQLDataSet->FieldByName("groen")->Value;
    Panel1->Color = (TColor) ((blauw << 16) + (groen << 8) + rood);  }
}
//---------------------------------------------------------------------------

void __fastcall TKleurStudentenkaartForm::CloseButtonClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TKleurStudentenkaartForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  HoofdScherm->Kleurstudentenkaart1->Checked = false;
}
//---------------------------------------------------------------------------

