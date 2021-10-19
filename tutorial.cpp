//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tutorial.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Word_2K_SRVR"
#pragma resource "*.dfm"
TTutorialForm *TutorialForm;
//---------------------------------------------------------------------------
__fastcall TTutorialForm::TTutorialForm(TComponent* Owner)
        : TForm(Owner)
{
  TutorialRichEdit->Lines->LoadFromFile("sas_handleiding.rtf");
}
//---------------------------------------------------------------------------
void __fastcall TTutorialForm::Close1Click(TObject *Sender)
{
 Hide();        
}
//---------------------------------------------------------------------------
void __fastcall TTutorialForm::Exit1Click(TObject *Sender)
{
  Close();
  HoofdScherm->Close();
}
//---------------------------------------------------------------------------
