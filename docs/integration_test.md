# integration test
Back to [README.md](../README.md)

## Test program:
For testsing execution manager was created testing program: test_prog.

If you just run ./test_prog, there will be the output of "Hello world" in console window, 

creatiion of txt file with writing down  "Hello world" into it and exit.





If you enter ./test_prog --text="some text", 
                                          the result will be the output "some text" to stdout and into file and exit;    

If you enter --text1="some words" --text2="something else" 
                                           the result will be the output "some words" and "something else" to stdout and file and exit;   

If you enter --text="some other text" --loop 
                                             the result will be the output "some other text" in an endless loop to stdout and file with an interval of 5 seconds 
  
## Robot test framework

Firstly need to install robot framework.

`pip3 install robotframework`

than check installation

`robot --version`

To run tests:

```
cd tests/integration/
robot test.robot
```

You will receive output in console and in  report.html files 