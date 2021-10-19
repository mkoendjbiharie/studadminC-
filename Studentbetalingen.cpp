//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Studentbetalingen.h"
#include "sasdm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStudentbetalingenForm *StudentbetalingenForm;
static int FModus;
//---------------------------------------------------------------------------
__fastcall TStudentbetalingenForm::TStudentbetalingenForm(TComponent* Owner)
        : TForm(Owner)
{
  FModus = 0;
  sasDataModule->personSQLDataSet->Active = true;
  sasDataModule->InschrijvingSQLDataSet->Active = true;
  sasDataModule->FaculteitSQLDataSet->Active = true;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  sasDataModule->SysteemSQLDataSet->Active = true;

  sasDataModule->personClientDataSet->Active = true;
  sasDataModule->InschrijvingClientDataSet->Active = true;
  sasDataModule->FaculteitClientDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;
  sasDataModule->SysteemClientDataSet->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TStudentbetalingenForm::Close1Click(TObject *Sender)
{
   HoofdScherm->Betalingen1->Checked = false;
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TStudentbetalingenForm::Exit1Click(TObject *Sender)
{
   HoofdScherm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TStudentbetalingenForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   HoofdScherm->Betalingen1->Checked = false;
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
    StudentbetalingenForm->InschrijvingDBNavigator->Enabled = true;
      StudentbetalingenForm->SearchEdit->Show();
    StudentbetalingenForm->SearchButton->Show();
    StudentbetalingenForm->ToggleButton->Show();
    StudentbetalingenForm->IdCardDBEdit->ReadOnly = true;
    StudentbetalingenForm->InschrijvingDBNavigator->Visible = true;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    StudentbetalingenForm->InschrijvingDBNavigator->Enabled = true;
    StudentbetalingenForm->SearchEdit->Show();
    StudentbetalingenForm->SearchButton->Show();
    StudentbetalingenForm->ToggleButton->Show();
    StudentbetalingenForm->IdCardDBEdit->ReadOnly = true;
    StudentbetalingenForm->InschrijvingDBNavigator->Visible = true;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
      StudentbetalingenForm->SearchEdit->Show();
    StudentbetalingenForm->SearchButton->Show();
    StudentbetalingenForm->ToggleButton->Show();
    StudentbetalingenForm->IdCardDBEdit->ReadOnly = false;
    StudentbetalingenForm->InschrijvingDBNavigator->Visible = true;
      SetReadModus(false);
}
//---------------------------------------------------------------------------

static void  DoInsert()
{
//    StudentbetalingenForm->InschrijvingDBNavigator->Enabled = false;
    StudentbetalingenForm->SearchEdit->Hide();
    StudentbetalingenForm->SearchButton->Hide();
    StudentbetalingenForm->ToggleButton->Hide();
    SetReadModus(false);
    StudentbetalingenForm->IdCardDBEdit->ReadOnly = false;
    StudentbetalingenForm->InschrijvingDBNavigator->Visible = true;
 }
//---------------------------------------------------------------------------
void __fastcall TStudentbetalingenForm::ModusKnopClick(TObject *Sender)
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

void __fastcall TStudentbetalingenForm::SearchButtonClick(TObject *Sender)
{
      // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
       //   sasDataModule->sasSQLConnection->Connected=true;
     }

   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active = false; // Flush previous data in set
   if (StudentbetalingenForm->ToggleButton->Caption == "op idnummer")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
        sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(StudentbetalingenForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else if (StudentbetalingenForm->ToggleButton->Caption == "op naam")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
        sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(StudentbetalingenForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
       else // op studienummer
         {
           //zoek eerst in inschrijving naar het studienummer en daarna in persoon naar het idnummer;
            sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
            sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
            sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where STUDIENR = :STUDIENR";
            sasDataModule->InschrijvingSQLDataSet->ParamByName("STUDIENR")->Value=LowerCase(StudentbetalingenForm->SearchEdit->Text);
            sasDataModule->InschrijvingSQLDataSet->Open();
            sasDataModule->InschrijvingClientDataSet->Active=true;
            String idnummer =(sasDataModule->InschrijvingClientDataSet->FindField("IDKAARTNR"))->AsString;
            sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
            sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(idnummer);
            sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
         }
   if (StudentbetalingenForm->ToggleButton->Caption != "op studienummer")
      {
        sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
     //   Application->MessageBox("", (sasDataModule->personClientDataSet->FieldByName("volgnr")->AsString).c_str(), MB_OK);

       sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
       sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
       sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR = :IDKAARTNR";
       sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(StudentbetalingenForm->IdCardDBEdit->Text);
       sasDataModule->InschrijvingSQLDataSet->Open();
       sasDataModule->InschrijvingClientDataSet->Active=true;
      }

        
}
//---------------------------------------------------------------------------

void __fastcall TStudentbetalingenForm::ToggleButtonClick(TObject *Sender)
{
 if (StudentbetalingenForm->ToggleButton->Caption == "op idnummer")
      StudentbetalingenForm->ToggleButton->Caption = "op naam";
   else  if(StudentbetalingenForm->ToggleButton->Caption == "op naam")
           StudentbetalingenForm->ToggleButton->Caption = "op studienummer";
        else
           StudentbetalingenForm->ToggleButton->Caption = "op idnummer";        
}
//---------------------------------------------------------------------------

void __fastcall TStudentbetalingenForm::PersoonDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
      //Als geen persoon opgegeven is mag je niet verder
    if ( IdCardDBEdit->Text == "") return;
    //nu moet gegaan worden naar het gekoppelde record in inschrijving
    sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
    sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->InschrijvingSQLDataSet->CommandText="select inschrijving.INSCHRIJFJAAR, inschrijving.* from inschrijving where IDKAARTNR = :IDKAARTNR ORDER BY inschrijving.INSCHRIJFJAAR DESC";
    sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(StudentbetalingenForm->IdCardDBEdit->Text);
    sasDataModule->InschrijvingSQLDataSet->Open();
    sasDataModule->InschrijvingClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

