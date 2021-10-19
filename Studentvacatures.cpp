//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Studentvacatures.h"
#include "sasdm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStudentVacaturesForm *StudentVacaturesForm;
static int FModus;
//---------------------------------------------------------------------------
__fastcall TStudentVacaturesForm::TStudentVacaturesForm(TComponent* Owner)
        : TForm(Owner)
{
  FModus = 0;
  StudentVacaturesForm->vacatureSQLDataSet->Active = true;
  StudentVacaturesForm->vacatureClientDataSet->Active = true;
  StudentVacaturesForm->functieSQLDataSet->Active = true;
  StudentVacaturesForm->functieClientDataSet->Active = true;
  StudentVacaturesForm->NieuwButton->Enabled = false;
  StudentVacaturesForm->OpslaanButton->Enabled = false;
  StudentVacaturesForm->VerwijderButton->Enabled = false;
  StudentVacaturesForm->StartdatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
  StudentVacaturesForm->EinddatumDBEdit->Field->EditMask = "!0000/00/00;1;_";

}
//---------------------------------------------------------------------------
void __fastcall TStudentVacaturesForm::Close1Click(TObject *Sender)
{
  HoofdScherm->Vacatures1->Checked = false;
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TStudentVacaturesForm::Exit1Click(TObject *Sender)
{
  HoofdScherm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TStudentVacaturesForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  HoofdScherm->Vacatures1->Checked = false;
  HoofdScherm->Show();
  Free();
}
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   StudentVacaturesForm->FunctieDBLookupComboBox->ReadOnly = mode;
   StudentVacaturesForm->StartdatumDBEdit->ReadOnly = mode;
   StudentVacaturesForm->EinddatumDBEdit->ReadOnly = mode;
   StudentVacaturesForm->VerantwoordelijkeDBEdit->ReadOnly = mode;
   StudentVacaturesForm->TaakomschrijvingDBMemo->ReadOnly = mode;
   StudentVacaturesForm->VakgebiedDBEdit->ReadOnly = mode;
   StudentVacaturesForm->AantalurenDBEdit->ReadOnly = mode;
//   StudentVacaturesForm->OpenDBRadioGroup->ReadOnly = mode;
}
//--------------------------------------------------------------------------

static void DoRead()
{
  //  StudentVacaturesForm->SearchEdit->Show();
    //StudentVacaturesForm->SearchButton->Show();
   // StudentVacaturesForm->ToggleButton->Show();
    StudentVacaturesForm->vacaturesDBNavigator->Enabled = true;
    StudentVacaturesForm->NieuwButton->Enabled = false;
    StudentVacaturesForm->OpslaanButton->Enabled = false;
    StudentVacaturesForm->VerwijderButton->Enabled = false;
//    StudentVacaturesForm->OpenDBRadioGroup->Enabled = false;

    SetReadModus(true);
     StudentVacaturesForm->vacatureSQLDataSet->Close(); // Flush previous query
     StudentVacaturesForm->vacatureClientDataSet->Active=false; // Flush previous data in set
     StudentVacaturesForm->vacatureSQLDataSet->CommandText="select * from vacature ";
     StudentVacaturesForm->vacatureSQLDataSet->Open();
     StudentVacaturesForm->vacatureClientDataSet->Active=true;
}
//----------------------------------------------------------------------------

static void DoDelete()
{
   // StudentVacaturesForm->SearchEdit->Show();
   // StudentVacaturesForm->SearchButton->Show();
   // StudentVacaturesForm->ToggleButton->Show();
    StudentVacaturesForm->vacaturesDBNavigator->Enabled = true;
    StudentVacaturesForm->NieuwButton->Enabled = false;
    StudentVacaturesForm->OpslaanButton->Enabled = false;
    StudentVacaturesForm->VerwijderButton->Enabled = true;
 //   StudentVacaturesForm->OpenDBRadioGroup->Enabled = false;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
   // StudentVacaturesForm->SearchEdit->Show();
  //  StudentVacaturesForm->SearchButton->Show();
   // StudentVacaturesForm->ToggleButton->Show();
    StudentVacaturesForm->vacaturesDBNavigator->Enabled = true;
    StudentVacaturesForm->NieuwButton->Enabled = false;
    StudentVacaturesForm->OpslaanButton->Enabled = true;
    StudentVacaturesForm->VerwijderButton->Enabled = false;
 //   StudentVacaturesForm->OpenDBRadioGroup->Enabled = true;

    SetReadModus(false);
}
//---------------------------------------------------------------------------

static void  DoInsert()
{
//    StudentVacaturesForm->InschrijvingDBNavigator->Enabled = false;
  //  StudentVacaturesForm->SearchEdit->Hide();
   // StudentVacaturesForm->SearchButton->Hide();
   // StudentVacaturesForm->ToggleButton->Hide();
    StudentVacaturesForm->vacaturesDBNavigator->Enabled = false;
    StudentVacaturesForm->OpenDBRadioGroup->ItemIndex = 1;
    StudentVacaturesForm->NieuwButton->Enabled = true;
    StudentVacaturesForm->OpslaanButton->Enabled = false;
    StudentVacaturesForm->VerwijderButton->Enabled = false;
 //   StudentVacaturesForm->OpenDBRadioGroup->Enabled = false;

    SetReadModus(false);
 }
//---------------------------------------------------------------------------

void __fastcall TStudentVacaturesForm::ModusKnopClick(TObject *Sender)
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

void __fastcall TStudentVacaturesForm::SearchButtonClick(TObject *Sender)
{
       // Check if the connection is already established
/*   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
       //   sasDataModule->sasSQLConnection->Connected=true;
     }

   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active = false; // Flush previous data in set
   if (StudentVacaturesForm->ToggleButton->Caption == "op idnummer")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
        sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(StudentVacaturesForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else if (StudentVacaturesForm->ToggleButton->Caption == "op naam")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
        sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(StudentVacaturesForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
       else // op studienummer
         {
           //zoek eerst in inschrijving naar het studienummer en daarna in persoon naar het idnummer;
            sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
            sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
            sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where STUDIENR = :STUDIENR";
            sasDataModule->InschrijvingSQLDataSet->ParamByName("STUDIENR")->Value=LowerCase(StudentVacaturesForm->SearchEdit->Text);
            sasDataModule->InschrijvingSQLDataSet->Open();
            sasDataModule->InschrijvingClientDataSet->Active=true;
            String idnummer =(sasDataModule->InschrijvingClientDataSet->FindField("IDKAARTNR"))->AsString;
            sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
            sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(idnummer);
            sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
         }
   if (StudentVacaturesForm->ToggleButton->Caption != "op studienummer")
      {
        sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
     //   Application->MessageBox("", (sasDataModule->personClientDataSet->FieldByName("volgnr")->AsString).c_str(), MB_OK);

       sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
       sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
       sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR = :IDKAARTNR";
       sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(StudentVacaturesForm->IdCardDBEdit->Text);
       sasDataModule->InschrijvingSQLDataSet->Open();
       sasDataModule->InschrijvingClientDataSet->Active=true;
      }

    */
}
//---------------------------------------------------------------------------


void __fastcall TStudentVacaturesForm::OpslaanButtonClick(TObject *Sender)
{
    int open = 0;
    String foutmelding = "";

    if (FunctieDBLookupComboBox->Text == "") foutmelding =  "U moet een functie kiezen.";
    else if  (StartdatumDBEdit->EditText == "") foutmelding = "U moet een startdatum opgeven.";
    else if  (EinddatumDBEdit->EditText == "") foutmelding = "U moet een einddatum opgeven.";
    else if  (VerantwoordelijkeDBEdit->Text == "") foutmelding = "U moet een verantwoordelijke opgeven.";
    else if  (AantalurenDBEdit->Text == "") foutmelding = "U moet het aantal uren opgeven.";

    if (foutmelding != "")
     {
       Application->MessageBox(foutmelding.c_str(), "" ,MB_OK|MB_ICONWARNING);
       return;
     }

    if (FModus == 1)  //Toevoegen
      {
         StudentVacaturesForm->vacatureSQLDataSet->CommandType = ctQuery;
         StudentVacaturesForm->vacatureSQLDataSet->CommandText = "INSERT INTO VACATURE (FUNKTIE_ID,STARTDATUM,\
         EINDDATUM,VERANTWOORDELIJKE, VAKGEBIED,TAAKOMSCHRIJVING,AANTALUREN,OPEN) VALUES(:FUNKTIE_ID,:STARTDATUM,\
         :EINDDATUM,:VERANTWOORDELIJKE,:VAKGEBIED,:TAAKOMSCHRIJVING,:AANTALUREN,:OPEN)";

         StudentVacaturesForm->vacatureSQLDataSet->Params->Items[0]->AsString = StudentVacaturesForm->FunctieDBLookupComboBox->KeyValue;
         StudentVacaturesForm->vacatureSQLDataSet->Params->Items[1]->AsString = StudentVacaturesForm->StartdatumDBEdit->Text;
         StudentVacaturesForm->vacatureSQLDataSet->Params->Items[2]->AsString = StudentVacaturesForm->EinddatumDBEdit->Text;
         StudentVacaturesForm->vacatureSQLDataSet->Params->Items[3]->AsString = StudentVacaturesForm->VerantwoordelijkeDBEdit->Text;
         StudentVacaturesForm->vacatureSQLDataSet->Params->Items[4]->AsString = StudentVacaturesForm->VakgebiedDBEdit->Text;
         StudentVacaturesForm->vacatureSQLDataSet->Params->Items[5]->AsString = StudentVacaturesForm->TaakomschrijvingDBMemo->Text;
         StudentVacaturesForm->vacatureSQLDataSet->Params->Items[6]->AsString = StudentVacaturesForm->AantalurenDBEdit->Text;
         StudentVacaturesForm->vacatureSQLDataSet->Params->Items[7]->AsInteger = 1;
      }
    else if (FModus == 2) //Wijzigen
      {
      StudentVacaturesForm->vacatureSQLDataSet->CommandType = ctQuery;
      StudentVacaturesForm->vacatureSQLDataSet->CommandText = "UPDATE vacature SET FUNKTIE_ID=:FUNKTIE_ID,\
      STARTDATUM=:STARTDATUM,EINDDATUM=:EINDDATUM,VERANTWOORDELIJKE=:VERANTWOORDELIJKE,\
      VAKGEBIED=:VAKGEBIED, TAAKOMSCHRIJVING =:TAAKOMSCHRIJVING, AANTALUREN =:AANTALUREN, OPEN =:OPEN WHERE VACATURE_ID =:VACATURE_ID ";
       StudentVacaturesForm->vacatureSQLDataSet->Params->Items[0]->AsString = StudentVacaturesForm->FunctieDBLookupComboBox->KeyValue;
       StudentVacaturesForm->vacatureSQLDataSet->Params->Items[1]->AsString = StudentVacaturesForm->StartdatumDBEdit->Text;
       StudentVacaturesForm->vacatureSQLDataSet->Params->Items[2]->AsString = StudentVacaturesForm->EinddatumDBEdit->Text;
       StudentVacaturesForm->vacatureSQLDataSet->Params->Items[3]->AsString = StudentVacaturesForm->VerantwoordelijkeDBEdit->Text;
       StudentVacaturesForm->vacatureSQLDataSet->Params->Items[4]->AsString = StudentVacaturesForm->VakgebiedDBEdit->Text;
       StudentVacaturesForm->vacatureSQLDataSet->Params->Items[5]->AsString = StudentVacaturesForm->TaakomschrijvingDBMemo->Text;
       StudentVacaturesForm->vacatureSQLDataSet->Params->Items[6]->AsString = StudentVacaturesForm->AantalurenDBEdit->Text;
       StudentVacaturesForm->vacatureSQLDataSet->Params->Items[7]->AsInteger = atoi(StudentVacaturesForm->OpenDBRadioGroup->Value.c_str());
       StudentVacaturesForm->vacatureSQLDataSet->Params->Items[8]->AsInteger = StudentVacaturesForm->vacatureClientDataSet->FieldValues["VACATURE_ID"];

      }
    vacatureSQLDataSet->ExecSQL();
}
//---------------------------------------------------------------------------


void __fastcall TStudentVacaturesForm::NieuwButtonClick(TObject *Sender)
{
    if (sasDataModule->sasSQLConnection->Connected!=true)
        {
                sasDataModule->sasSQLConnection->Connected=true;
        }

        StudentVacaturesForm->vacatureSQLDataSet->Close(); // Flush previous query
        StudentVacaturesForm->vacatureClientDataSet->Active=false; // Flush previous data in set
        StudentVacaturesForm->vacatureSQLDataSet->CommandText="select * from vacature where studienr like :STUDIENR";
        StudentVacaturesForm->vacatureSQLDataSet->ParamByName("STUDIENR")->Value="--------"; // Append the '%' sign to search for names like the one input in the box
        StudentVacaturesForm->vacatureSQLDataSet->Open();
        StudentVacaturesForm->vacatureClientDataSet->Active=true;
        StudentVacaturesForm->StartdatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
        StudentVacaturesForm->EinddatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
        StudentVacaturesForm->OpslaanButton->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TStudentVacaturesForm::VerwijderButtonClick(
      TObject *Sender)
{
  vacatureSQLDataSet->CommandType = ctQuery;
  vacatureSQLDataSet->CommandText = "DELETE FROM VACATURE WHERE VACATURE_ID = :VACATURE_ID";
  vacatureSQLDataSet->ParamByName("VACATURE_ID")->Value = StudentVacaturesForm->vacatureClientDataSet->FieldValues["VACATURE_ID"];
  vacatureSQLDataSet->ExecSQL();

  vacatureSQLDataSet->Close(); // Flush previous query
  vacatureClientDataSet->Active=false; // Flush previous data in set
  vacatureSQLDataSet->CommandText="select * from vacature where studienr like :STUDIENR";
  vacatureSQLDataSet->ParamByName("STUDIENR")->Value="-------"; // Append the '%' sign to search for names like the one input in the box
  vacatureSQLDataSet->Open();
  vacatureClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

