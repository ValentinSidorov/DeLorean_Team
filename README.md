# DeLorean_Team
## Description of the project documentation 

| Document | Description |
|----|----|
| [task](docs/task.md) | Setting a task for a project.|
| [types](./docs/types.md) | Description of the structure of the yml file parser. |
| [yaml_parser](docs/yaml_parser.md) | Description of the yml file parser procedure.|
| [process_start](docs/process_start.md) | Description of running processes.|
| [logger](docs/logger.md) | Description of the message logging function.|
| [main](docs/main.md) | Description of the main function.|
| [integration_test](docs/integration_test.md) | Description of the methodology for conducting integration tests.|
| [unit_test](docs/unit_test.md) | Description of the methodology for conducting unit tests.|
| [gcov_test](docs/gcov_test.md) | Description of the gcov tests.|
| [recommend](docs/recommend.md) | Recommendations for the future development of the project.|

---
Source project automotive BASECAMP

## Build and run
```
cd build
cmake ../
make
./main ../tests/example.yml
```

## Before commit   

### Check that your branch updated with main 
```
git checkout main
git pull
git checkout validator
git merge main
git push
```

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

