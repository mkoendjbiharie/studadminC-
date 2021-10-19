object VooraanmeldingForm: TVooraanmeldingForm
  Left = 832
  Top = 458
  Width = 886
  Height = 756
  Caption = 'Vooraanmelding'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = SasPersonMenu
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 0
    Top = 0
    Width = 927
    Height = 9
    Align = alTop
    Shape = bsTopLine
  end
  object Label31: TLabel
    Left = 387
    Top = 38
    Width = 18
    Height = 13
    Caption = 'van'
  end
  object PageControl: TPageControl
    Left = 27
    Top = 114
    Width = 900
    Height = 596
    ActivePage = TabSheet1
    TabIndex = 1
    TabOrder = 0
    object PersonSheet: TTabSheet
      Caption = 'Persoon'
      object Label3: TLabel
        Left = 32
        Top = 56
        Width = 30
        Height = 14
        Caption = 'Naam'
        Font.Charset = ANSI_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label4: TLabel
        Left = 32
        Top = 237
        Width = 86
        Height = 14
        Caption = 'Gehuwde naam'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label5: TLabel
        Left = 32
        Top = 90
        Width = 57
        Height = 14
        Caption = 'Voornaam'
        Font.Charset = ANSI_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label6: TLabel
        Left = 32
        Top = 120
        Width = 103
        Height = 14
        Caption = 'Tweede voornaam'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label7: TLabel
        Left = 32
        Top = 269
        Width = 87
        Height = 14
        Caption = 'Geboortedatum'
        Color = clBtnFace
        Font.Charset = ANSI_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
      end
      object Label8: TLabel
        Left = 32
        Top = 298
        Width = 64
        Height = 14
        Caption = 'Nationaliteit'
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label9: TLabel
        Left = 32
        Top = 360
        Width = 85
        Height = 14
        Caption = 'Geboorteplaats'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label10: TLabel
        Left = 32
        Top = 397
        Width = 94
        Height = 14
        Caption = 'Bevolkingsgroep'
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label11: TLabel
        Left = 32
        Top = 426
        Width = 36
        Height = 14
        AutoSize = False
        Caption = 'Geloof'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label12: TLabel
        Left = 32
        Top = 456
        Width = 78
        Height = 14
        Caption = 'Vooropleiding'
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label13: TLabel
        Left = 488
        Top = 176
        Width = 32
        Height = 14
        Caption = 'Straat'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label14: TLabel
        Left = 488
        Top = 208
        Width = 126
        Height = 14
        Caption = 'Huisnummer of lokatie'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label15: TLabel
        Left = 488
        Top = 149
        Width = 23
        Height = 14
        Caption = 'Wijk'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label16: TLabel
        Left = 488
        Top = 237
        Width = 49
        Height = 14
        Caption = 'Telefoon'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label17: TLabel
        Left = 488
        Top = 266
        Width = 58
        Height = 14
        Caption = 'Telefoon 2'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label18: TLabel
        Left = 488
        Top = 392
        Width = 48
        Height = 14
        Caption = 'E-mail #1'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label19: TLabel
        Left = 488
        Top = 421
        Width = 48
        Height = 14
        Caption = 'E-mail #2'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label20: TLabel
        Left = 488
        Top = 450
        Width = 95
        Height = 14
        Caption = 'Bankrekening nr.'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label21: TLabel
        Left = 232
        Top = 480
        Width = 76
        Height = 14
        Caption = 'Opmerkingen'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label22: TLabel
        Left = 32
        Top = 24
        Width = 58
        Height = 14
        Caption = 'Idnummer'
        Font.Charset = ANSI_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label23: TLabel
        Left = 488
        Top = 122
        Width = 39
        Height = 14
        Caption = 'District'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label24: TLabel
        Left = 32
        Top = 328
        Width = 103
        Height = 14
        Caption = 'Land van geboorte'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label1: TLabel
        Left = 488
        Top = 480
        Width = 30
        Height = 13
        Caption = 'Bank'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label25: TLabel
        Left = 488
        Top = 88
        Width = 68
        Height = 13
        Caption = 'Woonplaats'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label26: TLabel
        Left = 32
        Top = 480
        Width = 47
        Height = 13
        Caption = 'Hobbies'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label27: TLabel
        Left = 304
        Top = 300
        Width = 71
        Height = 13
        Caption = 'JJJJ-MM-DD'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label28: TLabel
        Left = 488
        Top = 296
        Width = 82
        Height = 13
        Caption = 'Telefoon werk'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label29: TLabel
        Left = 488
        Top = 328
        Width = 47
        Height = 13
        Caption = 'Extentie'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label30: TLabel
        Left = 488
        Top = 360
        Width = 143
        Height = 13
        Caption = 'Telefoon contactpersoon'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ContactTelefoonDBEdit: TDBEdit
        Left = 656
        Top = 360
        Width = 121
        Height = 21
        DataField = 'CONTACTTELEFOON'
        DataSource = vpersonDataSource
        TabOrder = 0
      end
      object ExtentieDBEdit: TDBEdit
        Left = 656
        Top = 328
        Width = 121
        Height = 21
        DataField = 'EXTENTIE'
        DataSource = vpersonDataSource
        TabOrder = 1
      end
      object WerkTelefoonDBEdit: TDBEdit
        Left = 656
        Top = 296
        Width = 121
        Height = 21
        DataField = 'WERKTELEFOON'
        DataSource = vpersonDataSource
        TabOrder = 2
      end
      object EthnicDBLookupComboBox: TDBLookupComboBox
        Left = 152
        Top = 393
        Width = 145
        Height = 21
        DataField = 'BEV_ID'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        KeyField = 'BEV_ID'
        ListField = 'BEV_GROEP'
        ListSource = SasBasicTables.ethnicDataSource
        ParentFont = False
        TabOrder = 3
      end
      object PrevEducationDBLookupComboBox: TDBLookupComboBox
        Left = 152
        Top = 452
        Width = 145
        Height = 21
        DataField = 'OPLEIDING_ID'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        KeyField = 'OPLEIDING_ID'
        ListField = 'OPLEIDING'
        ListSource = SasBasicTables.prevEduDataSource
        ParentFont = False
        TabOrder = 4
      end
      object NameDBEdit: TDBEdit
        Left = 152
        Top = 53
        Width = 145
        Height = 21
        DataField = 'NAAM'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
      end
      object MarriedNameDBEdit: TDBEdit
        Left = 152
        Top = 234
        Width = 145
        Height = 21
        DataField = 'GEHUWDENAAM'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
      end
      object FirstNameDBEdit: TDBEdit
        Left = 152
        Top = 87
        Width = 145
        Height = 21
        DataField = 'VOORNAAM'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
      end
      object InitialsDBEdit: TDBEdit
        Left = 152
        Top = 117
        Width = 145
        Height = 21
        DataField = 'VOORNAAM2'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 8
      end
      object NumberDBEdit: TDBEdit
        Left = 656
        Top = 205
        Width = 121
        Height = 21
        DataField = 'HUISNUMMER'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 9
      end
      object Email1DBEdit: TDBEdit
        Left = 656
        Top = 389
        Width = 121
        Height = 21
        DataField = 'EMAIL1'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 10
      end
      object Email2DBEdit: TDBEdit
        Left = 656
        Top = 418
        Width = 121
        Height = 21
        DataField = 'EMAIL2'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 11
      end
      object BankAccountDBEdit: TDBEdit
        Left = 656
        Top = 447
        Width = 121
        Height = 21
        DataField = 'BANKREKENINGNR'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 12
      end
      object SexDBRadioGroup: TDBRadioGroup
        Left = 32
        Top = 152
        Width = 113
        Height = 65
        Caption = 'Geslacht'
        DataField = 'GESLACHT'
        DataSource = vpersonDataSource
        Font.Charset = ANSI_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Items.Strings = (
          'Mannelijk'
          'Vrouwelijk')
        ParentFont = False
        TabOrder = 13
        Values.Strings = (
          'm'
          'v')
        OnClick = SexDBRadioGroupClick
      end
      object MarritalStatusDBRadioGroup: TDBRadioGroup
        Left = 160
        Top = 152
        Width = 297
        Height = 65
        Caption = 'Burgelijke staat'
        Columns = 2
        DataField = 'BURGERLIJKE_STAAT'
        DataSource = vpersonDataSource
        Font.Charset = ANSI_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Items.Strings = (
          'Ongehuwd'
          'Gehuwd'
          'Gescheiden'
          'Weduwe'
          'Weduwnaar'
          'Concubinaat')
        ParentFont = False
        TabOrder = 14
        Values.Strings = (
          'ongehuwd'
          'gehuwd'
          'gescheiden'
          'weduwe'
          'weduwnaar'
          'concubinaat')
        OnClick = MarritalStatusDBRadioGroupClick
      end
      object CommentDBMemo: TDBMemo
        Left = 232
        Top = 496
        Width = 249
        Height = 57
        DataField = 'OPMERKING'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 15
      end
      object IdCardDBEdit: TDBEdit
        Left = 152
        Top = 21
        Width = 121
        Height = 21
        DataField = 'IDKAARTNR'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 16
      end
      object BirthDateDBEdit: TDBEdit
        Left = 152
        Top = 264
        Width = 65
        Height = 21
        DataField = 'GEBOORTEDATUM'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 17
      end
      object TelephoneDBEdit: TDBEdit
        Left = 656
        Top = 234
        Width = 121
        Height = 21
        DataField = 'TELEFOON1'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 18
      end
      object CellNrDBEdit: TDBEdit
        Left = 656
        Top = 263
        Width = 121
        Height = 21
        DataField = 'TELEFOON2'
        DataSource = vpersonDataSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 19
      end
      object NationalityDBLookupComboBox: TDBLookupComboBox
        Left = 152
        Top = 296
        Width = 145
        Height = 21
        DataField = 'NATIO_ID'
        DataSource = vpersonDataSource
        KeyField = 'NATIO_ID'
        ListField = 'NATIONALITEIT'
        ListSource = SasBasicTables.nationalityDataSource
        TabOrder = 20
      end
      object BirthPlaceDBEdit: TDBEdit
        Left = 152
        Top = 360
        Width = 121
        Height = 21
        DataField = 'GEBOORTEPLAATS'
        DataSource = vpersonDataSource
        TabOrder = 21
      end
      object ReligionDBEdit: TDBEdit
        Left = 152
        Top = 424
        Width = 121
        Height = 21
        DataField = 'GELOOF'
        DataSource = vpersonDataSource
        TabOrder = 22
      end
      object DistrictDBEdit: TDBEdit
        Left = 656
        Top = 120
        Width = 121
        Height = 21
        DataField = 'DISTRICT'
        DataSource = vpersonDataSource
        TabOrder = 23
      end
      object AreaDBEdit: TDBEdit
        Left = 656
        Top = 144
        Width = 121
        Height = 21
        DataField = 'WIJK'
        DataSource = vpersonDataSource
        TabOrder = 24
      end
      object StreetDBEdit: TDBEdit
        Left = 656
        Top = 176
        Width = 121
        Height = 21
        DataField = 'STRAAT'
        DataSource = vpersonDataSource
        TabOrder = 25
      end
      object CountryDBEdit: TDBEdit
        Left = 152
        Top = 328
        Width = 121
        Height = 21
        DataField = 'GEBOORTELAND'
        DataSource = vpersonDataSource
        TabOrder = 26
      end
      object WoonplaatsDBEdit: TDBEdit
        Left = 656
        Top = 88
        Width = 121
        Height = 21
        DataField = 'WOONPLAATS'
        DataSource = vpersonDataSource
        TabOrder = 27
      end
      object BankDBEdit: TDBEdit
        Left = 656
        Top = 480
        Width = 121
        Height = 21
        DataField = 'BANK'
        DataSource = vpersonDataSource
        TabOrder = 28
      end
      object HobbiesDBMemo: TDBMemo
        Left = 32
        Top = 496
        Width = 177
        Height = 57
        DataField = 'HOBBIES'
        DataSource = vpersonDataSource
        TabOrder = 29
      end
      object GridPanel: TPanel
        Left = 480
        Top = 80
        Width = 345
        Height = 353
        TabOrder = 30
        Visible = False
        object Label2: TLabel
          Left = 16
          Top = 8
          Width = 200
          Height = 13
          Caption = 'Laats ingevoerde persoonsrecords '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object LastRecordsDBGrid: TDBGrid
          Left = 16
          Top = 32
          Width = 313
          Height = 321
          DataSource = sasDataModule.GridDataSource
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
          ParentFont = False
          ReadOnly = True
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'MS Sans Serif'
          TitleFont.Style = []
          Columns = <
            item
              Expanded = False
              FieldName = 'VOLGNR'
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'IDKAARTNR'
              Title.Alignment = taCenter
              Width = 100
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'NAAM'
              Title.Alignment = taCenter
              Width = 100
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'VOORNAAM'
              Title.Alignment = taCenter
              Width = 100
              Visible = True
            end>
        end
      end
      object GridPanelButton: TButton
        Left = 480
        Top = 24
        Width = 169
        Height = 25
        Caption = 'Toon laatst ingevoerde records'
        TabOrder = 31
        OnClick = GridPanelButtonClick
      end
      object Button1: TButton
        Left = 680
        Top = 24
        Width = 75
        Height = 25
        Caption = 'Print formulier'
        TabOrder = 32
        OnClick = Button1Click
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Studie'
      ImageIndex = 1
      object NatuurkundeLabel: TLabel
        Left = 56
        Top = 56
        Width = 74
        Height = 13
        Caption = 'Natuurkunde'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object WiskundeLabel: TLabel
        Left = 56
        Top = 88
        Width = 57
        Height = 13
        Caption = 'Wiskunde'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ScheikundeLabel: TLabel
        Left = 56
        Top = 120
        Width = 68
        Height = 13
        Caption = 'Scheikunde'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object BiologieLabel: TLabel
        Left = 56
        Top = 152
        Width = 46
        Height = 13
        Caption = 'Biologie'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Studierichting1Label: TLabel
        Left = 56
        Top = 224
        Width = 86
        Height = 13
        Caption = 'Studierichting1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Studierichting2Label: TLabel
        Left = 56
        Top = 256
        Width = 86
        Height = 13
        Caption = 'Studierichting2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object FaculteitLabel: TLabel
        Left = 56
        Top = 191
        Width = 50
        Height = 13
        Caption = 'Faculteit'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
      end
      object StudieMemoLabel: TLabel
        Left = 64
        Top = 293
        Width = 75
        Height = 13
        Caption = 'Opmerkingen'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object NatuurkundeDBEdit: TDBEdit
        Left = 232
        Top = 56
        Width = 121
        Height = 21
        DataField = 'NATUURKUNDE'
        DataSource = vinschrijvingDataSource
        TabOrder = 0
      end
      object WiskundeDBEdit: TDBEdit
        Left = 232
        Top = 88
        Width = 121
        Height = 21
        DataField = 'WISKUNDE'
        DataSource = vinschrijvingDataSource
        TabOrder = 1
      end
      object ScheikundeDBEdit: TDBEdit
        Left = 232
        Top = 120
        Width = 121
        Height = 21
        DataField = 'SCHEIKUNDE'
        DataSource = vinschrijvingDataSource
        TabOrder = 2
      end
      object BiologieDBEdit: TDBEdit
        Left = 232
        Top = 152
        Width = 121
        Height = 21
        DataField = 'BIOLOGIE'
        DataSource = vinschrijvingDataSource
        TabOrder = 3
      end
      object Studierichting1DBLookupComboBox: TDBLookupComboBox
        Left = 232
        Top = 216
        Width = 145
        Height = 21
        DataField = 'STUDIERICHTING1_ID'
        DataSource = vinschrijvingDataSource
        KeyField = 'RICHTING_ID'
        ListField = 'STUDIERICHTING'
        ListSource = sasDataModule.StudierichtingDataSource
        TabOrder = 4
      end
      object Studierichting2DBLookupComboBox: TDBLookupComboBox
        Left = 232
        Top = 248
        Width = 145
        Height = 21
        DataField = 'STUDIERICHTING2_ID'
        DataSource = vinschrijvingDataSource
        KeyField = 'RICHTING_ID'
        ListField = 'STUDIERICHTING'
        ListSource = sasDataModule.StudierichtingDataSource
        TabOrder = 5
      end
      object FaculteitDBLookupComboBox: TDBLookupComboBox
        Left = 232
        Top = 187
        Width = 145
        Height = 21
        DataField = 'FACULTEIT_ID'
        DataSource = vinschrijvingDataSource
        KeyField = 'FACULTEIT_ID'
        ListField = 'FACULTEIT'
        ListSource = sasDataModule.FaculteitDataSource
        TabOrder = 6
        OnClick = FaculteitDBLookupComboBoxClick
      end
      object ExtraPanel: TPanel
        Left = 448
        Top = 199
        Width = 297
        Height = 233
        BevelOuter = bvNone
        TabOrder = 7
        Visible = False
        object Label32: TLabel
          Left = 8
          Top = 120
          Width = 65
          Height = 14
          Caption = 'Referenties'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label33: TLabel
          Left = 16
          Top = 152
          Width = 7
          Height = 16
          Caption = '1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label34: TLabel
          Left = 16
          Top = 176
          Width = 7
          Height = 16
          Caption = '2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label35: TLabel
          Left = 16
          Top = 200
          Width = 7
          Height = 16
          Caption = '3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object DBEdit1: TDBEdit
          Left = 40
          Top = 152
          Width = 241
          Height = 21
          DataField = 'REFERENTIE1'
          DataSource = sasDataModule.InschrijvingDataSource
          TabOrder = 0
        end
        object DBEdit2: TDBEdit
          Left = 40
          Top = 176
          Width = 241
          Height = 21
          DataField = 'REFERENTIE2'
          DataSource = sasDataModule.InschrijvingDataSource
          TabOrder = 1
        end
        object DBEdit3: TDBEdit
          Left = 40
          Top = 200
          Width = 241
          Height = 21
          DataField = 'REFERENTIE3'
          DataSource = sasDataModule.InschrijvingDataSource
          TabOrder = 2
        end
        object GroupBox1: TGroupBox
          Left = 40
          Top = 8
          Width = 249
          Height = 105
          Caption = ' Vooropleiding '
          TabOrder = 3
          object Label36: TLabel
            Left = 24
            Top = 48
            Width = 47
            Height = 13
            Caption = 'Instituut'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label37: TLabel
            Left = 24
            Top = 24
            Width = 35
            Height = 13
            Caption = 'Graad'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label38: TLabel
            Left = 24
            Top = 72
            Width = 48
            Height = 13
            Caption = 'Richting'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object InstituutDBEdit: TDBEdit
            Left = 96
            Top = 40
            Width = 145
            Height = 21
            DataField = 'VOORINSTITUUT'
            DataSource = sasDataModule.InschrijvingDataSource
            TabOrder = 0
          end
          object RichtingDBEdit: TDBEdit
            Left = 96
            Top = 64
            Width = 145
            Height = 21
            DataField = 'VOORRICHTING'
            DataSource = sasDataModule.InschrijvingDataSource
            TabOrder = 1
          end
          object GraadComboBox: TDBLookupComboBox
            Left = 96
            Top = 16
            Width = 145
            Height = 21
            DataField = 'VOORGRAAD'
            DataSource = sasDataModule.InschrijvingDataSource
            KeyField = 'GRAAD_ID'
            ListField = 'GRAAD'
            TabOrder = 2
          end
        end
      end
      object StudieDBMemo: TDBMemo
        Left = 56
        Top = 309
        Width = 289
        Height = 57
        DataField = 'MEMO'
        DataSource = sasDataModule.InschrijvingDataSource
        ReadOnly = True
        TabOrder = 8
      end
    end
  end
  object ModusKnop: TBitBtn
    Left = 32
    Top = 40
    Width = 193
    Height = 41
    Caption = 'Lezen'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = ModusKnopClick
    Glyph.Data = {
      360C0000424D360C000000000000360000002800000020000000200000000100
      180000000000000C000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFF0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFF00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFF000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFF000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFF00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFF0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000}
    Layout = blGlyphRight
  end
  object DBNavigator1: TDBNavigator
    Left = 288
    Top = 8
    Width = 216
    Height = 25
    DataSource = vpersonDataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    TabOrder = 2
    OnClick = DBNavigator1Click
  end
  object NieuwButton: TButton
    Left = 288
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Nieuw '
    TabOrder = 3
    OnClick = NieuwButtonClick
  end
  object OpslaanButton: TButton
    Left = 360
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Opslaan'
    TabOrder = 4
    OnClick = OpslaanButtonClick
  end
  object VerwijderButton: TButton
    Left = 432
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Verwijder'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = VerwijderButtonClick
  end
  object first: TEdit
    Left = 288
    Top = 32
    Width = 57
    Height = 21
    Enabled = False
    TabOrder = 6
    Text = 'first'
  end
  object last: TEdit
    Left = 448
    Top = 32
    Width = 57
    Height = 21
    Enabled = False
    TabOrder = 7
    Text = 'last'
  end
  object InschrijfButton: TBitBtn
    Left = 504
    Top = 56
    Width = 113
    Height = 25
    Caption = 'Inschrijven'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
    OnClick = InschrijfButtonClick
  end
  object SearchEdit: TEdit
    Left = 32
    Top = 88
    Width = 121
    Height = 21
    TabOrder = 9
  end
  object SearchButton: TButton
    Left = 152
    Top = 86
    Width = 49
    Height = 25
    Caption = 'Zoek '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = SearchButtonClick
  end
  object ToggleButton: TBitBtn
    Left = 200
    Top = 86
    Width = 105
    Height = 25
    Caption = 'op idnummer'
    Default = True
    ModalResult = 1
    TabOrder = 11
    OnClick = ToggleButtonClick
    Glyph.Data = {
      7A000000424D7A000000000000003E000000280000000F0000000F0000000100
      0100000000003C0000000000000000000000020000000000000000000000FFFF
      FF000000000080000000E0000000F8000000FE000000FF800000FFE00000FFF8
      0000FFE00000FF800000FE000000F8000000E00000008000000000000000}
    Layout = blGlyphRight
  end
  object SasPersonMenu: TMainMenu
    Left = 808
    Top = 536
    object Bestand1: TMenuItem
      Caption = '&Bestand'
      object Close1: TMenuItem
        Caption = '&Close'
        OnClick = Close1Click
      end
      object Exit1: TMenuItem
        Caption = 'E&xit'
        OnClick = Exit1Click
      end
    end
  end
  object vpersonSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from  vpersoon'
    Params = <>
    Left = 544
    Top = 192
  end
  object vpersonDataSetProvider: TDataSetProvider
    DataSet = vpersonSQLDataSet
    Constraints = True
    Left = 600
    Top = 192
  end
  object vpersonClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'vpersonDataSetProvider'
    Left = 648
    Top = 192
  end
  object vpersonDataSource: TDataSource
    DataSet = vpersonClientDataSet
    Left = 704
    Top = 192
  end
  object vinschrijvingSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from  vinschrijving'
    Params = <>
    Left = 544
    Top = 232
  end
  object vschakelSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from vschakel'
    Params = <>
    Left = 544
    Top = 280
  end
  object vinschrijvingDataSetProvider: TDataSetProvider
    DataSet = vinschrijvingSQLDataSet
    Constraints = True
    Left = 600
    Top = 232
  end
  object vschakelDataSetProvider: TDataSetProvider
    DataSet = vschakelSQLDataSet
    Constraints = True
    Left = 600
    Top = 280
  end
  object vinschrijvingClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'vinschrijvingDataSetProvider'
    Left = 648
    Top = 232
  end
  object vschakelClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'vschakelDataSetProvider'
    Left = 648
    Top = 280
  end
  object vinschrijvingDataSource: TDataSource
    DataSet = vinschrijvingClientDataSet
    Left = 704
    Top = 229
  end
  object vschakelDataSource: TDataSource
    DataSet = vschakelClientDataSet
    Left = 704
    Top = 280
  end
end
