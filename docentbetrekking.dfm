object DocentBetrekkingForm: TDocentBetrekkingForm
  Left = 219
  Top = 98
  Width = 870
  Height = 600
  Caption = 'DocentBetrekkingForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 40
    Top = 272
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
    Top = 306
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
    Top = 240
    Width = 58
    Height = 14
    Caption = 'Idnummer'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 40
    Top = 144
    Width = 59
    Height = 16
    Caption = 'Persoon'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Label9: TLabel
    Left = 400
    Top = 136
    Width = 75
    Height = 16
    Caption = 'Betrekking'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label12: TLabel
    Left = 400
    Top = 232
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
    Left = 400
    Top = 200
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
  object GebouwLabel: TLabel
    Left = 400
    Top = 264
    Width = 40
    Height = 13
    Caption = 'Gebouw'
  end
  object KamernrLabel: TLabel
    Left = 400
    Top = 296
    Width = 30
    Height = 13
    Caption = 'Kamer'
  end
  object TelefoonnrLabel: TLabel
    Left = 400
    Top = 328
    Width = 42
    Height = 13
    Caption = 'Telefoon'
  end
  object Label7: TLabel
    Left = 400
    Top = 360
    Width = 73
    Height = 13
    Caption = 'Datum in dienst'
  end
  object UitDienstLabel: TLabel
    Left = 400
    Top = 392
    Width = 76
    Height = 13
    Caption = 'Datum uit dienst'
  end
  object CommentLabel: TLabel
    Left = 400
    Top = 456
    Width = 59
    Height = 13
    Caption = 'Commentaar'
  end
  object Label31: TLabel
    Left = 232
    Top = 168
    Width = 18
    Height = 13
    Caption = 'van'
  end
  object FunctieLabel: TLabel
    Left = 400
    Top = 424
    Width = 35
    Height = 13
    Caption = 'Functie'
  end
  object NameDBEdit: TDBEdit
    Left = 176
    Top = 269
    Width = 121
    Height = 21
    DataField = 'NAAM'
    DataSource = personDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 0
  end
  object FirstNameDBEdit: TDBEdit
    Left = 176
    Top = 303
    Width = 121
    Height = 21
    DataField = 'VOORNAAM'
    DataSource = personDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
  end
  object IdCardDBEdit: TDBEdit
    Left = 176
    Top = 237
    Width = 121
    Height = 21
    DataField = 'IDKAARTNR'
    DataSource = personDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 2
  end
  object PersoonDBNavigator: TDBNavigator
    Left = 128
    Top = 144
    Width = 224
    Height = 25
    DataSource = personDataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    TabOrder = 3
    OnClick = PersoonDBNavigatorClick
  end
  object SearchButton: TButton
    Left = 168
    Top = 102
    Width = 41
    Height = 25
    Caption = 'Zoek'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = SearchButtonClick
  end
  object SearchEdit: TEdit
    Left = 40
    Top = 104
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object ToggleButton: TBitBtn
    Left = 208
    Top = 102
    Width = 105
    Height = 25
    Caption = 'op idnummer'
    Default = True
    ModalResult = 1
    TabOrder = 6
    OnClick = ToggleButtonClick
    Glyph.Data = {
      7A000000424D7A000000000000003E000000280000000F0000000F0000000100
      0100000000003C0000000000000000000000020000000000000000000000FFFF
      FF000000000080000000E0000000F8000000FE000000FF800000FFE00000FFF8
      0000FFE00000FF800000FE000000F8000000E00000008000000000000000}
    Layout = blGlyphRight
  end
  object NieuwButton: TButton
    Left = 488
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Nieuw '
    Enabled = False
    TabOrder = 7
    OnClick = NieuwButtonClick
  end
  object OpslaanButton: TButton
    Left = 560
    Top = 152
    Width = 81
    Height = 25
    Caption = 'Opslaan'
    Enabled = False
    TabOrder = 8
    OnClick = OpslaanButtonClick
  end
  object VerwijderButton: TButton
    Left = 640
    Top = 152
    Width = 73
    Height = 25
    Caption = 'Verwijder'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = VerwijderButtonClick
  end
  object DocentBetrekkingNavigator: TDBNavigator
    Left = 488
    Top = 128
    Width = 224
    Height = 25
    DataSource = docentbetrekkingDataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    TabOrder = 10
  end
  object StudierichtingComboBox: TDBLookupComboBox
    Left = 512
    Top = 228
    Width = 145
    Height = 21
    DataField = 'studierichting'
    DataSource = docentbetrekkingDataSource
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    KeyField = 'RICHTING_ID'
    ListField = 'STUDIERICHTING'
    ListSource = studierichtingDataSource
    ParentFont = False
    TabOrder = 11
  end
  object FaculteitComboBox: TDBLookupComboBox
    Left = 512
    Top = 196
    Width = 145
    Height = 21
    DataField = 'faculteit'
    DataSource = docentbetrekkingDataSource
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    KeyField = 'FACULTEIT_ID'
    ListField = 'FACULTEIT'
    ListSource = faculteitDataSource
    ParentFont = False
    TabOrder = 12
    OnClick = FaculteitComboBoxClick
  end
  object GebouwDBEdit: TDBEdit
    Left = 512
    Top = 264
    Width = 121
    Height = 21
    DataField = 'gebouw'
    DataSource = docentbetrekkingDataSource
    ReadOnly = True
    TabOrder = 13
  end
  object KamerDBEdit: TDBEdit
    Left = 512
    Top = 296
    Width = 121
    Height = 21
    DataField = 'kamer'
    DataSource = docentbetrekkingDataSource
    ReadOnly = True
    TabOrder = 14
  end
  object TelefoonDBEdit: TDBEdit
    Left = 512
    Top = 328
    Width = 121
    Height = 21
    DataField = 'telefoon'
    DataSource = docentbetrekkingDataSource
    ReadOnly = True
    TabOrder = 15
  end
  object InDienstDBEdit: TDBEdit
    Left = 512
    Top = 360
    Width = 121
    Height = 21
    DataField = 'indienstdatum'
    DataSource = docentbetrekkingDataSource
    ReadOnly = True
    TabOrder = 16
  end
  object UitDienstDBEdit: TDBEdit
    Left = 512
    Top = 392
    Width = 121
    Height = 21
    DataField = 'uitdienstdatum'
    DataSource = docentbetrekkingDataSource
    ReadOnly = True
    TabOrder = 17
  end
  object CommentDBMemo: TDBMemo
    Left = 512
    Top = 456
    Width = 185
    Height = 89
    DataField = 'commentaar'
    DataSource = docentbetrekkingDataSource
    ReadOnly = True
    TabOrder = 18
  end
  object ModusKnop: TBitBtn
    Left = 40
    Top = 24
    Width = 193
    Height = 41
    Caption = 'Lezen'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 19
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
  object first: TEdit
    Left = 128
    Top = 168
    Width = 57
    Height = 21
    Enabled = False
    TabOrder = 20
  end
  object last: TEdit
    Left = 296
    Top = 168
    Width = 57
    Height = 21
    Enabled = False
    TabOrder = 21
  end
  object FunctieDBEdit: TDBEdit
    Left = 512
    Top = 424
    Width = 121
    Height = 21
    DataField = 'functie'
    DataSource = docentbetrekkingDataSource
    ReadOnly = True
    TabOrder = 22
  end
  object personClientDataSet: TClientDataSet
    Aggregates = <>
    FilterOptions = [foCaseInsensitive]
    Params = <>
    ProviderName = 'pesonDataSetProvider'
    Left = 48
    Top = 376
  end
  object studierichtingClientDataSet: TClientDataSet
    Aggregates = <>
    FilterOptions = [foCaseInsensitive]
    Params = <>
    ProviderName = 'studierichingDataSetProvider'
    Left = 184
    Top = 424
  end
  object faculteitClientDataSet: TClientDataSet
    Aggregates = <>
    FilterOptions = [foCaseInsensitive]
    Params = <>
    ProviderName = 'faculteitDataSetProvider'
    Left = 120
    Top = 376
  end
  object faculteitDataSource: TDataSource
    DataSet = faculteitClientDataSet
    Left = 120
    Top = 416
  end
  object personDataSource: TDataSource
    DataSet = personClientDataSet
    Left = 48
    Top = 416
  end
  object studierichtingDataSource: TDataSource
    DataSet = studierichtingClientDataSet
    Left = 184
    Top = 464
  end
  object docentbetrekkingClientDataSet: TClientDataSet
    Aggregates = <>
    FilterOptions = [foCaseInsensitive]
    Params = <>
    ProviderName = 'docentbetrekkingDataSetProvider'
    Left = 232
    Top = 424
  end
  object docentbetrekkingDataSource: TDataSource
    DataSet = docentbetrekkingClientDataSet
    Left = 232
    Top = 464
  end
  object docentbetrekkingDataSetProvider: TDataSetProvider
    DataSet = docentbetrekkingSQLDataSet
    Constraints = True
    Left = 232
    Top = 384
  end
  object studierichingDataSetProvider: TDataSetProvider
    DataSet = studierichtingSQLDataSet
    Constraints = True
    Left = 184
    Top = 384
  end
  object faculteitDataSetProvider: TDataSetProvider
    DataSet = sasDataModule.FaculteitSQLDataSet
    Constraints = True
    Left = 120
    Top = 336
  end
  object pesonDataSetProvider: TDataSetProvider
    DataSet = sasDataModule.personSQLDataSet
    Constraints = True
    Left = 48
    Top = 336
  end
  object studierichtingSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from studierichting'
    Params = <>
    Left = 184
    Top = 344
  end
  object docentbetrekkingSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from docentbetrekking'
    Params = <>
    Left = 232
    Top = 344
  end
end
