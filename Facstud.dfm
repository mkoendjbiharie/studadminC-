object Faculteitstudent: TFaculteitstudent
  Left = 254
  Top = 181
  Width = 1037
  Height = 812
  BiDiMode = bdLeftToRight
  Caption = 'Faculteitstudent'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  ParentBiDiMode = False
  Position = poScreenCenter
  Visible = True
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 616
    Top = 80
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
    Top = 304
    Width = 77
    Height = 14
    Caption = 'Studierichting'
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 40
    Top = 272
    Width = 46
    Height = 14
    Caption = 'Faculteit'
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 40
    Top = 336
    Width = 80
    Height = 13
    Caption = 'Studienummer'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 40
    Top = 368
    Width = 118
    Height = 13
    Caption = 'Jaar van inschrijving'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object AfstudeerDatumLabel: TLabel
    Left = 40
    Top = 440
    Width = 91
    Height = 13
    Caption = 'AfstudeerDatum'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object VerlengingLabel: TLabel
    Left = 40
    Top = 472
    Width = 124
    Height = 13
    Caption = 'Verlenging studieduur'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object AfschrijvingsDatumLabel: TLabel
    Left = 40
    Top = 520
    Width = 107
    Height = 13
    Caption = 'Afschrijvingsdatum'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StudieMemoLabel: TLabel
    Left = 392
    Top = 328
    Width = 75
    Height = 13
    Caption = 'Opmerkingen'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object RederLabel: TLabel
    Left = 40
    Top = 552
    Width = 133
    Height = 13
    Caption = 'Reden voor afschrijven'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object SysteemLabel: TLabel
    Left = 384
    Top = 232
    Width = 48
    Height = 13
    Caption = 'Systeem'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Label7: TLabel
    Left = 384
    Top = 80
    Width = 219
    Height = 13
    Caption = 'Eerdere inschrijvingen voor een studie'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 40
    Top = 72
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
    Left = 40
    Top = 216
    Width = 79
    Height = 16
    Caption = 'Inschrijving'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
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
  object Label3: TLabel
    Left = 40
    Top = 136
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
    Top = 170
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
    Top = 104
    Width = 58
    Height = 14
    Caption = 'Idnummer'
    Font.Charset = ANSI_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object SearchButton: TButton
    Left = 488
    Top = 22
    Width = 41
    Height = 25
    Caption = 'Zoek'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = SearchButtonClick
  end
  object LastRecordsDBGrid: TDBGrid
    Left = 616
    Top = 96
    Width = 241
    Height = 209
    DataSource = sasDataModule.GridDataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'VOLGNR'
        Width = 53
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'IDKAARTNR'
        Width = 74
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'STUDIENR'
        Width = 85
        Visible = True
      end>
  end
  object StudierichtingComboBox: TDBLookupComboBox
    Left = 176
    Top = 300
    Width = 145
    Height = 21
    DataField = 'STUDIERICHTING_ID'
    DataSource = sasDataModule.InschrijvingDataSource
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    KeyField = 'RICHTING_ID'
    ListField = 'STUDIERICHTING'
    ListSource = sasDataModule.StudierichtingDataSource
    ParentFont = False
    ReadOnly = True
    TabOrder = 2
    OnClick = StudierichtingComboBoxClick
  end
  object FaculteitComboBox: TDBLookupComboBox
    Left = 176
    Top = 268
    Width = 145
    Height = 21
    DataField = 'FACULTEIT_ID'
    DataSource = sasDataModule.InschrijvingDataSource
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
    TabOrder = 3
    OnClick = FaculteitComboBoxClick
  end
  object NieuwButton: TButton
    Left = 128
    Top = 232
    Width = 75
    Height = 25
    Caption = 'Nieuw '
    Enabled = False
    TabOrder = 4
    OnClick = NieuwButtonClick
  end
  object OpslaanButton: TButton
    Left = 200
    Top = 232
    Width = 81
    Height = 25
    Caption = 'Opslaan'
    Enabled = False
    TabOrder = 5
    OnClick = OpslaanButtonClick
  end
  object VerwijderButton: TButton
    Left = 280
    Top = 232
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
    TabOrder = 6
    OnClick = VerwijderButtonClick
  end
  object SearchEdit: TEdit
    Left = 360
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 7
  end
  object StudieNRDBEdit: TDBEdit
    Left = 176
    Top = 336
    Width = 145
    Height = 21
    DataField = 'STUDIENR'
    DataSource = sasDataModule.InschrijvingDataSource
    Enabled = False
    TabOrder = 8
  end
  object InschrijfJaarDBEdit: TDBEdit
    Left = 176
    Top = 368
    Width = 121
    Height = 21
    DataField = 'INSCHRIJFJAAR'
    DataSource = sasDataModule.InschrijvingDataSource
    Enabled = False
    TabOrder = 9
  end
  object InschrijvingDBNavigator: TDBNavigator
    Left = 128
    Top = 72
    Width = 224
    Height = 25
    DataSource = sasDataModule.personDataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    TabOrder = 10
    OnClick = InschrijvingDBNavigatorClick
  end
  object AfstudeerDatumDBEdit: TDBEdit
    Left = 176
    Top = 440
    Width = 121
    Height = 21
    DataField = 'AFSTUDEERDATUM'
    DataSource = sasDataModule.InschrijvingDataSource
    Enabled = False
    ReadOnly = True
    TabOrder = 11
  end
  object VerlengingDBEdit: TDBEdit
    Left = 176
    Top = 472
    Width = 121
    Height = 21
    DataField = 'VERLENGING'
    DataSource = sasDataModule.InschrijvingDataSource
    ReadOnly = True
    TabOrder = 12
  end
  object AfschrijvingsDatumDBEdit: TDBEdit
    Left = 176
    Top = 520
    Width = 121
    Height = 21
    DataField = 'AFSCHRIJVINGSDATUM'
    DataSource = sasDataModule.InschrijvingDataSource
    Enabled = False
    ReadOnly = True
    TabOrder = 13
  end
  object StudieDBMemo: TDBMemo
    Left = 384
    Top = 344
    Width = 289
    Height = 57
    DataField = 'MEMO'
    DataSource = sasDataModule.InschrijvingDataSource
    ReadOnly = True
    TabOrder = 14
  end
  object SysteemDBLookupListBox: TDBLookupListBox
    Left = 384
    Top = 248
    Width = 193
    Height = 56
    DataField = 'SYSTEEM_ID'
    DataSource = sasDataModule.InschrijvingDataSource
    KeyField = 'SYSTEEM_ID'
    ListField = 'SYSTEEM'
    ReadOnly = True
    TabOrder = 15
  end
  object ToggleButton: TBitBtn
    Left = 528
    Top = 22
    Width = 105
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
  object EerdereInschrijvingenDBGrid: TDBGrid
    Left = 384
    Top = 96
    Width = 193
    Height = 129
    DataSource = sasDataModule.EerdereInschrijvingenDataSource
    TabOrder = 17
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'INSCHRIJFJAAR'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'STUDIENR'
        Width = 84
        Visible = True
      end>
  end
  object RedenDBMemo: TDBMemo
    Left = 176
    Top = 552
    Width = 145
    Height = 73
    Enabled = False
    TabOrder = 18
  end
  object VolgnummerDBEdit: TDBEdit
    Left = 664
    Top = 24
    Width = 121
    Height = 21
    DataField = 'NUMMER'
    DataSource = sasDataModule.MaxNummersDataSource
    ReadOnly = True
    TabOrder = 19
    Visible = False
  end
  object JaarDBEdit: TDBEdit
    Left = 664
    Top = 48
    Width = 121
    Height = 21
    DataField = 'JAAR'
    DataSource = sasDataModule.MaxNummersDataSource
    ReadOnly = True
    TabOrder = 20
    Visible = False
  end
  object DBNavigator1: TDBNavigator
    Left = 128
    Top = 208
    Width = 224
    Height = 25
    DataSource = sasDataModule.InschrijvingDataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    TabOrder = 21
  end
  object AfgestudeerdDBRadioGroup: TDBRadioGroup
    Left = 40
    Top = 400
    Width = 161
    Height = 33
    Caption = ' Afgestudeerd '
    Columns = 2
    DataField = 'AFGESTUDEERD'
    DataSource = sasDataModule.InschrijvingDataSource
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Items.Strings = (
      'Nee'
      'Ja')
    ParentFont = False
    ReadOnly = True
    TabOrder = 22
    Values.Strings = (
      '0'
      '1')
  end
  object ExtraPanel: TPanel
    Left = 384
    Top = 416
    Width = 297
    Height = 233
    BevelOuter = bvNone
    TabOrder = 23
    Visible = False
    object Label10: TLabel
      Left = 8
      Top = 120
      Width = 65
      Height = 14
      Caption = 'Referenties'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label11: TLabel
      Left = 16
      Top = 152
      Width = 7
      Height = 16
      Caption = '1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 16
      Top = 176
      Width = 7
      Height = 16
      Caption = '2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label14: TLabel
      Left = 16
      Top = 200
      Width = 7
      Height = 16
      Caption = '3'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBEdit1: TDBEdit
      Left = 40
      Top = 152
      Width = 241
      Height = 21
      DataField = 'REFERENTIE1'
      DataSource = sasDataModule.InschrijvingDataSource
      TabOrder = 0
    end
    object DBEdit2: TDBEdit
      Left = 40
      Top = 176
      Width = 241
      Height = 21
      DataField = 'REFERENTIE2'
      DataSource = sasDataModule.InschrijvingDataSource
      TabOrder = 1
    end
    object DBEdit3: TDBEdit
      Left = 40
      Top = 200
      Width = 241
      Height = 21
      DataField = 'REFERENTIE3'
      DataSource = sasDataModule.InschrijvingDataSource
      TabOrder = 2
    end
    object GroupBox1: TGroupBox
      Left = 16
      Top = 8
      Width = 249
      Height = 105
      Caption = ' Vooropleiding '
      TabOrder = 3
      object Label15: TLabel
        Left = 24
        Top = 48
        Width = 47
        Height = 13
        Caption = 'Instituut'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label16: TLabel
        Left = 24
        Top = 24
        Width = 35
        Height = 13
        Caption = 'Graad'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label17: TLabel
        Left = 24
        Top = 72
        Width = 48
        Height = 13
        Caption = 'Richting'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object InstituutDBEdit: TDBEdit
        Left = 96
        Top = 40
        Width = 145
        Height = 21
        DataField = 'VOORINSTITUUT'
        DataSource = sasDataModule.InschrijvingDataSource
        TabOrder = 0
      end
      object RichtingDBEdit: TDBEdit
        Left = 96
        Top = 64
        Width = 145
        Height = 21
        DataField = 'VOORRICHTING'
        DataSource = sasDataModule.InschrijvingDataSource
        TabOrder = 1
      end
      object GraadComboBox: TDBLookupComboBox
        Left = 96
        Top = 16
        Width = 145
        Height = 21
        DataField = 'VOORGRAAD'
        DataSource = sasDataModule.InschrijvingDataSource
        KeyField = 'GRAAD_ID'
        ListField = 'GRAAD'
        ListSource = graadDataSource
        TabOrder = 2
      end
    end
  end
  object NameDBEdit: TDBEdit
    Left = 176
    Top = 133
    Width = 121
    Height = 21
    DataField = 'NAAM'
    DataSource = sasDataModule.personDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 24
  end
  object FirstNameDBEdit: TDBEdit
    Left = 176
    Top = 167
    Width = 121
    Height = 21
    DataField = 'VOORNAAM'
    DataSource = sasDataModule.personDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 25
  end
  object IdCardDBEdit: TDBEdit
    Left = 176
    Top = 101
    Width = 121
    Height = 21
    DataField = 'IDKAARTNR'
    DataSource = sasDataModule.personDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 26
    OnChange = IdCardDBEditChange
    OnExit = IdCardDBEditExit
  end
  object MainMenu1: TMainMenu
    Left = 800
    Top = 528
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
  object graadDataSetProvider: TDataSetProvider
    DataSet = graadSQLDataSet
    Constraints = True
    UpdateMode = upWhereKeyOnly
    Left = 699
    Top = 320
  end
  object graadSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from graad'
    Params = <>
    Left = 699
    Top = 289
  end
  object graadClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'graadDataSetProvider'
    Left = 696
    Top = 353
  end
  object graadDataSource: TDataSource
    DataSet = graadClientDataSet
    Left = 699
    Top = 385
  end
end
