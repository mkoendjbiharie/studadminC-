//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Splash.cpp", SplashForm);
USEFORM("Login.cpp", LoginForm);
USEFORM("Main.cpp", HoofdScherm);
USEFORM("sasdm.cpp", sasDataModule); /* TDataModule: File Type */
USEFORM("Person.cpp", PersonForm);
USEFORM("Facstud.cpp", Faculteitstudent);
USEFORM("Schakelstud.cpp", Schakelstudent);
USEFORM("Herinschrijving.cpp", HerinschrijvingForm);
USEFORM("Facstudafschr.cpp", FacStudAfschrijvingForm);
USEFORM("Schstudafschr.cpp", SchStudAfschrijvingForm);
USEFORM("Vooropleiding.cpp", VooropleidingForm);
USEFORM("Bevolkingsgroep.cpp", BevolkingsgroepForm);
USEFORM("kaartnaam.cpp", KaartNaamDlg);
USEFORM("kaartid.cpp", KaartIdDlg);
USEFORM("kaartrichting.cpp", KaartRichtingDlg);
USEFORM("kleurstudentenkaart.cpp", KleurStudentenkaartForm);
USEFORM("inschrijving_fac.cpp", InschrijvingfaculteitForm);
USEFORM("studentenkaart.cpp", studentenkaartenreport);
USEFORM("inschrijvingenfaculteit.cpp", inschrijvingenfaculteitreport);
USEFORM("Nationaliteit.cpp", NationaliteitForm);
USEFORM("Facnainschrijving.cpp", Facnainschr);
USEFORM("afschrijving_fac.cpp", AfschrijvingfaculteitForm);
USEFORM("CertFacStud.cpp", Certificatenfaculteitstudent);
USEFORM("CertSchStud.cpp", CertificaatSchakelStudent);
USEFORM("Vooraanmelding.cpp", VooraanmeldingForm);
USEFORM("StudentFuncties.cpp", StudentfunctiesForm);
USEFORM("Studentvacatures.cpp", StudentVacaturesForm);
USEFORM("Studentdeclaraties.cpp", StudentdeclaratiesForm);
USEFORM("Studentvooraanmeld.cpp", StudentvooraanmeldForm);
USEFORM("wachtwoord.cpp", WachtwoordForm);
USEFORM("Functie.cpp", FunctieForm);
USEFORM("Certificaat.cpp", CertificaatForm);
USEFORM("schakelreps.cpp", schakelrepsForm);
USEFORM("tutorial.cpp", TutorialForm);
USEFORM("about.cpp", AboutBox);
USEFORM("kaartbatch.cpp", KaartBatchDlg);
USEFORM("schakelstudentenkaart.cpp", schakelstudentenkaartenreport);
USEFORM("herinschrijving_fac.cpp", HerinschrijvingfaculteitForm);
USEFORM("graad.cpp", GraadForm);
USEFORM("studierichting.cpp", StudierichtingForm);
USEFORM("sasbasictablesmod.cpp", SasBasicTables); /* TDataModule: File Type */
USEFORM("intekenen.cpp", IntekenForm);
USEFORM("resultaten.cpp", ResultatenForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
            Application->Initialize();
                 Application->CreateForm(__classid(TSplashForm), &SplashForm);
                 Application->CreateForm(__classid(TsasDataModule), &sasDataModule);
                 Application->CreateForm(__classid(THoofdScherm), &HoofdScherm);
                 Application->CreateForm(__classid(TLoginForm), &LoginForm);
                 Application->CreateForm(__classid(TKaartIdDlg), &KaartIdDlg);
                 Application->CreateForm(__classid(TKaartRichtingDlg), &KaartRichtingDlg);
                 Application->CreateForm(__classid(Tinschrijvingenfaculteitreport), &inschrijvingenfaculteitreport);
                 Application->CreateForm(__classid(TTutorialForm), &TutorialForm);
                 Application->CreateForm(__classid(Tstudentenkaartenreport), &studentenkaartenreport);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->CreateForm(__classid(TKaartBatchDlg), &KaartBatchDlg);
                 Application->CreateForm(__classid(Tschakelstudentenkaartenreport), &schakelstudentenkaartenreport);
                 Application->CreateForm(__classid(TKaartNaamDlg), &KaartNaamDlg);
                 Application->CreateForm(__classid(TGraadForm), &GraadForm);
                 Application->CreateForm(__classid(TSasBasicTables), &SasBasicTables);
                 Application->Run();
        }
        catch (Exception &exception)
        {
            Application->ShowException(&exception);
        }
        catch (...)
        {
            try
            {
                throw Exception("");
            }
            catch (Exception &exception)
            {
                Application->ShowException(&exception);
            }
        }
        return 0;
}
//---------------------------------------------------------------------------
