//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StudentFuncties.h"
#include "sasdm.h"
#include "sasbasictablesmod.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStudentfunctiesForm *StudentfunctiesForm;
static int FModus;
//---------------------------------------------------------------------------
__fastcall TStudentfunctiesForm::TStudentfunctiesForm(TComponent* Owner)
        : TForm(Owner)
{
  FModus = 0;
  sasDataModule->personSQLDataSet->Active = true;
  sasDataModule->InschrijvingSQLDataSet->Active = true;
  sasDataModule->FaculteitSQLDataSet->Active = true;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  SasBasicTables->SysteemSQLDataSet->Active = true;
  StudentfunctiesForm->vacatureSQLDataSet->Active = true;
  StudentfunctiesForm->functieSQLDataSet->Active = true;

  sasDataModule->personClientDataSet->Active = true;
  sasDataModule->InschrijvingClientDataSet->Active = true;
  sasDataModule->FaculteitClientDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;
  SasBasicTables->SysteemClientDataSet->Active = true;
  StudentfunctiesForm->vacatureClientDataSet->Active = true;
  StudentfunctiesForm->functieClientDataSet->Active = true;
  StudentfunctiesForm->StartdatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
  StudentfunctiesForm->EinddatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------
void __fastcall TStudentfunctiesForm::Close1Click(TObject *Sender)
{
  HoofdScherm->Functies1->Checked = false;
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TStudentfunctiesForm::Exit1Click(TObject *Sender)
{
  HoofdScherm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TStudentfunctiesForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   HoofdScherm->Functies1->Checked = false;
   HoofdScherm->Show();
   Free();
}
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   StudentfunctiesForm->StartdatumDBEdit->ReadOnly = mode;
   StudentfunctiesForm->EinddatumDBEdit->ReadOnly = mode;
   StudentfunctiesForm->TaakomschrijvingDBMemo->ReadOnly = mode;
   StudentfunctiesForm->AantalurenDBEdit->ReadOnly = mode;
}
//--------------------------------------------------------------------------

static void DoRead()
{
    StudentfunctiesForm->InschrijvingDBNavigator->Enabled = true;
    StudentfunctiesForm->SearchEdit->Show();
    StudentfunctiesForm->SearchButton->Show();
    StudentfunctiesForm->ToggleButton->Show();
    StudentfunctiesForm->IdCardDBEdit->ReadOnly = true;
    StudentfunctiesForm->InschrijvingDBNavigator->Visible = true;
    StudentfunctiesForm->NieuwButton->Enabled = false;
    StudentfunctiesForm->OpslaanButton->Enabled = false;
    StudentfunctiesForm->VerwijderButton->Enabled = false;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    StudentfunctiesForm->InschrijvingDBNavigator->Enabled = true;
    StudentfunctiesForm->SearchEdit->Show();
    StudentfunctiesForm->SearchButton->Show();
    StudentfunctiesForm->ToggleButton->Show();
    StudentfunctiesForm->IdCardDBEdit->ReadOnly = true;
    StudentfunctiesForm->InschrijvingDBNavigator->Visible = true;
    StudentfunctiesForm->NieuwButton->Enabled = false;
    StudentfunctiesForm->OpslaanButton->Enabled = false;
    StudentfunctiesForm->VerwijderButton->Enabled = true;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
    StudentfunctiesForm->SearchEdit->Show();
    StudentfunctiesForm->SearchButton->Show();
    StudentfunctiesForm->ToggleButton->Show();
    StudentfunctiesForm->IdCardDBEdit->ReadOnly = false;
    StudentfunctiesForm->InschrijvingDBNavigator->Visible = true;
    StudentfunctiesForm->NieuwButton->Enabled = false;
    StudentfunctiesForm->OpslaanButton->Enabled = true;
    StudentfunctiesForm->VerwijderButton->Enabled = false;
      SetReadModus(false);
}
//---------------------------------------------------------------------------

static void  DoInsert()
{
//    StudentfunctiesForm->InschrijvingDBNavigator->Enabled = false;
    StudentfunctiesForm->SearchEdit->Hide();
    StudentfunctiesForm->SearchButton->Hide();
    StudentfunctiesForm->ToggleButton->Hide();
    SetReadModus(false);
    StudentfunctiesForm->IdCardDBEdit->ReadOnly = false;
    StudentfunctiesForm->InschrijvingDBNavigator->Visible = true;
    StudentfunctiesForm->NieuwButton->Enabled = true;
    StudentfunctiesForm->OpslaanButton->Enabled = false;
    StudentfunctiesForm->VerwijderButton->Enabled = false;
 }
void __fastcall TStudentfunctiesForm::ModusKnopClick(TObject *Sender)
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

void __fastcall TStudentfunctiesForm::SearchButtonClick(TObject *Sender)
{
      // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
       //   sasDataModule->sasSQLConnection->Connected=true;
     }

   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active = false; // Flush previous data in set
   if (StudentfunctiesForm->ToggleButton->Caption == "op idnummer")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
        sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(StudentfunctiesForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else if (StudentfunctiesForm->ToggleButton->Caption == "op naam")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
        sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(StudentfunctiesForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
       else // op studienummer
         {
           //zoek eerst in inschrijving naar het studienummer en daarna in persoon naar het idnummer;
            sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
            sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
            sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where STUDIENR = :STUDIENR";
            sasDataModule->InschrijvingSQLDataSet->ParamByName("STUDIENR")->Value=LowerCase(StudentfunctiesForm->SearchEdit->Text);
            sasDataModule->InschrijvingSQLDataSet->Open();
            sasDataModule->InschrijvingClientDataSet->Active=true;
            String idnummer =(sasDataModule->InschrijvingClientDataSet->FindField("IDKAARTNR"))->AsString;
            sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
            sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(idnummer);
            sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
         }
   if (StudentfunctiesForm->ToggleButton->Caption != "op studienummer")
      {
        sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
     //   Application->MessageBox("", (sasDataModule->personClientDataSet->FieldByName("volgnr")->AsString).c_str(), MB_OK);

       sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
       sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
       sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR = :IDKAARTNR";
       sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(StudentfunctiesForm->IdCardDBEdit->Text);
       sasDataModule->InschrijvingSQLDataSet->Open();
       sasDataModule->InschrijvingClientDataSet->Active=true;
      }
    //Nu gaan we naar de functies van deze student
    if ( StudieNRDBEdit->Text == "") return;
    StudentfunctiesForm->vacatureSQLDataSet->Close(); // Flush previous query
    StudentfunctiesForm->vacatureClientDataSet->Active=false; // Flush previous data in set
    StudentfunctiesForm->vacatureSQLDataSet->CommandText="select vacature.* from vacature where STUDIENR = :STUDIENR";
    StudentfunctiesForm->vacatureSQLDataSet->ParamByName("STUDIENR")->Value=LowerCase(StudentfunctiesForm->StudieNRDBEdit->Text);
    StudentfunctiesForm->vacatureSQLDataSet->Open();
    StudentfunctiesForm->vacatureClientDataSet->Active=true;
    StudentfunctiesForm->StartdatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
    StudentfunctiesForm->EinddatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------

void __fastcall TStudentfunctiesForm::ToggleButtonClick(TObject *Sender)
{
 if (StudentfunctiesForm->ToggleButton->Caption == "op idnummer")
      StudentfunctiesForm->ToggleButton->Caption = "op naam";
   else  if(StudentfunctiesForm->ToggleButton->Caption == "op naam")
           StudentfunctiesForm->ToggleButton->Caption = "op studienummer";
        else
           StudentfunctiesForm->ToggleButton->Caption = "op idnummer";
}
//---------------------------------------------------------------------------

void __fastcall TStudentfunctiesForm::PersoonDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
      //Als geen persoon opgegeven is mag je niet verder
    if ( IdCardDBEdit->Text == "") return;
    //nu moet gegaan worden naar het gekoppelde record in inschrijving
    sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
    sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->InschrijvingSQLDataSet->CommandText="select inschrijving.INSCHRIJFJAAR, inschrijving.* from inschrijving where IDKAARTNR = :IDKAARTNR ORDER BY inschrijving.INSCHRIJFJAAR DESC";
    sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(StudentfunctiesForm->IdCardDBEdit->Text);
    sasDataModule->InschrijvingSQLDataSet->Open();
    sasDataModule->InschrijvingClientDataSet->Active=true;

    //Nu gaan we naar de functies van deze student
    if ( StudieNRDBEdit->Text == "") return;
    StudentfunctiesForm->vacatureSQLDataSet->Close(); // Flush previous query
    StudentfunctiesForm->vacatureClientDataSet->Active=false; // Flush previous data in set
    StudentfunctiesForm->vacatureSQLDataSet->CommandText="select vacature.* from vacature where STUDIENR = :STUDIENR";
    StudentfunctiesForm->vacatureSQLDataSet->ParamByName("STUDIENR")->Value=LowerCase(StudentfunctiesForm->StudieNRDBEdit->Text);
    StudentfunctiesForm->vacatureSQLDataSet->Open();
    StudentfunctiesForm->vacatureClientDataSet->Active=true;
    StudentfunctiesForm->StartdatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
  StudentfunctiesForm->EinddatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------

void __fastcall TStudentfunctiesForm::InschrijvingDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
     //We gaan naar de functies van deze student
    if ( StudieNRDBEdit->Text == "") return;
    StudentfunctiesForm->vacatureSQLDataSet->Close(); // Flush previous query
    StudentfunctiesForm->vacatureClientDataSet->Active=false; // Flush previous data in set
    StudentfunctiesForm->vacatureSQLDataSet->CommandText="select vacature.* from vacature where STUDIENR = :STUDIENR";
    StudentfunctiesForm->vacatureSQLDataSet->ParamByName("STUDIENR")->Value=LowerCase(StudentfunctiesForm->StudieNRDBEdit->Text);
    StudentfunctiesForm->vacatureSQLDataSet->Open();
    StudentfunctiesForm->vacatureClientDataSet->Active=true;
    StudentfunctiesForm->StartdatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
    StudentfunctiesForm->EinddatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------

void __fastcall TStudentfunctiesForm::NieuwButtonClick(TObject *Sender)
{
    StudentfunctiesForm->NieuwButton->Enabled = true;
    StudentfunctiesForm->OpslaanButton->Enabled = true;
    StudentfunctiesForm->VerwijderButton->Enabled = false;
    //Haal alle openstaande vacatures op
    StudentfunctiesForm->vacatureSQLDataSet->Close(); // Flush previous query
    StudentfunctiesForm->vacatureClientDataSet->Active=false; // Flush previous data in set
    StudentfunctiesForm->vacatureSQLDataSet->CommandText="select vacature.* from vacature where OPEN = :OPEN";
    StudentfunctiesForm->vacatureSQLDataSet->ParamByName("OPEN")->Value= 1;
    StudentfunctiesForm->vacatureSQLDataSet->Open();
    StudentfunctiesForm->vacatureClientDataSet->Active=true;
    StudentfunctiesForm->StartdatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
    StudentfunctiesForm->EinddatumDBEdit->Field->EditMask = "!0000/00/00;1;_";

}
//---------------------------------------------------------------------------

void __fastcall TStudentfunctiesForm::OpslaanButtonClick(TObject *Sender)
{
    String foutmelding = "";
    if  (StartdatumDBEdit->EditText == "") foutmelding = "U moet een startdatum opgeven.";
    else if  (EinddatumDBEdit->EditText == "") foutmelding = "U moet een einddatum opgeven.";
    else if  (VerantwoordelijkeDBEdit->Text == "") foutmelding = "U moet een verantwoordelijke opgeven.";
    else if  (AantalurenDBEdit->Text == "") foutmelding = "U moet het aantal uren opgeven.";

    if (foutmelding != "")
     {
       Application->MessageBox(foutmelding.c_str(), "" ,MB_OK|MB_ICONWARNING);
       return;
     }

   StudentfunctiesForm->NieuwButton->Enabled = true;
   StudentfunctiesForm->OpslaanButton->Enabled = false;
   StudentfunctiesForm->VerwijderButton->Enabled = false;


     if (FModus == 1) //Toevoegen
      {
      StudentfunctiesForm->vacatureSQLDataSet->CommandType = ctQuery;
      StudentfunctiesForm->vacatureSQLDataSet->CommandText = "UPDATE vacature \
      SET STUDIENR=:STUDIENR,OPEN =:OPEN WHERE VACATURE_ID =:VACATURE_ID ";
       StudentfunctiesForm->vacatureSQLDataSet->Params->Items[0]->AsString = StudentfunctiesForm->StudieNRDBEdit->Text;
       StudentfunctiesForm->vacatureSQLDataSet->Params->Items[1]->AsInteger = 0;
       StudentfunctiesForm->vacatureSQLDataSet->Params->Items[2]->AsInteger = StudentfunctiesForm->vacatureClientDataSet->FieldValues["VACATURE_ID"];
      }
   else if (FModus == 2) //Wijzigen
      {
      StudentfunctiesForm->vacatureSQLDataSet->CommandType = ctQuery;
      StudentfunctiesForm->vacatureSQLDataSet->CommandText = "UPDATE vacature SET STARTDATUM=:STARTDATUM,\
                      EINDDATUM=:EINDDATUM,TAAKOMSCHRIJVING =:TAAKOMSCHRIJVING, AANTALUREN =:AANTALUREN\
                      WHERE VACATURE_ID =:VACATURE_ID ";
       StudentfunctiesForm->vacatureSQLDataSet->Params->Items[0]->AsString = StudentfunctiesForm->StartdatumDBEdit->Text;
       StudentfunctiesForm->vacatureSQLDataSet->Params->Items[1]->AsString = StudentfunctiesForm->EinddatumDBEdit->Text;
       StudentfunctiesForm->vacatureSQLDataSet->Params->Items[2]->AsString = StudentfunctiesForm->TaakomschrijvingDBMemo->Text;
       StudentfunctiesForm->vacatureSQLDataSet->Params->Items[3]->AsString = StudentfunctiesForm->AantalurenDBEdit->Text;
       StudentfunctiesForm->vacatureSQLDataSet->Params->Items[4]->AsInteger = StudentfunctiesForm->vacatureClientDataSet->FieldValues["VACATURE_ID"];
      }
    vacatureSQLDataSet->ExecSQL();
}
//---------------------------------------------------------------------------



