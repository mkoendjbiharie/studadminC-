//---------------------------------------------------------------------------

#ifndef SchakelstudH
#define SchakelstudH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TSchakelstudent : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label3;
        TLabel *Label5;
        TLabel *Label22;
        TLabel *Label2;
        TLabel *Label12;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *StudieMemoLabel;
        TButton *SearchButton;
        TDBEdit *NameDBEdit;
        TDBEdit *FirstNameDBEdit;
        TDBEdit *IdCardDBEdit;
        TDBGrid *LastRecordsDBGrid;
        TDBLookupComboBox *StudierichtingComboBox;
        TButton *NieuwButton;
        TButton *OpslaanButton;
        TButton *VerwijderButton;
        TEdit *SearchEdit;
        TDBEdit *StudieNRDBEdit;
        TDBEdit *InschrijfJaarDBEdit;
        TDBNavigator *InschrijvingDBNavigator;
        TDBMemo *StudieDBMemo;
        TMainMenu *MainMenu1;
        TMenuItem *Bestand1;
        TMenuItem *Close1;
        TMenuItem *Exit1;
        TBitBtn *ToggleButton;
        TDBRadioGroup *AfgerondDBRadioGroup;
        TDBEdit *VolgnummerDBEdit;
        TDBEdit *JaarDBEdit;
        TLabel *ModusLabel;
        TDBNavigator *DBNavigator1;
        TLabel *Label1;
        TLabel *Label7;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall NieuwButtonClick(TObject *Sender);
        void __fastcall OpslaanButtonClick(TObject *Sender);
        void __fastcall VerwijderButtonClick(TObject *Sender);
        void __fastcall StudierichtingComboBoxClick(TObject *Sender);
        void __fastcall IdCardDBEditExit(TObject *Sender);
        void __fastcall InschrijvingDBNavigatorClick(TObject *Sender,
         TNavigateBtn Button);
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSchakelstudent(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSchakelstudent *Schakelstudent;
//---------------------------------------------------------------------------
#endif
