#include<stdio.h>
#include <stdlib.h>
#include <vector>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include"LEX.h"
#include"PARSE_FN.h"
using namespace std;


//vector <string> TOKENS;
vector <string>::iterator index;


//
int main()
{
    LEXAL();
    TOKENS.push_back("ENDTOKENS");
    cout << "Hello world!" << endl;
    index = TOKENS.begin();


while(*index!="ENDTOKENS")
{
     bool s = language();
    if(s)
      cout<<"ok"<<endl;
   else
    {cout<<"NO"<<endl;
    break;}
}

if(*index=="ENDTOKENS")
    cout<<"congratulations!  your code kill lexical stage and parse stage\n"<<endl;
else cout<<"sorry , your code have errors and we will determine them when we have time to do that\n"<<endl;



   // cout<<*index;

    return 0;
}



//function implementation




bool language()
{
    return preprocessor()|| func()||Arth_op()||Decleration()||IF_While()|| prin_scan();
}
//Decleration context free grammer



bool Term(string x )
{
    if(*index == x)
    {
cout<<x<<" true "<<endl;
        index++;
        cout<<"++++++++++++"<<endl;
        return true;

    }
    else
    {
        cout<<"++++++++++++"<<endl;
         cout<<*index<<" from vector"<<endl;
          cout<<x<<" grammer "<<endl;
           cout<<"++++++++++++"<<endl;
        return false;
    }

}
//printf
bool prin_scan()
{
    return prin()|scan();
}

bool prin()
{
    return Term("Key_printf")&&Term("Sym_(")&& Term("Val")&& ((Term("Sym_,")&&Term("ID"))||true)&&Term("Sym_)")&&Term("Sym_;");
}

bool scan()

{
     return Term("Key_scanf")&&Term("Sym_(")&& Term("Val")&&Term("Sym_,")&& Term("Sym_&")&&Term("ID")&&Term("Sym_)")&&Term("Sym_;");
}

//end of printf
bool PP()
{
    return (Term("op")&&Term("ID")) || (Term("op")&&Term("Val")) || true;
}
bool Q1()
{
    return Term("ID")&& PP()&&Term("Sym_;");
}
bool Q2()
{
    return Term("Val") && PP()&& Term("Sym_;");
}
bool Q()
{
    return Q1()||Q2();
}
bool L1()
{
    return Term("Assign") &&Q();
}
bool L()
{
    return Term("Sym_;") || L1();
}

bool Decleration()
{
    vector <string>::iterator save=index;
    bool s=Term("DT") && Term("ID") && L();
    if(s)
    { return true;}
    else{
            index=save;
            return false;
    }

}

// end of Decleration


// Start of Arth_op



bool X()
{
    return Term("ID")||Term("Val");
}
bool W1()
{
    return Term("op") && X();
}

bool W()
{
    cout<<"iam true from W"<<endl;
    return W1() || MT();
}
bool S()
{
    return Term("ID") || Term("Val");
}
bool Z1()
{
    return Term("op") && S();
}
bool Z()
{
    return Z1() || true;
}
bool F1()
{

    return Term("ID")&& W() && Term("Sym_;");
}
bool F2()
{
    return Term("Val")&&Z()&& Term("Sym_;");
}
bool F5()
{
    return Term("Val")&&Term("Sym_;");
}
bool F6()
{
    return Term("ID") && Term("Sym_;");
}
bool F()
{
    return F1() ||F2();
}
bool Arth_op()
{
    return Term("ID")&&Term("Assign")&& F();
}

// End of arth op;


//start of preprocessor


bool p1()
{
    return Term("Key_define") && Term("ID") && Term ("Val");
}
bool p2()
{
    return Term("Key_include") && Term("Header");
}

bool p()
{
    return p1() || p2();
}
bool preprocessor()
{

    return Term("Sym_#") && p();
}


// end of preprocessor

// start of conditions

bool HH()
{
    return true;
}
bool N()
{
    return Term("Val") || Term("ID") ;
}
bool condition()
{
    return (Term("ID") && Term("Rop") && N())|| HH() ;
}

// End of conditions




// start of if and while

bool IF_while1()
{
    return Term("Key_if") && Term("Sym_(") && M() && K() && Term("Key_else")&&Term("Sym_{") && K()&& Term("Sym_}");
}

bool IF_While2()
{
    return Term("Key_while") && Term("Sym_(") && M() && K() ;
}
bool K()
{
    cout<<"iam "<<*index<<"from k"<<endl;
    return IF_While()||Arth_op()||Decleration()||prin_scan()||Term("Sym_}")||K_else() ;
}

bool K_else()
{
    return Term("Key_else") && Term("Sym_{")&&K();
}
bool MT()
{
    return true;
}
bool M()
{
    cout<<"i am m"<<endl;
    return M1() || M2();
}
bool M1()
{
    cout<<"i am m1"<<endl;
    return condition() && Term("Sym_)") &&Term("Sym_{") ;
}
bool M2()
{
    cout<<"i am m2"<<endl;
    return Term("Val") && Term("Sym_)") &&Term("Sym_{") ;
}
bool IF_While()
{
    return IF_while1() || IF_While2();
}



// end of if and while


// start of FUnction decleration
bool XF1()
{
    return Term("Key_main") &&Fun_args();
}
bool XF2()
{
    return Term("ID") &&Fun_args();
}

bool XF()
{
    return XF1() || XF2();
}

    bool func ()
    {
      vector <string>::iterator save=index;
    bool s=Term("DT") &&XF();
    if(s)
    { return true;}
    else{
            index=save;
            return false;
    }

    }

// End of function decleration

// Start of function args
/*
bool G1()
{
    cout<<"iam from G1"<<endl;
    return K()&& G1();
}
*/
bool G()
{
    cout<<"iam G()"<<endl;
   //return (K()&& G())|| MT();
   bool s=K();
   if(s==false)
    {
        return false;

    }
    else
    {
        if(*index=="ENDTOKENS")
            return true;
           else G();

    }

}
bool BF1(){

return Term("Sym_)") &&Term("Sym_{") && G()  ;

}
bool BF2()
{
    return Term("DT") && Term("ID") && CF()&& BF1();
}

bool CF()
{
    return CF2() || CF1();
}
bool CF1()
{
    cout <<"iam in cf1"<<endl;
    return true;
}
bool CF2()
{
    return Term("Sym_,") &&Term("DT") && Term("ID") && CF();
}
bool BF()
{
    return BF1()||BF2();
}
bool Fun_args()
{
    return Term("Sym_(") &&BF();
}


