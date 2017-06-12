//*******************************************************************
                                  //this program about objects that write themsleves in the disk filebuf
                                  //*****************************************************************
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<iomanip>
#include<ios>
#include<unistd.h>
#include<cstdlib>
#include<cstdio>
using namespace std;
//class person it is a class its objects write into one disk file
class person{
//private methods
private:
static char filename[100];
static fstream file;
int Id;
char name[100];
int Age;
//public methods
public:
person () //no argument
{}
person(char* filnam){    //one argument constructor
strcpy(filename,filnam);
strcat(filename,".DAT");
file.open(filename,ios::in|ios::out|ios::binary|ios::app);
if(!file)
{
cerr<<"couldn't create the file \n";
exit(1);
}
file.close();
}

person(int id,char* nam,int a):Id(id),Age(a)
{strcpy(name,nam);}                          //3  argument constructor

void getdata();
void dispdata();
bool readobjec(int);
bool search_by_id(int);
bool search_by_name(char []);
bool checkname(char[]);
bool checkid (int);
void writeobjec();
void getinfo_byId(int);
void getinfo_byName(char []);
static int countobjcs();
static void openfile(char*);
static void closefile();
};
void
person::getdata()
{
cout<<"***************************"<<endl;
cout<<"ID : ";      cin>>Id;
cout<<"Name : ";     cin>>name;
cout<<"Age : ";      cin>>Age;
}
void
person::dispdata()
{
cout<<"***************************"<<endl;
cout<<"Id : "<<Id<<endl;
cout<<"Name : "<<name<<endl;
cout<<"Age : "<<Age<<endl;
}
//create the filename
char
person::filename[100];
//create the fstream
fstream
person::file;
//countnumber_of_objects
int
person::countobjcs()
{
file.close();    //close the main file
fstream infile ; //create new object file
infile.open(filename,ios::binary|ios::in);
infile.seekg(0,ios::end);
int len=infile.tellg()/sizeof(person);
infile.close();
file.open(filename);
return len;
}
//write an object into the file
void
person::writeobjec()
{
file.write(reinterpret_cast<char*>(this),sizeof(*this));
if(!file)
cout<<"you may need to open the file to write the person to the file"<<endl;
else cout<<"successful writting.\n";

}
//read an object from the file
bool
person::readobjec(int obn)   //read an object by its index in the file
{
//make the get pointer points to the required object
//then read it

if(person::countobjcs()>0)        //check if there is persons or no
{
file.seekg(obn*sizeof(person),ios::beg);
file.read((char*)this,sizeof(*this));
return true;
}
else
{return false;}
}
//open specific file
void
person::openfile(char* nam)
{
strcpy(filename,nam);
file.close();
file.open(filename);
}
//close the file
void
person::closefile()
{file.close();}
//search by value
bool
person::search_by_name(char nam [100] )
{
file.seekg(0,ios::beg);
person p;
file.read(reinterpret_cast<char*>(&p),sizeof(p));  //read the first file
while(file)
{
if(p.checkname(nam))
{ file.seekg(0,ios::end); return true;}
//read new person
file.read(reinterpret_cast<char*>(&p),sizeof(p));
}//end while
file.seekg(0,ios::end);
return false;
}
//search by id
bool
person::search_by_id(int i)
{
file.seekg(0,ios::beg);
person p;
file.read(reinterpret_cast<char*>(&p),sizeof(p));  //read the first file

while(file)
{
if(p.checkid(i))
{ file.seekg(0,ios::end); return true;}
//read new person
file.read(reinterpret_cast<char*>(&p),sizeof(p));
}//end while
file.seekg(0,ios::end);
return false;
}
//check name
bool
person::checkname(char N[100])
{return strcmp(name,N)?false:true;}
//check Id
bool
person::checkid(int i)
{return Id==i? true:false;}
//get info by id
void
person::getinfo_byId(int i)
{
if(search_by_id(i))
{}
else
{cout<<"this person isn't found"<<endl;}
}
//get info by name
void
person::getinfo_byName(char nam[100])
{
if(search_by_name(nam))
{}
else
{cout<<"this person isn't found"<<endl;}
}
//main function
int main()
{

int r=remove("student.DAT");
r=remove("Employee.DAT");
person("student");                  //open file to record students
person("Employee");                 //open file to record the employees
person p(1,"ahmed",30);            //first person
p.openfile("student.DAT");
p.writeobjec();                    //write the first student int the file
person p1(3,"elsaid",50);                         //second person
p1.writeobjec();                   //write the second student to the file
if(p1.search_by_id(3))
{cout<<"okey"<<endl;}
person pp ;
pp.readobjec(0);
pp.dispdata();
person p2(4,"saad",1000);                         //third person
p1.writeobjec();                   //write the third student to the file
pp.readobjec(1);                   //now we need to read the second person
pp.dispdata();
pp.closefile();

person e(2,"Ibrahim",22);           //first employee
e.openfile("Employee.DAT");
e.writeobjec();
person ee ;
ee.readobjec(0);
ee.dispdata();
ee.closefile();

return 0;
}

