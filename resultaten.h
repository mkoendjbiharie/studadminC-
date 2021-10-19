//---------------------------------------------------------------------------

#ifndef resultatenH
#define resultatenH
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
class TResultatenForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *DatumLabel;
        TLabel *TijdLabel;
        TLabel *DeelTentamenLabel;
        TLabel *StudieJaarLabel;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label7;
        TBevel *Bevel1;
        TLabel *VakLabel;
        TLabel *Label1;
        TLabel *Label2;
        TDBEdit *DatumDBEdit;
        TDBEdit *TijdDBEdit;
        TDBEdit *DeelTentamenDBEdit;
        TBitBtn *ModusKnop;
        TButton *SearchButton;
        TDBLookupComboBox *VakLookupComboBox;
        TDBLookupComboBox *StudierichtingLookupComboBox;
        TMaskEdit *StudiejaarMaskEdit;
        TDBEdit *TentamenDBEdit;
        TClientDataSet *faculteitClientDataSet;
        TDataSource *faculteitDataSource;
        TDataSource *tentamenDataSource;
        TClientDataSet *tentamenClientDataSet;
        TDataSetProvider *tentamenDataSetProvider;
        TSQLDataSet *tentamenSQLDataSet;
        TClientDataSet *studierichtingClientDataSet;
        TDataSource *studierichtingDataSource;
        TDataSetProvider *studierichtingDataSetProvider;
        TDataSource *vakDataSource;
        TClientDataSet *vakClientDataSet;
        TDataSetProvider *vakDataSetProvider;
        TClientDataSet *ClientDataSet1;
        TDataSource *DataSource1;
        TDataSetProvider *faculteitDataSetProvider;
        TSQLDataSet *studierichtingSQLDataSet;
        TDBGrid *ResultatenDBGrid;
        TDataSource *resultatenDataSource;
        TClientDataSet *resultatenClientDataSet;
        TDataSetProvider *resultatenDataSetProvider;
        TSQLDataSet *resultatenSQLDataSet;
        TDBNavigator *DBNavigator1;
        TSQLDataSet *vakSQLDataSet;
        void __fastcall ModusKnopClick(TObject *Sender);
        void __fastcall SearchButtonClick(TObject *Sender);
        void __fastcall StudierichtingLookupComboBoxClick(TObject *Sender);
        void __fastcall tentamenDataSourceDataChange(TObject *Sender,
          TField *Field);
private:	// User declarations
public:		// User declarations
        __fastcall TResultatenForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TResultatenForm *ResultatenForm;
//---------------------------------------------------------------------------
#endif
