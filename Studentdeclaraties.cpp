//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Studentdeclaraties.h"
#include "sasdm.h"
#include "sasbasictablesmod.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStudentdeclaratiesForm *StudentdeclaratiesForm;
static int FModus;
//---------------------------------------------------------------------------
__fastcall TStudentdeclaratiesForm::TStudentdeclaratiesForm(TComponent* Owner)
        : TForm(Owner)
{
  FModus = 0;
  sasDataModule->personSQLDataSet->Active = true;
  sasDataModule->InschrijvingSQLDataSet->Active = true;
  sasDataModule->FaculteitSQLDataSet->Active = true;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  SasBasicTables->SysteemSQLDataSet->Active = true;

  sasDataModule->personClientDataSet->Active = true;
  sasDataModule->InschrijvingClientDataSet->Active = true;
  sasDataModule->FaculteitClientDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;
  SasBasicTables->SysteemClientDataSet->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TStudentdeclaratiesForm::Close1Click(TObject *Sender)
{
   HoofdScherm->Declaraties1->Checked = false;
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TStudentdeclaratiesForm::Exit1Click(TObject *Sender)
{
   HoofdScherm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TStudentdeclaratiesForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   HoofdScherm->Declaraties1->Checked = false;
   HoofdScherm->Show();
   Free();
}
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{

}
//--------------------------------------------------------------------------

static void DoRead()
{
    StudentdeclaratiesForm->InschrijvingDBNavigator->Enabled = true;
    StudentdeclaratiesForm->SearchEdit->Show();
    StudentdeclaratiesForm->SearchButton->Show();
    StudentdeclaratiesForm->ToggleButton->Show();
    StudentdeclaratiesForm->IdCardDBEdit->ReadOnly = true;
    StudentdeclaratiesForm->InschrijvingDBNavigator->Visible = true;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    StudentdeclaratiesForm->InschrijvingDBNavigator->Enabled = true;
    StudentdeclaratiesForm->SearchEdit->Show();
    StudentdeclaratiesForm->SearchButton->Show();
    StudentdeclaratiesForm->ToggleButton->Show();
    StudentdeclaratiesForm->IdCardDBEdit->ReadOnly = true;
    StudentdeclaratiesForm->InschrijvingDBNavigator->Visible = true;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
   StudentdeclaratiesForm->SearchEdit->Show();
    StudentdeclaratiesForm->SearchButton->Show();
    StudentdeclaratiesForm->ToggleButton->Show();
    StudentdeclaratiesForm->IdCardDBEdit->ReadOnly = false;
    StudentdeclaratiesForm->InschrijvingDBNavigator->Visible = true;
    SetReadModus(false);
}
//---------------------------------------------------------------------------

static void  DoInsert()
{
//    StudentdeclaratiesForm->InschrijvingDBNavigator->Enabled = false;
    StudentdeclaratiesForm->SearchEdit->Hide();
    StudentdeclaratiesForm->SearchButton->Hide();
    StudentdeclaratiesForm->ToggleButton->Hide();
    SetReadModus(false);
    StudentdeclaratiesForm->IdCardDBEdit->ReadOnly = false;
    StudentdeclaratiesForm->InschrijvingDBNavigator->Visible = true;
 }
//---------------------------------------------------------------------------
void __fastcall TStudentdeclaratiesForm::ModusKnopClick(TObject *Sender)
{
FModus = (++FModus)%4;
   switch (FModus)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Lezen"; DoRead();break;//lezen
   case 1: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Toevoegen";DoInsert();break;//toevoegen
   case 2: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Wijzigen";DoUpdate();break;//wijzigen
   case 3: ModusKnop->Font->Color = clRed ;ModusKnop->Caption = "Verwijderen";DoDelete();//verwijderen
   }        
}
//---------------------------------------------------------------------------

void __fastcall TStudentdeclaratiesForm::SearchButtonClick(TObject *Sender)
{
      // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
       //   sasDataModule->sasSQLConnection->Connected=true;
     }

   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active = false; // Flush previous data in set
   if (StudentdeclaratiesForm->ToggleButton->Caption == "op idnummer")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
        sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(StudentdeclaratiesForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else if (StudentdeclaratiesForm->ToggleButton->Caption == "op naam")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
        sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(StudentdeclaratiesForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
       else // op studienummer
         {
           //zoek eerst in inschrijving naar het studienummer en daarna in persoon naar het idnummer;
            sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
            sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
            sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where STUDIENR = :STUDIENR";
            sasDataModule->InschrijvingSQLDataSet->ParamByName("STUDIENR")->Value=LowerCase(StudentdeclaratiesForm->SearchEdit->Text);
            sasDataModule->InschrijvingSQLDataSet->Open();
            sasDataModule->InschrijvingClientDataSet->Active=true;
            String idnummer =(sasDataModule->InschrijvingClientDataSet->FindField("IDKAARTNR"))->AsString;
            sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
            sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(idnummer);
            sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
         }
   if (StudentdeclaratiesForm->ToggleButton->Caption != "op studienummer")
      {
        sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
     //   Application->MessageBox("", (sasDataModule->personClientDataSet->FieldByName("volgnr")->AsString).c_str(), MB_OK);

       sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
       sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
       sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR = :IDKAARTNR";
       sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(StudentdeclaratiesForm->IdCardDBEdit->Text);
       sasDataModule->InschrijvingSQLDataSet->Open();
       sasDataModule->InschrijvingClientDataSet->Active=true;
      }

        
}
//---------------------------------------------------------------------------

void __fastcall TStudentdeclaratiesForm::ToggleButtonClick(TObject *Sender)
{
 if (StudentdeclaratiesForm->ToggleButton->Caption == "op idnummer")
      StudentdeclaratiesForm->ToggleButton->Caption = "op naam";
   else  if(StudentdeclaratiesForm->ToggleButton->Caption == "op naam")
           StudentdeclaratiesForm->ToggleButton->Caption = "op studienummer";
        else
           StudentdeclaratiesForm->ToggleButton->Caption = "op idnummer";
}
//---------------------------------------------------------------------------

void __fastcall TStudentdeclaratiesForm::PersoonDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
      //Als geen persoon opgegeven is mag je niet verder
    if ( IdCardDBEdit->Text == "") return;
    //nu moet gegaan worden naar het gekoppelde record in inschrijving
    sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
    sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->InschrijvingSQLDataSet->CommandText="select inschrijving.INSCHRIJFJAAR, inschrijving.* from inschrijving where IDKAARTNR = :IDKAARTNR ORDER BY inschrijving.INSCHRIJFJAAR DESC";
    sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(StudentdeclaratiesForm->IdCardDBEdit->Text);
    sasDataModule->InschrijvingSQLDataSet->Open();
    sasDataModule->InschrijvingClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

