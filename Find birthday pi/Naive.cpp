//MY BIRTHDAY STRING= = 970328
// Naive algorihtm
#include<iostream> // input file stream
#include<string.h>
#include<fstream>
#include<vector>


using namespace std;

//function signatures
void search_index(vector<char> vect,char pat[]);


void search_index(vector<char> vect,char pat[]){
	
int n=vect.size(); // get the size of the dynamic array which means text
int m=strlen(pat); // get the size of the "pat" string which means pattern
int j=0; int i=0;

//create a reference varible for write
// make a text file and open it
ofstream writefile("results.txt"); 
writefile<<"My birthday string : "<<pat<<endl<<endl;//writing on the file
writefile<<"NAIVE INDEXES"<<endl<<endl; 

//for text 
for(i=0;i<=n-m;i++){	
	for(j=0;j<m;j++){//for pattern
		if(vect[i+j] !=pat[j]){
			break;
		}
	}	
	if(j==m){
		cout<<"Valid search at index number= "<<i<<endl;
		writefile<<"Valid search at index number= "<<i<<endl; 
	}	
}	
writefile.close(); // close the newly created file	
}


int main(){

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
vector<char> vect; //decalration of dynamic vector
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

search_index(vect,pat); // pass the strings to search function
return 0;	
}






