//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "docentbetrekking.h"
#include "sasdm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDocentBetrekkingForm *DocentBetrekkingForm;
static int Modus;
static String personquery;

//---------------------------------------------------------------------------
__fastcall TDocentBetrekkingForm::TDocentBetrekkingForm(TComponent* Owner)
        : TForm(Owner)
{
  Modus = 0;
  personquery = "select * from persoon left join Docentbetrekking on persoon.VOLGNR = Docentbetrekking.VOlGNR where Docentbetrekking.VOLGNR NOT NLL";
  studierichtingSQLDataSet->Active = true;
  sasDataModule->FaculteitSQLDataSet->Active = true;
  docentbetrekkingSQLDataSet->Active = true;
  docentbetrekkingClientDataSet->Active = true;
  faculteitClientDataSet->Active = true;
  studierichtingClientDataSet->Active = true;
  personClientDataSet->Active = true;
}
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   DocentBetrekkingForm->TelefoonDBEdit->ReadOnly=mode;
   DocentBetrekkingForm->GebouwDBEdit->ReadOnly=mode;
   DocentBetrekkingForm->KamerDBEdit->ReadOnly=mode;
   DocentBetrekkingForm->InDienstDBEdit->ReadOnly=mode;
   DocentBetrekkingForm->UitDienstDBEdit->ReadOnly=mode;
   DocentBetrekkingForm->CommentDBMemo->ReadOnly=mode;
   DocentBetrekkingForm->FunctieDBEdit->ReadOnly=mode;
}
//--------------------------------------------------------------------------

static void DoRead()
{
    DocentBetrekkingForm->FaculteitComboBox->Enabled = false;
    DocentBetrekkingForm->StudierichtingComboBox->Enabled = false;
    DocentBetrekkingForm->DocentBetrekkingNavigator->Enabled = true;
    DocentBetrekkingForm->NieuwButton->Enabled = false;
    DocentBetrekkingForm->OpslaanButton->Enabled = false;
    DocentBetrekkingForm->VerwijderButton->Enabled = false;
    DocentBetrekkingForm->SearchEdit->Show();
    DocentBetrekkingForm->SearchButton->Show();
    DocentBetrekkingForm->ToggleButton->Show();
 //   DocentBetrekkingForm->PersoonDBNavigator->Enabled = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    DocentBetrekkingForm->FaculteitComboBox->Enabled = false;
    DocentBetrekkingForm->StudierichtingComboBox->Enabled = false;
    DocentBetrekkingForm->DocentBetrekkingNavigator->Enabled = true;
    DocentBetrekkingForm->NieuwButton->Enabled = false;
    DocentBetrekkingForm->OpslaanButton->Enabled = false;
    DocentBetrekkingForm->VerwijderButton->Enabled = true;
    DocentBetrekkingForm->SearchEdit->Show();
    DocentBetrekkingForm->SearchButton->Show();
    DocentBetrekkingForm->ToggleButton->Show();
 //   DocentBetrekkingForm->PersoonDBNavigator->Enabled = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
    DocentBetrekkingForm->FaculteitComboBox->Enabled = true;
    DocentBetrekkingForm->StudierichtingComboBox->Enabled = true;
    DocentBetrekkingForm->DocentBetrekkingNavigator->Enabled = true;
    DocentBetrekkingForm->NieuwButton->Enabled = false;
    DocentBetrekkingForm->OpslaanButton->Enabled = true;
    DocentBetrekkingForm->VerwijderButton->Enabled = false;
    DocentBetrekkingForm->SearchEdit->Show();
    DocentBetrekkingForm->SearchButton->Show();
    DocentBetrekkingForm->ToggleButton->Show();
 //   DocentBetrekkingForm->PersoonDBNavigator->Enabled = true;
    SetReadModus(false);
}
//----------------------------------------------------------------------------

static void  DoInsert()
{
    DocentBetrekkingForm->FaculteitComboBox->Enabled = true;
    DocentBetrekkingForm->StudierichtingComboBox->Enabled = false;
    DocentBetrekkingForm->DocentBetrekkingNavigator->Enabled = false;
    DocentBetrekkingForm->NieuwButton->Enabled = true;
    DocentBetrekkingForm->OpslaanButton->Enabled = false;
    DocentBetrekkingForm->VerwijderButton->Enabled = false;
  //  DocentBetrekkingForm->SearchEdit->Hide();
  //  DocentBetrekkingForm->ToggleButton->Hide();
  //  DocentBetrekkingForm->SearchButton->Hide();
//    DocentBetrekkingForm->PersoonDBNavigator->Enabled = true;
    SetReadModus(false);
}

//---------------------------------------------------------------------------
void __fastcall TDocentBetrekkingForm::ModusKnopClick(TObject *Sender)
{
   Modus = (++Modus)%4;
   switch (Modus)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Lezen"; DoRead();break;//lezen
   case 1: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Toevoegen";DoInsert();break;//toevoegen
   case 2: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Wijzigen";DoUpdate();break;//wijzigen
   case 3: ModusKnop->Font->Color = clRed ;ModusKnop->Caption = "Verwijderen";DoDelete();//verwijderen
    };
}
//---------------------------------------------------------------------------

void __fastcall TDocentBetrekkingForm::ToggleButtonClick(TObject *Sender)
{
 if (DocentBetrekkingForm->ToggleButton->Caption == "op idnummer")
      DocentBetrekkingForm->ToggleButton->Caption = "op naam";
  else
      DocentBetrekkingForm->ToggleButton->Caption = "op idnummer";
}
//---------------------------------------------------------------------------

void __fastcall TDocentBetrekkingForm::SearchButtonClick(TObject *Sender)
{
   // Check if the connection is already established
   personClientDataSet->Filtered = true;
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
        sasDataModule->sasSQLConnection->Connected=true;
     }

 //  sasDataModule->personSQLDataSet->Close(); // Flush previous query
   personClientDataSet->Active=false; // Flush previous data in set
   if (DocentBetrekkingForm->ToggleButton->Caption == "op idnummer")
     {
      personClientDataSet->Filter =   String("IDKAARTNR like ") + String("'") + DocentBetrekkingForm->SearchEdit->Text + String("%'");
     }
   else
     {
       personClientDataSet->Filter = String("NAAM like ") + String("'") + DocentBetrekkingForm->SearchEdit->Text + String("%'");
     }
  personClientDataSet->Active=true;
  last->Text= String(personClientDataSet->RecordCount);
  first->Text= String(personClientDataSet->RecNo);
 //Nu moet gezocht worden in docentbetrekking
  docentbetrekkingClientDataSet->Active=false; // Flush previous data in set
  docentbetrekkingClientDataSet->Filtered = true;
  docentbetrekkingClientDataSet->Filter =   String("IDKAARTNR like ") + String("'") + DocentBetrekkingForm->IdCardDBEdit->Text + String("'");
  docentbetrekkingClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TDocentBetrekkingForm::NieuwButtonClick(TObject *Sender)
{
  if (sasDataModule->sasSQLConnection->Connected!=true)
        {
                sasDataModule->sasSQLConnection->Connected=true;
        }
  docentbetrekkingClientDataSet->Active=false; // Flush previous data in set
 //   Application->MessageBoxA("12","",MB_OK);
  docentbetrekkingClientDataSet->Filtered = true;
  docentbetrekkingClientDataSet->Filter= String("  IDKAARTNR like ") + "123456";
  docentbetrekkingClientDataSet->Active = true;
  DocentBetrekkingForm->OpslaanButton->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TDocentBetrekkingForm::OpslaanButtonClick(TObject *Sender)
{
Variant leeg = NULL;
  char buf[5];

  if (Modus == 1)
    {
    if (DocentBetrekkingForm->IdCardDBEdit->Text == "")
      {
         Application->MessageBox("U moet eerst een persoon selecteren", "Probeer het opnieuw", MB_OK);
         return;
      }
      docentbetrekkingSQLDataSet->CommandText = "INSERT INTO DOCENTBETREKKING (IDKAARTNR,COMMENTAAR,INDIENSTDATUM,UITDIENSTDATUM,GEBOUW,KAMER,TELEFOON,FUNCTIE,FACULTEIT,STUDIERICHTING)"
                                                                  "VALUES(:IDKAARTNR,:COMMENTAAR, :INDIENSTDATUM,:UITDIENSTDATUM,:GEBOUW,:KAMER,:TELEFOON,:FUNCTIE,:FACULTEIT,:STUDIERICHTING)";
      docentbetrekkingSQLDataSet->Params->Items[0]->AsString = DocentBetrekkingForm->IdCardDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[1]->AsString = DocentBetrekkingForm->CommentDBMemo->Text;
      docentbetrekkingSQLDataSet->Params->Items[2]->AsString = DocentBetrekkingForm->InDienstDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[3]->AsString = DocentBetrekkingForm->UitDienstDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[4]->AsString = DocentBetrekkingForm->GebouwDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[5]->AsString = DocentBetrekkingForm->KamerDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[6]->AsString = DocentBetrekkingForm->TelefoonDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[7]->AsString = DocentBetrekkingForm->FunctieDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[8]->AsString = DocentBetrekkingForm->FaculteitComboBox->KeyValue;
      docentbetrekkingSQLDataSet->Params->Items[9]->AsString = DocentBetrekkingForm->StudierichtingComboBox->KeyValue;
     DocentBetrekkingForm->NieuwButton->Enabled = true;
     DocentBetrekkingForm->OpslaanButton->Enabled = false;
     }

   else if (Modus == 2)
    {
      docentbetrekkingSQLDataSet->CommandType = ctQuery;
      docentbetrekkingSQLDataSet->CommandText = "UPDATE DOCENTBETREKKING SET COMMENTAAR=:COMENTAAR,INDIENSTDATUM=:INDIENSTDATUM,UITDIENSTDATUM=:UITDIENSTDATUM,GEBOUW=:GEBOUW,KAMER=:KAMER,TELEFOON=:TELEFOON,FUNCTIE=:FUNCTIE,FACULTEIT=:FACULTEIT,STUDIERICHTING=:STUDIERICHTING WHERE IDKAARTNR =:IDKAARTNR";
      docentbetrekkingSQLDataSet->Params->Items[0]->AsString = DocentBetrekkingForm->CommentDBMemo->Text;
      docentbetrekkingSQLDataSet->Params->Items[1]->AsString = DocentBetrekkingForm->InDienstDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[2]->AsString = DocentBetrekkingForm->UitDienstDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[3]->AsString = DocentBetrekkingForm->GebouwDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[4]->AsString = DocentBetrekkingForm->KamerDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[5]->AsString = DocentBetrekkingForm->TelefoonDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[6]->AsString = DocentBetrekkingForm->FunctieDBEdit->Text;
      docentbetrekkingSQLDataSet->Params->Items[7]->AsString = DocentBetrekkingForm->FaculteitComboBox->KeyValue;
      docentbetrekkingSQLDataSet->Params->Items[8]->AsString = DocentBetrekkingForm->StudierichtingComboBox->KeyValue;
      docentbetrekkingSQLDataSet->Params->Items[9]->AsString = DocentBetrekkingForm->IdCardDBEdit->Text;
     }
    docentbetrekkingClientDataSet->Close();
    docentbetrekkingSQLDataSet->Close();
    try
      {
        docentbetrekkingSQLDataSet->ExecSQL();
      }
    catch (Exception &exception)
      {
         Application->ShowException(&exception);
      }
//      Application->MessageBoxA("8","",MB_OK);
     docentbetrekkingSQLDataSet->CommandText = "select * from docentbetrekking";

     docentbetrekkingSQLDataSet->Open();
     docentbetrekkingClientDataSet->Open();
}
//---------------------------------------------------------------------------

void __fastcall TDocentBetrekkingForm::VerwijderButtonClick(
      TObject *Sender)
{
  docentbetrekkingSQLDataSet->CommandType = ctQuery;
  docentbetrekkingSQLDataSet->CommandText = "DELETE FROM docentbetrekking WHERE IDKAARTNR =   :IDKAARTNR ";
  docentbetrekkingSQLDataSet->Params->Items[0]->AsString = DocentBetrekkingForm->IdCardDBEdit->Text;
  docentbetrekkingSQLDataSet->ExecSQL();

  docentbetrekkingSQLDataSet->Close(); // Flush previous query
  docentbetrekkingClientDataSet->Active=false; // Flush previous data in set
  docentbetrekkingSQLDataSet->CommandText="select * from docentbetrekking where IDKAARTNR like :Name";
  docentbetrekkingSQLDataSet->ParamByName("IDKAARTNR")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
  docentbetrekkingSQLDataSet->Open();
  docentbetrekkingClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TDocentBetrekkingForm::FaculteitComboBoxClick(
      TObject *Sender)
{
// Application->MessageBoxA("8","",MB_OK);
  DocentBetrekkingForm->StudierichtingComboBox->Enabled = true;
  DocentBetrekkingForm->studierichtingClientDataSet->Active=false; // Flush previous data in set
  DocentBetrekkingForm->studierichtingClientDataSet->Filtered = true;
  DocentBetrekkingForm->studierichtingClientDataSet->Filter = String("faculteit_id = ") + "'" + DocentBetrekkingForm->FaculteitComboBox->KeyValue +"'";
  DocentBetrekkingForm->studierichtingClientDataSet->Active=true;
  Label12->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TDocentBetrekkingForm::PersoonDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{

  last->Text= String(personClientDataSet->RecordCount);
  first->Text= String(personClientDataSet->RecNo);
  //Nu moet indien er een ander docent gekozen is, alle betrekingen van deze docent getoond worden.
  //Nu moet gezocht worden in docentbetrekking
  docentbetrekkingClientDataSet->Active=false; // Flush previous data in set
  docentbetrekkingClientDataSet->Filtered = true;
  docentbetrekkingClientDataSet->Filter =   String("IDKAARTNR = ") + String("'") + DocentBetrekkingForm->IdCardDBEdit->Text + String("'");
  docentbetrekkingClientDataSet->Active=true;
}
//---------------------------------------------------------------------------





