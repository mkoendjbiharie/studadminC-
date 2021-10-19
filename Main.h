//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>

#include <OleServer.hpp>
#include <ImgList.hpp>

//---------------------------------------------------------------------------
class THoofdScherm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *SasMainMenu;
        TMenuItem *Bestand1;
        TMenuItem *Exit1;
        TMenuItem *Bewerken1;
        TMenuItem *Beeld1;
        TMenuItem *Student1;
        TMenuItem *Persoonsgegevens1;
        TMenuItem *N1;
        TMenuItem *Vooraanmelding1;
        TMenuItem *N2;
        TMenuItem *Functies1;
        TMenuItem *Declaraties1;
        TMenuItem *Aanpassen1;
        TMenuItem *Rapporten1;
        TMenuItem *Systeembeheer1;
        TMenuItem *Opties1;
        TMenuItem *Venster1;
        TMenuItem *Close1;
        TMenuItem *Help2;
        TMenuItem *About1;
        TMenuItem *HowtoUseHelp1;
        TMenuItem *Tutorial1;
        TMenuItem *SearchforHelpOn1;
        TMenuItem *Keyboard1;
        TMenuItem *Procedures1;
        TMenuItem *Commands1;
        TMenuItem *Index1;
        TMenuItem *Contents1;
        TMenuItem *Stamtabellen1;
        TMenuItem *Nationaliteit1;
        TMenuItem *Vooropleiding1;
        TMenuItem *Bevolkingsgroep1;
        TMenuItem *Studentenkaarten1;
        TMenuItem *Opnaam1;
        TMenuItem *Opidnummer1;
        TMenuItem *Opstudierichting1;
        TMenuItem *Kleurstudentenkaart1;
        TMenuItem *Studenten1;
        TMenuItem *Faculteit1;
        TMenuItem *Schakeljaar1;
        TMenuItem *Inschrijvingen1;
        TMenuItem *Afschrijvingen1;
        TMenuItem *N4;
        TMenuItem *Bevolkingsgroep2;
        TMenuItem *Nationaliteit2;
        TMenuItem *Diploma1;
        TMenuItem *Vooropleiding2;
        TMenuItem *N5;
        TMenuItem *Vacatures1;
        TMenuItem *Wachtwoord1;
        TMenuItem *Studentfunctie1;
        TMenuItem *Certificaat1;
        TMenuItem *Inschrijvingen2;
        TMenuItem *Afschrijvingen2;
        TMenuItem *N7;
        TMenuItem *Bevolkingsgroep3;
        TMenuItem *Nationaliteit3;
        TMenuItem *N8;
        TMenuItem *Vooropleiding3;
        TMenuItem *Faculteitstudent4;
        TMenuItem *Schakelstudent5;
        TMenuItem *Inschrijven1;
        TMenuItem *Afschrijven1;
        TMenuItem *Verwijderen1;
        TMenuItem *Opvragengegevens1;
        TMenuItem *Wijzigengegevens1;
        TMenuItem *N9;
        TMenuItem *Herinschrijven1;
        TMenuItem *Nainschrijven1;
        TMenuItem *Inschrijven2;
        TMenuItem *Afschrijven2;
        TMenuItem *N10;
        TMenuItem *Verwijderen2;
        TMenuItem *Opvragengegevens2;
        TMenuItem *Wijzigengegevens2;
        TMenuItem *N3;
        TMenuItem *DiplomasCertificaten2;
        TMenuItem *N11;
        TMenuItem *Certificaat2;
        TMenuItem *Batch1;
        TMenuItem *F1;
        TMenuItem *N6;
        TMenuItem *Opnaam2;
        TMenuItem *Opidnummer2;
        TMenuItem *Batch2;
        TMainMenu *SasMainMenu1;
        TMenuItem *MenuItem1;
        TMenuItem *MenuItem2;
        TMenuItem *MenuItem4;
        TMenuItem *MenuItem5;
        TMenuItem *MenuItem6;
        TMenuItem *MenuItem7;
        TMenuItem *MenuItem8;
        TMenuItem *MenuItem9;
        TMenuItem *MenuItem10;
        TMenuItem *MenuItem11;
        TMenuItem *MenuItem12;
        TMenuItem *MenuItem13;
        TMenuItem *MenuItem14;
        TMenuItem *MenuItem15;
        TMenuItem *MenuItem16;
        TMenuItem *MenuItem17;
        TMenuItem *MenuItem18;
        TMenuItem *MenuItem19;
        TMenuItem *MenuItem20;
        TMenuItem *MenuItem21;
        TMenuItem *MenuItem22;
        TMenuItem *MenuItem23;
        TMenuItem *MenuItem24;
        TMenuItem *MenuItem25;
        TMenuItem *MenuItem26;
        TMenuItem *MenuItem27;
        TMenuItem *MenuItem28;
        TMenuItem *MenuItem29;
        TMenuItem *MenuItem30;
        TMenuItem *MenuItem31;
        TMenuItem *MenuItem32;
        TMenuItem *MenuItem33;
        TMenuItem *MenuItem34;
        TMenuItem *MenuItem35;
        TMenuItem *MenuItem36;
        TMenuItem *MenuItem37;
        TMenuItem *MenuItem38;
        TMenuItem *MenuItem39;
        TMenuItem *MenuItem40;
        TMenuItem *MenuItem41;
        TMenuItem *MenuItem42;
        TMenuItem *MenuItem43;
        TMenuItem *MenuItem44;
        TMenuItem *MenuItem45;
        TMenuItem *MenuItem46;
        TMenuItem *MenuItem47;
        TMenuItem *MenuItem48;
        TMenuItem *MenuItem49;
        TMenuItem *MenuItem50;
        TMenuItem *MenuItem51;
        TMenuItem *MenuItem52;
        TMenuItem *MenuItem53;
        TMenuItem *MenuItem54;
        TMenuItem *MenuItem55;
        TMenuItem *MenuItem56;
        TMenuItem *MenuItem57;
        TMenuItem *MenuItem58;
        TMenuItem *MenuItem59;
        TMenuItem *MenuItem60;
        TMenuItem *MenuItem61;
        TMenuItem *MenuItem62;
        TMenuItem *MenuItem63;
        TMenuItem *MenuItem64;
        TMenuItem *MenuItem65;
        TMenuItem *MenuItem66;
        TMenuItem *MenuItem67;
        TMenuItem *MenuItem68;
        TMenuItem *MenuItem69;
        TMenuItem *MenuItem70;
        TMenuItem *MenuItem71;
        TMenuItem *MenuItem72;
        TMenuItem *MenuItem73;
        TMenuItem *MenuItem74;
        TMenuItem *MenuItem75;
        TMenuItem *MenuItem76;
        TMenuItem *MenuItem77;
        TMenuItem *MenuItem78;
        TMenuItem *MenuItem79;
        TMenuItem *MenuItem80;
        TMenuItem *MenuItem81;
        TMenuItem *MenuItem82;
        TMenuItem *MenuItem83;
        TMenuItem *MenuItem84;
        TMenuItem *Opstudierichting2;
        TMenuItem *Docent1;
        TMenuItem *Persoonsgegevens2;
        TMenuItem *Betrekking1;
        TMenuItem *N12;
        TMenuItem *Vacatures2;
        TMenuItem *Docent2;
        TMenuItem *Persoonsgegevens3;
        TMenuItem *Betrekking2;
        TMenuItem *N13;
        TMenuItem *Vacatures3;
        TMenuItem *Vakken1;
        TMenuItem *N14;
        TMenuItem *Cijfers1;
        TMenuItem *Tentamenresultaten1;
        TMenuItem *Tentamenresultaten2;
        TMenuItem *Functies2;
        TMenuItem *N15;
        TMenuItem *Faculteit2;
        TMenuItem *Bestuur1;
        TMenuItem *A1;
        TMenuItem *Studierichting1;
        TMenuItem *Vakken2;
        TMenuItem *Tentamens2;
        TMenuItem *Tentamens1;
        TMenuItem *Intekenlijst2;
        TMenuItem *Resultaten2;
        TMenuItem *C1;
        TMenuItem *Herinschrijvingen1;
        TMenuItem *Herinschrijvingen2;
        TMenuItem *Graad1;
        TMenuItem *Exit2;
        TMenuItem *Vacatures4;
        TMenuItem *Inzien1;
        TMenuItem *Toevoegen1;
        TMenuItem *Verwijderen3;
        TMenuItem *wijzigen1;
        TMenuItem *Richting1;
        TMenuItem *Orientatie1;
        TMenuItem *vakken3;
        TMenuItem *Gegevens1;
        TMenuItem *Inzien2;
        TMenuItem *Wijzigen2;
        TMenuItem *Cijferadministratie1;
        TMenuItem *Studentvolgsysteem1;
        TImageList *ImageList1;
        TBevel *Bevel1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall Persoonsgegevens1Click(TObject *Sender);
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall Herinschrijving1Click(TObject *Sender);
        void __fastcall Faculteitstudent2Click(TObject *Sender);
        void __fastcall Schakelstudent2Click(TObject *Sender);
        void __fastcall Nationaliteit1Click(TObject *Sender);
        void __fastcall Vooropleiding1Click(TObject *Sender);
        void __fastcall Bevolkingsgroep1Click(TObject *Sender);
        void __fastcall Opnaam1Click(TObject *Sender);
        void __fastcall Opidnummer1Click(TObject *Sender);
        void __fastcall Opstudierichting1Click(TObject *Sender);
        void __fastcall Kleurstudentenkaart1Click(TObject *Sender);
        void __fastcall Faculteitstudent3Click(TObject *Sender);
        void __fastcall Schakelstudent3Click(TObject *Sender);
        void __fastcall Faculteit1Click(TObject *Sender);
        void __fastcall Inschrijvingen1Click(TObject *Sender);
        void __fastcall Afschrijvingen1Click(TObject *Sender);
        void __fastcall Vooraanmelding1Click(TObject *Sender);
        void __fastcall Functies1Click(TObject *Sender);
        void __fastcall Vacatures1Click(TObject *Sender);
        void __fastcall Declaraties1Click(TObject *Sender);
        void __fastcall Wachtwoord1Click(TObject *Sender);
        void __fastcall Studentfunctie1Click(TObject *Sender);
        void __fastcall Certificaat1Click(TObject *Sender);
        void __fastcall Bevolkingsgroep2Click(TObject *Sender);
        void __fastcall Nationaliteit2Click(TObject *Sender);
        void __fastcall Diploma1Click(TObject *Sender);
        void __fastcall Vooropleiding2Click(TObject *Sender);
        void __fastcall Afschrijvingen2Click(TObject *Sender);
        void __fastcall Bevolkingsgroep3Click(TObject *Sender);
        void __fastcall Nationaliteit3Click(TObject *Sender);
        void __fastcall Vooropleiding3Click(TObject *Sender);
        void __fastcall Inschrijvingen2Click(TObject *Sender);
        void __fastcall Tutorial1Click(TObject *Sender);
        void __fastcall About1Click(TObject *Sender);
        void __fastcall Opvragengegevens1Click(TObject *Sender);
        void __fastcall Inschrijven1Click(TObject *Sender);
        void __fastcall Wijzigengegevens1Click(TObject *Sender);
        void __fastcall Verwijderen1Click(TObject *Sender);
        void __fastcall Inschrijven2Click(TObject *Sender);
        void __fastcall Verwijderen2Click(TObject *Sender);
        void __fastcall Opvragengegevens2Click(TObject *Sender);
        void __fastcall Wijzigengegevens2Click(TObject *Sender);
        void __fastcall DiplomasCertificaten2Click(TObject *Sender);
        void __fastcall Certificaat2Click(TObject *Sender);
        void __fastcall Nainschrijven1Click(TObject *Sender);
        void __fastcall Afschrijven2Click(TObject *Sender);
        void __fastcall Batch1Click(TObject *Sender);
        void __fastcall Afschrijven1Click(TObject *Sender);
        void __fastcall Opnaam2Click(TObject *Sender);
        void __fastcall Opidnummer2Click(TObject *Sender);
        void __fastcall Batch2Click(TObject *Sender);

        void __fastcall Venster1ItemClick(TObject *Sender);
        void __fastcall Opstudierichting2Click(TObject *Sender);
        void __fastcall Herinschrijvingen1Click(TObject *Sender);
        void __fastcall Persoonsgegevens2Click(TObject *Sender);
        void __fastcall Richting1Click(TObject *Sender);
        void __fastcall Persoonsgegevens3Click(TObject *Sender);
 /*       void __fastcall Toevoegen1Click(TObject *Sender);
        void __fastcall Verwijderen3Click(TObject *Sender);
        void __fastcall wijzigen1Click(TObject *Sender);
        void __fastcall Inzien1Click(TObject *Sender);
        void __fastcall Inzien2Click(TObject *Sender);
        void __fastcall Wijzigen2Click(TObject *Sender);
        void __fastcall Betrekking2Click(TObject *Sender);
        void __fastcall Vakken1Click(TObject *Sender);
        void __fastcall Tentamens1Click(TObject *Sender);
        void __fastcall Intekenlijst2Click(TObject *Sender);
        void __fastcall Resultaten2Click(TObject *Sender);
        void __fastcall Cijferadministratie1Click(TObject *Sender);     */

private:	// User declarations
public:		// User declarations
        __fastcall THoofdScherm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THoofdScherm *HoofdScherm;
//---------------------------------------------------------------------------
#endif