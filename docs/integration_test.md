# integration_test
Back to [README.md](../README.md)
```
#include "yaml_parse.h"
```


## Description:

Now if you just run ./test_prog, there will be the output of "Hello world" 10 times in console window, 
creatiion of txt file with writing down  "Hello world" 10 times into it and exit.

If you run ./test_prog and enter 4 arguments separated by a space 
(one should put the arguments inside which there are spaces in quotes)
which will be passed through argv and wull be displayed to the console and to a file according to the scenario: 


--text='some text' Output "some text" to stdout 10 times and into file and exit;    
--text='text1' --other-text='text2' Output "text1 text2" 10 times to stdout and file and exit;   
--text='some other text' -loop Output "some other text" in an endless loop to stdout and file with an interval of 5 seconds 
  with the lemitation of 5 iterations to ensure correct closure of the file

## Syntax:


## Parameters:


## Returns:


## Example Code:
