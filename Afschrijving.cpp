//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Afschrijving.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
static int Modus;
TAfschrijvingForm *AfschrijvingForm;
//---------------------------------------------------------------------------

__fastcall TAfschrijvingForm::TAfschrijvingForm(TComponent* Owner)
        : TForm(Owner)
{
  Modus = 0;
}
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   AfschrijvingForm->StudierichtingComboBox->ReadOnly=mode;
   AfschrijvingForm->StudieDBMemo->ReadOnly=mode;
}
//--------------------------------------------------------------------------

static void DoReadSchkst()
{
    AfschrijvingForm->AfschrijvingDBNavigator->Enabled = true;
    AfschrijvingForm->OpslaanButton->Enabled = false;
    AfschrijvingForm->SearchEdit->Show();
    AfschrijvingForm->SearchButton->Show();
    AfschrijvingForm->ToggleButton->Show();
    AfschrijvingForm->IdCardDBEdit->ReadOnly = true;
    AfschrijvingForm->AfschrijvingDBNavigator->Visible = true;
    SetReadModus(true);
}
//--------------------------------------------------------------------------

static void DoReadStudent()
{
    AfschrijvingForm->AfschrijvingDBNavigator->Enabled = true;
    AfschrijvingForm->OpslaanButton->Enabled = false;
    AfschrijvingForm->SearchEdit->Show();
    AfschrijvingForm->SearchButton->Show();
    AfschrijvingForm->ToggleButton->Show();
    AfschrijvingForm->StudierichtingComboBox->Enabled = false;
    AfschrijvingForm->FaculteitComboBox->Enabled = false;
    AfschrijvingForm->IdCardDBEdit->ReadOnly = true;
    AfschrijvingForm->AfschrijvingDBNavigator->Visible = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoSchkstAfschr()
{
    AfschrijvingForm->AfschrijvingDBNavigator->Enabled = true;
    AfschrijvingForm->OpslaanButton->Enabled = true;
    AfschrijvingForm->SearchEdit->Show();
    AfschrijvingForm->SearchButton->Show();
    AfschrijvingForm->ToggleButton->Show();
    SetReadModus(false);
//    Schakelstudent->StudierichtingComboBox->Enabled = false;
    AfschrijvingForm->IdCardDBEdit->ReadOnly = false;
    AfschrijvingForm->AfschrijvingDBNavigator->Visible = true;
}
//----------------------------------------------------------------------------

static void DoStudentAfschr()
{
    AfschrijvingForm->AfschrijvingDBNavigator->Enabled = true;
    AfschrijvingForm->OpslaanButton->Enabled = true;
    AfschrijvingForm->SearchEdit->Show();
    AfschrijvingForm->SearchButton->Show();
    AfschrijvingForm->ToggleButton->Show();
    SetReadModus(false);
    AfschrijvingForm->StudierichtingComboBox->Enabled = false;
    AfschrijvingForm->FaculteitComboBox->Enabled = true;
    AfschrijvingForm->IdCardDBEdit->ReadOnly = false;
    AfschrijvingForm->AfschrijvingDBNavigator->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TAfschrijvingForm::ModusKnopClick(TObject *Sender)
{
   Modus = (++Modus)%4;
   switch (Modus)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Student lezen"; DoReadStudent();break;//lezen
   case 1: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Student afschr";DoStudentAfschr();break;//toevoegen
   case 2: ModusKnop->Font->Color = clRed ;ModusKnop->Caption = "Schkst lezen";DoReadSchkst();break;//wijzigen
   case 3: ModusKnop->Font->Color = clRed ;ModusKnop->Caption = "Schkst afschr";DoSchkstAfschr();//verwijderen
    };
}
//---------------------------------------------------------------------------
void __fastcall TAfschrijvingForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   HoofdScherm->Afschrijving1->Checked = false;
   HoofdScherm->Show();

   Free();
}
//---------------------------------------------------------------------------

void __fastcall TAfschrijvingForm::Close1Click(TObject *Sender)
{
  HoofdScherm->Afschrijving1->Checked = false;
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TAfschrijvingForm::Exit1Click(TObject *Sender)
{
  HoofdScherm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TAfschrijvingForm::ToggleButtonClick(TObject *Sender)
{
 if (AfschrijvingForm->ToggleButton->Caption == "op idnummer")
      AfschrijvingForm->ToggleButton->Caption = "op naam";
  else
      AfschrijvingForm->ToggleButton->Caption = "op idnummer";

}
//---------------------------------------------------------------------------

void __fastcall TAfschrijvingForm::SearchButtonClick(TObject *Sender)
{
       // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
       sasDataModule->sasSQLConnection->Connected=true;
     }

   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
   if (Faculteitstudent->ToggleButton->Caption == "op idnummer")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
        sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Faculteitstudent->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
        sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(Faculteitstudent->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }

    sasDataModule->personSQLDataSet->Open();
    sasDataModule->personClientDataSet->Active=true;
    sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
    sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR like :IDKAARTNR";
    sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Faculteitstudent->IdCardDBEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
    sasDataModule->InschrijvingSQLDataSet->Open();
    sasDataModule->InschrijvingClientDataSet->Active=true;


  if (Faculteitstudent->IdCardDBEdit->Text != "")
    {
      Application->MessageBox("", "change", MB_OK);
      sasDataModule->EerdereInschrijvingenSQLDataSet->Close(); // Flush previous query
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->EerdereInschrijvingenSQLDataSet->CommandText= "select * from inschrijving where IDKAARTNR = :IDKAARTNR AND INSCHRIJFJAAR != :DITJAAR";
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("idkaartnr")->Value = LowerCase(Faculteitstudent->IdCardDBEdit->Text); // Append the '%' sign to search for names like the one input in the box
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("DITJAAR")->Value =CurrentYear();
      sasDataModule->EerdereInschrijvingenSQLDataSet->Open();
     sasDataModule->EerdereInschrijvingenClientDataSet->Active=true;
    }

}
//---------------------------------------------------------------------------

