#include <iostream>
#include <cstring>
#include<typeinfo>
//for strcpy(), etc
using namespace std;
////////////////////////////////////////////////////////////////
class Base{
virtual void vertfunc(){}
};
class Derv1: virtual public Base
{};
class Derv2: virtual public Base
{};
//this function check the type of current derived class 1 or 2
bool IsDerv1(Base * Derv)
{
Derv1* d1;
cout<<d1<<"         "<<dynamic_cast<Derv1*>(Derv)<<endl;
if(d1=dynamic_cast<Derv1*>(Derv))
return true;
else
return false;
}
int main()
{

Base* b=new Derv1;
cout<<typeid(*b).name()<<endl;
 b=new Derv2;
cout<<typeid(*b).name();
return 0;
}

//Good virtual fns ,class and static fns ,feilds and freind classes and fns and copy constructor and assignment operator overloading
//in this chapter we have learned virtual functions(concrete and pure or abstract) and also virtual classes
//**abstract virtual function use to create abstract base class use to derive only other classes from it where these
//virtual function must be redfine in every derived class
//***concrete virtual class used to deal with the derived classes from one base class by only one pointer that points to the
//the base class and then change in the runtime (polymorphism) where we can check the type of the pointer by using
//derv=dynamic_cast<derv *>(base *) from that we can know where now the pointer points
//and alse we can use the typeid(base*).name() to know the name of the current obeject that the pointer points to it
/*also we study the freind class and also the friend class where when we define a function or a class in anthor class
that it is freind this freind class or function can access the private and protected data in this class*/
/*we learn about the static feild as common variable among derived classes from one base class or it also a common variable
among various objects from the class , static function this is function can be called through the class itself where it is
exists unless you don't create any other objects from this class*/
/* overloading copy constructor and the assignment operator to avoid coping objects to assignment or casting
we do that if we want to track the number of objects that have been created from a classes and as a way to save resources
(memory)//
the best example I have seen is the string class where we create a new class has a pointer to the string and has the
count of string objects that points to the same str instead at every time create new place for the same string . */
