//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Nationaliteit.h"
#include "sasdm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNationaliteitForm *NationaliteitForm;
//---------------------------------------------------------------------------
__fastcall TNationaliteitForm::TNationaliteitForm(TComponent* Owner)
        : TForm(Owner)
{
  nationalitySQLDataSet->Close(); // Flush previous query
  nationalityClientDataSet->Active=false; // Flush previous data in set
  nationalitySQLDataSet->CommandText= "select natio_id,nationaliteit from nationaliteit order by nationaliteit";
  nationalitySQLDataSet->Open();
  nationalityClientDataSet->Active=true;

  NationaliteitEdit->Enabled = true;

  NationaliteitForm->btnwijzigen->Enabled=true;
  NationaliteitForm->btnnieuw->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TNationaliteitForm::btnsluitenClick(TObject *Sender)
{
  NationaliteitForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TNationaliteitForm::NationaliteitDBGridCellClick(
      TColumn *Column)
{
  NationaliteitForm->NationaliteitEdit->Text= NationaliteitDBGrid->Columns->Items[1]->Field->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TNationaliteitForm::ToggleButtonClick(TObject *Sender)
{
 if (NationaliteitForm->ToggleButton->Caption == "wijzigen")
 {
      NationaliteitForm->ToggleButton->Caption = "toevoegen";
      NationaliteitForm->btnwijzigen->Enabled=false;
      NationaliteitForm->btnnieuw->Enabled=true;
  }
  else
  {
      NationaliteitForm->ToggleButton->Caption = "wijzigen";
      NationaliteitForm->btnwijzigen->Enabled=true;
      NationaliteitForm->btnnieuw->Enabled=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TNationaliteitForm::btnwijzigenClick(TObject *Sender)
{
  nationalitySQLDataSet->CommandType = ctQuery;
  nationalitySQLDataSet->CommandText = "UPDATE NATIONALITEIT SET NATIONALITEIT=:NATIONALITEIT WHERE NATIO_ID=:NATIO_ID";
  nationalitySQLDataSet->Params->Items[0]->AsString = NationaliteitForm->NationaliteitEdit->Text;
  nationalitySQLDataSet->Params->Items[1]->AsString = NationaliteitDBGrid->Columns->Items[0]->Field->AsString;
  nationalitySQLDataSet->ExecSQL();

  nationalitySQLDataSet->Close(); // Flush previous query
  nationalityClientDataSet->Active=false; // Flush previous data in set
  nationalitySQLDataSet->CommandText= "select natio_id,nationaliteit from nationaliteit order by nationaliteit";
  nationalitySQLDataSet->Open();
  nationalityClientDataSet->Active=true;

}
//----------------------------------------------------------------------
void __fastcall TNationaliteitForm::btnnieuwClick(TObject *Sender)
{
  nationalitySQLDataSet->CommandType = ctQuery;
  nationalitySQLDataSet->CommandText = "INSERT INTO NATIONALITEIT(NATIONALITEIT) VALUES(:NATIONALITEIT)";
  nationalitySQLDataSet->Params->Items[0]->AsString = NationaliteitForm->NationaliteitEdit->Text;
  nationalitySQLDataSet->ExecSQL();

  nationalitySQLDataSet->Close(); // Flush previous query
  nationalityClientDataSet->Active=false; // Flush previous data in set
  nationalitySQLDataSet->CommandText= "select NATIO_ID,NATIONALITEIT from NATIONALITEIT order by nationaliteit";
  nationalitySQLDataSet->Open();
  nationalityClientDataSet->Active=true;
        
}
//---------------------------------------------------------------------------




void __fastcall TNationaliteitForm::NationaliteitDBGridKeyUp(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
  NationaliteitForm->NationaliteitEdit->Text= NationaliteitDBGrid->Columns->Items[1]->Field->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TNationaliteitForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  int index;
  index =  (HoofdScherm->Venster1->Find("&Nationaliteit"))->MenuIndex;
  HoofdScherm->Venster1->Delete(index);
}
//---------------------------------------------------------------------------

