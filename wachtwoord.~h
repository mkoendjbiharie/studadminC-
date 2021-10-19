//---------------------------------------------------------------------------

#ifndef wachtwoordH
#define wachtwoordH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TWachtwoordForm : public TForm
{
__published:	// IDE-managed Components
    TButton *btnsluiten;
    TPanel *Panel1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *oudEdit;
    TEdit *nieuwEdit1;
    TEdit *nieuwEdit2;
    TButton *btnbevestig;
    TButton *btncancel;
    TSQLDataSet *passwordSQLDataSet;
    TDataSetProvider *passwordDataSetProvider;
    TClientDataSet *passwordClientDataSet;
    TDataSource *passwordDataSource;
    void __fastcall btnbevestigClick(TObject *Sender);
    void __fastcall btncancelClick(TObject *Sender);
    void __fastcall btnsluitenClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TWachtwoordForm(TComponent* Owner);
//    void __fastcall btncancelClick(TObject *Sender);
//    void __fastcall btnsluitenClick(TObject *Sender);
//    void __fastcall btnbevestigClick(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TWachtwoordForm *WachtwoordForm;
//---------------------------------------------------------------------------
#endif
