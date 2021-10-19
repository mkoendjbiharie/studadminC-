object KaartBatchDlg: TKaartBatchDlg
  Left = 315
  Top = 150
  BorderStyle = bsDialog
  Caption = 'Studentenkaarten batch'
  ClientHeight = 282
  ClientWidth = 434
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
    Width = 313
    Height = 265
    Shape = bsFrame
  end
  object StudienrLabel: TLabel
    Left = 16
    Top = 64
    Width = 67
    Height = 13
    Caption = 'Studienummer'
  end
  object Label1: TLabel
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
    Left = 340
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
    Left = 340
    Top = 38
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
    OnClick = CancelBtnClick
  end
  object StudienrEdit: TEdit
    Left = 112
    Top = 64
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object VoegToeButton: TButton
    Left = 240
    Top = 64
    Width = 65
    Height = 25
    Caption = 'Voeg toe'
    TabOrder = 3
    OnClick = VoegToeButtonClick
  end
  object BatchListBox: TListBox
    Left = 24
    Top = 112
    Width = 65
    Height = 97
    ItemHeight = 13
    TabOrder = 4
    Visible = False
  end
  object NummerListBox: TListBox
    Left = 112
    Top = 104
    Width = 121
    Height = 145
    ItemHeight = 13
    TabOrder = 5
  end
  object VerwijderButton: TButton
    Left = 240
    Top = 96
    Width = 65
    Height = 25
    Caption = 'Verwijder'
    TabOrder = 6
    OnClick = VerwijderButtonClick
  end
  object UpDown1: TUpDown
    Left = 200
    Top = 24
    Width = 17
    Height = 21
    Associate = UpDownEdit
    Min = 2000
    Max = 3000
    Position = 2000
    TabOrder = 7
    Thousands = False
    Wrap = False
    OnChangingEx = UpDown1ChangingEx
  end
  object UpDownEdit: TEdit
    Left = 216
    Top = 24
    Width = 0
    Height = 21
    TabOrder = 8
    Text = '2000'
    Visible = False
  end
end
