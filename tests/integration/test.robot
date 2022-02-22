*** Settings ***
Library           Process 
Library           OperatingSystem
Library           String
Test Teardown     Remove Files    custom.log    test_prog1_out.txt    test_prog2_out.txt    filename1.txt    filename2.txt    filename3.txt
Suite Teardown    Terminate All Processes    kill=True


*** Test Cases ***
One app
    Start Process     ../../build/main robot_test1.yml    shell=True    alias=First
    ${result} =    Wait For Process    First
    Should Be Equal As Integers    ${result.rc}    0

    ${test_prog1_em_log} =    getFile     test_prog1_out.txt    encoding=UTF-8    encoding_errors=strict
    Should Be Equal As Strings    ${test_prog1_em_log}    helloo\n

Two app
    Start Process     ../../build/main robot_test2.yml    shell=True    alias=First
    ${result} =    Wait For Process    First
    Should Be Equal As Integers    ${result.rc}    0

    ${test_prog1_em_log} =    getFile     test_prog1_out.txt    encoding=UTF-8    encoding_errors=strict
    Should Be Equal As Strings    ${test_prog1_em_log}    helloo\n

    ${test_prog2_em_log} =    getFile     test_prog2_out.txt    encoding=UTF-8    encoding_errors=strict
    Should Be Equal As Strings    ${test_prog2_em_log}    World\n

loop app
    Start Process     ../../build/main robot_test3.yml    shell=True    alias=First
    Sleep	3s	Wait for a couple loops
    Terminate Process	First	kill=true
    ${test_prog1_em_log} =    getFile     test_prog1_out.txt    encoding=UTF-8    encoding_errors=strict
    Should Be Equal As Strings    ${test_prog1_em_log}    	helloo\nendless loop begins\nhelloo\n 
  