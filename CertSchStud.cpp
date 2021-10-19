//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CertSchStud.h"
#include "sasdm.h"
#include "sasbasictablesmod.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCertificaatSchakelStudent *CertificaatSchakelStudent;
static int FModus;
//---------------------------------------------------------------------------
__fastcall TCertificaatSchakelStudent::TCertificaatSchakelStudent(TComponent* Owner)
        : TForm(Owner)
{
  FModus = 0;
  sasDataModule->personSQLDataSet->Active = true;
  sasDataModule->SchakelSQLDataSet->Active = true;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  SasBasicTables->SysteemSQLDataSet->Active = true;


  sasDataModule->personClientDataSet->Active = true;
  sasDataModule->SchakelClientDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;
  /*

  Certificatenfaculteitstudent->NieuwButton->Enabled = false;
  Certificatenfaculteitstudent->OpslaanButton->Enabled = false;
  Certificatenfaculteitstudent->VerwijderButton->Enabled = false;
  DiplomaButton->Enabled = false;  */
  CertificaatSchakelStudent->AfgifteDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";

}
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
    CertificaatSchakelStudent->AfgifteDatumDBEdit->ReadOnly=mode;
    CertificaatSchakelStudent->AfgestudeerdDBRadioGroup->ReadOnly = mode;
}
//--------------------------------------------------------------------------

static void DoRead()
{
    CertificaatSchakelStudent->InschrijvingDBNavigator->Enabled = true;
    CertificaatSchakelStudent->OpslaanButton->Enabled = false;
    CertificaatSchakelStudent->SearchEdit->Show();
    CertificaatSchakelStudent->SearchButton->Show();
    CertificaatSchakelStudent->ToggleButton->Show();
    CertificaatSchakelStudent->IdCardDBEdit->ReadOnly = true;
    CertificaatSchakelStudent->InschrijvingDBNavigator->Visible = true;
    CertificaatSchakelStudent->AfgifteLabel->Enabled = false;
    CertificaatSchakelStudent->CertificaatLabel->Enabled = false;
    CertificaatSchakelStudent->AfgifteDatumDBEdit->Enabled = false;
    CertificaatSchakelStudent->AfgestudeerdDBRadioGroup->Enabled = false;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
    CertificaatSchakelStudent->OpslaanButton->Enabled = true;
    CertificaatSchakelStudent->SearchEdit->Show();
    CertificaatSchakelStudent->SearchButton->Show();
    CertificaatSchakelStudent->ToggleButton->Show();
    CertificaatSchakelStudent->IdCardDBEdit->ReadOnly = false;
    CertificaatSchakelStudent->InschrijvingDBNavigator->Visible = true;
    CertificaatSchakelStudent->AfgifteLabel->Enabled = true;
    CertificaatSchakelStudent->CertificaatLabel->Enabled = true;
    CertificaatSchakelStudent->AfgifteDatumDBEdit->Enabled = true;
    CertificaatSchakelStudent->AfgestudeerdDBRadioGroup->Enabled = true;
    SetReadModus(false);
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatSchakelStudent::Close1Click(TObject *Sender)
{
  HoofdScherm->Certificaat2->Checked = false;
  Close();
  HoofdScherm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatSchakelStudent::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  HoofdScherm->Certificaat2->Checked = false;
  HoofdScherm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatSchakelStudent::Exit1Click(TObject *Sender)
{
   HoofdScherm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatSchakelStudent::ModusKnopClick(TObject *Sender)
{
 FModus = (++FModus)%2;
   switch (FModus)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Lezen"; DoRead();break;//lezen
   case 1: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Wijzigen";DoUpdate();break;//wijzigen
   }
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatSchakelStudent::SearchButtonClick(
      TObject *Sender)
{
       // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
          sasDataModule->sasSQLConnection->Connected=true;

   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active = false; // Flush previous data in set
   if (CertificaatSchakelStudent->ToggleButton->Caption == "op idnummer")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
        sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(CertificaatSchakelStudent->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else if (CertificaatSchakelStudent->ToggleButton->Caption == "op naam")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
        sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(CertificaatSchakelStudent->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
       else // op studienummer
         {
           //zoek eerst in schakel naar het studienummer en daarna in persoon naar het idnummer;
            sasDataModule->SchakelSQLDataSet->Close(); // Flush previous query
            sasDataModule->SchakelClientDataSet->Active=false; // Flush previous data in set
            sasDataModule->SchakelSQLDataSet->CommandText="select * from schakel where STUDIENR = :STUDIENR";
            sasDataModule->SchakelSQLDataSet->ParamByName("STUDIENR")->Value=LowerCase(CertificaatSchakelStudent->SearchEdit->Text);
            sasDataModule->SchakelSQLDataSet->Open();
            sasDataModule->SchakelClientDataSet->Active=true;
            String idnummer =(sasDataModule->SchakelClientDataSet->FindField("IDKAARTNR"))->AsString;
            sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR = :IDKAARTNR";
            sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(idnummer);
            sasDataModule->personSQLDataSet->Open();
            sasDataModule->personClientDataSet->Active=true;
         }
   if (CertificaatSchakelStudent->ToggleButton->Caption != "op studienummer")
      {
        sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
     //   Application->MessageBox("", (sasDataModule->personClientDataSet->FieldByName("volgnr")->AsString).c_str(), MB_OK);

       sasDataModule->SchakelSQLDataSet->Close(); // Flush previous query
       sasDataModule->SchakelClientDataSet->Active=false; // Flush previous data in set
       sasDataModule->SchakelSQLDataSet->CommandText="select * from schakel where IDKAARTNR = :IDKAARTNR";
       sasDataModule->SchakelSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(CertificaatSchakelStudent->IdCardDBEdit->Text);
       sasDataModule->SchakelSQLDataSet->Open();
       sasDataModule->SchakelClientDataSet->Active=true;
      }
      CertificaatSchakelStudent->AfgifteDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatSchakelStudent::ToggleButtonClick(
      TObject *Sender)
{
  if (CertificaatSchakelStudent->ToggleButton->Caption == "op idnummer")
      CertificaatSchakelStudent->ToggleButton->Caption = "op naam";
   else  if(CertificaatSchakelStudent->ToggleButton->Caption == "op naam")
           CertificaatSchakelStudent->ToggleButton->Caption = "op studienummer";
        else
           CertificaatSchakelStudent->ToggleButton->Caption = "op idnummer";
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatSchakelStudent::PersoonDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
  //Als geen persoon opgegeven is mag je niet verder
    if ( IdCardDBEdit->Text == "") return;
    //nu moet gegaan worden naar het gekoppelde record in schakel
    sasDataModule->SchakelSQLDataSet->Close(); // Flush previous query
    sasDataModule->SchakelClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->SchakelSQLDataSet->CommandText="select schakel.SCHAKELJAAR, schakel.* from schakel where IDKAARTNR = :IDKAARTNR ORDER BY schakel.SCHAKELJAAR DESC";
    sasDataModule->SchakelSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(CertificaatSchakelStudent->IdCardDBEdit->Text);
    sasDataModule->SchakelSQLDataSet->Open();
    sasDataModule->SchakelClientDataSet->Active=true;
    CertificaatSchakelStudent->AfgifteDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatSchakelStudent::OpslaanButtonClick(
      TObject *Sender)
{
      Variant leeg = NULL;
   //Nu moeten de velden afgerond en afgiftedatum gewijzigd worden
     // in de schakel tabel

     if ((AfgestudeerdDBRadioGroup->Value == 1)&&(AfgifteDatumDBEdit->EditText == ""))
      {
         Application->MessageBox("U heeft de afgiftedatum niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
      sasDataModule->SchakelSQLDataSet->Close();
  //    sasDataModule->InschrijvingClientDataSet->Active = false;;
      sasDataModule->SchakelSQLDataSet->CommandType = ctQuery;
      if (AfgestudeerdDBRadioGroup->Value == 0)
         {
            sasDataModule->SchakelSQLDataSet->CommandText = "UPDATE SCHAKEL \
            SET AFGIFTEDATUM_CERTIFICAAT=NULL, AFGEROND=:AFGEROND WHERE STUDIENR =:STUDIENR";
            sasDataModule->SchakelSQLDataSet->Params->Items[0]->AsInteger = atoi(CertificaatSchakelStudent->AfgestudeerdDBRadioGroup->Value.c_str());
            sasDataModule->SchakelSQLDataSet->Params->Items[1]->AsString = CertificaatSchakelStudent->StudieNRDBEdit->Text;
         }            
      else
        {
            sasDataModule->SchakelSQLDataSet->CommandText = "UPDATE SCHAKEL \
            SET AFGIFTEDATUM_CERTIFICAAT=:AFGIFTEDATUM, AFGEROND=:AFGEROND WHERE STUDIENR =:STUDIENR";
            sasDataModule->SchakelSQLDataSet->Params->Items[0]->AsDate = CertificaatSchakelStudent->AfgifteDatumDBEdit->Text;
            sasDataModule->SchakelSQLDataSet->Params->Items[1]->AsInteger = atoi(CertificaatSchakelStudent->AfgestudeerdDBRadioGroup->Value.c_str());
            sasDataModule->SchakelSQLDataSet->Params->Items[2]->AsString = CertificaatSchakelStudent->StudieNRDBEdit->Text;
        }
      sasDataModule->SchakelSQLDataSet->ExecSQL();
  //    sasDataModule->InschrijvingSQLDataSet->Open();
  //    sasDataModule->InschrijvingClientDataSet->Active = true;
      CertificaatSchakelStudent->AfgifteDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------

void __fastcall TCertificaatSchakelStudent::AfgestudeerdDBRadioGroupChange(
      TObject *Sender)
{
 if  (AfgestudeerdDBRadioGroup->Value == 0)
      CertificaatSchakelStudent->AfgifteDatumDBEdit->EditText = "";
}
//---------------------------------------------------------------------------

