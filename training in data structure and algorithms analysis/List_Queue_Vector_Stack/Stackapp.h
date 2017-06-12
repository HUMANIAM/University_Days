#ifndef STACKAPP_H_INCLUDED
#define STACKAPP_H_INCLUDED

#include<string>
#include<stack>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
//                              Balancing symbols

//this funciton check that every open char has its closed char
class BlancingSymbols
{
private:
string s;

public:
BlancingSymbols(string str):s(str)
{}

//this funciotn push characters into the stack
bool Testexpr()
{
stack<char>Stack;
for (int i=0;i<s.length();i++)
{

if(s[i]=='}')
{
bool state = checkexpre(Stack,'{');
if(!state)
return false;
}

else if (s[i]==')')
{
bool state = checkexpre(Stack,'(');
if(!state)
return false;
}

else if (s[i]==']')
{
bool state = checkexpre(Stack,'[');
if(!state)
return false;
}
else
{
Stack.push(s[i]);
}
}//end for

return Nospecificchar(Stack);
}

//there is no specic character on the stack ( { [
bool Nospecificchar(stack<char>& Stack)
{

char x=Stack.top();
while(x != '(' && x != '[' && x != '{' )
{
Stack.pop();

if(!Stack.empty())
x=Stack.top();

else
break;
}

return Stack.empty();
}

bool checkexpre(stack<char>& Stack,char c)
{
if(Stack.empty())
return false;

while( ! Stack.empty())
{
if(Stack.top() != c )
Stack.pop();
else
break;
}

if(! Stack.empty())
{
Stack.pop();
return true;
}

else
return false;
}
};

//###################################################################
                               //Evaluation of postfix expression
/*
float Evalpostfixexp(queue<char*>& qu)
{
stack<char*>st;

while(!qu.empty())
{
char* val = qu.front();
char op=val[0];
qu.pop();

if( op !='*' && op !='+' &&op !='-' &&op !='/' )
{ st.push(val); }

else
{
float val0 = convettofloat(st.top());
st.pop();

float val1 = convettofloat(st.top());
st.pop();

switch(op)
{
case '+': st.push(converttochar*(val0+val1));
break;
case '-': st.push(converttochar*(val0-val1));
break;
case '*': st.push(converttochar*(val0*val1));
break;
case '/': st.push(converttochar*(val0/val1));
break;
default:
cout<<"unkown operator"<<endl;
break;
}//end of swich
}//end of else
}//end of while
return converttofloat(st.top());
}//end of evalpostfix
//#####################################################################
                              //convertion from infix to postfix
class InfixTopostfix
{
private:
enum{Maxlen=100};
char exp[Maxlen];
stack<char> st;
queue<char*>qu;

public:
//on argument constructor
InfixTopostfix(char * s)
{  strcpy(exp,s);  }
//convert infix to postfix
bool convert()
{
char * ptr=exp;

while(*ptr !='\0')
{
char ch = *ptr;
//the reading value may be number (f,i) or operator or  ( or )
if(isdigit(ch))
{
float num = strtof(ptr,&ptr);
//convert num to cstring then enqueue it into the queue
//char* val=
qu.push(val);
}
//it may be operator
else if (ch=='+' || ch=='-' ||ch=='/' ||ch=='*' )
{
char c=st.top();
char cc[2]; cc[0]=c; cc[1]='\0';

if((ch=='/' || ch=='*') && (c=='+' || c=='-' || c=='('))
{
st.push(ch);
ptr++;
}

else if((ch=='/' || ch=='*') && (c=='*' || c=='/'))
{
qu.push(cc);
st.pop();
st.push(ch);
ptr++;
}

else if ((ch=='+' || ch=='-') && (c != '('))
{
qu.push(cc);
st.pop();
st.push(ch);
ptr++;
}
}

else if (ch=='(')
{
st.push(ch);
ptr++;
}

else if (ch==')')
{
//read from the stack untill reach (
while(c!='(')
{
qu.push(cc);
st.pop();

if(!st.empty())
{c=st.top();
cc[0]=c; cc[1]='\0';}

else
break;
}

if(st.empty() )
return false;
else
st.pop();

ptr++;
}

else
{cout<<ch<<" invalid operator\n";
 ptr++;}
}//end of while

return emptythestack(qu,st);
}//end of convert function

bool emptythestack(queue<char*>& qu, stack<char>& st)
{
char c;
char cc[2];
while(!st.empty())
{
c=st.top();
if(c=='(')
{
cout<<"not balanced paranthesis"<<endl;
return false;
}
//format operator to char * to push it into the queue
cc[0]=c; cc[1]='\0';
qu.push(cc);
st.pop();
}
return true;

}//end of emptythestack

};//end of Infixtoposfix

*/


#endif // STACKAPP_H_INCLUDED
