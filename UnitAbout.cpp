//---------------------------------------------------------------------------
#include <vcl.h>
extern "C" {
#include <freesteam/config.h>
}
#pragma hdrstop

#include "UnitAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAbout *FormAbout;

static bool RussianLocale = true;
//---------------------------------------------------------------------------
__fastcall TFormAbout::TFormAbout(TComponent* Owner)
  : TForm(Owner)
{
//
//
}
//---------------------------------------------------------------------------
void __fastcall TFormAbout::OnCreate(TObject *Sender)
{
//
//
  LCID lcid = GetUserDefaultLCID ();
  if ((lcid & 0xff) != 0x19) {
    RussianLocale = false;
  }
  //RussianLocale = false;

  SetTranslation ();

  LabelModule->Caption = ((TForm*) Owner)->Caption;
  unsigned short Year, Month, Day;
  Now ().DecodeDate (&Year, &Month, &Day);
  String S;
  int BegYear = 2016;
  if (BegYear != Year)
    S.sprintf ("%s %d — %d", (RussianLocale) ? "Екатеринбург" : "Ekaterinburg", BegYear, Year);
  else
    S.sprintf ("%s %d", (RussianLocale) ? "Екатеринбург" : "Ekaterinburg", Year);
  LabelYears->Caption = S;

  // Информация о файле
  //
  // Get the size of the FileVersionInformatioin
  DWORD Tmp;
  DWORD InfoSize = GetFileVersionInfoSize (Application->ExeName.c_str (), &Tmp);

  if (InfoSize) {
    // Allocate memory for the file version information
    char* Info = new char [InfoSize];
    // Get the information
    if (GetFileVersionInfo (Application->ExeName.c_str (), 0, InfoSize, (void*) Info)) {

      // Query the information for the version
      PVSFixedFileInfo FileInfo;
      UINT FileInfoSize;
      if (VerQueryValue (Info, "\\", (void**) &FileInfo, &FileInfoSize)) {

        // Now fill in the version information
        int Major1 = FileInfo->dwFileVersionMS >> 16;
        int Major2 = FileInfo->dwFileVersionMS & 0x0000FFFF;
        int Minor1 = FileInfo->dwFileVersionLS >> 16;
        int Minor2 = FileInfo->dwFileVersionLS & 0x0000FFFF;

        FileVersion = ((RussianLocale) ? "Версия " : "Version ") +
                                  IntToStr (Major1) + "." + IntToStr (Major2) + "." +
                                  IntToStr (Minor1) + "." + IntToStr (Minor2);
      }
    }
    delete [] Info;
  }

  LabelFileVersion->Caption = FileVersion;

  LabelFreesteamVersion->Caption = LabelFreesteamVersion->Caption + FREESTEAM_VERSION;
}
//---------------------------------------------------------------------------

void __fastcall TFormAbout::LabelLinkClick(TObject *Sender)
{
  ShellExecute(Sender, "OPEN", "https://github.com/ayampolsky/IAPWSCalculator", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TFormAbout::LabelFreesteamLinkClick(TObject *Sender)
{
  ShellExecute(Sender, "OPEN", "http://sourceforge.net/projects/freesteam/", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TFormAbout::LabelFugueIconsLinkClick(TObject *Sender)
{
  ShellExecute(Sender, "OPEN", "http://p.yusukekamiyamane.com/", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TFormAbout::SetTranslation ()
{
  if (!RussianLocale) {
    Caption = "About";
    LabelDescription->Caption = "Water and steam properties calculator in IAPWS-IF97 standard.";
    LabelFreesteamVersion->Caption = "Based on Freesteam.";
    LabelFugueIconsVersion->Caption = "Uses Fugue Icons 3.5.6 by Yusuke Kamiyamane";
    LabelFileVersion->Caption = "Version 1.0.9.10";
    LabelCompanyName->Caption = "Institute of Thermal Physics, Urals branch of RAS";
    LabelYears->Caption = "Ekaterinburg 2000 — 2000";
  }
}
//---------------------------------------------------------------------------

