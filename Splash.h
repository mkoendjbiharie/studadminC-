//---------------------------------------------------------------------------

#ifndef SplashH
#define SplashH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <IniFiles.hpp>
#include <stdio.h>
#include <io.h>
#include <QRExport.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TSplashForm : public TForm
{
__published:	// IDE-managed Components
        TImage *SplashImage;
        TLabel *Label1;
        TTimer *SplashTimer1;
        TLabel *Label2;
        TLabel *Label4;
        void __fastcall FormClick(TObject *Sender);
        void __fastcall SplashTimer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSplashForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSplashForm *SplashForm;
//---------------------------------------------------------------------------
#endif
