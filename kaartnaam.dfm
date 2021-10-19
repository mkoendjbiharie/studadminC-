object KaartNaamDlg: TKaartNaamDlg
  Left = 244
  Top = 536
  BorderStyle = bsDialog
  Caption = 'Studentenkaart op naam'
  ClientHeight = 179
  ClientWidth = 392
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnClose = FormClose
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
    Width = 28
    Height = 13
    Caption = 'Naam'
  end
  object Label2: TLabel
    Left = 24
    Top = 112
    Width = 261
    Height = 13
    Caption = 'Voer de famillienaam of een gedeelte ervan in'
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
  object NaamEdit: TEdit
    Left = 72
    Top = 64
    Width = 209
    Height = 21
    TabOrder = 2
  end
  object UpDownEdit: TEdit
    Left = 216
    Top = 24
    Width = 0
    Height = 21
    TabOrder = 3
    Text = '2000'
    Visible = False
  end
  object UpDown1: TUpDown
    Left = 200
    Top = 24
    Width = 16
    Height = 21
    Associate = UpDownEdit
    Min = 2000
    Max = 3000
    Position = 2000
    TabOrder = 4
    Thousands = False
    Wrap = False
    OnChangingEx = UpDown1ChangingEx
  end
end
