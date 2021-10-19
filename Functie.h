//---------------------------------------------------------------------------

#ifndef FunctieH
#define FunctieH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TFunctieForm : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TDBGrid *FunctieDBGrid;
    TGroupBox *GroupBox2;
    TLabel *Label1;
    TEdit *OmschrijvingEdit;
    TButton *btnnieuw;
    TButton *btnwijzigen;
    TBitBtn *ToggleButton;
    TButton *btnsluiten;
    TEdit *VergoedingEdit;
    TEdit *MaxurenEdit;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Taken;
    TMemo *TakenEdit;
    TSQLDataSet *functieSQLDataSet;
    TDataSetProvider *functieDataSetProvider;
    TClientDataSet *functieClientDataSet;
    TDataSource *functieDataSource;
    void __fastcall btnsluitenClick(TObject *Sender);
    void __fastcall FunctieDBGridCellClick(TColumn *Column);
    void __fastcall ToggleButtonClick(TObject *Sender);
    void __fastcall btnwijzigenClick(TObject *Sender);
    void __fastcall btnnieuwClick(TObject *Sender);
    void __fastcall FunctieDBGridKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TFunctieForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFunctieForm *FunctieForm;
//---------------------------------------------------------------------------
#endif
