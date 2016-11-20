//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvCGrid.hpp"
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <CheckLst.hpp>
#include "slstbox.hpp"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TAdvStringGrid *AdvStringGrid1;
        TPanel *Panel1;
        TGroupBox *GroupBox1;
        TMemo *MemoTemperatureSteps;
        TRadioButton *RadioButtonInterval;
        TRadioButton *RadioButtonTmkp;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TEdit *EditIntervalStart;
        TLabel *Label2;
        TEdit *EditIntervalEnd;
        TEdit *EditIntervalStepCount;
        TLabel *Label3;
        TLabel *Label4;
        TRadioButton *RadioButtonTable;
        TBitBtn *BitBtnGenerate;
        TLabel *LabelStepCount;
        TGroupBox *GroupBox5;
        TLabel *LabelCriticalTemperature;
        TLabel *LabelCriticalPressure;
        TLabel *LabelMinTemperature;
        TLabel *LabelMaxTemperature;
        TLabel *LabelMaxPressure;
        TBitBtn *BitBtnAbout;
        TSaveDialog *SaveDialog1;
        TPanel *Panel2;
        TGroupBox *GroupBox3;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *EditPressureMPa;
        TEdit *EditPressureBar;
        TEdit *EditPressurePa;
        TGroupBox *GroupBox4;
        TBitBtn *BitBtnCalculate;
        TBitBtn *BitBtnSave;
        TCheckListBox *CheckListBoxColumns;
        TBitBtn *BitBtnCopy;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtnGenerateClick(TObject *Sender);
        void __fastcall MemoTemperatureStepsChange(TObject *Sender);
        void __fastcall BitBtnCalculateClick(TObject *Sender);
        void __fastcall EditPressureMPaChange(TObject *Sender);
        void __fastcall BitBtnAboutClick(TObject *Sender);
        void __fastcall BitBtnSaveClick(TObject *Sender);
        void __fastcall BitBtnCopyClick(TObject *Sender);
        void __fastcall MemoTemperatureStepsKeyDown(TObject *Sender,
          WORD &Key, TShiftState Shift);
private:	// User declarations
        void __fastcall SetTranslation ();
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 