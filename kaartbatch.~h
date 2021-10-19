//----------------------------------------------------------------------------
#ifndef kaartbatchH
#define kaartbatchH
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
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
//----------------------------------------------------------------------------
class TKaartBatchDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
        TEdit *StudienrEdit;
        TLabel *StudienrLabel;
        TButton *VoegToeButton;
        TListBox *BatchListBox;
        TListBox *NummerListBox;
        TButton *VerwijderButton;
        TLabel *Label1;
        TLabel *CollegejaarLabel;
        TUpDown *UpDown1;
        TEdit *UpDownEdit;
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall VoegToeButtonClick(TObject *Sender);
        void __fastcall CancelBtnClick(TObject *Sender);
        void __fastcall VerwijderButtonClick(TObject *Sender);
        void __fastcall UpDown1ChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall FormShow(TObject *Sender);
private:
public:
	virtual __fastcall TKaartBatchDlg(TComponent* AOwner);
        String SoortReport;
};
//----------------------------------------------------------------------------
extern PACKAGE TKaartBatchDlg *KaartBatchDlg;
//----------------------------------------------------------------------------
#endif    
