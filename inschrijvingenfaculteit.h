//---------------------------------------------------------------------------

#ifndef inschrijvingenfaculteitH
#define inschrijvingenfaculteitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
#include <Graphics.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <QRExport.hpp>
//---------------------------------------------------------------------------
class Tinschrijvingenfaculteitreport : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRBand *QRBand3;
    TQRDBText *QRDBText1;
    TQRDBText *QRDBText2;
    TQRDBText *QRDBText3;
    TQRDBText *QRDBText6;
    TQRDBText *QRDBText7;
    TQRDBText *QRDBText8;
    TQRDBText *QRDBText9;
    TQRDBText *QRDBText10;
    TQRBand *ColumnHeaderBand1;
    TQRLabel *collegejaar;
    TQRDBText *QRDBText4;
    TQRLabel *QRLabel1;
    TQRBand *PageFooterBand1;
    TQRSysData *QRSysData1;
    TQRSysData *QRSysData2;
    TQRSysData *QRSysData3;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel3;
    TQRLabel *QRLabel4;
    TQRLabel *QRLabel5;
    TQRLabel *QRLabel6;
    TQRLabel *QRLabel7;
    TQRLabel *QRLabel8;
    TQRLabel *QRLabel9;
    TQRLabel *QRLabel10;
    TQRLabel *QRLabel11;
    TQRLabel *QRLabel12;
    TQRLabel *QRLabel13;
    TQRDBText *QRDBText5;
        TQRCSVFilter *QRCSVFilter1;
private:	// User declarations
public:		// User declarations
    __fastcall Tinschrijvingenfaculteitreport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tinschrijvingenfaculteitreport *inschrijvingenfaculteitreport;
//---------------------------------------------------------------------------
#endif
