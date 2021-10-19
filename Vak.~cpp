//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "constant.h"
#include "Vak.h"
#include "Main.h"
#include "sasdm.h"
#include "Sasfacdm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern int FModus;
static String studie;
TVakForm *VakForm;

//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{  //   Application->MessageBox("2", "",MB_OK);
   VakForm->FaculteitComboBox->ReadOnly=mode;
   VakForm->StudierichtingComboBox->ReadOnly=mode;
   VakForm->OrientatieComboBox->ReadOnly=mode;
   VakForm->NaamDBEdit->ReadOnly=mode;
   VakForm->CodeDBEdit->ReadOnly=mode;
   VakForm->PeriodeDBEdit->ReadOnly=mode;
   VakForm->CreditDBEdit->ReadOnly=mode;
   VakForm->SoortPeriodeListBox->ReadOnly=mode;
   VakForm->HCCheckBox->Enabled=!mode;
   VakForm->WCCheckBox->Enabled=!mode;
   VakForm->PRCheckBox->Enabled=!mode;
   VakForm->PPCheckBox->Enabled=!mode;
   VakForm->DECheckBox->Enabled=!mode;
   VakForm->ONCheckBox->Enabled=!mode;
   VakForm->PJCheckBox->Enabled=!mode;
   VakForm->PSCheckBox->Enabled=!mode;
   VakForm->ANCheckBox->Enabled=!mode;
   VakForm->WerkVormenGroupBox->Enabled=!mode;
   VakForm->DBAndersMemo->Enabled=!mode;

   VakForm->OmschrijvingDBRichEdit->ReadOnly=mode;
   VakForm->WerkVormenGroupBox->Enabled = !mode;
                                    //      Application->MessageBox("3", "",MB_OK);
}
//--------------------------------------------------------------------------

static void DoRead()
{
    /*VakForm->InschrijvingDBNavigator->Enabled = true;
    VakForm->NieuwButton->Enabled = false;
    VakForm->OpslaanButton->Enabled = false;
    VakForm->VerwijderButton->Enabled = false;
    VakForm->Label1->Enabled = false;
    VakForm->Label2->Show();
    VakForm->SearchEdit->Show();
    VakForm->SearchButton->Show();
    VakForm->ToggleButton->Show();
    VakForm->LastRecordsDBGrid->Show();
    VakForm->StudierichtingComboBox->Enabled = false;
    VakForm->FaculteitComboBox->Enabled = false;
    VakForm->IdCardDBEdit->ReadOnly = true;
    VakForm->InschrijvingDBNavigator->Visible = true;  */
    VakForm->SearchEdit->Visible = true;
    VakForm->SearchButton->Visible = true;
    VakForm->ToggleButton->Visible = true;
    VakForm->NieuwButton->Enabled = false;
    VakForm->OpslaanButton->Enabled = false;
    VakForm->VerwijderButton->Enabled = false;
    VakForm->VakDBNavigator->Enabled = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
  /*  VakForm->InschrijvingDBNavigator->Enabled = true;
    VakForm->NieuwButton->Enabled = false;
    VakForm->OpslaanButton->Enabled = false;
    VakForm->VerwijderButton->Enabled = true;
    VakForm->Label1->Enabled = false;
    VakForm->Label2->Show();
    VakForm->SearchEdit->Show();
    VakForm->SearchButton->Show();
    VakForm->ToggleButton->Show();
    VakForm->LastRecordsDBGrid->Show();
    VakForm->StudierichtingComboBox->Enabled = false;
    VakForm->FaculteitComboBox->Enabled = false;
    VakForm->IdCardDBEdit->ReadOnly = true;
    VakForm->InschrijvingDBNavigator->Visible = true;    */
    VakForm->SearchEdit->Visible = true;
    VakForm->SearchButton->Visible = true;
    VakForm->ToggleButton->Visible = true;
    VakForm->NieuwButton->Enabled = false;
    VakForm->OpslaanButton->Enabled = false;
    VakForm->VerwijderButton->Enabled = true;
    VakForm->VakDBNavigator->Enabled = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
    VakForm->SearchEdit->Visible = true;
    VakForm->SearchButton->Visible = true;
    VakForm->ToggleButton->Visible = true;
    VakForm->NieuwButton->Enabled= false;
    VakForm->OpslaanButton->Enabled = true;
    VakForm->VerwijderButton->Enabled = false;
   /* VakForm->InschrijvingDBNavigator->Enabled = true;
    VakForm->NieuwButton->Enabled = false;
    VakForm->OpslaanButton->Enabled = true;
    VakForm->VerwijderButton->Enabled = false;
    VakForm->Label2->Show();
    VakForm->Label1->Enabled = false;
    VakForm->SearchEdit->Show();
    VakForm->SearchButton->Show();
    VakForm->ToggleButton->Show();
    VakForm->LastRecordsDBGrid->Show();
    VakForm->StudierichtingComboBox->Enabled = false;
    VakForm->FaculteitComboBox->Enabled = false;
    VakForm->IdCardDBEdit->ReadOnly = false;
    VakForm->InschrijvingDBNavigator->Visible = true; */
    VakForm->VakDBNavigator->Enabled = true;
    SetReadModus(false);
}
//---------------------------------------------------------------------------

static void  DoInsert()
{
   // VakForm->InschrijvingDBNavigator->Enabled = true;
  //  VakForm->NieuwButton->Enabled = true;
  //  VakForm->OpslaanButton->Enabled = false;
    VakForm->SearchEdit->Visible = false;
    VakForm->SearchButton->Visible = false;
    VakForm->ToggleButton->Visible = false;
    VakForm->NieuwButton->Enabled = true;
    VakForm->OpslaanButton->Enabled = true;
    VakForm->VerwijderButton->Enabled = false;
   // VakForm->SearchEdit->Hide();
   // VakForm->SearchButton->Hide();
   // VakForm->ToggleButton->Hide();
   VakForm->VakDBNavigator->Enabled = false;
    SetReadModus(false);
}

//---------------------------------------------------------------------------
__fastcall TVakForm::TVakForm(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TVakForm::FormClose(TObject *Sender, TCloseAction &Action)
{
   // HoofdScherm->Vakken2->Checked = False;
}
//---------------------------------------------------------------------------
void __fastcall TVakForm::Close1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TVakForm::Exit1Click(TObject *Sender)
{
  VakForm->Close();
  HoofdScherm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TVakForm::FaculteitComboBoxClick(TObject *Sender)
{
   if (VakForm->FaculteitComboBox->Text != "")
      {
       char  buf[20];
       char *a;
       Variant b;
        a = itoa(FaculteitComboBox->KeyValue,buf,10);

        VakForm->StudierichtingComboBox->Enabled = true;
        sasDataModule->StudierichtingSQLDataSet->Close(); // Flush previous query
        sasDataModule->StudierichtingClientDataSet->Active=false; // Flush previous data in set
        sasDataModule->StudierichtingSQLDataSet->CommandText = "select * from studierichting where faculteit_id = :faculteit_id and RICHTING_ID not like :RICHTING_ID";
        b =  VakForm->FaculteitComboBox->KeyValue; // Application->MessageBox("2", buf,MB_OK);
        sasDataModule->StudierichtingSQLDataSet->ParamByName("faculteit_id")->Value = b;
        sasDataModule->StudierichtingSQLDataSet->ParamByName("RICHTING_ID")->Value = "MP"; //Application->MessageBox("3", buf,MB_OK);
        sasDataModule->StudierichtingSQLDataSet->Open();
        sasDataModule->StudierichtingClientDataSet->Active = true;
 //       Application->MessageBox("4", buf,MB_OK);
     }
}
//---------------------------------------------------------------------------

void __fastcall TVakForm::FormActivate(TObject *Sender)
{

//Application->MessageBox("1", "",MB_OK);
switch (FModus)
    {
   case READ: ModusLabel->Font->Color = clNavy ;ModusLabel->Caption = "Vakgegevens opvragen"; DoRead();break;//lezen
   case ENTRY: ModusLabel->Font->Color = clNavy ;ModusLabel->Caption = "Vak toevoegen";DoInsert();break;//toevoegen
   case EDIT: ModusLabel->Font->Color = clNavy ;ModusLabel->Caption = "Vakgegevens wijzigen";DoUpdate();break;//wijzigen
   case DEL: ModusLabel->Font->Color = clRed ;ModusLabel->Caption = "Vak verwijderen";DoDelete(); break;//verwijderen
     }


  sasDataModule->FaculteitSQLDataSet->Active = true;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  sasDataModule->FaculteitClientDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;
  SasFaculteitData->vakSQLDataSet->Active = true;
  SasFaculteitData->vakClientDataSet->Active = true;
  switch ( FModus )
  {
  case  READ: DoRead();  VakForm->VakDBNavigator->VisibleButtons = TButtonSet() << nbFirst <<nbPrior <<nbNext <<nbLast; break;
  case  ENTRY: DoInsert();  VakForm->VakDBNavigator->VisibleButtons = TButtonSet()<< nbFirst <<nbPrior <<nbNext <<nbLast; break;
  case  EDIT: DoUpdate();  VakForm->VakDBNavigator->VisibleButtons = TButtonSet() << nbFirst <<nbPrior <<nbNext <<nbLast; break;
  case  DEL: DoDelete();  VakForm->VakDBNavigator->VisibleButtons = TButtonSet() << nbFirst <<nbPrior <<nbNext <<nbLast; break;
  }

/*   if (usergroup == "IGSR_ADMINISTRATIE")
    {
      ExtraPanel->Visible = true;
      sasDataModule->InschrijvingClientDataSet->Filter = "FACULTEIT_ID = 4";
      sasDataModule->InschrijvingClientDataSet->Filtered = true;
    }
   else
    {
      ExtraPanel->Visible = false;
      sasDataModule->InschrijvingClientDataSet->Filter = "FACULTEIT_ID <> 4";
      sasDataModule->InschrijvingClientDataSet->Filtered = true; */
  //    Application->MessageBox("11", "",MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TVakForm::Button1Click(TObject *Sender)
{
 FontDialog1->Execute();
 OmschrijvingDBRichEdit->SelAttributes->Name = FontDialog1->Font->Name;

 OmschrijvingDBRichEdit->SelAttributes->Size = FontDialog1->Font->Size;
 OmschrijvingDBRichEdit->SelAttributes->Color = FontDialog1->Font->Color;
}
//---------------------------------------------------------------------------

void __fastcall TVakForm::StudierichtingComboBoxClick(TObject *Sender)
{
 char  buf[20];
       char *a;
       Variant b;
    switch( FModus)
      {
     case READ: break;

     case ENTRY:
      /*  SasFaculteitData->vakSQLDataSet->Close();
        SasFaculteitData->vakClientDataSet->Active = false;

        SasFaculteitData->vakSQLDataSet->CommandText = "select * from vak where where FACULTEIT_ID =:faculteit_id and RICHTING_ID =:RICHTING_ID";
        SasFaculteitData->vakSQLDataSet->ParamByName("faculteit_id")->Value = VakForm->FaculteitComboBox->KeyValue ;
        SasFaculteitData->vakSQLDataSet->ParamByName("RICHTING_ID")->Value = VakForm->StudierichtingComboBox->KeyValue ;
        SasFaculteitData->vakSQLDataSet->Open();
        SasFaculteitData->vakClientDataSet->Active = true; break;  */


        studie = StudierichtingComboBox->Text;

       // a = itoa(StudierichtingComboBox->KeyValue,buf,10);

       // VakForm->OrientatieComboBox->Enabled = true;
       // sasDataModule->OrientatieSQLDataSet->Close(); // Flush previous query
       // sasDataModule->OrientatieClientDataSet->Active=false; // Flush previous data in set
       // sasDataModule->OrientatieSQLDataSet->CommandText = "select * from Orientatie where STUDIERICHTING_ID =:studierichting_id";// and OR_ID not like :orientatie_id";
       // b =  VakForm->StudierichtingComboBox->KeyValue;
   //    Application->MessageBox("2", buf,MB_OK);
      //  sasDataModule->OrientatieSQLDataSet->ParamByName("studierichting_id")->Value = VakForm->StudierichtingComboBox->KeyValue;
      //  sasDataModule->OrientatieSQLDataSet->ParamByName("RICHTING_ID")->Value = "MP"; Application->MessageBox("3", buf,MB_OK);

     //   sasDataModule->OrientatieSQLDataSet->Open();
     //   sasDataModule->OrientatieClientDataSet->Active = true;
  //      Application->MessageBox("4", buf,MB_OK);  break;
     case EDIT: break;
     case DEL:;
       }
        /*if  (Faculteitstudent->FaculteitComboBox->Text != "IGSR")
            ExtraPanel->Visible = false;
        else
            ExtraPanel->Visible = true;*/
     //   Label12->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TVakForm::VakDBNavigatorClick(TObject *Sender,
      TNavigateBtn Button)
{
 /* if (Button == nbInsert)
  {
      //SasFaculteitData->vakDataSource->
     //opslaan

   //   SasFaculteitData->vakSQLDataSet->FieldValues["VAK_ID"] = 2;
    }
    if (Button == nbPost)
    {
    SasFaculteitData->vakSQLDataSet->Close();
    SasFaculteitData->vakSQLDataSet->CommandType = ctQuery;

                   //
                   //
         SasFaculteitData->vakSQLDataSet->CommandText = "INSERT INTO VAK (FACULTEIT, STUDIERICHTING,VAK_NAAM,VAK_CODE,VAK_OMSCHRIJVING,PERIODE\
          ,CREDITPOINTS,ORIENTATIE, SOORT_PERIODE)\
VALUES(:FACULTEIT,:STUDIERICHTING,:VAK_NAAM,:VAK_CODE,:VAK_OMSCHRIJVING,:PERIODE,:CREDITPOINTS,:ORIENTATIE,:SOORT_PERIODE)";
      SasFaculteitData->vakSQLDataSet->Params->Items[0]->AsString = VakForm->FaculteitComboBox->KeyValue;
      SasFaculteitData->vakSQLDataSet->Params->Items[1]->AsString = VakForm->StudierichtingComboBox->KeyValue;
      SasFaculteitData->vakSQLDataSet->Params->Items[2]->AsString = VakForm->NaamDBEdit->Text;
      SasFaculteitData->vakSQLDataSet->Params->Items[3]->AsString = VakForm->CodeDBEdit->Text ;
      SasFaculteitData->vakSQLDataSet->Params->Items[4]->AsString = OmschrijvingDBRichEdit->Text;
      SasFaculteitData->vakSQLDataSet->Params->Items[5]->AsString = atoi((PeriodeDBEdit->Text).c_str());
      SasFaculteitData->vakSQLDataSet->Params->Items[6]->AsString = atoi((CreditDBEdit->Text).c_str());
      SasFaculteitData->vakSQLDataSet->Params->Items[7]->AsString = OrientatieComboBox->KeyValue;
      SasFaculteitData->vakSQLDataSet->Params->Items[8]->AsString = SoortPeriodeListBox->Items->Strings[SoortPeriodeListBox->ItemIndex];
 //     SasFaculteitData->vakSQLDataSet->Params->Items[8]->AsString =
 //     SasFaculteitData->vakSQLDataSet->Params->Items[9]->AsString =
 //     SasFaculteitData->vakSQLDataSet->Params->Items[10]->AsString =
 //     SasFaculteitData->vakSQLDataSet->Params->Items[11]->AsString =

      SasFaculteitData->vakSQLDataSet->ExecSQL();

   }

                     */
}
//---------------------------------------------------------------------------




void __fastcall TVakForm::SearchButtonClick(TObject *Sender)
{
    // Check if the connection is already established
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
        sasDataModule->sasSQLConnection->Connected=true;
     }
   SasFaculteitData->vakClientDataSet->Filtered = true;
 //  sasDataModule->personSQLDataSet->Close(); // Flush previous query
   SasFaculteitData->vakClientDataSet->Active=false; // Flush previous data in set
   if (VakForm->ToggleButton->Caption == "op studierichting")
     {
     SasFaculteitData->vakClientDataSet->Filter =   String("RICHTING_ID like ") + String("'") + VakForm->SearchEdit->Text + String("%'");
     }
   else
     {
       SasFaculteitData->vakClientDataSet->Filter = String("VAK_NAAM like ") + String("'") + VakForm->SearchEdit->Text + String("%'");
     }
   SasFaculteitData->vakClientDataSet->Active=true;
//  last->Text= String(sasDataModule->personClientDataSet->RecordCount);
//  first->Text= String(sasDataModule->personClientDataSet->RecNo);
}
//---------------------------------------------------------------------------

void __fastcall TVakForm::ToggleButtonClick(TObject *Sender)
{
 if (VakForm->ToggleButton->Caption == "op studierichting")
      VakForm->ToggleButton->Caption = "op naam";
  else
      VakForm->ToggleButton->Caption = "op studierichting";
}
//---------------------------------------------------------------------------

void __fastcall TVakForm::NieuwButtonClick(TObject *Sender)
{
      SasFaculteitData->vakSQLDataSet->Active=false; // Flush previous data in set
      SasFaculteitData->vakClientDataSet->Active=false;
      SasFaculteitData->vakSQLDataSet->CommandText= String( "SELECT * FROM vak WHERE VAK_NAAM like ") + "123456";
      SasFaculteitData->vakSQLDataSet->Active = true;
      SasFaculteitData->vakClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TVakForm::OpslaanButtonClick(TObject *Sender)
{
      SasFaculteitData->vakSQLDataSet->Close();
      SasFaculteitData->vakSQLDataSet->CommandType = ctQuery;


    SasFaculteitData->vakSQLDataSet->CommandText = "INSERT INTO VAK (FACULTEIT_ID, RICHTING_ID,VAK_NAAM,VAK_CODE,VAK_OMSCHRIJVING,PERIODE\
          ,CREDITPOINTS,ORIENTATIE, SOORTPERIODE)\
       VALUES(:FACULTEIT,:STUDIERICHTING,:VAK_NAAM,:VAK_CODE,:VAK_OMSCHRIJVING,:PERIODE,:CREDITPOINTS,:ORIENTATIE,:SOORT_PERIODE)";
      SasFaculteitData->vakSQLDataSet->Params->Items[0]->AsString = VakForm->FaculteitComboBox->KeyValue;
      SasFaculteitData->vakSQLDataSet->Params->Items[1]->AsString = VakForm->StudierichtingComboBox->KeyValue;
      SasFaculteitData->vakSQLDataSet->Params->Items[2]->AsString = VakForm->NaamDBEdit->Text;
      SasFaculteitData->vakSQLDataSet->Params->Items[3]->AsString = VakForm->CodeDBEdit->Text ;
      SasFaculteitData->vakSQLDataSet->Params->Items[4]->AsString = OmschrijvingDBRichEdit->Text;
      SasFaculteitData->vakSQLDataSet->Params->Items[5]->AsString = atoi((PeriodeDBEdit->Text).c_str());
      SasFaculteitData->vakSQLDataSet->Params->Items[6]->AsString = atoi((CreditDBEdit->Text).c_str());
      SasFaculteitData->vakSQLDataSet->Params->Items[7]->AsString = OrientatieComboBox->KeyValue;
      SasFaculteitData->vakSQLDataSet->Params->Items[8]->AsString = SoortPeriodeListBox->Items->Strings[SoortPeriodeListBox->ItemIndex];
 //     SasFaculteitData->vakSQLDataSet->Params->Items[8]->AsString =
 //     SasFaculteitData->vakSQLDataSet->Params->Items[9]->AsString =
 //     SasFaculteitData->vakSQLDataSet->Params->Items[10]->AsString =
 //     SasFaculteitData->vakSQLDataSet->Params->Items[11]->AsString =

      SasFaculteitData->vakSQLDataSet->ExecSQL();
}
//---------------------------------------------------------------------------



