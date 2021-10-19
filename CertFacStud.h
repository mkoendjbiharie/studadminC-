//---------------------------------------------------------------------------

#ifndef CertFacStudH
#define CertFacStudH
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
#include <DB.hpp>
#include <DBClient.hpp>
#include <DBXpress.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TCertificatenfaculteitstudent : public TForm
{
__published:	// IDE-managed Components
        TButton *SearchButton;
        TBitBtn *ModusKnop;
        TEdit *SearchEdit;
        TBitBtn *ToggleButton;
        TLabel *Label3;
        TLabel *Label5;
        TLabel *Label22;
        TLabel *Label12;
        TLabel *Label1;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *AfstudeerDatumLabel;
        TLabel *Label8;
        TLabel *Label9;
        TDBEdit *NameDBEdit;
        TDBEdit *FirstNameDBEdit;
        TDBEdit *IdCardDBEdit;
        TDBLookupComboBox *StudierichtingComboBox;
        TDBLookupComboBox *FaculteitComboBox;
        TButton *NieuwButton;
        TButton *OpslaanButton;
        TButton *VerwijderButton;
        TDBEdit *StudieNRDBEdit;
        TDBEdit *InschrijfJaarDBEdit;
        TDBNavigator *PersoonDBNavigator;
        TDBEdit *AfstudeerDatumDBEdit;
        TDBNavigator *InschrijvingDBNavigator;
        TDBNavigator *CertificaatDBNavigator;
        TLabel *CertificaatLabel;
        TLabel *AfgifteLabel;
        TDBEdit *AfgifteDatumDBEdit;
        TLabel *CertificatenLabel;
        TMainMenu *MainMenu1;
        TMenuItem *Bestand1;
        TMenuItem *Close1;
        TMenuItem *Exit1;
        TDBLookupComboBox *CertificaatComboBox;
        TSQLConnection *sasSQLConnection1;
        TDataSource *CertificaatDataSource;
        TClientDataSet *CertificaatClientDataSet;
        TSQLDataSet *CertificaatSQLDataSet;
        TSQLDataSet *StudcertificaatSQLDataSet;
        TDataSetProvider *CertificaatDataSetProvider;
        TDataSetProvider *StudcertificaatDataSetProvider;
        TClientDataSet *StudcertificaatClientDataSet;
        TDataSource *StudcertificaatDataSource;
        TLabel *Label2;
        TDBLookupListBox *SysteemDBLookupListBox;
        TLabel *Label7;
        TDBRadioGroup *AfgestudeerdDBRadioGroup;
        TButton *DiplomaButton;
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall ModusKnopClick(TObject *Sender);
        void __fastcall NieuwButtonClick(TObject *Sender);
        void __fastcall OpslaanButtonClick(TObject *Sender);
        void __fastcall VerwijderButtonClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall PersoonDBNavigatorClick(TObject *Sender,
          TNavigateBtn Button);
        void __fastcall InschrijvingDBNavigatorClick(TObject *Sender,
          TNavigateBtn Button);
        void __fastcall DiplomaButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TCertificatenfaculteitstudent(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCertificatenfaculteitstudent *Certificatenfaculteitstudent;
//---------------------------------------------------------------------------
#endif
