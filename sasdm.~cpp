//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "sasdm.h"
#include "login.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TsasDataModule *sasDataModule;
extern THoofdScherm *HoofdScherm;
extern TLoginForm *LoginForm;
TIniFile *ini;
//---------------------------------------------------------------------------
__fastcall TsasDataModule::TsasDataModule(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TsasDataModule::DataModuleCreate(TObject *Sender)
{
        if (access("sas.ini",0)!=0) // Als ongelijk 0 bestaat de file niet
        {
                // Creating the ini file with the database settings
 /*               ini = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));
                ini->WriteString("MySQL Server Config", "DbServer", "127.0.0.1");
                ini->WriteString("MySQL Server Config", "Db", "sas");
                ini->WriteString("MySQL Server Config", "Admin", "sasdba");
                ini->WriteString("MySQL Server Config", "Passwd", "xs4sasdba");  */
                     Application->MessageBoxA("Fout in inifile","",MB_OK+MB_ICONSTOP);

        }
         else  // de file bestaat
         {
               // Close any connections to db
                sasDataModule->sasSQLConnection->Connected=false;

                // Reading database settings from ini file
                ini = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));
                sasDataModule->sasSQLConnection->Params->Values["HostName"]=ini->ReadString("MySQL Server Config", "DbServer", "");
                sasDataModule->sasSQLConnection->Params->Values["Database"]=ini->ReadString("MySQL Server Config", "Db", "");
                if (( sasDataModule->sasSQLConnection->Params->Values["HostName"] == "")
                ||  (sasDataModule->sasSQLConnection->Params->Values["Database"] == ""))
              {
                 LoginForm->Hide();
                 Application->MessageBoxA("Fout in inifile","",MB_OK+MB_ICONSTOP);
                 HoofdScherm->Close();}

 /*               sasDataModule->sasSQLConnection->Params->Values["User_Name"]=ini->ReadString("MySQL Server Config", "Admin", "sasdba");
                sasDataModule->sasSQLConnection->Params->Values["Password"]=ini->ReadString("MySQL Server Config", "Passwd", "xs4sasdba");
    */
                // Open connection to db
               // sasDataModule->sasSQLConnection->LoadParamsOnConnect=true;
               // sasDataModule->sasSQLConnection->Connected=true;
         }
}
//---------------------------------------------------------------------------




