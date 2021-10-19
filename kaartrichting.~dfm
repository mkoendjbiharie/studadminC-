object KaartRichtingDlg: TKaartRichtingDlg
  Left = 689
  Top = 70
  BorderStyle = bsDialog
  Caption = 'Studentenkaart op richting'
  ClientHeight = 266
  ClientWidth = 394
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnActivate = FormActivate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 289
    Height = 225
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 24
    Top = 168
    Width = 64
    Height = 13
    Caption = 'Studierichting'
  end
  object Label2: TLabel
    Left = 24
    Top = 200
    Width = 130
    Height = 13
    Caption = 'Kies een studierichting'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 24
    Top = 144
    Width = 107
    Height = 13
    Caption = 'Kies een categorie'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object InschrijfjaarLabel: TLabel
    Left = 24
    Top = 120
    Width = 53
    Height = 13
    Caption = 'Inschrijfjaar'
    Visible = False
  end
  object CollegejaarLabel: TLabel
    Left = 104
    Top = 32
    Width = 86
    Height = 20
    Caption = '2006/2007'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 24
    Top = 32
    Width = 52
    Height = 13
    Caption = 'Collegejaar'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object OKBtn: TButton
    Left = 308
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 308
    Top = 38
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
    OnClick = CancelBtnClick
  end
  object RichtingComboBox: TDBLookupComboBox
    Left = 104
    Top = 168
    Width = 185
    Height = 21
    KeyField = 'RICHTING_ID'
    ListField = 'STUDIERICHTING'
    ListSource = sasDataModule.StudierichtingDataSource
    TabOrder = 2
  end
  object CategorieRadioGroup: TRadioGroup
    Left = 24
    Top = 72
    Width = 265
    Height = 41
    Caption = 'Studenten'
    Columns = 3
    ItemIndex = 1
    Items.Strings = (
      'oud'
      'nieuw'
      'alle')
    TabOrder = 3
    OnClick = CategorieRadioGroupClick
  end
  object InschrijfjaarEdit: TEdit
    Left = 96
    Top = 120
    Width = 129
    Height = 21
    TabOrder = 4
    Text = '2005'
    Visible = False
  end
  object UpDown1: TUpDown
    Left = 200
    Top = 32
    Width = 17
    Height = 21
    Enabled = False
    Min = 2000
    Max = 3000
    Position = 2000
    TabOrder = 5
    Thousands = False
    Wrap = False
    OnChangingEx = UpDown1ChangingEx
  end
  object UpDownEdit: TEdit
    Left = 216
    Top = 32
    Width = 0
    Height = 21
    TabOrder = 6
    Text = '2000'
    Visible = False
  end
end
