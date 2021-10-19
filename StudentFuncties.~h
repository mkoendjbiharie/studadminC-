//---------------------------------------------------------------------------

#ifndef StudentFunctiesH
#define StudentFunctiesH
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
class TStudentfunctiesForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *SasPersonMenu;
        TMenuItem *Bestand1;
        TMenuItem *Close1;
        TMenuItem *Exit1;
        TLabel *Label3;
        TLabel *Label5;
        TLabel *Label22;
        TLabel *Label12;
        TLabel *Label1;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label2;
        TButton *SearchButton;
        TBitBtn *ModusKnop;
        TEdit *SearchEdit;
        TBitBtn *ToggleButton;
        TDBEdit *NameDBEdit;
        TDBEdit *FirstNameDBEdit;
        TDBEdit *IdCardDBEdit;
        TDBLookupComboBox *StudierichtingComboBox;
        TDBLookupComboBox *FaculteitComboBox;
        TDBEdit *StudieNRDBEdit;
        TDBEdit *InschrijfJaarDBEdit;
        TDBNavigator *PersoonDBNavigator;
        TDBNavigator *InschrijvingDBNavigator;
        TDBLookupListBox *SysteemDBLookupListBox;
        TLabel *FunctieLabel;
        TLabel *StartdatumLabel;
        TLabel *EinddatumLabel;
        TLabel *VerantwoordelijkeLabel;
        TLabel *VakgebiedLabel1;
        TLabel *AantalurenLabel1;
        TLabel *Label7;
        TDBLookupComboBox *FunctieDBLookupComboBox;
        TDBEdit *StartdatumDBEdit;
        TDBEdit *EinddatumDBEdit;
        TDBEdit *VerantwoordelijkeDBEdit;
        TDBEdit *VakgebiedDBEdit;
        TDBEdit *AantalurenDBEdit;
        TSQLDataSet *functieSQLDataSet;
        TDataSetProvider *functieDataSetProvider;
        TClientDataSet *functieClientDataSet;
        TDataSource *functieDataSource;
        TDBNavigator *StudentfunctiesDBNavigator;
        TButton *NieuwButton;
        TButton *OpslaanButton;
        TButton *VerwijderButton;
        TSQLDataSet *vacatureSQLDataSet;
        TClientDataSet *vacatureClientDataSet;
        TDataSource *vacatureDataSource;
        TDataSetProvider *vacatureDataSetProvider;
        TDBMemo *TaakomschrijvingDBMemo;
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ModusKnopClick(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall PersoonDBNavigatorClick(TObject *Sender,
          TNavigateBtn Button);
        void __fastcall InschrijvingDBNavigatorClick(TObject *Sender,
          TNavigateBtn Button);
        void __fastcall NieuwButtonClick(TObject *Sender);
        void __fastcall OpslaanButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TStudentfunctiesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStudentfunctiesForm *StudentfunctiesForm;
//---------------------------------------------------------------------------
#endif
