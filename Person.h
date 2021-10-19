//---------------------------------------------------------------------------

#ifndef PersonH
#define PersonH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <strutils.hpp>
#include <Buttons.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TPersonForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *SasPersonMenu;
        TMenuItem *Bestand1;
        TMenuItem *Exit1;
        TBevel *Bevel1;
        TButton *SearchButton;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TDBLookupComboBox *EthnicDBLookupComboBox;
        TDBLookupComboBox *PrevEducationDBLookupComboBox;
        TDBEdit *NameDBEdit;
        TDBEdit *MarriedNameDBEdit;
        TDBEdit *FirstNameDBEdit;
        TDBEdit *InitialsDBEdit;
        TDBEdit *NumberDBEdit;
        TDBEdit *Email1DBEdit;
        TDBEdit *Email2DBEdit;
        TDBEdit *BankAccountDBEdit;
        TDBRadioGroup *SexDBRadioGroup;
        TDBRadioGroup *MarritalStatusDBRadioGroup;
        TDBMemo *CommentDBMemo;
        TLabel *Label21;
        TDBEdit *IdCardDBEdit;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label24;
        TDBEdit *BirthDateDBEdit;
        TDBEdit *TelephoneDBEdit;
        TDBEdit *CellNrDBEdit;
        TBitBtn *ModusKnop;
        TMenuItem *Close1;
        TDBLookupComboBox *NationalityDBLookupComboBox;
        TDBEdit *BirthPlaceDBEdit;
        TDBEdit *ReligionDBEdit;
        TDBEdit *DistrictDBEdit;
        TDBEdit *AreaDBEdit;
        TDBEdit *StreetDBEdit;
        TDBEdit *CountryDBEdit;
        TButton *NieuwButton;
        TButton *OpslaanButton;
        TButton *VerwijderButton;
        TDBEdit *WoonplaatsDBEdit;
        TDBEdit *BankDBEdit;
        TLabel *Label1;
        TLabel *Label25;
        TEdit *SearchEdit;
        TDBNavigator *DBNavigator1;
        TLabel *Label26;
        TDBMemo *HobbiesDBMemo;
        TPanel *GridPanel;
        TDBGrid *LastRecordsDBGrid;
        TButton *GridPanelButton;
        TLabel *Label2;
        TBitBtn *ToggleButton;
        TLabel *Label27;
        TLabel *Label28;
        TLabel *Label29;
        TLabel *Label30;
        TDBEdit *WerkTelefoonDBEdit;
        TDBEdit *ExtentieDBEdit;
        TDBEdit *ContactTelefoonDBEdit;
    TEdit *first;
    TEdit *last;
    TLabel *Label31;
        TImage *Image1;
        TDBImage *DBImage1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall ModusKnopClick(TObject *Sender);
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall NieuwButtonClick(TObject *Sender);
        void __fastcall OpslaanButtonClick(TObject *Sender);
        void __fastcall VerwijderButtonClick(TObject *Sender);
        void __fastcall SexDBRadioGroupChange(TObject *Sender);
        void __fastcall MarritalStatusDBRadioGroupChange(TObject *Sender);
        void __fastcall GridPanelButtonClick(TObject *Sender);
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall BirthDateDBEditChange(TObject *Sender);
        void __fastcall BirthDateDBEditEnter(TObject *Sender);
    void __fastcall DBNavigator1Click(TObject *Sender,
          TNavigateBtn Button);
        void __fastcall IdCardDBEditChange(TObject *Sender);

private:	// User declarations
/*        static void doRead();
        static void doInsert();
        static void doUpdate();
        static void doDelete(); */   
public:		// User declarations
        __fastcall TPersonForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPersonForm *PersonForm;
//---------------------------------------------------------------------------
#endif
