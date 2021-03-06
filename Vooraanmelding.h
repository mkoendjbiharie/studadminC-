//---------------------------------------------------------------------------

#ifndef VooraanmeldingH
#define VooraanmeldingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <DBXpress.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TVooraanmeldingForm : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl;
        TTabSheet *PersonSheet;
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
        TLabel *Label21;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label24;
        TLabel *Label1;
        TLabel *Label25;
        TLabel *Label26;
        TLabel *Label27;
        TLabel *Label28;
        TLabel *Label29;
        TLabel *Label30;
        TDBEdit *ContactTelefoonDBEdit;
        TDBEdit *ExtentieDBEdit;
        TDBEdit *WerkTelefoonDBEdit;
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
        TDBEdit *IdCardDBEdit;
        TDBEdit *BirthDateDBEdit;
        TDBEdit *TelephoneDBEdit;
        TDBEdit *CellNrDBEdit;
        TDBLookupComboBox *NationalityDBLookupComboBox;
        TDBEdit *BirthPlaceDBEdit;
        TDBEdit *ReligionDBEdit;
        TDBEdit *DistrictDBEdit;
        TDBEdit *AreaDBEdit;
        TDBEdit *StreetDBEdit;
        TDBEdit *CountryDBEdit;
        TDBEdit *WoonplaatsDBEdit;
        TDBEdit *BankDBEdit;
        TDBMemo *HobbiesDBMemo;
        TPanel *GridPanel;
        TLabel *Label2;
        TDBGrid *LastRecordsDBGrid;
        TButton *GridPanelButton;
        TMainMenu *SasPersonMenu;
        TMenuItem *Bestand1;
        TMenuItem *Close1;
        TMenuItem *Exit1;
        TBevel *Bevel1;
        TBitBtn *ModusKnop;
        TDBNavigator *DBNavigator1;
        TButton *NieuwButton;
        TButton *OpslaanButton;
        TButton *VerwijderButton;
        TEdit *first;
        TEdit *last;
        TSQLDataSet *vpersonSQLDataSet;
        TDataSetProvider *vpersonDataSetProvider;
        TClientDataSet *vpersonClientDataSet;
        TDataSource *vpersonDataSource;
        TSQLDataSet *vinschrijvingSQLDataSet;
        TSQLDataSet *vschakelSQLDataSet;
        TDataSetProvider *vinschrijvingDataSetProvider;
        TDataSetProvider *vschakelDataSetProvider;
        TClientDataSet *vinschrijvingClientDataSet;
        TClientDataSet *vschakelClientDataSet;
        TDataSource *vinschrijvingDataSource;
        TDataSource *vschakelDataSource;
        TButton *Button1;
        TLabel *Label31;
        TBitBtn *InschrijfButton;
        TEdit *SearchEdit;
        TButton *SearchButton;
        TBitBtn *ToggleButton;
        TTabSheet *TabSheet1;
        TLabel *NatuurkundeLabel;
        TLabel *WiskundeLabel;
        TLabel *ScheikundeLabel;
        TLabel *BiologieLabel;
        TLabel *Studierichting1Label;
        TLabel *Studierichting2Label;
        TLabel *FaculteitLabel;
        TDBEdit *NatuurkundeDBEdit;
        TDBEdit *WiskundeDBEdit;
        TDBEdit *ScheikundeDBEdit;
        TDBEdit *BiologieDBEdit;
        TDBLookupComboBox *Studierichting1DBLookupComboBox;
        TDBLookupComboBox *Studierichting2DBLookupComboBox;
        TDBLookupComboBox *FaculteitDBLookupComboBox;
        TPanel *ExtraPanel;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *Label34;
        TLabel *Label35;
        TDBEdit *DBEdit1;
        TDBEdit *DBEdit2;
        TDBEdit *DBEdit3;
        TGroupBox *GroupBox1;
        TLabel *Label36;
        TLabel *Label37;
        TLabel *Label38;
        TDBEdit *InstituutDBEdit;
        TDBEdit *RichtingDBEdit;
        TDBLookupComboBox *GraadComboBox;
        TLabel *StudieMemoLabel;
        TDBMemo *StudieDBMemo;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall ModusKnopClick(TObject *Sender);
        void __fastcall NieuwButtonClick(TObject *Sender);
        void __fastcall OpslaanButtonClick(TObject *Sender);
        void __fastcall VerwijderButtonClick(TObject *Sender);
        void __fastcall SexDBRadioGroupClick(TObject *Sender);
        void __fastcall MarritalStatusDBRadioGroupClick(TObject *Sender);
        void __fastcall GridPanelButtonClick(TObject *Sender);
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall DBNavigator1Click(TObject *Sender,
          TNavigateBtn Button);
        void __fastcall FaculteitDBLookupComboBoxClick(TObject *Sender);
        void __fastcall InschrijfButtonClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations

public:		// User declarations
        __fastcall TVooraanmeldingForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVooraanmeldingForm *VooraanmeldingForm;
//---------------------------------------------------------------------------
#endif
