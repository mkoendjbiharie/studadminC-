//---------------------------------------------------------------------------

#ifndef SasfacdmH
#define SasfacdmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TSasFaculteitData : public TDataModule
{
__published:	// IDE-managed Components
        TSQLDataSet *vakSQLDataSet;
        TDataSetProvider *vakDataSetProvider;
        TClientDataSet *vakClientDataSet;
        TDataSource *vakDataSource;
        void __fastcall vakDataSourceUpdateData(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSasFaculteitData(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSasFaculteitData *SasFaculteitData;
//---------------------------------------------------------------------------
#endif
