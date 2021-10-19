//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Splash.h"
#include "Login.h"
#include "sasdm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSplashForm *SplashForm;
//---------------------------------------------------------------------------
__fastcall TSplashForm::TSplashForm(TComponent* Owner)
        : TForm(Owner)
{
    SplashTimer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TSplashForm::FormClick(TObject *Sender)
{
    SplashTimer1->Enabled=false;
    LoginForm->Show();
     SplashForm->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TSplashForm::SplashTimer1Timer(TObject *Sender)
{
    SplashTimer1->Enabled=false;
    LoginForm->Show();
    SplashForm->Hide();
}
//---------------------------------------------------------------------------

