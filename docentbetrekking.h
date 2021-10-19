//---------------------------------------------------------------------------

#ifndef docentbetrekkingH
#define docentbetrekkingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <Provider.hpp>
#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TDocentBetrekkingForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label3;
        TLabel *Label5;
        TLabel *Label22;
        TLabel *Label8;
        TDBEdit *NameDBEdit;
        TDBEdit *FirstNameDBEdit;
        TDBEdit *IdCardDBEdit;
        TDBNavigator *PersoonDBNavigator;
        TButton *SearchButton;
        TEdit *SearchEdit;
        TBitBtn *ToggleButton;
        TLabel *Label9;
        TButton *NieuwButton;
        TButton *OpslaanButton;
        TButton *VerwijderButton;
        TDBNavigator *DocentBetrekkingNavigator;
        TLabel *Label12;
        TLabel *Label1;
        TDBLookupComboBox *StudierichtingComboBox;
        TDBLookupComboBox *FaculteitComboBox;
        TDBEdit *GebouwDBEdit;
        TDBEdit *KamerDBEdit;
        TDBEdit *TelefoonDBEdit;
        TDBEdit *InDienstDBEdit;
        TLabel *GebouwLabel;
        TLabel *KamernrLabel;
        TLabel *TelefoonnrLabel;
        TLabel *Label7;
        TLabel *UitDienstLabel;
        TDBEdit *UitDienstDBEdit;
        TDBMemo *CommentDBMemo;
        TLabel *CommentLabel;
        TBitBtn *ModusKnop;
        TClientDataSet *personClientDataSet;
        TClientDataSet *studierichtingClientDataSet;
        TClientDataSet *faculteitClientDataSet;
        TDataSource *faculteitDataSource;
        TDataSource *personDataSource;
        TDataSource *studierichtingDataSource;
        TClientDataSet *docentbetrekkingClientDataSet;
        TDataSource *docentbetrekkingDataSource;
        TLabel *Label31;
        TEdit *first;
        TEdit *last;
        TDataSetProvider *docentbetrekkingDataSetProvider;
        TDataSetProvider *studierichingDataSetProvider;
        TDataSetProvider *faculteitDataSetProvider;
        TDataSetProvider *pesonDataSetProvider;
        TDBEdit *FunctieDBEdit;
        TLabel *FunctieLabel;
        TSQLDataSet *studierichtingSQLDataSet;
        TSQLDataSet *docentbetrekkingSQLDataSet;
        void __fastcall ModusKnopClick(TObject *Sender);
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall NieuwButtonClick(TObject *Sender);
        void __fastcall OpslaanButtonClick(TObject *Sender);
        void __fastcall VerwijderButtonClick(TObject *Sender);
        void __fastcall FaculteitComboBoxClick(TObject *Sender);
        void __fastcall PersoonDBNavigatorClick(TObject *Sender,
          TNavigateBtn Button);
private:	// User declarations
public:		// User declarations
        __fastcall TDocentBetrekkingForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDocentBetrekkingForm *DocentBetrekkingForm;
//---------------------------------------------------------------------------
#endif
