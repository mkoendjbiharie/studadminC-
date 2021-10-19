//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Studentvooraanmeld.h"
#include "Main.h"
#include "sasdm.h"
#include "sasbasictablesmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
void Leegmaken();
TStudentvooraanmeldForm *StudentvooraanmeldForm;
//---------------------------------------------------------------------------
__fastcall TStudentvooraanmeldForm::TStudentvooraanmeldForm(TComponent* Owner)
        : TForm(Owner)
{

  StudentvooraanmeldForm->vpersonSQLDataSet->Active = true;
  StudentvooraanmeldForm->vpersonClientDataSet->Active = true;
  StudentvooraanmeldForm->vinschrijvingSQLDataSet->Active = true;
  StudentvooraanmeldForm->vinschrijvingClientDataSet->Active = true;
  SasBasicTables->ethnicSQLDataSet->Active = true;
  SasBasicTables->ethnicClientDataSet->Active = true;
  SasBasicTables->prevEduSQLDataSet->Active = true;
  SasBasicTables->prevEduClientDataSet->Active = true;

  sasDataModule->FaculteitSQLDataSet->Active = true;
  sasDataModule->FaculteitClientDataSet->Active = true;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;

  SasBasicTables->eduSQLDataSet->Active = true;
  SasBasicTables->eduClientDataSet->Active = true;
  SasBasicTables->nationalitySQLDataSet->Active = true;
  SasBasicTables->nationalityClientDataSet->Active = true;
  sasDataModule->GridSQLDataSet->Active = true;
  sasDataModule->GridClientDataSet->Active = true;

  StudentvooraanmeldForm->BirthDateDBEdit->Field->EditMask = "!0000/00/00;1;_";
  Leegmaken();
  //StudentvooraanmeldForm->DBEdit1->Field->EditMask = "!00/00/0000;0;_";
//((TDateField *)(vpersonClientDataSet->FindField("TESTDATUM")))->EditMask ="00/00/0000;0;_";

//((TDateField *)(vpersonClientDataSet->FindField("GEBOORTEDATUM")))->DisplayFormat = "yyyy/mm/dd";


 // vpersonClientDataSet-> FormatString = "dd/mm/jjjj";

}
//---------------------------------------------------------------------------
void __fastcall TStudentvooraanmeldForm::ExitClick(TObject *Sender)
{
    HoofdScherm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TStudentvooraanmeldForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    HoofdScherm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TStudentvooraanmeldForm::OpslaanButtonClick(
      TObject *Sender)
{
   Variant leeg = NULL;
   int volgnr = 0;
   char buf[5];
   String jaar = CurrentYear();
       if ((StudentvooraanmeldForm->SexDBRadioGroup->ItemIndex < 0)||(StudentvooraanmeldForm->MarritalStatusDBRadioGroup->ItemIndex < 0))
      {
         Application->MessageBox("U heeft het geslacht en/of de burgerlijke staat niet ingevuld", "Probeer het opnieuw", MB_OK|MB_ICONWARNING);
         return;
      }
       if (StudentvooraanmeldForm->NameDBEdit->Text == "")
      {
         Application->MessageBox("U heeft de naam niet ingevuld", "Probeer het opnieuw", MB_OK|MB_ICONWARNING);
         return;
      }
       if (StudentvooraanmeldForm->FirstNameDBEdit->Text == "")
      {
         Application->MessageBox("U heeft de voornaam niet ingevuld", "Probeer het opnieuw", MB_OK|MB_ICONWARNING);
         return;
      }
      if (StudentvooraanmeldForm->IdCardDBEdit->Text == "")
      {
         Application->MessageBox("U heeft het idnummer niet ingevuld", "Probeer het opnieuw", MB_OK|MB_ICONWARNING);
         return;
      }
      if (StudentvooraanmeldForm->BirthDateDBEdit->Text == "")
      {
         Application->MessageBox("U heeft de geboortedatum niet ingevuld", "Probeer het opnieuw", MB_OK|MB_ICONWARNING);
         return;
      }
      if ((StudentvooraanmeldForm->NatuurkundeDBEdit->Text == "")||
          (StudentvooraanmeldForm->WiskundeDBEdit->Text == "")||
          (StudentvooraanmeldForm->ScheikundeDBEdit->Text == "")||
          (StudentvooraanmeldForm->BiologieDBEdit->Text == ""))
      {
         Application->MessageBox("U heeft een cijfer niet ingevuld", "Probeer het opnieuw", MB_OK|MB_ICONWARNING);
         return;
      }
      if (StudentvooraanmeldForm->Studierichting1DBLookupComboBox->Text == "")
      {
         Application->MessageBox("U heeft geen studierichting ingevuld", "Probeer het opnieuw", MB_OK|MB_ICONWARNING);
         return;
      }

      vpersonSQLDataSet->CommandType = ctQuery;
      vpersonSQLDataSet->CommandText = "INSERT INTO VPERSOON (IDKAARTNR,NATIO_ID,BEV_ID,GESLACHT,NAAM,GEHUWDENAAM, VOORNAAM,VOORNAAM2,BURGERLIJKE_STAAT,OPMERKING,GEBOORTELAND,GEBOORTEPLAATS,BANK,DISTRICT,GELOOF,STRAAT,HUISNUMMER,EMAIL1,EMAIL2,GEBOORTEDATUM,BANKREKENINGNR,TELEFOON2,TELEFOON1,WOONPLAATS,WIJK, OPLEIDING_ID,HOBBIES)"
                                                                  "VALUES(:IDKAARTNR,:NATIO_ID,:BEV_ID,:GESLACHT,:NAAM,:GEHUWDENAAM,:VOORNAAM,:VOORNAAM2,:BURGERLIJKE_STAAT,:OPMERKING,:GEBOORTELAND,:GEBOORTEPLAATS,:BANK,:DISTRICT,:GELOOF,:STRAAT,:HUISNUMMER,:EMAIL1,:EMAIL2,:GEBOORTEDATUM,:BANKREKENINGNR,:TELEFOON2,:TELEFOON1,:WOONPLAATS,:WIJK,:OPLEIDING_ID,:HOBBIES)";
      vpersonSQLDataSet->Params->Items[0]->AsString = StudentvooraanmeldForm->IdCardDBEdit->Text;
      if (!(StudentvooraanmeldForm->NationalityDBLookupComboBox->Text == ""))
        {
   //       Application->MessageBox("",itoa(StudentvooraanmeldForm->NationalityDBLookupComboBox->ListFieldIndex, buf, 10) ,MB_OK);

       // Application->MessageBox("",itoa(StudentvooraanmeldForm->NationalityDBLookupComboBox->ListFieldIndex, buf, 10) ,MB_OK);
        vpersonSQLDataSet->Params->Items[1]->AsString = StudentvooraanmeldForm->NationalityDBLookupComboBox->KeyValue;
        }
      else
        vpersonSQLDataSet->Params->Items[1]->AsString = leeg;
      if (!(StudentvooraanmeldForm->EthnicDBLookupComboBox->Text == ""))
        vpersonSQLDataSet->Params->Items[2]->AsString = StudentvooraanmeldForm->EthnicDBLookupComboBox->KeyValue;
      else
      vpersonSQLDataSet->Params->Items[2]->AsString = leeg;
      vpersonSQLDataSet->Params->Items[3]->AsString = StudentvooraanmeldForm->SexDBRadioGroup->Value;
      vpersonSQLDataSet->Params->Items[4]->AsString = StudentvooraanmeldForm->NameDBEdit->Text;
      vpersonSQLDataSet->Params->Items[5]->AsString = StudentvooraanmeldForm->MarriedNameDBEdit->Text;
      vpersonSQLDataSet->Params->Items[6]->AsString = StudentvooraanmeldForm->FirstNameDBEdit->Text;
      vpersonSQLDataSet->Params->Items[7]->AsString = StudentvooraanmeldForm->InitialsDBEdit->Text;
      vpersonSQLDataSet->Params->Items[8]->AsString = StudentvooraanmeldForm->MarritalStatusDBRadioGroup->Value;
      vpersonSQLDataSet->Params->Items[9]->AsString = StudentvooraanmeldForm->CommentDBMemo->Text;
      vpersonSQLDataSet->Params->Items[10]->AsString = StudentvooraanmeldForm->CountryDBEdit->Text;
      vpersonSQLDataSet->Params->Items[11]->AsString = StudentvooraanmeldForm->BirthPlaceDBEdit->Text;
      vpersonSQLDataSet->Params->Items[12]->AsString = StudentvooraanmeldForm->BankDBEdit->Text;
      vpersonSQLDataSet->Params->Items[13]->AsString = StudentvooraanmeldForm->DistrictDBEdit->Text;
      vpersonSQLDataSet->Params->Items[14]->AsString = StudentvooraanmeldForm->ReligionDBEdit->Text;
      vpersonSQLDataSet->Params->Items[15]->AsString = StudentvooraanmeldForm->StreetDBEdit->Text;
      vpersonSQLDataSet->Params->Items[16]->AsString = StudentvooraanmeldForm->NumberDBEdit->Text;
      vpersonSQLDataSet->Params->Items[17]->AsString = StudentvooraanmeldForm->Email1DBEdit->Text;
      vpersonSQLDataSet->Params->Items[18]->AsString = StudentvooraanmeldForm->Email2DBEdit->Text;

      if (!(StudentvooraanmeldForm->BirthDateDBEdit->Text == ""))
        vpersonSQLDataSet->Params->Items[19]->AsDate = StudentvooraanmeldForm->BirthDateDBEdit->Text;
      else
        vpersonSQLDataSet->Params->Items[19]->AsDate = leeg;

//      vpersonSQLDataSet->Params->Items[19]->AsDate = StudentvooraanmeldForm->BirthDateDBEdit->EditText;
      vpersonSQLDataSet->Params->Items[20]->AsString = StudentvooraanmeldForm->BankAccountDBEdit->Text;
      vpersonSQLDataSet->Params->Items[21]->AsString = StudentvooraanmeldForm->TelephoneDBEdit->Text;
      vpersonSQLDataSet->Params->Items[22]->AsString = StudentvooraanmeldForm->CellNrDBEdit->Text;
      vpersonSQLDataSet->Params->Items[23]->AsString = StudentvooraanmeldForm->WoonplaatsDBEdit->Text;
      vpersonSQLDataSet->Params->Items[24]->AsString = StudentvooraanmeldForm->AreaDBEdit->Text;
      if (!(StudentvooraanmeldForm->PrevEducationDBLookupComboBox->Text == ""))
         vpersonSQLDataSet->Params->Items[25]->AsString = StudentvooraanmeldForm->PrevEducationDBLookupComboBox->KeyValue;
      else
         vpersonSQLDataSet->Params->Items[25]->AsString = leeg;
      vpersonSQLDataSet->Params->Items[26]->AsString = StudentvooraanmeldForm->HobbiesDBMemo->Text;

      vpersonSQLDataSet->ExecSQL();

     vinschrijvingSQLDataSet->CommandType = ctQuery;
     vinschrijvingSQLDataSet->CommandText = "INSERT INTO VINSCHRIJVING\
      (FACULTEIT_ID,IDKAARTNR,AANMELDJAAR,STUDIERICHTING1_ID,STUDIERICHTING2_ID,WISKUNDE,NATUURKUNDE,SCHEIKUNDE,BIOLOGIE)"
      "VALUES(:FACULTEIT_ID,:IDKAARTNR,:AANMELDJAAR,:STUDIERICHTING1_ID,:STUDIERICHTING2_ID,\
      :WISKUNDE,:NATUURKUNDE,:SCHEIKUNDE,:BIOLOGIE)";
     vinschrijvingSQLDataSet->Params->Items[0]->AsInteger = StudentvooraanmeldForm->FaculteitDBLookupComboBox->KeyValue;
     vinschrijvingSQLDataSet->Params->Items[1]->AsString = StudentvooraanmeldForm->IdCardDBEdit->Text;
     vinschrijvingSQLDataSet->Params->Items[2]->AsInteger = atoi(jaar.c_str());
     vinschrijvingSQLDataSet->Params->Items[3]->AsString = StudentvooraanmeldForm->Studierichting1DBLookupComboBox->KeyValue;
     vinschrijvingSQLDataSet->Params->Items[4]->AsString = StudentvooraanmeldForm->Studierichting2DBLookupComboBox->KeyValue;
     vinschrijvingSQLDataSet->Params->Items[5]->AsInteger = atoi(StudentvooraanmeldForm->WiskundeDBEdit->Text.c_str());
     vinschrijvingSQLDataSet->Params->Items[6]->AsInteger = atoi(StudentvooraanmeldForm->NatuurkundeDBEdit->Text.c_str());
     vinschrijvingSQLDataSet->Params->Items[7]->AsInteger = atoi(StudentvooraanmeldForm->ScheikundeDBEdit->Text.c_str());
     vinschrijvingSQLDataSet->Params->Items[8]->AsInteger = atoi(StudentvooraanmeldForm->BiologieDBEdit->Text.c_str());
     vinschrijvingSQLDataSet->ExecSQL();
     vpersonSQLDataSet->Close(); // Flush previous query
     vpersonClientDataSet->Active=false; // Flush previous data in set
     vpersonSQLDataSet->CommandText="select * from vpersoon where NAAM like :Name";
     vpersonSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
     vpersonSQLDataSet->Open();
     vpersonClientDataSet->Active=true;

     vinschrijvingSQLDataSet->Close(); // Flush previous query
     vinschrijvingClientDataSet->Active=false; // Flush previous data in set
     vinschrijvingSQLDataSet->CommandText="select * from vinschrijving where IDKAARTNR like :IDKAARTNR";
     vinschrijvingSQLDataSet->ParamByName("IDKAARTNR")->Value="--------"; // Append the '%' sign to search for names like the one input in the box
     vinschrijvingSQLDataSet->Open();
     vinschrijvingClientDataSet->Active=true;


 /* Variant leeg = NULL;
   char buf[5];

      if ((StudentvooraanmeldForm->SexDBRadioGroup->ItemIndex < 0)||(StudentvooraanmeldForm->MarritalStatusDBRadioGroup->ItemIndex < 0))
      {
         Application->MessageBox("U heeft het geslacht en/of de burgerlijke staat niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
       if (StudentvooraanmeldForm->NameDBEdit->Text == "")
      {
         Application->MessageBox("U heeft de naam niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
       if (StudentvooraanmeldForm->FirstNameDBEdit->Text == "")
      {
         Application->MessageBox("U heeft de voornaam niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
      if (StudentvooraanmeldForm->IdCardDBEdit->Text == "")
      {
         Application->MessageBox("U heeft het idnummer niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
      if (StudentvooraanmeldForm->BirthDateDBEdit->Text == "")
      {
         Application->MessageBox("U heeft de geboortedatum niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
      vpersonSQLDataSet->CommandType = ctQuery;
      vpersonSQLDataSet->CommandText = "INSERT INTO VPERSOON (IDKAARTNR,NATIO_ID,BEV_ID,GESLACHT,NAAM,GEHUWDENAAM, VOORNAAM,VOORNAAM2,BURGERLIJKE_STAAT,OPMERKING,GEBOORTELAND,GEBOORTEPLAATS,BANK,DISTRICT,GELOOF,STRAAT,HUISNUMMER,EMAIL1,EMAIL2,GEBOORTEDATUM,BANKREKENINGNR,TELEFOON2,TELEFOON1,WOONPLAATS,WIJK, OPLEIDING_ID,HOBBIES)"
                                                                  "VALUES(:IDKAARTNR,:NATIO_ID,:BEV_ID,:GESLACHT,:NAAM,:GEHUWDENAAM,:VOORNAAM,:VOORNAAM2,:BURGERLIJKE_STAAT,:OPMERKING,:GEBOORTELAND,:GEBOORTEPLAATS,:BANK,:DISTRICT,:GELOOF,:STRAAT,:HUISNUMMER,:EMAIL1,:EMAIL2,:GEBOORTEDATUM,:BANKREKENINGNR,:TELEFOON2,:TELEFOON1,:WOONPLAATS,:WIJK,:OPLEIDING_ID,:HOBBIES)";
      vpersonSQLDataSet->Params->Items[0]->AsString = StudentvooraanmeldForm->IdCardDBEdit->Text;
      if (!(StudentvooraanmeldForm->NationalityDBLookupComboBox->Text == ""))
        {
          Application->MessageBox("",itoa(StudentvooraanmeldForm->NationalityDBLookupComboBox->ListFieldIndex, buf, 10) ,MB_OK);

       // Application->MessageBox("",itoa(StudentvooraanmeldForm->NationalityDBLookupComboBox->ListFieldIndex, buf, 10) ,MB_OK);
        vpersonSQLDataSet->Params->Items[1]->AsString = StudentvooraanmeldForm->NationalityDBLookupComboBox->KeyValue;
        }
      else
        vpersonSQLDataSet->Params->Items[1]->AsString = leeg;
      if (!(StudentvooraanmeldForm->EthnicDBLookupComboBox->Text == ""))
        vpersonSQLDataSet->Params->Items[2]->AsString = StudentvooraanmeldForm->EthnicDBLookupComboBox->KeyValue;
      else
        vpersonSQLDataSet->Params->Items[2]->AsString = leeg;
      vpersonSQLDataSet->Params->Items[3]->AsString = StudentvooraanmeldForm->SexDBRadioGroup->Value;
      vpersonSQLDataSet->Params->Items[4]->AsString = StudentvooraanmeldForm->NameDBEdit->Text;
      vpersonSQLDataSet->Params->Items[5]->AsString = StudentvooraanmeldForm->MarriedNameDBEdit->Text;
      vpersonSQLDataSet->Params->Items[6]->AsString = StudentvooraanmeldForm->FirstNameDBEdit->Text;
      vpersonSQLDataSet->Params->Items[7]->AsString = StudentvooraanmeldForm->InitialsDBEdit->Text;
      vpersonSQLDataSet->Params->Items[8]->AsString = StudentvooraanmeldForm->MarritalStatusDBRadioGroup->Value;
      vpersonSQLDataSet->Params->Items[9]->AsString = StudentvooraanmeldForm->CommentDBMemo->Text;
      vpersonSQLDataSet->Params->Items[10]->AsString = StudentvooraanmeldForm->CountryDBEdit->Text;
      vpersonSQLDataSet->Params->Items[11]->AsString = StudentvooraanmeldForm->BirthPlaceDBEdit->Text;
      vpersonSQLDataSet->Params->Items[12]->AsString = StudentvooraanmeldForm->BankDBEdit->Text;
      vpersonSQLDataSet->Params->Items[13]->AsString = StudentvooraanmeldForm->DistrictDBEdit->Text;
      vpersonSQLDataSet->Params->Items[14]->AsString = StudentvooraanmeldForm->ReligionDBEdit->Text;
      vpersonSQLDataSet->Params->Items[15]->AsString = StudentvooraanmeldForm->StreetDBEdit->Text;
      vpersonSQLDataSet->Params->Items[16]->AsString = StudentvooraanmeldForm->NumberDBEdit->Text;
      vpersonSQLDataSet->Params->Items[17]->AsString = StudentvooraanmeldForm->Email1DBEdit->Text;
      vpersonSQLDataSet->Params->Items[18]->AsString = StudentvooraanmeldForm->Email2DBEdit->Text;

      if (!(StudentvooraanmeldForm->BirthDateDBEdit->Text == ""))
        vpersonSQLDataSet->Params->Items[19]->AsDate = StudentvooraanmeldForm->BirthDateDBEdit->Text;
      else
        vpersonSQLDataSet->Params->Items[19]->AsDate = leeg;

//      vpersonSQLDataSet->Params->Items[19]->AsDate = StudentvooraanmeldForm->BirthDateDBEdit->EditText;
      vpersonSQLDataSet->Params->Items[20]->AsString = StudentvooraanmeldForm->BankAccountDBEdit->Text;
      vpersonSQLDataSet->Params->Items[21]->AsString = StudentvooraanmeldForm->TelephoneDBEdit->Text;
      vpersonSQLDataSet->Params->Items[22]->AsString = StudentvooraanmeldForm->CellNrDBEdit->Text;
      vpersonSQLDataSet->Params->Items[23]->AsString = StudentvooraanmeldForm->WoonplaatsDBEdit->Text;
      vpersonSQLDataSet->Params->Items[24]->AsString = StudentvooraanmeldForm->AreaDBEdit->Text;
      if (!(StudentvooraanmeldForm->EthnicDBLookupComboBox->Text == ""))
         vpersonSQLDataSet->Params->Items[25]->AsString = StudentvooraanmeldForm->PrevEducationDBLookupComboBox->KeyValue;
      else
         vpersonSQLDataSet->Params->Items[25]->AsString = leeg;
      vpersonSQLDataSet->Params->Items[26]->AsString = StudentvooraanmeldForm->HobbiesDBMemo->Text;

      vpersonSQLDataSet->ExecSQL(); */
      Leegmaken();
}
//---------------------------------------------------------------------------
void __fastcall TStudentvooraanmeldForm::SexDBRadioGroupClick(
      TObject *Sender)
{
  if ((StudentvooraanmeldForm->SexDBRadioGroup->Value == "v")&& (StudentvooraanmeldForm->MarritalStatusDBRadioGroup->Value == "gehuwd"))
     StudentvooraanmeldForm->MarriedNameDBEdit->Enabled = true;
  else
     StudentvooraanmeldForm->MarriedNameDBEdit->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TStudentvooraanmeldForm::MarritalStatusDBRadioGroupClick(
      TObject *Sender)
{
   if ((StudentvooraanmeldForm->SexDBRadioGroup->Value == "v")&& (StudentvooraanmeldForm->MarritalStatusDBRadioGroup->Value == "gehuwd"))
     StudentvooraanmeldForm->MarriedNameDBEdit->Enabled = true;
  else
     StudentvooraanmeldForm->MarriedNameDBEdit->Enabled = false;
}
//---------------------------------------------------------------------------

void Leegmaken()
{
 if (sasDataModule->sasSQLConnection->Connected!=true)
        sasDataModule->sasSQLConnection->Connected=true;

        StudentvooraanmeldForm->vpersonSQLDataSet->Close(); // Flush previous query
        StudentvooraanmeldForm->vpersonClientDataSet->Active=false; // Flush previous data in set
        StudentvooraanmeldForm->vpersonSQLDataSet->CommandText="select * from vpersoon where NAAM like :Name";
        StudentvooraanmeldForm->vpersonSQLDataSet->ParamByName("Name")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
        StudentvooraanmeldForm->vpersonSQLDataSet->Open();
        StudentvooraanmeldForm->vpersonClientDataSet->Active=true;
        StudentvooraanmeldForm->BirthDateDBEdit->Field->EditMask="!0000/00/00;1;_";

        StudentvooraanmeldForm->vinschrijvingSQLDataSet->Close(); // Flush previous query
        StudentvooraanmeldForm->vinschrijvingClientDataSet->Active=false; // Flush previous data in set
        StudentvooraanmeldForm->vinschrijvingSQLDataSet->CommandText="select * from vinschrijving where IDKAARTNR like :IDKAARTNR";
        StudentvooraanmeldForm->vinschrijvingSQLDataSet->ParamByName("IDKAARTNR")->Value = "------"; 
        StudentvooraanmeldForm->vinschrijvingSQLDataSet->Open();
        StudentvooraanmeldForm->vinschrijvingClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TStudentvooraanmeldForm::StudieRadioGroupClick(
      TObject *Sender)
{
     StudentvooraanmeldForm->NatuurkundeDBEdit->Enabled = true;
     StudentvooraanmeldForm->WiskundeDBEdit->Enabled = true;
     StudentvooraanmeldForm->ScheikundeDBEdit->Enabled = true;
     StudentvooraanmeldForm->BiologieDBEdit->Enabled = true;
     StudentvooraanmeldForm->Studierichting1DBLookupComboBox->Enabled = true;
     StudentvooraanmeldForm->Studierichting2DBLookupComboBox->Enabled = true;
     StudentvooraanmeldForm->NatuurkundeLabel->Enabled = true;
     StudentvooraanmeldForm->WiskundeLabel->Enabled = true;
     StudentvooraanmeldForm->ScheikundeLabel->Enabled = true;
     StudentvooraanmeldForm->BiologieLabel->Enabled = true;
     StudentvooraanmeldForm->Studierichting1Label->Enabled = true;
     StudentvooraanmeldForm->Studierichting2Label->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TStudentvooraanmeldForm::FaculteitDBLookupComboBoxClick(
      TObject *Sender)
{
//  if ( IdCardDBEdit->Text == "") return;
     if (StudentvooraanmeldForm->FaculteitDBLookupComboBox->Text != "")
     {
//    Application->MessageBox("","faculteitclick",MB_OK);
        StudentvooraanmeldForm->Studierichting1DBLookupComboBox->Enabled = true;
        StudentvooraanmeldForm->Studierichting2DBLookupComboBox->Enabled = true;
        StudentvooraanmeldForm->Studierichting1Label->Enabled = true;
        StudentvooraanmeldForm->Studierichting2Label->Enabled = true;

        sasDataModule->StudierichtingSQLDataSet->Close(); // Flush previous query
        sasDataModule->StudierichtingClientDataSet->Active=false; // Flush previous data in set

        sasDataModule->StudierichtingSQLDataSet->CommandText = "select * from studierichting where faculteit_id = :faculteit_id and RICHTING_ID not like :RICHTING_ID";
        sasDataModule->StudierichtingSQLDataSet->ParamByName("faculteit_id")->Value = StudentvooraanmeldForm->FaculteitDBLookupComboBox->KeyValue;
        sasDataModule->StudierichtingSQLDataSet->ParamByName("RICHTING_ID")->Value = "MP";
        sasDataModule->StudierichtingSQLDataSet->Open();
        sasDataModule->StudierichtingClientDataSet->Active=true;
    }
}
//---------------------------------------------------------------------------

