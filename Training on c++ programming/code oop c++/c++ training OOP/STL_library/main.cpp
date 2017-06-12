#include <iostream>
#include<fstream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<list>
#include<string.h>
#include<deque>
#include<functional>
#include<typeinfo>
#include<numeric>
#include<iterator>
using namespace std;

/*

////////////////////////////
template<class T>
bool comp_cstr(T s1,T s2)
{ cout<<"s1 = "<<s1<< "    s2 = "<<s2<<endl;
return strcmp(s1,s2)>0?true:false;}
/////////////
//used with adding _if to the algorithm library
bool isall(string s)
{cout<<s<<endl; return s=="all";}
////////////////////
//using for_each algorithmm by determine what you want to do with each element in the container
//write your own function that does this something
void I_am(string s)
{
cout<<s<<endl;
}
///////////////////
//use transform algorithm to convert an array from pattern to anthor pattern
//the return must be from the same type of the content
string I_am_array(string s)
{ return "I am"+s;}
//main function
int main()
{
string nam[4]={"go","all","the","way"};
string I_am_nam[4];
transform(nam,nam+4,I_am_nam,I_am_array);

for_each(I_am_nam,I_am_nam+4,I_am);
cout<<"all in "<<find_if(nam,nam+4,isall)-nam<<endl;

char* names[4]={"go","all","the","way"};
int a[]={8,10,7,6,5,4,3,2,1};
cout<<count(a,a+6,1)<<endl;
//use find to search for one value in the container
cout<<find(a,a+9,10)-a<<endl;
sort(a,a+9);
//here we use the function object to sort descending instead of ascendingly
sort(names,names+4,comp_cstr<char*>);
for(int i=0;i<4;i++)
cout<<names[i]<<" ";
cout<<endl;
//use search to find container inside anthor container
int pattern[]={3,2,1};
sort(pattern,pattern+3);
int* ptr = search(a,a+9,pattern,pattern+3);
if(ptr==a+9)
cout<<"sory I can't find this subsequence\n";
else
cout<<ptr-a<<endl;
//merge two containers to each others but they must be sorted firstly


int dest[15];
merge(a,a+9,pattern,pattern+3,dest);
for(int i=0;i<12;i++)
cout<<dest[i]<<"  ";
cout<<endl;

    return 0;
}
*/
//in this part we deal with sequence container such as vector and deque and stack queue
void features_of_vectors()
{
//using max_size and size and push_back
vector<int> v;
vector<double> k;
if(v.max_size()>=k.max_size())
cout<<"hello"<<endl;
cout<<v.max_size()<<endl;
char c;
do{
int x;
cin>>x;
v.push_back(x);
cout<<"if you want to continue enter [y/n] : "; cin>>c;
}while(c=='y');
v.push_back(300);
v.pop_back();

for(int i=0;i<v.size();i++)
cout<<v[i]<<endl;
cout<<"_____________________________________"<<endl;

//use swap and push_back , pop_back and empty intialize a vector with an array
double arr[]={1,2,3,6,9,8,7,4,5,2};
vector<double>v1(arr,arr+4);
//or by specific size of elements

vector<double>v2 (arr+4,arr+10);
//v2.swap(v1);
swap(v1,v2);
while(!v2.empty())
{cout<<v2.back()<<"    "; v2.pop_back();}
cout<<endl;

while(!v1.empty())
{cout<<v1.back()<<"    "; v1.pop_back();}
cout<<endl;

////////////////
// use insert() and erase with vectors
v1.insert(v1.begin(),10);
cout<<v1[0]<<endl<<v1[1]<<endl;
v1.erase(v1.begin());
cout<<v1[0]<<endl<<v1[1]<<endl;
}

void features_of_lists()
{
//in lists we can't use random access since it is very slow so there isn't operator []
list<int>lis,lis1;
for(int i=0; i<5;i++)
{ lis.push_front(i); lis1.push_back(i);}
lis.insert(lis.begin(),5);
lis.erase(lis.begin());
lis.reverse();
lis.merge(lis1);
lis.unique();

int sz=lis.size();
for(int i=0; i<sz;i++)
{
cout<<lis.front()<<' ';
lis.pop_front();
}
}
void features_of_queues()
{
deque<int> deq;
for(int i=0; i<5;i++)
{ deq.push_front(i); }
deq[2]=5;
deq.push_front(4);
for(int i=0; i<deq.size();i++)
{ cout<<deq[i]<<endl;}
}
//now we will take about the iterators
//iterators are used as cables between algorithms and containers
//where they determine which algorithm can use which container
//there are 5 types of iterators(they are classes smart version of c++ pointers)
//order by power from high to low (random access , bidirectional, foreward , out , in)
//default to vectors and deques is random access iterators
//default for lists and associative containers is bidirectional iterators
void iterator_session()
{
//containers and iterators
int arr[]={1,2,3,4,5,6};
list<int>thelist(arr,arr+6);
//reverse iterator
list<int>::reverse_iterator listit = thelist.rbegin();
while(listit!=thelist.rend())
{
cout<<"item = "<<*listit++<<' ';
}
cout<<endl;
//insert iterator , it helps you to avoid overwritting do hear me yes
//there are 3 types (back_insert front_insert inserter "insert at a specific location")
//put in your mind front_insert can't be used with vector where they don't have push_front()
int a1[]={1,2,3};
int a2[]={4,5,6};
deque<int>d1(a1,a1+3);
deque<int>d2(a2,a2+3);
copy(d2.begin(),d2.end(),inserter(d1,d1.begin()+1));
deque<int>::iterator deit = d1.begin();
while(deit!=d1.end())
cout<<"d = "<<*deit++<<endl;
///////////////////////////

cout<<"first element = "<<*listit<<endl;
vector<int>thevector(arr,arr+6);
vector<int>emptyvector(10);

vector<int>::iterator itc =copy(thevector.begin(),thevector.begin()+5,emptyvector.begin());
vector<int>::iterator it = emptyvector.begin();
while(it!=itc)
cout<<*it++<<' ';
cout<<endl;
//stream iterators (ostream_iterators and istream_iterator) used to deal with files and o/i devices
//ostream_iterators
ostream_iterator<int> ositer (cout,", ");
cout<<"content of deque1 is"<<endl;
copy(d1.begin(),d1.end(),ositer);
cout<<endl;
//in files the same thing but instead use output stream object use output file object ofstream outfile("T.dat");
//istream
istream_iterator<int> cin_iter(cin);  //start of the iterator
istream_iterator<int> end_iter;     //end of iterator
copy(cin_iter,end_iter,d1.begin());
cout<<endl;
ostream_iterator<int> oster(cout," ");
copy(d1.begin(),d1.end(),oster);
///////////////////////
}
/////////////////////////
//user defined data type
class person{
private:
string fristname;
string lastname;
long num;
public:
person():fristname("blank"),lastname("blank"),num(0)
{}
person(string f , string l , int p):fristname(f),lastname(l),num(p)
{}
~person(){}
void setvals (string f,string l,int n)
{fristname=f; lastname=l; num=n;}
void display() const
{
cout<<"Frist Name : "<<fristname<<endl;
cout<<"Last Name : "<<lastname<<endl;
cout<<"Phone : "<<num<<endl;
}
//get the phone number
long get_phone()const
{return num;}

friend bool operator <(const person& , const person&);
friend bool operator ==(const person& , const person&);
friend bool operator >(const person& , const person&);
friend bool operator !=(const person& , const person&);
};

bool operator != (const person& p1 ,const person& p2)
{return !(p1==p2);}

bool operator > (const person& p1 ,const person& p2)
{return (!(p1==p2) && !(p1<p2)); }

bool operator < (const person& p1 ,const person& p2)
{
if(p1.lastname==p2.lastname)
return ( p1.fristname < p2.fristname ) ? true : false;
return (p1.lastname<p2.lastname)? true:false;
}

bool operator ==(const person& p1,const person& p2)
{ return ( p1.lastname == p2.lastname && p2.fristname == p1.fristname ) ? true : false ; }
/////////////////////////////////
void associative_containers()
{
string names[]={"enjoy","learning","maths","and","technologies"};
set<string, less<string> >set1(names,names+5);
set<string,less<string> >::iterator setit = set1.begin();
set1.insert("enjoy");
set1.insert("hello");
set1.insert("world");
cout<<"there is "<<set1.size()<<" in the list"<<endl;
while(setit!=set1.end())
{cout<<*setit++<<' ';}
cout<<endl;
string s ="maths";
if(find(set1.begin(),set1.end(),s)!=set1.end())
cout<<"I find maths "<<endl;
setit=set1.lower_bound("ew");   //this will return the first one equal or greater than this argument
cout<<"____________________-"<<endl;
while(setit!=set1.upper_bound("t"))
{cout<<*setit++<<endl;}
//map and multimap associative arrays or associative containers
//map<data type , key type , order type (less<datatype>, greate<data type>)>
string my_principle_in_life[]={"be quiet","be on the watch","go all the way","love what you do"};
int pops[]={0,1,2,3,4};
map<string , int , less<string> > namemap;
map<string, int, less<string> >::iterator mapit;
for(int i=0;i<4;i++)
{
string s=my_principle_in_life[i];
namemap[s]=i;   //as you can see string is the key word and int the value
}

cout<<"hello from map"<<endl;
cout<<namemap["go all the wa"]<<endl;
/////////////////////////////////////
//using multiset to define a key has more than one values
//we overload == and < operators because multiset need them in ordering process
cout<<"__________________________________"<<endl;
person* persons[10];
multiset<person , less<person> > multiset_person;
multiset<person , less<person> >::iterator multisetit;
string me[6]={"you","you","go","all","the","way"};
string ours[6]={"ahmed","ahmed","saad","eslaid","kamelia","amer"};
for(int i=0;i<6;i++)
{
string f=me[i];
string l=ours[i];
cout<<f<<endl;
persons[i]=new person(f,l,i);
multiset_person.insert(*(persons[i]));
}
person p1("you","ahmed",01);
person p2("you","ahmed",111);
multiset_person.insert(p1);
multiset_person.insert(p2);
person serper("you","ahmed",0);
//it as you search for aperson by counting its existence in the set
cout<<"there is "<<multiset_person.count(serper)<<endl;
multisetit=multiset_person.lower_bound(serper);
while(multisetit!=multiset_person.upper_bound(serper))
{(*multisetit++).display();}
cout<<"number of elements in multiset = "<<multiset_person.size()<<endl;
cout<<"I will display them"<<endl;
multisetit = multiset_person.begin();

while(multisetit!=multiset_person.end())
{(*multisetit++).display(); cout<<"-------"<<endl;}
/////////////////////////////////////////////////////////////
//it is a good idea to use list in inserting and deleting from the middle
//where list is faster than vector and assciative you don't need to swap any elements
list<person*>perslist (persons,persons+6);
list<person*>::iterator perslistit;
person* ptr=new person ("you","ahmed",11);
perslist.push_back(ptr);
ptr=new person("you","ahmed",10);
perslist.push_back(ptr);
//display persons on the screen
perslistit=perslist.begin();
while(perslistit!=perslist.end())
{(*perslistit++)->display();}
//now there are 3 persons has the same name with different phones numbers
perslistit=find(perslist.begin(),perslist.end(),ptr);
cout<<"******************************"<<endl;
if(perslistit!=perslist.end())
{
cout<<"persons are or is : \n";
do
{
(*perslistit++)->display();
perslistit=find(perslistit,perslist.end(),ptr);
}while(perslistit!=perslist.end());
}//end of if
////////////////////////
}
////////////////////////////////////////////////////////////////////////////
//in this part we will take about funtion objects and their meaning
//airtim class definition
class airtim{
private:
int hr;
int mn;
public:
airtim():hr(0),mn(0)
//no argument constructor
{}
airtim(int h , int m):hr(h),mn(m)
//two argument constructor
{}
void display()const
//display the air time
{cout<<hr<<" : "<<mn<<endl;}

void getairtime()
//get air time from the user
{char c; cin>>hr>>c>>mn;}
//overload operators
//+ operator
airtim operator + (const airtim& a) const
{
int temhr=hr+a.hr;
int temmn=mn+a.mn;
if(temmn>=60)
{temhr++; temmn-=60; }
return airtim(temhr,temmn);
}
// - operator
airtim operator - (const airtim& a) const
{
int temhr=(hr>= a.hr)? (hr-a.hr):(a.hr-hr);
int temmn;
if(temhr>=a.hr)
{temmn = (temmn>a.mn)? (temmn-a.mn): (a.mn-temmn);}
else
{temmn = (temmn<a.mn)? (-temmn+a.mn): (60-temmn+a.mn);}


return airtim(temhr,temmn);
}
//== operator
bool operator == (const airtim& a)const
{return (a.hr==hr && a.mn == mn);}
// != operator
bool operator != (const airtim& a) const
{ return !(a==*this);}
//< opertor
bool operator < (const airtim& a) const
{ return (hr<a.hr || ( hr == a.hr && mn<a.mn));}
//>operator
bool operator > (const airtim& a) const
{ return ( !(*this == a) && !(*this<a) );}
};
//function object
void function_object()
{
char answer;
airtim tem,sum;
list<airtim> list_air_time;
do{
tem.getairtime();
list_air_time.push_back(tem);
cout<<"do you want to enter anthor time air [y/n]\n";
cin>>answer;
}while(answer=='y');
//accumulate the air times
sum = accumulate(list_air_time.begin(),list_air_time.end(),airtim(0,0),plus<airtim>());
cout<<"sum = :"<<endl;
sum.display();
}


//main functions
int main()
{


//features_of_vectors();
//features_of_lists();
//features_of_queues();
//iterator_session();
//associative_containers();
//function_object();
return 0;
}
