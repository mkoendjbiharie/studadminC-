object BevolkingsgroepForm: TBevolkingsgroepForm
  Left = 322
  Top = 154
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderStyle = bsSingle
  Caption = 'Bevolkingsgroep'
  ClientHeight = 360
  ClientWidth = 478
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 217
    Height = 345
    Caption = 'Bevolkingsgroepen'
    TabOrder = 0
  end
  object BevolkingsgroepDBGrid: TDBGrid
    Left = 16
    Top = 24
    Width = 201
    Height = 321
    DataSource = ethnicDataSource
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnCellClick = BevolkingsgroepDBGridCellClick
    OnKeyUp = BevolkingsgroepDBGridKeyUp
    Columns = <
      item
        Expanded = False
        FieldName = 'BEV_ID'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'BEV_GROEP'
        Visible = True
      end>
  end
  object GroupBox2: TGroupBox
    Left = 240
    Top = 16
    Width = 225
    Height = 297
    Caption = 'Toevoegen/Wijzigen'
    TabOrder = 2
    object Label1: TLabel
      Left = 16
      Top = 72
      Width = 79
      Height = 13
      Caption = 'Bevolkingsgroep'
    end
    object BevolkingsgroepEdit: TEdit
      Left = 16
      Top = 88
      Width = 169
      Height = 21
      TabOrder = 0
    end
    object btnnieuw: TButton
      Left = 40
      Top = 128
      Width = 129
      Height = 25
      Caption = 'Nieuwe toevoegen'
      TabOrder = 1
      OnClick = btnnieuwClick
    end
    object btnwijzigen: TButton
      Left = 40
      Top = 160
      Width = 129
      Height = 25
      Caption = 'Huidige wijzigen'
      TabOrder = 2
      OnClick = btnwijzigenClick
    end
    object ToggleButton: TBitBtn
      Left = 16
      Top = 32
      Width = 113
      Height = 25
      Caption = 'wijzigen'
      TabOrder = 3
      OnClick = ToggleButtonClick
      Glyph.Data = {
        7A000000424D7A000000000000003E000000280000000F0000000F0000000100
        0100000000003C0000000000000000000000020000000000000000000000FFFF
        FF000000000080000000E0000000F8000000FE000000FF800000FFE00000FFF8
        0000FFE00000FF800000FE000000F8000000E00000008000000000000000}
    end
  end
  object btnsluiten: TButton
    Left = 320
    Top = 328
    Width = 57
    Height = 25
    Caption = 'Sluiten'
    TabOrder = 3
    OnClick = btnsluitenClick
  end
  object ethnicSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from bevolkingsgroep'
    Params = <>
    Left = 243
    Top = 321
  end
  object ethnicDataSetProvider: TDataSetProvider
    DataSet = ethnicSQLDataSet
    Constraints = True
    UpdateMode = upWhereKeyOnly
    Left = 283
    Top = 321
  end
  object ethnicClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'ethnicDataSetProvider'
    Left = 403
    Top = 321
  end
  object ethnicDataSource: TDataSource
    DataSet = ethnicClientDataSet
    Left = 443
    Top = 321
  end
end
