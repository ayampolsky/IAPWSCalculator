//---------------------------------------------------------------------------

#include <vcl.h>
extern "C" {
#include <freesteam/steam_ps.h>
#include <freesteam/steam_pT.h>
#include <freesteam/region4.h>
}
#include <list>
#include "UnitAbout.h"
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvCGrid"
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TForm1 *Form1;

static enum {
  COL_TEMPERATURE_C,
  COL_TEMPERATURE_K,
  COL_CAPACITY_CP_J,
  COL_CAPACITY_CP_KJ,
  COL_CAPACITY_CV_J,
  COL_CAPACITY_CV_KJ,
  COL_CONDUCTIVITY,
  COL_DENSITY,
  COL_SPECIFIC_VOLUME,

  COL_COUNT
} PropertyColumns;
static const char *PropertyNamesRu [] = {
  "Температура, °C",
  "Температура, K",
  "Изобарная тепплоёмкость, j/kgK",
  "Изобарная тепплоёмкость, kj/kgK",
  "Изохорная тепплоёмкость, j/kgK",
  "Изохорная тепплоёмкость, kj/kgK",
  "Теплопроводность, W/mk",
  "Плотность, kg/m3",
  "Удельный объём, m3/kg"
};
static const char *PropertyNamesEn [] = {
  "Temperature, °C",
  "Temperature, K",
  "Isobaric heat capacity, j/kgK",
  "Isobaric heat capacity, kj/kgK",
  "Isochoric heat capacity, j/kgK",
  "Isochoric heat capacity, kj/kgK",
  "Thermal conductivity, W/mk",
  "Density, kg/m3",
  "Specific volume, m3/kg"
};
static const char **PropertyNames = PropertyNamesRu;
static const int PropertyColWidths [] = {90, 90, 120, 120, 120, 120, 130, 80, 80};
static const int PropertyCount = COL_COUNT;

static std::list<double> TemperatureSteps;
static double Pressure = 0;
static bool RussianLocale = true;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
  LCID lcid = GetUserDefaultLCID ();
  if ((lcid & 0xff) != 0x19) {
    RussianLocale = false;
  }
  //RussianLocale = false;

  SetTranslation ();

#if 0
  double T = 400.; /* in Kelvin! */
  double p = 1e5; /* = 1 bar */

  /* set a steam state of 1 bar, 400 K */
  SteamState S = freesteam_set_pT (1e5, 400);

  double s = freesteam_s (S);

  /* calculate a steam state with entropy from above and 10 bar pressure */
  SteamState S2 = freesteam_set_ps (10e5, s);

  double T2 = freesteam_T (S2);
  double p2 = freesteam_p (S2);

  /* saturation temperature at final pressure */
  double Tsat = freesteam_region4_Tsat_p (p2);

  /* set a steam state of 23 MPa, 273.15 K */
  SteamState S3 = freesteam_set_pT (23e6, 273.15);

  const double lambda = freesteam_k (S3);
  const double cp = freesteam_cp (S3);
  const double rho = freesteam_rho (S3);

  for (int i = 0; i < AdvStringGrid1->ColCount; i++) {
    for (int j = 0; j < AdvStringGrid1->RowCount; j++) {
      AdvStringGrid1->Cells [i] [j] = IntToStr (100 * i + j);
    }
  }
#endif

  Constraints->MinHeight = Height;
  Constraints->MinWidth = Width;

  AdvStringGrid1->RowCount = 1;
  AdvStringGrid1->ColCount = 1;
  AdvStringGrid1->FixedRows = 0;
  AdvStringGrid1->FixedCols = 0;
  AdvStringGrid1->RowHeights [0] = AdvStringGrid1->DefaultRowHeight + 30;

  CheckListBoxColumns->Clear ();
  for (int i = 0; i < PropertyCount; i++) {
    CheckListBoxColumns->Items->Add (PropertyNames [i]);
    CheckListBoxColumns->Checked [i] = true;
  }

  MemoTemperatureSteps->Lines->SetText ("0\n20\n40\n60\n80\n100\n120\n140\n160\n180\n200\n220\n240\n260\n280\n300\n320\n340\n360\n370\n375\n380\n385\n390\n400\n420\n440");
  EditIntervalStart->Text = "0";
  EditIntervalEnd->Text = "600";
  EditIntervalStepCount->Text = "30";
  EditPressureMPa->Text = "25";

  MemoTemperatureStepsChange (MemoTemperatureSteps);
  EditPressureMPaChange (EditPressureMPa);

  BitBtnSave->Enabled = false;
  BitBtnCopy->Enabled = false;

  char s [16];
  sprintf (s, "%.3lf °C", (double) IAPWS97_TCRIT - IAPWS97_TMIN);
  LabelCriticalTemperature->Caption = LabelCriticalTemperature->Caption + s;
  sprintf (s, "%.3le %s", (double) IAPWS97_PCRIT, (RussianLocale) ? "Па" : "Pa");
  LabelCriticalPressure->Caption = LabelCriticalPressure->Caption + s;
  sprintf (s, "%.1lf °C", (double) 0);
  LabelMinTemperature->Caption = LabelMinTemperature->Caption + s;
  sprintf (s, "%.1lf °C", (double) IAPWS97_TMAX - IAPWS97_TMIN);
  LabelMaxTemperature->Caption = LabelMaxTemperature->Caption + s;
  sprintf (s, "%.3le %s", (double) IAPWS97_PMAX, (RussianLocale) ? "Па" : "Pa");
  LabelMaxPressure->Caption = LabelMaxPressure->Caption + s;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtnGenerateClick(TObject *Sender)
{
  if (RadioButtonInterval->Checked) {
    try {
      const double start = StrToFloat (EditIntervalStart->Text);
      const double end = StrToFloat (EditIntervalEnd->Text);
      const int step_count = StrToFloat (EditIntervalStepCount->Text);
      const double step = (end - start) / step_count;

      MemoTemperatureSteps->Clear ();
      double temperature = start;
      char s [16];
      for (int i = 0; i < step_count + 1; i++) {
        sprintf (s, "%.2lf", temperature);
        MemoTemperatureSteps->Lines->Add (s);
        temperature += step;
      }
    }
    catch (...) {
      if (RussianLocale) {
        Application->MessageBox ("Параметры генерации шагов по температуре заданы неверно.", "IAPWS", MB_OK | MB_ICONSTOP);
      }
      else {
        Application->MessageBox ("Temperature steps generation parameters are incorrect.", "IAPWS", MB_OK | MB_ICONSTOP);
      }
    }
  }
  else if (RadioButtonTmkp->Checked) {
    MemoTemperatureSteps->Lines->SetText ("0\n20\n40\n60\n80\n100\n120\n140\n160\n180\n200\n220\n240\n260\n280\n300\n320\n340\n360\n370\n375\n380\n385\n390\n400\n420\n440\n460\n480\n500\n520\n540\n560\n580\n600\n620\n640\n660\n680\n700\n720\n740\n760\n780\n800");
  }
  else if (RadioButtonTable->Checked) {
    MemoTemperatureSteps->Lines->SetText ("20\n30\n40\n50\n60\n70\n80\n90\n100\n110\n120\n130\n140\n150\n160\n170\n180\n190\n200\n210\n220\n230\n240\n250\n260\n270\n280\n290\n300\n310\n320\n330\n340\n350\n360\n365\n366\n367\n368\n369\n370\n371\n372\n373\n374\n375\n376\n377\n378\n379\n380\n381\n382\n383\n384\n385\n390\n400\n410\n420\n430\n440\n450\n460\n470\n480\n490\n500\n510\n520\n530\n540\n550\n560\n570\n580\n590\n600\n610\n620\n630\n640\n650\n700");
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MemoTemperatureStepsChange(TObject *Sender)
{
  double temperature = 0;
  TemperatureSteps.clear ();

  for (int i = 0; i < MemoTemperatureSteps->Lines->Count; i++) {
    if (sscanf (MemoTemperatureSteps->Lines->Strings [i].c_str (), "%lf", &temperature) == 1) {
      TemperatureSteps.push_back (temperature + IAPWS97_TMIN);
    }
  }
  LabelStepCount->Caption = String ((RussianLocale) ? "Шагов: " : "Steps: ") + IntToStr (TemperatureSteps.size ());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtnCalculateClick(TObject *Sender)
{
  int CheckedProperties = 0;
  for (int i = 0; i < CheckListBoxColumns->Items->Count; i++) {
    if (CheckListBoxColumns->Checked [i]) {
      CheckedProperties++;
    }
  }

  AdvStringGrid1->RowCount = TemperatureSteps.size () + 1;
  AdvStringGrid1->ColCount = CheckedProperties;
  AdvStringGrid1->FixedRows = 1;
  AdvStringGrid1->FixedCols = 1;
  AdvStringGrid1->Clear ();

  const TFontStyles FontStyles = TFontStyles () << fsBold;
  int row = 0;
  int col = 0;
  for (int i = 0; i < PropertyCount; i++) {
    if (CheckListBoxColumns->Checked [i]) {
      AdvStringGrid1->FontStyles [col] [row] = FontStyles;
      AdvStringGrid1->Cells [col] [row] = PropertyNames [i];
      AdvStringGrid1->Alignments [col] [row] = taCenter;
      AdvStringGrid1->ColWidths [col] = PropertyColWidths [i];
      col++;
    }
  }

  /*
    inline double temp() const{return freesteam_T(S);}
    inline double pres() const{return freesteam_p(S);}
    inline double dens() const{return 1./freesteam_v(S);}
    inline double specvol() const{return freesteam_v(S);}
    inline double specienergy() const{return freesteam_u(S);}
    inline double specentropy() const{return freesteam_s(S);}
    inline double specenthalpy() const{return freesteam_h(S);}
    inline double speccp() const{return freesteam_cp(S);}
    inline double speccv() const{return freesteam_cv(S);}
    inline double quality() const{return freesteam_x(S);}
    inline double dynvisc() const{return freesteam_mu(S);}
    inline double conductivity() const{return freesteam_k(S);}
  */

  row = 1;
  for (std::list<double>::iterator it = TemperatureSteps.begin (); it != TemperatureSteps.end (); it++, row++) {
    col = 0;
    const double Temperature = *it;
    if ((Temperature - IAPWS97_TMIN) < -1e-5) {
      char s [256];
      if (RussianLocale) {
        sprintf (s, "Значение температуры %.3lf °C (%.3lf K) меньше минимально допустимого.", Temperature - IAPWS97_TMIN, Temperature);
      }
      else {
        sprintf (s, "Temperature value %.3lf °C (%.3lf K) is less than minimum allowed.", Temperature - IAPWS97_TMIN, Temperature);
      }
      Application->MessageBox (s, "IAPWS", MB_OK | MB_ICONSTOP);
      break;
    }
    SteamState S = freesteam_set_pT (Pressure, Temperature);
    for (int j = 0; j < PropertyCount; j++) {
      if (CheckListBoxColumns->Checked [j]) {
        char s [16];
        switch (j) {
          case COL_TEMPERATURE_K :
            sprintf (s, "%.2lf", *it);
            break;
          case COL_TEMPERATURE_C :
            sprintf (s, "%.2lf", *it - IAPWS97_TMIN);
            break;
          case COL_CAPACITY_CP_J :
            sprintf (s, "%.3lf", freesteam_cp (S));
            break;
          case COL_CAPACITY_CP_KJ :
            sprintf (s, "%.3lf", freesteam_cp (S) / 1e3);
            break;
          case COL_CAPACITY_CV_J :
            sprintf (s, "%.3lf", freesteam_cv (S));
            break;
          case COL_CAPACITY_CV_KJ :
            sprintf (s, "%.3lf", freesteam_cv (S) / 1e3);
            break;
          case COL_CONDUCTIVITY :
            sprintf (s, "%.3lf", freesteam_k (S));
            break;
          case COL_DENSITY :
            sprintf (s, "%.3lf", freesteam_rho (S));
            break;
          case COL_SPECIFIC_VOLUME :
            sprintf (s, "%.7lf", freesteam_v (S));
            break;
          default :
            break;
        }
        AdvStringGrid1->Cells [col] [row] = s;
        col++;
      }
    }
  }

  BitBtnSave->Enabled = true;
  BitBtnCopy->Enabled = true;

  //AdvStringGrid1->AutoSizeColumns (true, 0);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::EditPressureMPaChange(TObject *Sender)
{
  // http://bcbjournal.org/articles/vol4/0007/Understanding_function_pointers.htm

  if (sscanf (((TEdit*) Sender)->Text.c_str (), "%lf", &Pressure) == 1) {
    char s [16];
    TEdit *PressureFields [] = {EditPressureMPa, EditPressurePa, EditPressureBar};
    const int PressureFieldsCount = sizeof (PressureFields) / sizeof (PressureFields [0]);
    TNotifyEvent ChangeTextHandler = EditPressureMPa->OnChange;

    for (int i = 0; i < PressureFieldsCount; i++) {
      PressureFields [i]->OnChange = NULL;
    }

    if (Sender == EditPressureMPa) {
      Pressure *= 1e6;
      sprintf (s, "%.0lf", Pressure);
      EditPressurePa->Text = s;
      sprintf (s, "%.3lf", Pressure / 1e5);
      EditPressureBar->Text = s;
    }
    else if (Sender == EditPressurePa) {
      sprintf (s, "%.3lf", Pressure / 1e6);
      EditPressureMPa->Text = s;
      sprintf (s, "%.3lf", Pressure / 1e5);
      EditPressureBar->Text = s;
    }
    else if (Sender == EditPressureBar) {
      Pressure /= 1e5;
      sprintf (s, "%.3lf", Pressure / 1e6);
      EditPressureMPa->Text = s;
      sprintf (s, "%.0lf", Pressure / 1e5);
      EditPressurePa->Text = s;
    }
    else {
      if (RussianLocale) {
        Application->MessageBox ("Неверный обработчик изменения давления.", "IAPWS", MB_OK | MB_ICONSTOP);
      }
      else {
        Application->MessageBox ("Wrong pressure change handler.", "IAPWS", MB_OK | MB_ICONSTOP);
      }
    }

    for (int i = 0; i < PressureFieldsCount; i++) {
      PressureFields [i]->OnChange = ChangeTextHandler;
    }
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtnAboutClick(TObject *Sender)
{
  try {
    if (FormAbout = new TFormAbout (this)) {
      FormAbout->ShowModal ();
    }
  }
  __finally {
    if(FormAbout) {
      delete FormAbout;
      FormAbout = NULL;
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtnSaveClick(TObject *Sender)
{
  char FileName [256];
  sprintf (FileName, "Properties_H2O_%.1lf_MPa.csv", Pressure / 1e6);

  SaveDialog1->FileName = FileName;
  if (SaveDialog1->Execute ()) {
    FILE *f = fopen (SaveDialog1->FileName.c_str (), "wb");
    if (f) {
      String s = "";
      for (int row = 0; row < AdvStringGrid1->RowCount; row++) {
        for (int col = 0; col < AdvStringGrid1->ColCount; col++) {
          s += AdvStringGrid1->Cells [col] [row] + ";";
        }
        s += "\r\n";
      }
      fwrite (s.c_str (), sizeof (char), s.Length (), f);
      fclose (f);
      f = NULL;
    }
  }
}
//---------------------------------------------------------------------------

bool SetClipboardLocale (const unsigned int Locale)
{
  // http://www.delphimaster.net/view/1-1139500353
  // http://www.sql.ru/forum/244851/kopirovanie-v-bufer-iz-prilozheniya-menyaet-kodirovku

  // Назначить кодовую страницу для буфера обмена
  HGLOBAL Data = GlobalAlloc (GMEM_MOVEABLE + GMEM_DDESHARE, 4);
  LPVOID lptstrCopy = GlobalLock (Data);
  int res = GetLastError ();
  if (!res) {
    *((int*) lptstrCopy) = Locale;
    res = GlobalUnlock (Data);
    res = GetLastError ();
    if (!res) {
      res = OpenClipboard (Application->Handle);
      res = GetLastError ();
      HANDLE h = SetClipboardData (CF_LOCALE, Data);
      res = GetLastError ();
      res = CloseClipboard ();
      if (h) {
        return true;
      }
    }
  }
  return false;
}

void __fastcall TForm1::BitBtnCopyClick(TObject *Sender)
{
  AdvStringGrid1->CopyToClipBoard ();

  SetClipboardLocale ((RussianLocale) ? 1251 : 1250);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MemoTemperatureStepsKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if ((Key == 'A') && Shift.Contains (ssCtrl)) {
    MemoTemperatureSteps->SelectAll();
    Key = 0;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SetTranslation ()
{
  if (!RussianLocale) {
    GroupBox1->Caption = "Temperature steps";
    GroupBox2->Caption = "Generation";
    GroupBox3->Caption = "Pressure";
    GroupBox4->Caption = "Results";
    GroupBox5->Caption = "Reference";
    LabelStepCount->Caption = "Steps:";
    RadioButtonInterval->Caption = "Interval";
    RadioButtonTmkp->Caption = "For Tmkp (45 steps in 20 K)";
    RadioButtonTable->Caption = "For Excel (84 steps in 10 K)";
    Label1->Caption = "From";
    Label2->Caption = "°C to";
    Label3->Caption = "for";
    Label4->Caption = "steps";
    BitBtnGenerate->Caption = "Generate";
    Label5->Caption = "MPa";
    Label6->Caption = "Pa";
    Label7->Caption = "bar";
    BitBtnCalculate->Caption = "Calculate";
    BitBtnSave->Caption = "Save to file";
    BitBtnCopy->Caption = "Copy to clipboard";
    LabelCriticalTemperature->Caption = "Critical temperature of water: ";
    LabelCriticalPressure->Caption = "Critical pressure of water: ";
    LabelMinTemperature->Caption = "Maximum temperature of calculation: ";
    LabelMaxTemperature->Caption = "Minimum temperature of calculation: ";
    LabelMaxPressure->Caption = "Maximum pressure of calculation: ";
    BitBtnAbout->Caption = "About";

    PropertyNames = PropertyNamesEn;
  }
}
//---------------------------------------------------------------------------

