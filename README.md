# DeLorean_Team
Source project automotive BASECAMP


## Build
```
cd build
cmake ../
make
```

## Run
``` 
./main
```

## Before commit   

### Make sure your code matches the Google C++ Style Guide.  
For automatic format of all code you can use command: 
```
find src/ -iname *.hpp -o -iname *.cpp | xargs clang-format -i -style=Google
```

or for one file 
```
clang-format -i -style=Google src/main.cpp
```
(Warning, will modify code in place without any notice)

### Check that tests passed 
```
cd build
cmake ../
make
./tests
```
| Document | Description |
|----|----|
| [Ы](./doc/dlt_build_options.md) | The CMake build system provides a large amount of build options. They let you turn on or off certain features and provide alternative implementation details. |
| [LogStorage](doc/dlt_offline_logstorage.md) | The DLT Daemon as well as the DLT libary provide buffers for caching log data during absence of a consumer. However, some use cases require to write large amounts of log message e.g. to mass storages for long term storage or because no other means of exfiltrating the log data is available. |