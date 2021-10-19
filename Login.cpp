//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Login.h"
#include "Splash.h"
#include "Main.h"
#include "Studentvooraanmeld.h"
#include "sasdm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLoginForm *LoginForm;
static int inlogpogingen;
extern String usergroup;
extern String username;
extern String password;
//---------------------------------------------------------------------------
__fastcall TLoginForm::TLoginForm(TComponent* Owner)
        : TForm(Owner)
{
  inlogpogingen = 0;
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  //SplashForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::OkButtonClick(TObject *Sender)
{

    sasDataModule->sasSQLConnection->Params->Values["User_Name"]= UserNameEdit->Text.c_str();
    sasDataModule->sasSQLConnection->Params->Values["Password"]= UserPassEdit->Text.c_str();
    username =   UserNameEdit->Text;
    password =   UserPassEdit->Text;
    bool ingelogd = false;

    while ((inlogpogingen++ < 5)&& (ingelogd == false))
    {
        try
        {
            sasDataModule->sasSQLConnection->Connected = false;
            sasDataModule->sasSQLConnection->Connected = true;
            ingelogd = true;
     //NU wordt de user_group opgevraagd
           // Application->MessageBoxA(usergroup.c_str(), username.c_str(), MB_OK);



          }
        catch(const Exception &E)
        {
            Application->MessageBox("Wrong username or password", "Try again", MB_OK);
            return;
        }
    }
    if (!ingelogd)
    LoginForm->Close();
    else                        //,user_group
       {
       /*   String qstring="SELECT GROEP,GROEP_ID FROM sastest.GEBRUIKERSGROEP g,mysql.user u where g.GROEP_ID=u.user_group and u.user='"+username+"'";
           sasDataModule->GebruikersgroepSQLDataSet->CommandText=qstring;
           sasDataModule->GebruikersgroepSQLDataSet->Open();
           usergroup=sasDataModule->GebruikersgroepSQLDataSet->FieldByName("GROEP")->AsString;
          Application->MessageBoxA(usergroup.c_str(), username.c_str(), MB_OK);
             sasDataModule->FaculteitClientDataSet->Filter = "faculteit_id <> 4";

            if (usergroup == "STUZAMEDEWERKER")
               HoofdScherm->Menu = HoofdScherm->SasMainMenu;
            else if   (usergroup == "DIRECTEUR_UVS")
                 HoofdScherm->Menu = HoofdScherm->SasMainMenu1;
            else if   (usergroup == "DIRECTEUR_FAC")
                 HoofdScherm->Menu = HoofdScherm->SasMainMenu1;
            else  if  (usergroup == "DOCENT")
                 HoofdScherm->Menu = HoofdScherm->SasMainMenu1;
            else  if  (usergroup == "IGSR_ADMINISTRATIE")
                 {HoofdScherm->Menu = HoofdScherm->SasMainMenu;
                  sasDataModule->FaculteitClientDataSet->Filter = "faculteit_id = 4"; }
             sasDataModule->FaculteitClientDataSet->Filtered = true;  */
               HoofdScherm->Menu = HoofdScherm->SasMainMenu;
           if (UserNameEdit->Text == "vooraanmelden")
           {
               //Toon het vooraanmeldscherm voor de student
               Application->CreateForm(__classid(TStudentvooraanmeldForm), &StudentvooraanmeldForm);

           }
         else
           {
             HoofdScherm->Enabled = true;
             HoofdScherm->Show();    HoofdScherm->WindowState = wsNormal;
           }
         }
     LoginForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::CancelButtonClick(TObject *Sender)
{
    SplashForm->Close();
}
//---------------------------------------------------------------------------
