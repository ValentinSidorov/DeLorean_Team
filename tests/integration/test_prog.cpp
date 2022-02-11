#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include "include/test_prog.hpp"
#include <sstream>


using namespace std;


void print_hello (void){
      

	
        for (int i=0; i<10; i++){
	
	    std::cout<<"Hello world!\n";
	}


               
	std::ofstream fout("filename.txt");
	
	if(!fout.is_open()){
	
		std::cout<<"mistake in opening the file\n";
	
	} else{

	
		std::cout<<"filename.txt has been successfully created, you can check it out in your current directory\n";
		
	   }
	   
	int i=0;
       
        while (i<10){

       	 fout<<"Hello world!\n";
       	 i++;

         }



	fout.close();
	
	}
          


void print_arg(const std::string& str) {
      
                int i=0;
                std::cout<<"Output text as argument\n";
                
                
     		 for(i=0; i<10; i++){
          	 std::cout << str<<std::endl;
          	 
             }  

		
		      
		std::ofstream fout("filename1.txt");
		
		if(!fout.is_open()){
		
			std::cout<<"mistake in opening the file\n";
		
		} else{

		
			std::cout<<"filename1.txt has been successfully created, you can check it out in your current directory\n";
			
		   }
	       
		
	       
	       
	       for(int i=0; i<10; i++){
                        
                        
	       	 fout << str <<std::endl;
	       	 

		 }

              

		fout.close();          

	      } 
	      
	      
	



void print_arg2(const std::string& str1, const std::string& str2) {
      
                int i=0;
                std::cout<<"Output text as argument\n";
     		 while (i<10){
          	 std::cout << str1<<std::endl;
          	 std::cout << str2<<std::endl;
          	 i++;
             }  

		
		      
		std::ofstream fout("filename2.txt");
		
		if(!fout.is_open()){
		
			std::cout<<"mistake in opening the file\n";
		
		} else{

		
			std::cout<<"filename2.txt has been successfully created, you can check it out in your current directory\n";
			
		   }
	       
		
	       
	       
	       
	       
	       for(int i=0; i<10; i++){
                        
                        
	       	 fout << str1<<std::endl;
	       	 fout << str2<<std::endl;

		 }

               

		fout.close();          

	      } 	
	      
	      
	      
	      
	      
	      
	      void print_arg3(const std::string& str3) {
      
                int i=0;
                std::cout<<"Output text as argument\n";
     		 while (i<10){
          	 std::cout << str3<<std::endl;
          	 i++;
               }  

		
		      
		std::ofstream fout("filename3.txt");
		
		if(!fout.is_open()){
		
			std::cout<<"mistake in opening the file\n";
		
		} else{

		
			std::cout<<"filename4.txt has been successfully created, you can check it out in your current directory\n";
			
		   }
	       
		
	       
	       
	       
	       
	       int num=0;
	       
	       std::cout<<"the program with endless loop will be finished after five iterations, please wait"<<std::endl;
	       
	       while(true){
                        
                        std::cout << str3 <<std::endl;
                        
	       	 fout << str3 <<std::endl;
	       	 
	       	 
	       	 
	       	 num++;
	       	 
	       	 if(num==5){
	       	 
	       	    fout.close();
	       	    
	       	    break;        
	       	 }
	       	 
	       	 sleep(5);

		 }

    
		    

	      } 
	      
	      

/*void print_choice(void){
	cout<<"Press key 1 to output entered text 10 times to stdout, create file and write the text 10 times there"<<endl;
	cout<<endl;
        cout<<"Press key 2 to output two entered text 10 times to console, create file and write the text 10 times there"<<endl;
        cout<<endl;
        cout<<"Press key 3 to output of entered texts to console, create file and write the text there"<<endl;
	
	cout<<endl;
	}*/
	
   int main (int argc, char *argv[]){
   
   
        //print_choice();
        
       
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
