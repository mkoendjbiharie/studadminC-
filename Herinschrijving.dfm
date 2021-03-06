object HerinschrijvingForm: THerinschrijvingForm
  Left = 310
  Top = 279
  Width = 817
  Height = 641
  Caption = 'Herinschrijving'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  Visible = True
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 40
    Top = 152
    Width = 30
    Height = 14
    Caption = 'Naam'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 40
    Top = 186
    Width = 57
    Height = 14
    Caption = 'Voornaam'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label22: TLabel
    Left = 40
    Top = 216
    Width = 58
    Height = 14
    Caption = 'Idnummer'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 392
    Top = 120
    Width = 147
    Height = 14
    Caption = 'Laatst ingevoerde records'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label12: TLabel
    Left = 40
    Top = 312
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
    Top = 280
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
  object Label4: TLabel
    Left = 40
    Top = 248
    Width = 80
    Height = 13
    Caption = 'Studienummer'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object JaarListLabel: TLabel
    Left = 40
    Top = 376
    Width = 223
    Height = 13
    Caption = 'Jaren van inschrijving voor deze studie'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StudieMemoLabel: TLabel
    Left = 48
    Top = 472
    Width = 61
    Height = 13
    Caption = 'Opmerking'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object JaarLabel: TLabel
    Left = 40
    Top = 344
    Width = 136
    Height = 13
    Caption = 'Jaar van herinschrijving'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object SearchButton: TButton
    Left = 200
    Top = 94
    Width = 41
    Height = 25
    Caption = 'Zoek '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = SearchButtonClick
  end
  object ModusKnop: TBitBtn
    Left = 40
    Top = 40
    Width = 193
    Height = 41
    Caption = 'Lezen'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = ModusKnopClick
    Glyph.Data = {
      360C0000424D360C000000000000360000002800000020000000200000000100
      180000000000000C000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFF0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFF00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFF000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFF000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFF00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFF0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000}
    Layout = blGlyphRight
  end
  object NameDBEdit: TDBEdit
    Left = 184
    Top = 141
    Width = 121
    Height = 21
    DataField = 'NAAM'
    DataSource = PersoonDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 2
  end
  object FirstNameDBEdit: TDBEdit
    Left = 184
    Top = 175
    Width = 121
    Height = 21
    DataField = 'VOORNAAM'
    DataSource = PersoonDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 3
  end
  object IdCardDBEdit: TDBEdit
    Left = 184
    Top = 205
    Width = 121
    Height = 21
    DataField = 'IDKAARTNR'
    DataSource = PersoonDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 4
    OnExit = IdCardDBEditExit
  end
  object LastRecordsDBGrid: TDBGrid
    Left = 384
    Top = 136
    Width = 169
    Height = 329
    DataSource = GridDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 5
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'VOLGNR'
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'STUDIENR'
        Width = 84
        Visible = True
      end>
  end
  object StudierichtingComboBox: TDBLookupComboBox
    Left = 184
    Top = 300
    Width = 145
    Height = 21
    DataField = 'STUDIERICHTING_ID'
    DataSource = InschrijvingDataSource
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    KeyField = 'RICHTING_ID'
    ListField = 'STUDIERICHTING'
    ListSource = StudierichtingDataSource
    ParentFont = False
    ReadOnly = True
    TabOrder = 6
  end
  object FaculteitComboBox: TDBLookupComboBox
    Left = 184
    Top = 268
    Width = 145
    Height = 21
    DataField = 'FACULTEIT_ID'
    DataSource = InschrijvingDataSource
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    KeyField = 'FACULTEIT_ID'
    ListField = 'FACULTEIT'
    ListSource = sasDataModule.FaculteitDataSource
    ParentFont = False
    ReadOnly = True
    TabOrder = 7
  end
  object NieuwButton: TButton
    Left = 240
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Nieuw '
    Enabled = False
    TabOrder = 8
    OnClick = NieuwButtonClick
  end
  object OpslaanButton: TButton
    Left = 312
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Opslaan'
    Enabled = False
    TabOrder = 9
    OnClick = OpslaanButtonClick
  end
  object VerwijderButton: TButton
    Left = 384
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Verwijder'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = VerwijderButtonClick
  end
  object SearchEdit: TEdit
    Left = 40
    Top = 96
    Width = 121
    Height = 21
    TabOrder = 11
  end
  object StudieNRDBEdit: TDBEdit
    Left = 184
    Top = 240
    Width = 145
    Height = 21
    Color = clWhite
    DataField = 'STUDIENR'
    DataSource = InschrijvingDataSource
    Enabled = False
    ReadOnly = True
    TabOrder = 12
  end
  object InschrijvingDBNavigator: TDBNavigator
    Left = 240
    Top = 24
    Width = 224
    Height = 25
    DataSource = PersoonDataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    TabOrder = 13
    OnClick = InschrijvingDBNavigatorClick
  end
  object HerinschrijvingDBMemo: TDBMemo
    Left = 40
    Top = 488
    Width = 289
    Height = 89
    DataField = 'MEMO'
    DataSource = HerinschrijvingDataSource
    ReadOnly = True
    TabOrder = 14
  end
  object InschrijfJaarDBLookupListBox: TDBLookupListBox
    Left = 272
    Top = 375
    Width = 41
    Height = 95
    KeyField = 'VOLGNR'
    ListField = 'JAAR'
    ListSource = InschrijfJarenDataSource
    ReadOnly = True
    TabOrder = 15
  end
  object ToggleButton: TBitBtn
    Left = 240
    Top = 94
    Width = 129
    Height = 25
    Caption = 'op idnummer'
    Default = True
    ModalResult = 1
    TabOrder = 16
    OnClick = ToggleButtonClick
    Glyph.Data = {
      7A000000424D7A000000000000003E000000280000000F0000000F0000000100
      0100000000003C0000000000000000000000020000000000000000000000FFFF
      FF000000000080000000E0000000F8000000FE000000FF800000FFE00000FFF8
      0000FFE00000FF800000FE000000F8000000E00000008000000000000000}
    Layout = blGlyphRight
  end
  object VolgNRDBEdit: TDBEdit
    Left = 400
    Top = 487
    Width = 121
    Height = 21
    DataField = 'VOLGNR'
    DataSource = HerinschrijvingDataSource
    Enabled = False
    ReadOnly = True
    TabOrder = 17
    Visible = False
  end
  object IdNummerComboBox: TDBLookupComboBox
    Left = 544
    Top = 16
    Width = 145
    Height = 21
    KeyField = 'VOLGNR'
    ListField = 'STUDIENR'
    ListSource = InschrijvingDataSource
    TabOrder = 18
    Visible = False
    OnClick = IdNummerComboBoxClick
  end
  object JaarDBEdit: TDBEdit
    Left = 184
    Top = 336
    Width = 121
    Height = 21
    DataField = 'JAAR'
    DataSource = HerinschrijvingDataSource
    ReadOnly = True
    TabOrder = 19
  end
  object MainMenu1: TMainMenu
    Left = 616
    Top = 392
    object Bestand1: TMenuItem
      Caption = 'Bestand'
      object Close1: TMenuItem
        Caption = '&Close'
        OnClick = Close1Click
      end
      object Exit1: TMenuItem
        Caption = '&Exit'
        OnClick = Exit1Click
      end
    end
  end
  object HerinschrijvingSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from herinschrijving'
    Params = <>
    Left = 688
    Top = 70
  end
  object HerinschrijvingDataSetProvider: TDataSetProvider
    DataSet = HerinschrijvingSQLDataSet
    Constraints = True
    Left = 688
    Top = 118
  end
  object HerinschrijvingClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'HerinschrijvingDataSetProvider'
    Left = 696
    Top = 150
  end
  object HerinschrijvingDataSource: TDataSource
    DataSet = HerinschrijvingClientDataSet
    Left = 696
    Top = 182
  end
  object PersoonSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from persoon'
    Params = <>
    Left = 568
    Top = 208
  end
  object InschrijvingSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from inschrijving order by STUDIENR ASC'
    Params = <>
    Left = 632
    Top = 207
  end
  object InschrijfJarenSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from herinschrijving '
    Params = <>
    Left = 744
    Top = 224
  end
  object PersoonDataSetProvider: TDataSetProvider
    DataSet = PersoonSQLDataSet
    Constraints = True
    Left = 576
    Top = 256
  end
  object InschrijvingDataSetProvider: TDataSetProvider
    DataSet = InschrijvingSQLDataSet
    Constraints = True
    Left = 640
    Top = 256
  end
  object InschrijfJarenDataSetProvider: TDataSetProvider
    DataSet = InschrijfJarenSQLDataSet
    Constraints = True
    Left = 752
    Top = 264
  end
  object PersoonClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'PersoonDataSetProvider'
    Left = 584
    Top = 304
  end
  object InschrijvingClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'InschrijvingDataSetProvider'
    Left = 648
    Top = 304
  end
  object InschrijfJarenClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'InschrijfJarenDataSetProvider'
    Left = 760
    Top = 304
  end
  object PersoonDataSource: TDataSource
    DataSet = PersoonClientDataSet
    Left = 584
    Top = 352
  end
  object InschrijvingDataSource: TDataSource
    DataSet = InschrijvingClientDataSet
    Left = 656
    Top = 352
  end
  object InschrijfJarenDataSource: TDataSource
    DataSet = InschrijfJarenClientDataSet
    Left = 760
    Top = 352
  end
  object GridSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from herinschrijving'
    Params = <>
    Left = 680
    Top = 280
  end
  object GridDataSetProvider: TDataSetProvider
    DataSet = GridSQLDataSet
    Constraints = True
    Left = 688
    Top = 328
  end
  object GridClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'GridDataSetProvider'
    Left = 696
    Top = 392
  end
  object GridDataSource: TDataSource
    DataSet = GridClientDataSet
    Left = 720
    Top = 408
  end
  object StudierichtingSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select  * from studierichting'
    Params = <>
    Left = 600
    Top = 448
  end
  object StudierichtingDataSource: TDataSource
    DataSet = StudierichtingClientDataSet
    Left = 600
    Top = 560
  end
  object StudierichtingDataSetProvider: TDataSetProvider
    DataSet = StudierichtingSQLDataSet
    Constraints = True
    Left = 600
    Top = 488
  end
  object StudierichtingClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'StudierichtingDataSetProvider'
    Left = 600
    Top = 520
  end
end
