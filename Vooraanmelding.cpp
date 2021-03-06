//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Vooraanmelding.h"
#include "Main.h"
#include "sasdm.h"
#include "sasbasictablesmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TVooraanmeldingForm *VooraanmeldingForm;
static int Modus;
void SetReadModus(bool mode);
//---------------------------------------------------------------------------
__fastcall TVooraanmeldingForm::TVooraanmeldingForm(TComponent* Owner)
        : TForm(Owner)
{
  Modus = 0;
  vpersonSQLDataSet->Active = true;
  vpersonClientDataSet->Active = true;
  VooraanmeldingForm->vinschrijvingSQLDataSet->Active = true;
  VooraanmeldingForm->vinschrijvingClientDataSet->Active = true;

  sasDataModule->FaculteitSQLDataSet->Active = true;
  sasDataModule->FaculteitClientDataSet->Active = true;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;

  SasBasicTables->ethnicSQLDataSet->Active = true;
  SasBasicTables->ethnicClientDataSet->Active = true;
  SasBasicTables->prevEduSQLDataSet->Active = true;
  SasBasicTables->prevEduClientDataSet->Active = true;
  SasBasicTables->eduSQLDataSet->Active = true;
  SasBasicTables->eduClientDataSet->Active = true;
  SasBasicTables->nationalitySQLDataSet->Active = true;
  SasBasicTables->nationalityClientDataSet->Active = true;
  sasDataModule->GridSQLDataSet->Active = true;
  sasDataModule->GridClientDataSet->Active = true;

  VooraanmeldingForm->NieuwButton->Enabled = false;
  VooraanmeldingForm->OpslaanButton->Enabled = false;
  VooraanmeldingForm->VerwijderButton->Enabled = false;
  VooraanmeldingForm->BirthDateDBEdit->Field->EditMask = "!0000/00/00;1;_";
// VooraanmeldingForm->DBEdit1->Field->EditMask = "!00/00/0000;0;_";
//((TDateField *)(vpersonClientDataSet->FindField("TESTDATUM")))->EditMask ="00/00/0000;0;_";

//((TDateField *)(vpersonClientDataSet->FindField("GEBOORTEDATUM")))->DisplayFormat = "yyyy/mm/dd";


 // vpersonClientDataSet-> FormatString = "dd/mm/jjjj";
  SetReadModus(true);
  last->Text= String(vpersonClientDataSet->RecordCount);
  first->Text= String(vpersonClientDataSet->RecNo);
}
//---------------------------------------------------------------------------
void __fastcall TVooraanmeldingForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
     HoofdScherm->Vooraanmelding1->Checked = false;
     HoofdScherm->Show();
     Free();
}

//---------------------------------------------------------------------------
void __fastcall TVooraanmeldingForm::Close1Click(TObject *Sender)
{
        HoofdScherm->Vooraanmelding1->Checked = false;
        HoofdScherm->Show();
        Free();
}

//---------------------------------------------------------------------------
void __fastcall TVooraanmeldingForm::Exit1Click(TObject *Sender)
{
        VooraanmeldingForm->Close();
        HoofdScherm->Close();
}

//---------------------------------------------------------------------------
void __fastcall TVooraanmeldingForm::SearchButtonClick(TObject *Sender)
{
   // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
        sasDataModule->sasSQLConnection->Connected=true;
     }

   vpersonSQLDataSet->Close(); // Flush previous query
   vpersonClientDataSet->Active=false; // Flush previous data in set
   if (VooraanmeldingForm->ToggleButton->Caption == "op idnummer")
     {
        vpersonSQLDataSet->CommandText="select * from vpersoon where IDKAARTNR like :IDKAARTNR";
        vpersonSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(VooraanmeldingForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else if (VooraanmeldingForm->ToggleButton->Caption == "op aanmeldnr")
     {
        vpersonSQLDataSet->CommandText="select * from vpersoon where AANMELDNR like :AANMELDNR";
        vpersonSQLDataSet->ParamByName("aanmeldnr")->Value=LowerCase(VooraanmeldingForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
        else
          {
            vpersonSQLDataSet->CommandText="select * from vpersoon where NAAM like :NAAM";
            vpersonSQLDataSet->ParamByName("naam")->Value=LowerCase(VooraanmeldingForm->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
          }
   vpersonSQLDataSet->Open();
   vpersonClientDataSet->Active=true;
   VooraanmeldingForm->BirthDateDBEdit->Field->EditMask="!0000/00/00;1;_";
   last->Text= String(vpersonClientDataSet->RecordCount);
   first->Text= String(vpersonClientDataSet->RecNo);
   vinschrijvingSQLDataSet->Close(); // Flush previous query
   vinschrijvingClientDataSet->Active=false; // Flush previous data in set
   vinschrijvingSQLDataSet->CommandText = "SELECT * FROM vinschrijving WHERE IDKAARTNR =   :IDKAARTNR ";
   vinschrijvingSQLDataSet->Params->Items[0]->AsString = VooraanmeldingForm->IdCardDBEdit->Text;
   vinschrijvingSQLDataSet->Open(); // Flush previous query
   vinschrijvingClientDataSet->Active=true; // Flush previous data in set

}

//---------------------------------------------------------------------------
void __fastcall TVooraanmeldingForm::FormActivate(TObject *Sender)
{
  sasDataModule->GridSQLDataSet->Close(); // Flush previous query

  sasDataModule->GridClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->GridSQLDataSet->CommandText = "SELECT MAX(VOLGNR) AS VOLGNR FROM VPERSOON";

  sasDataModule->GridSQLDataSet->Open();
  sasDataModule->GridClientDataSet->Active=true;

  int maxvolgnr;
  if(VooraanmeldingForm->LastRecordsDBGrid->Fields[0]->Text ==""){
    maxvolgnr = 0;}
  else{
    maxvolgnr = VooraanmeldingForm->LastRecordsDBGrid->Fields[0]->Value;}
  sasDataModule->GridSQLDataSet->Close();
  sasDataModule->GridClientDataSet->Active=false;
  sasDataModule->GridSQLDataSet->CommandText = "SELECT * FROM vpersoon WHERE VOLGNR > :volgnr ORDER BY VOLGNR DESC";
  sasDataModule->GridSQLDataSet->ParamByName("volgnr")->AsString = maxvolgnr - 50;

  sasDataModule->GridSQLDataSet->Open();
  sasDataModule->GridClientDataSet->Active=true;

  last->Text= String(vpersonClientDataSet->RecordCount);
  first->Text= String(vpersonClientDataSet->RecNo);
  vinschrijvingSQLDataSet->Close(); // Flush previous query
  vinschrijvingClientDataSet->Active=false; // Flush previous data in set
  vinschrijvingSQLDataSet->CommandText = "SELECT * FROM vinschrijving WHERE IDKAARTNR =   :IDKAARTNR ";
  vinschrijvingSQLDataSet->Params->Items[0]->AsString = VooraanmeldingForm->IdCardDBEdit->Text;
  vinschrijvingSQLDataSet->Open(); // Flush previous query
  vinschrijvingClientDataSet->Active=true; // Flush previous data in set


}
//---------------------------------------------------------------------------

void SetReadModus(bool mode)
{

                VooraanmeldingForm->IdCardDBEdit->ReadOnly=mode;
                VooraanmeldingForm->NameDBEdit->ReadOnly=mode;
                VooraanmeldingForm->MarriedNameDBEdit->ReadOnly=mode;
                VooraanmeldingForm->FirstNameDBEdit->ReadOnly=mode;
                VooraanmeldingForm->InitialsDBEdit->ReadOnly=mode;
                VooraanmeldingForm->BirthDateDBEdit->ReadOnly=mode;
                VooraanmeldingForm->NationalityDBLookupComboBox->ReadOnly=mode;
                VooraanmeldingForm->BirthPlaceDBEdit->ReadOnly=mode;
                VooraanmeldingForm->EthnicDBLookupComboBox->ReadOnly=mode;
                VooraanmeldingForm->ReligionDBEdit->ReadOnly=mode;
                VooraanmeldingForm->PrevEducationDBLookupComboBox->ReadOnly=mode;
                VooraanmeldingForm->SexDBRadioGroup->ReadOnly=mode;
                VooraanmeldingForm->MarritalStatusDBRadioGroup->ReadOnly=mode;
                VooraanmeldingForm->StreetDBEdit->ReadOnly=mode;
                VooraanmeldingForm->NumberDBEdit->ReadOnly=mode;
                VooraanmeldingForm->AreaDBEdit->ReadOnly=mode;
                VooraanmeldingForm->DistrictDBEdit->ReadOnly=mode;
                VooraanmeldingForm->CountryDBEdit->ReadOnly=mode;
                VooraanmeldingForm->TelephoneDBEdit->ReadOnly=mode;
                VooraanmeldingForm->CellNrDBEdit->ReadOnly=mode;
                VooraanmeldingForm->Email1DBEdit->ReadOnly=mode;
                VooraanmeldingForm->Email2DBEdit->ReadOnly=mode;
                VooraanmeldingForm->BankAccountDBEdit->ReadOnly=mode;
                VooraanmeldingForm->CommentDBMemo->ReadOnly=mode;
                VooraanmeldingForm->HobbiesDBMemo->ReadOnly=mode;
                VooraanmeldingForm->ExtentieDBEdit->ReadOnly=mode;
                VooraanmeldingForm->ContactTelefoonDBEdit->ReadOnly=mode;
                VooraanmeldingForm->WerkTelefoonDBEdit->ReadOnly=mode;
                VooraanmeldingForm->NatuurkundeDBEdit->ReadOnly = mode;
                VooraanmeldingForm->WiskundeDBEdit->ReadOnly = mode;
                VooraanmeldingForm->ScheikundeDBEdit->ReadOnly = mode;
                VooraanmeldingForm->BiologieDBEdit->ReadOnly = mode;
                VooraanmeldingForm->FaculteitDBLookupComboBox->ReadOnly = mode;
                VooraanmeldingForm->Studierichting1DBLookupComboBox->ReadOnly = mode;
                VooraanmeldingForm->Studierichting2DBLookupComboBox->ReadOnly = mode;
}
//--------------------------------------------------------------------------

static void DoRead()
{
    VooraanmeldingForm->DBNavigator1->Enabled = true;
    VooraanmeldingForm->NieuwButton->Enabled = false;
    VooraanmeldingForm->OpslaanButton->Enabled = false;
    VooraanmeldingForm->VerwijderButton->Enabled = false;
    VooraanmeldingForm->InschrijfButton->Enabled = false;
    VooraanmeldingForm->SearchEdit->Show();
    VooraanmeldingForm->SearchButton->Show();
    VooraanmeldingForm->ToggleButton->Show();
    VooraanmeldingForm->LastRecordsDBGrid->Show();
   // VooraanmeldingForm->InschrijfButton->Enabled = false;
   // VooraanmeldingForm->NatuurkundeLabel->ReadOnly = true;
   // VooraanmeldingForm->WiskundeLabel->ReadOnly = true;
   // VooraanmeldingForm->ScheikundeLabel->Enabled = false;
   // VooraanmeldingForm->BiologieLabel->Enabled = false;
    VooraanmeldingForm->NatuurkundeDBEdit->ReadOnly = true;
    VooraanmeldingForm->WiskundeDBEdit->ReadOnly = true;
    VooraanmeldingForm->ScheikundeDBEdit->ReadOnly = true;
    VooraanmeldingForm->BiologieDBEdit->ReadOnly = true;
    VooraanmeldingForm->FaculteitDBLookupComboBox->ReadOnly = true;
    VooraanmeldingForm->Studierichting1DBLookupComboBox->ReadOnly = true;
    VooraanmeldingForm->Studierichting2DBLookupComboBox->ReadOnly = true;
 //   VooraanmeldingForm->FaculteitLabel->Enabled = false;
 //   VooraanmeldingForm->Studierichting1Label->Enabled = false;
 //   VooraanmeldingForm->Studierichting2Label->Enabled = false;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    VooraanmeldingForm->DBNavigator1->Enabled = true;
    VooraanmeldingForm->NieuwButton->Enabled = false;
    VooraanmeldingForm->OpslaanButton->Enabled = false;
    VooraanmeldingForm->VerwijderButton->Enabled = true;
    VooraanmeldingForm->SearchEdit->Show();
    VooraanmeldingForm->SearchButton->Show();
    VooraanmeldingForm->ToggleButton->Show();
    VooraanmeldingForm->LastRecordsDBGrid->Show();
    VooraanmeldingForm->InschrijfButton->Enabled = false;
    VooraanmeldingForm->NatuurkundeLabel->Enabled = false;
    VooraanmeldingForm->WiskundeLabel->Enabled = false;
    VooraanmeldingForm->ScheikundeLabel->Enabled = false;
    VooraanmeldingForm->BiologieLabel->Enabled = false;
    VooraanmeldingForm->NatuurkundeDBEdit->Enabled = false;
    VooraanmeldingForm->WiskundeDBEdit->Enabled = false;
    VooraanmeldingForm->ScheikundeDBEdit->Enabled = false;
    VooraanmeldingForm->BiologieDBEdit->Enabled = false;
    VooraanmeldingForm->FaculteitDBLookupComboBox->Enabled = false;
    VooraanmeldingForm->Studierichting1DBLookupComboBox->Enabled = false;
    VooraanmeldingForm->Studierichting2DBLookupComboBox->Enabled = false;
    VooraanmeldingForm->FaculteitLabel->Enabled = false;
    VooraanmeldingForm->Studierichting1Label->Enabled = false;
    VooraanmeldingForm->Studierichting2Label->Enabled = false;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoInschrijven()
{
    VooraanmeldingForm->DBNavigator1->Enabled = true;
    VooraanmeldingForm->NieuwButton->Enabled = false;
    VooraanmeldingForm->OpslaanButton->Enabled = false;
    VooraanmeldingForm->VerwijderButton->Enabled = false;
    VooraanmeldingForm->InschrijfButton->Enabled = true;
    VooraanmeldingForm->SearchEdit->Show();
    VooraanmeldingForm->SearchButton->Show();
    VooraanmeldingForm->ToggleButton->Show();
    VooraanmeldingForm->LastRecordsDBGrid->Show();
    VooraanmeldingForm->FaculteitDBLookupComboBox->Enabled = false;
    VooraanmeldingForm->Studierichting1DBLookupComboBox->Enabled = false;
    VooraanmeldingForm->Studierichting2DBLookupComboBox->Enabled = false;
     VooraanmeldingForm->FaculteitLabel->Enabled = false;
    VooraanmeldingForm->Studierichting1Label->Enabled = false;
    VooraanmeldingForm->Studierichting2Label->Enabled = false;
    VooraanmeldingForm->NatuurkundeLabel->Enabled = false;
    VooraanmeldingForm->WiskundeLabel->Enabled = false;
    VooraanmeldingForm->ScheikundeLabel->Enabled = false;
    VooraanmeldingForm->BiologieLabel->Enabled = false;
    VooraanmeldingForm->NatuurkundeDBEdit->Enabled = false;
    VooraanmeldingForm->WiskundeDBEdit->Enabled = false;
    VooraanmeldingForm->ScheikundeDBEdit->Enabled = false;
    VooraanmeldingForm->BiologieDBEdit->Enabled = false;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
    VooraanmeldingForm->DBNavigator1->Enabled = true;
    VooraanmeldingForm->NieuwButton->Enabled = false;
    VooraanmeldingForm->OpslaanButton->Enabled = true;
    VooraanmeldingForm->VerwijderButton->Enabled = false;
    VooraanmeldingForm->InschrijfButton->Enabled = false;
    VooraanmeldingForm->SearchEdit->Show();
    VooraanmeldingForm->SearchButton->Show();
    VooraanmeldingForm->ToggleButton->Show();
    VooraanmeldingForm->LastRecordsDBGrid->Show();
    VooraanmeldingForm->NatuurkundeLabel->Enabled = true;
    VooraanmeldingForm->WiskundeLabel->Enabled = true;
    VooraanmeldingForm->ScheikundeLabel->Enabled = true;
    VooraanmeldingForm->BiologieLabel->Enabled = true;
    VooraanmeldingForm->NatuurkundeDBEdit->Enabled = true;
    VooraanmeldingForm->WiskundeDBEdit->Enabled = true;
    VooraanmeldingForm->ScheikundeDBEdit->Enabled = true;
    VooraanmeldingForm->BiologieDBEdit->Enabled = true;
    VooraanmeldingForm->FaculteitDBLookupComboBox->Enabled = true;
    VooraanmeldingForm->Studierichting1DBLookupComboBox->Enabled = true;
    VooraanmeldingForm->Studierichting2DBLookupComboBox->Enabled = true;
    VooraanmeldingForm->FaculteitLabel->Enabled = true;
    VooraanmeldingForm->Studierichting1Label->Enabled = true;
    VooraanmeldingForm->Studierichting2Label->Enabled = true;

//    VooraanmeldingForm->IdCardDBEdit->ReadOnly = true;
    VooraanmeldingForm->MarriedNameDBEdit->Enabled = false;
     SetReadModus(false);
}
//----------------------------------------------------------------------------

static void  DoInsert()
{
    VooraanmeldingForm->DBNavigator1->Enabled = false;
    VooraanmeldingForm->SexDBRadioGroup->ItemIndex = 1;
    VooraanmeldingForm->MarritalStatusDBRadioGroup->ItemIndex = 0;
    VooraanmeldingForm->NieuwButton->Enabled = true;
    VooraanmeldingForm->OpslaanButton->Enabled = false;
    VooraanmeldingForm->VerwijderButton->Enabled = false;
    VooraanmeldingForm->InschrijfButton->Enabled = false;
    VooraanmeldingForm->SearchEdit->Hide();
    VooraanmeldingForm->ToggleButton->Hide();
    VooraanmeldingForm->SearchButton->Hide();

    VooraanmeldingForm->MarriedNameDBEdit->Enabled = false;
    VooraanmeldingForm->NatuurkundeLabel->Enabled = true;
    VooraanmeldingForm->WiskundeLabel->Enabled = true;
    VooraanmeldingForm->ScheikundeLabel->Enabled = true;
    VooraanmeldingForm->BiologieLabel->Enabled = true;
    VooraanmeldingForm->NatuurkundeDBEdit->Enabled = true;
    VooraanmeldingForm->WiskundeDBEdit->Enabled = true;
    VooraanmeldingForm->ScheikundeDBEdit->Enabled = true;
    VooraanmeldingForm->BiologieDBEdit->Enabled = true;
    VooraanmeldingForm->FaculteitDBLookupComboBox->Enabled = true;
    VooraanmeldingForm->Studierichting1DBLookupComboBox->Enabled = true;
    VooraanmeldingForm->Studierichting2DBLookupComboBox->Enabled = true;
    VooraanmeldingForm->FaculteitLabel->Enabled = true;
    VooraanmeldingForm->Studierichting1Label->Enabled = true;
    VooraanmeldingForm->Studierichting2Label->Enabled = true;

    SetReadModus(false);

}
//---------------------------------------------------------------------------
void __fastcall TVooraanmeldingForm::ModusKnopClick(TObject *Sender)
{
   Modus = (++Modus)%5;
   switch (Modus)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Lezen"; DoRead();break;//lezen
   case 1: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Toevoegen";DoInsert();break;//toevoegen
   case 2: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Wijzigen";DoUpdate();break;//wijzigen
   case 3: ModusKnop->Font->Color = clRed ;ModusKnop->Caption = "Verwijderen";DoDelete();break;//verwijderen
   case 4: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Inschrijven";DoInschrijven();//inschrijven
    };
}
//---------------------------------------------------------------------------
void __fastcall TVooraanmeldingForm::NieuwButtonClick(TObject *Sender)
{
    if (sasDataModule->sasSQLConnection->Connected!=true)
        {
                sasDataModule->sasSQLConnection->Connected=true;
        }

        vpersonSQLDataSet->Close(); // Flush previous query
        vpersonClientDataSet->Active=false; // Flush previous data in set
        vpersonSQLDataSet->CommandText="select * from vpersoon where NAAM like :Name";
        vpersonSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
        vpersonSQLDataSet->Open();
        vpersonClientDataSet->Active=true;
       // VooraanmeldingForm->SexDBRadioGroup->ItemIndex = 1;
      //  VooraanmeldingForm->MarritalStatusDBRadioGroup->ItemIndex = 0;
        VooraanmeldingForm->BirthDateDBEdit->Field->EditMask="!0000/00/00;1;_";
        //VooraanmeldingForm->TelephoneDBEdit->Field->EditMask="!00000000;1;_";
        //VooraanmeldingForm->CellNrDBEdit->Field->EditMask="!00000000;1;_";
        VooraanmeldingForm->OpslaanButton->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TVooraanmeldingForm::OpslaanButtonClick(TObject *Sender)
{
   Variant leeg = NULL;
   int volgnr = 0;
   char buf[5];
   String jaar = CurrentYear();
   if (Modus == 1)
    {
      if ((VooraanmeldingForm->SexDBRadioGroup->ItemIndex < 0)||(VooraanmeldingForm->MarritalStatusDBRadioGroup->ItemIndex < 0))
      {
         Application->MessageBox("U heeft het geslacht en/of de burgerlijke staat niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
       if (VooraanmeldingForm->NameDBEdit->Text == "")
      {
         Application->MessageBox("U heeft de naam niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
       if (VooraanmeldingForm->FirstNameDBEdit->Text == "")
      {
         Application->MessageBox("U heeft de voornaam niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
      if (VooraanmeldingForm->IdCardDBEdit->Text == "")
      {
         Application->MessageBox("U heeft het idnummer niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
      if (VooraanmeldingForm->BirthDateDBEdit->Text == "")
      {
         Application->MessageBox("U heeft de geboortedatum niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
      vpersonSQLDataSet->CommandType = ctQuery;
      vpersonSQLDataSet->CommandText = "INSERT INTO VPERSOON (IDKAARTNR,NATIO_ID,BEV_ID,GESLACHT,NAAM,GEHUWDENAAM, VOORNAAM,VOORNAAM2,BURGERLIJKE_STAAT,OPMERKING,GEBOORTELAND,GEBOORTEPLAATS,BANK,DISTRICT,GELOOF,STRAAT,HUISNUMMER,EMAIL1,EMAIL2,GEBOORTEDATUM,BANKREKENINGNR,TELEFOON2,TELEFOON1,WOONPLAATS,WIJK, OPLEIDING_ID,HOBBIES)"
                                                                  "VALUES(:IDKAARTNR,:NATIO_ID,:BEV_ID,:GESLACHT,:NAAM,:GEHUWDENAAM,:VOORNAAM,:VOORNAAM2,:BURGERLIJKE_STAAT,:OPMERKING,:GEBOORTELAND,:GEBOORTEPLAATS,:BANK,:DISTRICT,:GELOOF,:STRAAT,:HUISNUMMER,:EMAIL1,:EMAIL2,:GEBOORTEDATUM,:BANKREKENINGNR,:TELEFOON2,:TELEFOON1,:WOONPLAATS,:WIJK,:OPLEIDING_ID,:HOBBIES)";
      vpersonSQLDataSet->Params->Items[0]->AsString = VooraanmeldingForm->IdCardDBEdit->Text;
      if (!(VooraanmeldingForm->NationalityDBLookupComboBox->Text == ""))
        {
   //       Application->MessageBox("",itoa(VooraanmeldingForm->NationalityDBLookupComboBox->ListFieldIndex, buf, 10) ,MB_OK);

       // Application->MessageBox("",itoa(VooraanmeldingForm->NationalityDBLookupComboBox->ListFieldIndex, buf, 10) ,MB_OK);
        vpersonSQLDataSet->Params->Items[1]->AsString = VooraanmeldingForm->NationalityDBLookupComboBox->KeyValue;
        }
      else
        vpersonSQLDataSet->Params->Items[1]->AsString = leeg;
      if (!(VooraanmeldingForm->EthnicDBLookupComboBox->Text == ""))
        vpersonSQLDataSet->Params->Items[2]->AsString = VooraanmeldingForm->EthnicDBLookupComboBox->KeyValue;
      else
        vpersonSQLDataSet->Params->Items[2]->AsString = leeg;
      vpersonSQLDataSet->Params->Items[3]->AsString = VooraanmeldingForm->SexDBRadioGroup->Value;
      vpersonSQLDataSet->Params->Items[4]->AsString = VooraanmeldingForm->NameDBEdit->Text;
      vpersonSQLDataSet->Params->Items[5]->AsString = VooraanmeldingForm->MarriedNameDBEdit->Text;
      vpersonSQLDataSet->Params->Items[6]->AsString = VooraanmeldingForm->FirstNameDBEdit->Text;
      vpersonSQLDataSet->Params->Items[7]->AsString = VooraanmeldingForm->InitialsDBEdit->Text;
      vpersonSQLDataSet->Params->Items[8]->AsString = VooraanmeldingForm->MarritalStatusDBRadioGroup->Value;
      vpersonSQLDataSet->Params->Items[9]->AsString = VooraanmeldingForm->CommentDBMemo->Text;
      vpersonSQLDataSet->Params->Items[10]->AsString = VooraanmeldingForm->CountryDBEdit->Text;
      vpersonSQLDataSet->Params->Items[11]->AsString = VooraanmeldingForm->BirthPlaceDBEdit->Text;
      vpersonSQLDataSet->Params->Items[12]->AsString = VooraanmeldingForm->BankDBEdit->Text;
      vpersonSQLDataSet->Params->Items[13]->AsString = VooraanmeldingForm->DistrictDBEdit->Text;
      vpersonSQLDataSet->Params->Items[14]->AsString = VooraanmeldingForm->ReligionDBEdit->Text;
      vpersonSQLDataSet->Params->Items[15]->AsString = VooraanmeldingForm->StreetDBEdit->Text;
      vpersonSQLDataSet->Params->Items[16]->AsString = VooraanmeldingForm->NumberDBEdit->Text;
      vpersonSQLDataSet->Params->Items[17]->AsString = VooraanmeldingForm->Email1DBEdit->Text;
      vpersonSQLDataSet->Params->Items[18]->AsString = VooraanmeldingForm->Email2DBEdit->Text;

      vpersonSQLDataSet->Params->Items[19]->AsDate = VooraanmeldingForm->BirthDateDBEdit->EditText;
      vpersonSQLDataSet->Params->Items[20]->AsString = VooraanmeldingForm->BankAccountDBEdit->Text;
      vpersonSQLDataSet->Params->Items[21]->AsString = VooraanmeldingForm->TelephoneDBEdit->Text;
      vpersonSQLDataSet->Params->Items[22]->AsString = VooraanmeldingForm->CellNrDBEdit->Text;
      vpersonSQLDataSet->Params->Items[23]->AsString = VooraanmeldingForm->WoonplaatsDBEdit->Text;
      vpersonSQLDataSet->Params->Items[24]->AsString = VooraanmeldingForm->AreaDBEdit->Text;
      if (!(VooraanmeldingForm->PrevEducationDBLookupComboBox->Text == ""))
         vpersonSQLDataSet->Params->Items[25]->AsString = VooraanmeldingForm->PrevEducationDBLookupComboBox->KeyValue;
      else
         vpersonSQLDataSet->Params->Items[25]->AsString = leeg;
      vpersonSQLDataSet->Params->Items[26]->AsString = VooraanmeldingForm->HobbiesDBMemo->Text;

      vpersonSQLDataSet->ExecSQL();

     vinschrijvingSQLDataSet->CommandType = ctQuery;
     String vinschrijvingquery ;
     vinschrijvingSQLDataSet->CommandText = vinschrijvingquery = "INSERT INTO VINSCHRIJVING\
      (FACULTEIT_ID,IDKAARTNR,AANMELDJAAR,STUDIERICHTING1_ID,STUDIERICHTING2_ID,WISKUNDE,NATUURKUNDE,SCHEIKUNDE,BIOLOGIE)"
      "VALUES(:FACULTEIT_ID,:IDKAARTNR,:AANMELDJAAR,:STUDIERICHTING1_ID,:STUDIERICHTING2_ID,\
      :WISKUNDE,:NATUURKUNDE,:SCHEIKUNDE,:BIOLOGIE)";
     vinschrijvingSQLDataSet->Params->Items[0]->AsInteger = VooraanmeldingForm->FaculteitDBLookupComboBox->KeyValue;
     vinschrijvingSQLDataSet->Params->Items[1]->AsString = VooraanmeldingForm->IdCardDBEdit->Text;
     vinschrijvingSQLDataSet->Params->Items[2]->AsInteger = atoi(jaar.c_str());
     vinschrijvingSQLDataSet->Params->Items[3]->AsString = VooraanmeldingForm->Studierichting1DBLookupComboBox->KeyValue;
     vinschrijvingSQLDataSet->Params->Items[4]->AsString = VooraanmeldingForm->Studierichting2DBLookupComboBox->KeyValue;
     vinschrijvingSQLDataSet->Params->Items[5]->AsInteger = atoi(VooraanmeldingForm->WiskundeDBEdit->Text.c_str());
     vinschrijvingSQLDataSet->Params->Items[6]->AsInteger = atoi(VooraanmeldingForm->NatuurkundeDBEdit->Text.c_str());
     vinschrijvingSQLDataSet->Params->Items[7]->AsInteger = atoi(VooraanmeldingForm->ScheikundeDBEdit->Text.c_str());
     vinschrijvingSQLDataSet->Params->Items[8]->AsInteger = atoi(VooraanmeldingForm->BiologieDBEdit->Text.c_str());
    Application->MessageBox(vinschrijvingquery.c_str(),"",MB_OK);
     vinschrijvingSQLDataSet->ExecSQL();


   VooraanmeldingForm->NieuwButton->Enabled = true;
   VooraanmeldingForm->OpslaanButton->Enabled = false;
    }
   else if (Modus == 2)
    {
      vpersonSQLDataSet->CommandType = ctQuery;
      vpersonSQLDataSet->CommandText = "UPDATE VPERSOON\
      SET NATIO_ID=:NATIO_ID,BEV_ID=:BEV_ID,GESLACHT=:GESLACHT,NAAM=:NAAM,\
      GEHUWDENAAM=:GEHUWDENAAM, VOORNAAM=:VOORNAAM,VOORNAAM2=:VOORNAAM2,\
      BURGERLIJKE_STAAT=:BURGERLIJKE_STAAT,OPMERKING=:OPMERKING,\
      GEBOORTELAND=:GEBOORTELAND,GEBOORTEPLAATS=:GEBOORTEPLAATS,\
      BANK=:BANK,DISTRICT=:DISTRICT,GELOOF=:GELOOF,STRAAT=:STRAAT,\
      HUISNUMMER=:HUISNUMMER,EMAIL1=:EMAIL1,EMAIL2=:EMAIL2,\
      GEBOORTEDATUM=:GEBOORTEDATUM,BANKREKENINGNR=:BANKREKENINGNR,\
      TELEFOON2=:TELEFOON2,TELEFOON1=:TELEFOON1,WOONPLAATS=:WOONPLAATS,\
      WIJK=:WIJK, OPLEIDING_ID=:OPLEIDING_ID,HOBBIES=:HOBBIES WHERE IDKAARTNR=:IDKAARTNR;";
        if (!(VooraanmeldingForm->NationalityDBLookupComboBox->Text == ""))
        {
 //         Application->MessageBox("",itoa(PersonForm->NationalityDBLookupComboBox->ListFieldIndex, buf, 10) ,MB_OK);

       // Application->MessageBox("",itoa(PersonForm->NationalityDBLookupComboBox->ListFieldIndex, buf, 10) ,MB_OK);
         vpersonSQLDataSet->Params->Items[1]->AsString = VooraanmeldingForm->NationalityDBLookupComboBox->KeyValue;
        }
      else
         vpersonSQLDataSet->Params->Items[1]->AsString = leeg;
      if (!(VooraanmeldingForm->EthnicDBLookupComboBox->Text == ""))
        vpersonSQLDataSet->Params->Items[2]->AsString = VooraanmeldingForm->EthnicDBLookupComboBox->KeyValue;
      else
         vpersonSQLDataSet->Params->Items[2]->AsString = leeg;

      vpersonSQLDataSet->Params->Items[0]->AsString = VooraanmeldingForm->NationalityDBLookupComboBox->KeyValue;
 //     vpersonSQLDataSet->Params->Items[1]->AsString = VooraanmeldingForm->EthnicDBLookupComboBox->KeyValue;
 //     vpersonSQLDataSet->Params->Items[2]->AsString = VooraanmeldingForm->SexDBRadioGroup->Value;
      vpersonSQLDataSet->Params->Items[3]->AsString = VooraanmeldingForm->NameDBEdit->Text;
      vpersonSQLDataSet->Params->Items[4]->AsString = VooraanmeldingForm->MarriedNameDBEdit->Text;
      vpersonSQLDataSet->Params->Items[5]->AsString = VooraanmeldingForm->FirstNameDBEdit->Text;
      vpersonSQLDataSet->Params->Items[6]->AsString = VooraanmeldingForm->InitialsDBEdit->Text;
      vpersonSQLDataSet->Params->Items[7]->AsString = VooraanmeldingForm->MarritalStatusDBRadioGroup->Value;
      vpersonSQLDataSet->Params->Items[8]->AsString = VooraanmeldingForm->CommentDBMemo->Text;
      vpersonSQLDataSet->Params->Items[9]->AsString = VooraanmeldingForm->CountryDBEdit->Text;
      vpersonSQLDataSet->Params->Items[10]->AsString = VooraanmeldingForm->BirthPlaceDBEdit->Text;
      vpersonSQLDataSet->Params->Items[11]->AsString = VooraanmeldingForm->BankDBEdit->Text;
      vpersonSQLDataSet->Params->Items[12]->AsString = VooraanmeldingForm->DistrictDBEdit->Text;
      vpersonSQLDataSet->Params->Items[13]->AsString = VooraanmeldingForm->ReligionDBEdit->Text;
      vpersonSQLDataSet->Params->Items[14]->AsString = VooraanmeldingForm->StreetDBEdit->Text;
      vpersonSQLDataSet->Params->Items[15]->AsString = VooraanmeldingForm->NumberDBEdit->Text;
      vpersonSQLDataSet->Params->Items[16]->AsString = VooraanmeldingForm->Email1DBEdit->Text;
      vpersonSQLDataSet->Params->Items[17]->AsString = VooraanmeldingForm->Email2DBEdit->Text;

      if (!(VooraanmeldingForm->BirthDateDBEdit->Text == ""))
        vpersonSQLDataSet->Params->Items[18]->AsDate = VooraanmeldingForm->BirthDateDBEdit->EditText;
      else
        vpersonSQLDataSet->Params->Items[18]->AsDate = leeg;

      vpersonSQLDataSet->Params->Items[19]->AsString = VooraanmeldingForm->BankAccountDBEdit->Text;
      vpersonSQLDataSet->Params->Items[20]->AsString = VooraanmeldingForm->TelephoneDBEdit->Text;
      vpersonSQLDataSet->Params->Items[21]->AsString = VooraanmeldingForm->CellNrDBEdit->Text;
      vpersonSQLDataSet->Params->Items[22]->AsString = VooraanmeldingForm->WoonplaatsDBEdit->Text;
      vpersonSQLDataSet->Params->Items[23]->AsString = VooraanmeldingForm->AreaDBEdit->Text;
      vpersonSQLDataSet->Params->Items[24]->AsString = VooraanmeldingForm->PrevEducationDBLookupComboBox->KeyValue;
      vpersonSQLDataSet->Params->Items[25]->AsString = VooraanmeldingForm->HobbiesDBMemo->Text;
       vpersonSQLDataSet->Params->Items[26]->AsString = VooraanmeldingForm->IdCardDBEdit->Text;

     vpersonSQLDataSet->ExecSQL();

      volgnr = vinschrijvingClientDataSet->FieldValues["VOLGNR"];
      Application->MessageBox( ((String)vinschrijvingClientDataSet->FieldValues["VOLGNR"]).c_str(), VooraanmeldingForm->IdCardDBEdit->Text.c_str(), MB_OK);

      vinschrijvingSQLDataSet->CommandType = ctQuery;
      vinschrijvingSQLDataSet->CommandText = "UPDATE VINSCHRIJVING SET  FACULTEIT_ID =:FACULTEIT_ID,\
      IDKAARTNR =:IDKAARTNR,AANMELDJAAR =:AANMELDJAAR,STUDIERICHTING1_ID =:STUDIERICHTING1_ID,\
      STUDIERICHTING2_ID =:STUDIERICHTING2_ID,WISKUNDE =:WISKUNDE,NATUURKUNDE =:NATUURKUNDE,\
      SCHEIKUNDE =:SCHEIKUNDE,BIOLOGIE =:BIOLOGIE WHERE VOLGNR =:VOLGNR " ;
      vinschrijvingSQLDataSet->Params->Items[0]->AsInteger = VooraanmeldingForm->FaculteitDBLookupComboBox->KeyValue;
      vinschrijvingSQLDataSet->Params->Items[1]->AsString = VooraanmeldingForm->IdCardDBEdit->Text;
      vinschrijvingSQLDataSet->Params->Items[2]->AsInteger = atoi(jaar.c_str());
      vinschrijvingSQLDataSet->Params->Items[3]->AsString = VooraanmeldingForm->Studierichting1DBLookupComboBox->KeyValue;
      vinschrijvingSQLDataSet->Params->Items[4]->AsString = VooraanmeldingForm->Studierichting2DBLookupComboBox->KeyValue;
      vinschrijvingSQLDataSet->Params->Items[5]->AsInteger = atoi(VooraanmeldingForm->WiskundeDBEdit->Text.c_str());
      vinschrijvingSQLDataSet->Params->Items[6]->AsInteger = atoi(VooraanmeldingForm->NatuurkundeDBEdit->Text.c_str());
      vinschrijvingSQLDataSet->Params->Items[7]->AsInteger = atoi(VooraanmeldingForm->ScheikundeDBEdit->Text.c_str());
      vinschrijvingSQLDataSet->Params->Items[8]->AsInteger = atoi(VooraanmeldingForm->BiologieDBEdit->Text.c_str());
      vinschrijvingSQLDataSet->Params->Items[9]->AsInteger = volgnr;

//Application->MessageBox("2", (VooraanmeldingForm->IdCardDBEdit->Text).c_str(), MB_OK);

      vinschrijvingSQLDataSet->ExecSQL();

      vinschrijvingSQLDataSet->Close(); // Flush previous query
      vinschrijvingClientDataSet->Active=false; // Flush previous data in set
      vinschrijvingSQLDataSet->CommandText="select * from vinschrijving where idkaartnr like :IDKAARTNR";
      vinschrijvingSQLDataSet->ParamByName("IDKAARTNR")->Value="------"; // Append the '%' sign to search for names like the one input in the box
      vinschrijvingSQLDataSet->Open();
      vinschrijvingClientDataSet->Active=true;

       vpersonSQLDataSet->Close(); // Flush previous query
      vpersonClientDataSet->Active=false; // Flush previous data in set
      vpersonSQLDataSet->CommandText="select * from persoon where NAAM like :Name";
      vpersonSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
      vpersonSQLDataSet->Open();
      vpersonClientDataSet->Active=true;
    }
    sasDataModule->GridClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->GridSQLDataSet->CommandText = "SELECT MAX(VOLGNR) AS VOLGNR FROM VPERSOON";


  sasDataModule->GridSQLDataSet->Open();
  sasDataModule->GridClientDataSet->Active=true;
  int maxvolgnr = LastRecordsDBGrid->Fields[0]->Value;
 // char buf[7];
 // Application->MessageBox("", itoa(maxvolgnr, buf, 10), MB_OK);
  sasDataModule->GridSQLDataSet->Close();
  sasDataModule->GridClientDataSet->Active=false;
  sasDataModule->GridSQLDataSet->CommandText = "SELECT * FROM vpersoon where volgnr > :volgnr  ORDER BY VOLGNR DESC";
  sasDataModule->GridSQLDataSet->ParamByName("volgnr")->AsString = maxvolgnr - 50;

  sasDataModule->GridSQLDataSet->Open();
  sasDataModule->GridClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TVooraanmeldingForm::VerwijderButtonClick(TObject *Sender)
{
  vpersonSQLDataSet->CommandType = ctQuery;
  vpersonSQLDataSet->CommandText = "DELETE FROM VPERSOON WHERE IDKAARTNR =   :IDKAARTNR ";
  vpersonSQLDataSet->Params->Items[0]->AsString = VooraanmeldingForm->IdCardDBEdit->Text;
  vpersonSQLDataSet->ExecSQL();

  vpersonSQLDataSet->Close(); // Flush previous query
  vpersonClientDataSet->Active=false; // Flush previous data in set
  vpersonSQLDataSet->CommandText="select * from vpersoon where NAAM like :Name";
  vpersonSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
  vpersonSQLDataSet->Open();
  vpersonClientDataSet->Active=true;

  vinschrijvingSQLDataSet->CommandType = ctQuery;
  vinschrijvingSQLDataSet->CommandText = "DELETE FROM VINSCHRIJVING WHERE IDKAARTNR =   :IDKAARTNR ";
  vinschrijvingSQLDataSet->Params->Items[0]->AsString = VooraanmeldingForm->IdCardDBEdit->Text;
  vinschrijvingSQLDataSet->ExecSQL();

  vinschrijvingSQLDataSet->Close(); // Flush previous query
  vinschrijvingClientDataSet->Active=false; // Flush previous data in set
  vinschrijvingSQLDataSet->CommandText="select * from vinschrijving where IDKAARTNR like :ID";
  vinschrijvingSQLDataSet->ParamByName("ID")->Value="--------"; // Append the '%' sign to search for names like the one input in the box
  vinschrijvingSQLDataSet->Open();
  vinschrijvingClientDataSet->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TVooraanmeldingForm::SexDBRadioGroupClick(TObject *Sender)
{
  if ((VooraanmeldingForm->SexDBRadioGroup->Value == "v")&& (VooraanmeldingForm->MarritalStatusDBRadioGroup->Value == "gehuwd"))
     VooraanmeldingForm->MarriedNameDBEdit->Enabled = true;
  else
     VooraanmeldingForm->MarriedNameDBEdit->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TVooraanmeldingForm::MarritalStatusDBRadioGroupClick(
      TObject *Sender)
{
    if ((VooraanmeldingForm->SexDBRadioGroup->Value == "v")&& (VooraanmeldingForm->MarritalStatusDBRadioGroup->Value == "gehuwd"))
     VooraanmeldingForm->MarriedNameDBEdit->Enabled = true;
  else
     VooraanmeldingForm->MarriedNameDBEdit->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TVooraanmeldingForm::GridPanelButtonClick(TObject *Sender)
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

void __fastcall TVooraanmeldingForm::ToggleButtonClick(TObject *Sender)
{
    if (VooraanmeldingForm->ToggleButton->Caption == "op idnummer")
      VooraanmeldingForm->ToggleButton->Caption = "op naam";
    else if (VooraanmeldingForm->ToggleButton->Caption == "op naam")
            VooraanmeldingForm->ToggleButton->Caption = "op aanmeldnr";
         else
            VooraanmeldingForm->ToggleButton->Caption = "op idnummer";
}
//---------------------------------------------------------------------------

void __fastcall TVooraanmeldingForm::DBNavigator1Click(TObject *Sender,
      TNavigateBtn Button)
{
  last->Text= String(vpersonClientDataSet->RecordCount);
  first->Text= String(vpersonClientDataSet->RecNo);
  // We moeten gaan naar het gekoppelde record in vinschrijving
   vinschrijvingSQLDataSet->Close(); // Flush previous query
   vinschrijvingClientDataSet->Active=false; // Flush previous data in set

   vinschrijvingSQLDataSet->CommandText = "SELECT * FROM vinschrijving WHERE IDKAARTNR =   :IDKAARTNR ";
   vinschrijvingSQLDataSet->Params->Items[0]->AsString = VooraanmeldingForm->IdCardDBEdit->Text;
   vinschrijvingSQLDataSet->Open(); // Flush previous query
   vinschrijvingClientDataSet->Active=true; // Flush previous data in set

}
//---------------------------------------------------------------------------

void __fastcall TVooraanmeldingForm::FaculteitDBLookupComboBoxClick(
      TObject *Sender)
{
     if ( IdCardDBEdit->Text == "") return;
     if (VooraanmeldingForm->FaculteitDBLookupComboBox->Text != "")
     {
   // Application->MessageBox("","faculteitclick",MB_OK);
        VooraanmeldingForm->Studierichting1DBLookupComboBox->Enabled = true;
        VooraanmeldingForm->Studierichting2DBLookupComboBox->Enabled = true;
        VooraanmeldingForm->Studierichting1Label->Enabled = true;
        VooraanmeldingForm->Studierichting2Label->Enabled = true;

        sasDataModule->StudierichtingSQLDataSet->Close(); // Flush previous query
        sasDataModule->StudierichtingClientDataSet->Active=false; // Flush previous data in set

        sasDataModule->StudierichtingSQLDataSet->CommandText = "select * from studierichting where faculteit_id = :faculteit_id and RICHTING_ID not like :RICHTING_ID";
        sasDataModule->StudierichtingSQLDataSet->ParamByName("faculteit_id")->Value = VooraanmeldingForm->FaculteitDBLookupComboBox->KeyValue;
        sasDataModule->StudierichtingSQLDataSet->ParamByName("RICHTING_ID")->Value = "MP";
        sasDataModule->StudierichtingSQLDataSet->Open();
        sasDataModule->StudierichtingClientDataSet->Active=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TVooraanmeldingForm::InschrijfButtonClick(TObject *Sender)
{
// Nu moet de vooraanmelding doorgevoerd worden in de database
//insert into inschrijving ( FACULTEIT_ID, idkaartnr, studierichting_id) select vinschrijving.Faculteit_id, vinschrijving.idkaartnr, vinschrijving.studierichting1_id from vinschrijving where vinschrijving.idkaartnr = "ZZ555555M"; 
}
//---------------------------------------------------------------------------

void __fastcall TVooraanmeldingForm::Button1Click(TObject *Sender)
{
     VooraanmeldingForm->Print();
}
//---------------------------------------------------------------------------




