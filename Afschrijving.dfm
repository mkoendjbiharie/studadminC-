object AfschrijvingForm: TAfschrijvingForm
  Left = 262
  Top = 149
  Width = 696
  Height = 480
  Caption = 'Afschrijving'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 16
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
    Left = 16
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
    Left = 16
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
  object Label12: TLabel
    Left = 16
    Top = 248
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
    Left = 16
    Top = 216
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
    Left = 16
    Top = 280
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
    Left = 16
    Top = 312
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
  object AfschrijvingsDatumLabel: TLabel
    Left = 16
    Top = 344
    Width = 109
    Height = 13
    Caption = 'AfschrijvingsDatum'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StudieMemoLabel: TLabel
    Left = 320
    Top = 433
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
  object RederLabel: TLabel
    Left = 16
    Top = 377
    Width = 38
    Height = 13
    Caption = 'Reden'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object SysteemLabel: TLabel
    Left = 16
    Top = 401
    Width = 48
    Height = 13
    Caption = 'Systeem'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 368
    Top = 72
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
  object SchakelInschrijvingenLabel: TLabel
    Left = 368
    Top = 204
    Width = 247
    Height = 13
    Caption = 'Eerdere inschrijvingen voor het schakeljaar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 320
    Top = 336
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
  object SearchButton: TButton
    Left = 144
    Top = 70
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
  object ModusKnop: TBitBtn
    Left = 16
    Top = 16
    Width = 225
    Height = 41
    Caption = 'Student lezen'
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
    Left = 144
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
    TabOrder = 2
  end
  object FirstNameDBEdit: TDBEdit
    Left = 144
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
    TabOrder = 3
  end
  object IdCardDBEdit: TDBEdit
    Left = 144
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
    TabOrder = 4
  end
  object StudierichtingComboBox: TDBLookupComboBox
    Left = 144
    Top = 244
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
    TabOrder = 5
  end
  object FaculteitComboBox: TDBLookupComboBox
    Left = 144
    Top = 212
    Width = 145
    Height = 21
    DataField = 'FACULTEIT_ID'
    DataSource = sasDataModule.InschrijvingDataSource
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
    TabOrder = 6
  end
  object OpslaanButton: TButton
    Left = 264
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Opslaan'
    Enabled = False
    TabOrder = 7
  end
  object SearchEdit: TEdit
    Left = 16
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 8
  end
  object StudieNRDBEdit: TDBEdit
    Left = 144
    Top = 280
    Width = 145
    Height = 21
    DataField = 'STUDIENR'
    DataSource = sasDataModule.InschrijvingDataSource
    Enabled = False
    ReadOnly = True
    TabOrder = 9
  end
  object InschrijfJaarDBEdit: TDBEdit
    Left = 144
    Top = 312
    Width = 121
    Height = 21
    DataField = 'INSCHRIJFJAAR'
    DataSource = sasDataModule.InschrijvingDataSource
    Enabled = False
    ReadOnly = True
    TabOrder = 10
  end
  object AfschrijvingDBNavigator: TDBNavigator
    Left = 336
    Top = 16
    Width = 224
    Height = 25
    DataSource = sasDataModule.personDataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    TabOrder = 11
  end
  object AfschrijvingsDatumDBEdit: TDBEdit
    Left = 144
    Top = 344
    Width = 121
    Height = 21
    DataField = 'AFSCHRIJVINGSDATUM'
    DataSource = sasDataModule.InschrijvingDataSource
    ReadOnly = True
    TabOrder = 12
  end
  object StudieDBMemo: TDBMemo
    Left = 312
    Top = 357
    Width = 289
    Height = 89
    DataField = 'MEMO'
    DataSource = sasDataModule.InschrijvingDataSource
    ReadOnly = True
    TabOrder = 13
  end
  object RedenDBEdit: TDBEdit
    Left = 144
    Top = 377
    Width = 121
    Height = 21
    DataField = 'REDEN'
    DataSource = sasDataModule.InschrijvingDataSource
    ReadOnly = True
    TabOrder = 14
  end
  object SysteemDBLookupListBox: TDBLookupListBox
    Left = 16
    Top = 417
    Width = 129
    Height = 69
    DataField = 'SYSTEEM_ID'
    DataSource = sasDataModule.InschrijvingDataSource
    KeyField = 'SYSTEEM_ID'
    ListField = 'SYSTEEM'
    ListSource = sasDataModule.SysteemDataSource
    ReadOnly = True
    TabOrder = 15
  end
  object ToggleButton: TBitBtn
    Left = 184
    Top = 70
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
    Left = 360
    Top = 88
    Width = 193
    Height = 89
    DataSource = sasDataModule.EerdereInschrijvingenDataSource
    ReadOnly = True
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
  object DBGrid1: TDBGrid
    Left = 360
    Top = 228
    Width = 193
    Height = 57
    TabOrder = 18
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object MainMenu1: TMainMenu
    Left = 632
    Top = 480
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
