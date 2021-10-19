object Schakelstudent: TSchakelstudent
  Left = 691
  Top = 739
  Width = 943
  Height = 570
  Caption = 'Schakelstudent'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
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
    Top = 120
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
  object Label2: TLabel
    Left = 392
    Top = 112
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
    Left = 48
    Top = 304
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
  object Label4: TLabel
    Left = 48
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
    Left = 48
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
  object StudieMemoLabel: TLabel
    Left = 48
    Top = 481
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
  object Label1: TLabel
    Left = 40
    Top = 80
    Width = 59
    Height = 16
    Caption = 'Persoon'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 40
    Top = 240
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
  object SearchButton: TButton
    Left = 488
    Top = 22
    Width = 33
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
  object NameDBEdit: TDBEdit
    Left = 168
    Top = 149
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
    TabOrder = 1
  end
  object FirstNameDBEdit: TDBEdit
    Left = 168
    Top = 183
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
    TabOrder = 2
  end
  object IdCardDBEdit: TDBEdit
    Left = 168
    Top = 117
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
    TabOrder = 3
    OnExit = IdCardDBEditExit
  end
  object LastRecordsDBGrid: TDBGrid
    Left = 384
    Top = 128
    Width = 241
    Height = 329
    DataSource = sasDataModule.SchakelGridDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 4
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
    DataSource = sasDataModule.SchakelDataSource
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
    TabOrder = 5
    OnClick = StudierichtingComboBoxClick
  end
  object NieuwButton: TButton
    Left = 144
    Top = 256
    Width = 75
    Height = 25
    Caption = 'Nieuw '
    Enabled = False
    TabOrder = 6
    OnClick = NieuwButtonClick
  end
  object OpslaanButton: TButton
    Left = 216
    Top = 256
    Width = 75
    Height = 25
    Caption = 'Opslaan'
    Enabled = False
    TabOrder = 7
    OnClick = OpslaanButtonClick
  end
  object VerwijderButton: TButton
    Left = 288
    Top = 256
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
    TabOrder = 8
    OnClick = VerwijderButtonClick
  end
  object SearchEdit: TEdit
    Left = 360
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 9
  end
  object StudieNRDBEdit: TDBEdit
    Left = 176
    Top = 336
    Width = 145
    Height = 21
    DataField = 'STUDIENR'
    DataSource = sasDataModule.SchakelDataSource
    Enabled = False
    TabOrder = 10
  end
  object InschrijfJaarDBEdit: TDBEdit
    Left = 176
    Top = 368
    Width = 121
    Height = 21
    DataField = 'SCHAKELJAAR'
    DataSource = sasDataModule.SchakelDataSource
    Enabled = False
    TabOrder = 11
  end
  object InschrijvingDBNavigator: TDBNavigator
    Left = 136
    Top = 72
    Width = 224
    Height = 25
    DataSource = sasDataModule.personDataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    TabOrder = 12
    OnClick = InschrijvingDBNavigatorClick
  end
  object StudieDBMemo: TDBMemo
    Left = 48
    Top = 501
    Width = 289
    Height = 89
    DataField = 'MEMO'
    DataSource = sasDataModule.SchakelDataSource
    ReadOnly = True
    TabOrder = 13
  end
  object ToggleButton: TBitBtn
    Left = 520
    Top = 22
    Width = 105
    Height = 25
    Caption = 'op idnummer'
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
  object AfgerondDBRadioGroup: TDBRadioGroup
    Left = 48
    Top = 400
    Width = 121
    Height = 65
    Caption = ' Afgerond '
    DataField = 'AFGEROND'
    DataSource = sasDataModule.SchakelDataSource
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Items.Strings = (
      'Ja'
      'Nee')
    ParentFont = False
    ReadOnly = True
    TabOrder = 15
    Values.Strings = (
      '1'
      '0')
  end
  object VolgnummerDBEdit: TDBEdit
    Left = 696
    Top = 32
    Width = 121
    Height = 21
    DataField = 'NUMMER'
    DataSource = sasDataModule.MaxNummersDataSource
    ReadOnly = True
    TabOrder = 16
    Visible = False
  end
  object JaarDBEdit: TDBEdit
    Left = 696
    Top = 48
    Width = 121
    Height = 21
    DataField = 'JAAR'
    DataSource = sasDataModule.MaxNummersDataSource
    ReadOnly = True
    TabOrder = 17
    Visible = False
  end
  object DBNavigator1: TDBNavigator
    Left = 144
    Top = 232
    Width = 216
    Height = 25
    DataSource = sasDataModule.SchakelDataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    TabOrder = 18
  end
  object MainMenu1: TMainMenu
    Left = 624
    Top = 384
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
end
