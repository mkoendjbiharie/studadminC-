//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "wachtwoord.h"
#include "sasdm.h"
#include "Main.h"
#include <ctype.h>
#include <string.h>
#include <conio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWachtwoordForm *WachtwoordForm;
char *wachtwoord;
//---------------------------------------------------------------------------
__fastcall TWachtwoordForm::TWachtwoordForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool goedWachtwoord(char *wachtwoord)
{
  int aantalletters=0;
  if(strlen(wachtwoord)>=6)
  {
    for(int i=0;i<(int)strlen(wachtwoord);i++)
    {
      if(isalpha(wachtwoord[i]))
         aantalletters++;
    }
    if (aantalletters<(int)strlen(wachtwoord))
      return true;
  }
  return false;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TWachtwoordForm::btnbevestigClick(TObject *Sender)
{
  char *oud=sasDataModule->sasSQLConnection->Params->Values["Password"].c_str();
  //Application->MessageBox(oud, MB_OK);
  char *nieuw1=WachtwoordForm->nieuwEdit1->Text.c_str();
  char *nieuw2=WachtwoordForm->nieuwEdit2->Text.c_str();
  if(strcmp(oud,oudEdit->Text.c_str())==0)
  {
  if(strcmp(nieuw1,nieuw2)==0)
  {
//        Application->MessageBox("Twee wachtwoorden gelijk", MB_OK);
    if(goedWachtwoord(nieuw1)==true)
    {
        //Application->MessageBox(nieuwEdit2->Text.c_str(), MB_OK);
        passwordSQLDataSet->CommandType = ctQuery;
        passwordSQLDataSet->CommandText = "SET PASSWORD=PASSWORD(:PASSWORD)";
        passwordSQLDataSet->Params->Items[0]->AsString = nieuwEdit2->Text.c_str();
        passwordSQLDataSet->ExecSQL();
        Application->MessageBox("Wachtwoord succesvol gewijzigd", MB_OK);
    }
    else
        Application->MessageBox("Nieuw wachtwoord te kort, moet uit ten minste 6 tekens bestaan en mag ook niet uit alleen letters bestaan, probeer opnieuw", MB_OK);
  }
  else
  Application->MessageBox("Nieuwe wachtwoorden mogen niet verschillen, probeer opnieuw", MB_OK);
  }
  else
  Application->MessageBox("Oud wachtwoord klopt niet, probeer opnieuw", MB_OK);

}
//---------------------------------------------------------------------------

void __fastcall TWachtwoordForm::btncancelClick(TObject *Sender)
{
    WachtwoordForm->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TWachtwoordForm::btnsluitenClick(TObject *Sender)
{
    WachtwoordForm->Visible=false;
}
//---------------------------------------------------------------------------

