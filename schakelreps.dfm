object schakelrepsForm: TschakelrepsForm
  Left = 535
  Top = 396
  Width = 511
  Height = 273
  Caption = 'Inschrijvingen schakeljaar'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object FaculteitLabel: TLabel
    Left = 24
    Top = 24
    Width = 40
    Height = 13
    Caption = 'Faculteit'
    Visible = False
  end
  object SudierichtingLabel: TLabel
    Left = 24
    Top = 56
    Width = 64
    Height = 13
    Caption = 'Studierichting'
    Visible = False
  end
  object CollegejaarLabel: TLabel
    Left = 24
    Top = 88
    Width = 52
    Height = 13
    Caption = 'Collegejaar'
    Visible = False
  end
  object BevolkingsgroepLabel: TLabel
    Left = 32
    Top = 160
    Width = 79
    Height = 13
    Caption = 'Bevolkingsgroep'
    Visible = False
  end
  object NationaliteitLabel: TLabel
    Left = 16
    Top = 160
    Width = 81
    Height = 13
    Caption = 'NationaliteitLabel'
    Visible = False
  end
  object VooropleidingLabel: TLabel
    Left = 16
    Top = 160
    Width = 64
    Height = 13
    Caption = 'Vooropleiding'
    Visible = False
  end
  object DiplomaLabel: TLabel
    Left = 16
    Top = 160
    Width = 38
    Height = 13
    Caption = 'Diploma'
    Visible = False
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 104
    Top = 16
    Width = 145
    Height = 21
    KeyField = 'FACULTEIT_ID'
    ListField = 'FACULTEIT'
    ListSource = sasDataModule.FaculteitDataSource
    TabOrder = 0
    Visible = False
    OnClick = DBLookupComboBox1Click
  end
  object DBLookupComboBox2: TDBLookupComboBox
    Left = 104
    Top = 48
    Width = 145
    Height = 21
    KeyField = 'RICHTING_ID'
    ListField = 'STUDIERICHTING'
    ListSource = sasDataModule.StudierichtingDataSource
    TabOrder = 1
    Visible = False
  end
  object RadioGroup1: TRadioGroup
    Left = 288
    Top = 56
    Width = 185
    Height = 41
    Caption = ' Jaar '
    Columns = 2
    ItemIndex = 1
    Items.Strings = (
      'Specifiek'
      'Alle')
    TabOrder = 2
    OnClick = RadioGroup1Click
  end
  object CollegejaarEdit: TEdit
    Left = 104
    Top = 80
    Width = 129
    Height = 21
    TabOrder = 3
    Text = '2.005'
    Visible = False
  end
  object CollegejaarUpDown: TUpDown
    Left = 233
    Top = 80
    Width = 16
    Height = 21
    Associate = CollegejaarEdit
    Min = 1980
    Max = 2080
    Position = 2005
    TabOrder = 4
    Visible = False
    Wrap = False
  end
  object Button1: TButton
    Left = 328
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Rapport'
    TabOrder = 5
    OnClick = Button1Click
  end
  object CloseButton: TButton
    Left = 400
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 6
    OnClick = CloseButtonClick
  end
  object RadioGroup2: TRadioGroup
    Left = 288
    Top = 104
    Width = 185
    Height = 41
    Caption = ' Geslacht  '
    Columns = 3
    ItemIndex = 2
    Items.Strings = (
      'Man'
      'Vrouw'
      'Beide')
    TabOrder = 7
  end
  object StudierichtingRadioGroup: TRadioGroup
    Left = 288
    Top = 8
    Width = 185
    Height = 41
    Caption = ' Studierichting '
    Columns = 2
    ItemIndex = 1
    Items.Strings = (
      'Specifiek'
      'Alle')
    TabOrder = 8
    OnClick = StudierichtingRadioGroupClick
  end
  object BevolkingsgroepDBLookupComboBox: TDBLookupComboBox
    Left = 128
    Top = 152
    Width = 145
    Height = 21
    KeyField = 'BEV_ID'
    ListField = 'BEV_GROEP'
    TabOrder = 9
    Visible = False
  end
  object NationaliteitDBLookupComboBox: TDBLookupComboBox
    Left = 128
    Top = 152
    Width = 145
    Height = 21
    KeyField = 'NATIO_ID'
    ListField = 'NATIONALITEIT'
    TabOrder = 10
    Visible = False
  end
  object VooropleidingDBLookupComboBox: TDBLookupComboBox
    Left = 128
    Top = 152
    Width = 145
    Height = 21
    KeyField = 'OPLEIDING_ID'
    ListField = 'OPLEIDING'
    TabOrder = 11
    Visible = False
  end
  object DiplomaDBLookupComboBox: TDBLookupComboBox
    Left = 128
    Top = 152
    Width = 145
    Height = 21
    TabOrder = 12
    Visible = False
  end
end
