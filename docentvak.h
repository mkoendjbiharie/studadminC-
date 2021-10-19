//---------------------------------------------------------------------------

#ifndef docentvakH
#define docentvakH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Provider.hpp>
#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TDocentVakForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label3;
        TLabel *Label5;
        TLabel *Label22;
        TLabel *VakLabel;
        TLabel *Label12;
        TLabel *Label1;
        TLabel *Label31;
        TDBEdit *NameDBEdit;
        TDBEdit *FirstNameDBEdit;
        TDBEdit *IdCardDBEdit;
        TDBNavigator *PersoonDBNavigator;
        TButton *SearchButton;
        TEdit *SearchEdit;
        TBitBtn *ToggleButton;
        TButton *NieuwButton;
        TButton *OpslaanButton;
        TButton *VerwijderButton;
        TDBNavigator *DocentVakNavigator;
        TBitBtn *ModusKnop;
        TEdit *first;
        TEdit *last;
        TClientDataSet *personClientDataSet;
        TClientDataSet *studierichtingClientDataSet;
        TClientDataSet *faculteitClientDataSet;
        TDataSource *faculteitDataSource;
        TDataSource *personDataSource;
        TDataSource *studierichtingDataSource;
        TClientDataSet *docentvakClientDataSet;
        TDataSource *docentvakDataSource;
        TDataSetProvider *docentvakDataSetProvider;
        TDataSetProvider *studierichingDataSetProvider;
        TDataSetProvider *faculteitDataSetProvider;
        TDataSetProvider *pesonDataSetProvider;
        TLabel *DocentLabel;
        TDBLookupComboBox *StudierichtingLookupComboBox;
        TDBEdit *VakCodeDBEdit;
        TDBEdit *VakNaamDBEdit;
        TLabel *VakCodeLabel;
        TLabel *VakNaamLabel;
        TDataSource *docentbetrekingDataSource;
        TClientDataSet *docentbetrekkingClientDataSet;
        TDataSetProvider *docentbetrekkingDataSetProvider;
        TDataSource *vakDataSource;
        TClientDataSet *vakClientDataSet;
        TDataSetProvider *vakDataSetProvider;
        TDBEdit *FaculteitDBEdit;
        TDBEdit *StudierichtingDBEdit;
        TDBEdit *DocentIdDBEdit;
        TDBEdit *VanDBEdit;
        TDBEdit *TotDBEdit;
        TLabel *VanLabel;
        TLabel *Totlabel;
        TSQLDataSet *personSQLDataSet;
        TSQLDataSet *studierichtingSQLDataSet;
        TSQLDataSet *docentbetrekkingSQLDataSet;
        TSQLDataSet *vakSQLDataSet;
        void __fastcall ModusKnopClick(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall PersoonDBNavigatorClick(TObject *Sender,
          TNavigateBtn Button);
        void __fastcall IdCardDBEditChange(TObject *Sender);
        void __fastcall NieuwButtonClick(TObject *Sender);
        void __fastcall OpslaanButtonClick(TObject *Sender);
        void __fastcall VerwijderButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDocentVakForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDocentVakForm *DocentVakForm;
//---------------------------------------------------------------------------
#endif
