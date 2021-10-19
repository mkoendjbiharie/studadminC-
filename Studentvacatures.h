//---------------------------------------------------------------------------

#ifndef StudentvacaturesH
#define StudentvacaturesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TStudentVacaturesForm : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *ModusKnop;
        TMainMenu *MainMenu1;
        TMenuItem *Bestand1;
        TMenuItem *Close1;
        TMenuItem *Exit1;
        TDBNavigator *vacaturesDBNavigator;
        TDBLookupComboBox *FunctieDBLookupComboBox;
        TLabel *FunctieLabel;
        TLabel *StartdatumLabel;
        TLabel *EinddatumLabel;
        TLabel *VerantwoordelijkeLabel;
        TLabel *VakgebiedLabel1;
        TLabel *AantalurenLabel1;
        TLabel *OpenLabel;
        TDBEdit *StartdatumDBEdit;
        TDBEdit *EinddatumDBEdit;
        TDBEdit *VerantwoordelijkeDBEdit;
        TDBEdit *VakgebiedDBEdit;
        TDBEdit *AantalurenDBEdit;
        TSQLDataSet *vacatureSQLDataSet;
        TClientDataSet *vacatureClientDataSet;
        TDataSource *vacatureDataSource;
        TDataSetProvider *vacatureDataSetProvider;
        TButton *NieuwButton;
        TButton *OpslaanButton;
        TButton *VerwijderButton;
        TSQLDataSet *functieSQLDataSet;
        TDataSetProvider *functieDataSetProvider;
        TClientDataSet *functieClientDataSet;
        TDataSource *functieDataSource;
        TDBRadioGroup *OpenDBRadioGroup;
        TLabel *TaakomschrijvingLabel;
        TDBMemo *TaakomschrijvingDBMemo;
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ModusKnopClick(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall OpslaanButtonClick(TObject *Sender);
        void __fastcall NieuwButtonClick(TObject *Sender);
        void __fastcall VerwijderButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TStudentVacaturesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStudentVacaturesForm *StudentVacaturesForm;
//---------------------------------------------------------------------------
#endif
