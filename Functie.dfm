object FunctieForm: TFunctieForm
  Left = 404
  Top = 196
  BorderStyle = bsDialog
  Caption = 'Studenten functies'
  ClientHeight = 360
  ClientWidth = 474
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 217
    Height = 345
    Caption = 'Studenten functies'
    TabOrder = 0
  end
  object FunctieDBGrid: TDBGrid
    Left = 16
    Top = 24
    Width = 201
    Height = 321
    DataSource = functieDataSource
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnCellClick = FunctieDBGridCellClick
    OnKeyUp = FunctieDBGridKeyUp
    Columns = <
      item
        Expanded = False
        FieldName = 'functie_id'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'omschrijving'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'vergoeding'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'maxuren'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'taken'
        Visible = False
      end>
  end
  object GroupBox2: TGroupBox
    Left = 240
    Top = 8
    Width = 225
    Height = 305
    Caption = 'Toevoegen'
    TabOrder = 2
    object Label1: TLabel
      Left = 8
      Top = 80
      Width = 60
      Height = 13
      Caption = 'Omschrijving'
    end
    object Label2: TLabel
      Left = 8
      Top = 112
      Width = 54
      Height = 13
      Caption = 'Vergoeding'
    end
    object Label3: TLabel
      Left = 8
      Top = 144
      Width = 44
      Height = 13
      Caption = 'Max uren'
    end
    object Taken: TLabel
      Left = 8
      Top = 168
      Width = 31
      Height = 13
      Caption = 'Taken'
    end
    object OmschrijvingEdit: TEdit
      Left = 72
      Top = 72
      Width = 145
      Height = 21
      TabOrder = 0
    end
    object btnnieuw: TButton
      Left = 48
      Top = 240
      Width = 129
      Height = 25
      Caption = 'Nieuwe toevoegen'
      TabOrder = 1
      OnClick = btnnieuwClick
    end
    object btnwijzigen: TButton
      Left = 48
      Top = 272
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
    object VergoedingEdit: TEdit
      Left = 72
      Top = 104
      Width = 73
      Height = 21
      TabOrder = 4
    end
    object MaxurenEdit: TEdit
      Left = 72
      Top = 136
      Width = 145
      Height = 21
      TabOrder = 5
    end
    object TakenEdit: TMemo
      Left = 8
      Top = 184
      Width = 209
      Height = 49
      MaxLength = 1000
      TabOrder = 6
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
  object functieSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from functie'
    Params = <>
    Left = 248
    Top = 328
  end
  object functieDataSetProvider: TDataSetProvider
    DataSet = functieSQLDataSet
    Constraints = True
    Left = 288
    Top = 328
  end
  object functieClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'functieDataSetProvider'
    Left = 400
    Top = 328
  end
  object functieDataSource: TDataSource
    DataSet = functieClientDataSet
    Left = 440
    Top = 328
  end
end
