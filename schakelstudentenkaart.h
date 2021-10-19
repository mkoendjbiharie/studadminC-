//---------------------------------------------------------------------------

#ifndef schakelstudentenkaartH
#define schakelstudentenkaartH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class Tschakelstudentenkaartenreport : public TForm
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
        TQRLabel *QRLabel8;
        TQRDBText *QRDBText2;
        TQRDBText *QRDBText3;
        TQRDBText *QRDBText6;
        TQRDBText *QRDBText7;
        TQRDBText *QRDBText10;
        TQRLabel *QRLabel12;
        TQRImage *QRImage1;
        TQRLabel *collegejaar;
        TQRLabel *QRLabel10;
        TQRShape *Kleurbalk;
        TQRBand *PageFooterBand1;
        TQRSysData *QRSysData1;
        TQRSysData *QRSysData2;
        TQRSysData *QRSysData3;
        TQRLabel *QRLabel9;
        TQRLabel *QRLabel13;
        TQRLabel *QRLabel14;
        TQRLabel *QRLabel6;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall QuickRep1AfterPreview(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tschakelstudentenkaartenreport(TComponent* Owner);
        int huidig_collegejaar;
};
//---------------------------------------------------------------------------
extern PACKAGE Tschakelstudentenkaartenreport *schakelstudentenkaartenreport;
//---------------------------------------------------------------------------
#endif
