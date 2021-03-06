object VooropleidingForm: TVooropleidingForm
  Left = 273
  Top = 142
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderStyle = bsSingle
  Caption = 'Vooropleiding'
  ClientHeight = 360
  ClientWidth = 476
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
    Caption = 'Vooropleiding'
    TabOrder = 0
  end
  object VooropleidingDBGrid: TDBGrid
    Left = 16
    Top = 24
    Width = 201
    Height = 321
    DataSource = eduDataSource
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnCellClick = VooropleidingDBGridCellClick
    OnKeyUp = VooropleidingDBGridKeyUp
    Columns = <
      item
        Expanded = False
        FieldName = 'OPLEIDING_ID'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'OPLEIDING'
        Visible = True
      end>
  end
  object GroupBox2: TGroupBox
    Left = 240
    Top = 8
    Width = 225
    Height = 297
    Caption = 'Toevoegen/Wijzigen'
    TabOrder = 2
    object Label1: TLabel
      Left = 16
      Top = 72
      Width = 64
      Height = 13
      Caption = 'Vooropleiding'
      FocusControl = VooropleidingDBGrid
    end
    object VooropleidingEdit: TEdit
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
    Left = 328
    Top = 328
    Width = 57
    Height = 25
    Caption = 'Sluiten'
    TabOrder = 3
    OnClick = btnsluitenClick
  end
  object eduDataSource: TDataSource
    DataSet = eduClientDataSet
    Left = 627
    Top = 161
  end
  object eduClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'eduDataSetProvider'
    Left = 627
    Top = 113
  end
  object eduDataSetProvider: TDataSetProvider
    DataSet = eduSQLDataSet
    Constraints = True
    UpdateMode = upWhereKeyOnly
    Left = 627
    Top = 65
  end
  object eduSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from opleiding'
    Params = <>
    Left = 627
    Top = 17
  end
end
