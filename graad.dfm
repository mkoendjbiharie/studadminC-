object GraadForm: TGraadForm
  Left = 454
  Top = 118
  Width = 484
  Height = 387
  Caption = 'Graad'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 217
    Height = 345
    Caption = 'Beschikbare graden'
    TabOrder = 0
  end
  object GraadDBGrid: TDBGrid
    Left = 16
    Top = 24
    Width = 201
    Height = 321
    DataSource = graadDataSource
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnCellClick = GraadDBGridCellClick
    OnKeyUp = GraadDBGridKeyUp
    Columns = <
      item
        Expanded = False
        FieldName = 'graad_id'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'GRAAD'
        Width = 120
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
      Width = 29
      Height = 13
      Caption = 'Graad'
    end
    object GraadEdit: TEdit
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
  object graadDataSource: TDataSource
    DataSet = graadClientDataSet
    Left = 443
    Top = 321
  end
  object graadClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'graadDataSetProvider'
    Left = 408
    Top = 321
  end
  object graadDataSetProvider: TDataSetProvider
    DataSet = graadSQLDataSet
    Constraints = True
    UpdateMode = upWhereKeyOnly
    Left = 283
    Top = 328
  end
  object graadSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from graad'
    Params = <>
    Left = 243
    Top = 321
  end
end
