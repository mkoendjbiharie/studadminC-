//---------------------------------------------------------------------------

#ifndef CertSchStudH
#define CertSchStudH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TCertificaatSchakelStudent : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label3;
        TLabel *Label5;
        TLabel *Label22;
        TLabel *Label12;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *AfgifteLabel;
        TLabel *CertificaatLabel;
        TButton *SearchButton;
        TBitBtn *ModusKnop;
        TEdit *SearchEdit;
        TBitBtn *ToggleButton;
        TDBEdit *NameDBEdit;
        TDBEdit *FirstNameDBEdit;
        TDBEdit *IdCardDBEdit;
        TDBLookupComboBox *StudierichtingComboBox;
        TDBEdit *StudieNRDBEdit;
        TDBEdit *InschrijfJaarDBEdit;
        TDBNavigator *PersoonDBNavigator;
        TDBNavigator *InschrijvingDBNavigator;
        TDBEdit *AfgifteDatumDBEdit;
        TDBRadioGroup *AfgestudeerdDBRadioGroup;
        TButton *OpslaanButton;
        TMainMenu *MainMenu1;
        TMenuItem *Bestand1;
        TMenuItem *Close1;
        TMenuItem *Exit1;
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall ModusKnopClick(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall PersoonDBNavigatorClick(TObject *Sender,
          TNavigateBtn Button);
        void __fastcall OpslaanButtonClick(TObject *Sender);
        void __fastcall AfgestudeerdDBRadioGroupChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TCertificaatSchakelStudent(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCertificaatSchakelStudent *CertificaatSchakelStudent;
//---------------------------------------------------------------------------
#endif
