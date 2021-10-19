//---------------------------------------------------------------------------

#ifndef kleurstudentenkaartH
#define kleurstudentenkaartH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include "CGRID.h"
#include <ComCtrls.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TKleurStudentenkaartForm : public TForm
{
__published:	// IDE-managed Components
        TColorDialog *ColorDialog1;
        TButton *OpslaanButton;
        TButton *CancelButton;
        TButton *NieuwButton;
        TUpDown *UpDown1;
        TEdit *Edit1;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit2;
        TLabel *Label3;
        TPanel *Panel2;
        TLabel *Label4;
        TButton *CloseButton;
        void __fastcall OpslaanButtonClick(TObject *Sender);
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall NieuwButtonClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall UpDown1ChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall CloseButtonClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TKleurStudentenkaartForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKleurStudentenkaartForm *KleurStudentenkaartForm;
//---------------------------------------------------------------------------
#endif
