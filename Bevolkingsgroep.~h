//---------------------------------------------------------------------------

#ifndef BevolkingsgroepH
#define BevolkingsgroepH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TBevolkingsgroepForm : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TDBGrid *BevolkingsgroepDBGrid;
    TGroupBox *GroupBox2;
    TLabel *Label1;
    TEdit *BevolkingsgroepEdit;
    TButton *btnnieuw;
    TButton *btnwijzigen;
    TBitBtn *ToggleButton;
    TButton *btnsluiten;
    TSQLDataSet *ethnicSQLDataSet;
    TDataSetProvider *ethnicDataSetProvider;
    TClientDataSet *ethnicClientDataSet;
    TDataSource *ethnicDataSource;
    void __fastcall btnnieuwClick(TObject *Sender);
    void __fastcall btnsluitenClick(TObject *Sender);
    void __fastcall BevolkingsgroepDBGridCellClick(TColumn *Column);
    void __fastcall ToggleButtonClick(TObject *Sender);
    void __fastcall btnwijzigenClick(TObject *Sender);
    void __fastcall BevolkingsgroepDBGridKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
    __fastcall TBevolkingsgroepForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBevolkingsgroepForm *BevolkingsgroepForm;
//---------------------------------------------------------------------------
#endif
