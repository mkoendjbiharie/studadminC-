//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <dir.h>
//#include <SysUtils.h>
#include "Person.h"
#include "Main.h"
#include "sasdm.h"
#include "sasbasictablesmod.h"
#include "string.h"
//#include "Facstud.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPersonForm *PersonForm;
AnsiString BirthDate;
extern bool student;
int Modus;
static void SetReadModus(bool mode);
extern String usergroup;
static String personquery;
//---------------------------------------------------------------------------
__fastcall TPersonForm::TPersonForm(TComponent* Owner)
        : TForm(Owner)
{
  Modus = 0;
  if(!student)
   {
     personquery = "select persoon.* from persoon join Docentbetrekking on persoon.IDKAARTNR = Docentbetrekking.IDKAARTNR ";
    //  sasDataModule->personSQLDataSet->Active = false;
     sasDataModule->personClientDataSet->Active = false;
     sasDataModule->personClientDataSet->CommandText= personquery; }
  else
   {
 // Application->MessageBoxA("","",MB_OK);

     personquery = "select * from persoon "; //left join Docentbetrekking on persoon.VOLGNR = Docentbetrekking.VOlGNR where Docentbetrekking.VOLGNR IS NULL";
   //  sasDataModule->personSQLDataSet->Active = false;
     sasDataModule->personClientDataSet->Active = false;
     sasDataModule->personClientDataSet->CommandText= personquery; }
 //Application->MessageBoxA("","",MB_OK);

 // sasDataModule->personSQLDataSet->Active = true;
//Application->MessageBoxA("","",MB_OK);

  sasDataModule->personClientDataSet->Active = true;
// Application->MessageBoxA("","",MB_OK);

  SasBasicTables->ethnicSQLDataSet->Active = true;
  SasBasicTables->ethnicClientDataSet->Active = true;
  SasBasicTables->prevEduSQLDataSet->Active = true;
  SasBasicTables->prevEduClientDataSet->Active = true;
// Application->MessageBoxA("","",MB_OK);

  SasBasicTables->eduSQLDataSet->Active = true;
  SasBasicTables->eduClientDataSet->Active = true;
  SasBasicTables->nationalitySQLDataSet->Active = true;
  SasBasicTables->nationalityClientDataSet->Active = true;
  sasDataModule->GridSQLDataSet->Active = true;
  sasDataModule->GridClientDataSet->Active = true;
 //Application->MessageBoxA("","",MB_OK);

  PersonForm->NieuwButton->Enabled = false;
  PersonForm->OpslaanButton->Enabled = false;
  PersonForm->VerwijderButton->Enabled = false;
  PersonForm->BirthDateDBEdit->Field->EditMask = "!0000/00/00;1;_";
// PersonForm->DBEdit1->Field->EditMask = "!00/00/0000;0;_";
//((TDateField *)(sasDataModule->personClientDataSet->FindField("TESTDATUM")))->EditMask ="00/00/0000;0;_";

//((TDateField *)(sasDataModule->personClientDataSet->FindField("GEBOORTEDATUM")))->DisplayFormat = "yyyy/mm/dd";

// Application->MessageBoxA("","",MB_OK);
 // sasDataModule->personClientDataSet-> FormatString = "dd/mm/jjjj";
  SetReadModus(true);
//   Application->MessageBoxA("","",MB_OK);


  last->Text= String(sasDataModule->personClientDataSet->RecordCount);
  first->Text= String(sasDataModule->personClientDataSet->RecNo);

//  Application->MessageBoxA("","",MB_OK);
  if ((usergroup == "DOCENT") ||  (usergroup == "DIRECTEUR_UVS")|| (usergroup == "DIRECTEUR_FAC"))
     ModusKnop->Enabled = false;
  else ModusKnop->Enabled = true;
  //\\\\192.168.222.11\\temp\\uvslogo.bmp");
//  Application->MessageBoxA("","",MB_OK);
 // DBImage1->Picture->LoadFromFile("fotos\\uvslogo1.jpg");
//  Application->MessageBoxA("","",MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TPersonForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   if (student)
        HoofdScherm->Persoonsgegevens1->Checked = false;
   else
        HoofdScherm->Persoonsgegevens3->Checked = false;
   HoofdScherm->Show();
   Free();
}
//---------------------------------------------------------------------------
void __fastcall TPersonForm::Exit1Click(TObject *Sender)
{
        PersonForm->Close();
        HoofdScherm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TPersonForm::SearchButtonClick(TObject *Sender)
{
   // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
        sasDataModule->sasSQLConnection->Connected=true;
     }

 //  sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
   if (PersonForm->ToggleButton->Caption == "op idnummer")
     {
     sasDataModule->personClientDataSet->Filter =   String("IDKAARTNR like ") + String("'") + PersonForm->SearchEdit->Text + String("%'");
  //      sasDataModule->personSQLDataSet->CommandText= personquery + " AND persoon.IDKAARTNR like :IDKAARTNR";
  //      sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(PersonForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else
     {
       sasDataModule->personClientDataSet->Filter = String("NAAM like ") + String("'") + PersonForm->SearchEdit->Text + String("%'");

       // sasDataModule->personSQLDataSet->CommandText=personquery + " AND NAAM like :NAAM";
     //   sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(PersonForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
 //  sasDataModule->personSQLDataSet->Open();
   sasDataModule->personClientDataSet->Active=true;
   PersonForm->BirthDateDBEdit->Field->EditMask="!0000/00/00;1;_";
        //PersonForm->TelephoneDBEdit->Field->EditMask="!00000000;1;_";
        //PersonForm->CellNrDBEdit->Field->EditMask="!00000000;1;_";
  last->Text= String(sasDataModule->personClientDataSet->RecordCount);
  first->Text= String(sasDataModule->personClientDataSet->RecNo);
}
//---------------------------------------------------------------------------


void __fastcall TPersonForm::FormActivate(TObject *Sender)
{

 // sasDataModule->personSQLDataSet->Close();
   //sasDataModule->personClientDataSet->Active=true;
  if(!student)
     personquery = "select persoon.* from persoon join Docentbetrekking on persoon.IDKAARTNR = Docentbetrekking.IDKAARTNR ";
     // sasDataModule->personSQLDataSet->Active = false;
     // sasDataModule->personClientDataSet->Active = false;
    //  sasDataModule->personSQLDataSet->CommandText= personquery; }
  else
//Application->MessageBoxA("1","",MB_OK);
     personquery = "select * from persoon"; // left join Docentbetrekking on persoon.VOLGNR = Docentbetrekking.VOlGNR where Docentbetrekking.VOLGNR IS NULL";
     //sasDataModule->personSQLDataSet->Active = false;
     //sasDataModule->personClientDataSet->Active = false;
     //sasDataModule->personSQLDataSet->CommandText= personquery; }
// Application->MessageBoxA("11","",MB_OK);
    sasDataModule->personClientDataSet->Close();
    sasDataModule->personClientDataSet->CommandText= personquery;
    sasDataModule->personClientDataSet->Open();
//  Application->MessageBoxA("1","",MB_OK);
  //sasDataModule->personSQLDataSet->Active = true;
 // sasDataModule->personClientDataSet->Active = true;
  sasDataModule->GridSQLDataSet->Close(); // Flush previous query

  sasDataModule->GridClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->GridSQLDataSet->CommandText = "SELECT MAX(VOLGNR) AS VOLGNR FROM PERSOON";

  sasDataModule->GridSQLDataSet->Open();
  sasDataModule->GridClientDataSet->Active=true;
// Application->MessageBoxA("2","",MB_OK);
  int maxvolgnr;
  if(PersonForm->LastRecordsDBGrid->Fields[0]->Text ==""){
    maxvolgnr = 0;
  }
  else{
    maxvolgnr = PersonForm->LastRecordsDBGrid->Fields[0]->Value;
 // char buf[7];
}
//Application->MessageBoxA("3","",MB_OK);
  sasDataModule->GridSQLDataSet->Close();
  sasDataModule->GridClientDataSet->Active=false;
  sasDataModule->GridSQLDataSet->CommandText = "SELECT * FROM persoon WHERE VOLGNR > :volgnr ORDER BY VOLGNR DESC";
  sasDataModule->GridSQLDataSet->ParamByName("volgnr")->AsString = maxvolgnr - 50;
 //Application->MessageBoxA("4","",MB_OK);
  sasDataModule->GridSQLDataSet->Open();
  sasDataModule->GridClientDataSet->Active=true;
// Application->MessageBoxA("6","",MB_OK);
  last->Text= String(sasDataModule->personClientDataSet->RecordCount);
  first->Text= String(sasDataModule->personClientDataSet->RecNo);


}

//---------------------------------------------------------------------------
void __fastcall TPersonForm::Close1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{

                PersonForm->IdCardDBEdit->ReadOnly=mode;
                PersonForm->NameDBEdit->ReadOnly=mode;
                PersonForm->MarriedNameDBEdit->ReadOnly=mode;
                PersonForm->FirstNameDBEdit->ReadOnly=mode;
                PersonForm->InitialsDBEdit->ReadOnly=mode;
                PersonForm->BirthDateDBEdit->ReadOnly=mode;
                PersonForm->NationalityDBLookupComboBox->ReadOnly=mode;
                PersonForm->BirthPlaceDBEdit->ReadOnly=mode;
                PersonForm->EthnicDBLookupComboBox->ReadOnly=mode;
                PersonForm->ReligionDBEdit->ReadOnly=mode;
                PersonForm->PrevEducationDBLookupComboBox->ReadOnly=mode;
                PersonForm->SexDBRadioGroup->ReadOnly=mode;
                PersonForm->MarritalStatusDBRadioGroup->ReadOnly=mode;
                PersonForm->StreetDBEdit->ReadOnly=mode;
                PersonForm->NumberDBEdit->ReadOnly=mode;
                PersonForm->AreaDBEdit->ReadOnly=mode;
                PersonForm->DistrictDBEdit->ReadOnly=mode;
                PersonForm->CountryDBEdit->ReadOnly=mode;
                PersonForm->TelephoneDBEdit->ReadOnly=mode;
                PersonForm->CellNrDBEdit->ReadOnly=mode;
                PersonForm->Email1DBEdit->ReadOnly=mode;
                PersonForm->Email2DBEdit->ReadOnly=mode;
                PersonForm->BankAccountDBEdit->ReadOnly=mode;
                PersonForm->CommentDBMemo->ReadOnly=mode;
                PersonForm->HobbiesDBMemo->ReadOnly=mode;
                PersonForm->ExtentieDBEdit->ReadOnly=mode;
                PersonForm->ContactTelefoonDBEdit->ReadOnly=mode;
                PersonForm->WerkTelefoonDBEdit->ReadOnly=mode;
}
//--------------------------------------------------------------------------

static void DoRead()
{
    PersonForm->DBNavigator1->Enabled = true;
    PersonForm->NieuwButton->Enabled = false;
    PersonForm->OpslaanButton->Enabled = false;
    PersonForm->VerwijderButton->Enabled = false;
    PersonForm->SearchEdit->Show();
    PersonForm->SearchButton->Show();
    PersonForm->ToggleButton->Show();
    PersonForm->LastRecordsDBGrid->Show();
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    PersonForm->DBNavigator1->Enabled = true;
    PersonForm->NieuwButton->Enabled = false;
    PersonForm->OpslaanButton->Enabled = false;
    PersonForm->VerwijderButton->Enabled = true;
    PersonForm->SearchEdit->Show();
    PersonForm->SearchButton->Show();
    PersonForm->ToggleButton->Show();
    PersonForm->LastRecordsDBGrid->Show();
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
    PersonForm->DBNavigator1->Enabled = true;
    PersonForm->NieuwButton->Enabled = false;
    PersonForm->OpslaanButton->Enabled = true;
    PersonForm->VerwijderButton->Enabled = false;
    PersonForm->SearchEdit->Show();
    PersonForm->SearchButton->Show();
    PersonForm->ToggleButton->Show();
    PersonForm->LastRecordsDBGrid->Show();
    SetReadModus(false);
//    PersonForm->IdCardDBEdit->ReadOnly = true;
    PersonForm->MarriedNameDBEdit->Enabled = false;
}
//----------------------------------------------------------------------------

static void  DoInsert()
{
    PersonForm->DBNavigator1->Enabled = false;
    PersonForm->SexDBRadioGroup->ItemIndex = 1;
    PersonForm->MarritalStatusDBRadioGroup->ItemIndex = 0;
    PersonForm->NieuwButton->Enabled = true;
    PersonForm->OpslaanButton->Enabled = false;
    PersonForm->VerwijderButton->Enabled = false;
    PersonForm->SearchEdit->Hide();
    PersonForm->ToggleButton->Hide();
    PersonForm->SearchButton->Hide();
    SetReadModus(false);
    PersonForm->MarriedNameDBEdit->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TPersonForm::ModusKnopClick(TObject *Sender)
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

void __fastcall TPersonForm::NieuwButtonClick(TObject *Sender)
{
   if (sasDataModule->sasSQLConnection->Connected!=true)
        {
                sasDataModule->sasSQLConnection->Connected=true;
        }
//  Application->MessageBoxA("1","",MB_OK);
 //       sasDataModule->personSQLDataSet->Close(); // Flush previous query
 //    Application->MessageBoxA("11","",MB_OK);
        sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
 //   Application->MessageBoxA("12","",MB_OK);
        sasDataModule->personClientDataSet->CommandText= personquery + " WHERE NAAM like " + "123456";
 //    Application->MessageBoxA("13","",MB_OK);
//        sasDataModule->personClientDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
//      Application->MessageBoxA("14","",MB_OK);
//       Application->MessageBoxA("15","",MB_OK);

 //        Application->MessageBoxA("16","",MB_OK);
  //     sasDataModule->personClientDataSet->Active=true;
         sasDataModule->personClientDataSet->Active = true;
//         Application->MessageBoxA("2","",MB_OK);
       // PersonForm->SexDBRadioGroup->ItemIndex = 1;
      //  PersonForm->MarritalStatusDBRadioGroup->ItemIndex = 0;
        PersonForm->BirthDateDBEdit->Field->EditMask="!0000/00/00;1;_";
        //PersonForm->TelephoneDBEdit->Field->EditMask="!00000000;1;_";
        //PersonForm->CellNrDBEdit->Field->EditMask="!00000000;1;_";
        PersonForm->OpslaanButton->Enabled = true;
 //        Application->MessageBoxA("3","",MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TPersonForm::OpslaanButtonClick(TObject *Sender)
{
  Variant leeg = NULL;
  char buf[5];
  String foto;
  if (Modus == 1)
    {
   //   DBImage1->Picture->LoadFromFile("fotos\\uvslogo1.jpg");
      if ((PersonForm->SexDBRadioGroup->ItemIndex < 0)||(PersonForm->MarritalStatusDBRadioGroup->ItemIndex < 0))
      {
         Application->MessageBox("U heeft het geslacht en/of de burgerlijke staat niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
       if (PersonForm->NameDBEdit->Text == "")
      {
         Application->MessageBox("U heeft de naam niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
       if (PersonForm->FirstNameDBEdit->Text == "")
      {
         Application->MessageBox("U heeft de voornaam niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
      if (PersonForm->IdCardDBEdit->Text == "")
      {
         Application->MessageBox("U heeft het idnummer niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
      if (PersonForm->BirthDateDBEdit->Text == "")
      {
         Application->MessageBox("U heeft de geboortedatum niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
      //Nu gaan we eerst na of de persoon al voorkomt. Zelfde naam, voornaam, geboortedatum. Er volgt een message
      //We ondervragen de database en als de resultset niet leeg is komt de persoon al voor.
    //   sasDataModule->personSQLDataSet->Fields->FieldByName(Foto)->
  //       Application->MessageBoxA("4","",MB_OK);
       sasDataModule->personSQLDataSet->Close();
 //         Application->MessageBoxA("44","",MB_OK);
      sasDataModule->personSQLDataSet->CommandType = ctQuery;
      String querystring;
//      querystring  = String("SELECT * FROM PERSOON PERSOON  WHERE NAAM = ") + "'" + NameDBEdit->Text + "'" + " AND VOORNAAM = " + "'" + FirstNameDBEdit->Text + "'" + " AND GEBOORTEDATUM = " + "'" + BirthDateDBEdit->Text + "'" + " AND IDKAARTNR = " + "'" + IdCardDBEdit->Text + "'";
       querystring  = String("SELECT * FROM PERSOON PERSOON  WHERE IDKAARTNR = ") + "'" + IdCardDBEdit->Text + "'";

      sasDataModule->personSQLDataSet->CommandText =  querystring;
//         Application->MessageBoxA("5","",MB_OK);

//         Application->MessageBoxA("6","",MB_OK);
               // sasDataModule->personSQLDataSet->ExecSQL();
//                   Application->MessageBoxA("7","",MB_OK);
        if (sasDataModule->personSQLDataSet->RecordCount > 0 )
          {Application->MessageBox("Error", "Het nummer van de idkaart komt al voor" ,MB_OK);  return;}
      sasDataModule->personSQLDataSet->CommandText = "INSERT INTO PERSOON (IDKAARTNR,NATIO_ID,BEV_ID,GESLACHT,NAAM,GEHUWDENAAM, VOORNAAM,VOORNAAM2,BURGERLIJKE_STAAT,OPMERKING,GEBOORTELAND,GEBOORTEPLAATS,BANK,DISTRICT,GELOOF,STRAAT,HUISNUMMER,EMAIL1,EMAIL2,GEBOORTEDATUM,BANKREKENINGNR,TELEFOON2,TELEFOON1,WOONPLAATS,WIJK, OPLEIDING_ID,HOBBIES, FOTO)"
                                                                  "VALUES(:IDKAARTNR,:NATIO_ID,:BEV_ID,:GESLACHT,:NAAM,:GEHUWDENAAM,:VOORNAAM,:VOORNAAM2,:BURGERLIJKE_STAAT,:OPMERKING,:GEBOORTELAND,:GEBOORTEPLAATS,:BANK,:DISTRICT,:GELOOF,:STRAAT,:HUISNUMMER,:EMAIL1,:EMAIL2,:GEBOORTEDATUM,:BANKREKENINGNR,:TELEFOON2,:TELEFOON1,:WOONPLAATS,:WIJK,:OPLEIDING_ID,:HOBBIES,:FOTO)";
      sasDataModule->personSQLDataSet->Params->Items[0]->AsString = PersonForm->IdCardDBEdit->Text;
      if (!(PersonForm->NationalityDBLookupComboBox->Text == ""))
        {
 //         Application->MessageBox("",itoa(PersonForm->NationalityDBLookupComboBox->ListFieldIndex, buf, 10) ,MB_OK);

       // Application->MessageBox("",itoa(PersonForm->NationalityDBLookupComboBox->ListFieldIndex, buf, 10) ,MB_OK);
        sasDataModule->personSQLDataSet->Params->Items[1]->AsString = PersonForm->NationalityDBLookupComboBox->KeyValue;
        }
      else
        sasDataModule->personSQLDataSet->Params->Items[1]->AsString = leeg;
      if (!(PersonForm->EthnicDBLookupComboBox->Text == ""))
        sasDataModule->personSQLDataSet->Params->Items[2]->AsString = PersonForm->EthnicDBLookupComboBox->KeyValue;
      else
        sasDataModule->personSQLDataSet->Params->Items[2]->AsString = leeg;
      sasDataModule->personSQLDataSet->Params->Items[3]->AsString = PersonForm->SexDBRadioGroup->Value;
      sasDataModule->personSQLDataSet->Params->Items[4]->AsString = PersonForm->NameDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[5]->AsString = PersonForm->MarriedNameDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[6]->AsString = PersonForm->FirstNameDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[7]->AsString = PersonForm->InitialsDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[8]->AsString = PersonForm->MarritalStatusDBRadioGroup->Value;
      sasDataModule->personSQLDataSet->Params->Items[9]->AsString = PersonForm->CommentDBMemo->Text;
      sasDataModule->personSQLDataSet->Params->Items[10]->AsString = PersonForm->CountryDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[11]->AsString = PersonForm->BirthPlaceDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[12]->AsString = PersonForm->BankDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[13]->AsString = PersonForm->DistrictDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[14]->AsString = PersonForm->ReligionDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[15]->AsString = PersonForm->StreetDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[16]->AsString = PersonForm->NumberDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[17]->AsString = PersonForm->Email1DBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[18]->AsString = PersonForm->Email2DBEdit->Text;

      if (!(PersonForm->BirthDateDBEdit->Text == ""))
        sasDataModule->personSQLDataSet->Params->Items[19]->AsDate = PersonForm->BirthDateDBEdit->Text;
      else
        sasDataModule->personSQLDataSet->Params->Items[19]->AsDate = leeg;

//      sasDataModule->personSQLDataSet->Params->Items[19]->AsDate = PersonForm->BirthDateDBEdit->EditText;
      sasDataModule->personSQLDataSet->Params->Items[20]->AsString = PersonForm->BankAccountDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[21]->AsString = PersonForm->TelephoneDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[22]->AsString = PersonForm->CellNrDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[23]->AsString = PersonForm->WoonplaatsDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[24]->AsString = PersonForm->AreaDBEdit->Text;
      if (!(PersonForm->PrevEducationDBLookupComboBox->Text == ""))
         sasDataModule->personSQLDataSet->Params->Items[25]->AsString = PersonForm->PrevEducationDBLookupComboBox->KeyValue;
      else
         sasDataModule->personSQLDataSet->Params->Items[25]->AsString = leeg;
      sasDataModule->personSQLDataSet->Params->Items[26]->AsString = PersonForm->HobbiesDBMemo->Text;
   sasDataModule->personSQLDataSet->Close();
//  Application->MessageBoxA("8","",MB_OK);
    foto =   String("fotos\\") + IdCardDBEdit->Text + String(".bmp");
    if (FileExists(foto))
        sasDataModule->personSQLDataSet->Params->Items[27]->LoadFromFile(foto.c_str(), ftBlob); // AsBlob =  PersonForm->DBImage1->DataField;
    else
        sasDataModule->personSQLDataSet->Params->Items[27]->LoadFromFile("fotos\\uvslogo1.bmp", ftBlob); // AsBlob =  PersonForm->DBImage1->DataField;

        //         Application->MessageBoxA("9","",MB_OK);

          sasDataModule->personClientDataSet->Close();
          sasDataModule->personSQLDataSet->Close();
  try
   {
      sasDataModule->personSQLDataSet->ExecSQL();
   }
  catch (Exception &exception)
        {
            Application->ShowException(&exception);
        }
//      Application->MessageBoxA("8","",MB_OK);
   PersonForm->NieuwButton->Enabled = true;
   PersonForm->OpslaanButton->Enabled = false;
    }
   else if (Modus == 2)
    {
      sasDataModule->personSQLDataSet->CommandType = ctQuery;
      sasDataModule->personSQLDataSet->CommandText = "UPDATE PERSOON SET NATIO_ID=:NATIO_ID,BEV_ID=:BEV_ID,GESLACHT=:GESLACHT,NAAM=:NAAM,GEHUWDENAAM=:GEHUWDENAAM, VOORNAAM=:VOORNAAM,VOORNAAM2=:VOORNAAM2,BURGERLIJKE_STAAT=:BURGERLIJKE_STAAT,OPMERKING=:OPMERKING,GEBOORTELAND=:GEBOORTELAND,GEBOORTEPLAATS=:GEBOORTEPLAATS,BANK=:BANK,DISTRICT=:DISTRICT,GELOOF=:GELOOF,STRAAT=:STRAAT,HUISNUMMER=:HUISNUMMER,EMAIL1=:EMAIL1,EMAIL2=:EMAIL2,GEBOORTEDATUM=:GEBOORTEDATUM,BANKREKENINGNR=:BANKREKENINGNR,TELEFOON2=:TELEFOON2,TELEFOON1=:TELEFOON1,WOONPLAATS=:WOONPLAATS,WIJK=:WIJK, OPLEIDING_ID=:OPLEIDING_ID,HOBBIES=:HOBBIES,IDKAARTNR=:IDKAARTNR, FOTO=:FOTO WHERE VOLGNR =:VOLGNR;";
      sasDataModule->personSQLDataSet->Params->Items[0]->AsString = PersonForm->NationalityDBLookupComboBox->KeyValue;
      sasDataModule->personSQLDataSet->Params->Items[1]->AsString = PersonForm->EthnicDBLookupComboBox->KeyValue;
      sasDataModule->personSQLDataSet->Params->Items[2]->AsString = PersonForm->SexDBRadioGroup->Value;
      sasDataModule->personSQLDataSet->Params->Items[3]->AsString = PersonForm->NameDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[4]->AsString = PersonForm->MarriedNameDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[5]->AsString = PersonForm->FirstNameDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[6]->AsString = PersonForm->InitialsDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[7]->AsString = PersonForm->MarritalStatusDBRadioGroup->Value;
      sasDataModule->personSQLDataSet->Params->Items[8]->AsString = PersonForm->CommentDBMemo->Text;
      sasDataModule->personSQLDataSet->Params->Items[9]->AsString = PersonForm->CountryDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[10]->AsString = PersonForm->BirthPlaceDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[11]->AsString = PersonForm->BankDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[12]->AsString = PersonForm->DistrictDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[13]->AsString = PersonForm->ReligionDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[14]->AsString = PersonForm->StreetDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[15]->AsString = PersonForm->NumberDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[16]->AsString = PersonForm->Email1DBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[17]->AsString = PersonForm->Email2DBEdit->Text;

      if (!(PersonForm->BirthDateDBEdit->Text == ""))
        sasDataModule->personSQLDataSet->Params->Items[18]->AsDate = PersonForm->BirthDateDBEdit->EditText;
      else
        sasDataModule->personSQLDataSet->Params->Items[18]->AsDate = leeg;

      sasDataModule->personSQLDataSet->Params->Items[19]->AsString = PersonForm->BankAccountDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[20]->AsString = PersonForm->TelephoneDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[21]->AsString = PersonForm->CellNrDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[22]->AsString = PersonForm->WoonplaatsDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[23]->AsString = PersonForm->AreaDBEdit->Text;
      sasDataModule->personSQLDataSet->Params->Items[24]->AsString = PersonForm->PrevEducationDBLookupComboBox->KeyValue;
      sasDataModule->personSQLDataSet->Params->Items[25]->AsString = PersonForm->HobbiesDBMemo->Text;
      sasDataModule->personSQLDataSet->Params->Items[26]->AsString = PersonForm->IdCardDBEdit->Text;
      if (FileExists(foto))
        sasDataModule->personSQLDataSet->Params->Items[27]->LoadFromFile(foto.c_str(), ftBlob); // AsBlob =  PersonForm->DBImage1->DataField;
      else
        sasDataModule->personSQLDataSet->Params->Items[27]->LoadFromFile("fotos\\uvslogo1.bmp", ftBlob); // AsBlob =  PersonForm->DBImage1->DataField;

      sasDataModule->personSQLDataSet->Params->Items[28]->AsString = String(sasDataModule->personClientDataSet->FieldValues["VOLGNR"]);



     sasDataModule->personSQLDataSet->ExecSQL();

     }
      sasDataModule->personSQLDataSet->Close(); // Flush previous query
      sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :Name";
      sasDataModule->personSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
      sasDataModule->personSQLDataSet->Open();
      sasDataModule->personClientDataSet->Active=true;

      sasDataModule->GridSQLDataSet->Close();
      sasDataModule->GridClientDataSet->Active=false; // Flush previous data in set
      sasDataModule->GridSQLDataSet->CommandText = "SELECT MAX(VOLGNR) AS VOLGNR FROM PERSOON";


  sasDataModule->GridSQLDataSet->Open();
  sasDataModule->GridClientDataSet->Active=true;
  int maxvolgnr = LastRecordsDBGrid->Fields[0]->Value;
 // char buf[7];
 // Application->MessageBox("", itoa(maxvolgnr, buf, 10), MB_OK);
  sasDataModule->GridSQLDataSet->Close();
  sasDataModule->GridClientDataSet->Active=false;
  sasDataModule->GridSQLDataSet->CommandText = "SELECT * FROM persoon where volgnr > :volgnr  ORDER BY VOLGNR DESC";
  sasDataModule->GridSQLDataSet->ParamByName("volgnr")->AsString = maxvolgnr - 50;

  sasDataModule->GridSQLDataSet->Open();
  sasDataModule->GridClientDataSet->Active=true;
}
//---------------------------------------------------------------------------


void __fastcall TPersonForm::VerwijderButtonClick(TObject *Sender)
{
  sasDataModule->personSQLDataSet->CommandType = ctQuery;
  sasDataModule->personSQLDataSet->CommandText = "DELETE FROM PERSOON WHERE IDKAARTNR =   :IDKAARTNR ";
  sasDataModule->personSQLDataSet->Params->Items[0]->AsString = PersonForm->IdCardDBEdit->Text;
  sasDataModule->personSQLDataSet->ExecSQL();

  sasDataModule->personSQLDataSet->Close(); // Flush previous query
  sasDataModule->personClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :Name";
  sasDataModule->personSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
  sasDataModule->personSQLDataSet->Open();
  sasDataModule->personClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TPersonForm::SexDBRadioGroupChange(TObject *Sender)
{
  if ((PersonForm->SexDBRadioGroup->Value == "v")&& (PersonForm->MarritalStatusDBRadioGroup->Value == "gehuwd"))
     PersonForm->MarriedNameDBEdit->Enabled = true;
  else
     PersonForm->MarriedNameDBEdit->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TPersonForm::MarritalStatusDBRadioGroupChange(
      TObject *Sender)
{
  if ((PersonForm->SexDBRadioGroup->Value == "v")&& (PersonForm->MarritalStatusDBRadioGroup->Value == "gehuwd"))
     PersonForm->MarriedNameDBEdit->Enabled = true;
  else
     PersonForm->MarriedNameDBEdit->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TPersonForm::GridPanelButtonClick(TObject *Sender)
{
  if (GridPanel->Visible == true)
     {
       GridPanel->Visible = false;
       GridPanelButton->Caption = "Toon laatst ingevoerde records";
     }
  else
     {
       GridPanel->Visible = true;
       GridPanelButton->Caption = "Verberg laatst ingevoerde records";
     }
}
//---------------------------------------------------------------------------


void __fastcall TPersonForm::ToggleButtonClick(TObject *Sender)
{
  if (PersonForm->ToggleButton->Caption == "op idnummer")
      PersonForm->ToggleButton->Caption = "op naam";
  else
      PersonForm->ToggleButton->Caption = "op idnummer";
}
//---------------------------------------------------------------------------


void __fastcall TPersonForm::BirthDateDBEditChange(TObject *Sender)
{
//  Variant leeg = NULL;
//  char buf[10];
//  Application->MessageBox(PersonForm->BirthDateDBEdit->EditText.c_str(), itoa(strlen(PersonForm->BirthDateDBEdit->EditText.c_str()), buf, 10),MB_OK);
/* if (PersonForm->BirthDateDBEdit->EditText == "__-__-____")
  {
       PersonForm->BirthDateDBEdit->Field->EditMask="";
 //      PersonForm->BirthDateDBEdit->Field->EditMask="!00/00/0000;1;_";
  } */
  //PersonForm->BirthDateDBEdit->EditText = "";//PersonForm->BirthDateDBEdit->Clear();
  // Application->MessageBox(PersonForm->BirthDateDBEdit->Text.c_str(),"Gelukt",MB_OK);}
}
//---------------------------------------------------------------------------


void __fastcall TPersonForm::BirthDateDBEditEnter(TObject *Sender)
{
 //if (!(PersonForm->BirthDateDBEdit->IsMasked))
 //   PersonForm->BirthDateDBEdit->Field->EditMask="!00/00/0000;1;_";
}
//---------------------------------------------------------------------------

void __fastcall TPersonForm::DBNavigator1Click(TObject *Sender,
      TNavigateBtn Button)
{
  last->Text= String(sasDataModule->personClientDataSet->RecordCount);
  first->Text= String(sasDataModule->personClientDataSet->RecNo);

}
//---------------------------------------------------------------------------



void __fastcall TPersonForm::IdCardDBEditChange(TObject *Sender)
{
//String foto = "fotos\\uvslgo1.bmp" ;
 // foto += "uvs.bmp";
//  Image1->Picture->LoadFromFile("\\\\192.168.214.29\\temp\\uvs.bmp");
//  if (!FileExists(foto))
//Image1->Picture->LoadFromFile("uvslogo1.bmp");
}
//---------------------------------------------------------------------------





