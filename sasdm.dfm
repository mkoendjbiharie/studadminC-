object sasDataModule: TsasDataModule
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Left = 153
  Height = 747
  Width = 1127
  object sasSQLConnection: TSQLConnection
    Connected = True
    ConnectionName = 'MySQLConnection'
    DriverName = 'MySQL'
    GetDriverFunc = 'getSQLDriverMYSQL'
    LibraryName = 'dbexpmysql.dll'
    LoginPrompt = False
    Params.Strings = (
      'DriverName=MySQL'
      'HostName=localhost'
      'Database=sastest'
      'User_Name=sasdba'
      'Password=xs4sasdba'
      'BlobSize=-1'
      'ErrorResourceFile='
      'LocaleCode=0000')
    VendorLib = 'libmysql.dll'
    Left = 42
    Top = 25
  end
  object personDataSetProvider: TDataSetProvider
    DataSet = personSQLDataSet
    Constraints = True
    Options = [poAllowCommandText]
    Left = 307
    Top = 105
  end
  object personClientDataSet: TClientDataSet
    Aggregates = <>
    Filtered = True
    FieldDefs = <
      item
        Name = 'GESLACHT'
        Attributes = [faRequired, faFixed]
        DataType = ftString
        Size = 1
      end
      item
        Name = 'NAAM'
        Attributes = [faRequired]
        DataType = ftString
        Size = 50
      end
      item
        Name = 'GEHUWDENAAM'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'VOORNAAM'
        Attributes = [faRequired]
        DataType = ftString
        Size = 50
      end
      item
        Name = 'VOORNAAM2'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'BURGERLIJKE_STAAT'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'FOTO'
        DataType = ftBlob
        Size = 1
      end
      item
        Name = 'OPMERKING'
        DataType = ftMemo
        Size = 1
      end
      item
        Name = 'GEBOORTELAND'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'GEBOORTEPLAATS'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'BANK'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'DISTRICT'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'GELOOF'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'STRAAT'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'HUISNUMMER'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'EMAIL1'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'EMAIL2'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'BANKREKENINGNR'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'TELEFOON2'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'TELEFOON1'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'WOONPLAATS'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'WIJK'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'OPLEIDING_ID'
        DataType = ftInteger
      end
      item
        Name = 'NATIO_ID'
        DataType = ftInteger
      end
      item
        Name = 'BEV_ID'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'GEBOORTEDATUM'
        DataType = ftDate
      end
      item
        Name = 'HOBBIES'
        DataType = ftMemo
        Size = 1
      end
      item
        Name = 'IDKAARTNR'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'VOLGNR'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'WERKTELEFOON'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'EXTENTIE'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'CONTACTTELEFOON'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'VOORGRAAD'
        DataType = ftInteger
      end
      item
        Name = 'VOORINSTITUUT'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'VOORRICHTING'
        DataType = ftString
        Size = 50
      end>
    IndexDefs = <>
    Params = <>
    ProviderName = 'personDataSetProvider'
    StoreDefs = True
    Left = 307
    Top = 177
  end
  object personDataSource: TDataSource
    DataSet = personClientDataSet
    Left = 315
    Top = 233
  end
  object personSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 'select * from persoon'
    Params = <>
    Left = 307
    Top = 73
  end
  object SchakelSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 'select * from schakel'
    Params = <>
    Left = 98
    Top = 594
  end
  object SchakelDataSetProvider: TDataSetProvider
    DataSet = SchakelSQLDataSet
    Constraints = True
    Left = 98
    Top = 642
  end
  object SchakelClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'SchakelDataSetProvider'
    Left = 98
    Top = 690
  end
  object SchakelDataSource: TDataSource
    DataSet = SchakelClientDataSet
    Left = 98
    Top = 738
  end
  object GridSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 'select * from persoon'
    Params = <>
    Left = 437
    Top = 73
  end
  object GridDataSetProvider: TDataSetProvider
    DataSet = GridSQLDataSet
    Constraints = True
    Left = 438
    Top = 121
  end
  object GridClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'GridDataSetProvider'
    Left = 438
    Top = 177
  end
  object GridDataSource: TDataSource
    DataSet = GridClientDataSet
    Left = 438
    Top = 217
  end
  object FaculteitSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 'select * from faculteit'
    Params = <>
    Left = 256
    Top = 337
  end
  object FaculteitDataSetProvider: TDataSetProvider
    DataSet = FaculteitSQLDataSet
    Constraints = True
    Left = 256
    Top = 382
  end
  object FaculteitClientDataSet: TClientDataSet
    Active = True
    Aggregates = <>
    Params = <>
    ProviderName = 'FaculteitDataSetProvider'
    Left = 256
    Top = 429
  end
  object FaculteitDataSource: TDataSource
    DataSet = FaculteitClientDataSet
    Left = 256
    Top = 476
  end
  object StudierichtingSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 
      'select studierichting.*, faculteit.faculteit, vak.vak_id , docen' +
      'tvak.docent_id from studierichting join faculteit on faculteit.F' +
      'ACULTEIT_ID = studierichting.FACULTEIT_ID join vak on vak.richti' +
      'ng_id = studierichting.richting_id join docentvak on vak.vak_id ' +
      '= docentvak.vak_id'
    Params = <>
    Left = 400
    Top = 335
  end
  object StudierichtingDataSetProvider: TDataSetProvider
    DataSet = StudierichtingSQLDataSet
    Constraints = True
    Left = 400
    Top = 379
  end
  object StudierichtingClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'StudierichtingDataSetProvider'
    Left = 400
    Top = 429
  end
  object StudierichtingDataSource: TDataSource
    DataSet = StudierichtingClientDataSet
    Left = 408
    Top = 485
  end
  object InschrijvingSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 'select * from inschrijving where idkaartnr = "00000000"'
    Params = <>
    Left = 88
    Top = 331
  end
  object InschrijvingDataSetProvider: TDataSetProvider
    DataSet = InschrijvingSQLDataSet
    Constraints = True
    Left = 88
    Top = 390
  end
  object InschrijvingClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'InschrijvingDataSetProvider'
    Left = 80
    Top = 440
  end
  object InschrijvingDataSource: TDataSource
    DataSet = InschrijvingClientDataSet
    Left = 80
    Top = 496
  end
  object GridSQLDataSet1: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 'select * from inschrijving'
    Params = <>
    Left = 560
    Top = 72
  end
  object GridDataSetProvider1: TDataSetProvider
    DataSet = GridSQLDataSet1
    Constraints = True
    Left = 560
    Top = 120
  end
  object GridClientDataSet1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'GridDataSetProvider1'
    Left = 560
    Top = 168
  end
  object GridDataSource1: TDataSource
    DataSet = GridClientDataSet1
    Left = 560
    Top = 216
  end
  object SchakelGridSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 'select * from schakel'
    Params = <>
    Left = 737
    Top = 352
  end
  object SchakelGridDataSetProvider: TDataSetProvider
    DataSet = SchakelGridSQLDataSet
    Constraints = True
    Left = 751
    Top = 400
  end
  object SchakelGridClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'SchakelGridDataSetProvider'
    Left = 753
    Top = 464
  end
  object SchakelGridDataSource: TDataSource
    DataSet = SchakelGridClientDataSet
    Left = 777
    Top = 512
  end
  object EerdereInschrijvingenSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 'select  * from inschrijving'
    Params = <>
    Left = 576
    Top = 344
  end
  object EerdereInschrijvingenDataSetProvider: TDataSetProvider
    DataSet = EerdereInschrijvingenSQLDataSet
    Constraints = True
    Left = 585
    Top = 400
  end
  object EerdereInschrijvingenClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'EerdereInschrijvingenDataSetProvider'
    Left = 587
    Top = 440
  end
  object EerdereInschrijvingenDataSource: TDataSource
    DataSet = EerdereInschrijvingenClientDataSet
    Left = 592
    Top = 496
  end
  object MaxNummersSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 'select * from maxnummers'
    Params = <>
    Left = 707
    Top = 32
  end
  object MaxNummersDataSetProvider: TDataSetProvider
    DataSet = MaxNummersSQLDataSet
    Constraints = True
    Left = 712
    Top = 88
  end
  object MaxNummersClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'MaxNummersDataSetProvider'
    Left = 727
    Top = 160
  end
  object MaxNummersDataSource: TDataSource
    DataSet = MaxNummersClientDataSet
    Left = 728
    Top = 232
  end
  object kleurcollegekaartSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    Params = <>
    Left = 800
    Top = 65435
  end
  object kleurcollegekaartDataSetProvider: TDataSetProvider
    DataSet = kleurcollegekaartSQLDataSet
    Constraints = True
    Left = 398
    Top = 556
  end
  object kleurcollegekaartClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'kleurcollegekaartDataSetProvider'
    Left = 398
    Top = 675
  end
  object DataSource1: TDataSource
    Left = 1096
    Top = 293
  end
  object kleurcollegekaartDataSource: TDataSource
    DataSet = kleurcollegekaartClientDataSet
    Left = 398
    Top = 728
  end
  object studentenkaartSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 
      'SELECT persoon.*,  inschrijving.* from persoon  INNER JOIN insch' +
      'rijving  on persoon.IDKAARTNR = inschrijving.IDKAARTNR '
    Params = <>
    Left = 110
    Top = 88
  end
  object studentenkaartDataSetProvider: TDataSetProvider
    DataSet = studentenkaartSQLDataSet
    Constraints = True
    Left = 120
    Top = 137
  end
  object studentenkaartClientDataSet: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'GESLACHT'
        Attributes = [faRequired, faFixed]
        DataType = ftString
        Size = 1
      end
      item
        Name = 'NAAM'
        Attributes = [faRequired]
        DataType = ftString
        Size = 50
      end
      item
        Name = 'GEHUWDENAAM'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'VOORNAAM'
        Attributes = [faRequired]
        DataType = ftString
        Size = 50
      end
      item
        Name = 'VOORNAAM2'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'BURGERLIJKE_STAAT'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'FOTO'
        DataType = ftBlob
        Size = 1
      end
      item
        Name = 'OPMERKING'
        DataType = ftMemo
        Size = 1
      end
      item
        Name = 'GEBOORTELAND'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'GEBOORTEPLAATS'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'BANK'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'DISTRICT'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'GELOOF'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'STRAAT'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'HUISNUMMER'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'EMAIL1'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'EMAIL2'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'BANKREKENINGNR'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'TELEFOON2'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'TELEFOON1'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'WOONPLAATS'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'WIJK'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'OPLEIDING_ID'
        DataType = ftInteger
      end
      item
        Name = 'NATIO_ID'
        DataType = ftInteger
      end
      item
        Name = 'BEV_ID'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'GEBOORTEDATUM'
        DataType = ftDate
      end
      item
        Name = 'HOBBIES'
        DataType = ftMemo
        Size = 1
      end
      item
        Name = 'IDKAARTNR'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'VOLGNR'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'WERKTELEFOON'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'EXTENTIE'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'CONTACTTELEFOON'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'FACULTEIT_ID'
        DataType = ftInteger
      end
      item
        Name = 'REDEN'
        DataType = ftMemo
        Size = 1
      end
      item
        Name = 'VERLENGING'
        DataType = ftInteger
      end
      item
        Name = 'MEMO'
        DataType = ftMemo
        Size = 1
      end
      item
        Name = 'IDKAARTNR_1'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'INSCHRIJFJAAR'
        DataType = ftInteger
      end
      item
        Name = 'AFSTUDEERDATUM'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'AFSCHRIJVINGSDATUM'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'SYSTEEM_ID'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'STUDIERICHTING_ID'
        Attributes = [faFixed]
        DataType = ftString
        Size = 3
      end
      item
        Name = 'VOLGNR_1'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'STUDIENR'
        Attributes = [faRequired]
        DataType = ftString
        Size = 10
      end
      item
        Name = 'SOORTOPLEIDING'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'ORIENTATIE'
        DataType = ftString
        Size = 10
      end>
    IndexDefs = <>
    Params = <>
    ProviderName = 'studentenkaartDataSetProvider'
    ReadOnly = True
    StoreDefs = True
    Left = 120
    Top = 181
  end
  object studentenkaartDataSource: TDataSource
    DataSet = studentenkaartClientDataSet
    Left = 120
    Top = 228
  end
  object diplomaSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 'select * from certificaat'
    Params = <>
    Left = 947
    Top = 446
  end
  object diplomaDataSetProvider: TDataSetProvider
    DataSet = diplomaSQLDataSet
    Constraints = True
    Left = 938
    Top = 510
  end
  object diplomaClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'diplomaDataSetProvider'
    Left = 946
    Top = 566
  end
  object diplomaDataSource: TDataSource
    DataSet = diplomaClientDataSet
    Left = 974
    Top = 639
  end
  object GebruikersgroepSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    Params = <>
    Left = 880
    Top = 24
  end
  object GebruikersgroepDataSetProvider: TDataSetProvider
    DataSet = GebruikersgroepSQLDataSet
    Constraints = True
    Left = 896
    Top = 96
  end
  object GebruikersgroepClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'GebruikersgroepDataSetProvider'
    ReadOnly = True
    Left = 912
    Top = 176
  end
  object GebruikersgroepDataSource: TDataSource
    DataSet = GebruikersgroepClientDataSet
    Left = 912
    Top = 240
  end
  object DataSource2: TDataSource
    Left = 1168
    Top = 160
  end
  object OrientatieSQLDataSet: TSQLDataSet
    SQLConnection = sasSQLConnection
    CommandText = 'select * from  orientatie'
    Params = <>
    Left = 584
    Top = 568
  end
  object OrientatieDataSetProvider: TDataSetProvider
    DataSet = OrientatieSQLDataSet
    Constraints = True
    Left = 592
    Top = 632
  end
  object OrientatieClientDataSet: TClientDataSet
    Active = True
    Aggregates = <>
    Params = <>
    ProviderName = 'OrientatieDataSetProvider'
    Left = 592
    Top = 704
  end
  object OrientatieDataSource: TDataSource
    DataSet = OrientatieClientDataSet
    Left = 664
    Top = 688
  end
  object StudierichtingDataSourcedummy: TDataSource
    DataSet = StudierichtingClientDataSetdummy
    Left = 264
    Top = 544
  end
  object StudierichtingClientDataSetdummy: TClientDataSet
    Active = True
    Aggregates = <>
    Params = <>
    ProviderName = 'StudierichtingDataSetProvider'
    Left = 328
    Top = 520
  end
end
