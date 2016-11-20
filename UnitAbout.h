//---------------------------------------------------------------------------

#ifndef UnitAboutH
#define UnitAboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormAbout : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GroupBox3;
  TImage *Image2;
  TLabel *LabelCompanyName;
  TLabel *LabelYears;
  TPanel *Panel1;
  TLabel *LabelModule;
  TLabel *LabelFileVersion;
  TPanel *Panel2;
  TButton *Button1;
        TLabel *LabelDescription;
        TLabel *LabelFreesteamVersion;
        TLabel *LabelFreesteamLink;
        TLabel *LabelFugueIconsVersion;
        TLabel *LabelFugueIconsLink;
        TLabel *LabelLink;
  void __fastcall OnCreate(TObject *Sender);
        void __fastcall LabelFreesteamLinkClick(TObject *Sender);
        void __fastcall LabelFugueIconsLinkClick(TObject *Sender);
        void __fastcall LabelLinkClick(TObject *Sender);

private:	// User declarations
  String FileVersion;
  void __fastcall SetTranslation ();

public:		// User declarations
  __fastcall TFormAbout(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormAbout *FormAbout;
//---------------------------------------------------------------------------
#endif
