//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "woningontwerp.h"
#include "ruimte.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thoofdscherm *hoofdscherm;
TRuimte  *ruimte1;
//---------------------------------------------------------------------------
__fastcall Thoofdscherm::Thoofdscherm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Thoofdscherm::Button1Click(TObject *Sender)
{
    ruimte1 = new TRuimte(hoofdscherm);
    ruimte1->Parent = hoofdscherm;
    ruimte1->Repaint();
}
//---------------------------------------------------------------------------
