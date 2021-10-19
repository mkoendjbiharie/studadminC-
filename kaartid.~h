//----------------------------------------------------------------------------
#ifndef kaartidH
#define kaartidH
//----------------------------------------------------------------------------
#include <vcl\ExtCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <ComCtrls.hpp>
//----------------------------------------------------------------------------
class TKaartIdDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
        TLabel *Label1;
        TEdit *IdnummerEdit;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *CollegejaarLabel;
        TUpDown *UpDown1;
        TEdit *UpDownEdit;
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall CancelBtnClick(TObject *Sender);
        void __fastcall UpDown1ChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall FormShow(TObject *Sender);
private:
public:
	virtual __fastcall TKaartIdDlg(TComponent* AOwner);
        String SoortReport;
};
//----------------------------------------------------------------------------
extern PACKAGE TKaartIdDlg *KaartIdDlg;
//----------------------------------------------------------------------------
#endif    
