//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Facnainschrijving.h"
#include "Main.h"
#include "sasdm.h"
#include "sasbasictablesmod.h"
#include "person.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFacnainschr *Facnainschr;

static int FModus;
void VulLaatsttoegevoegdeRecordsGrid();
static String studie;
enum modus{lezen, toevoegen};
static modus the_mode;
//---------------------------------------------------------------------------
__fastcall TFacnainschr::TFacnainschr(TComponent* Owner)
        : TForm(Owner)
{
 // Show();
  FModus = 0;
  the_mode = 0;
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
  Facnainschr->NieuwButton->Enabled = false;
  Facnainschr->OpslaanButton->Enabled = false;
 // VulLaatsttoegevoegdeRecordsGrid();
}
//---------------------------------------------------------------------------
void __fastcall TFacnainschr::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  HoofdScherm->Nainschrijven1->Checked = false;
  HoofdScherm->Show();
  Free();
}
//---------------------------------------------------------------------------

void __fastcall TFacnainschr::Close1Click(TObject *Sender)
{
 HoofdScherm->Nainschrijven1->Checked = false;
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TFacnainschr::Exit1Click(TObject *Sender)
{
  HoofdScherm->Close();
}
//---------------------------------------------------------------------------
void VulLaatsttoegevoegdeRecordsGrid()
{
sasDataModule->GridSQLDataSet1->Close(); // Flush previous query

  sasDataModule->GridClientDataSet1->Active=false; // Flush previous data in set

  sasDataModule->GridSQLDataSet1->CommandText = "SELECT MAX(VOLGNR) AS VOLGNR FROM INSCHRIJVING";


  sasDataModule->GridSQLDataSet1->Open();
  sasDataModule->GridClientDataSet1->Active=true;
  int maxvolgnr;
  if(Facnainschr->LastRecordsDBGrid->Fields[0]->Text =="")
    maxvolgnr = 0;
  else
    maxvolgnr = Facnainschr->LastRecordsDBGrid->Fields[0]->Value;

 // char buf[7];
 // Application->MessageBox("", itoa(maxvolgnr, buf, 10), MB_OK);

  sasDataModule->GridSQLDataSet1->Close();
  sasDataModule->GridClientDataSet1->Active=false;
  sasDataModule->GridSQLDataSet1->CommandText = "SELECT * FROM INSCHRIJVING WHERE volgnr > :volgnr ORDER BY VOLGNR DESC";
  sasDataModule->GridSQLDataSet1->ParamByName("volgnr")->AsString = maxvolgnr - 50;

  sasDataModule->GridSQLDataSet1->Open();
  sasDataModule->GridClientDataSet1->Active=true;
}

 //---------------------------------------------------------------------------
void __fastcall TFacnainschr::SearchButtonClick(TObject *Sender)
{
        // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
       //   sasDataModule->sasSQLConnection->Connected=true;
     }

   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
   if (Facnainschr->ToggleButton->Caption == "op idnummer")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
        sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Facnainschr->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
        sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(Facnainschr->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }

    sasDataModule->personSQLDataSet->Open();
    sasDataModule->personClientDataSet->Active=true;

    sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
    sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR = :IDKAARTNR";
    sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Facnainschr->IdCardDBEdit->Text);
    sasDataModule->InschrijvingSQLDataSet->Open();
    sasDataModule->InschrijvingClientDataSet->Active=true;


  if (Facnainschr->IdCardDBEdit->Text != "")
    {
 //     Application->MessageBox("", "change", MB_OK);
      String jaar;
      TDateTime datum = Now();
      unsigned short jar, mnd, dag;
      datum.DecodeDate(&jar, &mnd, &dag);

      char buf[5];
      if (mnd < 9)
        jar--;
      jaar = itoa(jar, buf, 10);
      sasDataModule->EerdereInschrijvingenSQLDataSet->Close(); // Flush previous query
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->EerdereInschrijvingenSQLDataSet->CommandText= "select inschrijving.inschrijfjaar, inschrijving.* from inschrijving where IDKAARTNR = :IDKAARTNR AND INSCHRIJFJAAR != :DITJAAR ORDER BY INSCHRIJFJAAR DESC";

      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("idkaartnr")->Value = LowerCase(Facnainschr->IdCardDBEdit->Text); // Append the '%' sign to search for names like the one input in the box
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("DITJAAR")->Value = jaar;
      sasDataModule->EerdereInschrijvingenSQLDataSet->Open();
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=true;
    }
}
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   Facnainschr->FaculteitComboBox->ReadOnly=mode;
   Facnainschr->StudierichtingComboBox->ReadOnly=mode;
   Facnainschr->SysteemDBLookupListBox->ReadOnly=mode;
   Facnainschr->StudieDBMemo->ReadOnly=mode;
 //  Facnainschr->VerlengingDBEdit->ReadOnly=mode;
   Facnainschr->InschrijfJaarDBEdit->ReadOnly = mode;
}
//--------------------------------------------------------------------------

static void DoRead()
{
    Facnainschr->InschrijvingDBNavigator->Enabled = true;
    Facnainschr->NieuwButton->Enabled = false;
    Facnainschr->OpslaanButton->Enabled = false;
    Facnainschr->Label1->Enabled = false;
    Facnainschr->Label2->Show();
    Facnainschr->SearchEdit->Show();
    Facnainschr->SearchButton->Show();
    Facnainschr->ToggleButton->Show();
    Facnainschr->LastRecordsDBGrid->Show();
    Facnainschr->StudierichtingComboBox->Enabled = false;
    Facnainschr->FaculteitComboBox->Enabled = false;
    Facnainschr->IdCardDBEdit->ReadOnly = true;
    Facnainschr->InschrijvingDBNavigator->Visible = true;
    Facnainschr->FaculteitComboBox->Enabled = false;
    SetReadModus(true);
}

//---------------------------------------------------------------------------

static void  DoInsert()
{
    Facnainschr->InschrijvingDBNavigator->Enabled = false;
    Facnainschr->NieuwButton->Enabled = true;
    Facnainschr->OpslaanButton->Enabled = false;
    Facnainschr->Label2->Enabled = true;
    Facnainschr->Label1->Enabled = true;
    Facnainschr->SearchEdit->Hide();
    Facnainschr->SearchButton->Hide();
    Facnainschr->ToggleButton->Hide();
    SetReadModus(false);
    Facnainschr->StudierichtingComboBox->Enabled = false;
    Facnainschr->FaculteitComboBox->Enabled = true;
    Facnainschr->IdCardDBEdit->ReadOnly = false;
    Facnainschr->InschrijvingDBNavigator->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TFacnainschr::ModusKnopClick(TObject *Sender)
{
   the_mode = (the_mode + 1)%2;
   switch (the_mode)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Lezen"; DoRead();break;//lezen
   case 1: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Student inschrijven";DoInsert();break;//toevoegen
     };
}
//---------------------------------------------------------------------------

void __fastcall TFacnainschr::NieuwButtonClick(TObject *Sender)
{
    OpslaanButton->Enabled=true;
   if (sasDataModule->sasSQLConnection->Connected!=true)
        {
                sasDataModule->sasSQLConnection->Connected=true;
        }

        sasDataModule->personSQLDataSet->Close(); // Flush previous query
        sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR = :IDKAARTNR";
        sasDataModule->personSQLDataSet->ParamByName("IDKAARTNR")->Value="-------"; // Append the '%' sign to search for names like the one input in the box
        sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
        sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
        sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
        sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR = :Idkaartnr";
        sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value="-------"; // Append the '%' sign to search for names like the one input in the box
        sasDataModule->InschrijvingSQLDataSet->Open();
        sasDataModule->InschrijvingClientDataSet->Active=true;
        Facnainschr->OpslaanButton->Enabled = true;
         //Facnainschr->InschrijfJaarDBEdit->ReadOnly = false;
}
//---------------------------------------------------------------------------

static int GetVolgnummer(char *richting, int jaar, bool & algemeen_nummer)
{
//Kijk of jaar voorkomt in maxnummers. Indien niet dan is het een oude inschrijving en dan
// moet het algemene maxnummer worden opgehaald


   sasDataModule->MaxNummersSQLDataSet->Close(); // Flush previous query
   sasDataModule->MaxNummersClientDataSet->Active=false; // Flush previous data in set
   sasDataModule->MaxNummersSQLDataSet->CommandText="select * from maxnummers where RICHTING = :RICHTING AND JAAR = :JAAR";
   sasDataModule->MaxNummersSQLDataSet->ParamByName("RICHTING")->Value = richting;
   sasDataModule->MaxNummersSQLDataSet->ParamByName("JAAR")->Value = jaar;
   sasDataModule->MaxNummersSQLDataSet->Open();
   sasDataModule->MaxNummersClientDataSet->Active=true;
//   Application->MessageBox("in getvolgnummer",Facnainschr->VolgnummerDBEdit->Text.c_str(), MB_OK);

   if ((Facnainschr->VolgnummerDBEdit->Text != "") && (atoi(Facnainschr->JaarDBEdit->Text.c_str()) == jaar))
     {//Application->MessageBox("in getvolgnummer",Facnainschr->VolgnummerDBEdit->Text.c_str(), MB_OK);
       algemeen_nummer = false;
       return atoi(Facnainschr->VolgnummerDBEdit->Text.c_str());}
   else   //Haal het algemene volgnumer op
    {
   sasDataModule->MaxNummersSQLDataSet->Close(); // Flush previous query
   sasDataModule->MaxNummersClientDataSet->Active=false; // Flush previous data in set
   sasDataModule->MaxNummersSQLDataSet->CommandText="select * from maxnummers where RICHTING = :RICHTING AND JAAR = :JAAR";
   sasDataModule->MaxNummersSQLDataSet->ParamByName("RICHTING")->Value= "ALL";
   sasDataModule->MaxNummersSQLDataSet->ParamByName("JAAR")->Value= 0;
   sasDataModule->MaxNummersSQLDataSet->Open();
   sasDataModule->MaxNummersClientDataSet->Active=true;
   algemeen_nummer = true;
   return atoi(Facnainschr->VolgnummerDBEdit->Text.c_str());
    }
}
//---------------------------------------------------------------------------

static void Werkmaxnummersbij(int nummer, int jaar, char *richting)
{
  if ((nummer == 1000)&& (Facnainschr->VolgnummerDBEdit->Text == "")) //toevoegen
    {
      sasDataModule->MaxNummersSQLDataSet->Close(); // Flush previous query
      sasDataModule->MaxNummersSQLDataSet->CommandType = ctQuery;
      sasDataModule->MaxNummersSQLDataSet->CommandText="INSERT INTO maxnummers  (RICHTING, JAAR, NUMMER) VALUES (:RICHTING, :JAAR, :NUMMER)";
      sasDataModule->MaxNummersSQLDataSet->ParamByName("RICHTING")->Value= richting;
      sasDataModule->MaxNummersSQLDataSet->ParamByName("JAAR")->Value= jaar;
      sasDataModule->MaxNummersSQLDataSet->ParamByName("NUMMER")->Value= nummer;
      sasDataModule->MaxNummersSQLDataSet->ExecSQL();
      sasDataModule->MaxNummersClientDataSet->Active=true;
    }
  else //updaten
    {
//    Application->MessageBox("in werkbij","", MB_OK);

      sasDataModule->MaxNummersSQLDataSet->Close(); // Flush previous query
      sasDataModule->MaxNummersSQLDataSet->CommandType = ctQuery;
      sasDataModule->MaxNummersSQLDataSet->CommandText="UPDATE maxnummers  SET NUMMER = :NUMMER, JAAR =:JAAR WHERE RICHTING = :RICHTING ";
      sasDataModule->MaxNummersSQLDataSet->ParamByName("RICHTING")->Value= richting;
      sasDataModule->MaxNummersSQLDataSet->ParamByName("JAAR")->Value= jaar;
      sasDataModule->MaxNummersSQLDataSet->ParamByName("NUMMER")->Value= nummer;
      sasDataModule->MaxNummersSQLDataSet->ExecSQL();
      sasDataModule->MaxNummersClientDataSet->Active=true;
     // Application->MessageBox("in werkbij","", MB_OK);
    }
//Application->MessageBox("in werkbij","", MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TFacnainschr::OpslaanButtonClick(TObject *Sender)
{
    int nummer;
    bool is_algemeen = false;
    if ( IdCardDBEdit->Text == "")
      {
        Application->MessageBox("", "U heeft geen idnummer opgegeven",MB_OK + MB_ICONWARNING);
        return;
      }
     String jr = InschrijfJaarDBEdit->Text;
     TDateTime datum = Now();
     unsigned short jar, mnd, dag;
     datum.DecodeDate(&jar, &mnd, &dag);
     if (mnd < 9) jar--;

    int jaar = atoi(jr.c_str());
    char buf[5];
    if (jaar == jar)
      {
         Application->MessageBox("Ga naar faculteitstudent voor huidig collegejaar", "Geen nainschrijving", MB_OK + MB_ICONWARNING);
         return;
      }
    else if (jaar > jar)
      {
         Application->MessageBox("Jaar moet kleiner zijn dan huidig collegejaar", "Jaar fout", MB_OK + MB_ICONWARNING);
         return;
      }
    String studienr;

      //We halen eerst het hoogste volgnummer op voor deze studierichting in maxnummers
    //Daarna maken we het studienummer
      nummer = GetVolgnummer(studie.c_str(), jaar, is_algemeen);
      nummer++;

      studienr = jr.SubString(3,2) + studie +  String(itoa(nummer, buf, 10));
 //Application->MessageBox("uit getvolgnummer", studienr.c_str(), MB_OK);

    //Nu moeten we eerst maxnummers updaten en daarna de inschrijving toevoegen
      if (is_algemeen) {jaar = 0;studie = "ALL";}
      Werkmaxnummersbij(nummer, jaar, studie.c_str());
          // Application->MessageBox("uit werkbij",studienr.c_str(), MB_OK);
      sasDataModule->InschrijvingSQLDataSet->Close();
      Facnainschr->OpslaanButton->Enabled = false;
      sasDataModule->InschrijvingSQLDataSet->CommandType = ctQuery;
      sasDataModule->InschrijvingSQLDataSet->CommandText = "INSERT INTO inschrijving (FACULTEIT_ID,\
       STUDIERICHTING_ID, STUDIENR,IDKAARTNR,INSCHRIJFJAAR, SYSTEEM_ID,MEMO)  VALUES (:FACULTEIT_ID,\
        :STUDIERICHTING_ID, :STUDIENR,:IDKAARTNR,:INSCHRIJFJAAR,:SYSTEEM,:MEMO) ";
      sasDataModule->InschrijvingSQLDataSet->Params->Items[0]->AsString = Facnainschr->FaculteitComboBox->KeyValue;
      sasDataModule->InschrijvingSQLDataSet->Params->Items[1]->AsString = Facnainschr->StudierichtingComboBox->KeyValue;
      sasDataModule->InschrijvingSQLDataSet->Params->Items[2]->AsString = studienr.c_str();
      sasDataModule->InschrijvingSQLDataSet->Params->Items[3]->AsString = Facnainschr->IdCardDBEdit->Text;
      sasDataModule->InschrijvingSQLDataSet->Params->Items[4]->AsString = Facnainschr->InschrijfJaarDBEdit->Text;
      sasDataModule->InschrijvingSQLDataSet->Params->Items[5]->AsString = Facnainschr->SysteemDBLookupListBox->KeyValue;
      sasDataModule->InschrijvingSQLDataSet->Params->Items[6]->AsString = Facnainschr->StudieDBMemo->Text;
      sasDataModule->InschrijvingSQLDataSet->ExecSQL();


//    Facnainschr->OpslaanButton->Enabled = false;
    //Nu moet de grid opnieuw gevuld worden, om de toevoeging zichtbaar te maken
    sasDataModule->GridClientDataSet1->Active=false; // Flush previous data in set
    sasDataModule->GridSQLDataSet1->CommandText = "SELECT MAX(VOLGNR) AS VOLGNR FROM INSCHRIJVING";


  sasDataModule->GridSQLDataSet1->Open();
  sasDataModule->GridClientDataSet1->Active=true;
  int maxvolgnr;
  if(LastRecordsDBGrid->Fields[0]->Text =="")
    maxvolgnr = 0;
  else
    maxvolgnr = LastRecordsDBGrid->Fields[0]->Value;
 // char buf[7];
 // Application->MessageBox("", itoa(maxvolgnr, buf, 10), MB_OK);
  sasDataModule->GridSQLDataSet1->Close();
  sasDataModule->GridClientDataSet1->Active=false;
  sasDataModule->GridSQLDataSet1->CommandText = "SELECT * FROM INSCHRIJVING WHERE volgnr > :volgnr  ORDER BY VOLGNR DESC";
  sasDataModule->GridSQLDataSet1->ParamByName("volgnr")->AsString = maxvolgnr - 50;

  sasDataModule->GridSQLDataSet1->Open();
  sasDataModule->GridClientDataSet1->Active=true;
}

//---------------------------------------------------------------------------

void __fastcall TFacnainschr::FaculteitComboBoxClick(TObject *Sender)
{
   if ( IdCardDBEdit->Text == "")
      {
          return;
      }
   if (Facnainschr->FaculteitComboBox->Text != "")
     {
   // Application->MessageBox("","faculteitclick",MB_OK);
        Facnainschr->StudierichtingComboBox->Enabled = true;
        sasDataModule->StudierichtingSQLDataSet->Close(); // Flush previous query
        sasDataModule->StudierichtingClientDataSet->Active=false; // Flush previous data in set

        sasDataModule->StudierichtingSQLDataSet->CommandText = "select * from studierichting where faculteit_id = :faculteit_id and RICHTING_ID not like :RICHTING_ID";
        sasDataModule->StudierichtingSQLDataSet->ParamByName("faculteit_id")->Value = Facnainschr->FaculteitComboBox->KeyValue;
        sasDataModule->StudierichtingSQLDataSet->ParamByName("RICHTING_ID")->Value = "MP";
        sasDataModule->StudierichtingSQLDataSet->Open();
        sasDataModule->StudierichtingClientDataSet->Active=true;
        Label12->Enabled = true;

   // Nu gaan we na of de student eerder was ingeschreven. Alle inschrijvingen worden
   // getoond in een grid.

     }
}
//---------------------------------------------------------------------------

void __fastcall TFacnainschr::StudierichtingComboBoxClick(
      TObject *Sender)
{
    String jaar = CurrentYear();
          //Facnainschr->InschrijfJaarDBEdit->ReadOnly = true;
        //Facnainschr->StudieNRDBEdit->ReadOnly = false;
    studie = Facnainschr->StudierichtingComboBox->KeyValue;
//  String parameter = jaar.SubString(3,2) + studie;

 // sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
 // sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set

 // sasDataModule->InschrijvingSQLDataSet->CommandText = "SELECT * FROM INSCHRIJVING WHERE STUDIENR LIKE :STUDIENR ORDER BY STUDIENR DESC";
//  sasDataModule->InschrijvingSQLDataSet->CommandText = "SELECT MAX(STUDIENR) FROM INSCHRIJVING WHERE STUDIENR LIKE :STUDIENR";
//  sasDataModule->InschrijvingSQLDataSet->Params->Items[0]->AsString = parameter;
//  sasDataModule->InschrijvingSQLDataSet->Open(); // Flush previous query
//  sasDataModule->InschrijvingClientDataSet->Active=true; // Flush previous data in set
  //sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
 // sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set



     TDateTime datum = Now();
     unsigned short jar, mnd, dag;
     datum.DecodeDate(&jar, &mnd, &dag);

    int jr = atoi(jaar.c_str());
    char buf[5];
    if (mnd < 9)
      {
        jr--;
        jaar = itoa(jr, buf, 10);
      }
//   Facnainschr->InschrijfJaarDBEdit->Text = jaar;
//  studienr = Facnainschr->LastRecordsDBGrid->Fields[2]->Value;
  //Application->MessageBox("nummer", studienr.c_str(), MB_OK);
/*  char buf[5];
  int nr=1000;
  if (!(studienr == ""))
     {
        strcpy(buf, studienr.SubString(5,4).c_str());
        nr = atoi(buf); nr++;
     //   Application->MessageBox("nummer", nr + "", MB_OK);
      }
  itoa(nr, buf, 10);*/
  //Application->MessageBox("nummer2",nr+"", MB_OK);
//  strcpy(&studienr.c_str()[4],buf);
//  strncpy(&(studienr.c_str())[0], &(parameter.c_str())[0],4);
 // Application->MessageBox("", studienr.c_str(), MB_OK);

 //  Facnainschr->StudieNRDBEdit->Text = studienr.c_str();
//  Facnainschr->StudieNRDBEdit->Text = parameter;       // Facnainschr->StudieNRDBEdit->ReadOnly = true;

}
//---------------------------------------------------------------------------

void __fastcall TFacnainschr::IdCardDBEditExit(TObject *Sender)
{
  if (Facnainschr->IdCardDBEdit->Modified)
    {
        //Nu moet gezocht worden naar dit record in persoon
        //Als het niet voorkomt dient het veld schoon gemaakt te worden en een
        //boodschap op het scherm getoond te worden
   String idnummer = Facnainschr->IdCardDBEdit->Text;
   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
   sasDataModule->personSQLDataSet->CommandText= "select * from persoon where IDKAARTNR = :IDKAARTNR";
   sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value = LowerCase(idnummer); // Append the '%' sign to search for names like the one input in the box
   sasDataModule->personSQLDataSet->Open();
   sasDataModule->personClientDataSet->Active=true;
   if (sasDataModule->personClientDataSet->IsEmpty())
    {
      Facnainschr->IdCardDBEdit->Text = "";
      Application->MessageBox("", "Het door u opgegeven idnummer komt niet voor",MB_OK + MB_ICONWARNING);
    }
   }
}
//---------------------------------------------------------------------------

void __fastcall TFacnainschr::InschrijvingDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
   //Ga naar juiste record in persoon tabel
  /* switch (Button)
     {
   case nbFirst : sasDataModule->personClientDataSet->FindFirst(); break;
   case nbNext  : sasDataModule->personClientDataSet->FindNext(); break;
   case nbPrior : sasDataModule->personClientDataSet->FindPrior(); break;
   case nbLast  : sasDataModule->personClientDataSet->FindLast();
     }   */
    //nu moet gegaan worden naar het gekoppelde record in inschrijving
        if ( IdCardDBEdit->Text == "") return;
    sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
    sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->InschrijvingSQLDataSet->CommandText="select inschrijving.inschrijfjaar, inschrijving.* from inschrijving where IDKAARTNR = :IDKAARTNR ORDER BY inschrijving.INSCHRIJFJAAR DESC";
    sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Facnainschr->IdCardDBEdit->Text);
    sasDataModule->InschrijvingSQLDataSet->Open();
    sasDataModule->InschrijvingClientDataSet->Active=true;


  if (Facnainschr->IdCardDBEdit->Text != "")
    {
      TDateTime datum = Now();
      unsigned short jar, mnd, dag;
      datum.DecodeDate(&jar, &mnd, &dag);

     // int jr = atoi((CurrentYear()).c_str());
      char buf[5];
      if (mnd < 9)
        jar--;
      String jaar = itoa(jar, buf, 10);
//      Application->MessageBox("", "change", MB_OK);
      sasDataModule->EerdereInschrijvingenSQLDataSet->Close(); // Flush previous query
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->EerdereInschrijvingenSQLDataSet->CommandText= "select inschrijving.inschrijfjaar, inschrijving.* from inschrijving where IDKAARTNR = :IDKAARTNR AND INSCHRIJFJAAR != :DITCOLLEGEJAAR ORDER BY INSCHRIJFJAAR DESC";
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("idkaartnr")->Value = LowerCase(Facnainschr->IdCardDBEdit->Text); // Append the '%' sign to search for names like the one input in the box
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("DITCOLLEGEJAAR")->Value = jaar;
      sasDataModule->EerdereInschrijvingenSQLDataSet->Open();
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFacnainschr::ToggleButtonClick(TObject *Sender)
{
 if (Facnainschr->ToggleButton->Caption == "op idnummer")
      Facnainschr->ToggleButton->Caption = "op naam";
  else
      Facnainschr->ToggleButton->Caption = "op idnummer";
}
//---------------------------------------------------------------------------

void __fastcall TFacnainschr::IdCardDBEditChange(TObject *Sender)
{
  // Het onderstaande dient plaats te vinden indien het idkaartnr veranderdt
  // Nu moet de inschrijving query gedaan worden zodat door
  // de inschrijvingen gebladerd kan worden
  // als op een knop gedrukt wordt van de navigator dan moet ook het overeenkomstige
  // persoonsrecord opgehaald worden.
  // Als op de modus knopgedukt wordt en modus wordt twee, dan dient de query opnieuw
  // uitgevoerd te worden.

}
//---------------------------------------------------------------------------



