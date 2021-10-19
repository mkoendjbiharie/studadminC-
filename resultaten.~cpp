//---------------------------------------------------------------------------
#include "sasdm.h"
#include <vcl.h>
#pragma hdrstop

#include "resultaten.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
static int Modus;
extern String usergroup;
TResultatenForm *ResultatenForm;
//--------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
 }
//--------------------------------------------------------------------------

static void DoRead()
{
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
   SetReadModus(false);
}
//----------------------------------------------------------------------------

static void  DoInsert()
{
     SetReadModus(false);
}

//---------------------------------------------------------------------------
__fastcall TResultatenForm::TResultatenForm(TComponent* Owner)
        : TForm(Owner)
{
  Modus = 0;
  String facnaam = usergroup;
 /* char  *letter = usergroup.c_str();
  while ((*letter != '_') && (*letter != '\0'))   letter++;
  *letter = '\0';  */
  if (facnaam != "")
    {
  /*    studierichtingSQLDataSet->Close();
      studierichtingClientDataSet->Close();
      studierichtingClientDataSet->Filtered = true;
      studierichtingClientDataSet->Filter = "Faculteit = '" + facnaam + "'" + "";
     */ studierichtingSQLDataSet->Open();
      studierichtingClientDataSet->Open();
    }
}
//---------------------------------------------------------------------------

void __fastcall TResultatenForm::ModusKnopClick(TObject *Sender)
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


void __fastcall TResultatenForm::SearchButtonClick(TObject *Sender)
{
   bool isfilter;
   isfilter = false;
   AnsiString filter;
 //  first->Text = "";
 //  last->Text = "";

   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
        sasDataModule->sasSQLConnection->Connected=true;
     }
   //We gebruken vak_id en studiejaar als filter voor tentamen
    tentamenClientDataSet->Active=false; // Flush previous data in set
 //   Application->MessageBoxA("12","",MB_OK);
    tentamenClientDataSet->Filtered = true;
    tentamenClientDataSet->Filter= String("  STUDIEJAAR = ") + "'" +  StudiejaarMaskEdit->EditText + "'" + "AND VAK_ID =" + "'" + VakLookupComboBox->KeyValue + "'";
    tentamenClientDataSet->Active = true;

   //nu moeten we zoeken naar de aanmeldingen die bij dit tentamen horen
   //filter wordt tentamen_id
}
//---------------------------------------------------------------------------

void __fastcall TResultatenForm::StudierichtingLookupComboBoxClick(
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


void __fastcall TResultatenForm::tentamenDataSourceDataChange(
      TObject *Sender, TField *Field)
{
//NU moeten de resultaten van het betreffende tetamen worden getoond
//Hiertoe wordt een filter gezet op basis van tentamen_id
resultatenClientDataSet->Filtered = false;
resultatenClientDataSet->Filter = String("tentamen_id = ")  +  TentamenDBEdit->Text;
resultatenClientDataSet->Filtered = true;
}
//---------------------------------------------------------------------------

