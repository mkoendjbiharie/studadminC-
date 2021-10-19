//----------------------------------------------------------------------------
#ifndef kaartnaamH
#define kaartnaamH
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
class TKaartNaamDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
        TEdit *NaamEdit;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *CollegejaarLabel;
        TEdit *UpDownEdit;
        TUpDown *UpDown1;
        void __fastcall CancelBtnClick(TObject *Sender);
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall UpDown1ChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall FormShow(TObject *Sender);
private:
public:
	virtual __fastcall TKaartNaamDlg(TComponent* AOwner);
        String SoortReport;
};
//----------------------------------------------------------------------------
extern PACKAGE TKaartNaamDlg *KaartNaamDlg;
//----------------------------------------------------------------------------
#endif    
