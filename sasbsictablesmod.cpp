//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "sasbsictablesmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSasBasicTables *SasBasicTables;
//---------------------------------------------------------------------------
__fastcall TSasBasicTables::TSasBasicTables(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
