//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "graad.h"
#include "sasdm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGraadForm *GraadForm;
//---------------------------------------------------------------------------
__fastcall TGraadForm::TGraadForm(TComponent* Owner)
        : TForm(Owner)
{
  graadSQLDataSet->Close(); // Flush previous query
  graadClientDataSet->Active=false; // Flush previous data in set
  graadSQLDataSet->CommandText= "select graad_id,graad from graad order by graad";
  graadSQLDataSet->Open();
  graadClientDataSet->Active=true;

  GraadEdit->Enabled = true;

  GraadForm->btnwijzigen->Enabled=true;
  GraadForm->btnnieuw->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TGraadForm::ToggleButtonClick(TObject *Sender)
{
 if (GraadForm->ToggleButton->Caption == "wijzigen")
 {
      GraadForm->ToggleButton->Caption = "toevoegen";
      GraadForm->btnwijzigen->Enabled=false;
      GraadForm->btnnieuw->Enabled=true;
  }
  else
  {
      GraadForm->ToggleButton->Caption = "wijzigen";
      GraadForm->btnwijzigen->Enabled=true;
      GraadForm->btnnieuw->Enabled=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TGraadForm::btnwijzigenClick(TObject *Sender)
{
  graadSQLDataSet->CommandType = ctQuery;
  graadSQLDataSet->CommandText = "UPDATE GRAAD SET GRAAD=:GRAAD WHERE GRAAD_ID=:GRAAD_ID";
  graadSQLDataSet->Params->Items[0]->AsString = GraadForm->GraadEdit->Text;
  graadSQLDataSet->Params->Items[1]->AsString = GraadDBGrid->Columns->Items[0]->Field->AsString;
  graadSQLDataSet->ExecSQL();
  Application->MessageBox(GraadDBGrid->Columns->Items[0]->Field->AsString.c_str(), "Probeer het opnieuw", MB_OK);
  graadSQLDataSet->Close(); // Flush previous query
  graadClientDataSet->Active=false; // Flush previous data in set
  graadSQLDataSet->CommandText= "select graad_id,graad from graad order by graad";
  graadSQLDataSet->Open();
  graadClientDataSet->Active=true;

}
//----------------------------------------------------------------------
void __fastcall TGraadForm::btnnieuwClick(TObject *Sender)
{
  graadSQLDataSet->CommandType = ctQuery;
  graadSQLDataSet->CommandText = "INSERT INTO graad(graad) VALUES(:graad)";
  graadSQLDataSet->Params->Items[0]->AsString = GraadForm->GraadEdit->Text;
  graadSQLDataSet->ExecSQL();

  graadSQLDataSet->Close(); // Flush previous query
  graadClientDataSet->Active=false; // Flush previous data in set
  graadSQLDataSet->CommandText= "select graad_ID,graad from graad order by graad";
  graadSQLDataSet->Open();
  graadClientDataSet->Active=true;
        
}
//---------------------------------------------------------------------------

void __fastcall TGraadForm::GraadDBGridKeyUp(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
  GraadForm->GraadEdit->Text= GraadDBGrid->Columns->Items[1]->Field->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TGraadForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  int index;
  index =  (HoofdScherm->Venster1->Find("&Graad"))->MenuIndex;
  HoofdScherm->Venster1->Delete(index);
}
//---------------------------------------------------------------------------

void __fastcall TGraadForm::GraadDBGridCellClick(TColumn *Column)
{
  GraadForm->GraadEdit->Text= GraadDBGrid->Columns->Items[1]->Field->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TGraadForm::btnsluitenClick(TObject *Sender)
{
     GraadForm->Close();
}
//---------------------------------------------------------------------------

