object TutorialForm: TTutorialForm
  Left = 289
  Top = 316
  Width = 696
  Height = 480
  Caption = 'TutorialForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object TutorialRichEdit: TRichEdit
    Left = 24
    Top = 16
    Width = 969
    Height = 657
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'TutorialRichEdit')
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object MainMenu1: TMainMenu
    Left = 720
    Top = 96
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
