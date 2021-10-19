//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "constant.h"
#include "Facstud.h"
#include "Main.h"
#include "sasdm.h"
#include "sasbasictablesmod.h"
#include "person.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFaculteitstudent *Faculteitstudent;

extern int FModus;
void VulLaatsttoegevoegdeRecordsGrid();
static String studie;
extern String usergroup;

//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   Faculteitstudent->FaculteitComboBox->ReadOnly=mode;
   Faculteitstudent->StudierichtingComboBox->ReadOnly=mode;
   Faculteitstudent->AfstudeerDatumDBEdit->ReadOnly=mode;
   Faculteitstudent->SysteemDBLookupListBox->ReadOnly=mode;
   Faculteitstudent->VerlengingDBEdit->ReadOnly=mode;
   Faculteitstudent->StudieDBMemo->ReadOnly=mode;
   Faculteitstudent->InschrijfJaarDBEdit->ReadOnly=true;
   Faculteitstudent->InschrijfJaarDBEdit->Enabled=false;
   Faculteitstudent->Label6->Enabled = false;

}
//--------------------------------------------------------------------------

static void DoRead()
{
    Faculteitstudent->InschrijvingDBNavigator->Enabled = true;
    Faculteitstudent->NieuwButton->Enabled = false;
    Faculteitstudent->OpslaanButton->Enabled = false;
    Faculteitstudent->VerwijderButton->Enabled = false;
    Faculteitstudent->Label1->Enabled = false;
    Faculteitstudent->Label2->Show();
    Faculteitstudent->SearchEdit->Show();
    Faculteitstudent->SearchButton->Show();
    Faculteitstudent->ToggleButton->Show();
    Faculteitstudent->LastRecordsDBGrid->Show();
    Faculteitstudent->StudierichtingComboBox->Enabled = false;
    Faculteitstudent->FaculteitComboBox->Enabled = false;
    Faculteitstudent->IdCardDBEdit->ReadOnly = true;
    Faculteitstudent->InschrijvingDBNavigator->Visible = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    Faculteitstudent->InschrijvingDBNavigator->Enabled = true;
    Faculteitstudent->NieuwButton->Enabled = false;
    Faculteitstudent->OpslaanButton->Enabled = false;
    Faculteitstudent->VerwijderButton->Enabled = true;
    Faculteitstudent->Label1->Enabled = false;
    Faculteitstudent->Label2->Show();
    Faculteitstudent->SearchEdit->Show();
    Faculteitstudent->SearchButton->Show();
    Faculteitstudent->ToggleButton->Show();
    Faculteitstudent->LastRecordsDBGrid->Show();
    Faculteitstudent->StudierichtingComboBox->Enabled = false;
    Faculteitstudent->FaculteitComboBox->Enabled = false;
    Faculteitstudent->IdCardDBEdit->ReadOnly = true;
    Faculteitstudent->InschrijvingDBNavigator->Visible = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
    Faculteitstudent->InschrijvingDBNavigator->Enabled = true;
    Faculteitstudent->NieuwButton->Enabled = false;
    Faculteitstudent->OpslaanButton->Enabled = true;
    Faculteitstudent->VerwijderButton->Enabled = false;
    Faculteitstudent->Label2->Show();
    Faculteitstudent->Label1->Enabled = false;
    Faculteitstudent->SearchEdit->Show();
    Faculteitstudent->SearchButton->Show();
    Faculteitstudent->ToggleButton->Show();
    Faculteitstudent->LastRecordsDBGrid->Show();
    Faculteitstudent->StudierichtingComboBox->Enabled = false;
    Faculteitstudent->FaculteitComboBox->Enabled = false;
    Faculteitstudent->IdCardDBEdit->ReadOnly = false;
    Faculteitstudent->InschrijvingDBNavigator->Visible = true;
    SetReadModus(false);
}
//---------------------------------------------------------------------------

static void  DoInsert()
{
    Faculteitstudent->InschrijvingDBNavigator->Enabled = true;
    Faculteitstudent->NieuwButton->Enabled = true;
    Faculteitstudent->OpslaanButton->Enabled = false;
    Faculteitstudent->Label2->Enabled = true;
    Faculteitstudent->Label1->Enabled = true;
    Faculteitstudent->VerwijderButton->Enabled = false;
   // Faculteitstudent->SearchEdit->Hide();
   // Faculteitstudent->SearchButton->Hide();
   // Faculteitstudent->ToggleButton->Hide();
    SetReadModus(false);
    if (FModus == AFTERENTRY)
     {
       Faculteitstudent->InschrijfJaarDBEdit->ReadOnly=false;
       Faculteitstudent->InschrijfJaarDBEdit->Enabled=true;
       Faculteitstudent->Label6->Enabled = true;
     }
    Faculteitstudent->StudierichtingComboBox->Enabled = false;
    Faculteitstudent->FaculteitComboBox->Enabled = true;
    Faculteitstudent->IdCardDBEdit->ReadOnly = false;
    Faculteitstudent->InschrijvingDBNavigator->Visible = true;
}

//---------------------------------------------------------------------------
__fastcall TFaculteitstudent::TFaculteitstudent(TComponent* Owner)
        : TForm(Owner)
{
 // Show();

  sasDataModule->personSQLDataSet->Active = true;
  sasDataModule->InschrijvingSQLDataSet->Close();
  sasDataModule->InschrijvingSQLDataSet->CommandText = "SELECT * FROM inschrijving";
  sasDataModule->InschrijvingSQLDataSet->Open();
  sasDataModule->FaculteitSQLDataSet->Active = true;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  SasBasicTables->SysteemSQLDataSet->Active = true;

  graadSQLDataSet->Close(); // Flush previous query
  graadClientDataSet->Active=false; // Flush previous data in set
  graadSQLDataSet->CommandText= "select graad_id,graad from graad order by graad";
  graadSQLDataSet->Open();
  graadClientDataSet->Active=true;

  sasDataModule->personClientDataSet->Active = true;
  sasDataModule->InschrijvingClientDataSet->Active = false;
  sasDataModule->InschrijvingClientDataSet->Active = true;
  sasDataModule->FaculteitClientDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;
  SasBasicTables->SysteemClientDataSet->Active = true;
  Faculteitstudent->NieuwButton->Enabled = false;
  Faculteitstudent->OpslaanButton->Enabled = false;
  Faculteitstudent->VerwijderButton->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFaculteitstudent::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 // HoofdScherm->Inschrijven1->Checked = false;
  HoofdScherm->Show();
  Free();
}
//---------------------------------------------------------------------------

void __fastcall TFaculteitstudent::Close1Click(TObject *Sender)
{
// HoofdScherm->Inschrijven1->Checked = false;
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TFaculteitstudent::Exit1Click(TObject *Sender)
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
  if(Faculteitstudent->LastRecordsDBGrid->Fields[0]->Text =="")
    maxvolgnr = 0;
  else
    maxvolgnr = Faculteitstudent->LastRecordsDBGrid->Fields[0]->Value;

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
void __fastcall TFaculteitstudent::SearchButtonClick(TObject *Sender)
{
        // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
         sasDataModule->sasSQLConnection->Connected=true;
     }

   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
   if (Faculteitstudent->ToggleButton->Caption == "op idnummer")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
        sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Faculteitstudent->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
        sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(Faculteitstudent->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }

   sasDataModule->personSQLDataSet->Open();
    sasDataModule->personClientDataSet->Active=true;
     //   Application->MessageBox("", (sasDataModule->personClientDataSet->FieldByName("volgnr")->AsString).c_str(), MB_OK);

    sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
    sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR = :IDKAARTNR";
    sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Faculteitstudent->IdCardDBEdit->Text);
    sasDataModule->InschrijvingSQLDataSet->Open();
    sasDataModule->InschrijvingClientDataSet->Active=true;


  if (Faculteitstudent->IdCardDBEdit->Text != "")
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
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("idkaartnr")->Value = LowerCase(Faculteitstudent->IdCardDBEdit->Text); // Append the '%' sign to search for names like the one input in the box
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("DITJAAR")->Value = jaar;
      sasDataModule->EerdereInschrijvingenSQLDataSet->Open();
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFaculteitstudent::ModusKnopClick(TObject *Sender)
{
  /* FModus = (++FModus)%4;
   switch (FModus)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Lezen"; DoRead();break;//lezen
   case 1: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Toevoegen";DoInsert();break;//toevoegen
   case 2: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Wijzigen";DoUpdate();break;//wijzigen
   case 3: ModusKnop->Font->Color = clRed ;ModusKnop->Caption = "Verwijderen";DoDelete();//verwijderen
    };    */
}
//---------------------------------------------------------------------------

void __fastcall TFaculteitstudent::NieuwButtonClick(TObject *Sender)
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
        Faculteitstudent->OpslaanButton->Enabled = true;
        //Faculteitstudent->InschrijfJaarDBEdit->ReadOnly = false;
}
//---------------------------------------------------------------------------

static int GetVolgnummer(char *richting, int jaar)
{
   sasDataModule->MaxNummersSQLDataSet->Close(); // Flush previous query
   sasDataModule->MaxNummersClientDataSet->Active=false; // Flush previous data in set
   sasDataModule->MaxNummersSQLDataSet->CommandText="select * from maxnummers where RICHTING = :RICHTING AND JAAR = :JAAR";
   sasDataModule->MaxNummersSQLDataSet->ParamByName("RICHTING")->Value= richting;
   sasDataModule->MaxNummersSQLDataSet->ParamByName("JAAR")->Value= jaar;
   sasDataModule->MaxNummersSQLDataSet->Open();
   sasDataModule->MaxNummersClientDataSet->Active=true;
//  Application->MessageBox("in getvolgnummer",Faculteitstudent->VolgnummerDBEdit->Text.c_str(), MB_OK);

   if ((Faculteitstudent->VolgnummerDBEdit->Text != "") && (atoi(Faculteitstudent->JaarDBEdit->Text.c_str()) == jaar))
//     { Application->MessageBox("in getvolgnummer",Faculteitstudent->VolgnummerDBEdit->Text.c_str(), MB_OK);

       return atoi(Faculteitstudent->VolgnummerDBEdit->Text.c_str());
   else
     return 999;
}
//---------------------------------------------------------------------------

static void Werkmaxnummersbij(int nummer, int jaar, char *richting)
{
  if ((nummer == 1000)&& (Faculteitstudent->VolgnummerDBEdit->Text == "")) //toevoegen
    {
 //          Application->MessageBox("in werkbij","voor toevoegen", MB_OK);
      sasDataModule->MaxNummersSQLDataSet->Close(); // Flush previous query
      sasDataModule->MaxNummersSQLDataSet->CommandType = ctQuery;
      sasDataModule->MaxNummersSQLDataSet->CommandText="INSERT INTO maxnummers  (RICHTING, JAAR, NUMMER) VALUES (:RICHTING, :JAAR, :NUMMER)";
      sasDataModule->MaxNummersSQLDataSet->ParamByName("RICHTING")->Value= richting;
      sasDataModule->MaxNummersSQLDataSet->ParamByName("JAAR")->Value= jaar;
      sasDataModule->MaxNummersSQLDataSet->ParamByName("NUMMER")->Value= nummer;
 //     Application->MessageBox("in werkbij",sasDataModule->MaxNummersSQLDataSet->CommandText.c_str(), MB_OK);

      sasDataModule->MaxNummersSQLDataSet->ExecSQL();
      sasDataModule->MaxNummersClientDataSet->Active=true;
    }
  else //updaten
    {
 //   Application->MessageBox("in werkbij","voor updaten", MB_OK);

      sasDataModule->MaxNummersSQLDataSet->Close(); // Flush previous query
      sasDataModule->MaxNummersSQLDataSet->CommandType = ctQuery;
      sasDataModule->MaxNummersSQLDataSet->CommandText="UPDATE maxnummers  SET NUMMER = :NUMMER  WHERE RICHTING = :RICHTING  AND JAAR = :JAAR";
      sasDataModule->MaxNummersSQLDataSet->ParamByName("RICHTING")->Value= richting;
      sasDataModule->MaxNummersSQLDataSet->ParamByName("JAAR")->Value= jaar;
      sasDataModule->MaxNummersSQLDataSet->ParamByName("NUMMER")->Value= nummer;
 //          Application->MessageBox("in werkbij",sasDataModule->MaxNummersSQLDataSet->CommandText.c_str(), MB_OK);

      sasDataModule->MaxNummersSQLDataSet->ExecSQL();
      sasDataModule->MaxNummersClientDataSet->Active=true;
    }
//   Application->MessageBox("in werkbij","", MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TFaculteitstudent::OpslaanButtonClick(TObject *Sender)
{
    if ( IdCardDBEdit->Text == "")
      {
        Application->MessageBox("U heeft geen idnummer opgegeven", "", MB_OK + MB_ICONWARNING);
        return;
      }
    else if ((FModus == AFTERENTRY)&& (InschrijfJaarDBEdit->Text == ""))
        {
        Application->MessageBox("U heeft geen inschrijfjaar opgegeven", "", MB_OK + MB_ICONWARNING);
        return;
      }
    String Systeem;
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
    if (FModus == AFTERENTRY)
     {
       jaar = atoi(InschrijfJaarDBEdit->Text.c_str());
       jr = InschrijfJaarDBEdit->Text;
      }
    if ((FModus == ENTRY)||(FModus == AFTERENTRY))
    {
    //We halen eerst het hoogste volgnummer op voor deze studierichting in maxnummers
    //Daarna maken we het studienummer

      nummer = GetVolgnummer(studie.c_str(), jaar);
      nummer++;
      studienr = jr.SubString(3,2) + studie +  String(itoa(nummer, buf, 10));
Application->MessageBox("uit getvolgnummer", studienr.c_str(), MB_OK);

    //Nu moeten we eerst maxnummers updaten en daarna de inschrijving toevoegen
 //     Werkmaxnummersbij(nummer, jaar, studie.c_str());
      try
       {
      sasDataModule->InschrijvingSQLDataSet->Close();
      Faculteitstudent->OpslaanButton->Enabled = false;
      sasDataModule->InschrijvingSQLDataSet->CommandType = ctQuery;
        if (!VarIsNull(Faculteitstudent->SysteemDBLookupListBox->KeyValue))
        {
          sasDataModule->InschrijvingSQLDataSet->CommandText = "INSERT INTO inschrijving (FACULTEIT_ID,\
          STUDIERICHTING_ID, STUDIENR,IDKAARTNR,INSCHRIJFJAAR, MEMO, SYSTEEM_ID)  VALUES (:FACULTEIT_ID,\
          :STUDIERICHTING_ID, :STUDIENR,:IDKAARTNR,:INSCHRIJFJAAR,:MEMO,:SYSTEEM_ID) ";
          sasDataModule->InschrijvingSQLDataSet->Params->Items[0]->AsString = Faculteitstudent->FaculteitComboBox->KeyValue;
          sasDataModule->InschrijvingSQLDataSet->Params->Items[1]->AsString = Faculteitstudent->StudierichtingComboBox->KeyValue;
          sasDataModule->InschrijvingSQLDataSet->Params->Items[2]->AsString = studienr.c_str();
          sasDataModule->InschrijvingSQLDataSet->Params->Items[3]->AsString = Faculteitstudent->IdCardDBEdit->Text;
          sasDataModule->InschrijvingSQLDataSet->Params->Items[4]->AsString = Faculteitstudent->InschrijfJaarDBEdit->Text;
          sasDataModule->InschrijvingSQLDataSet->Params->Items[5]->AsString = Faculteitstudent->StudieDBMemo->Text;
          sasDataModule->InschrijvingSQLDataSet->Params->Items[6]->AsString = Faculteitstudent->SysteemDBLookupListBox->KeyValue;
       }
       else
       {
          sasDataModule->InschrijvingSQLDataSet->CommandText = "INSERT INTO inschrijving (FACULTEIT_ID,\
          STUDIERICHTING_ID, STUDIENR,IDKAARTNR,INSCHRIJFJAAR, MEMO)  VALUES (:FACULTEIT_ID,\
          :STUDIERICHTING_ID, :STUDIENR,:IDKAARTNR,:INSCHRIJFJAAR,:MEMO) ";
          sasDataModule->InschrijvingSQLDataSet->Params->Items[0]->AsString = Faculteitstudent->FaculteitComboBox->KeyValue;
          sasDataModule->InschrijvingSQLDataSet->Params->Items[1]->AsString = Faculteitstudent->StudierichtingComboBox->KeyValue;
          sasDataModule->InschrijvingSQLDataSet->Params->Items[2]->AsString = studienr.c_str();
          sasDataModule->InschrijvingSQLDataSet->Params->Items[3]->AsString = Faculteitstudent->IdCardDBEdit->Text;
          sasDataModule->InschrijvingSQLDataSet->Params->Items[4]->AsString = Faculteitstudent->InschrijfJaarDBEdit->Text;
          sasDataModule->InschrijvingSQLDataSet->Params->Items[5]->AsString = Faculteitstudent->StudieDBMemo->Text;
       }
      sasDataModule->InschrijvingSQLDataSet->ExecSQL();
      }
        catch (Exception &exception)
        {
          // Application->MessageBox(exception.Message.c_str(),"",MB_OK);
           Application->MessageBox("Fout bij het toevoegen. Probeer het opnieuw.", "", MB_OK|MB_ICONSTOP);
           return;
        }

       Werkmaxnummersbij(nummer, jaar, studie.c_str());
    }
   else if (FModus == EDIT)
    {
      sasDataModule->InschrijvingSQLDataSet->Close();
      sasDataModule->InschrijvingSQLDataSet->CommandType = ctQuery;
      if (!VarIsNull(Faculteitstudent->SysteemDBLookupListBox->KeyValue))
        {
          sasDataModule->InschrijvingSQLDataSet->CommandText = "UPDATE INSCHRIJVING SET MEMO=:MEMO,\
          VERLENGING=:VERLENGING, SYSTEEM_ID=:SYSTEEM WHERE STUDIENR =:STUDIENR";
          sasDataModule->InschrijvingSQLDataSet->Params->Items[0]->AsString = Faculteitstudent->StudieDBMemo->Text;
          sasDataModule->InschrijvingSQLDataSet->Params->Items[1]->AsInteger =  atoi((Faculteitstudent->VerlengingDBEdit)->Text.c_str());
          sasDataModule->InschrijvingSQLDataSet->Params->Items[2]->AsString =  Faculteitstudent->SysteemDBLookupListBox->KeyValue;
          sasDataModule->InschrijvingSQLDataSet->Params->Items[3]->AsString =  Faculteitstudent->StudieNRDBEdit->Text;
      }
    else
     {
          sasDataModule->InschrijvingSQLDataSet->CommandText = "UPDATE INSCHRIJVING SET MEMO=:MEMO,\
          VERLENGING=:VERLENGING WHERE STUDIENR =:STUDIENR";
          sasDataModule->InschrijvingSQLDataSet->Params->Items[0]->AsString = Faculteitstudent->StudieDBMemo->Text;
          sasDataModule->InschrijvingSQLDataSet->Params->Items[1]->AsInteger =  atoi((Faculteitstudent->VerlengingDBEdit)->Text.c_str());
          sasDataModule->InschrijvingSQLDataSet->Params->Items[2]->AsString =  Faculteitstudent->StudieNRDBEdit->Text;
     }
      sasDataModule->InschrijvingSQLDataSet->ExecSQL();


    /*  sasDataModule->personSQLDataSet->Close(); // Flush previous query
      sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :Name";
      sasDataModule->personSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
      sasDataModule->personSQLDataSet->Open();
      sasDataModule->personClientDataSet->Active=true; */
    }
//    Faculteitstudent->OpslaanButton->Enabled = false;
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

void __fastcall TFaculteitstudent::VerwijderButtonClick(TObject *Sender)
{
   sasDataModule->InschrijvingSQLDataSet->CommandType = ctQuery;
   sasDataModule->InschrijvingSQLDataSet->CommandText = "DELETE FROM INSCHRIJVING WHERE STUDIENR =   :STUDIENR";
   sasDataModule->InschrijvingSQLDataSet->Params->Items[0]->AsString = Faculteitstudent->StudieNRDBEdit->Text;

   sasDataModule->InschrijvingSQLDataSet->ExecSQL();

   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
   sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :Name";
   sasDataModule->personSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
   sasDataModule->personSQLDataSet->Open();
   sasDataModule->personClientDataSet->Active=true;

   sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
   sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
   sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR = :IDKAARTNR";
   sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Faculteitstudent->SearchEdit->Text); // Append the '%' sign to search for names like the one input in the box
   sasDataModule->InschrijvingSQLDataSet->Open();
   sasDataModule->InschrijvingClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TFaculteitstudent::FaculteitComboBoxClick(TObject *Sender)
{

   if ( IdCardDBEdit->Text == "") return;
   if (Faculteitstudent->FaculteitComboBox->Text != "")
     {
   // Application->MessageBox("","faculteitclick",MB_OK);
        Faculteitstudent->StudierichtingComboBox->Enabled = true;
        sasDataModule->StudierichtingSQLDataSet->Close(); // Flush previous query
        sasDataModule->StudierichtingClientDataSet->Active=false; // Flush previous data in set

        sasDataModule->StudierichtingSQLDataSet->CommandText = "select * from studierichting where faculteit_id = :faculteit_id and RICHTING_ID not like :RICHTING_ID";
        sasDataModule->StudierichtingSQLDataSet->ParamByName("faculteit_id")->Value = Faculteitstudent->FaculteitComboBox->KeyValue;
        sasDataModule->StudierichtingSQLDataSet->ParamByName("RICHTING_ID")->Value = "MP";
        sasDataModule->StudierichtingSQLDataSet->Open();
        sasDataModule->StudierichtingClientDataSet->Active=true;
        Label12->Enabled = true;

        if  (Faculteitstudent->FaculteitComboBox->Text != "IGSR")
            ExtraPanel->Visible = false;
        else
            ExtraPanel->Visible = true;
   // Nu gaan we na of de student eerder was ingeschreven. Alle inschrijvingen worden
   // getoond in een grid.

     }
}
//---------------------------------------------------------------------------

void __fastcall TFaculteitstudent::StudierichtingComboBoxClick(
      TObject *Sender)
{
    String jaar = CurrentYear();
          //Faculteitstudent->InschrijfJaarDBEdit->ReadOnly = true;
        //Faculteitstudent->StudieNRDBEdit->ReadOnly = false;
    studie = Faculteitstudent->StudierichtingComboBox->KeyValue;
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
    if  (FModus != AFTERENTRY) Faculteitstudent->InschrijfJaarDBEdit->Text = jaar;
//  studienr = Faculteitstudent->LastRecordsDBGrid->Fields[2]->Value;
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

 //  Faculteitstudent->StudieNRDBEdit->Text = studienr.c_str();
//  Faculteitstudent->StudieNRDBEdit->Text = parameter;       // Faculteitstudent->StudieNRDBEdit->ReadOnly = true;

}
//---------------------------------------------------------------------------

void __fastcall TFaculteitstudent::IdCardDBEditExit(TObject *Sender)
{
  if (Faculteitstudent->IdCardDBEdit->Modified)
    {
        //Nu moet gezocht worden naar dit record in persoon
        //Als het niet voorkomt dient het veld schoon gemaakt te worden en een
        //boodschap op het scherm getoond te worden
   String idnummer = Faculteitstudent->IdCardDBEdit->Text;
   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
   sasDataModule->personSQLDataSet->CommandText= "select * from persoon where IDKAARTNR = :IDKAARTNR";
   sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value = LowerCase(idnummer); // Append the '%' sign to search for names like the one input in the box
   sasDataModule->personSQLDataSet->Open();
   sasDataModule->personClientDataSet->Active=true;
   if (sasDataModule->personClientDataSet->IsEmpty())
    {
      Faculteitstudent->IdCardDBEdit->Text = "";
      Application->MessageBox("", "Het door u opgegeven idnummer komt niet voor",MB_OK + MB_ICONWARNING);
    }
   }
}
//---------------------------------------------------------------------------

void __fastcall TFaculteitstudent::InschrijvingDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
    //Als geen persoon opgegeven is mag je niet verder
    if ( IdCardDBEdit->Text == "") return;
    //nu moet gegaan worden naar het gekoppelde record in inschrijving
    sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
    sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->InschrijvingSQLDataSet->CommandText="select inschrijving.INSCHRIJFJAAR, inschrijving.* from inschrijving where IDKAARTNR = :IDKAARTNR ORDER BY inschrijving.INSCHRIJFJAAR DESC";
    sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Faculteitstudent->IdCardDBEdit->Text);
    sasDataModule->InschrijvingSQLDataSet->Open();
    sasDataModule->InschrijvingClientDataSet->Active=true;


  if (Faculteitstudent->IdCardDBEdit->Text != "")
    {
      TDateTime datum = Now();
      unsigned short jar, mnd, dag;
      datum.DecodeDate(&jar, &mnd, &dag);
     // String jaar = CurrentYear();
    //  int jr = atoi(jaar.c_str());
      char buf[5];
      if (mnd < 9)
        jar--;
       String jaar = itoa(jar, buf, 10);
//      Application->MessageBox("", "change", MB_OK);
      sasDataModule->EerdereInschrijvingenSQLDataSet->Close(); // Flush previous query
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->EerdereInschrijvingenSQLDataSet->CommandText= "select inschrijving.INSCHRIJFJAAR, inschrijving.* from inschrijving where IDKAARTNR = :IDKAARTNR AND INSCHRIJFJAAR != :DITCOLLEGEJAAR ORDER BY inschrijving.INSCHRIJFJAAR DESC";
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("idkaartnr")->Value = LowerCase(Faculteitstudent->IdCardDBEdit->Text); // Append the '%' sign to search for names like the one input in the box
      sasDataModule->EerdereInschrijvingenSQLDataSet->ParamByName("DITCOLLEGEJAAR")->Value = jaar;
      sasDataModule->EerdereInschrijvingenSQLDataSet->Open();
      sasDataModule->EerdereInschrijvingenClientDataSet->Active=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFaculteitstudent::ToggleButtonClick(TObject *Sender)
{
 if (Faculteitstudent->ToggleButton->Caption == "op idnummer")
      Faculteitstudent->ToggleButton->Caption = "op naam";
  else
      Faculteitstudent->ToggleButton->Caption = "op idnummer";
}
//---------------------------------------------------------------------------

void __fastcall TFaculteitstudent::IdCardDBEditChange(TObject *Sender)
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

void __fastcall TFaculteitstudent::FormActivate(TObject *Sender)
{
   switch (FModus)
    {
   case READ: ModusLabel->Font->Color = clNavy ;ModusLabel->Caption = "Studentgegevens opvragen"; DoRead();break;//lezen
   case ENTRY: ModusLabel->Font->Color = clNavy ;ModusLabel->Caption = "Student inschrijven";DoInsert();break;//toevoegen
   case EDIT: ModusLabel->Font->Color = clNavy ;ModusLabel->Caption = "Studentgegevens wijzigen";DoUpdate();break;//wijzigen
   case DEL: ModusLabel->Font->Color = clRed ;ModusLabel->Caption = "Student verwijderen";DoDelete(); break;//verwijderen
   case AFTERENTRY: ModusLabel->Font->Color = clNavy ;ModusLabel->Caption = "Student nainschrijven";DoInsert();break;//toevoegen
     }
   if (usergroup == "IGSR_ADMINISTRATIE")
    {
      ExtraPanel->Visible = true;
      sasDataModule->InschrijvingClientDataSet->Filter = "FACULTEIT_ID = 4";
      sasDataModule->InschrijvingClientDataSet->Filtered = true;
    }
   else
    {
      ExtraPanel->Visible = false;
      sasDataModule->InschrijvingClientDataSet->Filter = "FACULTEIT_ID <> 4";
      sasDataModule->InschrijvingClientDataSet->Filtered = true;
    }
}
//---------------------------------------------------------------------------






