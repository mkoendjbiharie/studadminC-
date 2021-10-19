//---------------------------------------------------------------------------
#include "sasdm.h"
#include <vcl.h>
#pragma hdrstop

#include "intekenen.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TIntekenForm *IntekenForm;
static int Modus;
extern String usergroup;
//--------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   IntekenForm->IntekenDatumDBEdit->ReadOnly=mode;
   IntekenForm->StudentLookupComboBox->ReadOnly=mode;
}
//--------------------------------------------------------------------------

static void DoRead()
{
    IntekenForm->IntekenLijstDBNavigator->Enabled = true;
    IntekenForm->NieuwButton->Enabled = false;
    IntekenForm->OpslaanButton->Enabled = false;
    IntekenForm->VerwijderButton->Enabled = false;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    IntekenForm->IntekenLijstDBNavigator->Enabled = true;
    IntekenForm->NieuwButton->Enabled = false;
    IntekenForm->OpslaanButton->Enabled = false;
    IntekenForm->VerwijderButton->Enabled = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
    IntekenForm->IntekenLijstDBNavigator->Enabled = true;
    IntekenForm->NieuwButton->Enabled = false;
    IntekenForm->OpslaanButton->Enabled = true;
    IntekenForm->VerwijderButton->Enabled = false;
    SetReadModus(false);
}
//----------------------------------------------------------------------------

static void  DoInsert()
{
    IntekenForm->IntekenLijstDBNavigator->Enabled = false;
    IntekenForm->NieuwButton->Enabled = true;
    IntekenForm->OpslaanButton->Enabled = false;
    IntekenForm->VerwijderButton->Enabled = false;
    SetReadModus(false);
}

//---------------------------------------------------------------------------
__fastcall TIntekenForm::TIntekenForm(TComponent* Owner)
        : TForm(Owner)
{
  Modus = 0;
  String facnaam = usergroup;
  char  *letter = usergroup.c_str();
  while ((*letter != '_') && (*letter != '\0'))   letter++;
  *letter = '\0';
  if (facnaam != "")
    {
      studierichtingSQLDataSet->Open();
      studierichtingClientDataSet->Close();
      studierichtingClientDataSet->Filtered = true;
      studierichtingClientDataSet->Filter = "Faculteit = '" + facnaam + "'" + "";
      studierichtingClientDataSet->Open();
    }  
}
//---------------------------------------------------------------------------

void __fastcall TIntekenForm::ModusKnopClick(TObject *Sender)
{
   Modus = (++Modus)%4;
   switch (Modus)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Lezen"; DoRead();break;//lezen
   case 1: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Toevoegen";DoInsert();break;//toevoegen
   case 2: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Wijzigen";DoUpdate();break;//toevoegen
   case 3: ModusKnop->Font->Color = clRed ;ModusKnop->Caption = "Verwijderen";DoDelete();//verwijderen
    };
}
//---------------------------------------------------------------------------


void __fastcall TIntekenForm::SearchButtonClick(TObject *Sender)
{
   bool isfilter;
   isfilter = false;
   AnsiString filter;
   first->Text = "";
   last->Text = "";

   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
        sasDataModule->sasSQLConnection->Connected=true;
     }
   //We gebruken vak_id en studiejaar als filter voor tentamen
    tentamenClientDataSet->Active=false; // Flush previous data in set
 //   Application->MessageBoxA("12","",MB_OK);
    tentamenClientDataSet->Filtered = true;
    tentamenClientDataSet->Filter= String("  STUDIEJAAR = ") + "'" +  StudiejaarMaskEdit->EditText + "'" + "AND VAK_ID =" + "'" + VakLookupComboBox->KeyField + "'";
    tentamenClientDataSet->Active = true;

   //nu moeten we zoeken naar de aanmeldingen die bij dit tentamen horen
   //filter wordt tentamen_id
    intekenlijstClientDataSet->Active=false; // Flush previous data in set
 //   Application->MessageBoxA("12","",MB_OK);
    intekenlijstClientDataSet->Filtered = true;
    intekenlijstClientDataSet->Filter= String("TENTAMEN_ID = ") + "'" +  TentamenDBEdit->Text + "'" + "AND VAK_ID =" + "'" + VakLookupComboBox->KeyField + "'";
    intekenlijstClientDataSet->Active = true;

    last->Text= String(intekenlijstClientDataSet->RecordCount);
    first->Text= String(intekenlijstClientDataSet->RecNo);
}
//---------------------------------------------------------------------------

void __fastcall TIntekenForm::StudierichtingLookupComboBoxClick(
      TObject *Sender)
{
   //Als studierichting verandert moet de filter voor vak veranderen
   //namelijk de studierichting_id wordt filter
   AnsiString filter;
   vakClientDataSet->Active = false;
   vakClientDataSet->Filtered = false;
   filter = String("RICHTING_ID = '") + StudierichtingLookupComboBox->KeyValue + "'" ;
   vakClientDataSet->Filter = filter;
   Application->MessageBoxA(filter.c_str(),"searchbutton op studierichting 1",MB_OK);
   vakClientDataSet->Filtered = true;
   vakClientDataSet->Active = true;
}
//---------------------------------------------------------------------------


