//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tentamen.h"
#include "sasdm.h"
#include "Sasfacdm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TTentamenForm *TentamenForm;
static int Modus;
static bool datasetactive;
//---------------------------------------------------------------------------

static void SetReadModus(bool mode)
{
   TentamenForm->ZaalDBEdit->ReadOnly=mode;
   TentamenForm->GebouwDBEdit->ReadOnly=mode;
   TentamenForm->TijdDBEdit->ReadOnly=mode;
   TentamenForm->StudiejaarDBEdit->ReadOnly=mode;
   TentamenForm->DeelTentamenDBEdit->ReadOnly=mode;
   TentamenForm->DatumDBEdit->ReadOnly=mode;
}

//--------------------------------------------------------------------------

static void DoRead()
{
    TentamenForm->VakDBNavigator->Enabled = true;
    TentamenForm->NieuwButton->Enabled = false;
    TentamenForm->OpslaanButton->Enabled = false;
    TentamenForm->VerwijderButton->Enabled = false;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoDelete()
{
    TentamenForm->TentamenDBNavigator->Enabled = true;
    TentamenForm->NieuwButton->Enabled = false;
    TentamenForm->OpslaanButton->Enabled = false;
    TentamenForm->VerwijderButton->Enabled = true;
    SetReadModus(true);
}
//----------------------------------------------------------------------------

static void DoUpdate()
{
//    TentamenForm->FaculteitComboBox->Enabled = true;
//    TentamenForm->StudierichtingComboBox->Enabled = true;
    TentamenForm->TentamenDBNavigator->Enabled = true;
    TentamenForm->NieuwButton->Enabled = false;
    TentamenForm->OpslaanButton->Enabled = true;
    TentamenForm->VerwijderButton->Enabled = false;
    SetReadModus(false);
}

//----------------------------------------------------------------------------
static void  DoInsert()
{
    TentamenForm->TentamenDBNavigator->Enabled = false;
    TentamenForm->VakDBNavigator->Enabled = true;
    TentamenForm->NieuwButton->Enabled = true;
    TentamenForm->OpslaanButton->Enabled = false;
    TentamenForm->VerwijderButton->Enabled = false;
    SetReadModus(false);
}

//---------------------------------------------------------------------------
__fastcall TTentamenForm::TTentamenForm(TComponent* Owner)
        : TForm(Owner)
{
   sasDataModule->docentSQLDataSet->Active = true;
   sasDataModule->vakSQLDataSet->Active = true;
   sasDataModule->FaculteitSQLDataSet->Active = true;
   sasDataModule->StudierichtingSQLDataSet->Active = true;
   sasDataModule->docentbetrekkingSQLDataSet->Active = true;
   tentamenSQLDataSet->Active = true;

   personClientDataSet->Active = true;
   vakClientDataSet->Active = true;
   docentbetrekkingClientDataSet->Active = true;
   studierichtingClientDataSet->Active = true;
   faculteitClientDataSet->Active = true;
   tentamenClientDataSet->Active = true;
   datasetactive = false;
   DatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
   StudiejaarDBEdit->Field->EditMask = "!0000\-0000;1;_";
   TijdDBEdit->Field->EditMask = "!00:00;1;_";



}
//---------------------------------------------------------------------------

void __fastcall TTentamenForm::ToggleButtonClick(TObject *Sender)
{
  if (TentamenForm->ToggleButton->Caption == "op studierichting")
   {
     TentamenForm->ToggleButton->Caption = "op docentnaam";
    // TentamenForm->DocentLookupComboBox->Visible = true;
     TentamenForm->DocentLookupComboBox->BringToFront();
   //  TentamenForm->DocentLookupComboBox->Enabled = true;
   }
  else if(TentamenForm->ToggleButton->Caption == "op docentnaam")
   {
     TentamenForm->ToggleButton->Caption = "op vaknaam";
   //  TentamenForm->VakLookupComboBox->Visible = true;
     TentamenForm->VakLookupComboBox->BringToFront();
   //  TentamenForm->VakLookupComboBox->Enabled = true;
   }
  else
   {
      TentamenForm->ToggleButton->Caption = "op studierichting";
  //    TentamenForm->StudierichtingLookupComboBox->Visible = true;
      TentamenForm->StudierichtingLookupComboBox->BringToFront();
  //    TentamenForm->StudierichtingLookupComboBox->Enabled = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TTentamenForm::ModusKnopClick(TObject *Sender)
{
   Modus = (++Modus)%4;
   switch (Modus)
    {
   case 0: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Lezen"; DoRead();break;//lezen
   case 1: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Toevoegen";DoInsert();break;//toevoegen
   case 2: ModusKnop->Font->Color = clNavy ;ModusKnop->Caption = "Wijzigen";DoUpdate();break;//toevoegen
   case 3: ModusKnop->Font->Color = clRed ;ModusKnop->Caption = "Verwijderen";DoDelete();//verwijderen
    };
}
//---------------------------------------------------------------------------

void __fastcall TTentamenForm::SearchButtonClick(TObject *Sender)
{
   bool isfilter;
   isfilter = false;
   AnsiString filter;
   first1->Text = "";
   last1->Text = "";
   if (datasetactive == false)
     {
       //personClientDataSet->Active = true;
       //vakClientDataSet->Active = true;
       //docentbetrekkingClientDataSet->Active = true;
       //studierichtingClientDataSet->Active = true;
       //faculteitClientDataSet->Active = true;
       DocentNaamDBEdit->DataField = "naam";
       DocentVoorNaamDBEdit->DataField = "voornaam";
       VakCodeDBEdit->DataField = "VAK_CODE";
       VakNaamDBEdit->DataField = "VAK_NAAM";
       FaculteitDBEdit->DataField = "faculteit";
       StudierichtingDBEdit->DataField = "STUDIERICHTING";
       datasetactive = true;
     }
   personClientDataSet->Filtered = true;
   if (sasDataModule->sasSQLConnection->Connected!=true)
     {
        sasDataModule->sasSQLConnection->Connected=true;
     }
   if (ToggleButton->Caption == "op studierichting")
     {
     //Nu moeten we alle vakken zoeken die bij deze studierichting horen
      if  (StudierichtingLookupComboBox->Text == "") return;
     studierichtingClientDataSet->Active = false;
     studierichtingClientDataSet->Filtered = false;
     studierichtingClientDataSet->Active = true;
     vakClientDataSet->Active = false;
     vakClientDataSet->Filtered = false;
    if (PeriodeEdit->Text != "")
       filter = String("RICHTING_ID = '") + StudierichtingLookupComboBox->KeyValue + "'" + " AND periode = " + "'" + String(atoi(PeriodeEdit->Text.c_str())) + "'";
 //     Application->MessageBoxA(filter.c_str(),"",MB_OK);
    else
       filter = String("RICHTING_ID = '") + StudierichtingLookupComboBox->KeyValue + "'" ;

     vakClientDataSet->Filter = filter;
     Application->MessageBoxA(filter.c_str(),"searchbutton op studierichting 1",MB_OK);
     vakClientDataSet->Filtered = true;
     vakClientDataSet->Active = true;
     //We moeten nu de docent zoeken die het vak in het huidige record geeft
     // We nemen vak_id en zoeken in docentvak docent_id op
     // docentbetrekking levert dit op
     personClientDataSet->Active = false;
     personClientDataSet->Filtered = false;

     filter = String("VAK_ID = '") + VakIDDBEdit->Text + "'";
     personClientDataSet->Filter = filter;
     Application->MessageBoxA(filter.c_str(),"searchbutton op studierichting 2",MB_OK);
     personClientDataSet->Filtered = true;
     personClientDataSet->Active = true;

     }
    else if (ToggleButton->Caption == "op docentnaam")
     {
      if  (DocentLookupComboBox->Text == "") return;
     //Nu moeten we alle vakken zoeken die bij deze docent horen
     //Keyfield van de lookupcombobox is docent_id
     //De richting vinden we uit de betrekking van de docent
     vakClientDataSet->Active = false;
     vakClientDataSet->Filtered = false;
    if (PeriodeEdit->Text == "")
     filter = String("DOCENT_ID = '") + DocentIDDBEdit->Text + "'";
    else
     filter = String("DOCENT_ID = '") + DocentIDDBEdit->Text + "'" + " AND periode = " + "'" + String(atoi(PeriodeEdit->Text.c_str())) + "'";

     vakClientDataSet->Filter = filter;
     Application->MessageBoxA(filter.c_str(),"searchbutton op docentnaam",MB_OK);
     vakClientDataSet->Filtered = true;
     vakClientDataSet->Active = true;
     studierichtingClientDataSet->Active = false;
     studierichtingClientDataSet->Filtered = false;
     studierichtingClientDataSet->Active = true;
     }
    else //op vaknaam
     {

     if  (VakLookupComboBox->Text == "") return;
     // We zoeken in docentvak naar de docent_id

     // Daarna vinden we de gegevens van de docent uit docentbetrekking
      personClientDataSet->Active = false;
     personClientDataSet->Filtered = false;
    if (PeriodeEdit->Text == "")
      filter = String("VAK_ID = '") + VakIDDBEdit->Text + "'";
 //   else
 //      filter = String("VAK_ID = '") + VakIDDBEdit->Text + "'"  + " AND periode = " + "'" + String(atoi(PeriodeEdit->Text.c_str())) + "'";

     personClientDataSet->Filter = filter;
 //    Application->MessageBoxA(filter.c_str(),"",MB_OK);
     personClientDataSet->Filtered = true;
     personClientDataSet->Active = true;

     studierichtingClientDataSet->Active = false;
     studierichtingClientDataSet->Filtered = false;

     filter = String("VAK_ID = '") + VakIDDBEdit->Text + "'";
     studierichtingClientDataSet->Filter = filter;
 //    Application->MessageBoxA(filter.c_str(),"",MB_OK);
     studierichtingClientDataSet->Filtered = true;
     studierichtingClientDataSet->Active = true;
     }
  last1->Text= String(vakClientDataSet->RecordCount);
  first1->Text= String(vakClientDataSet->RecNo);
  last->Text= String(tentamenClientDataSet->RecordCount);
  first->Text= String(tentamenClientDataSet->RecNo);
}
//---------------------------------------------------------------------------

void __fastcall TTentamenForm::VakDBNavigatorClick(TObject *Sender,
      TNavigateBtn Button)
{
 // last1->Text= String(vakClientDataSet->RecordCount);
  first1->Text= String(vakClientDataSet->RecNo);

 //Als op docentnaam gezocht wordt
 //moet de richting van de docent gezocht worden
   if(ToggleButton->Caption == "op docentnaam")
      {

      }
 //als op richting moet
 //de docent gezocht worden bij dit vak
   else if  (ToggleButton->Caption == "op studierichting")
         {
           AnsiString filter;
           personClientDataSet->Active = false;
           personClientDataSet->Filtered = false;

           filter = String("VAK_ID = '") + VakIDDBEdit->Text + "'";
           personClientDataSet->Filter = filter;
           Application->MessageBoxA(filter.c_str(),"",MB_OK);
           personClientDataSet->Filtered = true;
           personClientDataSet->Active = true;
         }
  //als op vaknaam
  //er hoeft niets te gebeuren omdat er maar een vak is dus maar een docent en ook
  //een richting
}
//---------------------------------------------------------------------------

void __fastcall TTentamenForm::NieuwButtonClick(TObject *Sender)
{
  if (sasDataModule->sasSQLConnection->Connected!=true)
        {
                sasDataModule->sasSQLConnection->Connected=true;
        }
  tentamenClientDataSet->Active=false; // Flush previous data in set
 //   Application->MessageBoxA("12","",MB_OK);
  tentamenClientDataSet->Filtered = true;
  tentamenClientDataSet->Filter= String("  GEBOUW = ") + "'" +  "0" + "'";
  tentamenClientDataSet->Active = true;
  TentamenForm->OpslaanButton->Enabled = true;
  DatumDBEdit->Field->EditMask = "!0000/00/00;1;_";
  StudiejaarDBEdit->Field->EditMask = "!0000\-0000;1;_";
  TijdDBEdit->Field->EditMask = "!00:00;1;_";
}
//---------------------------------------------------------------------------

void __fastcall TTentamenForm::OpslaanButtonClick(TObject *Sender)
{
Variant leeg = NULL;
  char buf[5];

  if (Modus == 1) //toevoegen
    {
    if (TentamenForm->VakCodeDBEdit->Text == "")
      {
         Application->MessageBox("U moet eerst een vak selecteren", "Probeer het opnieuw", MB_OK);
         return;
      }
      tentamenSQLDataSet->CommandText = "INSERT INTO TENTAMEN (DATUM,TIJD,STUDIEJAAR,DEELTENTAMEN,GEBOUW,ZAAL,VAK_ID)"
                                                                  "VALUES(:DATUM,:TIJD, :STUDIEJAAR,:DEELTENTAMEN,:GEBOUW,:ZAAL,:VAK_ID)";
      tentamenSQLDataSet->Params->Items[0]->AsString = TentamenForm->DatumDBEdit->Text;
      tentamenSQLDataSet->Params->Items[1]->AsString = TentamenForm->TijdDBEdit->Text;
      tentamenSQLDataSet->Params->Items[2]->AsString = TentamenForm->StudiejaarDBEdit->Text;
      tentamenSQLDataSet->Params->Items[3]->AsString = TentamenForm->DeelTentamenDBEdit->Text;
      tentamenSQLDataSet->Params->Items[4]->AsString = TentamenForm->GebouwDBEdit->Text;
      tentamenSQLDataSet->Params->Items[5]->AsString = TentamenForm->ZaalDBEdit->Text;
      tentamenSQLDataSet->Params->Items[6]->AsString = TentamenForm->VakIDDBEdit->Text;

      tentamenClientDataSet->Close();
      tentamenSQLDataSet->Close();
  try
   {
      tentamenSQLDataSet->ExecSQL();
   }
  catch (Exception &exception)
        {
            Application->ShowException(&exception);
        }
//      Application->MessageBoxA("8","",MB_OK); */
   TentamenForm->NieuwButton->Enabled = true;
   TentamenForm->OpslaanButton->Enabled = false;
   tentamenSQLDataSet->Open();
   tentamenClientDataSet->Active=false; // Flush previous data in set
   tentamenClientDataSet->Filtered = false;
   tentamenClientDataSet->Filter =  "select * from tentamen where GEBOUW = '0'";
   tentamenClientDataSet->Filtered = true;
   tentamenClientDataSet->Active=true;
  // tentamenClientDataSet->Active=false; // Flush previous data in set
  // tentamenClientDataSet->Filtered = false;
  // tentamenClientDataSet->Active=true;

    }
   else if (Modus == 2) //wijzigen
    {
   /*   sasDataModule->tentamenSQLDataSet->CommandType = ctQuery;
      sasDataModule->tentamenSQLDataSet->CommandText = "UPDATE DOCENTBETREKKING SET COMMENTAAR=:COMENTAAR,INDIENSTDATUM=:INDIENSTDATUM,UITDIENSTDATUM=:UITDIENSTDATUM,GEBOUW=:GEBOUW,KAMER=:KAMER,TELEFOON=:TELEFOON,FUNCTIE=:FUNCTIE,FACULTEIT=:FACULTEIT,STUDIERICHTING=:STUDIERICHTING WHERE IDKAARTNR =:IDKAARTNR";
      sasDataModule->tentamenSQLDataSet->Params->Items[0]->AsString = TentamenForm->CommentDBMemo->Text;
      sasDataModule->tentamenSQLDataSet->Params->Items[1]->AsString = TentamenForm->InDienstDBEdit->Text;
      sasDataModule->tentamenSQLDataSet->Params->Items[2]->AsString = TentamenForm->UitDienstDBEdit->Text;
      sasDataModule->tentamenSQLDataSet->Params->Items[3]->AsString = TentamenForm->GebouwDBEdit->Text;
      sasDataModule->tentamenSQLDataSet->Params->Items[4]->AsString = TentamenForm->KamerDBEdit->Text;
      sasDataModule->tentamenSQLDataSet->Params->Items[5]->AsString = TentamenForm->TelefoonDBEdit->Text;
      sasDataModule->tentamenSQLDataSet->Params->Items[6]->AsString = TentamenForm->FunctieDBEdit->Text;
      sasDataModule->tentamenSQLDataSet->Params->Items[7]->AsString = TentamenForm->FaculteitComboBox->KeyValue;
      sasDataModule->tentamenSQLDataSet->Params->Items[8]->AsString = TentamenForm->StudierichtingComboBox->KeyValue;
      sasDataModule->tentamenSQLDataSet->Params->Items[9]->AsString = TentamenForm->IdCardDBEdit->Text;
      sasDataModule->tentamenSQLDataSet->ExecSQL();  */
     }
   //   tentamenSQLDataSet->Close(); // Flush previous query

}
//---------------------------------------------------------------------------

void __fastcall TTentamenForm::VerwijderButtonClick(TObject *Sender)
{
 // sasDataModule->docentbetrekkingSQLDataSet->CommandType = ctQuery;
//  sasDataModule->docentbetrekkingSQLDataSet->CommandText = "DELETE FROM docentbetrekking WHERE IDKAARTNR =   :IDKAARTNR ";
//  sasDataModule->docentbetrekkingSQLDataSet->Params->Items[0]->AsString = TentamenForm->IdCardDBEdit->Text;
 // sasDataModule->docentbetrekkingSQLDataSet->ExecSQL();

  sasDataModule->docentbetrekkingSQLDataSet->Close(); // Flush previous query
  docentbetrekkingClientDataSet->Active=false; // Flush previous data in set
  sasDataModule->docentbetrekkingSQLDataSet->CommandText="select * from docentbetrekking where IDKAARTNR like :Name";
  sasDataModule->docentbetrekkingSQLDataSet->ParamByName("IDKAARTNR")->Value="123456%"; // Append the '%' sign to search for names like the one input in the box
  sasDataModule->docentbetrekkingSQLDataSet->Open();
  docentbetrekkingClientDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TTentamenForm::DocentLookupComboBoxClick(TObject *Sender)
{
   //Nu moet als filter voor personclientdataset de docen_id gezet worden die gekozen is in docentlookupcombobox
}
//---------------------------------------------------------------------------

void __fastcall TTentamenForm::StudierichtingLookupComboBoxClick(
      TObject *Sender)
{
   //Nu moet studierichting_id uit studierichtinglookupcombobox gekozen worden als
   // filter voor personclientdataset
}
//---------------------------------------------------------------------------

void __fastcall TTentamenForm::VakLookupComboBoxClick(TObject *Sender)
{
   //Nu moet vak_id uit vaklookupcombobox gekozen worden als filter voor tentamenvakclientdataset
}
//---------------------------------------------------------------------------

void __fastcall TTentamenForm::VakCodeDBEditChange(TObject *Sender)
{
   //Nu gaan we alle tentamens zoeken die bij dit vak horen indien
   //De modusknop lezen, wijzigen of verwijderen aangeeft.
    AnsiString filter;
    if (VakCodeDBEdit->Text == "") return;
    if (ModusKnop->Caption == "Toevoegen")
     {
       //De  editboxen leegmaken

     }
    else
    {
      //Zoeken naar tentamens die bij dit vak horen
      //Zet een filter op basis van vak_id
     tentamenClientDataSet->Active = false;
     tentamenClientDataSet->Filtered = false;
     if (StudiejaarMaskEdit->Text == "")
       filter = String("VAK_ID = '") + VakIDDBEdit->Text + "'";
     else
       filter =  String("VAK_ID = '") + VakIDDBEdit->Text + "'" + "AND STUDIEJAAR = " +"'" + StudiejaarMaskEdit->Text +"'";
     tentamenClientDataSet->Filter = filter;
     Application->MessageBoxA(filter.c_str(),"vakcodedbeditchange",MB_OK);
     tentamenClientDataSet->Filtered = true;
     tentamenClientDataSet->Active = true;
     last->Text= String(tentamenClientDataSet->RecordCount);
     first->Text= String(tentamenClientDataSet->RecNo);
    }

}
//---------------------------------------------------------------------------


void __fastcall TTentamenForm::vakClientDataSetAfterScroll(
      TDataSet *DataSet)
{
  // if (ToggleButton->Caption == "op studierichting")
  //wie is de docent

}
//---------------------------------------------------------------------------

void __fastcall TTentamenForm::TentamenDBNavigatorClick(TObject *Sender,
      TNavigateBtn Button)
{
   first->Text= String(tentamenClientDataSet->RecNo);
}
//---------------------------------------------------------------------------

