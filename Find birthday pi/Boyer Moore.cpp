//MY BIRTHDAY STRING= = 970328
//Boyer algorithm
#include<iostream> // input file stream
#include<string.h>
#include<fstream>
#include<vector>

#define c 256 

using namespace std; 

//function signatures 
 void badCharacter(int badarr[c],char pat[], int size);
 void search_index(  char pat[],vector<char> vect);
  
  
void badCharacter( int badarr[c],char pat[], int size)  
{  
    int i;  
  
    // default values  
    for (i = 0; i <c; i++)  
        badarr[i] = -1;  
  
    // last occurence value
    for (i = 0; i < size; i++)  
        badarr[(int) pat[i]] = i;  
}  
  

void search_index( char pat[],vector<char> vect)  
{  
    int m = strlen(pat); // get the size of the "pat" string which means pattern 
    int n = vect.size();  // get the size of the dynamic array which means text 
  
    int badarr[c];  
  
    // calling the badcharacter function
    badCharacter( badarr,pat, m);  
  
  //create a reference varible for write
// make a text file and open it
ofstream writefile("results.txt"); 
writefile<<"My birthday string : "<<pat<<endl<<endl;//writing on the file
writefile<<"BOYER MOORE INDEXES"<<endl<<endl; 
  
    int s = 0; 
    
    while(s <= (n - m))  
    {  
        int j = m - 1;  
  
        //decrement indexes ,pattern and text are matching in this shift 
        while(j >= 0 && pat[j] == vect[s + j]){
        	j--;
		}  
              
  
        
        if (j < 0)  
        {  
            cout << "Valid search at index number= " <<  s << endl;  
  writefile<<"Valid search at index number= "<<s<<endl; 
            
            // shift the pattern
            s += (s + m < n)? m-badarr[vect[s + m]] : 1;  
  
        }else{
        	s += max(1, j - badarr[vect[s + j]]);  

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

search_index(pat,vect); // pass the strings to search function

	return 0; 
	 
}  
   

