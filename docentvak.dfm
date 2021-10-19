object DocentVakForm: TDocentVakForm
  Left = 319
  Top = 134
  Width = 870
  Height = 572
  Caption = 'Docent vakken'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 40
    Top = 264
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
    Top = 298
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
    Top = 232
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
  object DocentLabel: TLabel
    Left = 40
    Top = 144
    Width = 50
    Height = 16
    Caption = 'Docent'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object VakLabel: TLabel
    Left = 400
    Top = 136
    Width = 28
    Height = 16
    Caption = 'Vak'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label12: TLabel
    Left = 40
    Top = 360
    Width = 77
    Height = 14
    Caption = 'Studierichting'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 40
    Top = 328
    Width = 46
    Height = 14
    Caption = 'Faculteit'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label31: TLabel
    Left = 232
    Top = 168
    Width = 18
    Height = 13
    Caption = 'van'
  end
  object VakCodeLabel: TLabel
    Left = 408
    Top = 224
    Width = 51
    Height = 13
    Caption = 'Vakcode'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object VakNaamLabel: TLabel
    Left = 408
    Top = 256
    Width = 53
    Height = 13
    Caption = 'Vaknaam'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object VanLabel: TLabel
    Left = 408
    Top = 288
    Width = 23
    Height = 13
    Caption = 'Van'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Totlabel: TLabel
    Left = 408
    Top = 320
    Width = 20
    Height = 13
    Caption = 'Tot'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StudierichtingLookupComboBox: TDBLookupComboBox
    Left = 40
    Top = 104
    Width = 145
    Height = 21
    KeyField = 'RICHTING_ID'
    ListField = 'STUDIERICHTING'
    ListSource = studierichtingDataSource
    TabOrder = 14
  end
  object NameDBEdit: TDBEdit
    Left = 176
    Top = 261
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
    Top = 295
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
    Top = 229
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
    OnChange = IdCardDBEditChange
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
    Left = 192
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
    Width = 145
    Height = 21
    TabOrder = 5
  end
  object ToggleButton: TBitBtn
    Left = 232
    Top = 102
    Width = 105
    Height = 25
    Caption = 'op docentnaam'
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
  object DocentVakNavigator: TDBNavigator
    Left = 488
    Top = 128
    Width = 224
    Height = 25
    DataSource = docentvakDataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    TabOrder = 10
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
    TabOrder = 11
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
    TabOrder = 12
    Text = 'first'
  end
  object last: TEdit
    Left = 296
    Top = 168
    Width = 57
    Height = 21
    Enabled = False
    TabOrder = 13
    Text = 'last'
  end
  object VakCodeDBEdit: TDBEdit
    Left = 520
    Top = 224
    Width = 121
    Height = 21
    DataField = 'VAK_CODE'
    DataSource = vakDataSource
    ReadOnly = True
    TabOrder = 15
  end
  object VakNaamDBEdit: TDBEdit
    Left = 520
    Top = 256
    Width = 121
    Height = 21
    DataField = 'VAK_NAAM'
    DataSource = vakDataSource
    ReadOnly = True
    TabOrder = 16
  end
  object FaculteitDBEdit: TDBEdit
    Left = 176
    Top = 328
    Width = 121
    Height = 21
    DataField = 'faculteit'
    DataSource = personDataSource
    ReadOnly = True
    TabOrder = 17
  end
  object StudierichtingDBEdit: TDBEdit
    Left = 176
    Top = 360
    Width = 121
    Height = 21
    DataField = 'studierichting'
    DataSource = personDataSource
    ReadOnly = True
    TabOrder = 18
  end
  object DocentIdDBEdit: TDBEdit
    Left = 400
    Top = 24
    Width = 121
    Height = 21
    DataField = 'docent_id'
    DataSource = personDataSource
    TabOrder = 19
    Visible = False
  end
  object VanDBEdit: TDBEdit
    Left = 520
    Top = 288
    Width = 121
    Height = 21
    TabOrder = 20
  end
  object TotDBEdit: TDBEdit
    Left = 520
    Top = 320
    Width = 121
    Height = 21
    TabOrder = 21
  end
  object personClientDataSet: TClientDataSet
    Aggregates = <>
    FilterOptions = [foCaseInsensitive]
    Params = <>
    ProviderName = 'pesonDataSetProvider'
    Left = 440
    Top = 448
  end
  object studierichtingClientDataSet: TClientDataSet
    Aggregates = <>
    FilterOptions = [foCaseInsensitive]
    Params = <>
    ProviderName = 'studierichingDataSetProvider'
    Left = 568
    Top = 440
  end
  object faculteitClientDataSet: TClientDataSet
    Aggregates = <>
    FilterOptions = [foCaseInsensitive]
    Params = <>
    ProviderName = 'faculteitDataSetProvider'
    Left = 512
    Top = 400
  end
  object faculteitDataSource: TDataSource
    DataSet = faculteitClientDataSet
    Left = 512
    Top = 440
  end
  object personDataSource: TDataSource
    DataSet = personClientDataSet
    Left = 440
    Top = 488
  end
  object studierichtingDataSource: TDataSource
    DataSet = studierichtingClientDataSet
    Left = 568
    Top = 480
  end
  object docentvakClientDataSet: TClientDataSet
    Aggregates = <>
    FilterOptions = [foCaseInsensitive]
    Params = <>
    ProviderName = 'docentvakDataSetProvider'
    Left = 624
    Top = 400
  end
  object docentvakDataSource: TDataSource
    DataSet = docentvakClientDataSet
    Left = 624
    Top = 440
  end
  object docentvakDataSetProvider: TDataSetProvider
    DataSet = sasDataModule.docentvakSQLDataSet
    Constraints = True
    Left = 624
    Top = 360
  end
  object studierichingDataSetProvider: TDataSetProvider
    DataSet = studierichtingSQLDataSet
    Constraints = True
    Left = 568
    Top = 400
  end
  object faculteitDataSetProvider: TDataSetProvider
    DataSet = sasDataModule.FaculteitSQLDataSet
    Constraints = True
    Left = 512
    Top = 360
  end
  object pesonDataSetProvider: TDataSetProvider
    DataSet = personSQLDataSet
    Constraints = True
    Left = 440
    Top = 408
  end
  object docentbetrekingDataSource: TDataSource
    DataSet = docentbetrekkingClientDataSet
    Left = 672
    Top = 480
  end
  object docentbetrekkingClientDataSet: TClientDataSet
    Aggregates = <>
    FilterOptions = [foCaseInsensitive]
    Params = <>
    ProviderName = 'docentbetrekkingDataSetProvider'
    Left = 672
    Top = 440
  end
  object docentbetrekkingDataSetProvider: TDataSetProvider
    DataSet = docentbetrekkingSQLDataSet
    Constraints = True
    Left = 672
    Top = 400
  end
  object vakDataSource: TDataSource
    DataSet = vakClientDataSet
    Left = 720
    Top = 480
  end
  object vakClientDataSet: TClientDataSet
    Aggregates = <>
    FilterOptions = [foCaseInsensitive]
    Params = <>
    ProviderName = 'vakDataSetProvider'
    Left = 720
    Top = 440
  end
  object vakDataSetProvider: TDataSetProvider
    DataSet = vakSQLDataSet
    Constraints = True
    Left = 720
    Top = 400
  end
  object personSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 
      'select persoon.naam, persoon.voornaam, persoon.idkaartnr, persoo' +
      'n.volgnr, docentbetrekking.*, docentvak.vak_id from persoon join' +
      ' docentbetrekking on persoon.idkaartnr = docentbetrekking.idkaar' +
      'tnr join docentvak on docentbetrekking.docent_id = docentvak.doc' +
      'ent_id'
    Params = <>
    Left = 440
    Top = 368
  end
  object studierichtingSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 
      'select studierichting.*, faculteit.faculteit, vak.vak_id , docen' +
      'tvak.docent_id from studierichting join faculteit on faculteit.F' +
      'ACULTEIT_ID = studierichting.FACULTEIT_ID join vak on vak.richti' +
      'ng_id = studierichting.richting_id join docentvak on vak.vak_id ' +
      '= docentvak.vak_id'
    Params = <>
    Left = 568
    Top = 360
  end
  object docentbetrekkingSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 
      'SELECT docentbetrekking.* from docentbetrekking join docentvak o' +
      'n docentbetrekking.docent_id = docentvak.docent_id'
    Params = <>
    Left = 672
    Top = 360
  end
  object vakSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 
      'select vak.*, docentvak.docent_id from vak join docentvak on vak' +
      '.vak_id = docentvak.vak_id'
    Params = <>
    Left = 720
    Top = 360
  end
end
