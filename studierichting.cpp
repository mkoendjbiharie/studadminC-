//---------------------------------------------------------------------------

#include <vcl.h>
//#include "main.h"
#include "constant.h"
#include "studierichting.h"
#include "sasdm.h"
//#include "Sasfacdm.h"
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Word_2K_SRVR"
#pragma link "Word_97_SRVR"
#pragma resource "*.dfm"
extern int FModus;
TStudierichtingForm *StudierichtingForm;
//---------------------------------------------------------------------------
static void SetReadModus(bool mode)
{
   /*
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
                PersonForm->WerkTelefoonDBEdit->ReadOnly=mode; */
}

//---------------------------------------------------------------------------

static void DoRead()
{
/* PersonForm->DBNavigator1->Enabled = true;
    PersonForm->NieuwButton->Enabled = false;
    PersonForm->OpslaanButton->Enabled = false;
    PersonForm->VerwijderButton->Enabled = false;
    PersonForm->SearchEdit->Show();
    PersonForm->SearchButton->Show();
    PersonForm->ToggleButton->Show();
    PersonForm->LastRecordsDBGrid->Show();*/
    SetReadModus(true);
}

//---------------------------------------------------------------------------
static void DoUpdate()
{
 /*PersonForm->DBNavigator1->Enabled = true;
    PersonForm->NieuwButton->Enabled = false;
    PersonForm->OpslaanButton->Enabled = true;
    PersonForm->VerwijderButton->Enabled = false;
    PersonForm->SearchEdit->Show();
    PersonForm->SearchButton->Show();
    PersonForm->ToggleButton->Show();
    PersonForm->LastRecordsDBGrid->Show(); */
    SetReadModus(false);
//    PersonForm->IdCardDBEdit->ReadOnly = true;
   // PersonForm->MarriedNameDBEdit->Enabled = false;
}
//---------------------------------------------------------------------------

__fastcall TStudierichtingForm::TStudierichtingForm(TComponent* Owner)
        : TForm(Owner)
{
  sasDataModule->FaculteitSQLDataSet->Active = true;
  sasDataModule->StudierichtingSQLDataSet->Active = true;
  sasDataModule->FaculteitClientDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;
    sasDataModule->StudierichtingClientDataSetdummy->Active = true;
 // sasDataModule->FaculteitClientDataSet->Active = true;
  sasDataModule->StudierichtingClientDataSet->Active = true;

  Show();
}

//---------------------------------------------------------------------------


void __fastcall TStudierichtingForm::BitBtn1Click(TObject *Sender)
{
/*TVariant FileName = "c:/test.doc";
WordApplication1->Connect();
WordApplication1->set_Visible(1);
TVariant par2 = 0;
TVariant readonly = 1;
WordApplication1->Documents->Open(&FileName,par2,readonly); */
}
//---------------------------------------------------------------------------


void __fastcall TStudierichtingForm::FaculteitComboBoxClick(
      TObject *Sender)
{
   String fac;
   fac = StudierichtingForm->FaculteitComboBox->KeyValue;
   if (StudierichtingForm->FaculteitComboBox->Text != "")
     {
   // Application->MessageBox("","faculteitclick",MB_OK);
      //  StudierichtingForm->StudierichtingComboBox->Enabled = true;
        sasDataModule->StudierichtingSQLDataSet->Close(); // Flush previous query
        sasDataModule->StudierichtingClientDataSet->Active=false; // Flush previous data in set
         sasDataModule->StudierichtingClientDataSetdummy->Active=false;
        sasDataModule->StudierichtingSQLDataSet->CommandText = "select * from studierichting where faculteit_id = :faculteit_id";// and RICHTING_ID not like :RICHTING_ID";
        sasDataModule->StudierichtingSQLDataSet->ParamByName("faculteit_id")->Value = fac;
//        sasDataModule->StudierichtingSQLDataSet->ParamByName("RICHTING_ID")->Value = "MP";
    //     sasDataModule->StudierichtingSQLDataSet->ParamByName("RICHTING_ID")->Value = "MP";
        sasDataModule->StudierichtingSQLDataSet->Open();
        sasDataModule->StudierichtingClientDataSet->Active=true;
          sasDataModule->StudierichtingClientDataSetdummy->Active=true;
        Label12->Enabled = true;

    //    if  (StudierichtingForm->FaculteitComboBox->Text != "IGSR")
   //         ExtraPanel->Visible = false;
   //     else
   //         ExtraPanel->Visible = true;
   // Nu gaan we na of de student eerder was ingeschreven. Alle inschrijvingen worden
   // getoond in een grid.

     }
}
//---------------------------------------------------------------------------



/*
This example dynamically creates a Page Control, then a series of Tab Sheets on the Page Control.

#include <Comctrls.hpp>
TPageControl* ppc;
TTabSheet* pts[MAXTABS];
const char * ppcTabTitles[] = { "ShortString", "Orders", "Items", "Parts" };
int iTabTitles = sizeof(ppcTabTitles)/sizeof(ppcTabTitles[0]);

void __fastcall TForm1::FormCreate(TObject *Sender)

{
	ppc = new TPageControl(this);
	ppc->Parent = this;
	ppc->Align = alClient;
	for (int i=0;i<iTabTitles;i++)
  {
		pts[i] = new TTabSheet(this);
		pts[i]->PageControl = ppc;
		pts[i]->Name = AnsiString("pts") + ppcTabTitles[i];
        pts[i]->Caption = ppcTabTitles[i];
  }
}

void __fastcall TForm1::FormDestroy(TObject *Sender)

{
  for (int i=0;i<iTabTitles;i++)
    	delete pts[i];
	delete ppc;
}



*/




void __fastcall TStudierichtingForm::FormActivate(TObject *Sender)
{
switch (FModus)
    {
   case READ: ModusLabel->Font->Color = clNavy ;ModusLabel->Caption = "Richtinggegevens opvragen"; DoRead();break;//lezen
   case EDIT: ModusLabel->Font->Color = clNavy ;ModusLabel->Caption = "Richtingegevens wijzigen";DoUpdate();break;//wijzigen
     }
}
//---------------------------------------------------------------------------


void __fastcall TStudierichtingForm::StudierichtingComboBoxClick(
      TObject *Sender)
{
  String rich;
  rich = StudierichtingForm->StudierichtingComboBox->KeyValue;
 /*
         SasFaculteitData->vakSQLDataSet->Close(); // Flush previous query
        SasFaculteitData->vakClientDataSet->Active=false; // Flush previous data in set
 //        SasFaculteitData->vakClientDataSetdummy->Active=false;
        SasFaculteitData->vakSQLDataSet->CommandText = "select * from vak where richting_id = :richting_id";// and RICHTING_ID not like :RICHTING_ID";
        SasFaculteitData->vakSQLDataSet->ParamByName("richting_id")->Value = rich;
          SasFaculteitData->vakSQLDataSet->Open(); // Flush previous query
        SasFaculteitData->vakClientDataSet->Active=true; // Flush previous data in set
 */
}
//---------------------------------------------------------------------------

