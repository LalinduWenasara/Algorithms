//MY BIRTHDAY STRING= = 970328
//Rabin carp algorithm
#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>

#define s 256
 
using namespace std; 
       
//function signature     
void search_index(vector<char> vect,int q,char pat[]);

void search_index(vector<char> vect,int q,char pat[])  
{  
    int m = strlen(pat);// get the size of the dynamic array which means text  
    int n = vect.size();//get the size of the "pat" string which means pattern  
    int i, j;  
    int p = 0; // hash pattern index  
    int t = 0; // hash text index  
    int a = 1;  
    
    
    //create a reference varible for write
// make a text file and open it
ofstream writefile("results.txt"); 
writefile<<"My birthday string : "<<pat<<endl<<endl;//writing on the file
writefile<<"RABIN CARP INDEXES"<<endl<<endl; 
  
    
    for (i = 0; i < m - 1; i++)  
        a = (a * s) % q;  
  
   
    for (i = 0; i < m; i++)  
    {  
        p = (s * p + pat[i]) % q;  
        t = (s * t + vect[i]) % q;  
    }  
  
    // pattern increment along the text  
    for (i = 0; i <= n - m; i++)  
    {  
  
        // hash values checking
        
        if ( p == t )  
        {  
            
            for (j = 0; j < m; j++)   // for loop for check the characters one after the other
            {  
                if (vect[i+j] != pat[j])  
                    break;  
            }  
  
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]  
            if (j == m)  
                cout<<"Valid search at index number= "<< i<<endl; 
				 writefile<<"Valid search at index number= "<<i<<endl;
        }  
  
       
        if ( i < n-m )  
        {  
            t = (s*(t - vect[i]*a) + vect[i+m])%q;  
  
            
            if (t < 0)  // to ignore the t's negative value to convert it to positive
            t = (t + q);  
        }  
    }  
}  
  

int main()  
{  

//declare an input file stream variable
// create a reference called "file" for "pi.txt" 
// assign txt file to the "file"
fstream file; 
string line;

file.open("pi.txt"); // opent the "pi.txt" file, we put a reference as "file", in future we access the text file as this "file" reference

//check whether the file is open or not
if(!file.is_open()){
	
	cout<< "Error in file opening ";
	exit(1);
}

// prevent the unwanted line up to "pi=3."

for(int i=0;i<21;i++){   //read line by line from "file" and put it into a variable called "line"
//"getline(file,line)" this function has a return value


//when call first time first line of the file will be assigned to the "line"
//while(getline(file,line))

	getline(file,line);
}

//cout<<line;
vector<char> vect;
while(getline(file,line)){
	
	if(!line.empty()){
		for(int j=0;j<=53;j++){
			
			if(!(line[j]==' ')){
				vect.push_back(line[j]);
				
				
			}
			
		}	
		
	}
}
//cout<<vect.size();


//cout<<vect.at(0);

//cout<<"Enter birthday code:"<<endl;

//char pat[]={'9','7','0','3','2','8','\0'};

//char pat[]="970328";
char pat[6];

cout<<"Enter the birthday String for search :"<<endl;
cin>>pat;


    int q = 101; // A prime number  
    search_index(vect,q,pat);  
    
   return 0;  
}  
  
 
