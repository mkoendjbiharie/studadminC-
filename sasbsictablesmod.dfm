object SasBasicTables: TSasBasicTables
  OldCreateOrder = False
  Left = 492
  Top = 188
  Height = 638
  Width = 778
  object ethnicSQLDataSet: TSQLDataSet
    CommandText = 'select * from bevolkingsgroep'
    MaxBlobSize = 0
    Params = <>
    Left = 43
    Top = 9
  end
  object ethnicDataSetProvider: TDataSetProvider
    DataSet = ethnicSQLDataSet
    Constraints = True
    UpdateMode = upWhereKeyOnly
    Left = 43
    Top = 57
  end
  object ethnicClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'ethnicDataSetProvider'
    Left = 491
    Top = 105
  end
  object ethnicDataSource: TDataSource
    DataSet = ethnicClientDataSet
    Left = 43
    Top = 169
  end
  object prevEduSQLDataSet: TSQLDataSet
    CommandText = 'select * from opleiding'
    MaxBlobSize = 0
    Params = <>
    Left = 211
    Top = 9
  end
  object prevEduDataSource: TDataSource
    DataSet = prevEduClientDataSet
    Left = 211
    Top = 153
  end
  object prevEduClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'prevEduDataSetProvider'
    Left = 211
    Top = 105
  end
  object prevEduDataSetProvider: TDataSetProvider
    DataSet = prevEduSQLDataSet
    Constraints = True
    UpdateMode = upWhereKeyOnly
    Left = 211
    Top = 57
  end
  object nationalityDataSource: TDataSource
    DataSet = nationalityClientDataSet
    Left = 347
    Top = 153
  end
  object nationalityClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'nationalityDataSetProvider'
    Left = 347
    Top = 105
  end
  object nationalityDataSetProvider: TDataSetProvider
    DataSet = nationalitySQLDataSet
    Constraints = True
    UpdateMode = upWhereKeyOnly
    Left = 347
    Top = 57
  end
  object nationalitySQLDataSet: TSQLDataSet
    CommandText = 'select * from nationaliteit'
    MaxBlobSize = 0
    Params = <>
    Left = 347
    Top = 9
  end
  object religionSQLDataSet: TSQLDataSet
    CommandText = 'select * from geloof'
    MaxBlobSize = 0
    Params = <>
    Left = 483
    Top = 9
  end
  object religionDataSetProvider: TDataSetProvider
    DataSet = religionSQLDataSet
    Constraints = True
    Left = 491
    Top = 57
  end
  object religionClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'religionDataSetProvider'
    Left = 51
    Top = 113
  end
  object religionDataSource: TDataSource
    DataSet = religionClientDataSet
    Left = 499
    Top = 169
  end
  object SysteemSQLDataSet: TSQLDataSet
    CommandText = 'SELECT *  FROM systeem'
    MaxBlobSize = 0
    Params = <>
    Left = 552
    Top = 256
  end
  object SysteemDataSetProvider: TDataSetProvider
    DataSet = SysteemSQLDataSet
    Constraints = True
    Left = 552
    Top = 304
  end
  object SysteemClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'SysteemDataSetProvider'
    Left = 552
    Top = 360
  end
  object SysteemDataSource: TDataSource
    DataSet = SysteemClientDataSet
    Left = 544
    Top = 408
  end
  object eduDataSource: TDataSource
    DataSet = eduClientDataSet
    Left = 635
    Top = 161
  end
  object eduClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'eduDataSetProvider'
    Left = 635
    Top = 113
  end
  object eduDataSetProvider: TDataSetProvider
    DataSet = eduSQLDataSet
    Constraints = True
    UpdateMode = upWhereKeyOnly
    Left = 635
    Top = 65
  end
  object eduSQLDataSet: TSQLDataSet
    CommandText = 'select * from opleiding'
    MaxBlobSize = 0
    Params = <>
    Left = 635
    Top = 17
  end
  object placeSQLDataSet: TSQLDataSet
    CommandText = 'select * from plaats'
    MaxBlobSize = 0
    Params = <>
    Left = 427
    Top = 257
  end
  object placeDataSetProvider: TDataSetProvider
    DataSet = placeSQLDataSet
    Constraints = True
    Left = 427
    Top = 305
  end
  object placeClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'placeDataSetProvider'
    Left = 427
    Top = 353
  end
  object placeDataSource: TDataSource
    DataSet = placeClientDataSet
    Left = 427
    Top = 401
  end
  object streetSQLDataSet: TSQLDataSet
    CommandText = 'select * from straat'
    MaxBlobSize = 0
    Params = <>
    Left = 35
    Top = 249
  end
  object streetDataSetProvider: TDataSetProvider
    DataSet = streetSQLDataSet
    Constraints = True
    Left = 35
    Top = 297
  end
  object streetClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'streetDataSetProvider'
    Left = 35
    Top = 345
  end
  object streetDataSource: TDataSource
    DataSet = streetClientDataSet
    Left = 35
    Top = 393
  end
  object areaSQLDataSet: TSQLDataSet
    CommandText = 'select * from wijk'
    MaxBlobSize = 0
    Params = <>
    Left = 155
    Top = 249
  end
  object areaDataSetProvider: TDataSetProvider
    DataSet = areaSQLDataSet
    Constraints = True
    Left = 155
    Top = 297
  end
  object areaClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'areaDataSetProvider'
    Left = 155
    Top = 345
  end
  object areaDataSource: TDataSource
    DataSet = areaClientDataSet
    Left = 155
    Top = 393
  end
  object districtSQLDataSet: TSQLDataSet
    CommandText = 'select * from district'
    MaxBlobSize = 0
    Params = <>
    Left = 275
    Top = 252
  end
  object districtDataSetProvider: TDataSetProvider
    DataSet = districtSQLDataSet
    Constraints = True
    Left = 275
    Top = 297
  end
  object districtClientDataSet: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'districtDataSetProvider'
    Left = 275
    Top = 345
  end
  object districtDataSource: TDataSource
    DataSet = districtClientDataSet
    Left = 275
    Top = 393
  end
end
