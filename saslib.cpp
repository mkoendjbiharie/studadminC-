//---------------------------------------------------------------------------


#pragma hdrstop
#include <vcl.h>

//#include "string.h"
#include "saslib.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

String & jaar_voor(String &datum)
{
   datum = datum.SubString(4, 4) + datum.SubString(2,2) + datum.SubString(0,2);
   return datum;
}
//---------------------------------------------------------------------------

String & jaar_achter(String &datum)
{
   datum = datum.SubString(6, 2) + datum.SubString(4,2) + datum.SubString(0,4);
   return datum;
}