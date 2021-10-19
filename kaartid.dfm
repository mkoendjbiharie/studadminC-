object KaartIdDlg: TKaartIdDlg
  Left = 466
  Top = 224
  BorderStyle = bsDialog
  Caption = 'Studentenkaart op idnummer'
  ClientHeight = 179
  ClientWidth = 395
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 289
    Height = 161
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 24
    Top = 64
    Width = 46
    Height = 13
    Caption = 'Idnummer'
  end
  object Label2: TLabel
    Left = 24
    Top = 112
    Width = 263
    Height = 13
    Caption = 'Voer het idnummer of een gedeelte daarvan in'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 24
    Top = 24
    Width = 52
    Height = 13
    Caption = 'Collegejaar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object CollegejaarLabel: TLabel
    Left = 104
    Top = 24
    Width = 86
    Height = 20
    Caption = '2006/2007'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
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
  object IdnummerEdit: TEdit
    Left = 88
    Top = 64
    Width = 193
    Height = 21
    TabOrder = 2
  end
  object UpDown1: TUpDown
    Left = 218
    Top = 24
    Width = 17
    Height = 21
    Min = 2000
    Max = 3000
    Position = 2000
    TabOrder = 3
    Thousands = False
    Wrap = False
    OnChangingEx = UpDown1ChangingEx
  end
  object UpDownEdit: TEdit
    Left = 216
    Top = 24
    Width = 2
    Height = 21
    TabOrder = 4
    Text = '2000'
    Visible = False
  end
end
