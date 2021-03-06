//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Schakelstud.h"
#include "Main.h"
#include "sasdm.h"
#include "person.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern int SModus;
TSchakelstudent *Schakelstudent;
//---------------------------------------------------------------------------
__fastcall TSchakelstudent::TSchakelstudent(TComponent* Owner)
        : TForm(Owner)
{
  //FModus = 0;
  sasDataModule->personSQLDataSet->Close();
  sasDataModule->personClientDataSet->Close();
  sasDataModule->personSQLDataSet->CommandText = "SELECT * FROM persoon";
  sasDataModule->personSQLDataSet->Open();
  sasDataModule->personClientDataSet->Open();
  sasDataModule->SchakelSQLDataSet->Close();
  sasDataModule->SchakelClientDataSet->Close();
  sasDataModule->SchakelSQLDataSet->CommandText = "SELECT * FROM schakel";
  sasDataModule->SchakelSQLDataSet->Open();
  sasDataModule->SchakelClientDataSet->Open();
  Schakelstudent->NieuwButton->Enabled = false;
  Schakelstudent->OpslaanButton->Enabled = false;
  Schakelstudent->VerwijderButton->Enabled = false;

  sasDataModule->SchakelGridSQLDataSet->Close(); // Flush previous query

  sasDataModule->SchakelGridClientDataSet->Active=false; // Flush previous data in set

  sasDataModule->SchakelGridSQLDataSet->CommandText = "SELECT MAX(VOLGNR) AS VOLGNR FROM SCHAKEL";


  sasDataModule->SchakelGridSQLDataSet->Open();
  sasDataModule->SchakelGridClientDataSet->Active=true;
  int maxvolgnr;
  if(Schakelstudent->LastRecordsDBGrid->Fields[0]->Text =="")
    maxvolgnr = 0;
  else
    maxvolgnr = Schakelstudent->LastRecordsDBGrid->Fields[0]->Value;

 // char buf[7];
 // Application->MessageBox("", itoa(maxvolgnr, buf, 10), MB_OK);

  sasDataModule->SchakelGridSQLDataSet->Close();
  sasDataModule->SchakelGridClientDataSet->Active=false;
  sasDataModule->SchakelGridSQLDataSet->CommandText = "SELECT * FROM SCHAKEL WHERE volgnr > :volgnr ORDER BY VOLGNR DESC";
  sasDataModule->SchakelGridSQLDataSet->ParamByName("volgnr")->AsString = maxvolgnr - 50;

  sasDataModule->SchakelGridSQLDataSet->Open();
  sasDataModule->SchakelGridClientDataSet->Active=true;

   sasDataModule->StudierichtingSQLDataSet->Close(); // Flush previous query
   sasDataModule->StudierichtingClientDataSet->Active=false; // Flush previous data in set

   sasDataModule->StudierichtingSQLDataSet->CommandText = "select * from studierichting where schakelen=1";
   sasDataModule->StudierichtingSQLDataSet->Open();
   sasDataModule->StudierichtingClientDataSet->Active=true;

 //   last->Text= String(sasDataModule->SchakelClientDataSet->RecordCount);
 //   first->Text= String(sasDataModule->SchakelClientDataSet->RecNo);

}
//---------------------------------------------------------------------------
void __fastcall TSchakelstudent::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  // HoofdScherm->Inschrijven2->Checked = false;
   HoofdScherm->Show();

   Free();
}
//---------------------------------------------------------------------------


void __fastcall TSchakelstudent::Close1Click(TObject *Sender)
{
 // HoofdScherm->Inschrijven2->Checked = false;
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TSchakelstudent::Exit1Click(TObject *Sender)
{
    HoofdScherm->Close();
 }
//---------------------------------------------------------------------------
void __fastcall TSchakelstudent::SearchButtonClick(TObject *Sender)
{
        // Check if the connection is already established
        if (sasDataModule->sasSQLConnection->Connected!=true)
        {
           sasDataModule->sasSQLConnection->Connected=true;
        }
        sasDataModule->personSQLDataSet->Close(); // Flush previous query
        sasDataModule->personClientDataSet->Active=false; // Flush previous data in set

        if (Schakelstudent->ToggleButton->Caption == "op idnummer")
         {
           sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
           sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Schakelstudent->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
         }
       else
         {
           sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
           sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(Schakelstudent->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
         }
        sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
        String idkaartnr = Schakelstudent->IdCardDBEdit->Text;
        sasDataModule->SchakelSQLDataSet->Close(); // Flush previous query
        sasDataModule->SchakelClientDataSet->Active=false; // Flush previous data in set
        sasDataModule->SchakelSQLDataSet->CommandText="select * from schakel where IDKAARTNR like :IDKAARTNR";
        sasDataModule->SchakelSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(idkaartnr); // Append the '%' sign to search for names like the one input in the box
        sasDataModule->SchakelSQLDataSet->Open();
        sasDataModule->SchakelClientDataSet->Active=true;

//    last->Text= String(sasDataModule->SchakelClientDataSet->RecordCount);
 //   first->Text= String(sasDataModule->SchakelClientDataSet->RecNo);

}
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   Schakelstudent->StudierichtingComboBox->ReadOnly=mode;
 //ReadOnly=mode;
 //  Schakelstudent->AfgerondDBRadioGroup->ReadOnly=mode;
}
//--------------------------------------------------------------------------

static void DoRead()
{
    Schakelstudent->InschrijvingDBNavigator->Enabled = true;
    Schakelstudent->AfgerondDBRadioGroup->Enabled = false;
    Schakelstudent->NieuwButton->Enabled = false;
    Schakelstudent->OpslaanButton->Enabled = false;
    Schakelstudent->VerwijderButton->Enabled = false;
    Schakelstudent->Label2->Show();
    Schakelstudent->SearchEdit->Show();
    Schakelstudent->SearchButton->Show();
    Schakelstudent->ToggleButton->Show();
    Schakelstudent->LastRecordsDBGrid->Show();
 //   Schakelstudent->StudierichtingComboBox->Enabled = false;
    Schakelstudent->IdCardDBEdit->ReadOnly = true;
    Schakelstudent->InschrijvingDBNavigator->Visible = true;
     Schakelstudent->StudieDBMemo->ReadOnly = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    Schakelstudent->InschrijvingDBNavigator->Enabled = true;
    Schakelstudent->AfgerondDBRadioGroup->Enabled = false;
    Schakelstudent->NieuwButton->Enabled = false;
    Schakelstudent->OpslaanButton->Enabled = false;
    Schakelstudent->VerwijderButton->Enabled = true;
    Schakelstudent->Label2->Show();
    Schakelstudent->SearchEdit->Show();
    Schakelstudent->SearchButton->Show();
    Schakelstudent->ToggleButton->Show();
    Schakelstudent->LastRecordsDBGrid->Show();
 //   Schakelstudent->StudierichtingComboBox->Enabled = false;
    Schakelstudent->IdCardDBEdit->ReadOnly = true;
    Schakelstudent->InschrijvingDBNavigator->Visible = true;
    Schakelstudent->StudieDBMemo->ReadOnly = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
    Schakelstudent->InschrijvingDBNavigator->Enabled = true;
    Schakelstudent->AfgerondDBRadioGroup->Enabled = false;
    Schakelstudent->NieuwButton->Enabled = false;
    Schakelstudent->OpslaanButton->Enabled = true;
    Schakelstudent->VerwijderButton->Enabled = false;
    Schakelstudent->Label2->Show();
    Schakelstudent->SearchEdit->Show();
    Schakelstudent->SearchButton->Show();
    Schakelstudent->ToggleButton->Show();
    Schakelstudent->LastRecordsDBGrid->Show();
    SetReadModus(true);
//    Schakelstudent->StudierichtingComboBox->Enabled = false;
    Schakelstudent->IdCardDBEdit->ReadOnly = false;
    Schakelstudent->InschrijvingDBNavigator->Visible = true;
    Schakelstudent->StudieDBMemo->ReadOnly = false;
}
//---------------------------------------------------------------------------

static void  DoInsert()
{
    Schakelstudent->InschrijvingDBNavigator->Enabled = false;
    Schakelstudent->AfgerondDBRadioGroup->Enabled = false;
    Schakelstudent->NieuwButton->Enabled = true;
    Schakelstudent->OpslaanButton->Enabled = false;
    Schakelstudent->VerwijderButton->Enabled = false;
    Schakelstudent->SearchEdit->Hide();
    Schakelstudent->SearchButton->Hide();
    Schakelstudent->ToggleButton->Hide();
    SetReadModus(false);
 //   Schakelstudent->StudierichtingComboBox->Enabled = false;
    Schakelstudent->IdCardDBEdit->ReadOnly = false;
    Schakelstudent->InschrijvingDBNavigator->Visible = true;
    Schakelstudent->AfgerondDBRadioGroup->ReadOnly = true;
    Schakelstudent->StudieDBMemo->ReadOnly = false;
}
//---------------------------------------------------------------------------


void __fastcall TSchakelstudent::NieuwButtonClick(TObject *Sender)
{
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
        sasDataModule->SchakelSQLDataSet->Close(); // Flush previous query
        sasDataModule->SchakelClientDataSet->Active=false; // Flush previous data in set
        sasDataModule->SchakelSQLDataSet->CommandText="select * from schakel where IDKAARTNR = :Idkaartnr";
        sasDataModule->SchakelSQLDataSet->ParamByName("idkaartnr")->Value="-------"; // Append the '%' sign to search for names like the one input in the box
        sasDataModule->SchakelSQLDataSet->Open();
        sasDataModule->SchakelClientDataSet->Active=true;
        Schakelstudent->OpslaanButton->Enabled = true;
        //Faculteitstudent->InschrijfJaarDBEdit->ReadOnly = false;
}
//---------------------------------------------------------------------------

static int GetVolgnummer(char *richting, int jaar)
{
    sasDataModule->MaxNummersSQLDataSet->Close(); // Flush previous query
   sasDataModule->MaxNummersClientDataSet->Active=false; // Flush previous data in set
   sasDataModule->MaxNummersSQLDataSet->CommandText="select * from maxnummers where RICHTING = :RICHTING AND JAAR = :JAAR";
   sasDataModule->MaxNummersSQLDataSet->ParamByName("RICHTING")->Value= "SJ";
   sasDataModule->MaxNummersSQLDataSet->ParamByName("JAAR")->Value= jaar;
   sasDataModule->MaxNummersSQLDataSet->Open();
   sasDataModule->MaxNummersClientDataSet->Active=true;
 //  Application->MessageBox("in getvolgnummer","", MB_OK);

   if ((Schakelstudent->VolgnummerDBEdit->Text != "") && (atoi(Schakelstudent->JaarDBEdit->Text.c_str()) == jaar))
     {//Application->MessageBox("in getvolgnummer",Schakelstudent->VolgnummerDBEdit->Text.c_str(), MB_OK);

       return atoi(Schakelstudent->VolgnummerDBEdit->Text.c_str());}
   else
     return 999;
}
//---------------------------------------------------------------------------

static void Werkmaxnummersbij(int nummer, int jaar, char *richting)
{
  if ((nummer == 1000)&& (Schakelstudent->VolgnummerDBEdit->Text == "")) //toevoegen
    {
     // sasDataModule->MaxNummersSQLDataSet->Close(); // Flush previous query
      sasDataModule->MaxNummersSQLDataSet->CommandType = ctQuery;
      sasDataModule->MaxNummersSQLDataSet->CommandText="INSERT INTO maxnummers  (RICHTING, JAAR, NUMMER) VALUES (:RICHTING, :JAAR, :NUMMER)";
      sasDataModule->MaxNummersSQLDataSet->ParamByName("RICHTING")->Value= richting;
      sasDataModule->MaxNummersSQLDataSet->ParamByName("JAAR")->Value= jaar;
      sasDataModule->MaxNummersSQLDataSet->ParamByName("NUMMER")->Value= nummer;
      sasDataModule->MaxNummersSQLDataSet->ExecSQL();
     // sasDataModule->MaxNummersClientDataSet->Active=true;
    }
  else //updaten
    {
  //Application->MessageBox("in werkbij","updaten", MB_OK);

      //sasDataModule->MaxNummersSQLDataSet->Close(); // Flush previous query
      sasDataModule->MaxNummersSQLDataSet->CommandType = ctQuery;
      sasDataModule->MaxNummersSQLDataSet->CommandText="UPDATE maxnummers  SET NUMMER = :NUMMER  WHERE RICHTING = :RICHTING  AND JAAR = :JAAR";
      sasDataModule->MaxNummersSQLDataSet->ParamByName("RICHTING")->Value= richting;
      sasDataModule->MaxNummersSQLDataSet->ParamByName("JAAR")->Value= jaar;
      sasDataModule->MaxNummersSQLDataSet->ParamByName("NUMMER")->Value= nummer;
      sasDataModule->MaxNummersSQLDataSet->ExecSQL();
      //sasDataModule->MaxNummersClientDataSet->Active=true;
    }
//Application->MessageBox("uit werkbij","", MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TSchakelstudent::OpslaanButtonClick(TObject *Sender)
{
    String richting = "SJ";
    int nummer;
    String jr = CurrentYear();
    TDateTime datum = Now();
    unsigned short jar, mnd, dag;
    datum.DecodeDate(&jar, &mnd, &dag);

    int jaar = atoi(jr.c_str());
    char buf[5];
    if (mnd < 9)
      {
        jaar--;
        jr = itoa(jaar, buf, 10);
      }
    String studienr;
    if (SModus == 1)
    {
//       Application->MessageBox("voor getvolgnummer","", MB_OK);

      nummer = GetVolgnummer("SJ", jaar);
      nummer++;
      studienr = jr.SubString(3,2) + richting +  String(itoa(nummer, buf, 10));
//Application->MessageBox("uit getvolgnummer", studienr.c_str(), MB_OK);

    //Nu moeten we eerst de inschrijving toevoegen en daarna maxnummers updaten

      try
      {
        sasDataModule->SchakelSQLDataSet->Close();
        Schakelstudent->OpslaanButton->Enabled = false;
        sasDataModule->SchakelSQLDataSet->CommandType = ctQuery;
        sasDataModule->SchakelSQLDataSet->CommandText = "INSERT INTO SCHAKEL (STUDIERICHTING_ID, STUDIENR,IDKAARTNR,SCHAKELJAAR, MEMO)  VALUES (:STUDIERICHTING_ID, :STUDIENR,:IDKAARTNR,:SCHAKELJAAR,:MEMO) ";
        sasDataModule->SchakelSQLDataSet->Params->Items[0]->AsString = Schakelstudent->StudierichtingComboBox->KeyValue;
        sasDataModule->SchakelSQLDataSet->Params->Items[1]->AsString = studienr.c_str();
        sasDataModule->SchakelSQLDataSet->Params->Items[2]->AsString = Schakelstudent->IdCardDBEdit->Text;
        sasDataModule->SchakelSQLDataSet->Params->Items[3]->AsString = Schakelstudent->InschrijfJaarDBEdit->Text;
        sasDataModule->SchakelSQLDataSet->Params->Items[4]->AsString = Schakelstudent->StudieDBMemo->Text;
        sasDataModule->SchakelSQLDataSet->ExecSQL();
       }
      catch (Exception &exception)
        {
          // Application->MessageBox(exception.Message.c_str(),"",MB_OK);
           Application->MessageBox("Fout bij het toevoegen. Probeer het opnieuw.", "", MB_OK|MB_ICONSTOP);
           return;
        }

       Werkmaxnummersbij(nummer, jaar, "SJ");
    }
   else if (SModus == 2)
    {
      sasDataModule->SchakelSQLDataSet->CommandType = ctQuery;
      sasDataModule->SchakelSQLDataSet->CommandText = "UPDATE SCHAKEL SET IDKAARTNR=:IDKAARTNR, MEMO=:MEMO WHERE STUDIENR = :STUDIENR";
      sasDataModule->SchakelSQLDataSet->Params->Items[0]->AsString = Schakelstudent->IdCardDBEdit->Text;
      sasDataModule->SchakelSQLDataSet->Params->Items[1]->AsString = Schakelstudent->StudieDBMemo->Text;
      sasDataModule->SchakelSQLDataSet->Params->Items[2]->AsString = Schakelstudent->StudieNRDBEdit->Text;

      sasDataModule->SchakelSQLDataSet->ExecSQL();


    /*  sasDataModule->personSQLDataSet->Close(); // Flush previous query
      sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :Name";
      sasDataModule->personSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
      sasDataModule->personSQLDataSet->Open();
      sasDataModule->personClientDataSet->Active=true; */
    }
    Schakelstudent->OpslaanButton->Enabled = false;
    //Nu moet de grid opnieuw gevuld worden, om de toevoeging zichtbaar te maken
      sasDataModule->SchakelGridSQLDataSet->Close(); // Flush previous query

  sasDataModule->SchakelGridClientDataSet->Active=false; // Flush previous data in set

  sasDataModule->SchakelGridSQLDataSet->CommandText = "SELECT MAX(VOLGNR) AS VOLGNR FROM SCHAKEL";


  sasDataModule->SchakelGridSQLDataSet->Open();
  sasDataModule->SchakelGridClientDataSet->Active=true;
  int maxvolgnr;
  if(Schakelstudent->LastRecordsDBGrid->Fields[0]->Text =="")
    maxvolgnr = 0;
  else
    maxvolgnr = Schakelstudent->LastRecordsDBGrid->Fields[0]->Value;

 // char buf[7];
 // Application->MessageBox("", itoa(maxvolgnr, buf, 10), MB_OK);

  sasDataModule->SchakelGridSQLDataSet->Close();
  sasDataModule->SchakelGridClientDataSet->Active=false;
  sasDataModule->SchakelGridSQLDataSet->CommandText = "SELECT * FROM SCHAKEL WHERE volgnr > :volgnr ORDER BY VOLGNR DESC";
  sasDataModule->SchakelGridSQLDataSet->ParamByName("volgnr")->AsString = maxvolgnr - 50;

  sasDataModule->SchakelGridSQLDataSet->Open();
  sasDataModule->SchakelGridClientDataSet->Active=true;


}
//---------------------------------------------------------------------------

void __fastcall TSchakelstudent::VerwijderButtonClick(TObject *Sender)
{
  sasDataModule->SchakelSQLDataSet->CommandType = ctQuery;
  sasDataModule->SchakelSQLDataSet->CommandText = "DELETE FROM SCHAKEL WHERE IDKAARTNR =   :IDKAARTNR ";
  sasDataModule->SchakelSQLDataSet->Params->Items[0]->AsString = Schakelstudent->IdCardDBEdit->Text;
  sasDataModule->SchakelSQLDataSet->ExecSQL();

  sasDataModule->personSQLDataSet->Close(); // Flush previous query
  sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :Name";
  sasDataModule->personSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
  sasDataModule->personSQLDataSet->Open();
  sasDataModule->personClientDataSet->Active=true;

   sasDataModule->SchakelSQLDataSet->Close(); // Flush previous query
   sasDataModule->SchakelClientDataSet->Active=false; // Flush previous data in set
   sasDataModule->SchakelSQLDataSet->CommandText="select * from schakel where IDKAARTNR = :IDKAARTNR";
   sasDataModule->SchakelSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Schakelstudent->SearchEdit->Text); // Append the '%' sign to search for names like the one input in the box
   sasDataModule->SchakelSQLDataSet->Open();
   sasDataModule->SchakelClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TSchakelstudent::StudierichtingComboBoxClick(TObject *Sender)
{
  int nummer;
  String jr = CurrentYear();
  TDateTime datum = Now();
  unsigned short jar, mnd, dag;
  datum.DecodeDate(&jar, &mnd, &dag);

  int jaar = atoi(jr.c_str());
  char buf[5];
  if (mnd < 9)
      {
        jaar--;
        jr = itoa(jaar, buf, 10);
      }
    String studienr;
//  String studie("SJ");
//  String parameter = jaar.SubString(3,2) + studie;

  Schakelstudent->InschrijfJaarDBEdit->Text = jr;
/*  if (Schakelstudent->LastRecordsDBGrid->Fields[2]->Text == "")
    studienr = "";
  else
    studienr =  Schakelstudent->LastRecordsDBGrid->Fields[2]->Value;
  Application->MessageBox("nummer", studienr.c_str(), MB_OK);
  char buf[5];
  int nr=1000;
  if (!(studienr == ""))
     {
        strcpy(buf, studienr.SubString(5,4).c_str());
        nr = atoi(buf); nr++;
      }
  itoa(nr, buf, 10);

  studienr = parameter + String(buf);
  Schakelstudent->StudieNRDBEdit->Text = studienr.c_str();*/
}
//---------------------------------------------------------------------------

void __fastcall TSchakelstudent::IdCardDBEditExit(TObject *Sender)
{
  if (Schakelstudent->IdCardDBEdit->Modified)
    {
        //Nu moet gezocht worden naar dit record in persoon
        //Als het niet voorkomt dient het veld schoon gemaakt te worden en een
        //boodschap op het scherm getoond te worden
   String idnummer = Schakelstudent->IdCardDBEdit->Text;
   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
   sasDataModule->personSQLDataSet->CommandText= "select * from persoon where IDKAARTNR = :IDKAARTNR";
   sasDataModule->personSQLDataSet->ParamByName("IDKAARTNR")->Value = LowerCase(idnummer);
   sasDataModule->personSQLDataSet->Open();
   sasDataModule->personClientDataSet->Active=true;
   if (sasDataModule->personClientDataSet->IsEmpty())
    {
      Schakelstudent->IdCardDBEdit->Text = "";
      Application->MessageBox("", "Het door u opgegeven idnummer komt niet voor",MB_OK + MB_ICONWARNING);
    }
   }
}
//---------------------------------------------------------------------------

void __fastcall TSchakelstudent::InschrijvingDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
   //nu moet gegaan worden naar het gekoppelde record in inschrijving

   sasDataModule->SchakelSQLDataSet->Close(); // Flush previous query
   sasDataModule->SchakelClientDataSet->Active=false; // Flush previous data in set
   sasDataModule->SchakelSQLDataSet->CommandText= "select * from schakel where IDKAARTNR = :IDKAARTNR";
   sasDataModule->SchakelSQLDataSet->ParamByName("idkaartnr")->Value = LowerCase(Schakelstudent->IdCardDBEdit->Text);
   sasDataModule->SchakelSQLDataSet->Open();
   sasDataModule->SchakelSQLDataSet->Active=true;
   sasDataModule->SchakelClientDataSet->Active=true;

 //   last->Text= String(sasDataModule->SchakelClientDataSet->RecordCount);
 //  first->Text= String(sasDataModule->SchakelClientDataSet->RecNo);
}
//---------------------------------------------------------------------------


void __fastcall TSchakelstudent::ToggleButtonClick(TObject *Sender)
{
 if (Schakelstudent->ToggleButton->Caption == "op idnummer")
      Schakelstudent->ToggleButton->Caption = "op naam";
  else
      Schakelstudent->ToggleButton->Caption = "op idnummer";
}
//---------------------------------------------------------------------------



void __fastcall TSchakelstudent::FormActivate(TObject *Sender)
{
   switch (SModus)
    {
   case 0: ModusLabel->Font->Color = clNavy ;ModusLabel->Caption = "Studentgegevens opvragen"; DoRead();break;//lezen
   case 1: ModusLabel->Font->Color = clNavy ;ModusLabel->Caption = "Student inschrijven";DoInsert();break;//toevoegen
   case 2: ModusLabel->Font->Color = clNavy ;ModusLabel->Caption = "Studentgegevens wijzigen";DoUpdate();break;//wijzigen
   case 3: ModusLabel->Font->Color = clRed ;ModusLabel->Caption = "Student verwijderen";DoDelete();//verwijderen
    };
}
//---------------------------------------------------------------------------

