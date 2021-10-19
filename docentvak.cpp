//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "docentvak.h"
#include "sasdm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TDocentVakForm *DocentVakForm;
static int Modus;
static String personquery;
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{

}
//--------------------------------------------------------------------------

static void DoRead()
{
    DocentVakForm->DocentVakNavigator->Enabled = true;
    DocentVakForm->NieuwButton->Enabled = false;
    DocentVakForm->OpslaanButton->Enabled = false;
    DocentVakForm->VerwijderButton->Enabled = false;
    DocentVakForm->SearchEdit->Show();
    DocentVakForm->SearchButton->Show();
    DocentVakForm->ToggleButton->Show();
 //   DocentBetrekkingForm->PersoonDBNavigator->Enabled = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    DocentVakForm->DocentVakNavigator->Enabled = true;
    DocentVakForm->NieuwButton->Enabled = false;
    DocentVakForm->OpslaanButton->Enabled = false;
    DocentVakForm->VerwijderButton->Enabled = true;
    DocentVakForm->SearchEdit->Show();
    DocentVakForm->SearchButton->Show();
    DocentVakForm->ToggleButton->Show();
 //   DocentVakForm->PersoonDBNavigator->Enabled = true;
    SetReadModus(true);
}

//----------------------------------------------------------------------------

static void  DoInsert()
{
    DocentVakForm->DocentVakNavigator->Enabled = false;
    DocentVakForm->NieuwButton->Enabled = true;
    DocentVakForm->OpslaanButton->Enabled = false;
    DocentVakForm->VerwijderButton->Enabled = false;
  //  DocentVakForm->SearchEdit->Hide();
  //  DocentVakForm->ToggleButton->Hide();
  //  DocentVakForm->SearchButton->Hide();
//    DocentVakForm->PersoonDBNavigator->Enabled = true;
    SetReadModus(false);
}


//---------------------------------------------------------------------------
__fastcall TDocentVakForm::TDocentVakForm(TComponent* Owner)
        : TForm(Owner)
{
  Modus = 0;
 // personquery = "select persoon.* from persoon join Docentbetrekking on persoon.IDKAARTNR = Docentbetrekking.IDKAARTNR ";
 // DocentVakForm->personClientDataSet->Active = false;
 // DocentVakForm->personClientDataSet->CommandText= personquery;
 // DocentVakForm->personClientDataSet->Active = true;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  sasDataModule->FaculteitSQLDataSet->Active = true;
  sasDataModule->docentSQLDataSet->Active = true;
  sasDataModule->vakSQLDataSet->Active = true;
  sasDataModule->docentvakSQLDataSet->Active = true;
  docentvakClientDataSet->Active = true;
  faculteitClientDataSet->Active = true;
  vakClientDataSet->Active = true;
  studierichtingClientDataSet->Active = true;
  personClientDataSet->Active = true;
  last->Text= String(personClientDataSet->RecordCount);
  first->Text= String(personClientDataSet->RecNo);

//  personClientDataSet->Active = true;
//  personClientDataSet->Filtered = true;
//  personClientDataSet->Filter = "WHERE   personquery = "select * from persoon left join Docentbetrekking on persoon.VOLGNR = Docentbetrekking.VOlGNR where Docentbetrekking.VOLGNR NOT NLL";;
}
//---------------------------------------------------------------------------
void __fastcall TDocentVakForm::ModusKnopClick(TObject *Sender)
{
   Modus = (++Modus)%3;
   switch (Modus)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Lezen"; DoRead();break;//lezen
   case 1: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Toevoegen";DoInsert();break;//toevoegen
   case 2: ModusKnop->Font->Color = clRed ;ModusKnop->Caption = "Verwijderen";DoDelete();//verwijderen
    };
}
//---------------------------------------------------------------------------

void __fastcall TDocentVakForm::SearchButtonClick(TObject *Sender)
{
  String richtingquery;
   // Check if the connection is already established
   personClientDataSet->Filtered = true;
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
        sasDataModule->sasSQLConnection->Connected=true;
     }

 //  sasDataModule->personSQLDataSet->Close(); // Flush previous query
   personClientDataSet->Active=false; // Flush previous data in set
   if (DocentVakForm->ToggleButton->Caption == "op studierichting")
     {
        //We moeten alle docent_Id van de gekozen studierichting ophalen uit docentbetrekking
        //Daarna moeten we deze joinen met persoon
       richtingquery = "select persoon.naam, persoon.voornaam, persoon.idkaartnr, faculteit.faculteit, studierichting.studierichting from persoon join docentbetrekking on persoon.IDKAARTNR = docentbetrekking.IDKAARTNR join faculteit on docentbetrekking.faculteit = faculteit.faculteit_id join studierichting on docentbetrekking.studierichting = studierichting.richting_id";       sasDataModule->docentSQLDataSet->Active = false;
       sasDataModule->docentSQLDataSet->CommandText = richtingquery;
       sasDataModule->docentSQLDataSet->Active = true;
       personClientDataSet->Active = false;
       personClientDataSet->Filtered = true;
       personClientDataSet->Filter = String("studierichting = ") + String("'") +   StudierichtingLookupComboBox->Text + String("'");
       personClientDataSet->Active = true;

      /* vakClientDataSet->Active = false;
       vakClientDataSet->Filtered = true;
       vakClientDataSet->Filter = String("NAAM like ") + String("'") + DocentVakForm->SearchEdit->Text + String("%'");
       vakClientDataSet->Active = true; */

       // Nu moeten de vakken opgehaald worden die bij deze richting horen.
       //Hier kunnen we met een filter volstaan
       //dit doen we als idcarddbedit verandert
     }
   else
     {
       richtingquery = "select persoon.naam, persoon.voornaam, persoon.idkaartnr, faculteit.faculteit, studierichting.studierichting from persoon join docentbetrekking on persoon.IDKAARTNR = docentbetrekking.IDKAARTNR join studierichting on docentbetrekking.studierichting = studierichting.richting_id join faculteit on docentbetrekking.faculteit = faculteit.faculteit_id";
       sasDataModule->docentSQLDataSet->Active = false;
       sasDataModule->docentSQLDataSet->CommandText = richtingquery;
       sasDataModule->docentSQLDataSet->Active = true;

       personClientDataSet->Active = false;
       personClientDataSet->Filtered = true;
       personClientDataSet->Filter = String("NAAM like ") + String("'") + DocentVakForm->SearchEdit->Text + String("%'");
       personClientDataSet->Active = true;

       // Nu moeten de vakken opgehaald worden die bij deze richting horen.
       //Hier kunnen we met een filter volstaan
       //dit doen we als idcarddbedit verandert
     }
  personClientDataSet->Active=true;
  last->Text= String(personClientDataSet->RecordCount);
  first->Text= String(personClientDataSet->RecNo);
 //Nu moet gezocht worden in docentbetrekking
 /* docentbetrekkingClientDataSet->Active=false; // Flush previous data in set
  docentbetrekkingClientDataSet->Filtered = true;
  docentbetrekkingClientDataSet->Filter =   String("IDKAARTNR like ") + String("'") + DocentVakForm->IdCardDBEdit->Text + String("'");
  docentbetrekkingClientDataSet->Active=true; */
}
//---------------------------------------------------------------------------

void __fastcall TDocentVakForm::ToggleButtonClick(TObject *Sender)
{
 if (DocentVakForm->ToggleButton->Caption == "op studierichting")
   {
     DocentVakForm->ToggleButton->Caption = "op docentnaam";
     DocentVakForm->SearchEdit->Visible = true;
   }
  else
   {
      DocentVakForm->ToggleButton->Caption = "op studierichting";
      DocentVakForm->SearchEdit->Visible = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TDocentVakForm::PersoonDBNavigatorClick(TObject *Sender,
      TNavigateBtn Button)
{
  last->Text= String(personClientDataSet->RecordCount);
  first->Text= String(personClientDataSet->RecNo);
  //Nu moet indien er een ander docent gekozen is, alle betrekingen van deze docent getoond worden.
  //Nu moet gezocht worden in docentbetrekking
  docentbetrekkingClientDataSet->Active=false; // Flush previous data in set
  docentbetrekkingClientDataSet->Filtered = true;
  docentbetrekkingClientDataSet->Filter =   String("IDKAARTNR = ") + String("'") + DocentVakForm->IdCardDBEdit->Text + String("'");
  docentbetrekkingClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TDocentVakForm::IdCardDBEditChange(TObject *Sender)
{
  String vakquery;
  vakquery = "SELECT vak.vak_code, vak.vak_naam , faculteit.faculteit, studierichting.studierichting FROM docentvak join vak on docentvak.vak_id = vak.vak_id join faculteit on vak.faculteit_id = faculteit.faculteit_id join studierichting on vak.richting_id = studierichting.richting_id";
  sasDataModule->vakSQLDataSet->Active = false;
  sasDataModule->vakSQLDataSet->CommandText = vakquery;
  sasDataModule->vakSQLDataSet->Active = true;
  vakClientDataSet->Active = false;
  vakClientDataSet->Filtered = false;
//  vakClientDataSet->Filter = String("studierichting = ") + StudierichtingDBEdit->Text;
  vakClientDataSet->Active = true;
}

//---------------------------------------------------------------------------

void __fastcall TDocentVakForm::NieuwButtonClick(TObject *Sender)
{
 if (sasDataModule->sasSQLConnection->Connected!=true)
        {
                sasDataModule->sasSQLConnection->Connected=true;
        }
  docentvakClientDataSet->Active=false; // Flush previous data in set
 //   Application->MessageBoxA("12","",MB_OK);
  docentvakClientDataSet->Filtered = true;
  docentvakClientDataSet->Filter= String("vak_code like ") + "000000";
  docentvakClientDataSet->Active = true;
  DocentVakForm->OpslaanButton->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TDocentVakForm::OpslaanButtonClick(TObject *Sender)
{
Variant leeg = NULL;
  char buf[5];

  if (Modus == 1)
    {
    if (DocentVakForm->IdCardDBEdit->Text == "")
      {
         Application->MessageBox("U moet eerst een persoon selecteren", "Probeer het opnieuw", MB_OK);
         return;
      }
      sasDataModule->personSQLDataSet->CommandText = "INSERT INTO DOCENTBETREKKING (IDKAARTNR,COMMENTAAR,INDIENSTDATUM,UITDIENSTDATUM,GEBOUW,KAMER,TELEFOON,FUNCTIE,FACULTEIT,STUDIERICHTING)"
                                                                  "VALUES(:IDKAARTNR,:COMMENTAAR, :INDIENSTDATUM,:UITDIENSTDATUM,:GEBOUW,:KAMER,:TELEFOON,:FUNCTIE,:FACULTEIT,:STUDIERICHTING)";
      sasDataModule->personSQLDataSet->Params->Items[0]->AsString = DocentVakForm->IdCardDBEdit->Text;
//      sasDataModule->docentvakSQLDataSet->Params->Items[1]->AsString = DocentVakForm->CommentDBMemo->Text;
//      sasDataModule->docentvakSQLDataSet->Params->Items[2]->AsString = DocentVakForm->InDienstDBEdit->Text;

      personClientDataSet->Close();
      sasDataModule->docentvakSQLDataSet->Close();
  try
   {
      sasDataModule->docentvakSQLDataSet->ExecSQL();
   }
  catch (Exception &exception)
        {
            Application->ShowException(&exception);
        }
//      Application->MessageBoxA("8","",MB_OK);
   DocentVakForm->NieuwButton->Enabled = true;
   DocentVakForm->OpslaanButton->Enabled = false;
    }

      sasDataModule->docentvakSQLDataSet->Close(); // Flush previous query
      personClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->docentvakSQLDataSet->CommandText="select * from persoon where NAAM like :Name";
      sasDataModule->docentvakSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
      sasDataModule->docentvakSQLDataSet->Open();
      personClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TDocentVakForm::VerwijderButtonClick(TObject *Sender)
{
  sasDataModule->docentvakSQLDataSet->CommandType = ctQuery;
  sasDataModule->docentvakSQLDataSet->CommandText = "DELETE FROM docentvak WHERE vak_code = :VAK_CODE AND docent_id = :DOCENT_ID";
//  sasDataModule->docentvakSQLDataSet->Params->Items[0]->AsString = DocentVakForm->Vak_CodeDBEdit->Text;
   sasDataModule->docentvakSQLDataSet->Params->Items[1]->AsString = DocentVakForm->DocentIdDBEdit->Text;
  sasDataModule->docentvakSQLDataSet->ExecSQL();

  sasDataModule->docentvakSQLDataSet->Close(); // Flush previous query
  docentvakClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->docentvakSQLDataSet->CommandText="select * from docentvak where VAK_CODE LIKE :VK_CODE";
  sasDataModule->docentvakSQLDataSet->ParamByName("VAK->CODE")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
  sasDataModule->docentvakSQLDataSet->Open();
  docentvakClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

