object HerinschrijvingfaculteitForm: THerinschrijvingfaculteitForm
  Left = 196
  Top = 171
  Width = 515
  Height = 226
  Caption = 'Herinschrijvingen'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
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
  end
  object SudierichtingLabel: TLabel
    Left = 24
    Top = 48
    Width = 64
    Height = 13
    Caption = 'Studierichting'
  end
  object CollegejaarLabel: TLabel
    Left = 24
    Top = 80
    Width = 52
    Height = 13
    Caption = 'Collegejaar'
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
    OnClick = DBLookupComboBox1Click
  end
  object CollegejaarEdit: TEdit
    Left = 104
    Top = 80
    Width = 129
    Height = 21
    TabOrder = 1
    Text = '2.005'
  end
  object CollegejaarUpDown: TUpDown
    Left = 233
    Top = 80
    Width = 15
    Height = 21
    Associate = CollegejaarEdit
    Min = 1980
    Max = 2080
    Position = 2005
    TabOrder = 2
    Wrap = False
  end
  object Button1: TButton
    Left = 328
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Rapport'
    TabOrder = 3
    OnClick = Button1Click
  end
  object CloseButton: TButton
    Left = 400
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 4
    OnClick = CloseButtonClick
  end
  object RadioGroup2: TRadioGroup
    Left = 288
    Top = 88
    Width = 185
    Height = 41
    Caption = ' Geslacht '
    Columns = 3
    ItemIndex = 2
    Items.Strings = (
      'Man'
      'Vrouw'
      'Beide')
    TabOrder = 5
  end
  object DBLookupComboBox2: TDBLookupComboBox
    Left = 104
    Top = 48
    Width = 145
    Height = 21
    Enabled = False
    KeyField = 'RICHTING_ID'
    ListField = 'STUDIERICHTING'
    ListSource = sasDataModule.StudierichtingDataSource
    TabOrder = 6
  end
end
