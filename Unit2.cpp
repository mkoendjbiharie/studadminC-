//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "sasdm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tkaart_op_richting_rep *kaart_op_richting_rep;
int huidig_collegejaar;
//---------------------------------------------------------------------------
__fastcall Tkaart_op_richting_rep::Tkaart_op_richting_rep(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
