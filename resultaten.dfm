object ResultatenForm: TResultatenForm
  Left = 192
  Top = 103
  Width = 870
  Height = 500
  Caption = 'ResultatenForm'
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
    Top = 312
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
    Top = 344
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
    Top = 376
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
  object Label4: TLabel
    Left = 296
    Top = 312
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
    Top = 344
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
  object Bevel1: TBevel
    Left = 40
    Top = 88
    Width = 360
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
  object DatumDBEdit: TDBEdit
    Left = 160
    Top = 312
    Width = 120
    Height = 21
    DataField = 'DATUM'
    DataSource = tentamenDataSource
    ReadOnly = True
    TabOrder = 0
  end
  object TijdDBEdit: TDBEdit
    Left = 160
    Top = 344
    Width = 120
    Height = 21
    DataField = 'TIJD'
    DataSource = tentamenDataSource
    ReadOnly = True
    TabOrder = 1
  end
  object DeelTentamenDBEdit: TDBEdit
    Left = 160
    Top = 376
    Width = 120
    Height = 21
    DataField = 'DEELTENTAMEN'
    DataSource = tentamenDataSource
    ReadOnly = True
    TabOrder = 2
  end
  object ModusKnop: TBitBtn
    Left = 40
    Top = 24
    Width = 192
    Height = 41
    Caption = 'Lezen'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
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
  object SearchButton: TButton
    Left = 400
    Top = 86
    Width = 40
    Height = 123
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
  object VakLookupComboBox: TDBLookupComboBox
    Left = 160
    Top = 168
    Width = 144
    Height = 21
    KeyField = 'VAK_ID'
    ListField = 'VAK_NAAM'
    ListSource = vakDataSource
    TabOrder = 5
  end
  object StudierichtingLookupComboBox: TDBLookupComboBox
    Left = 160
    Top = 104
    Width = 225
    Height = 21
    KeyField = 'RICHTING_ID'
    ListField = 'STUDIERICHTING;FACULTEIT'
    ListSource = studierichtingDataSource
    TabOrder = 6
    OnClick = StudierichtingLookupComboBoxClick
  end
  object StudiejaarMaskEdit: TMaskEdit
    Left = 160
    Top = 136
    Width = 116
    Height = 21
    EditMask = '0000\-0000;0;_'
    MaxLength = 9
    TabOrder = 7
  end
  object TentamenDBEdit: TDBEdit
    Left = 584
    Top = 32
    Width = 121
    Height = 21
    DataField = 'TENTAMEN_ID'
    DataSource = tentamenDataSource
    TabOrder = 8
    Visible = False
  end
  object ResultatenDBGrid: TDBGrid
    Left = 136
    Top = 416
    Width = 577
    Height = 120
    DataSource = resultatenDataSource
    ReadOnly = True
    TabOrder = 9
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'STUDIENR'
        Width = 82
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'naam'
        Title.Caption = 'NAAM'
        Width = 93
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'voornaam'
        Title.Caption = 'VOORNAAM'
        Width = 105
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'CIJFER'
        ReadOnly = False
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'INGELEVERD'
        ReadOnly = False
        Width = 78
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'AANWEZIG'
        ReadOnly = False
        Visible = True
      end
      item
        Expanded = False
        Visible = True
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 40
    Top = 272
    Width = 224
    Height = 25
    DataSource = tentamenDataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    TabOrder = 10
  end
  object faculteitClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'faculteitDataSetProvider'
    Left = 568
    Top = 88
  end
  object faculteitDataSource: TDataSource
    DataSet = faculteitClientDataSet
    Left = 568
    Top = 120
  end
  object tentamenDataSource: TDataSource
    DataSet = tentamenClientDataSet
    OnDataChange = tentamenDataSourceDataChange
    Left = 440
    Top = 120
  end
  object tentamenClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'TentamenDataSetProvider'
    Left = 440
    Top = 88
  end
  object tentamenDataSetProvider: TDataSetProvider
    DataSet = tentamenSQLDataSet
    Constraints = True
    Left = 440
    Top = 56
  end
  object tentamenSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from tentamen'
    Params = <>
    Left = 440
    Top = 24
  end
  object studierichtingClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'studierichtingDataSetProvider'
    Left = 528
    Top = 88
  end
  object studierichtingDataSource: TDataSource
    DataSet = studierichtingClientDataSet
    Left = 528
    Top = 120
  end
  object studierichtingDataSetProvider: TDataSetProvider
    DataSet = studierichtingSQLDataSet
    Constraints = True
    Left = 528
    Top = 56
  end
  object vakDataSource: TDataSource
    DataSet = vakClientDataSet
    Left = 488
    Top = 120
  end
  object vakClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'vakDataSetProvider'
    Left = 488
    Top = 88
  end
  object vakDataSetProvider: TDataSetProvider
    DataSet = vakSQLDataSet
    Constraints = True
    Left = 488
    Top = 56
  end
  object ClientDataSet1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'faculteitDataSetProvider'
    Left = 664
    Top = 32
  end
  object DataSource1: TDataSource
    DataSet = ClientDataSet1
    Left = 664
    Top = 64
  end
  object faculteitDataSetProvider: TDataSetProvider
    DataSet = sasDataModule.FaculteitSQLDataSet
    Constraints = True
    Left = 568
    Top = 56
  end
  object studierichtingSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 
      'select studierichting.*, faculteit.* from studierichting join fa' +
      'culteit on studierichting.faculteit_id = faculteit.faculteit_id'
    Params = <>
    Left = 528
    Top = 24
  end
  object resultatenDataSource: TDataSource
    DataSet = resultatenClientDataSet
    Left = 608
    Top = 121
  end
  object resultatenClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'resultatenDataSetProvider'
    Left = 608
    Top = 89
  end
  object resultatenDataSetProvider: TDataSetProvider
    DataSet = resultatenSQLDataSet
    Constraints = True
    Left = 608
    Top = 57
  end
  object resultatenSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 
      'select   intekenlijst.*, inschrijving.idkaartnr,  inschrijving.s' +
      'tudierichting_id, persoon.naam, persoon.voornaam from intekenlij' +
      'st join inschrijving on intekenlijst.studienr = inschrijving.stu' +
      'dienr join persoon on persoon.idkaartnr = inschrijving.idkaartnr'
    Params = <>
    Left = 608
    Top = 25
  end
  object vakSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from vak'
    Params = <>
    Left = 488
    Top = 24
  end
end
