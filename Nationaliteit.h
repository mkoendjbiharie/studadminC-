//---------------------------------------------------------------------------

#ifndef NationaliteitH
#define NationaliteitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TNationaliteitForm : public TForm
{
__published:	// IDE-managed Components
        TDBGrid *NationaliteitDBGrid;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TButton *btnsluiten;
        TLabel *Label1;
        TEdit *NationaliteitEdit;
        TButton *btnnieuw;
        TButton *btnwijzigen;
        TBitBtn *ToggleButton;
    TDataSource *nationalityDataSource;
    TClientDataSet *nationalityClientDataSet;
    TDataSetProvider *nationalityDataSetProvider;
    TSQLDataSet *nationalitySQLDataSet;
        void __fastcall btnsluitenClick(TObject *Sender);
        void __fastcall NationaliteitDBGridCellClick(TColumn *Column);
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall btnwijzigenClick(TObject *Sender);
        void __fastcall btnnieuwClick(TObject *Sender);
    void __fastcall NationaliteitDBGridKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TNationaliteitForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNationaliteitForm *NationaliteitForm;
//---------------------------------------------------------------------------
#endif
