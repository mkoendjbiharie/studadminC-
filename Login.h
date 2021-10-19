//---------------------------------------------------------------------------

#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TLoginForm : public TForm
{
__published:	// IDE-managed Components
        TEdit *UserNameEdit;
        TEdit *UserPassEdit;
        TLabel *Label1;
        TLabel *Label2;
        TButton *OkButton;
        TButton *CancelButton;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall OkButtonClick(TObject *Sender);
        void __fastcall CancelButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLoginForm *LoginForm;
//---------------------------------------------------------------------------
#endif
