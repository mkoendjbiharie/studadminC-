//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <process.h>
#include "constant.h"
#include "Main.h"
#include "Splash.h"
#include "about.h"
#include "Person.h"
#include "intekenen.h"
#include "Facstud.h"
#include "docentvak.h"
#include "Facnainschrijving.h"
#include "Schakelstud.h"
#include "Herinschrijving.h"
#include "Facstudafschr.h"
#include "Schstudafschr.h"
#include "Bevolkingsgroep.h"
#include "Nationaliteit.h"
#include "Vooropleiding.h"
#include "Unit1.h"
#include "kaartnaam.h"
#include "kaartid.h"
#include "kaartrichting.h"
#include "kleurstudentenkaart.h"
#include "resultaten.h"
#include "inschrijving_fac.h"
#include "afschrijving_fac.h"
#include "docentbetrekking.h"
#include "CertFacStud.h"
#include "vooraanmelding.h"
#include "CertSchStud.h"
#include "StudentFuncties.h"
#include "Studentvacatures.h"
#include "Studentdeclaraties.h"
#include "wachtwoord.h"
#include "Functie.h"
#include "Certificaat.h"
#include "schakelreps.h"
#include "tutorial.h"
#include "kaartbatch.h"
#include "herinschrijving_fac.h"
#include "graad.h"
#include "studierichting.h"
#include "Vak.h"
#include "tentamen.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma resource "*.dfm"
THoofdScherm *HoofdScherm;
String  categorie;
String usergroup;
String username;
String password;
bool student;
int  FModus, SModus;

//---------------------------------------------------------------------------
__fastcall THoofdScherm::THoofdScherm(TComponent* Owner)
        : TForm(Owner)
{
   //Application->MessageBox("mainform1","",MB_OK);

}
//---------------------------------------------------------------------------
void __fastcall THoofdScherm::FormClose(TObject *Sender, TCloseAction &Action)
{
      SplashForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Exit1Click(TObject *Sender)
{
      SplashForm->Close();
        Close();
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Persoonsgegevens1Click(TObject *Sender)
{
  student = true;
  if (Persoonsgegevens1->Checked)
     {PersonForm->Show();PersonForm->WindowState = wsNormal;}
  else if (Persoonsgegevens3->Checked)
        {PersonForm->Show();PersonForm->WindowState = wsNormal;
         Persoonsgegevens1->Checked = true; Persoonsgegevens3->Checked = false;}
        else
         {Application->CreateForm(__classid(TPersonForm), &PersonForm);
           Persoonsgegevens1->Checked = true;
          }


/*     TMenuItem *NewItem = new TMenuItem(Venster1); // create the separator
NewItem->Caption = "Person";
Venster1->Add(NewItem); // add it to the Window menu
NewItem->OnClick = Venster1ItemClick; */

}
//---------------------------------------------------------------------------


void __fastcall THoofdScherm::Close1Click(TObject *Sender)
{
  //ActiveMDIChild->Close();
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Herinschrijving1Click(TObject *Sender)
{
   if (!Herinschrijven1->Checked)
     {Application->CreateForm(__classid(THerinschrijvingForm), &HerinschrijvingForm);
      Herinschrijven1->Checked = true;
     }
  else
     {HerinschrijvingForm->Show();HerinschrijvingForm->WindowState = wsNormal;}
     TMenuItem *NewItem = new TMenuItem(Venster1); // create the separator
NewItem->Caption = "Herinschrijving";
Venster1->Add(NewItem); // add it to the Window menu
NewItem->OnClick = Venster1ItemClick;
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Faculteitstudent2Click(TObject *Sender)
{
 /* if (!Faculteitstudent2->Checked)
     {Application->CreateForm(__classid(TFacStudAfschrijvingForm), &FacStudAfschrijvingForm);

      Faculteitstudent2->Checked = true;
     }
   else
     {FacStudAfschrijvingForm->Show(); FacStudAfschrijvingForm->WindowState = wsNormal;}
*/
}
//---------------------------------------------------------------------------


void __fastcall THoofdScherm::Schakelstudent2Click(TObject *Sender)
{
 /* if (!Schakelstudent2->Checked)
     {Application->CreateForm(__classid(TSchStudAfschrijvingForm), &SchStudAfschrijvingForm);

      Schakelstudent2->Checked = true;
     }
   else
     {SchStudAfschrijvingForm->Show(); SchStudAfschrijvingForm->WindowState = wsNormal;}
 */
}
//---------------------------------------------------------------------------



void __fastcall THoofdScherm::Nationaliteit1Click(TObject *Sender)
{
    Application->CreateForm(__classid(TNationaliteitForm), &NationaliteitForm);
    TMenuItem *NewItem = new TMenuItem(Venster1); // create the separator
NewItem->Caption = "Nationaliteit";
Venster1->Add(NewItem); // add it to the Window menu
NewItem->OnClick = Venster1ItemClick;
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Vooropleiding1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TVooropleidingForm), &VooropleidingForm);
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Bevolkingsgroep1Click(TObject *Sender)
{
    Application->CreateForm(__classid(TBevolkingsgroepForm), &BevolkingsgroepForm);
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Opnaam1Click(TObject *Sender)
{
 /* if (!Opnaam1->Checked)
     {Application->CreateForm(__classid(TKaartNaamDlg), &KaartNaamDlg);

      Opnaam1->Checked = true;
     }   */

    KaartNaamDlg->SoortReport = "Faculteit";
    KaartNaamDlg->Show(); KaartNaamDlg->WindowState = wsNormal;
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Opidnummer1Click(TObject *Sender)
{
  KaartIdDlg->SoortReport = "Faculteit";
  KaartIdDlg->Show();
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Opstudierichting1Click(TObject *Sender)
{
   KaartRichtingDlg->SoortReport = "Faculteit";
   KaartRichtingDlg->Show();
}
//---------------------------------------------------------------------------


void __fastcall THoofdScherm::Kleurstudentenkaart1Click(TObject *Sender)
{
   if (!Kleurstudentenkaart1->Checked)
     {Application->CreateForm(__classid(TKleurStudentenkaartForm), &KleurStudentenkaartForm);
      Kleurstudentenkaart1->Checked = true;
     }
   else
     {KleurStudentenkaartForm->Show(); KleurStudentenkaartForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Faculteitstudent3Click(TObject *Sender)
{
 /* if (!Faculteitstudent3->Checked)
     {Application->CreateForm(__classid(TFaculteitstudent), &Faculteitstudent);
      Faculteitstudent3->Checked = true;
     }
  else
     {Faculteitstudent->Show();Faculteitstudent->WindowState = wsNormal;}
     FModus = 1;
*/
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Schakelstudent3Click(TObject *Sender)
{
/*   if (!Schakelstudent3->Checked)
     {Application->CreateForm(__classid(TSchakelstudent), &Schakelstudent);
      Schakelstudent3->Checked = true;
     }
  else
     {Schakelstudent->Show();Schakelstudent->WindowState = wsNormal;}
*/
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Faculteit1Click(TObject *Sender)
{
      if (!Faculteit1->Checked)
     {Application->CreateForm(__classid(TInschrijvingfaculteitForm), &InschrijvingfaculteitForm);
      Faculteit1->Checked = true;
     }
  else
     {InschrijvingfaculteitForm->Show();InschrijvingfaculteitForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------


void __fastcall THoofdScherm::Inschrijvingen1Click(TObject *Sender)
{
      if (!Inschrijvingen1->Checked)
     {Application->CreateForm(__classid(TInschrijvingfaculteitForm), &InschrijvingfaculteitForm);
      Inschrijvingen1->Checked = true;
     }
  else
     {InschrijvingfaculteitForm->Show();InschrijvingfaculteitForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Afschrijvingen1Click(TObject *Sender)
{
  categorie = "afschrijvingen";
  if (!Afschrijvingen1->Checked)
     {Application->CreateForm(__classid(TAfschrijvingfaculteitForm), &AfschrijvingfaculteitForm);
      Afschrijvingen1->Checked = true;
     }
  else
     {AfschrijvingfaculteitForm->Show();AfschrijvingfaculteitForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------



void __fastcall THoofdScherm::Vooraanmelding1Click(TObject *Sender)
{
if (!Vooraanmelding1->Checked)
     {Application->CreateForm(__classid(TVooraanmeldingForm), &VooraanmeldingForm);
      Vooraanmelding1->Checked = true;
     }
  else
     {VooraanmeldingForm->Show();VooraanmeldingForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Functies1Click(TObject *Sender)
{
   if (!Functies1->Checked)
     {Application->CreateForm(__classid(TStudentfunctiesForm), &StudentfunctiesForm);
      Functies1->Checked = true;
     }
  else
     {StudentfunctiesForm->Show();StudentfunctiesForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Vacatures1Click(TObject *Sender)
{
    if (!Vacatures1->Checked)
     {Application->CreateForm(__classid(TStudentVacaturesForm), &StudentVacaturesForm);
      Vacatures1->Checked = true;
     }
  else
     {StudentVacaturesForm->Show();StudentVacaturesForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Declaraties1Click(TObject *Sender)
{
  if (!Declaraties1->Checked)
     {Application->CreateForm(__classid(TStudentdeclaratiesForm), &StudentdeclaratiesForm);
      Declaraties1->Checked = true;
     }
  else
     {StudentdeclaratiesForm->Show();StudentdeclaratiesForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Wachtwoord1Click(TObject *Sender)
{
    Application->CreateForm(__classid(TWachtwoordForm), &WachtwoordForm);
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Studentfunctie1Click(TObject *Sender)
{
 if (!Studentfunctie1->Checked)
  {
    Application->CreateForm(__classid(TFunctieForm), &FunctieForm);
    Studentfunctie1->Checked = true;
  }
 else
  {FunctieForm->Show();FunctieForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Certificaat1Click(TObject *Sender)
{
 if (!Certificaat1->Checked)
  {
    Application->CreateForm(__classid(TCertificaatForm), &CertificaatForm);
    Certificaat1->Checked = true;
  }
 else
   {CertificaatForm->Show();CertificaatForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Bevolkingsgroep2Click(TObject *Sender)
{
  categorie = "bevolkingsgroep";
  if (!Bevolkingsgroep2->Checked)
     {Application->CreateForm(__classid(TAfschrijvingfaculteitForm), &AfschrijvingfaculteitForm);
      Bevolkingsgroep2->Checked = true;
     }
  else
     {AfschrijvingfaculteitForm->Show();AfschrijvingfaculteitForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Nationaliteit2Click(TObject *Sender)
{
  categorie = "nationaliteit";
  if (!Nationaliteit2->Checked)
     {Application->CreateForm(__classid(TAfschrijvingfaculteitForm), &AfschrijvingfaculteitForm);
      Nationaliteit2->Checked = true;
     }
  else
     {AfschrijvingfaculteitForm->Show();AfschrijvingfaculteitForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Diploma1Click(TObject *Sender)
{
  categorie = "diploma";
  if (!Diploma1->Checked)
     {Application->CreateForm(__classid(TAfschrijvingfaculteitForm), &AfschrijvingfaculteitForm);
      Diploma1->Checked = true;
     }
  else
     {AfschrijvingfaculteitForm->Show();AfschrijvingfaculteitForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Vooropleiding2Click(TObject *Sender)
{
  categorie = "vooropleiding";
  if (!Vooropleiding2->Checked)
     {Application->CreateForm(__classid(TAfschrijvingfaculteitForm), &AfschrijvingfaculteitForm);
      Vooropleiding2->Checked = true;
     }
  else
     {AfschrijvingfaculteitForm->Show();AfschrijvingfaculteitForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------


void __fastcall THoofdScherm::Afschrijvingen2Click(TObject *Sender)
{
  categorie = "afschrijvingen";
  if (!Afschrijvingen2->Checked)
     {Application->CreateForm(__classid(TschakelrepsForm), &schakelrepsForm);
      Afschrijvingen2->Checked = true;
     }
  else
     {schakelrepsForm->Show();schakelrepsForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Bevolkingsgroep3Click(TObject *Sender)
{
  categorie = "bevolkingsgroep";
  if (!Bevolkingsgroep3->Checked)
     {Application->CreateForm(__classid(TschakelrepsForm), &schakelrepsForm);
      Bevolkingsgroep3->Checked = true;
     }
  else
     {schakelrepsForm->Show();schakelrepsForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Nationaliteit3Click(TObject *Sender)
{
  categorie = "nationaliteit";
  if (!Nationaliteit3->Checked)
     {Application->CreateForm(__classid(TschakelrepsForm), &schakelrepsForm);
      Nationaliteit3->Checked = true;
     }
  else
     {schakelrepsForm->Show();schakelrepsForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Vooropleiding3Click(TObject *Sender)
{
  categorie = "vooropleiding";
  if (!Vooropleiding3->Checked)
     {Application->CreateForm(__classid(TschakelrepsForm), &schakelrepsForm);
      Vooropleiding3->Checked = true;
     }
  else
     {schakelrepsForm->Show();schakelrepsForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------


void __fastcall THoofdScherm::Inschrijvingen2Click(TObject *Sender)
{
  categorie = "inschrijving";
  if (!Inschrijvingen2->Checked)
     {Application->CreateForm(__classid(TschakelrepsForm), &schakelrepsForm);
      Inschrijvingen2->Checked = true;
     }
  else
     {schakelrepsForm->Show();schakelrepsForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Tutorial1Click(TObject *Sender)
{
   TutorialForm->Show();
}
//---------------------------------------------------------------------------



void __fastcall THoofdScherm::About1Click(TObject *Sender)
{
   AboutBox->Show();
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Opvragengegevens1Click(TObject *Sender)
{
 FModus = READ;
  bool bestaat = false;
  for (int i = 0; i < Screen->FormCount; i++)
{
  if (Screen->Forms[i]->Name == "Faculteitstudent")
   { bestaat = true; break;}
}
  if (!bestaat)
     {Application->CreateForm(__classid(TFaculteitstudent), &Faculteitstudent);
   //   Opvragengegevens1->Checked = true;
     }
  else
     {Faculteitstudent->Show();Faculteitstudent->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Inschrijven1Click(TObject *Sender)
{
  FModus = ENTRY;
  bool bestaat = false;
  for (int i = 0; i < Screen->FormCount; i++)
{
  if (Screen->Forms[i]->Name == "Faculteitstudent")
   { bestaat = true; break;}
}
  if (!bestaat)
     {Application->CreateForm(__classid(TFaculteitstudent), &Faculteitstudent);
    //  Inschrijven1->Checked = true;
     }
  else
     {Faculteitstudent->Show();Faculteitstudent->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Wijzigengegevens1Click(TObject *Sender)
{
  FModus = EDIT;
 bool bestaat = false;
  for (int i = 0; i < Screen->FormCount; i++)
{
  if (Screen->Forms[i]->Name == "Faculteitstudent")
   { bestaat = true; break;}
}
  if (!bestaat)
     {Application->CreateForm(__classid(TFaculteitstudent), &Faculteitstudent);
//      Wijzigengegevens1->Checked = true;
     }
  else
     {Faculteitstudent->Show();Faculteitstudent->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Verwijderen1Click(TObject *Sender)
{
   FModus = DELETE;
   bool bestaat = false;
  for (int i = 0; i < Screen->FormCount; i++)
{
  if (Screen->Forms[i]->Name == "Faculteitstudent")
   { bestaat = true; break;}
}
  if (!bestaat)
     {Application->CreateForm(__classid(TFaculteitstudent), &Faculteitstudent);
//      Verwijderen1->Checked = true;
     }
  else
     {Faculteitstudent->Show();Faculteitstudent->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Inschrijven2Click(TObject *Sender)
{
   SModus = 1;
  bool bestaat = false;
  for (int i = 0; i < Screen->FormCount; i++)
{
  if (Screen->Forms[i]->Name == "Schakelstudent")
   { bestaat = true; break;}
}
  if (!bestaat)
     {Application->CreateForm(__classid(TSchakelstudent), &Schakelstudent);
    //  Inschrijven1->Checked = true;
     }
  else
     {Schakelstudent->Show();Schakelstudent->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Verwijderen2Click(TObject *Sender)
{
     SModus = 3;
   bool bestaat = false;
  for (int i = 0; i < Screen->FormCount; i++)
{
  if (Screen->Forms[i]->Name == "Schakelstudent")
   { bestaat = true; break;}
}
  if (!bestaat)
     {Application->CreateForm(__classid(TSchakelstudent), &Schakelstudent);
//      Verwijderen1->Checked = true;
     }
  else
     {Schakelstudent->Show();Schakelstudent->WindowState = wsNormal;}

 }
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Opvragengegevens2Click(TObject *Sender)
{
  SModus = 0;
  bool bestaat = false;
  for (int i = 0; i < Screen->FormCount; i++)
{
  if (Screen->Forms[i]->Name == "Schakelstudent")
   { bestaat = true; break;}
}
  if (!bestaat)
     {Application->CreateForm(__classid(TSchakelstudent), &Schakelstudent);
   //   Opvragengegevens1->Checked = true;
     }
  else
     {Schakelstudent->Show();Schakelstudent->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Wijzigengegevens2Click(TObject *Sender)
{
   SModus = 2;
 bool bestaat = false;
  for (int i = 0; i < Screen->FormCount; i++)
{
  if (Screen->Forms[i]->Name == "Schakelstudent")
   { bestaat = true; break;}
}
  if (!bestaat)
     {Application->CreateForm(__classid(TSchakelstudent), &Schakelstudent);
//      Wijzigengegevens1->Checked = true;
     }
  else
     {Schakelstudent->Show();Schakelstudent->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------


void __fastcall THoofdScherm::DiplomasCertificaten2Click(TObject *Sender)
{
   if (!DiplomasCertificaten2->Checked)
     {Application->CreateForm(__classid(TCertificatenfaculteitstudent), &Certificatenfaculteitstudent);
      DiplomasCertificaten2->Checked = true;
     }
  else
     {Certificatenfaculteitstudent->Show();Certificatenfaculteitstudent->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Certificaat2Click(TObject *Sender)
{
 if (!Certificaat2->Checked)
     {Application->CreateForm(__classid(TCertificaatSchakelStudent), &CertificaatSchakelStudent);
      Certificaat2->Checked = true;
     }
  else
     {CertificaatSchakelStudent->Show();CertificaatSchakelStudent->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------


void __fastcall THoofdScherm::Nainschrijven1Click(TObject *Sender)
{
  FModus = AFTERENTRY;
  bool bestaat = false;
  for (int i = 0; i < Screen->FormCount; i++)
    {
      if (Screen->Forms[i]->Name == "Faculteitstudent")
      { bestaat = true; break;}
    }
  if (!bestaat)
     Application->CreateForm(__classid(TFaculteitstudent), &Faculteitstudent);
  else
     {Faculteitstudent->Show();Faculteitstudent->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Afschrijven2Click(TObject *Sender)
{
     if (!Afschrijven2->Checked)
     {Application->CreateForm(__classid(TSchStudAfschrijvingForm), &SchStudAfschrijvingForm);

      Afschrijven2->Checked = true;
     }
   else
     {SchStudAfschrijvingForm->Show(); SchStudAfschrijvingForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Batch1Click(TObject *Sender)
{
  KaartBatchDlg->SoortReport = "Faculteit";
  KaartBatchDlg->Show();
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Afschrijven1Click(TObject *Sender)
{
 bool bestaat = false;
  for (int i = 0; i < Screen->FormCount; i++)
{
  if (Screen->Forms[i]->Name == "FacStudAfschrijvingForm")
   { bestaat = true; break;}
}
  if (!bestaat)
     {Application->CreateForm(__classid(TFacStudAfschrijvingForm), &FacStudAfschrijvingForm);
//      Wijzigengegevens1->Checked = true;
     }
  else
     {FacStudAfschrijvingForm->Show();FacStudAfschrijvingForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Opnaam2Click(TObject *Sender)
{
  /*  if (!Opnaam2->Checked)
     {Application->CreateForm(__classid(TKaartNaamDlg), &KaartNaamDlg);
      Opnaam2->Checked = true;
     }       */
    KaartNaamDlg->SoortReport = "Schakel";
    KaartNaamDlg->Show(); KaartNaamDlg->WindowState = wsNormal;
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Opidnummer2Click(TObject *Sender)
{
    KaartIdDlg->SoortReport = "Schakel";
    KaartIdDlg->Show();
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Batch2Click(TObject *Sender)
{
    KaartBatchDlg->SoortReport = "Schakel";
    KaartBatchDlg->Show();
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Venster1ItemClick(TObject *Sender)
{
  String  scherm =  ((TMenuItem *)Sender)->Caption + "Form";
   for (int i = 0; i < Screen->FormCount; i++)
    {
      if (String("&") + Screen->Forms[i]->Name ==  scherm)
       { Screen->Forms[i]->Show(); break;}
    }

}
//---------------------------------------------------------------------------


void __fastcall THoofdScherm::Opstudierichting2Click(TObject *Sender)
{
    KaartRichtingDlg->SoortReport = "Schakel";
    KaartRichtingDlg->Show();
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Herinschrijvingen1Click(TObject *Sender)
{
   if (!Herinschrijvingen1->Checked)
     {Application->CreateForm(__classid(THerinschrijvingfaculteitForm), &HerinschrijvingfaculteitForm);
      Herinschrijvingen1->Checked = true;
     }
   else
     {HerinschrijvingfaculteitForm->Show();HerinschrijvingfaculteitForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Persoonsgegevens2Click(TObject *Sender)
{
    if (!Persoonsgegevens1->Checked)
     {Application->CreateForm(__classid(TPersonForm), &PersonForm);
      Persoonsgegevens1->Checked = true;
     }
  else
     {PersonForm->Show();PersonForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Richting1Click(TObject *Sender)
{
  if (!Richting1->Checked)
     {Application->CreateForm(__classid(TStudierichtingForm), &StudierichtingForm);
      Richting1->Checked = true;
     }
  else
     {StudierichtingForm->Show();StudierichtingForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Persoonsgegevens3Click(TObject *Sender)
{
  student = false;

  if (Persoonsgegevens3->Checked)
     {PersonForm->Show();PersonForm->WindowState = wsNormal;}
  else if (Persoonsgegevens1->Checked)
        {PersonForm->Show();PersonForm->WindowState = wsNormal;
         Persoonsgegevens3->Checked = true; Persoonsgegevens1->Checked = false;}
        else
         {Application->CreateForm(__classid(TPersonForm), &PersonForm);
           Persoonsgegevens3->Checked = true;
          }
} /*
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Toevoegen1Click(TObject *Sender)
{
   FModus = ENTRY;
   bool bestaat = false;
    for (int i = 0; i < Screen->FormCount; i++)
     {
    if (Screen->Forms[i]->Name == "VakForm")
      { bestaat = true; break;}
     }
    if (!bestaat)
     {Application->CreateForm(__classid(TVakForm), &VakForm);
     }
  else
     {VakForm->Show(); VakForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Verwijderen3Click(TObject *Sender)
{
   FModus = DEL;
    bool bestaat = false;
    for (int i = 0; i < Screen->FormCount; i++)
     {
    if (Screen->Forms[i]->Name == "VakForm")
      { bestaat = true; break;}
     }
    if (!bestaat)
     {Application->CreateForm(__classid(TVakForm), &VakForm);
     }
  else
     {VakForm->Show(); VakForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::wijzigen1Click(TObject *Sender)
{
  FModus = EDIT;
  bool bestaat = false;
    for (int i = 0; i < Screen->FormCount; i++)
     {
    if (Screen->Forms[i]->Name == "VakForm")
      { bestaat = true; break;}
     }
    if (!bestaat)
     {Application->CreateForm(__classid(TVakForm), &VakForm);
     }
  else
     {VakForm->Show(); VakForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Inzien1Click(TObject *Sender)
{
   FModus = READ;
  bool bestaat = false;
    for (int i = 0; i < Screen->FormCount; i++)
     {
    if (Screen->Forms[i]->Name == "VakForm")
      { bestaat = true; break;}
     }
    if (!bestaat)
     {Application->CreateForm(__classid(TVakForm), &VakForm);
     }
  else
     {VakForm->Show(); VakForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------


void __fastcall THoofdScherm::Inzien2Click(TObject *Sender)
{
     FModus = READ;
  bool bestaat = false;
    for (int i = 0; i < Screen->FormCount; i++)
     {
    if (Screen->Forms[i]->Name == "StudierichtingForm")
      { bestaat = true; break;}
     }
    if (!bestaat)
     {Application->CreateForm(__classid(TStudierichtingForm), &StudierichtingForm);
     }
  else
     {StudierichtingForm->Show(); StudierichtingForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Wijzigen2Click(TObject *Sender)
{
       FModus = EDIT;
  bool bestaat = false;
    for (int i = 0; i < Screen->FormCount; i++)
     {
    if (Screen->Forms[i]->Name == "StudierichtingForm")
      { bestaat = true; break;}
     }
    if (!bestaat)
     {Application->CreateForm(__classid(TStudierichtingForm), &StudierichtingForm);
     }
  else
     {StudierichtingForm->Show(); StudierichtingForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------


void __fastcall THoofdScherm::Betrekking2Click(TObject *Sender)
{
  FModus = EDIT;
  bool bestaat = false;
    for (int i = 0; i < Screen->FormCount; i++)
     {
    if (Screen->Forms[i]->Name == "DocentbetrekkingForm")
      { bestaat = true; break;}
     }
    if (!bestaat)
     {Application->CreateForm(__classid(TDocentBetrekkingForm), &DocentBetrekkingForm);
     }
  else
     {DocentBetrekkingForm->Show(); DocentBetrekkingForm->WindowState = wsNormal;}
}
//---------------------------------------------------------------------------


void __fastcall THoofdScherm::Vakken1Click(TObject *Sender)
{
   bool bestaat = false;
    for (int i = 0; i < Screen->FormCount; i++)
     {
    if (Screen->Forms[i]->Name == "DocentVakForm")
      { bestaat = true; break;}
     }
    if (!bestaat)
     {Application->CreateForm(__classid(TDocentVakForm), &DocentVakForm);
      DocentVakForm->Show();
     }
  else
     {DocentVakForm->Show(); DocentVakForm->WindowState = wsNormal;}

}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Tentamens1Click(TObject *Sender)
{
   bool bestaat = false;
    for (int i = 0; i < Screen->FormCount; i++)
     {
    if (Screen->Forms[i]->Name == "TentamenForm")
      { bestaat = true; break;}
     }
    if (!bestaat)
     {Application->CreateForm(__classid(TTentamenForm), &TentamenForm);
     }
  else
     {TentamenForm->Show(); TentamenForm->WindowState = wsNormal;}
  TentamenForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Intekenlijst2Click(TObject *Sender)
{
   bool bestaat = false;
    for (int i = 0; i < Screen->FormCount; i++)
     {
    if (Screen->Forms[i]->Name == "IntekenForm")
      { bestaat = true; break;}
     }
    if (!bestaat)
     {Application->CreateForm(__classid(TIntekenForm), &IntekenForm);
     }
  else
     {IntekenForm->Show(); IntekenForm->WindowState = wsNormal;}
  IntekenForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall THoofdScherm::Resultaten2Click(TObject *Sender)
{
 bool bestaat = false;
    for (int i = 0; i < Screen->FormCount; i++)
     {
    if (Screen->Forms[i]->Name == "ResultatenForm")
      { bestaat = true; break;}
     }
    if (!bestaat)
     {Application->CreateForm(__classid(TResultatenForm), &ResultatenForm);
     }
  else
     {ResultatenForm->Show(); ResultatenForm->WindowState = wsNormal;}
  ResultatenForm->Show();
}
//---------------------------------------------------------------------------



void __fastcall THoofdScherm::Cijferadministratie1Click(TObject *Sender)
{
 execl(".\/cijferadministratie\/cijferadministratie.exe"  ,username.c_str(), password.c_str(), 2,NULL);
}
//---------------------------------------------------------------------------

    */

