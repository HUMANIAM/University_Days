#include <iostream>
#include <cstring>
#include<cstdlib>
#include<cstdio>
#include<typeinfo>
//for strlen(), etc
using namespace std;

const int MAX = 40;

////////////////////////////////////////////////////////////////
class Token
{
public:
virtual float getNumber()=0;
virtual char getCharacter()=0;
};
////////////////////////////////////////////////////////////////////////////
class Character: public Token
//expression class
{
private:
char oper;
public:
// one argument constructor
Character(char c): oper(c){}
//defintion of getNumber to avoiding abstraction
float getNumber(){}
//getCharacter funciton
char getCharacter()
{return oper;}
};

///////////////////////////////////////////////////////////////////////////////
class Number: public Token{
//Number class
private:
float f;
public:
//one argument constructor
Number(float ff): f(ff){}
//getnumber function
float getNumber()
{return f;}
//get operaotor defineition
char getCharacter()
{}
};
////////////////////////////////////////////////////////////////////////////////////
//pointer to the base class can hold derived
//classes from him so this array can hold float and chars at the same time
class Stack
{
private:
Token * ptr[MAX];
int top;
public:
//no argument constructor
Stack():top(0){}
//void push funciton
void push(Token * T)
{ptr[++top]=T;}
//pop function return the current value in the ptr
Token * pop()
{return ptr[top--];}
int gettop()
{return top;}
//read the current value
Token* readval()
{return ptr[top];}
};
////////////////////////////////////////////////////////////////////////////////////
//class expression
class express
{

private:
Stack s;
char str[MAX];
public:
//one argument constructor
express(char *s)
{strcpy(str,s); }
//declerator of parse funciton
void parse();
//declerator of solver function
float solve();

};
//-^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//             PARSING
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void express::parse()
//add items to stack
{
//pointer End used to float nums from the string
char * End=str;
Token* lastval;
//last value
Token* lastop;
//last Character
while(*End!='\0')
{
char ch = *End;
if(isdigit(ch))
{
//num hold the value of the float num
float num=strtof(End,&End);
//  n points to the object that has the float number
Number * n=new Number(num);
//push the pointer to float into the stack
s.push(n);

}
//get the Character
else if (ch=='*' || ch=='+' || ch=='/' || ch=='-')
{
End++;
//check the Character
if( s.gettop() == 1 || s.gettop() == 2)
{s.push(new Character (ch)); }
//else we need check the last Character
else
{
//get previous digit
 lastval= s.pop();
//get the previous Character
lastop = s.pop();
//last character
char c =lastop->getCharacter();
//last character is (
if(c=='(')
{
//restore last two pops
s.push(lastop);
s.push(lastval);
}
//if the current op is * or / and the previous is + or - we push all again
//then push the current Character
else if( (ch=='*' || ch=='/') && (c=='+' || c=='-') )
{
//restore last two pops
s.push(lastop);
s.push(lastval);
}
else
//in all other cases
{

float prelastval=s.pop()->getNumber();
float     lf    =lastval->getNumber();
//calculate the last operation the push it
//then push the new operator
if(c=='+')
{s.push(new Number(prelastval+lf));}

else if(c=='-')
{s.push(new Number(prelastval-lf));}

else if(c=='/')
{s.push(new Number(prelastval/lf));}

else
{s.push(new Number(prelastval*lf));}

}
s.push(new Character(ch));
}
}//end check the Character

else if(ch=='(')
{ s.push(new Character(ch)); End++;  }

else if(ch==')')
{  float f=solve();   End++; }

else
{
cout<<"invaild character"<<ch<<endl;
exit(1);
} //end of nothing of others
} //end of string
} //end parse()

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//            SOLVING
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
float express::solve()
//remove items from stack
{
//go through the stack to get the final result
while(s.gettop() > 1)
{

Token* lval = s.pop();  //pointer the last value object
//get previous value
char c=s.pop()->getCharacter();

//check if c is ( no an operator
if(c=='(')
{  s.push(lval);  return 1.1 ; } // return this value because function must retun float no
else
{
float lastval = lval->getNumber();
float llvalue=s.pop()->getNumber(); //this is the value before the operator
switch( c )
//get previous Character
{
//do operation, push answer
case '+': s.push(new Number(llvalue + lastval)); break;
case '-': s.push( new Number(llvalue - lastval)); break;
case '*': s.push( new Number(llvalue * lastval)); break;
case '/': s.push( new Number(llvalue / lastval)); break;
default: cout << "\nUnknown Character"; exit(1);
} //end switch
}//END else
} //end while

return  s.pop()->getNumber();  //last item on stack is ans
} //end solve()
////////////////////////////////////////////////////////////////

int main()
{
char str[MAX];
cout<<"     Enter your arthimatic operation  \n";
cout<<"     _______________________________  \n\n\n";
cout<<"     ";
cin>>str;
express s(str);
s.parse();
float f=s.solve();
cout<<"\n\n         Answer = "<<f<<endl;
return 0;
}
