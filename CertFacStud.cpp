//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CertFacStud.h"
#include "Main.h"
#include "sasdm.h"
#include "sasbasictablesmod.h"
#include "person.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCertificatenfaculteitstudent *Certificatenfaculteitstudent;
static int FModus;
static String studie;
//---------------------------------------------------------------------------
__fastcall TCertificatenfaculteitstudent::TCertificatenfaculteitstudent(TComponent* Owner)
        : TForm(Owner)
{
  FModus = 0;
  sasDataModule->personSQLDataSet->Active = true;
  sasDataModule->InschrijvingSQLDataSet->Active = true;
  sasDataModule->FaculteitSQLDataSet->Active = true;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  SasBasicTables->SysteemSQLDataSet->Active = true;


  CertificaatSQLDataSet->Active = true;
  StudcertificaatSQLDataSet->Active = true;


  sasDataModule->personClientDataSet->Active = true;
  sasDataModule->InschrijvingClientDataSet->Active = true;
  sasDataModule->FaculteitClientDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;
  SasBasicTables->SysteemClientDataSet->Active = true;

  CertificaatClientDataSet->Active = true;
  StudcertificaatClientDataSet->Active = true;


  Certificatenfaculteitstudent->NieuwButton->Enabled = false;
  Certificatenfaculteitstudent->OpslaanButton->Enabled = false;
  Certificatenfaculteitstudent->VerwijderButton->Enabled = false;
  DiplomaButton->Enabled = false;
  Certificatenfaculteitstudent->AfstudeerDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
  Certificatenfaculteitstudent->AfgifteDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";

}

//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   Certificatenfaculteitstudent->CertificaatComboBox->ReadOnly=mode;
   Certificatenfaculteitstudent->AfgifteDatumDBEdit->ReadOnly=mode;
}
//--------------------------------------------------------------------------

static void DoRead()
{
    Certificatenfaculteitstudent->InschrijvingDBNavigator->Enabled = true;
    Certificatenfaculteitstudent->NieuwButton->Enabled = false;
    Certificatenfaculteitstudent->OpslaanButton->Enabled = false;
    Certificatenfaculteitstudent->VerwijderButton->Enabled = false;
    Certificatenfaculteitstudent->DiplomaButton->Enabled = false;
    Certificatenfaculteitstudent->SearchEdit->Show();
    Certificatenfaculteitstudent->SearchButton->Show();
    Certificatenfaculteitstudent->ToggleButton->Show();
    Certificatenfaculteitstudent->IdCardDBEdit->ReadOnly = true;
    Certificatenfaculteitstudent->InschrijvingDBNavigator->Visible = true;
    Certificatenfaculteitstudent->CertificaatLabel->Enabled = false;
    Certificatenfaculteitstudent->AfgifteLabel->Enabled = false;
    Certificatenfaculteitstudent->CertificaatComboBox->Enabled = false;
    Certificatenfaculteitstudent->AfgifteDatumDBEdit->Enabled = false;
    Certificatenfaculteitstudent->AfstudeerDatumLabel->Enabled = false;
    Certificatenfaculteitstudent->AfstudeerDatumDBEdit->Enabled = false;
    Certificatenfaculteitstudent->AfgestudeerdDBRadioGroup->Enabled = false;
    Certificatenfaculteitstudent->AfstudeerDatumDBEdit->ReadOnly = true;
    Certificatenfaculteitstudent->AfgestudeerdDBRadioGroup->ReadOnly = true;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    Certificatenfaculteitstudent->InschrijvingDBNavigator->Enabled = true;
    Certificatenfaculteitstudent->NieuwButton->Enabled = false;
    Certificatenfaculteitstudent->OpslaanButton->Enabled = false;
    Certificatenfaculteitstudent->VerwijderButton->Enabled = true;
    Certificatenfaculteitstudent->DiplomaButton->Enabled = false;
    Certificatenfaculteitstudent->SearchEdit->Show();
    Certificatenfaculteitstudent->SearchButton->Show();
    Certificatenfaculteitstudent->ToggleButton->Show();
    Certificatenfaculteitstudent->IdCardDBEdit->ReadOnly = true;
    Certificatenfaculteitstudent->InschrijvingDBNavigator->Visible = true;
    Certificatenfaculteitstudent->CertificaatLabel->Enabled = true;
    Certificatenfaculteitstudent->AfgifteLabel->Enabled = true;
    Certificatenfaculteitstudent->CertificaatComboBox->Enabled = true;
    Certificatenfaculteitstudent->AfgifteDatumDBEdit->Enabled = true;
    Certificatenfaculteitstudent->AfstudeerDatumLabel->Enabled = false;
    Certificatenfaculteitstudent->AfstudeerDatumDBEdit->Enabled = false;
    Certificatenfaculteitstudent->AfgestudeerdDBRadioGroup->Enabled = false;
    Certificatenfaculteitstudent->AfstudeerDatumDBEdit->ReadOnly = true;
    Certificatenfaculteitstudent->AfgestudeerdDBRadioGroup->ReadOnly = true;

    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
    Certificatenfaculteitstudent->NieuwButton->Enabled = false;
    Certificatenfaculteitstudent->OpslaanButton->Enabled = true;
    Certificatenfaculteitstudent->VerwijderButton->Enabled = false;
    Certificatenfaculteitstudent->DiplomaButton->Enabled = true;
    Certificatenfaculteitstudent->SearchEdit->Show();
    Certificatenfaculteitstudent->SearchButton->Show();
    Certificatenfaculteitstudent->ToggleButton->Show();
    Certificatenfaculteitstudent->IdCardDBEdit->ReadOnly = false;
    Certificatenfaculteitstudent->InschrijvingDBNavigator->Visible = true;
    Certificatenfaculteitstudent->CertificaatLabel->Enabled = true;
    Certificatenfaculteitstudent->AfgifteLabel->Enabled = true;
    Certificatenfaculteitstudent->CertificaatComboBox->Enabled = true;
    Certificatenfaculteitstudent->AfgifteDatumDBEdit->Enabled = true;
    Certificatenfaculteitstudent->AfstudeerDatumLabel->Enabled = true;
    Certificatenfaculteitstudent->AfstudeerDatumDBEdit->Enabled = true;
    Certificatenfaculteitstudent->AfgestudeerdDBRadioGroup->Enabled = true;
    Certificatenfaculteitstudent->AfstudeerDatumDBEdit->ReadOnly = false;
    Certificatenfaculteitstudent->AfgestudeerdDBRadioGroup->ReadOnly = false;
    Certificatenfaculteitstudent->AfstudeerDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
    SetReadModus(false);
}
//---------------------------------------------------------------------------

static void  DoInsert()
{
//    Certificatenfaculteitstudent->InschrijvingDBNavigator->Enabled = false;
    Certificatenfaculteitstudent->NieuwButton->Enabled = true;
    Certificatenfaculteitstudent->OpslaanButton->Enabled = false;
    Certificatenfaculteitstudent->VerwijderButton->Enabled = false;
    Certificatenfaculteitstudent->DiplomaButton->Enabled = true;
    Certificatenfaculteitstudent->SearchEdit->Hide();
    Certificatenfaculteitstudent->SearchButton->Hide();
    Certificatenfaculteitstudent->ToggleButton->Hide();
    SetReadModus(false);
    Certificatenfaculteitstudent->IdCardDBEdit->ReadOnly = false;
    Certificatenfaculteitstudent->InschrijvingDBNavigator->Visible = true;
    Certificatenfaculteitstudent->CertificaatLabel->Enabled = true;
    Certificatenfaculteitstudent->AfgifteLabel->Enabled = true;
    Certificatenfaculteitstudent->CertificaatComboBox->Enabled = true;
    Certificatenfaculteitstudent->AfgifteDatumDBEdit->Enabled = true;
    Certificatenfaculteitstudent->AfstudeerDatumLabel->Enabled = true;
    Certificatenfaculteitstudent->AfstudeerDatumDBEdit->Enabled = true;
    Certificatenfaculteitstudent->AfgestudeerdDBRadioGroup->Enabled = true;
    Certificatenfaculteitstudent->AfstudeerDatumDBEdit->ReadOnly = true;
    Certificatenfaculteitstudent->AfgestudeerdDBRadioGroup->ReadOnly = true;


}
//---------------------------------------------------------------------------


void __fastcall TCertificatenfaculteitstudent::Close1Click(TObject *Sender)
{
 HoofdScherm->DiplomasCertificaten2->Checked = false;
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TCertificatenfaculteitstudent::Exit1Click(TObject *Sender)
{
  HoofdScherm->DiplomasCertificaten2->Checked = false;
  HoofdScherm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCertificatenfaculteitstudent::SearchButtonClick(
      TObject *Sender)
{
        // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
       //   sasDataModule->sasSQLConnection->Connected=true;
     }

   sasDataModule->personSQLDataSet->Close(); // Flush previous query
   sasDataModule->personClientDataSet->Active = false; // Flush previous data in set
   if (Certificatenfaculteitstudent->ToggleButton->Caption == "op idnummer")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
        sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Certificatenfaculteitstudent->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
   else if (Certificatenfaculteitstudent->ToggleButton->Caption == "op naam")
     {
        sasDataModule->personSQLDataSet->CommandText="select * from persoon where NAAM like :NAAM";
        sasDataModule->personSQLDataSet->ParamByName("naam")->Value=LowerCase(Certificatenfaculteitstudent->SearchEdit->Text+"%"); // Append the '%' sign to search for names like the one input in the box
     }
       else // op studienummer
         {
           //zoek eerst in inschrijving naar het studienummer en daarna in persoon naar het idnummer;
            sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
            sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
            sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where STUDIENR = :STUDIENR";
            sasDataModule->InschrijvingSQLDataSet->ParamByName("STUDIENR")->Value=LowerCase(Certificatenfaculteitstudent->SearchEdit->Text);
            sasDataModule->InschrijvingSQLDataSet->Open();
            sasDataModule->InschrijvingClientDataSet->Active=true;
            String idnummer =(sasDataModule->InschrijvingClientDataSet->FindField("IDKAARTNR"))->AsString;
            sasDataModule->personSQLDataSet->CommandText="select * from persoon where IDKAARTNR like :IDKAARTNR";
            sasDataModule->personSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(idnummer);
            sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
          Certificatenfaculteitstudent->AfstudeerDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";

         }
   if (Certificatenfaculteitstudent->ToggleButton->Caption != "op studienummer")
      {
        sasDataModule->personSQLDataSet->Open();
        sasDataModule->personClientDataSet->Active=true;
     //   Application->MessageBox("", (sasDataModule->personClientDataSet->FieldByName("volgnr")->AsString).c_str(), MB_OK);

       sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
       sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
       sasDataModule->InschrijvingSQLDataSet->CommandText="select * from inschrijving where IDKAARTNR = :IDKAARTNR";
       sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Certificatenfaculteitstudent->IdCardDBEdit->Text);
       sasDataModule->InschrijvingSQLDataSet->Open();
       sasDataModule->InschrijvingClientDataSet->Active=true;
         Certificatenfaculteitstudent->AfstudeerDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";

      }
   //Nu moet op basis van het studienummer gezocht worden in de studentcertificaten tabel.
        StudcertificaatSQLDataSet->Close(); // Flush previous query
        StudcertificaatClientDataSet->Active=false; // Flush previous data in set
        StudcertificaatSQLDataSet->CommandText="select * from studentcertificaat where STUDIENR = :STUDIENR";
        StudcertificaatSQLDataSet->ParamByName("STUDIENR")->Value= StudieNRDBEdit->Text; // Append the '%' sign to search for names like the one input in the box
        StudcertificaatSQLDataSet->Open();
        StudcertificaatClientDataSet->Active=true;
//        Certificatenfaculteitstudent->AfstudeerDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
         Certificatenfaculteitstudent->AfgifteDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";

}
//---------------------------------------------------------------------------

void __fastcall TCertificatenfaculteitstudent::ToggleButtonClick(
      TObject *Sender)
{
   if (Certificatenfaculteitstudent->ToggleButton->Caption == "op idnummer")
      Certificatenfaculteitstudent->ToggleButton->Caption = "op naam";
   else  if(Certificatenfaculteitstudent->ToggleButton->Caption == "op naam")
           Certificatenfaculteitstudent->ToggleButton->Caption = "op studienummer";
        else
           Certificatenfaculteitstudent->ToggleButton->Caption = "op idnummer";
}
//---------------------------------------------------------------------------

void __fastcall TCertificatenfaculteitstudent::ModusKnopClick(
      TObject *Sender)
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

void __fastcall TCertificatenfaculteitstudent::NieuwButtonClick(
      TObject *Sender)
{
  OpslaanButton->Enabled=true;
   if (sasDataModule->sasSQLConnection->Connected!=true)
        {
                sasDataModule->sasSQLConnection->Connected=true;
        }
      //We maken alleen studentcertificaten leeg
        StudcertificaatSQLDataSet->Close(); // Flush previous query
        StudcertificaatClientDataSet->Active=false; // Flush previous data in set
        StudcertificaatSQLDataSet->CommandText="select * from studentcertificaat where STUDIENR = :STUDIENR";
        StudcertificaatSQLDataSet->ParamByName("STUDIENR")->Value="00000000"; // Append the '%' sign to search for names like the one input in the box
        StudcertificaatSQLDataSet->Open();
        StudcertificaatClientDataSet->Active=true;

        Certificatenfaculteitstudent->OpslaanButton->Enabled = true;
          Certificatenfaculteitstudent->AfgifteDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
        //Faculteitstudent->InschrijfJaarDBEdit->ReadOnly = false;
}
//---------------------------------------------------------------------------

void __fastcall TCertificatenfaculteitstudent::OpslaanButtonClick(
      TObject *Sender)
{
   if (FModus == 1)  //insert
     { //Als de velden niet zijn ingevuld volgt een foutmelding waarna
       //de procedure verlaten wordt
     if (CertificaatComboBox->Text == "")
      {
         Application->MessageBox("U heeft geen certificaat gekozen", "Probeer het opnieuw", MB_OK);
         return;
      }
      else if (AfgifteDatumDBEdit->EditText == "")
      {
         Application->MessageBox("U heeft geen afgiftedatum ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
  //    StudcertificaatSQLDataSet->Close();
      OpslaanButton->Enabled = false;
      StudcertificaatSQLDataSet->CommandType = ctQuery;
      StudcertificaatSQLDataSet->CommandText = "INSERT INTO studentcertificaat (STUDIENR,\
      CERTIFICAAT_ID, AFGIFTEDATUM) VALUES (:STUDIENR,:CERTIFICAATID,:AFGIFTEDATUM)";
      StudcertificaatSQLDataSet->Params->Items[0]->AsString = Certificatenfaculteitstudent->StudieNRDBEdit->Text;
      StudcertificaatSQLDataSet->Params->Items[1]->AsString = Certificatenfaculteitstudent->CertificaatComboBox->KeyValue;
      StudcertificaatSQLDataSet->Params->Items[2]->AsDate = Certificatenfaculteitstudent->AfgifteDatumDBEdit->Text;
     }
   else if (FModus == 2)   //update
     {
     //Als er geen record in de set voorkomt kan er geen update plaatsvinden
     //De procedure wordt gewoon verlaten


     if (AfgifteDatumDBEdit->EditText == "")
      {
         Application->MessageBox("U heeft geen afgiftedatum ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
  //    StudcertificaatSQLDataSet->Close();
      StudcertificaatSQLDataSet->CommandType = ctQuery;
      StudcertificaatSQLDataSet->CommandText = "UPDATE STUDENTCERTIFICAAT SET AFGIFTEDATUM=:AFGIFTEDATUM \
      WHERE STUDIENR = :STUDIENR";
      StudcertificaatSQLDataSet->Params->Items[0]->AsDate = Certificatenfaculteitstudent->AfgifteDatumDBEdit->Text;
      StudcertificaatSQLDataSet->Params->Items[1]->AsString = Certificatenfaculteitstudent->StudieNRDBEdit->Text;
      }
      StudcertificaatSQLDataSet->ExecSQL();

      Certificatenfaculteitstudent->AfgifteDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";

}
//---------------------------------------------------------------------------

void __fastcall TCertificatenfaculteitstudent::VerwijderButtonClick(
      TObject *Sender)
{  //Als de recordset leeg is moet de procedure verlaten worden
   StudcertificaatSQLDataSet->CommandType = ctQuery;
   StudcertificaatSQLDataSet->CommandText = "DELETE FROM STUDENTCERTIFICAAT WHERE STUDIENR =   :STUDIENR \
   AND CERTIFICAATID = :CERTIFICAATID";
   StudcertificaatSQLDataSet->Params->Items[0]->AsString = StudieNRDBEdit->Text;
   StudcertificaatSQLDataSet->Params->Items[1]->AsString = CertificaatComboBox->KeyValue;
   StudcertificaatSQLDataSet->ExecSQL();
   Certificatenfaculteitstudent->AfgifteDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";

}
//---------------------------------------------------------------------------

void __fastcall TCertificatenfaculteitstudent::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  HoofdScherm->DiplomasCertificaten2->Checked = false;
  HoofdScherm->Show();
  Free();
}
//---------------------------------------------------------------------------

void __fastcall TCertificatenfaculteitstudent::PersoonDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
     //Als geen persoon opgegeven is mag je niet verder
    if ( IdCardDBEdit->Text == "") return;
    //nu moet gegaan worden naar het gekoppelde record in inschrijving
    sasDataModule->InschrijvingSQLDataSet->Close(); // Flush previous query
    sasDataModule->InschrijvingClientDataSet->Active=false; // Flush previous data in set
    sasDataModule->InschrijvingSQLDataSet->CommandText="select inschrijving.INSCHRIJFJAAR, inschrijving.* from inschrijving where IDKAARTNR = :IDKAARTNR ORDER BY inschrijving.INSCHRIJFJAAR DESC";
    sasDataModule->InschrijvingSQLDataSet->ParamByName("idkaartnr")->Value=LowerCase(Certificatenfaculteitstudent->IdCardDBEdit->Text);
    sasDataModule->InschrijvingSQLDataSet->Open();
    sasDataModule->InschrijvingClientDataSet->Active=true;
    //nu moet gegaan worden naar de gekoppelde recordset in studentcertificaat
    //Als deze leeg is mag niet verwijderd en gewijzigd worden
    //Dus opslaanbutton en verwijderbutton moeten disabled worden
    //anders moeten ze afhankeleijk van de modus enabled worden
    StudcertificaatSQLDataSet->Close(); // Flush previous query
    StudcertificaatClientDataSet->Active=false; // Flush previous data in set
    StudcertificaatSQLDataSet->CommandText="select * from studentcertificaat where STUDIENR = :STUDIENR";
    StudcertificaatSQLDataSet->ParamByName("STUDIENR")->Value= StudieNRDBEdit->Text; // Append the '%' sign to search for names like the one input in the box
    StudcertificaatSQLDataSet->Open();
    StudcertificaatClientDataSet->Active=true;
    Certificatenfaculteitstudent->AfstudeerDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
    Certificatenfaculteitstudent->AfgifteDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";

}
//---------------------------------------------------------------------------

void __fastcall TCertificatenfaculteitstudent::InschrijvingDBNavigatorClick(
      TObject *Sender, TNavigateBtn Button)
{
  //De dataset van studentcertificaat moet gevuld worden
   //Als deze leeg is mag niet verwijderd en gewijzigd worden
    //Dus opslaanbutton en verwijderbutton moeten disabled worden
    //anders moeten ze afhankeleijk van de modus enabled worden
    StudcertificaatSQLDataSet->Close(); // Flush previous query
    StudcertificaatClientDataSet->Active=false; // Flush previous data in set
    StudcertificaatSQLDataSet->CommandText="select * from studentcertificaat where STUDIENR = :STUDIENR";
    StudcertificaatSQLDataSet->ParamByName("STUDIENR")->Value= StudieNRDBEdit->Text; // Append the '%' sign to search for names like the one input in the box
    StudcertificaatSQLDataSet->Open();
    StudcertificaatClientDataSet->Active=true;
    Certificatenfaculteitstudent->AfgifteDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";

}
//---------------------------------------------------------------------------

void __fastcall TCertificatenfaculteitstudent::DiplomaButtonClick(
      TObject *Sender)
{

    if ((AfgestudeerdDBRadioGroup->Value == 1)&&(AfstudeerDatumDBEdit->EditText == ""))
      {
         Application->MessageBox("U heeft de afstudeerdatum niet ingevuld", "Probeer het opnieuw", MB_OK);
         return;
      }
    else if (AfgestudeerdDBRadioGroup->Value == 0)
       {
         //Nu moeten de velden afgestudeerd en afstudeerdatum gewijzigd worden
         // in de inschrijving tabel
         //afgestudeerd wordt false en afstudeerdatum null

        sasDataModule->InschrijvingSQLDataSet->CommandType = ctQuery;
        sasDataModule->InschrijvingSQLDataSet->CommandText = "UPDATE INSCHRIJVING \
        SET AFSTUDEERDATUM=NULL, AFGESTUDEERD=:AFGESTUDEERD WHERE STUDIENR =:STUDIENR";
        sasDataModule->InschrijvingSQLDataSet->Params->Items[0]->AsInteger = atoi(Certificatenfaculteitstudent->AfgestudeerdDBRadioGroup->Value.c_str());
        sasDataModule->InschrijvingSQLDataSet->Params->Items[1]->AsString = Certificatenfaculteitstudent->StudieNRDBEdit->Text;
       }
      else
       {
        //Nu moeten de velden afgestudeerd en afstudeerdatum gewijzigd worden
        // in de inschrijving tabel

        sasDataModule->InschrijvingSQLDataSet->CommandType = ctQuery;
        sasDataModule->InschrijvingSQLDataSet->CommandText = "UPDATE INSCHRIJVING \
        SET AFSTUDEERDATUM=:AFSTUDEERDATUM, AFGESTUDEERD=:AFGESTUDEERD WHERE STUDIENR =:STUDIENR";
        sasDataModule->InschrijvingSQLDataSet->Params->Items[0]->AsString = Certificatenfaculteitstudent->AfstudeerDatumDBEdit->Text;
        sasDataModule->InschrijvingSQLDataSet->Params->Items[1]->AsInteger = atoi(Certificatenfaculteitstudent->AfgestudeerdDBRadioGroup->Value.c_str());
        sasDataModule->InschrijvingSQLDataSet->Params->Items[2]->AsString = Certificatenfaculteitstudent->StudieNRDBEdit->Text;
       }
      sasDataModule->InschrijvingSQLDataSet->ExecSQL();
      Certificatenfaculteitstudent->AfstudeerDatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
}
//---------------------------------------------------------------------------




