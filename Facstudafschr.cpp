//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Facstudafschr.h"
#include "sasdm.h"
#include "sasbasictablesmod.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
static int Modus;
TFacStudAfschrijvingForm *FacStudAfschrijvingForm;
//---------------------------------------------------------------------------
__fastcall TFacStudAfschrijvingForm::TFacStudAfschrijvingForm(TComponent* Owner)
        : TForm(Owner)
{
  Modus = 0;
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

  FacStudAfschrijvingForm->AfschrijvingsDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   FacStudAfschrijvingForm->StudieDBMemo->ReadOnly=mode;
   FacStudAfschrijvingForm->RedenDBMemo->ReadOnly=mode;
   FacStudAfschrijvingForm->AfschrijvingsDatumDBEdit->ReadOnly=mode;
}
//---------------------------------------------------------------------------
static void DoReadStudent()
{
    FacStudAfschrijvingForm->AfschrijvingDBNavigator->Enabled = true;
    FacStudAfschrijvingForm->OpslaanButton->Enabled = false;
    FacStudAfschrijvingForm->SearchEdit->Show();
    FacStudAfschrijvingForm->SearchButton->Show();
    FacStudAfschrijvingForm->ToggleButton->Show();
    FacStudAfschrijvingForm->StudierichtingComboBox->Enabled = false;
    FacStudAfschrijvingForm->FaculteitComboBox->Enabled = false;
    FacStudAfschrijvingForm->IdCardDBEdit->ReadOnly = true;
    FacStudAfschrijvingForm->AfschrijvingDBNavigator->Visible = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoAfschrStudent()
{
    FacStudAfschrijvingForm->AfschrijvingDBNavigator->Enabled = true;
    FacStudAfschrijvingForm->OpslaanButton->Enabled = true;
    FacStudAfschrijvingForm->SearchEdit->Show();
    FacStudAfschrijvingForm->SearchButton->Show();
    FacStudAfschrijvingForm->ToggleButton->Show();
    FacStudAfschrijvingForm->StudierichtingComboBox->Enabled = false;
    FacStudAfschrijvingForm->IdCardDBEdit->ReadOnly = false;
    FacStudAfschrijvingForm->AfschrijvingDBNavigator->Visible = true;
    SetReadModus(false);
}
//---------------------------------------------------------------------------
void __fastcall TFacStudAfschrijvingForm::ModusKnopClick(TObject *Sender)
{
   Modus = (++Modus)%2;
   switch (Modus)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Lezen"; DoReadStudent();break;//lezen
   case 1: ModusKnop->Font->Color = clRed ;ModusKnop->Caption = "Afschrijven";DoAfschrStudent();break;//toevoegen
    };
}
//---------------------------------------------------------------------------
void __fastcall TFacStudAfschrijvingForm::Close1Click(TObject *Sender)
{
  HoofdScherm->Afschrijven1->Checked = false;
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TFacStudAfschrijvingForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   HoofdScherm->Afschrijven1->Checked = false;
   HoofdScherm->Show();

   Free();
}
//---------------------------------------------------------------------------
void __fastcall TFacStudAfschrijvingForm::Exit1Click(TObject *Sender)
{
  HoofdScherm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFacStudAfschrijvingForm::ToggleButtonClick(
      TObject *Sender)
{
  if (FacStudAfschrijvingForm->ToggleButton->Caption == "op idnummer")
      FacStudAfschrijvingForm->ToggleButton->Caption = "op naam";
  else
      FacStudAfschrijvingForm->ToggleButton->Caption = "op idnummer";
}
//---------------------------------------------------------------------------
void __fastcall TFacStudAfschrijvingForm::SearchButtonClick(
      TObject *Sender)
{
      // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
       sasDataModule->sasSQLConnection->Connected=true;
     }

   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
   if (FacStudAfschrijvingForm->ToggleButton->Caption == "op idnummer")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
        sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(FacStudAfschrijvingForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
        sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(FacStudAfschrijvingForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }

    sasDataModule->personSQLDataSet->Open();
    sasDataModule->personClientDataSet->Active=true;
    sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
    sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR like :IDKAARTNR";
    sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(FacStudAfschrijvingForm->IdCardDBEdit->Text+"%");
    sasDataModule->InschrijvingSQLDataSet->Open();
    sasDataModule->InschrijvingClientDataSet->Active=true;

  if (FacStudAfschrijvingForm->IdCardDBEdit->Text != "")
    {
//      Application->MessageBox("", "change", MB_OK);
      sasDataModule->EerdereInschrijvingenSQLDataSet->Close(); // Flush previous query
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->EerdereInschrijvingenSQLDataSet->CommandText= "select * from inschrijving where IDKAARTNR = :IDKAARTNR AND INSCHRIJFJAAR != :DITJAAR";
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("idkaartnr")->Value = LowerCase(FacStudAfschrijvingForm->IdCardDBEdit->Text); // Append the '%' sign to search for names like the one input in the box
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("DITJAAR")->Value =CurrentYear();
      sasDataModule->EerdereInschrijvingenSQLDataSet->Open();
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=true;
    }
    FacStudAfschrijvingForm->AfschrijvingsDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------
void __fastcall TFacStudAfschrijvingForm::AfschrijvingDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
    //nu moet gegaan worden naar het gekoppelde record in inschrijving
    sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
    sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR like :IDKAARTNR";
    sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(FacStudAfschrijvingForm->IdCardDBEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
    sasDataModule->InschrijvingSQLDataSet->Open();
    sasDataModule->InschrijvingClientDataSet->Active=true;


  if (FacStudAfschrijvingForm->IdCardDBEdit->Text != "")
    {
//      Application->MessageBox("", "change", MB_OK);
      sasDataModule->EerdereInschrijvingenSQLDataSet->Close(); // Flush previous query
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->EerdereInschrijvingenSQLDataSet->CommandText= "select * from inschrijving where IDKAARTNR = :IDKAARTNR AND INSCHRIJFJAAR != :DITJAAR";
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("idkaartnr")->Value = LowerCase(FacStudAfschrijvingForm->IdCardDBEdit->Text); // Append the '%' sign to search for names like the one input in the box
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("DITJAAR")->Value =CurrentYear();
      sasDataModule->EerdereInschrijvingenSQLDataSet->Open();
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=true;
    }
   FacStudAfschrijvingForm->AfschrijvingsDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------
void __fastcall TFacStudAfschrijvingForm::OpslaanButtonClick(
      TObject *Sender)
{
    //  We hoeven alleen de velden afschrijvingsdatum en reden weg te schrijven
      sasDataModule->InschrijvingSQLDataSet->CommandType = ctQuery;
      sasDataModule->InschrijvingSQLDataSet->CommandText = "UPDATE INSCHRIJVING SET AFSCHRIJVINGSDATUM=:AFSCHRIJVINGSDATUM,REDEN=:REDEN WHERE STUDIENR=:STUDIENR";
      sasDataModule->InschrijvingSQLDataSet->Params->Items[0]->AsDate = FacStudAfschrijvingForm->AfschrijvingsDatumDBEdit->Text;
      sasDataModule->InschrijvingSQLDataSet->Params->Items[1]->AsMemo = FacStudAfschrijvingForm->RedenDBMemo->Text;
      sasDataModule->InschrijvingSQLDataSet->Params->Items[2]->AsString = FacStudAfschrijvingForm->StudieNRDBEdit->Text;
      sasDataModule->InschrijvingSQLDataSet->ExecSQL();
}
//---------------------------------------------------------------------------

