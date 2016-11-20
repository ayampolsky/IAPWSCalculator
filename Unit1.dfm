object Form1: TForm1
  Left = 192
  Top = 107
  Width = 1000
  Height = 500
  Caption = 'IAPWS Calculator'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 992
    Height = 156
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object GroupBox1: TGroupBox
      Left = 0
      Top = 0
      Width = 370
      Height = 156
      Align = alLeft
      Caption = #1064#1072#1075#1080' '#1087#1086' '#1090#1077#1084#1087#1077#1088#1072#1090#1091#1088#1077
      TabOrder = 0
      DesignSize = (
        370
        156)
      object LabelStepCount: TLabel
        Left = 8
        Top = 135
        Width = 35
        Height = 13
        Caption = #1064#1072#1075#1086#1074':'
      end
      object GroupBox2: TGroupBox
        Left = 99
        Top = 16
        Width = 263
        Height = 132
        Anchors = [akLeft, akTop, akRight, akBottom]
        Caption = #1043#1077#1085#1077#1088#1072#1094#1080#1103
        TabOrder = 1
        object Label1: TLabel
          Left = 26
          Top = 38
          Width = 13
          Height = 13
          Caption = #1054#1090
        end
        object Label2: TLabel
          Left = 92
          Top = 38
          Width = 26
          Height = 13
          Caption = #176'C '#1076#1086
        end
        object Label3: TLabel
          Left = 176
          Top = 38
          Width = 12
          Height = 13
          Caption = #1085#1072
        end
        object Label4: TLabel
          Left = 224
          Top = 38
          Width = 31
          Height = 13
          Caption = #1096#1072#1075#1086#1074
        end
        object RadioButtonTmkp: TRadioButton
          Left = 8
          Top = 58
          Width = 185
          Height = 17
          Caption = #1044#1083#1103' Tmkp (45 '#1096#1072#1075#1086#1074' '#1095#1077#1088#1077#1079' 20 K)'
          TabOrder = 4
          TabStop = True
        end
        object RadioButtonInterval: TRadioButton
          Left = 8
          Top = 16
          Width = 185
          Height = 17
          Caption = #1048#1085#1090#1077#1088#1074#1072#1083
          Checked = True
          TabOrder = 0
          TabStop = True
        end
        object EditIntervalStart: TEdit
          Left = 44
          Top = 34
          Width = 45
          Height = 21
          TabOrder = 1
        end
        object EditIntervalEnd: TEdit
          Left = 127
          Top = 34
          Width = 45
          Height = 21
          TabOrder = 2
        end
        object EditIntervalStepCount: TEdit
          Left = 191
          Top = 34
          Width = 29
          Height = 21
          TabOrder = 3
        end
        object RadioButtonTable: TRadioButton
          Left = 8
          Top = 74
          Width = 185
          Height = 17
          Caption = #1044#1083#1103' Excel (84 '#1096#1072#1075#1072' '#1095#1077#1088#1077#1079' 10 K)'
          TabOrder = 5
          TabStop = True
        end
        object BitBtnGenerate: TBitBtn
          Left = 72
          Top = 99
          Width = 121
          Height = 25
          Caption = #1057#1075#1077#1085#1077#1088#1080#1088#1086#1074#1072#1090#1100
          TabOrder = 6
          OnClick = BitBtnGenerateClick
          Glyph.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            0400000000008000000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00337773333333
            633337FFF733333366337FF9FF7366666E637F999F736EEEEEE67FF99F736666
            6E6337FFF9F73333663333777F9F73336333333337F9F73333333333337F9F73
            333333333337FEF73333333333337FEF73333333333337FEF73333333333337F
            EF73333333333337FEF73333333333337FE73333333333333773}
        end
      end
      object MemoTemperatureSteps: TMemo
        Left = 8
        Top = 17
        Width = 85
        Height = 116
        Anchors = [akLeft, akTop, akBottom]
        ScrollBars = ssVertical
        TabOrder = 0
        OnChange = MemoTemperatureStepsChange
        OnKeyDown = MemoTemperatureStepsKeyDown
      end
    end
    object GroupBox5: TGroupBox
      Left = 731
      Top = 0
      Width = 261
      Height = 156
      Align = alClient
      Caption = #1057#1087#1088#1072#1074#1082#1072
      TabOrder = 1
      object LabelCriticalTemperature: TLabel
        Left = 8
        Top = 16
        Width = 168
        Height = 13
        Caption = #1050#1088#1080#1090#1080#1095#1077#1089#1082#1072#1103' '#1090#1077#1084#1087#1077#1088#1072#1090#1091#1088#1072' '#1074#1086#1076#1099': '
      end
      object LabelCriticalPressure: TLabel
        Left = 8
        Top = 32
        Width = 151
        Height = 13
        Caption = #1050#1088#1080#1090#1080#1095#1077#1089#1082#1086#1077' '#1076#1072#1074#1083#1077#1085#1080#1077' '#1074#1086#1076#1099': '
      end
      object LabelMinTemperature: TLabel
        Left = 8
        Top = 64
        Width = 188
        Height = 13
        Caption = #1052#1080#1085#1080#1084#1072#1083#1100#1085#1072#1103' '#1090#1077#1084#1087#1077#1088#1072#1090#1091#1088#1072' '#1088#1072#1089#1095#1105#1090#1072': '
      end
      object LabelMaxTemperature: TLabel
        Left = 8
        Top = 80
        Width = 194
        Height = 13
        Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1072#1103' '#1090#1077#1084#1087#1077#1088#1072#1090#1091#1088#1072' '#1088#1072#1089#1095#1105#1090#1072': '
      end
      object LabelMaxPressure: TLabel
        Left = 8
        Top = 96
        Width = 177
        Height = 13
        Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1086#1077' '#1076#1072#1074#1083#1077#1085#1080#1077' '#1088#1072#1089#1095#1105#1090#1072': '
      end
      object BitBtnAbout: TBitBtn
        Left = 8
        Top = 123
        Width = 105
        Height = 25
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        TabOrder = 0
        OnClick = BitBtnAboutClick
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000000000000000000000000000000000000008080008080
          0080800080800080800080800080800080800080800080800080800080800080
          8000808000808000808000808000808000808000808000808000808000808000
          8080008080008080008080008080008080008080008080008080008080008080
          008080008080008080B83D20E36136F57040F57040E36136B83D200080800080
          80008080008080008080008080008080008080008080E16236F16F3FF16F3ECF
          5A31CF5A31E86A3BF16F3EE06034008080008080008080008080008080008080
          008080DA6138E6683AE5673ACF795CEAEAEAEEEEEED49E8BE5673AE5673AD85B
          31008080008080008080008080008080BD4725D96338D86035D86035CF9885E3
          E3E3D47D5FE1A691D86035D86035D86035B83D1A008080008080008080008080
          D06542CB5930CB582FCB582FCC6844DBDBDBD1A99CCB582FCB582FCB582FCB58
          2FC5502A008080008080008080008080D97755C85F3BC0522CBE502ABA4E29C8
          A194DBDBDBBE603FBE502ABE502ABE502AC2552F008080008080008080008080
          DD7B59CC6644C96240BD5431BE8A79CECECED4D4D4CBA396B44A26B44A26B44A
          26BD5431008080008080008080008080DD7956CF6947CF6947CF6947C7613FB6
          4F2DAB4522AB4522AD4624AD4624B04A27C15936008080008080008080008080
          D1613CDC7856D6704ED6704ED6704ED68970FFFFFFF6DCD4CC6644D6704EDA75
          53C95732008080008080008080008080008080E98664E07B59DF7957DF7957DA
          8D74FFFFFFF8DED6D26C4AE07B59E37E5A008080008080008080008080008080
          008080008080ED8A67EB8765E7815FE07A58D87250D87250EA8765EA86620080
          80008080008080008080008080008080008080008080008080D96841ED8B67F4
          9673F49572ED8966D8663F008080008080008080008080008080008080008080
          0080800080800080800080800080800080800080800080800080800080800080
          8000808000808000808000808000808000808000808000808000808000808000
          8080008080008080008080008080008080008080008080008080}
      end
    end
    object Panel2: TPanel
      Left = 370
      Top = 0
      Width = 361
      Height = 156
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 2
      object GroupBox3: TGroupBox
        Left = 0
        Top = 0
        Width = 361
        Height = 45
        Align = alTop
        Caption = #1044#1072#1074#1083#1077#1085#1080#1077
        TabOrder = 0
        object Label5: TLabel
          Left = 94
          Top = 24
          Width = 23
          Height = 13
          Caption = #1052#1055#1072
        end
        object Label6: TLabel
          Left = 326
          Top = 24
          Width = 18
          Height = 13
          Caption = #1073#1072#1088
        end
        object Label7: TLabel
          Left = 214
          Top = 24
          Width = 14
          Height = 13
          Caption = #1055#1072
        end
        object EditPressureMPa: TEdit
          Left = 8
          Top = 16
          Width = 81
          Height = 21
          TabOrder = 0
          OnChange = EditPressureMPaChange
        end
        object EditPressureBar: TEdit
          Left = 240
          Top = 16
          Width = 81
          Height = 21
          TabOrder = 2
          OnChange = EditPressureMPaChange
        end
        object EditPressurePa: TEdit
          Left = 128
          Top = 16
          Width = 81
          Height = 21
          TabOrder = 1
          OnChange = EditPressureMPaChange
        end
      end
      object GroupBox4: TGroupBox
        Left = 0
        Top = 45
        Width = 361
        Height = 111
        Align = alClient
        Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099
        TabOrder = 1
        DesignSize = (
          361
          111)
        object BitBtnCalculate: TBitBtn
          Left = 8
          Top = 16
          Width = 121
          Height = 25
          Caption = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100
          TabOrder = 0
          OnClick = BitBtnCalculateClick
          Glyph.Data = {
            36030000424D3603000000000000360000002800000010000000100000000100
            1800000000000003000000000000000000000000000000000000008080008080
            0909090B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0909
            09008080008080008080008080008080171717C9C9C9CDCDCDC5C5C5CDCDCDC5
            C5C5CDCDCDC5C5C5CDCDCDC9C9C9171717008080008080008080008080008080
            262626C7C7C78A8A8ABEBEBE8A8A8ABEBEBE8A8A8ABEBEBE8A8A8AC7C7C72626
            260080800080800080800080800080802F2F2FC9C9C9C9C9C9C0C0C0C9C9C9C0
            C0C0C9C9C9C0C0C08C8C8CC9C9C92F2F2F008080008080008080008080008080
            333333CCCCCC8F8F8FC3C3C38F8F8FC3C3C38F8F8FC3C3C38F8F8FCCCCCC3333
            33008080008080008080008080008080373737CFCFCFCECECEC6C6C6CECECEC6
            C6C6CECECEC6C6C6CECECECFCFCF373737008080008080008080008080008080
            3A3A3AD1D1D1949494C8C8C8949494C8C8C8949494C8C8C8949494D1D1D13A3A
            3A0080800080800080800080800080803E3E3ED4D4D4D4D4D4CBCBCBD4D4D4CB
            CBCBD4D4D4CBCBCBD4D4D4D4D4D43E3E3E008080008080008080008080008080
            424242D8D8D8999999CFCFCF999999CFCFCF999999CFCFCF999999D8D8D84242
            42008080008080008080008080008080454545DBDBDBD2D2D2D2D2D2D2D2D2D2
            D2D2D2D2D2D2D2D2D2D2D2DBDBDB454545008080008080008080008080008080
            0404047272727272727272727272727272727272727272727272727272720404
            04008080008080008080008080008080030303AADDAAA7DAA7A3D6A39FD29F9A
            CD9A96C99691C491699C698ABD8A030303008080008080008080008080008080
            02020291C4918FC28F8DC08D8BBE8B89BC8987BA8784B7845E915E81B4810202
            0200808000808000808000808000808001010157575757575757575757575757
            5757575757575757575757575757010101008080008080008080008080008080
            535353EAEAEAE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5EAEAEA5353
            5300808000808000808000808000808055555555555555555555555555555555
            5555555555555555555555555555555555008080008080008080}
        end
        object BitBtnSave: TBitBtn
          Left = 8
          Top = 47
          Width = 121
          Height = 25
          Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
          Enabled = False
          TabOrder = 1
          OnClick = BitBtnSaveClick
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            0400000000000001000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00337777777777
            773333777777777777F3337FFFFFFFFFF73333788888888F87F3337FFFFFFF0F
            F733337888888878F7F3337FFFFFFFF0F733337888888887F7F3337FFFFFFF00
            F733337FFFFFFF77F7F3222222222F00F733777777777F7787F32FFFFFFF2FFF
            F7337F8888887F8887F32F22822F2FFFF7337F7787787F8FF7F32F22282F2F00
            F7337F7778787F77F7F32F82828F2F00F7337F8787887F7787F32F28222F2FFF
            F7337F7877787F8887F32F22822F2FFFF7337F7787787F8FF7F32FFFFFFF2F77
            77337FFFFFFF7F7777F3222222222F7FF73377777777787F8733337FFFFFFF7F
            7333337FFFFFFF7F733333777777777733333377777777773333}
          NumGlyphs = 2
        end
        object CheckListBoxColumns: TCheckListBox
          Left = 135
          Top = 16
          Width = 218
          Height = 87
          Anchors = [akLeft, akTop, akRight, akBottom]
          ItemHeight = 13
          TabOrder = 3
        end
        object BitBtnCopy: TBitBtn
          Left = 8
          Top = 78
          Width = 121
          Height = 25
          Caption = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100
          Enabled = False
          TabOrder = 2
          OnClick = BitBtnCopyClick
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            0400000000000001000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333337777777
            7773333337777777777F333337FFFFFFFF73333337F88888887F333337FFFFFF
            FF73333337F88888887F377777FFFFFFFF73377777F88888887F37FFF7FFFFFF
            FF7337F887F88888887F37FFF7FFFFFFFF7337F887F88888887F37FFF7FFFFFF
            FF7337F887F88888887F37FFF7FFFFFFFF7337F887F88888887F37FFF7FFFFFF
            FF7337F887F88888FF7F37FFF7FFFFF7777337F887F88887777337FFF7FFFFF7
            F73337F887F88887873337FFF7FFFFF7733337F887FFFFF7733337FFF7777777
            333337F887777777333337FFFFF7F733333337F888878733333337FFFFF77333
            333337FFFFF77333333337777777333333333777777733333333}
          NumGlyphs = 2
        end
      end
    end
  end
  object AdvStringGrid1: TAdvStringGrid
    Left = 0
    Top = 156
    Width = 992
    Height = 317
    Cursor = crDefault
    Align = alClient
    DefaultRowHeight = 21
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected]
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 1
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    AutoSize = True
    SearchFooter.FindNextCaption = 'Find next'
    SearchFooter.FindPrevCaption = 'Find previous'
    SearchFooter.HighLightCaption = 'Highlight'
    SearchFooter.HintClose = 'Close'
    SearchFooter.HintFindNext = 'Find next occurence'
    SearchFooter.HintFindPrev = 'Find previous occurence'
    SearchFooter.HintHighlight = 'Highlight occurences'
    SearchFooter.MatchCaseCaption = 'Match case'
    SelectionRectangleColor = clGray
    PrintSettings.DateFormat = 'dd/mm/yyyy'
    PrintSettings.Font.Charset = DEFAULT_CHARSET
    PrintSettings.Font.Color = clWindowText
    PrintSettings.Font.Height = -11
    PrintSettings.Font.Name = 'MS Sans Serif'
    PrintSettings.Font.Style = []
    PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
    PrintSettings.FixedFont.Color = clWindowText
    PrintSettings.FixedFont.Height = -11
    PrintSettings.FixedFont.Name = 'MS Sans Serif'
    PrintSettings.FixedFont.Style = []
    PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
    PrintSettings.HeaderFont.Color = clWindowText
    PrintSettings.HeaderFont.Height = -11
    PrintSettings.HeaderFont.Name = 'MS Sans Serif'
    PrintSettings.HeaderFont.Style = []
    PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
    PrintSettings.FooterFont.Color = clWindowText
    PrintSettings.FooterFont.Height = -11
    PrintSettings.FooterFont.Name = 'MS Sans Serif'
    PrintSettings.FooterFont.Style = []
    PrintSettings.PageNumSep = '/'
    Navigation.AllowClipboardShortCuts = True
    Navigation.AllowClipboardAlways = True
    MouseActions.RangeSelectAndEdit = True
    ScrollWidth = 16
    FixedFont.Charset = DEFAULT_CHARSET
    FixedFont.Color = clWindowText
    FixedFont.Height = -11
    FixedFont.Name = 'Tahoma'
    FixedFont.Style = [fsBold]
    FloatFormat = '%.2f'
    Filter = <>
    DefaultEditor = edNone
    Version = '3.3.0.3'
    ColWidths = (
      64
      20
      20
      20
      503)
  end
  object SaveDialog1: TSaveDialog
    Filter = 'CSV '#1089' '#1088#1072#1079#1076#1077#1083#1080#1090#1077#1083#1103#1084#1080' ; (*.csv)|*.csv|'#1042#1089#1077' '#1092#1072#1081#1083#1099'|*.*'
    FilterIndex = 0
    Options = [ofEnableSizing]
    OptionsEx = [ofExNoPlacesBar]
    Title = #1057#1086#1093#1088#1072#1085#1077#1085#1080#1077' '#1090#1072#1073#1083#1080#1094#1099' '#1089#1074#1086#1081#1089#1090#1074
    Left = 328
    Top = 112
  end
end
