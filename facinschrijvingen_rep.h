//---------------------------------------------------------------------------

#ifndef facinschrijvingen_repH
#define facinschrijvingen_repH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <Graphics.hpp>
#include <QRCtrls.hpp>
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class Tfaculteit_inschrijvingen_report : public TForm
{
__published:	// IDE-managed Components
        TQuickRep *QuickRep1;
    TQRBand *QRBand3;
    TQRLabel *QRLabel1;
    TQRDBText *QRDBText1;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel3;
    TQRLabel *QRLabel4;
    TQRLabel *QRLabel5;
    TQRLabel *QRLabel6;
    TQRLabel *QRLabel7;
    TQRLabel *QRLabel8;
    TQRDBText *QRDBText2;
    TQRDBText *QRDBText3;
    TQRDBText *QRDBText6;
    TQRDBText *QRDBText7;
    TQRDBText *QRDBText8;
    TQRDBText *QRDBText9;
    TQRDBText *QRDBText10;
    TQRLabel *QRLabel12;
    TQRImage *QRImage1;
    TQRLabel *collegejaar;
    TQRLabel *QRLabel10;
    TQRLabel *QRLabel11;
    TQRMemo *QRMemo1;
    TQRBand *PageFooterBand1;
    TQRSysData *QRSysData1;
    TQRSysData *QRSysData2;
    TQRSysData *QRSysData3;
    TQRLabel *QRLabel9;
    TQRLabel *QRLabel13;
    TQRLabel *QRLabel14;
private:	// User declarations
public:		// User declarations
        __fastcall Tfaculteit_inschrijvingen_report(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfaculteit_inschrijvingen_report *faculteit_inschrijvingen_report;
//---------------------------------------------------------------------------
#endif
