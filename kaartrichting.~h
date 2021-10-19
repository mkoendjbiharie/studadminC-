//----------------------------------------------------------------------------
#ifndef kaartrichtingH
#define kaartrichtingH
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
#include <ComCtrls.hpp>
//----------------------------------------------------------------------------
class TKaartRichtingDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
        TLabel *Label1;
        TLabel *Label2;
        TDBLookupComboBox *RichtingComboBox;
        TRadioGroup *CategorieRadioGroup;
        TLabel *Label3;
        TLabel *InschrijfjaarLabel;
        TEdit *InschrijfjaarEdit;
        TLabel *CollegejaarLabel;
        TUpDown *UpDown1;
        TLabel *Label5;
        TEdit *UpDownEdit;
        void __fastcall CancelBtnClick(TObject *Sender);
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall CategorieRadioGroupClick(TObject *Sender);
        void __fastcall UpDown1ChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall FormShow(TObject *Sender);
private:
public:
	virtual __fastcall TKaartRichtingDlg(TComponent* AOwner);
        String SoortReport;
};
//----------------------------------------------------------------------------
extern PACKAGE TKaartRichtingDlg *KaartRichtingDlg;
//----------------------------------------------------------------------------
#endif    
