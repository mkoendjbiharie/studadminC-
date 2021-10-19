//---------------------------------------------------------------------------

#ifndef studierichtingH
#define studierichtingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include "Word_2K_SRVR.h"
#include <Buttons.hpp>
#include <Mask.hpp>
#include <OleServer.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <dbcgrids.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "Word_97_SRVR.h"
//---------------------------------------------------------------------------
class TStudierichtingForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label12;
        TLabel *Label1;
        TDBLookupComboBox *StudierichtingComboBox;
        TDBLookupComboBox *FaculteitComboBox;
        TDBLookupListBox *DBLookupListBox2;
        TLabel *Label3;
        TDBEdit *DBEdit1;
        TLabel *Label4;
        TDBEdit *DBEdit2;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TDBEdit *DBEdit3;
        TLabel *Label9;
        TDBCheckBox *DBCheckBox1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
   //     TWordApplication *WordApplication1;
        TOpenDialog *OpenDialog1;
        TDBGrid *DBGrid1;
        TDBEdit *DBEdit4;
        TDBEdit *DBEdit5;
        TDBEdit *DBEdit6;
        TDBEdit *DBEdit7;
        TDBEdit *DBEdit8;
        TDBEdit *DBEdit9;
        TDBLookupComboBox *DBLookupComboBox1;
        TDBLookupComboBox *DBLookupComboBox2;
        TDBLookupComboBox *DBLookupComboBox3;
        TLabel *ModusLabel;
        TDBComboBox *DBComboBox1;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FaculteitComboBoxClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall StudierichtingComboBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TStudierichtingForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStudierichtingForm *StudierichtingForm;
//---------------------------------------------------------------------------
#endif
