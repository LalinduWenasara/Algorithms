//MY BIRTHDAY STRING= = 970328 
// KMP algorithm 
#include<iostream> //input file stream
#include<string.h>
#include<fstream>
#include<vector>

using namespace std;

  
  
//function signatures  
void pifunction(int prefix[],char pat[], int a); 
void search(vector<char> vect,char pat[]);
  

void search(vector<char> vect,char pat[]) 
{ 
//create reference variable for write
//make a text file and open it
ofstream writefile("results.txt");

writefile<<"My birthday string : "<<pat<<endl<<endl;//writing on the file

 writefile<<"KMP INDEXES"<<endl<<endl;

 int b = vect.size(); // get the size of the dynamic array which mean text
int a = strlen(pat); // get the size of the "pat" string which means pattern
   
  
    
     //Declaration of the prefix array which has same length of pattern
    int prefix[a];
  
    //Create the pi function for the pattern
    pifunction(prefix,pat,a); 
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < b) { 
        if (pat[j] == vect[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == a) { 
            cout<<"Valid search at index number= "<< i - j <<endl;
            
           
			writefile<<"Valid search at index number= "<< i - j <<endl; 
            j = prefix[j - 1]; 
        } 
  
        
        else if (i < b && pat[j] != vect[i]) { 
            
            if (j != 0) 
                j = prefix[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 
  
void pifunction(int prefix[],char pat[], int a) 
{ 

    
    int len = 0;
  
  
  
  // default prefix[0]=0 in pi function array
  prefix[0] = 0; 
  
    // create the prefix pi function array
    int i = 1; 
    while (i < a) { 
        if (pat[i] == pat[len]) { 
            len++; 
            prefix[i] = len; 
            i++; 
        } 
        else if(pat[i] != pat[len]) 
        { 
            
            if (len != 0) { 
                len = prefix[len - 1]; 
  
                
            } 
            else if (len == 0) 
            { 
                prefix[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
  

int main() 
{ 
//ofstream myfile("abi.txt");
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



//char text[]="ABBCABBCBCCABCDABCFGCD";
//cout<<"Enter birthday code:"<<endl;

//char pat[]={'9','7','0','3','2','8','\0'};

//char pat[]="970328";
char pat[6];

cout<<"Enter the birthday String for search :"<<endl;
cin>>pat;
cout<<endl; 

search(vect,pat); // pass the strings to search function

	return 0; 
} 
