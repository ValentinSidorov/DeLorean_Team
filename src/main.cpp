#include "include/hello.hpp"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


void print_choice(void){
	cout<<"Press key 1 to output entered text 10 times to stdout, create file and write the text 10 times there"<<endl;
	cout<<endl;
        cout<<"Press key 2 to output two entered text 10 times to console, create file and write the text 10 times there"<<endl;
        cout<<endl;
        cout<<"Press key 3 to output of entered texts to console, create file and write the text there"<<endl;
	
	cout<<endl;
	}
	
   int main (int argc, char *argv[]){
   
   
        print_choice();
        
       
	print_hello();
	

 
	
	std::stringstream convert(argv[1]); // create varibale stringstream with name convert, initializing it with the value of argv[1]
 
	int a;
	if (!(convert >> a)) // make conversion
		a = 0; //if conversion fails, then assign a value to a by default 
 

	if (a==1){
	
               cout<<"You've chosen to output entered text 10 times to stdout, create file and write the text 10 times there"<<endl;
		cout << "Enter some text: "<<endl;
		//string str="This is text 1.";
		
		
		string str;
		
		getline(cin, str);
		print_arg(str);

	    }
	
	  
        else if (a==2)
	   {
		cout << "Now output with the function of two arguments passed: "<<endl;
		cout << "Enter some text: "<<endl;
		
		string str1;
		getline(cin, str1);
		
	        cout << "Enter another text: "<<endl;
		string str2;
		
		getline(cin, str2);
		
		print_arg2(str1, str2);
			
           }
	
	
	
           else if(a==3)
          {		
		cout << "Now output with infinite loop function taking one argument: "<<endl;
		string str3;
		
		cout << "Enter some text: "<<endl;
		getline(cin, str3);
		print_arg3(str3);
		
	  }	
	 
	 
          else{
	 
	 
	 cout<<"You have not pressed the required keys, try again"<<endl;
	 
	 
	 }
	 
	 
	return 0;

}
