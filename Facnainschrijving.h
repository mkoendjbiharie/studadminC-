//---------------------------------------------------------------------------

#ifndef FacnainschrijvingH
#define FacnainschrijvingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFacnainschr : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Bestand1;
        TMenuItem *Close1;
        TMenuItem *Exit1;
        TButton *SearchButton;
        TBitBtn *ModusKnop;
        TLabel *Label3;
        TLabel *Label5;
        TLabel *Label22;
        TDBEdit *NameDBEdit;
        TDBEdit *FirstNameDBEdit;
        TDBEdit *IdCardDBEdit;
        TLabel *Label2;
        TDBGrid *LastRecordsDBGrid;
        TLabel *Label12;
        TDBLookupComboBox *StudierichtingComboBox;
        TLabel *Label1;
        TDBLookupComboBox *FaculteitComboBox;
        TButton *NieuwButton;
        TButton *OpslaanButton;
        TEdit *SearchEdit;
        TDBEdit *StudieNRDBEdit;
        TLabel *Label4;
        TDBEdit *InschrijfJaarDBEdit;
        TLabel *Label6;
        TDBNavigator *InschrijvingDBNavigator;
        TDBEdit *AfstudeerDatumDBEdit;
        TDBEdit *VerlengingDBEdit;
        TDBEdit *AfschrijvingsDatumDBEdit;
        TLabel *AfstudeerDatumLabel;
        TLabel *VerlengingLabel;
        TLabel *AfschrijvingsDatumLabel;
        TLabel *StudieMemoLabel;
        TDBMemo *StudieDBMemo;
        TLabel *RederLabel;
        TDBLookupListBox *SysteemDBLookupListBox;
        TLabel *SysteemLabel;
        TBitBtn *ToggleButton;
        TDBGrid *EerdereInschrijvingenDBGrid;
        TLabel *Label7;
        TDBMemo *RedenDBMemo;
        TDBEdit *VolgnummerDBEdit;
        TDBEdit *JaarDBEdit;
        TLabel *Label8;
        TLabel *Label9;
        TDBNavigator *DBNavigator1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall ModusKnopClick(TObject *Sender);
        void __fastcall NieuwButtonClick(TObject *Sender);
        void __fastcall OpslaanButtonClick(TObject *Sender);
        void __fastcall FaculteitComboBoxClick(TObject *Sender);
        void __fastcall StudierichtingComboBoxClick(TObject *Sender);
        void __fastcall IdCardDBEditExit(TObject *Sender);
        void __fastcall InschrijvingDBNavigatorClick(TObject *Sender,
          TNavigateBtn Button);
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall IdCardDBEditChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFacnainschr(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFacnainschr *Facnainschr;
//---------------------------------------------------------------------------
#endif
