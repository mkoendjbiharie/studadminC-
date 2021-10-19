//---------------------------------------------------------------------------

#ifndef tentamenH
#define tentamenH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Provider.hpp>
#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TTentamenForm : public TForm
{
__published:	// IDE-managed Components
        TDBLookupComboBox *StudierichtingLookupComboBox;
        TButton *SearchButton;
        TBitBtn *ToggleButton;
        TBitBtn *ModusKnop;
        TLabel *DocentLabel;
        TLabel *Label31;
        TDBNavigator *TentamenDBNavigator;
        TEdit *first;
        TEdit *last;
        TLabel *Label1;
        TEdit *PeriodeEdit;
        TLabel *Label2;
        TBevel *Bevel1;
        TMaskEdit *StudiejaarMaskEdit;
        TLabel *Label3;
        TClientDataSet *personClientDataSet;
        TClientDataSet *studierichtingClientDataSet;
        TClientDataSet *faculteitClientDataSet;
        TDataSource *faculteitDataSource;
        TDataSource *personDataSource;
        TDataSource *studierichtingDataSource;
        TClientDataSet *tentamenvakClientDataSet;
        TDataSource *tentamenvakDataSource;
        TDataSetProvider *tentamenvakDataSetProvider;
        TDataSetProvider *studierichtingDataSetProvider;
        TDataSetProvider *faculteitDataSetProvider;
        TDataSetProvider *personDataSetProvider;
        TDataSource *docentbetrekingDataSource;
        TClientDataSet *docentbetrekkingClientDataSet;
        TDataSetProvider *docentbetrekkingDataSetProvider;
        TDataSource *vakDataSource;
        TClientDataSet *vakClientDataSet;
        TDataSetProvider *vakDataSetProvider;
        TDataSource *tentamenDataSource;
        TClientDataSet *tentamenClientDataSet;
        TDataSetProvider *tentamenDataSetProvider;
        TDBLookupComboBox *DocentLookupComboBox;
        TDBLookupComboBox *VakLookupComboBox;
        TLabel *TentamenLabel;
        TLabel *Label5;
        TDBNavigator *VakDBNavigator;
        TEdit *first1;
        TEdit *last1;
        TDBEdit *VakCodeDBEdit;
        TDBEdit *VakNaamDBEdit;
        TDBEdit *DocentNaamDBEdit;
        TDBEdit *DocentVoorNaamDBEdit;
        TDBEdit *FaculteitDBEdit;
        TDBEdit *StudierichtingDBEdit;
        TLabel *VakCodeLabel;
        TLabel *VakNaamLabel;
        TLabel *DocentNaamLabel;
        TLabel *DocentVoorNaamLabel;
        TLabel *FaculteitLabel;
        TLabel *StudierichtingLabel;
        TDBEdit *DatumDBEdit;
        TDBEdit *TijdDBEdit;
        TDBEdit *DeelTentamenDBEdit;
        TDBEdit *StudiejaarDBEdit;
        TDBEdit *GebouwDBEdit;
        TDBEdit *ZaalDBEdit;
        TLabel *DatumLabel;
        TLabel *TijdLabel;
        TLabel *DeelTentamenLabel;
        TLabel *StudieJaarLabel;
        TLabel *GebouwLabel;
        TLabel *ZaalLabel;
        TButton *NieuwButton;
        TButton *OpslaanButton;
        TButton *VerwijderButton;
        TDBEdit *VakIDDBEdit;
        TDBEdit *DocentIDDBEdit;
        TSQLDataSet *tentamenSQLDataSet;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label7;
        void __fastcall ToggleButtonClick(TObject *Sender);
        void __fastcall ModusKnopClick(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall VakDBNavigatorClick(TObject *Sender,
          TNavigateBtn Button);
        void __fastcall NieuwButtonClick(TObject *Sender);
        void __fastcall OpslaanButtonClick(TObject *Sender);
        void __fastcall VerwijderButtonClick(TObject *Sender);
        void __fastcall DocentLookupComboBoxClick(TObject *Sender);
        void __fastcall StudierichtingLookupComboBoxClick(TObject *Sender);
        void __fastcall VakLookupComboBoxClick(TObject *Sender);
        void __fastcall VakCodeDBEditChange(TObject *Sender);
        void __fastcall vakClientDataSetAfterScroll(TDataSet *DataSet);
        void __fastcall TentamenDBNavigatorClick(TObject *Sender,
          TNavigateBtn Button);
private:	// User declarations
public:		// User declarations
        __fastcall TTentamenForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTentamenForm *TentamenForm;
//---------------------------------------------------------------------------
#endif
