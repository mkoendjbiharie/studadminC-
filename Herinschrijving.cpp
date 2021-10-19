//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Herinschrijving.h"
#include "sasdm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

static int FModus;
static void VulLaatsttoegevoegdeRecordsGrid();

THerinschrijvingForm *HerinschrijvingForm;
//---------------------------------------------------------------------------
__fastcall THerinschrijvingForm::THerinschrijvingForm(TComponent* Owner)
        : TForm(Owner)
{
  FModus = 0;
  PersoonSQLDataSet->Close();
  PersoonClientDataSet->Close();
  PersoonSQLDataSet->CommandText = "SELECT * FROM persoon";
  PersoonSQLDataSet->Open();
  PersoonClientDataSet->Open();
  InschrijvingSQLDataSet->Active = true;
  HerinschrijvingSQLDataSet->Active = true;
  sasDataModule->FaculteitSQLDataSet->Active = true;
  StudierichtingSQLDataSet->Active = true;


  InschrijvingClientDataSet->Active = true;
  HerinschrijvingClientDataSet->Active = true;
  sasDataModule->FaculteitClientDataSet->Active = true;
   StudierichtingClientDataSet->Active = true;


  NieuwButton->Enabled = false;
  OpslaanButton->Enabled = false;
  VerwijderButton->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall THerinschrijvingForm::Close1Click(TObject *Sender)
{
  HoofdScherm->Herinschrijven1->Checked = false;
  HoofdScherm->Show();
  Free();
}
//---------------------------------------------------------------------------

void __fastcall THerinschrijvingForm::Exit1Click(TObject *Sender)
{
 HoofdScherm->Close();
}
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   HerinschrijvingForm->StudierichtingComboBox->ReadOnly=mode;
   HerinschrijvingForm->HerinschrijvingDBMemo->ReadOnly=mode;
}
//--------------------------------------------------------------------------

static void DoRead()
{
    HerinschrijvingForm->InschrijvingDBNavigator->Enabled = true;
    HerinschrijvingForm->NieuwButton->Enabled = false;
    HerinschrijvingForm->OpslaanButton->Enabled = false;
    HerinschrijvingForm->VerwijderButton->Enabled = false;
    HerinschrijvingForm->Label2->Show();
    HerinschrijvingForm->IdNummerComboBox->Hide();
    HerinschrijvingForm->SearchEdit->Show();
    HerinschrijvingForm->SearchButton->Show();
    HerinschrijvingForm->ToggleButton->Show();
    HerinschrijvingForm->LastRecordsDBGrid->Show();
 //   Schakelstudent->StudierichtingComboBox->Enabled = false;
   // HerinschrijvingForm->IdCardDBEdit->ReadOnly = true;
    HerinschrijvingForm->InschrijvingDBNavigator->Visible = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    HerinschrijvingForm->InschrijvingDBNavigator->Enabled = true;
    HerinschrijvingForm->NieuwButton->Enabled = false;
    HerinschrijvingForm->OpslaanButton->Enabled = false;
    HerinschrijvingForm->VerwijderButton->Enabled = true;
    HerinschrijvingForm->Label2->Show();
    HerinschrijvingForm->SearchEdit->Show();
    HerinschrijvingForm->IdNummerComboBox->Hide();
    HerinschrijvingForm->SearchButton->Show();
    HerinschrijvingForm->ToggleButton->Show();
    HerinschrijvingForm->LastRecordsDBGrid->Show();
 //   Schakelstudent->StudierichtingComboBox->Enabled = false;
  //  HerinschrijvingForm->IdCardDBEdit->ReadOnly = true;
    HerinschrijvingForm->InschrijvingDBNavigator->Visible = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
    HerinschrijvingForm->InschrijvingDBNavigator->Enabled = true;
    HerinschrijvingForm->NieuwButton->Enabled = false;
    HerinschrijvingForm->OpslaanButton->Enabled = true;
    HerinschrijvingForm->VerwijderButton->Enabled = false;
    HerinschrijvingForm->Label2->Show();
    HerinschrijvingForm->SearchEdit->Show();
    HerinschrijvingForm->IdNummerComboBox->Hide();
    HerinschrijvingForm->SearchButton->Show();
    HerinschrijvingForm->ToggleButton->Show();
    HerinschrijvingForm->LastRecordsDBGrid->Show();
   // HerinschrijvingForm->IdCardDBEdit->Show();
    HerinschrijvingForm->IdNummerComboBox->Hide();
    SetReadModus(false);
//    Schakelstudent->StudierichtingComboBox->Enabled = false;
  //  HerinschrijvingForm->IdCardDBEdit->ReadOnly = false;
    HerinschrijvingForm->InschrijvingDBNavigator->Visible = true;
}
//---------------------------------------------------------------------------

static void  DoInsert()
{
    HerinschrijvingForm->InschrijvingDBNavigator->Enabled = true;
    HerinschrijvingForm->NieuwButton->Enabled = true;
    HerinschrijvingForm->OpslaanButton->Enabled = false;
    HerinschrijvingForm->VerwijderButton->Enabled = false;
  //  HerinschrijvingForm->SearchEdit->Hide();
  // HerinschrijvingForm->SearchButton->Hide();
  // HerinschrijvingForm->IdNummerComboBox->Show();
 //   HerinschrijvingForm->ToggleButton->Hide();
 //  HerinschrijvingForm->IdCardDBEdit->Hide();
 //   HerinschrijvingForm->IdNummerComboBox->Visible = true;
    SetReadModus(false);
 //   Schakelstudent->StudierichtingComboBox->Enabled = false;
   // HerinschrijvingForm->IdCardDBEdit->ReadOnly = false;
    HerinschrijvingForm->InschrijvingDBNavigator->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall THerinschrijvingForm::ToggleButtonClick(TObject *Sender)
{
  if (HerinschrijvingForm->ToggleButton->Caption == "op idnummer")
      HerinschrijvingForm->ToggleButton->Caption = "op naam";
  else  if  (HerinschrijvingForm->ToggleButton->Caption == "op naam")
      HerinschrijvingForm->ToggleButton->Caption = "op studienummer";
  else
      HerinschrijvingForm->ToggleButton->Caption = "op idnummer";
}

//---------------------------------------------------------------------------

void __fastcall THerinschrijvingForm::SearchButtonClick(TObject *Sender)
{
            // Check if the connection is already established
  if (sasDataModule->sasSQLConnection->Connected!=true)
        {
             //   sasDataModule->sasSQLConnection->Connected=true;
        }

   PersoonSQLDataSet->Close(); // Flush previous query
   PersoonClientDataSet->Active=false; // Flush previous data in set
   if (HerinschrijvingForm->ToggleButton->Caption == "op studienummer")
   {
      //Zoek eerst in inschrijving naar het record en vind idkaartnummer
        InschrijvingSQLDataSet->Close(); // Flush previous query
        InschrijvingClientDataSet->Active=false; // Flush previous data in set
        InschrijvingSQLDataSet->CommandText= "select * from inschrijving where STUDIENR like :STUDIENR AND IsNull(AFSTUDEERDATUM) and IsNull(AFSCHRIJVINGSDATUM)";
        InschrijvingSQLDataSet->ParamByName("STUDIENR")->Value=LowerCase(HerinschrijvingForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
        InschrijvingSQLDataSet->Open();
        InschrijvingClientDataSet->Active=true;

      //zoek in persoon naar het persoonsrecord als het studienummer voorkomt
        if ( !InschrijvingClientDataSet->IsEmpty())
          {
           PersoonSQLDataSet->CommandText="select * from persoon where IDKAARTNR = :IDKAARTNR";
           PersoonSQLDataSet->ParamByName("idkaartnr")->Value= InschrijvingClientDataSet->FieldValues["IDKAARTNR"];
           PersoonSQLDataSet->Open(); // Flush previous query
           PersoonClientDataSet->Active=true; // Flush previous data in set
          }
   }
   else
   {
   if (HerinschrijvingForm->ToggleButton->Caption == "op idnummer")
     {
        PersoonSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
        PersoonSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(HerinschrijvingForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else   if (HerinschrijvingForm->ToggleButton->Caption == "op naam")
     {
        PersoonSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
        PersoonSQLDataSet->ParamByName("naam")->Value=LowerCase(HerinschrijvingForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }



  //          sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
  //      sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Faculteitstudent->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
        PersoonSQLDataSet->Open();
        PersoonClientDataSet->Active=true;
        InschrijvingSQLDataSet->Close(); // Flush previous query
        InschrijvingClientDataSet->Active=false; // Flush previous data in set
        InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR like :IDKAARTNR AND IsNull(AFSTUDEERDATUM) and IsNull(AFSCHRIJVINGSDATUM)";
        InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(HerinschrijvingForm->IdCardDBEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
        InschrijvingSQLDataSet->Open();
        InschrijvingClientDataSet->Active=true;
   }
  //Nu moet het gekoppelde herinschijvingsrecord getoond worden
        HerinschrijvingSQLDataSet->Close(); // Flush previous query
        HerinschrijvingClientDataSet->Active=false; // Flush previous data in set
        HerinschrijvingSQLDataSet->CommandText="select * from herinschrijving where STUDIENR = :STUDIENR AND JAAR =:DITJAAR";
        HerinschrijvingSQLDataSet->ParamByName("STUDIENR")->Value=LowerCase(HerinschrijvingForm->StudieNRDBEdit->Text); // Append the '%' sign to search for names like the one input in the box
        HerinschrijvingSQLDataSet->ParamByName("DITJAAR")->Value =CurrentYear();

        HerinschrijvingSQLDataSet->Open();
        HerinschrijvingClientDataSet->Active=true;


      //Nu moeten de vorige jaren dat de student ingeshreven was getoond worden in de listbox
 if (HerinschrijvingForm->IdCardDBEdit->Text != "")
    {
 //     Application->MessageBox("inschrijfjaren", HerinschrijvingForm->StudieNRDBEdit->Text.c_str(), MB_OK);
      InschrijfJarenSQLDataSet->Close(); // Flush previous query
      InschrijfJarenClientDataSet->Active=false; // Flush previous data in set
      InschrijfJarenSQLDataSet->CommandText= "select * from herinschrijving where STUDIENR = :STUDIENR";// AND JAAR != :DITJAAR";
      InschrijfJarenSQLDataSet->ParamByName("studienr")->Value = LowerCase(HerinschrijvingForm->StudieNRDBEdit->Text);
//      HerinschrijvingSQLDataSet->ParamByName("JAAR")->Value =CurrentYear();
      InschrijfJarenSQLDataSet->Open();
      InschrijfJarenClientDataSet->Active=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall THerinschrijvingForm::ModusKnopClick(TObject *Sender)
{
 FModus = (++FModus)%4;
   switch (FModus)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Lezen"; DoRead();break;//lezen
   case 1: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Toevoegen";DoInsert();break;//toevoegen
   case 2: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Wijzigen";DoUpdate();break;//wijzigen
   case 3: ModusKnop->Font->Color = clRed ;ModusKnop->Caption = "Verwijderen";DoDelete();//verwijderen
    };
}
//---------------------------------------------------------------------------

void __fastcall THerinschrijvingForm::IdCardDBEditExit(TObject *Sender)
{
 if (HerinschrijvingForm->IdCardDBEdit->Modified)
    {
   //Nu moet gezocht worden naar dit record in persoon
   //Als het niet voorkomt dient het veld schoon gemaakt te worden en een
   //boodschap op het scherm getoond te worden
//   Application->MessageBox("",IdCardDBEdit->Text.c_str(),MB_OK);
   String zoekstring = IdCardDBEdit->Text;
   PersoonSQLDataSet->Close(); // Flush previous query
   PersoonClientDataSet->Active=false; // Flush previous data in set
   PersoonSQLDataSet->CommandText= "select * from persoon where IDKAARTNR = :IDKAARTNR";
   PersoonSQLDataSet->Params->Items[0]->AsString = zoekstring.c_str(); // Append the '%' sign to search for names like the one input in the box
   PersoonSQLDataSet->Open();
   PersoonClientDataSet->Active=true;

   InschrijvingSQLDataSet->Close(); // Flush previous query
   InschrijvingClientDataSet->Active=false; // Flush previous data in set
   InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR = :IDKAARTNR";
   InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value = LowerCase(HerinschrijvingForm->IdCardDBEdit->Text);
   InschrijvingSQLDataSet->Open();
   InschrijvingClientDataSet->Active=true;
   if (PersoonClientDataSet->IsEmpty())
    {
      HerinschrijvingForm->IdCardDBEdit->Text = "";
      Application->MessageBox("", "Het door u opgegeven idnummer komt niet voor",MB_OK + MB_ICONWARNING);
    }
   //Nu moeten de vorige jaren dat de student ingeshreven was getoond worden in de listbox
   else
    {
      InschrijfJarenSQLDataSet->Close(); // Flush previous query
      InschrijfJarenClientDataSet->Active=false; // Flush previous data in set
      InschrijfJarenSQLDataSet->CommandText= "select * from herinschrijving where STUDIENR = :STUDIENR";// AND JAAR != :DITJAAR";
      InschrijfJarenSQLDataSet->ParamByName("studienr")->Value = LowerCase(HerinschrijvingForm->StudieNRDBEdit->Text);
//      HerinschrijvingSQLDataSet->ParamByName("JAAR")->Value =CurrentYear();
      InschrijfJarenSQLDataSet->Open();
      InschrijfJarenClientDataSet->Active=true;
    }
   }
}
//---------------------------------------------------------------------------

void __fastcall THerinschrijvingForm::NieuwButtonClick(TObject *Sender)
{
   if (sasDataModule->sasSQLConnection->Connected!=true)
        {
                sasDataModule->sasSQLConnection->Connected=true;
        }

    PersoonSQLDataSet->Close(); // Flush previous query
    PersoonClientDataSet->Active=false; // Flush previous data in set
    PersoonSQLDataSet->CommandText="select * from persoon where IDKAARTNR = :IDKAARTNR";
    PersoonSQLDataSet->ParamByName("IDKAARTNR")->Value="-------"; // Append the '%' sign to search for names like the one input in the box
    PersoonSQLDataSet->Open();
    PersoonClientDataSet->Active=true;
    InschrijvingSQLDataSet->Close(); // Flush previous query
    InschrijvingClientDataSet->Active=false; // Flush previous data in set
  // InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR = :Idkaartnr";
   // InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value="-------"; // Append the '%' sign to search for names like the one input in the box
    InschrijvingSQLDataSet->CommandText="select * from inschrijving where IsNull(AFSTUDEERDATUM) AND IsNull(AFSCHRIJVINGSDATUM)";
    InschrijvingSQLDataSet->Open();
    InschrijvingClientDataSet->Active=true;
    HerinschrijvingSQLDataSet->Close(); // Flush previous query
    HerinschrijvingClientDataSet->Active=false; // Flush previous data in set
    HerinschrijvingSQLDataSet->CommandText="select * from  herinschrijving where STUDIENR = :STUDIENR";
    HerinschrijvingSQLDataSet->ParamByName("STUDIENR")->Value="--------"; // Append the '%' sign to search for names like the one input in the box

    HerinschrijvingSQLDataSet->Open();
    HerinschrijvingClientDataSet->Active=true;
    JaarDBEdit->Text = "";
    HerinschrijvingForm->OpslaanButton->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall THerinschrijvingForm::OpslaanButtonClick(TObject *Sender)
{
    String collegejaar, ditjaar;
    ditjaar = CurrentYear();
    TDateTime datum = Now();
    unsigned short jar, mnd, dag;
    datum.DecodeDate(&jar, &mnd, &dag);

   int jaar = atoi(ditjaar.c_str());
    char buf[5];
    if (mnd < 9)
      {
        jaar--;
      }
        collegejaar = itoa(jaar, buf, 10);


    //Als het inschrijfjaar hetzelfde is als het jaar van herinschrijving dan moet een foutmelding volgen

    if (collegejaar == InschrijvingClientDataSet->FieldValues["INSCHRIJFJAAR"])
     {
      Application->MessageBox("Kan niet worden heringeschreven!!","Nieuwe student",MB_OK|MB_ICONSTOP);
      return;
     }


    if (FModus == 1)
    {
     // HerinschrijvingSQLDataSet->Close();
      HerinschrijvingForm->OpslaanButton->Enabled = false;
      HerinschrijvingSQLDataSet->CommandType = ctQuery;
      HerinschrijvingSQLDataSet->CommandText = "INSERT INTO herinschrijving (STUDIENR, JAAR, MEMO)  VALUES (:STUDIENR, :JAAR, :MEMO) ";
      HerinschrijvingSQLDataSet->Params->Items[0]->AsString = HerinschrijvingForm->SearchEdit->Text;
      HerinschrijvingSQLDataSet->Params->Items[1]->AsString = collegejaar;
      HerinschrijvingSQLDataSet->Params->Items[2]->AsString = HerinschrijvingForm->HerinschrijvingDBMemo->Text;
      HerinschrijvingSQLDataSet->ExecSQL();
      JaarDBEdit->Text = collegejaar;
    }
   else if (FModus == 2)
    {
      HerinschrijvingSQLDataSet->CommandType = ctQuery;
      HerinschrijvingSQLDataSet->CommandText = "UPDATE HERINSCHRIJVING SET MEMO=:MEMO WHERE VOLGNR = :VOLGNR";
      HerinschrijvingSQLDataSet->Params->Items[0]->AsString = HerinschrijvingForm->HerinschrijvingDBMemo->Text.c_str();
      HerinschrijvingSQLDataSet->Params->Items[1]->AsString = HerinschrijvingForm->VolgNRDBEdit->Text.c_str();
      HerinschrijvingSQLDataSet->ExecSQL();


    /*  sasDataModule->personSQLDataSet->Close(); // Flush previous query
      sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :Name";
      sasDataModule->personSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
      sasDataModule->personSQLDataSet->Open();
      sasDataModule->personClientDataSet->Active=true; */
    }
    HerinschrijvingForm->OpslaanButton->Enabled = false;
    //Nu moet de grid opnieuw gevuld worden, om de toevoeging zichtbaar te maken
    GridClientDataSet->Active=false; // Flush previous data in set
    GridSQLDataSet->CommandText = "SELECT MAX(VOLGNR) AS VOLGNR FROM HERINSCHRIJVING";


  GridSQLDataSet->Open();
  GridClientDataSet->Active=true;
  int maxvolgnr;
  if(LastRecordsDBGrid->Fields[0]->Text =="")
    maxvolgnr = 0;
  else
    maxvolgnr = LastRecordsDBGrid->Fields[0]->Value;
 // char buf[7];
 // Application->MessageBox("", itoa(maxvolgnr, buf, 10), MB_OK);
  GridSQLDataSet->Close();
  GridClientDataSet->Active=false;
  GridSQLDataSet->CommandText = "SELECT * FROM HERINSCHRIJVING WHERE volgnr > :volgnr  ORDER BY VOLGNR DESC";
  GridSQLDataSet->ParamByName("volgnr")->AsString = maxvolgnr - 50;

  GridSQLDataSet->Open();
  GridClientDataSet->Active=true;

}
//---------------------------------------------------------------------------

void __fastcall THerinschrijvingForm::InschrijvingDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
   //nu moet gegaan worden naar het gekoppelde record in inschrijving
    InschrijvingSQLDataSet->Close(); // Flush previous query
    InschrijvingClientDataSet->Active=false; // Flush previous data in set
    InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR like :IDKAARTNR";
    InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=HerinschrijvingForm->IdCardDBEdit->Text; // Append the '%' sign to search for names like the one input in the box
    InschrijvingSQLDataSet->Open();
    InschrijvingClientDataSet->Active=true;

    //Nu moet gesprongen worden naar het gekoppelde record in herinschrijving
      if (HerinschrijvingForm->IdCardDBEdit->Text != "")
    {
 //     Application->MessageBox("", "change", MB_OK);
 //     String studienr =    HerinschrijvingForm->StudieNRDBEdit->Text;
      HerinschrijvingSQLDataSet->Close(); // Flush previous query
      HerinschrijvingClientDataSet->Active=false; // Flush previous data in set
      HerinschrijvingSQLDataSet->CommandText= "select * from herinschrijving where STUDIENR =:STUDIENR";// AND JAAR = :DITJAAR)";
      HerinschrijvingSQLDataSet->ParamByName("STUDIENR")->Value = LowerCase(HerinschrijvingForm->StudieNRDBEdit->Text); // Append the '%' sign to search for names like the one input in the box
//      HerinschrijvingSQLDataSet->ParamByName("DITJAAR")->Value =CurrentYear();
//  Application->MessageBox(HerinschrijvingSQLDataSet->CommandText.c_str(), "change", MB_OK);

      HerinschrijvingSQLDataSet->Open();
      HerinschrijvingClientDataSet->Active=true;

    }

   //Nu moet de listbox gevuild worden met jaren van eerdere herinschrijvingen
  if (HerinschrijvingForm->IdCardDBEdit->Text != "")
    {
 //     Application->MessageBox("inschrijfjaren", HerinschrijvingForm->StudieNRDBEdit->Text.c_str(), MB_OK);
      InschrijfJarenSQLDataSet->Close(); // Flush previous query
      InschrijfJarenClientDataSet->Active=false; // Flush previous data in set
      InschrijfJarenSQLDataSet->CommandText= "select * from herinschrijving where STUDIENR = :STUDIENR";// AND JAAR != :DITJAAR";
      InschrijfJarenSQLDataSet->ParamByName("studienr")->Value = LowerCase(HerinschrijvingForm->StudieNRDBEdit->Text);
//      HerinschrijvingSQLDataSet->ParamByName("JAAR")->Value =CurrentYear();
      InschrijfJarenSQLDataSet->Open();
      InschrijfJarenClientDataSet->Active=true;
    }
}
//---------------------------------------------------------------------------

void VulLaatsttoegevoegdeRecordsGrid()
{
  HerinschrijvingForm->GridSQLDataSet->Close(); // Flush previous query

  HerinschrijvingForm->GridClientDataSet->Active=false; // Flush previous data in set

  HerinschrijvingForm->GridSQLDataSet->CommandText = "SELECT MAX(VOLGNR) AS VOLGNR FROM HERINSCHRIJVING";


  HerinschrijvingForm->GridSQLDataSet->Open();
  HerinschrijvingForm->GridClientDataSet->Active=true;
  int maxvolgnr;
  if(HerinschrijvingForm->LastRecordsDBGrid->Fields[0]->Text =="")
    maxvolgnr = 0;
  else
    maxvolgnr = HerinschrijvingForm->LastRecordsDBGrid->Fields[0]->Value;

  HerinschrijvingForm->GridSQLDataSet->Close();
  HerinschrijvingForm->GridClientDataSet->Active=false;
  HerinschrijvingForm->GridSQLDataSet->CommandText = "SELECT * FROM HERINSCHRIJVING WHERE volgnr > :volgnr ORDER BY VOLGNR DESC";
  HerinschrijvingForm->GridSQLDataSet->ParamByName("volgnr")->AsString = maxvolgnr - 50;

  HerinschrijvingForm->GridSQLDataSet->Open();
  HerinschrijvingForm->GridClientDataSet->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall THerinschrijvingForm::FormActivate(TObject *Sender)
{
  VulLaatsttoegevoegdeRecordsGrid();
}
//---------------------------------------------------------------------------


void __fastcall THerinschrijvingForm::IdNummerComboBoxClick(
      TObject *Sender)
{
    PersoonSQLDataSet->Close(); // Flush previous query
    PersoonClientDataSet->Active=false; // Flush previous data in set
    PersoonSQLDataSet->CommandText="select * from persoon where IDKAARTNR = :IDKAARTNR";
    PersoonSQLDataSet->ParamByName("idkaartnr")->Value= InschrijvingClientDataSet->FieldValues["IDKAARTNR"];
    PersoonSQLDataSet->Open();
    PersoonClientDataSet->Active=true;
}
//---------------------------------------------------------------------------



void __fastcall THerinschrijvingForm::VerwijderButtonClick(TObject *Sender)
{
   HerinschrijvingSQLDataSet->CommandType = ctQuery;
   HerinschrijvingSQLDataSet->CommandText = "DELETE FROM HERINSCHRIJVING WHERE STUDIENR =   :STUDIENR";
   HerinschrijvingSQLDataSet->Params->Items[0]->AsString = HerinschrijvingForm->StudieNRDBEdit->Text;
   HerinschrijvingSQLDataSet->ExecSQL();

   PersoonSQLDataSet->Close(); // Flush previous query
   PersoonClientDataSet->Active=false; // Flush previous data in set
   PersoonSQLDataSet->CommandText="select * from persoon where NAAM like :Name";
   PersoonSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
   PersoonSQLDataSet->Open();
   PersoonClientDataSet->Active=true;

   InschrijvingSQLDataSet->Close(); // Flush previous query
   InschrijvingClientDataSet->Active=false; // Flush previous data in set
   InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR = :IDKAARTNR";
   InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(HerinschrijvingForm->SearchEdit->Text); // Append the '%' sign to search for names like the one input in the box
   InschrijvingSQLDataSet->Open();
   InschrijvingClientDataSet->Active=true;
}
//---------------------------------------------------------------------------


