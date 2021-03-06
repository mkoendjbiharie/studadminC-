//---------------------------------------------------------------------------

#ifndef CertificaatH
#define CertificaatH
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
class TCertificaatForm : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TDBGrid *CertificaatDBGrid;
    TGroupBox *GroupBox2;
    TLabel *Label1;
    TEdit *CertificaatEdit;
    TButton *btnnieuw;
    TButton *btnwijzigen;
    TBitBtn *ToggleButton;
    TButton *btnsluiten;
    TSQLDataSet *certificaatSQLDataSet;
    TDataSetProvider *certificaatDataSetProvider;
    TClientDataSet *certificaatClientDataSet;
    TDataSource *certificaatDataSource;
    void __fastcall ToggleButtonClick(TObject *Sender);
    void __fastcall btnnieuwClick(TObject *Sender);
    void __fastcall btnwijzigenClick(TObject *Sender);
    void __fastcall btnsluitenClick(TObject *Sender);
    void __fastcall CertificaatDBGridCellClick(TColumn *Column);
    void __fastcall CertificaatDBGridKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TCertificaatForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCertificaatForm *CertificaatForm;
//---------------------------------------------------------------------------
#endif
