object IntekenForm: TIntekenForm
  Left = 218
  Top = 133
  Width = 934
  Height = 538
  Caption = 'IntekenForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object DatumLabel: TLabel
    Left = 40
    Top = 272
    Width = 37
    Height = 13
    Caption = 'Datum'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object TijdLabel: TLabel
    Left = 40
    Top = 304
    Width = 22
    Height = 13
    Caption = 'Tijd'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DeelTentamenLabel: TLabel
    Left = 40
    Top = 336
    Width = 79
    Height = 13
    Caption = 'Deeltentamen'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StudieJaarLabel: TLabel
    Left = 64
    Top = 136
    Width = 58
    Height = 13
    Caption = 'Studiejaar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object GebouwLabel: TLabel
    Left = 40
    Top = 368
    Width = 47
    Height = 13
    Caption = 'Gebouw'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ZaalLabel: TLabel
    Left = 40
    Top = 404
    Width = 26
    Height = 13
    Caption = 'Zaal'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 296
    Top = 272
    Width = 71
    Height = 13
    Caption = 'JJJJ-MM-DD'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 296
    Top = 136
    Width = 53
    Height = 13
    Caption = 'JJJJ-JJJJ'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 296
    Top = 304
    Width = 43
    Height = 13
    Caption = 'UU:MM'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StudentLabel: TLabel
    Left = 536
    Top = 224
    Width = 45
    Height = 13
    Caption = 'Student'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object IntekenDatumLabel: TLabel
    Left = 536
    Top = 264
    Width = 82
    Height = 13
    Caption = 'Inteken datum'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Bevel1: TBevel
    Left = 40
    Top = 88
    Width = 361
    Height = 121
  end
  object VakLabel: TLabel
    Left = 64
    Top = 168
    Width = 23
    Height = 13
    Caption = 'Vak'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 64
    Top = 104
    Width = 79
    Height = 13
    Caption = 'Studierichting'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 40
    Top = 240
    Width = 81
    Height = 20
    Caption = 'Tentamen'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 512
    Top = 80
    Width = 89
    Height = 20
    Caption = 'Intekenlijst'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label31: TLabel
    Left = 696
    Top = 160
    Width = 18
    Height = 13
    Caption = 'van'
  end
  object DatumDBEdit: TDBEdit
    Left = 160
    Top = 272
    Width = 121
    Height = 21
    DataField = 'DATUM'
    DataSource = tentamenDataSource
    ReadOnly = True
    TabOrder = 0
  end
  object TijdDBEdit: TDBEdit
    Left = 160
    Top = 304
    Width = 121
    Height = 21
    DataField = 'TIJD'
    DataSource = tentamenDataSource
    ReadOnly = True
    TabOrder = 1
  end
  object DeelTentamenDBEdit: TDBEdit
    Left = 160
    Top = 336
    Width = 121
    Height = 21
    DataField = 'DEELTENTAMEN'
    DataSource = tentamenDataSource
    ReadOnly = True
    TabOrder = 2
  end
  object GebouwDBEdit: TDBEdit
    Left = 160
    Top = 372
    Width = 121
    Height = 21
    DataField = 'GEBOUW'
    DataSource = tentamenDataSource
    ReadOnly = True
    TabOrder = 3
  end
  object ZaalDBEdit: TDBEdit
    Left = 160
    Top = 404
    Width = 121
    Height = 21
    DataField = 'ZAAL'
    DataSource = tentamenDataSource
    ReadOnly = True
    TabOrder = 4
  end
  object NieuwButton: TButton
    Left = 592
    Top = 184
    Width = 75
    Height = 25
    Caption = 'Nieuw '
    Enabled = False
    TabOrder = 5
  end
  object OpslaanButton: TButton
    Left = 664
    Top = 184
    Width = 81
    Height = 25
    Caption = 'Opslaan'
    Enabled = False
    TabOrder = 6
  end
  object VerwijderButton: TButton
    Left = 744
    Top = 184
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
    TabOrder = 7
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
    TabOrder = 8
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
  object StudentLookupComboBox: TDBLookupComboBox
    Left = 672
    Top = 224
    Width = 145
    Height = 21
    TabOrder = 9
  end
  object IntekenDatumDBEdit: TDBEdit
    Left = 672
    Top = 264
    Width = 121
    Height = 21
    TabOrder = 10
  end
  object SearchButton: TButton
    Left = 360
    Top = 86
    Width = 41
    Height = 123
    Caption = 'Zoek'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = SearchButtonClick
  end
  object VakLookupComboBox: TDBLookupComboBox
    Left = 160
    Top = 168
    Width = 145
    Height = 21
    KeyField = 'VAK_ID'
    ListField = 'VAK_NAAM'
    ListSource = vakDataSource
    ReadOnly = True
    TabOrder = 12
  end
  object StudierichtingLookupComboBox: TDBLookupComboBox
    Left = 160
    Top = 104
    Width = 145
    Height = 21
    KeyField = 'RICHTING_ID'
    ListField = 'STUDIERICHTING'
    ListSource = studierichtingDataSource
    TabOrder = 13
    OnClick = StudierichtingLookupComboBoxClick
  end
  object IntekenLijstDBNavigator: TDBNavigator
    Left = 592
    Top = 136
    Width = 224
    Height = 25
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    TabOrder = 14
  end
  object IntekenLijstDBGrid: TDBGrid
    Left = 128
    Top = 488
    Width = 320
    Height = 120
    DataSource = intekenlijstDataSource
    TabOrder = 15
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'STUDIENR'
        Width = 95
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'INTEKEN_DATUM'
        Width = 132
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'TENTAMEN_ID'
        Visible = True
      end>
  end
  object StudiejaarMaskEdit: TMaskEdit
    Left = 160
    Top = 136
    Width = 116
    Height = 21
    EditMask = '0000\-0000;0;_'
    MaxLength = 9
    TabOrder = 16
  end
  object first: TEdit
    Left = 592
    Top = 160
    Width = 57
    Height = 21
    Enabled = False
    TabOrder = 17
  end
  object last: TEdit
    Left = 760
    Top = 160
    Width = 57
    Height = 21
    Enabled = False
    TabOrder = 18
  end
  object TentamenDBEdit: TDBEdit
    Left = 584
    Top = 32
    Width = 121
    Height = 21
    DataField = 'TENTAMEN_ID'
    DataSource = tentamenDataSource
    TabOrder = 19
    Visible = False
  end
  object faculteitClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'faculteitDataSetProvider'
    Left = 448
    Top = 24
  end
  object faculteitDataSource: TDataSource
    DataSet = faculteitClientDataSet
    Left = 432
    Top = 72
  end
  object tentamenDataSource: TDataSource
    DataSet = tentamenClientDataSet
    Left = 376
    Top = 376
  end
  object tentamenClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'TentamenDataSetProvider'
    Left = 376
    Top = 336
  end
  object tentamenDataSetProvider: TDataSetProvider
    DataSet = tentamenSQLDataSet
    Constraints = True
    Left = 376
    Top = 296
  end
  object tentamenSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from tentamen'
    Params = <>
    Left = 376
    Top = 256
  end
  object studierichtingClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'studierichtingDataSetProvider'
    Left = 464
    Top = 336
  end
  object studierichtingDataSource: TDataSource
    DataSet = studierichtingClientDataSet
    Left = 464
    Top = 376
  end
  object studierichtingDataSetProvider: TDataSetProvider
    DataSet = studierichtingSQLDataSet
    Constraints = True
    Left = 464
    Top = 296
  end
  object vakDataSource: TDataSource
    DataSet = vakClientDataSet
    Left = 424
    Top = 376
  end
  object vakClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'vakDataSetProvider'
    Left = 424
    Top = 336
  end
  object vakDataSetProvider: TDataSetProvider
    DataSet = sasDataModule.vakSQLDataSet
    Constraints = True
    Left = 424
    Top = 296
  end
  object ClientDataSet1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'faculteitDataSetProvider'
    Left = 504
    Top = 336
  end
  object DataSource1: TDataSource
    DataSet = ClientDataSet1
    Left = 504
    Top = 376
  end
  object faculteitDataSetProvider: TDataSetProvider
    DataSet = sasDataModule.FaculteitSQLDataSet
    Constraints = True
    Left = 504
    Top = 296
  end
  object intekenlijstSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from intekenlijst'
    Params = <>
    Left = 816
    Top = 312
  end
  object intekenlijstDataSetProvider: TDataSetProvider
    DataSet = intekenlijstSQLDataSet
    Constraints = True
    Left = 816
    Top = 352
  end
  object intekenlijstClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'intekenlijstDataSetProvider'
    Left = 816
    Top = 392
  end
  object intekenlijstDataSource: TDataSource
    DataSet = intekenlijstClientDataSet
    Left = 816
    Top = 432
  end
  object studierichtingSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 
      'select studierichting.*, faculteit.* from studierichting join fa' +
      'culteit on studierichting.faculteit_id = faculteit.faculteit_id'
    Params = <>
    Left = 464
    Top = 264
  end
end
