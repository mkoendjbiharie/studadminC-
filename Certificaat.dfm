object CertificaatForm: TCertificaatForm
  Left = 316
  Top = 167
  BorderStyle = bsDialog
  Caption = 'Certificaten'
  ClientHeight = 369
  ClientWidth = 490
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
    Caption = 'Certificaten'
    TabOrder = 0
  end
  object CertificaatDBGrid: TDBGrid
    Left = 16
    Top = 24
    Width = 201
    Height = 321
    DataSource = certificaatDataSource
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnCellClick = CertificaatDBGridCellClick
    OnKeyUp = CertificaatDBGridKeyUp
    Columns = <
      item
        Expanded = False
        FieldName = 'CERTIFICAAT_ID'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'OMSCHRIJVING'
        Visible = True
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
      Left = 24
      Top = 80
      Width = 47
      Height = 13
      Caption = 'Certificaat'
    end
    object CertificaatEdit: TEdit
      Left = 24
      Top = 96
      Width = 169
      Height = 21
      TabOrder = 0
    end
    object btnnieuw: TButton
      Left = 40
      Top = 136
      Width = 129
      Height = 25
      Caption = 'Nieuwe toevoegen'
      TabOrder = 1
      OnClick = btnnieuwClick
    end
    object btnwijzigen: TButton
      Left = 40
      Top = 168
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
  object certificaatSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from certificaat'
    Params = <>
    Left = 248
    Top = 328
  end
  object certificaatDataSetProvider: TDataSetProvider
    DataSet = certificaatSQLDataSet
    Constraints = True
    Left = 288
    Top = 328
  end
  object certificaatClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'certificaatDataSetProvider'
    Left = 416
    Top = 328
  end
  object certificaatDataSource: TDataSource
    DataSet = certificaatClientDataSet
    Left = 448
    Top = 328
  end
end
