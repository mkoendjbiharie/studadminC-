//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Schstudafschr.h"
#include "sasdm.h"
#include "sasbasictablesmod.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
static int Modus;
TSchStudAfschrijvingForm *SchStudAfschrijvingForm;
//---------------------------------------------------------------------------
__fastcall TSchStudAfschrijvingForm::TSchStudAfschrijvingForm(TComponent* Owner)
        : TForm(Owner)
{
  Modus = 0;
  sasDataModule->personSQLDataSet->Active = true;
  sasDataModule->SchakelSQLDataSet->Active = true;
  sasDataModule->FaculteitSQLDataSet->Active = true;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  SasBasicTables->SysteemSQLDataSet->Active = true;

  sasDataModule->personClientDataSet->Active = true;
  sasDataModule->SchakelClientDataSet->Active = true;
  sasDataModule->FaculteitClientDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;
  SasBasicTables->SysteemClientDataSet->Active = true;

  SchStudAfschrijvingForm->AfschrijvingsDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   SchStudAfschrijvingForm->RedenDBMemo->ReadOnly=mode;
   SchStudAfschrijvingForm->StudieDBMemo->ReadOnly=mode;
}
//---------------------------------------------------------------------------
static void DoReadSchStudent()
{
    SchStudAfschrijvingForm->AfschrijvingDBNavigator->Enabled = true;
    SchStudAfschrijvingForm->OpslaanButton->Enabled = false;
    SchStudAfschrijvingForm->SearchEdit->Show();
    SchStudAfschrijvingForm->SearchButton->Show();
    SchStudAfschrijvingForm->ToggleButton->Show();
    SchStudAfschrijvingForm->StudierichtingComboBox->Enabled = false;
    SchStudAfschrijvingForm->IdCardDBEdit->ReadOnly = true;
    SchStudAfschrijvingForm->AfschrijvingDBNavigator->Visible = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoAfschrSchStudent()
{
    SchStudAfschrijvingForm->AfschrijvingDBNavigator->Enabled = true;
    SchStudAfschrijvingForm->OpslaanButton->Enabled = true;
    SchStudAfschrijvingForm->SearchEdit->Show();
    SchStudAfschrijvingForm->SearchButton->Show();
    SchStudAfschrijvingForm->ToggleButton->Show();
    SchStudAfschrijvingForm->StudierichtingComboBox->Enabled = false;
    SchStudAfschrijvingForm->IdCardDBEdit->ReadOnly = false;
    SchStudAfschrijvingForm->AfschrijvingDBNavigator->Visible = true;
    SetReadModus(false);
}
//----------------------------------------------------------------------------

void __fastcall TSchStudAfschrijvingForm::ModusKnopClick(TObject *Sender)
{
   Modus = (++Modus)%2;
   switch (Modus)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Lezen"; DoReadSchStudent();break;//lezen
   case 1: ModusKnop->Font->Color = clRed ;ModusKnop->Caption = "Afschrijven";DoAfschrSchStudent();break;//toevoegen
    };
}
//---------------------------------------------------------------------------

void __fastcall TSchStudAfschrijvingForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   HoofdScherm->Afschrijven2->Checked = false;
   HoofdScherm->Show();

   Free();
}
//---------------------------------------------------------------------------
void __fastcall TSchStudAfschrijvingForm::Close1Click(TObject *Sender)
{
  HoofdScherm->Afschrijven2->Checked = false;
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TSchStudAfschrijvingForm::Exit1Click(TObject *Sender)
{
   HoofdScherm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TSchStudAfschrijvingForm::ToggleButtonClick(
      TObject *Sender)
{
 if (SchStudAfschrijvingForm->ToggleButton->Caption == "op idnummer")
      SchStudAfschrijvingForm->ToggleButton->Caption = "op naam";
  else
      SchStudAfschrijvingForm->ToggleButton->Caption = "op idnummer";
}
//---------------------------------------------------------------------------

void __fastcall TSchStudAfschrijvingForm::SearchButtonClick(
      TObject *Sender)
{
    // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
       sasDataModule->sasSQLConnection->Connected=true;
     }

   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
   if (SchStudAfschrijvingForm->ToggleButton->Caption == "op idnummer")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
        sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(SchStudAfschrijvingForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
        sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(SchStudAfschrijvingForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }

    sasDataModule->personSQLDataSet->Open();
    sasDataModule->personClientDataSet->Active=true;
    sasDataModule->SchakelSQLDataSet->Close(); // Flush previous query
    sasDataModule->SchakelClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->SchakelSQLDataSet->CommandText="select * from schakel where IDKAARTNR like :IDKAARTNR";
    sasDataModule->SchakelSQLDataSet->ParamByName("idkaartnr")->Value=\
    LowerCase(SchStudAfschrijvingForm->IdCardDBEdit->Text+"%");
    sasDataModule->SchakelSQLDataSet->Open();
    sasDataModule->SchakelClientDataSet->Active=true;

  if (SchStudAfschrijvingForm->IdCardDBEdit->Text != "")
    {
//      Application->MessageBox("", "change", MB_OK);
      sasDataModule->EerdereInschrijvingenSQLDataSet->Close(); // Flush previous query
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->EerdereInschrijvingenSQLDataSet->CommandText= "select * from inschrijving where IDKAARTNR = \
      :IDKAARTNR AND INSCHRIJFJAAR != :DITJAAR";
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("idkaartnr")->Value = \
      LowerCase(SchStudAfschrijvingForm->IdCardDBEdit->Text); // Append the '%' sign to search for names like the one input in the box
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("DITJAAR")->Value =CurrentYear();
      sasDataModule->EerdereInschrijvingenSQLDataSet->Open();
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=true;
    }
  SchStudAfschrijvingForm->AfschrijvingsDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------

void __fastcall TSchStudAfschrijvingForm::AfschrijvingDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
   //nu moet gegaan worden naar het gekoppelde record in inschrijving
    sasDataModule->SchakelSQLDataSet->Close(); // Flush previous query
    sasDataModule->SchakelClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->SchakelSQLDataSet->CommandText="select * from schakel where IDKAARTNR like :IDKAARTNR";
    sasDataModule->SchakelSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(SchStudAfschrijvingForm->\
    IdCardDBEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
    sasDataModule->SchakelSQLDataSet->Open();
    sasDataModule->SchakelClientDataSet->Active=true;


  if (SchStudAfschrijvingForm->IdCardDBEdit->Text != "")
    {
//      Application->MessageBox("", "change", MB_OK);
      sasDataModule->EerdereInschrijvingenSQLDataSet->Close(); // Flush previous query
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->EerdereInschrijvingenSQLDataSet->CommandText= "select * from inschrijving where\
       IDKAARTNR = :IDKAARTNR AND INSCHRIJFJAAR != :DITJAAR";
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("idkaartnr")->Value = \
      LowerCase(SchStudAfschrijvingForm->IdCardDBEdit->Text); // Append the '%' sign to search for names like the one input in the box
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("DITJAAR")->Value =CurrentYear();
      sasDataModule->EerdereInschrijvingenSQLDataSet->Open();
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=true;
    }
 SchStudAfschrijvingForm->AfschrijvingsDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------

void __fastcall TSchStudAfschrijvingForm::OpslaanButtonClick(
      TObject *Sender)
{
   sasDataModule->SchakelSQLDataSet->CommandType = ctQuery;
   sasDataModule->SchakelSQLDataSet->CommandText = "UPDATE SCHAKEL SET AFSCHRIJVINGSDATUM=:AFSCHRIJVINGSDATUM, \
   MEMO=:MEMO, REDEN=:REDEN WHERE STUDIENR = :STUDIENR";
/*  if (SchStudAfschrijvingForm->AfschrijvingsDatumDBEdit->Text == "")
     {
       sasDataModule->SchakelSQLDataSet->Params->Items[0]->Clear();
 //    Application->MessageBox("leeg", "Probeer het opnieuw", MB_OK);
     }
  else*/
   sasDataModule->SchakelSQLDataSet->Params->Items[0]->AsDate = SchStudAfschrijvingForm->AfschrijvingsDatumDBEdit->Text;
   sasDataModule->SchakelSQLDataSet->Params->Items[1]->AsString = SchStudAfschrijvingForm->StudieDBMemo->Text;
   sasDataModule->SchakelSQLDataSet->Params->Items[2]->AsString = SchStudAfschrijvingForm->RedenDBMemo->Text;
   sasDataModule->SchakelSQLDataSet->Params->Items[3]->AsString = SchStudAfschrijvingForm->StudieNRDBEdit->Text;
   try
     {sasDataModule->SchakelSQLDataSet->ExecSQL();}
   catch (const Exception &E)
     {
      Application->MessageBox("Onjuist datum format", "Probeer het opnieuw", MB_OK);
     }
}
//---------------------------------------------------------------------------






