#include<iostream>
#include<ostream>
#include<fstream>
#include<string>
#include<string.h>
#include<iomanip>
#include<ios>
#include<strstream>
#include<unistd.h>
#include<cstdlib>
#include<cstdio>
#include<typeinfo>
using namespace std;
//****************************
//This code about streams
//***************************
/*
//this function check the input string is okey
bool checkIdentifier(string s)
{
int len=s.size();
int i=0;

//identifier must start with alpha
if(!isalpha(s[i++]))
return false;
 //return false if the character isn't alph and num and _
for(int i=0;i<len;i++)
if(!isalpha(s[i]) && s[i]!='_' && !isalnum(s[i]))
return false;
return true;

}

int main()
{
string str;


//test if input string is okey
while(true)
{
cin.unsetf(ios::skipws);
//cout<<"Enter integer value"<<endl;
cin>>str;
if(checkIdentifier(str))
{
cout<<"Your identifier is okey"<<endl;
cin.ignore(100,'\n');
break;
}
else
{
cout<<"Enter correct identifier"<<endl;
cin.ignore(100,'\n');
 }
}
int n;          //n must be greater than 0 and less than 10

while (true)
{
cin.unsetf(ios::skipws);     //don't ignore whitespaces
cin>>n;
if(n>9 || n<1)
{
cout<<"enter value greater than 0 and less than 10"<<endl;
cin.clear(ios::failbit);    //say there is an error in the input value
}
if(cin.good())
{
cin.ignore(10,'\n');
break;
}
cin.clear();               //return everything as it was (right or okey)
cin.ignore(10,'\n');       // ignore the characters in the buffer and '\n' from them

}

return 0;
}
*/
//******************************************************************************************************************
//**************************
//This Code about Files
//**********************
//this class to store an object in the disk
/*class person{
private:
char name[100];
int age;
public:
//insert data of the person
void getdate()
{
cout<<"Name : ";       cin>>name;
cout<<"Age : " ;        cin>>age;
}
//display data of the person
void disp()
{
cout<<"_________________"<<endl;
cout<<"person data"<<endl;
cout<<"Name : "<<name<<endl;
cout<<"Age = "<<age<<endl;
}
//get age
int getage()
{return age;}
//get name
void getname(char N[100])
{N=name;}
//check name
bool checkname(char N[100])
{return strcmp(name,N)?false:true;}
//end of the class
};
//I have create this class to ensure that we can assign different class with different
//methods to each other if the have the same field methods
//where you must define the variabel of the second in the same order of the first
class pp{
private:
char name[100];
int age;
public:
//display data of the person
void disp()
{
cout<<"Name : "<<name<<endl;
cout<<"Age = "<<age<<endl;
}

};
int main()
{
string s1 = "hello";
string s2 = "world";
string s3 = "helloscince";
char ch = 'D';
int j = 77;
double d = 6.02;
*/
//ofstream f("des.txt");
                        //**************************************
                          //this part about create in/out files and
                          //how to write into them and read from them
                        //*********************************************

/*f<<"if you are going to try go all the way , "<<endl;
f<<"otherwise don't even start this could mean losing your mind ,"<<endl;
f<<"this could mean losing your relatives ,"<<endl;
f<<"this could mean losing your wife ,"<<endl;
f<<"this could mean not eating for 3 or 4 days ,"<<endl;

ifstream ifile("des.txt");
char s[100];
while(!ifile.eof())
{
ifile.getline(s,100,'.');
cout<<s<<endl;
}
*/
                           //***************************************************
                           //this part ouptut IO characters (put(char),get(char))
                           //**************************************************
/*for(int i=0;i<s1.length();i++)
f.put(s1[i]);
f<<endl;
*/
//ifstream f("des.txt");
//ofstream of("des.txt");
//of<<f.rdbuf()<<endl;
//cout<<f.rdbuf();
//*****************
//this part about IO binary
//********************
/*const int MAX=100;
int buffer[MAX];
for(int j=0;j<MAX;j++)
buffer[j]=j;
ifstream inf("des.txt");
ofstream os("intarray.dat",ios::binary);
os.write((char*)inf.rdbuf(),MAX*sizeof(int));
os.close();
ifstream is("intarray.dat",ios::binary);
is.read(reinterpret_cast<char*>(buffer),MAX*sizeof(int));
for(int j=0;j<MAX;j++)
if(buffer[j]!=j)
{cerr<<"incorrect data\n";  return 1;}
cout<<"correct data\n";
*/
                                       //*************************************************
                                       //this part about IO objects to and from the disk
                                        //***********************************************
/*person p;
p.getdate();
//create file to store an object on the disk
ofstream outfile;
outfile.open("person.DAT",ios::binary);
outfile.write(reinterpret_cast<char*>(&p),sizeof(p));
outfile.close();
pp per;
ifstream infile;
infile.open("person.DAT",ios::binary);
infile.read(reinterpret_cast<char*>(&per),sizeof(per));
per.disp();
infile.close();
*/
                                        //******************
                                        //I/o multiple objects
                                        //**************
/*
char c;
person per;
fstream file;
file.open("Group.DAT",ios::out|ios::in|ios::binary|ios::app);
do
{
cout<<"\n Enter the person data\n";
per.getdate();
file.write(reinterpret_cast<char*>(&per),sizeof(per));
cout<<"Enter 'y' to enter new person"<<endl;
cin>>c;
}while(c=='y');

cout<<"*****************************************"<<endl;

infile.seekg(0,ios::beg);
infile.read(reinterpret_cast<char*>(&per),sizeof(per));
while(infile)
{
cout<<"person "<<endl;
per.disp();
//read new record
infile.read(reinterpret_cast<char*>(&per),sizeof(per));
}*/
                                          //**************
                                          //File pointers
                                          //**************
/*
person per;
char  s[100];
//create pointer to read the file Group
ifstream infile("Group.DAT",ios::in|ios::binary);
//set get pointer to the start of the file
infile.seekg(0,ios::end);
//get the offest from the beginning
int endpoistion=infile.tellg();
//calculate the number of persons in the file
int n = endpoistion/sizeof(per);
//get person from the user
cout<<"there is "<<n<< " int the file"<<endl;
cout<<"\nEnter the name person you want know data about him : ";
cin>>s;
//search in the file about this person
infile.seekg(0,ios::beg);
infile.read(reinterpret_cast<char*>(&per),sizeof(per));
while(infile)
{
//check if this the required person
if(per.checkname(s))
{cout<<"his age = "<<per.getage()<<endl; break;}
//read new person
infile.read(reinterpret_cast<char*>(&per),sizeof(per));
}//end if

//read by the number
int index;    //required person
//get the number
cout<<"Enter the number of the person\n";
cin>>index;
//get the data about the person
if(index <n+1 && index>0)
{
infile.seekg((n-1)*sizeof(per),ios::beg);
infile.read(reinterpret_cast<char*>(&per),sizeof(per));
per.disp();
}//end if
*/
                                    //************************
                                    //Error handling i/o files
                                    //***********************
/*int buffer[100];
ofstream ofile;
ofile.open("buffer.DAT",ios::trunc| ios::binary);
if(!ofile)
{cerr<<"could not open output file\n"; exit(1);}
cout<<"Writting ... \n";
ofile.write(reinterpret_cast<char*>(buffer),100*sizeof(int));
if(!ofile)
{cerr<<"could not write in this  file\n"; exit(1) ;}
for(int i=0;i<sizeof(buffer)/sizeof(int);i++)
buffer[i]=i;
ofile.close();
//open new file to read
ifstream infile("buff1er.DAt",ios::binary);
if(!infile)
{cerr<<"could not open input file\n"; exit(1) ;}
cout<<"Reading the file \n";
infile.read(reinterpret_cast<char*>(buffer),100*sizeof(int));
if(!infile)
{cerr<<"could not read in this  file\n"; exit(1) ;}
//check the reading data
for(int i=0;i<sizeof(buffer)/sizeof(int);i++)
{
if(buffer[i]!=i)
{
cerr<<"data is incorrect \n"; exit(1) ;
}
}
cout<<"Data is correct\n";

return 0;
}
*/                                 //*******************************************************************
                                  //this program about objects that write themsleves in the disk filebuf
                                  //*****************************************************************
/*
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
*/

                                                  //*********************************************************
                                                  //this program about deal with various class by one array of pointers
                                                  //***************************************************************
/*

const int LEN = 32;            //length of the last name
const  int MAXEM = 100;       //no of employees
enum emp_type{tmanager,tscinetist,tlabour};
/////////////////////////////////////////
class employee    //base class
{
private:
char name[LEN];
unsigned long number;
static int n;   //current number of employees
static employee* arrap[MAXEM];  //arr of pointers to emps
public:
virtual void getdata();
virtual void putdata();
virtual emp_type get_type();
static void add();       //add emp to the arr
static void read();     //read an emp from the disk
static void write();   //write emp to the disk
static void display(); //dispaly all emps

};
//////////////////////////
int employee::n;
/////////////////////////
employee* employee::arrap[MAXEM];
//////////////////////////////////
void employee::getdata()
{
cin.ignore(10,'\n');
cout<<"Enter the last name   :"; cin>>name;
cout<<"Enter the number :";      cin>>number;
cout<<endl;
}
/////////////////////////////
void employee::putdata()
{
cout<<"\n  Name : "; cout<<name<<endl;
cout<<"\n   Number : "; cout <<number<<endl;
cout<<endl;
}
////////////////////////////////
//class of manager
class manager:public employee
{
private:
char title[LEN];
double dues;
public:
void getdata()
{
employee::getdata();
cout<<"Enter the title : "; cin>>title;
cout<<"Enter golf club dues : "; cin>>dues;
cout<<endl;
}

void putdata()
{
employee::putdata();
cout<<"\nTitle : "<<title<<endl;
cout<<"\nDues : "<<dues<<endl;
cout<<endl;
}
};
//////////////////////////////
//class of scientist
class scientist: public employee
{
private:
int pubs;
public:
void getdata()
{
employee::getdata();
cout<<"Enter the number of publication : "; cin>>pubs;
cout<<endl;
}

void putdata()
{
employee::putdata();
cout<<"NO of Publications : "<<pubs<<endl;
cout<<endl;
}

};
///////////////////////////////
//class of labour
class labour:public employee
{};
///////////////////////////////////
void employee::add()
{
char ch;
cout<<"'m' to add a manager"
      "'\n 's' to add a scientist"
      "\n 'l' to add a laborer"
      "\n Enter selection :";
cin>>ch;
switch(ch)
{
case 'm': arrap[n]=new manager;   break;
case 's': arrap[n]=new scientist; break;
case 'l': arrap[n]=new labour;    break;
default: cout<<"\n Unkown employee type\n";   return;
}
arrap[n++]->getdata();
}
////////////////////////////////////////////////////////
emp_type employee::get_type()
{
if(typeid(*this)==typeid(manager))
{return tmanager;}
else if(typeid(*this)==typeid(scientist))
{return tscinetist;}
else if(typeid(*this)==typeid(labour))
{return tlabour;}
else
cout<<"Bad employee type\n"<<endl;
}
////////////////////////////////////////////////////////
void employee::display()
{
for(int i=0;i<n;i++)
{
cout<<i+1;
switch(arrap[i]->get_type())
{
case tmanager : cout<<"Type: manager\n";  break;
case tscinetist : cout<<"Type: scientist\n";  break;
case tlabour : cout<<"Type: labour\n";  break;
default: cout<<"Unkwon type\n";
}
arrap[i]->putdata();
}
}
/////////////////////////////////////////////////
//write all memory objects to a file
void employee::write()
{
int siz;
cout<<"Writting "<<n<<"employees\n";
emp_type etype;
ofstream outf;
outf.open("EMPS.DAT",ios::binary|ios::trunc);
if(!outf)
{cout<<"can't open file \n"; return;}

for(int i=0;i<n;i++)
{
etype=arrap[i]->get_type();
outf.write((char*)&etype,sizeof(etype));
switch(etype)
{
case tmanager:   siz=sizeof(manager) ;       break;
case tscinetist: siz=sizeof(scientist);      break;
case tlabour:     siz=sizeof(labour) ;       break;
}
outf.write(reinterpret_cast<char*>(arrap[i]),siz);
if(!outf)
{cout<<"can't write to the file"<<endl;}
}
}
///////////////////////////////////////////////////
void employee::read()
{
int siz;
emp_type etype;
ifstream infile;
infile.open("EMPS.DAT",ios::binary);
if(!infile)
{cout<<"can't open this file \n";}
n=0;
while(true)
{
infile.read((char*)&etype,sizeof(etype));
if(infile.eof())
{break;}
if(!infile)
{cout<<"can't rad type of this file\n";}
switch(etype)
{
case tmanager:
arrap[n]=new manager;
siz=sizeof(manager);
break;

case tscinetist:
arrap[n]=new scientist;
siz=sizeof(scientist);
break;

case tlabour:
arrap[n]=new labour;
siz=sizeof(labour);
break;

default:cout<<"unknow type in the file"<<endl; return;
}//end of switch

infile.read(reinterpret_cast<char*>(arrap[n]),siz);
if(!infile)
{cout<<"can't read employee from the file"<<endl;}
n++;
}//end of while
cout<<"reading "<<n<<" of employees"<<endl;

}
//////////////////////////////////////////////////
int main()
{
char ch;
while(true)
{
cout<<"************************************************"<<endl;
cout<<"'a'  --add data for employee"
      "\n'd'  --display data for all employees"
      "\n'w'  --write all employees to file"
      "\n'r'  --read all employees to file"
      "\n'x'  --to exit"
      "\nEnter selection : ";
      cin>>ch;
switch(ch)
{
case 'a': employee::add(); break;
case 'd': employee::display(); break;
case 'r': employee::read(); break;
case 'w': employee::write(); break;
case 'x': exit(0);
default : cout<<"\n Unkwon command"; break;
}

}//end while

return 0;
}
*/
                                     //***********************************
                                     //overloading << and >> with objects and files
                                     //deal with memory as stream objects to format your output
   /*                                  //*********************************
class A{
private:
int x;
int y;
public:

A():x(0),y(0){}
friend istream& operator >>(istream& s,A& a);
friend ostream& operator <<(ostream& s,A& a);
};

istream& operator >>(istream& s,A& a)
{
s>>a.x;
s>>a.y;
return s;
}
ostream& operator <<(ostream& s,A& a)
{
s<<a.x<<endl;
s<<a.y<<endl;
return s;
}
int main()
{
int j=1;
char c='a';
double d=10245.11248;
char buff[100];
char str1[]="hello";
char str2[]="thank you";
ostrstream s(buff,100);
s<<"ch="<<c<<endl
 <<"j="<<j<<endl
 <<setiosflags(ios::fixed)
 <<setprecision(2)
 <<"d="<<d<<endl<<ends
 <<"str1"<<str1<<endl
 <<"str2"<<str2<<endl
 <<ends;
 cout<<buff<<endl;
A a,b;
cout<<"enter A and B\n";
cin>>a>>b;
cout<<a<<endl<<b;
cout<<"******"<<endl;
cout<<a<<endl<<b;
fstream f("s.dat",ios::binary|ios::out|ios::in|ios::trunc);

return 0;
}
*/
                    //*************************
                    //command line arguments
                    //**********************
int main(int arg,char * argums[])
{
cout<<"NO of arguments"<<arg<<endl;
for(int i=0;i<arg;i++)
cout<<argums[i]<<endl;

return 0;
}
