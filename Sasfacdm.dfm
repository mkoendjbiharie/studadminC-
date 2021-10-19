object SasFaculteitData: TSasFaculteitData
  OldCreateOrder = False
  Left = 465
  Height = 248
  Width = 798
  object vakSQLDataSet: TSQLDataSet
    SQLConnection = sasDataModule.sasSQLConnection
    CommandText = 'select * from vak'
    Params = <>
    Left = 40
    Top = 8
  end
  object vakDataSetProvider: TDataSetProvider
    DataSet = vakSQLDataSet
    Constraints = True
    Left = 48
    Top = 64
  end
  object vakClientDataSet: TClientDataSet
    Aggregates = <>
    Filtered = True
    FilterOptions = [foCaseInsensitive]
    Params = <>
    ProviderName = 'vakDataSetProvider'
    Left = 40
    Top = 128
  end
  object vakDataSource: TDataSource
    DataSet = vakClientDataSet
    OnUpdateData = vakDataSourceUpdateData
    Left = 40
    Top = 176
  end
end
