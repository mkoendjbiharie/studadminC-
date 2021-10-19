//---------------------------------------------------------------------------

#ifndef intekenenH
#define intekenenH
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
#include <FMTBcd.hpp>
#include <Mask.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TIntekenForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *DatumLabel;
        TLabel *TijdLabel;
        TLabel *DeelTentamenLabel;
        TLabel *StudieJaarLabel;
        TLabel *GebouwLabel;
        TLabel *ZaalLabel;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label7;
        TDBEdit *DatumDBEdit;
        TDBEdit *TijdDBEdit;
        TDBEdit *DeelTentamenDBEdit;
        TDBEdit *GebouwDBEdit;
        TDBEdit *ZaalDBEdit;
        TButton *NieuwButton;
        TButton *OpslaanButton;
        TButton *VerwijderButton;
        TClientDataSet *faculteitClientDataSet;
        TDataSource *faculteitDataSource;
        TDataSource *tentamenDataSource;
        TClientDataSet *tentamenClientDataSet;
        TDataSetProvider *tentamenDataSetProvider;
        TSQLDataSet *tentamenSQLDataSet;
        TBitBtn *ModusKnop;
        TDBLookupComboBox *StudentLookupComboBox;
        TDBEdit *IntekenDatumDBEdit;
        TLabel *StudentLabel;
        TLabel *IntekenDatumLabel;
        TButton *SearchButton;
        TBevel *Bevel1;
        TDBLookupComboBox *VakLookupComboBox;
        TLabel *VakLabel;
        TDBLookupComboBox *StudierichtingLookupComboBox;
        TLabel *Label1;
        TDBNavigator *IntekenLijstDBNavigator;
        TDBGrid *IntekenLijstDBGrid;
        TLabel *Label2;
        TLabel *Label3;
        TClientDataSet *studierichtingClientDataSet;
        TDataSource *studierichtingDataSource;
        TDataSetProvider *studierichtingDataSetProvider;
        TDataSource *vakDataSource;
        TClientDataSet *vakClientDataSet;
        TDataSetProvider *vakDataSetProvider;
        TClientDataSet *ClientDataSet1;
        TDataSource *DataSource1;
        TDataSetProvider *faculteitDataSetProvider;
        TMaskEdit *StudiejaarMaskEdit;
        TLabel *Label31;
        TEdit *first;
        TEdit *last;
        TSQLDataSet *intekenlijstSQLDataSet;
        TDataSetProvider *intekenlijstDataSetProvider;
        TClientDataSet *intekenlijstClientDataSet;
        TDataSource *intekenlijstDataSource;
        TDBEdit *TentamenDBEdit;
        TSQLDataSet *studierichtingSQLDataSet;
        void __fastcall ModusKnopClick(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall StudierichtingLookupComboBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TIntekenForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TIntekenForm *IntekenForm;
//---------------------------------------------------------------------------
#endif
