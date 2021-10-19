//---------------------------------------------------------------------------

#ifndef herinschrijvingenfaculteitH
#define herinschrijvingenfaculteitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class THerinschrijvingfaculteitform : public TForm
{
__published:	// IDE-managed Components
        TLabel *FaculteitLabel;
        TLabel *SudierichtingLabel;
        TLabel *CollegejaarLabel;
        TDBLookupComboBox *DBLookupComboBox1;
        TDBLookupComboBox *DBLookupComboBox2;
        TRadioGroup *RadioGroup1;
        TEdit *CollegejaarEdit;
        TUpDown *CollegejaarUpDown;
        TButton *Button1;
        TButton *CloseButton;
        TRadioGroup *RadioGroup2;
private:	// User declarations
public:		// User declarations
        __fastcall THerinschrijvingfaculteitform(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THerinschrijvingfaculteitform *Herinschrijvingfaculteitform;
//---------------------------------------------------------------------------
#endif
