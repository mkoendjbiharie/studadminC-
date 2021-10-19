//---------------------------------------------------------------------------

#ifndef VooropleidingH
#define VooropleidingH
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
class TVooropleidingForm : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TDBGrid *VooropleidingDBGrid;
    TGroupBox *GroupBox2;
    TLabel *Label1;
    TEdit *VooropleidingEdit;
    TButton *btnnieuw;
    TButton *btnwijzigen;
    TBitBtn *ToggleButton;
    TButton *btnsluiten;
    TDataSource *eduDataSource;
    TClientDataSet *eduClientDataSet;
    TDataSetProvider *eduDataSetProvider;
    TSQLDataSet *eduSQLDataSet;
    void __fastcall btnnieuwClick(TObject *Sender);
    void __fastcall btnsluitenClick(TObject *Sender);
    void __fastcall btnwijzigenClick(TObject *Sender);
    void __fastcall VooropleidingDBGridCellClick(TColumn *Column);
    void __fastcall ToggleButtonClick(TObject *Sender);
    void __fastcall VooropleidingDBGridKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
    __fastcall TVooropleidingForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVooropleidingForm *VooropleidingForm;
//---------------------------------------------------------------------------
#endif
