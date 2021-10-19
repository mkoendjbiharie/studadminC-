//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
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
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TQuickRep *QuickRep1;
        TQRBand *TitleBand1;
        TQRBand *DetailBand1;
        TQRBand *PageHeaderBand1;
        TQRImage *QRImage1;
        TQRLabel *QRLabel12;
        TQRLabel *QRLabel10;
        TQRLabel *QRLabel1;
        TQRLabel *QRLabel2;
        TQRLabel *QRLabel3;
        TQRLabel *QRLabel4;
        TQRLabel *QRLabel5;
        TQRLabel *QRLabel6;
        TQRLabel *QRLabel7;
        TQRLabel *QRLabel8;
        TQRLabel *QRLabel13;
        TQRDBText *QRDBText10;
        TQRDBText *QRDBText9;
        TQRDBText *QRDBText8;
        TQRDBText *QRDBText7;
        TQRDBText *QRDBText4;
        TQRDBText *QRDBText5;
        TQRDBText *QRDBText6;
        TQRDBText *QRDBText3;
        TQRDBText *QRDBText2;
        TQRDBText *QRDBText1;
        TQRLabel *QRLabel11;
        TQRDBText *groenQRDBText;
        TQRDBText *blauwQRDBText;
        TQRDBText *roodQRDBText;
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
