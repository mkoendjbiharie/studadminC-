//---------------------------------------------------------------------------

#ifndef woningontwerpH
#define woningontwerpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Thoofdscherm : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Thoofdscherm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Thoofdscherm *hoofdscherm;
//---------------------------------------------------------------------------
#endif
