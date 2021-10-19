//---------------------------------------------------------------------------

#ifndef graadH
#define graadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <DBGrids.hpp>
#include <FMTBcd.hpp>
#include <Grids.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TGraadForm : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TDBGrid *GraadDBGrid;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TEdit *GraadEdit;
        TButton *btnnieuw;
        TButton *btnwijzigen;
        TBitBtn *ToggleButton;
        TButton *btnsluiten;
        TDataSource *graadDataSource;
        TClientDataSet *graadClientDataSet;
        TDataSetProvider *graadDataSetProvider;
        TSQLDataSet *graadSQLDataSet;
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall btnwijzigenClick(TObject *Sender);
        void __fastcall btnnieuwClick(TObject *Sender);
        void __fastcall GraadDBGridKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall GraadDBGridCellClick(TColumn *Column);
        void __fastcall btnsluitenClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TGraadForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGraadForm *GraadForm;
//---------------------------------------------------------------------------
#endif
