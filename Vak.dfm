object VakForm: TVakForm
  Left = 127
  Top = 323
  Width = 968
  Height = 651
  Caption = 'Vakken'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Visible = True
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label12: TLabel
    Left = 40
    Top = 192
    Width = 77
    Height = 14
    Caption = 'Studierichting'
    Font.Charset = ANSI_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 40
    Top = 160
    Width = 46
    Height = 14
    Caption = 'Faculteit'
    Font.Charset = ANSI_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ModusLabel: TLabel
    Left = 32
    Top = 16
    Width = 142
    Height = 29
    Caption = 'ModusLabel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object CodeLabel: TLabel
    Left = 40
    Top = 256
    Width = 55
    Height = 13
    Caption = 'Vak code'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object NaamLabel: TLabel
    Left = 40
    Top = 224
    Width = 33
    Height = 13
    Caption = 'Naam'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object OmschrijvingLabel: TLabel
    Left = 40
    Top = 288
    Width = 73
    Height = 13
    Caption = 'Omschrijving'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object PeriodeLabel: TLabel
    Left = 48
    Top = 392
    Width = 44
    Height = 13
    Caption = 'Periode'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object CreditLabel: TLabel
    Left = 632
    Top = 120
    Width = 68
    Height = 13
    Caption = 'Creditpoints'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object soortPeriodeLabel: TLabel
    Left = 48
    Top = 424
    Width = 77
    Height = 13
    Caption = 'Soort periode'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object AndersLabel: TLabel
    Left = 432
    Top = 376
    Width = 99
    Height = 13
    Caption = 'Andere werkvorm'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object OrientatieLabel: TLabel
    Left = 633
    Top = 164
    Width = 56
    Height = 13
    Caption = 'Orientatie'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StudierichtingComboBox: TDBLookupComboBox
    Left = 176
    Top = 188
    Width = 185
    Height = 21
    DataField = 'RICHTING_ID'
    DataSource = SasFaculteitData.vakDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    KeyField = 'RICHTING_ID'
    ListField = 'STUDIERICHTING'
    ListSource = sasDataModule.StudierichtingDataSource
    ParentFont = False
    TabOrder = 0
    OnClick = StudierichtingComboBoxClick
  end
  object FaculteitComboBox: TDBLookupComboBox
    Left = 176
    Top = 156
    Width = 185
    Height = 21
    DataField = 'FACULTEIT_ID'
    DataSource = SasFaculteitData.vakDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    KeyField = 'FACULTEIT_ID'
    ListField = 'FACULTEIT'
    ListSource = sasDataModule.FaculteitDataSource
    ParentFont = False
    TabOrder = 1
    OnClick = FaculteitComboBoxClick
  end
  object CodeDBEdit: TDBEdit
    Left = 176
    Top = 256
    Width = 121
    Height = 21
    DataField = 'VAK_CODE'
    DataSource = SasFaculteitData.vakDataSource
    TabOrder = 2
  end
  object PeriodeDBEdit: TDBEdit
    Left = 176
    Top = 392
    Width = 121
    Height = 21
    DataField = 'PERIODE'
    DataSource = SasFaculteitData.vakDataSource
    TabOrder = 3
  end
  object OmschrijvingDBRichEdit: TDBRichEdit
    Left = 176
    Top = 288
    Width = 209
    Height = 89
    DataField = 'VAK_OMSCHRIJVING'
    DataSource = SasFaculteitData.vakDataSource
    TabOrder = 4
  end
  object CreditDBEdit: TDBEdit
    Left = 712
    Top = 120
    Width = 121
    Height = 21
    DataField = 'CREDITPOINTS'
    DataSource = SasFaculteitData.vakDataSource
    TabOrder = 5
  end
  object Button1: TButton
    Left = 552
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Font wijzigen'
    TabOrder = 6
    OnClick = Button1Click
  end
  object WerkVormenGroupBox: TGroupBox
    Left = 432
    Top = 104
    Width = 185
    Height = 257
    Caption = 'Werkvormen'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    object HCCheckBox: TCheckBox
      Left = 16
      Top = 24
      Width = 97
      Height = 17
      Caption = 'Hoorcollege'
      TabOrder = 0
    end
    object WCCheckBox: TCheckBox
      Left = 16
      Top = 48
      Width = 97
      Height = 17
      Caption = 'Werkcollege'
      TabOrder = 1
    end
    object PRCheckBox: TCheckBox
      Left = 16
      Top = 72
      Width = 97
      Height = 17
      Caption = 'Prakticum'
      TabOrder = 2
    end
    object DECheckBox: TCheckBox
      Left = 16
      Top = 96
      Width = 137
      Height = 17
      Caption = 'Distance Education'
      TabOrder = 3
    end
    object PPCheckBox: TCheckBox
      Left = 16
      Top = 120
      Width = 97
      Height = 17
      Caption = 'Paper'
      TabOrder = 4
    end
    object PJCheckBox: TCheckBox
      Left = 16
      Top = 144
      Width = 97
      Height = 17
      Caption = 'Project'
      TabOrder = 5
    end
    object PSCheckBox: TCheckBox
      Left = 16
      Top = 168
      Width = 97
      Height = 17
      Caption = 'Presentatie'
      TabOrder = 6
    end
    object ANCheckBox: TCheckBox
      Left = 16
      Top = 216
      Width = 97
      Height = 17
      Caption = 'Anders'
      TabOrder = 7
    end
    object ONCheckBox: TCheckBox
      Left = 16
      Top = 192
      Width = 97
      Height = 17
      Caption = 'Onderzoek'
      TabOrder = 8
    end
  end
  object NaamDBEdit: TDBEdit
    Left = 176
    Top = 224
    Width = 209
    Height = 21
    DataField = 'VAK_NAAM'
    DataSource = SasFaculteitData.vakDataSource
    TabOrder = 8
  end
  object SoortPeriodeListBox: TDBListBox
    Left = 176
    Top = 431
    Width = 121
    Height = 55
    DataField = 'SOORTPERIODE'
    DataSource = SasFaculteitData.vakDataSource
    ItemHeight = 13
    Items.Strings = (
      'Kwartaal'
      'Semester'
      'Trimester')
    TabOrder = 9
  end
  object VakDBNavigator: TDBNavigator
    Left = 40
    Top = 51
    Width = 218
    Height = 25
    DataSource = SasFaculteitData.vakDataSource
    VisibleButtons = []
    ParentShowHint = False
    ShowHint = True
    TabOrder = 10
    OnClick = VakDBNavigatorClick
  end
  object DBAndersMemo: TDBMemo
    Left = 432
    Top = 400
    Width = 185
    Height = 89
    DataSource = SasFaculteitData.vakDataSource
    TabOrder = 11
  end
  object SearchButton: TButton
    Left = 160
    Top = 126
    Width = 49
    Height = 25
    Caption = 'Zoek '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
    OnClick = SearchButtonClick
  end
  object SearchEdit: TEdit
    Left = 40
    Top = 128
    Width = 121
    Height = 21
    TabOrder = 13
  end
  object ToggleButton: TBitBtn
    Left = 208
    Top = 126
    Width = 105
    Height = 25
    Caption = 'op naam'
    Default = True
    ModalResult = 1
    TabOrder = 14
    OnClick = ToggleButtonClick
    Glyph.Data = {
      7A000000424D7A000000000000003E000000280000000F0000000F0000000100
      0100000000003C0000000000000000000000020000000000000000000000FFFF
      FF000000000080000000E0000000F8000000FE000000FF800000FFE00000FFF8
      0000FFE00000FF800000FE000000F8000000E00000008000000000000000}
    Layout = blGlyphRight
  end
  object OpslaanButton: TButton
    Left = 112
    Top = 80
    Width = 81
    Height = 25
    Caption = 'Opslaan'
    TabOrder = 15
    OnClick = OpslaanButtonClick
  end
  object NieuwButton: TButton
    Left = 40
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Nieuw '
    TabOrder = 16
    OnClick = NieuwButtonClick
  end
  object VerwijderButton: TButton
    Left = 192
    Top = 80
    Width = 83
    Height = 25
    Caption = 'Verwijderen'
    TabOrder = 17
  end
  object OrientatieComboBox: TDBLookupComboBox
    Left = 704
    Top = 164
    Width = 145
    Height = 21
    DataField = 'ORIENTATIE'
    DataSource = SasFaculteitData.vakDataSource
    KeyField = 'OR_ID'
    ListField = 'OMSCHRIJVING'
    ListSource = sasDataModule.OrientatieDataSource
    TabOrder = 18
  end
  object MainMenu1: TMainMenu
    Left = 800
    Top = 80
    object Bestand1: TMenuItem
      Caption = '&Bestand'
      object Close2: TMenuItem
        Caption = '&Close'
        OnClick = Close1Click
      end
      object Exit1: TMenuItem
        Caption = '&Exit'
        OnClick = Exit1Click
      end
    end
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 416
    Top = 32
  end
end
