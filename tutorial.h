//---------------------------------------------------------------------------

#ifndef tutorialH
#define tutorialH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include "Word_2K_SRVR.h"
#include <OleServer.hpp>
#include <OleCtnrs.hpp>
//---------------------------------------------------------------------------
class TTutorialForm : public TForm
{
__published:	// IDE-managed Components
        TRichEdit *TutorialRichEdit;
        TMainMenu *MainMenu1;
        TMenuItem *Bestand1;
        TMenuItem *Close1;
        TMenuItem *Exit1;
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TTutorialForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTutorialForm *TutorialForm;
//---------------------------------------------------------------------------
#endif
