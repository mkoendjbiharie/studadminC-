//---------------------------------------------------------------------------

#ifndef VakH
#define VakH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <DBCtrls.hpp>
#include <ComCtrls.hpp>
#include <Mask.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TVakForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Bestand1;
        TMenuItem *Exit1;
        TMenuItem *Close2;
        TLabel *Label12;
        TLabel *Label1;
        TDBLookupComboBox *StudierichtingComboBox;
        TDBLookupComboBox *FaculteitComboBox;
        TLabel *ModusLabel;
        TDBEdit *CodeDBEdit;
        TDBEdit *PeriodeDBEdit;
        TDBRichEdit *OmschrijvingDBRichEdit;
        TDBEdit *CreditDBEdit;
        TLabel *CodeLabel;
        TLabel *NaamLabel;
        TLabel *OmschrijvingLabel;
        TLabel *PeriodeLabel;
        TLabel *CreditLabel;
        TLabel *soortPeriodeLabel;
        TFontDialog *FontDialog1;
        TButton *Button1;
        TGroupBox *WerkVormenGroupBox;
        TCheckBox *HCCheckBox;
        TCheckBox *WCCheckBox;
        TCheckBox *PRCheckBox;
        TCheckBox *DECheckBox;
        TDBEdit *NaamDBEdit;
        TDBListBox *SoortPeriodeListBox;
        TDBNavigator *VakDBNavigator;
        TCheckBox *PPCheckBox;
        TCheckBox *PJCheckBox;
        TCheckBox *PSCheckBox;
        TCheckBox *ANCheckBox;
        TCheckBox *ONCheckBox;
        TDBMemo *DBAndersMemo;
        TLabel *AndersLabel;
        TButton *SearchButton;
        TEdit *SearchEdit;
        TBitBtn *ToggleButton;
        TButton *OpslaanButton;
        TButton *NieuwButton;
        TButton *VerwijderButton;
        TLabel *OrientatieLabel;
        TDBLookupComboBox *OrientatieComboBox;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall FaculteitComboBoxClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall StudierichtingComboBoxClick(TObject *Sender);
        void __fastcall VakDBNavigatorClick(TObject *Sender,
          TNavigateBtn Button);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall NieuwButtonClick(TObject *Sender);
        void __fastcall OpslaanButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TVakForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVakForm *VakForm;
//---------------------------------------------------------------------------
#endif
