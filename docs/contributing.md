# Welcome to contributing guide  
Back to [README.md](../README.md)

For contribute to repo:

1) Create branch for your feature from ```main```  branch or  [update your  existing branch](#Update-your-branch)

2) Code :)

3) Cover your change with gooletest 

3) [Check that build run successful](#build-and-run) 

4) [That unit tests pass](#check-that-unit-tests-passed)

5) [Check code coverage](#create-code-coverage-report)

6) [Check that integration tests pass](#integration-tests)

7) [Check cppcheck report](#be-sure-your-code-passed-cppcheck-without-warnings)

8) [Check that your code styled matches google-stylee](#make-sure-your-code-matches-the-google-c-style-guide)

9) Create pull request from your branch to `main`

10) [Check `GitHub` action result](#github-actions)



## Update your branch
```
git checkout Logger
git merge origin/main
git push
```

## Build and run

```
cd build
cmake ../
make
./main ../tests/example.yml
```

### Check that unit tests passed 
```
cd build
cmake ../
make
./tests
```
[more info](../docs/unit_test.md)

## Create code coverage report
<b> Firstly, you need to install gcovr:</b>
```
sudo apt-get install gcovr
```
<b>Create a report:  </b>
```
cd build
make code_coverage
cd ../tests/code_coverage/report
```
[more info](../docs/unit_test.md)


## Integration tests

```
cd tests/integraion
robot test.robot
```
[more info](../docs/integration_test.md)

### Be sure your code passed cppcheck without warnings 
```
cppcheck --enable=all --inconclusive -i./build --std=c++14 main.cpp --suppress=missingIncludeSystem  -I include/ ./
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

### Github actions

In our project configured system that checks some steps in automatic mode on commit or pull request to `main` branch. 

In pull request open:
![image](https://user-images.githubusercontent.com/9269521/155344294-cd9461bd-b11d-491e-a41e-1f84fadcf90a.png)

![image](https://user-images.githubusercontent.com/9269521/155344406-1409738f-ba77-49bf-ae32-3b0bc70b8ad3.png)

Need to check that all this test passed (must be gray, not red):

- Build: checks that project can be built
- Tests: check that unit tests passed
- cppcheck - report: check that code has not warnings   
- Clang-format - report: check that code matches google-stylee

If someone of this check failed, need convert pull request to draft and fix errors.
