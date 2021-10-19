object WachtwoordForm: TWachtwoordForm
  Left = 450
  Top = 85
  Width = 402
  Height = 331
  Caption = 'Wachtwoord wijzigen'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object btnsluiten: TButton
    Left = 160
    Top = 272
    Width = 73
    Height = 25
    Caption = 'Sluiten'
    TabOrder = 0
    OnClick = btnsluitenClick
  end
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 377
    Height = 257
    TabOrder = 1
    object Label1: TLabel
      Left = 112
      Top = 24
      Width = 81
      Height = 13
      Caption = 'Oud wachtwoord'
    end
    object Label2: TLabel
      Left = 112
      Top = 80
      Width = 91
      Height = 13
      Caption = 'Nieuw wachtwoord'
    end
    object Label3: TLabel
      Left = 112
      Top = 136
      Width = 129
      Height = 13
      Caption = 'Herhaal nieuw wachtwoord'
    end
    object oudEdit: TEdit
      Left = 112
      Top = 40
      Width = 145
      Height = 21
      PasswordChar = '#'
      TabOrder = 0
    end
    object nieuwEdit1: TEdit
      Left = 112
      Top = 96
      Width = 145
      Height = 21
      PasswordChar = '#'
      TabOrder = 1
    end
    object nieuwEdit2: TEdit
      Left = 112
      Top = 152
      Width = 145
      Height = 21
      PasswordChar = '#'
      TabOrder = 2
    end
    object btnbevestig: TButton
      Left = 104
      Top = 208
      Width = 73
      Height = 25
      Caption = 'Bevestig'
      TabOrder = 3
      OnClick = btnbevestigClick
    end
    object btncancel: TButton
      Left = 200
      Top = 208
      Width = 73
      Height = 25
      Cancel = True
      Caption = 'Cancel'
      TabOrder = 4
      OnClick = btncancelClick
    end
  end
  object passwordSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * form mysql.user'
    Params = <>
    Left = 776
    Top = 282
  end
  object passwordDataSetProvider: TDataSetProvider
    DataSet = passwordSQLDataSet
    Constraints = True
    Left = 776
    Top = 330
  end
  object passwordClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'passwordDataSetProvider'
    Left = 776
    Top = 378
  end
  object passwordDataSource: TDataSource
    Left = 776
    Top = 426
  end
end
