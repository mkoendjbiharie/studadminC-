object StudierichtingForm: TStudierichtingForm
  Left = -4
  Top = -4
  Width = 1288
  Height = 778
  Caption = 'Studierichting gegevens'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label12: TLabel
    Left = 52
    Top = 112
    Width = 77
    Height = 14
    Caption = 'Studierichting'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 51
    Top = 72
    Width = 46
    Height = 14
    Caption = 'Faculteit'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 737
    Top = 400
    Width = 56
    Height = 13
    Caption = 'Docenten'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 50
    Top = 240
    Width = 15
    Height = 13
    Caption = 'RC'
  end
  object Label5: TLabel
    Left = 51
    Top = 312
    Width = 62
    Height = 13
    Caption = 'Secretaresse'
  end
  object Label6: TLabel
    Left = 435
    Top = 216
    Width = 30
    Height = 13
    Caption = 'Kamer'
  end
  object Label7: TLabel
    Left = 345
    Top = 216
    Width = 40
    Height = 13
    Caption = 'Gebouw'
  end
  object Label8: TLabel
    Left = 502
    Top = 216
    Width = 35
    Height = 13
    Caption = 'Toestel'
  end
  object Label9: TLabel
    Left = 47
    Top = 272
    Width = 82
    Height = 13
    Caption = 'Waarnemend RC'
  end
  object ModusLabel: TLabel
    Left = 48
    Top = 16
    Width = 142
    Height = 29
    Caption = 'ModusLabel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StudierichtingComboBox: TDBLookupComboBox
    Left = 160
    Top = 108
    Width = 145
    Height = 21
    DataField = 'RICHTING_ID'
    DataSource = sasDataModule.StudierichtingDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    KeyField = 'RICHTING_ID'
    ListField = 'STUDIERICHTING'
    ListSource = sasDataModule.StudierichtingDataSourcedummy
    ParentFont = False
    TabOrder = 0
    OnClick = StudierichtingComboBoxClick
  end
  object FaculteitComboBox: TDBLookupComboBox
    Left = 160
    Top = 76
    Width = 145
    Height = 21
    DataField = 'FACULTEIT_ID'
    DataSource = sasDataModule.StudierichtingDataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    KeyField = 'FACULTEIT_ID'
    ListField = 'FACULTEIT'
    ListSource = sasDataModule.FaculteitDataSource
    ParentFont = False
    TabOrder = 1
    OnClick = FaculteitComboBoxClick
  end
  object DBLookupListBox2: TDBLookupListBox
    Left = 624
    Top = 424
    Width = 169
    Height = 160
    TabOrder = 2
  end
  object DBEdit1: TDBEdit
    Left = 344
    Top = 240
    Width = 57
    Height = 21
    DataField = 'KAMERRC'
    DataSource = sasDataModule.StudierichtingDataSource
    TabOrder = 3
  end
  object DBEdit2: TDBEdit
    Left = 344
    Top = 304
    Width = 57
    Height = 21
    TabOrder = 4
  end
  object DBEdit3: TDBEdit
    Left = 344
    Top = 272
    Width = 57
    Height = 21
    TabOrder = 5
  end
  object DBCheckBox1: TDBCheckBox
    Left = 48
    Top = 192
    Width = 97
    Height = 17
    Caption = 'Schakelen'
    TabOrder = 6
    ValueChecked = 'True'
    ValueUnchecked = 'False'
  end
  object BitBtn1: TBitBtn
    Left = 54
    Top = 376
    Width = 107
    Height = 25
    Caption = 'Curriculum'
    TabOrder = 7
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 174
    Top = 376
    Width = 107
    Height = 25
    Caption = 'Collegerooster'
    TabOrder = 8
  end
  object DBGrid1: TDBGrid
    Left = 56
    Top = 428
    Width = 545
    Height = 120
    TabOrder = 9
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'VAK_CODE'
        ReadOnly = True
        Width = 65
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'VAK_NAAM'
        ReadOnly = True
        Width = 203
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PERIODE'
        ReadOnly = True
        Width = 59
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'SOORTPERIODE'
        ReadOnly = True
        Width = 101
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'CREDITPOINTS'
        ReadOnly = True
        Width = 158
        Visible = True
      end>
  end
  object DBEdit4: TDBEdit
    Left = 424
    Top = 240
    Width = 49
    Height = 21
    DataField = 'KAMERRC'
    DataSource = sasDataModule.StudierichtingDataSource
    TabOrder = 10
  end
  object DBEdit5: TDBEdit
    Left = 424
    Top = 272
    Width = 49
    Height = 21
    TabOrder = 11
  end
  object DBEdit6: TDBEdit
    Left = 424
    Top = 304
    Width = 49
    Height = 21
    TabOrder = 12
  end
  object DBEdit7: TDBEdit
    Left = 504
    Top = 240
    Width = 49
    Height = 21
    DataField = 'TELRC'
    DataSource = sasDataModule.StudierichtingDataSource
    TabOrder = 13
  end
  object DBEdit8: TDBEdit
    Left = 504
    Top = 272
    Width = 49
    Height = 21
    TabOrder = 14
  end
  object DBEdit9: TDBEdit
    Left = 504
    Top = 304
    Width = 49
    Height = 21
    TabOrder = 15
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 168
    Top = 240
    Width = 145
    Height = 21
    TabOrder = 16
  end
  object DBLookupComboBox2: TDBLookupComboBox
    Left = 168
    Top = 272
    Width = 145
    Height = 21
    TabOrder = 17
  end
  object DBLookupComboBox3: TDBLookupComboBox
    Left = 168
    Top = 304
    Width = 145
    Height = 21
    TabOrder = 18
  end
  object DBComboBox1: TDBComboBox
    Left = 816
    Top = 136
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 19
  end
  object WordApplication1: TWordApplication
    AutoConnect = False
    ConnectKind = ckNewInstance
    Left = 1132
    Top = 248
  end
  object OpenDialog1: TOpenDialog
    Left = 1068
    Top = 248
  end
end
