
#ifndef LEX
#define LEX
#include<stdio.h>
#include <stdlib.h>
#include <vector>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include"LEX.h"

using namespace std;

char Type[7][10]={"int","double","long","float","char","short","void"};
char keyword [14][10]={"printf","scanf","if","else","do","while","for","main","struct","enum","union","include","define","return"};
char heads[5][19]={"<stdlib.h>","<stdio.h>","<cmaths>","<string.h>","<ctype.h>"};
char operators[12]="+-/*=<>!&|";
char symbols[16]=" \t\n,;&(){}/[]#\"";
vector<string> TOKENS;
  char ch;
  int i=0,j;
   char temp[100];
   FILE *source;

   void check_keyword_identif()
   {

   //check if str is string or no
   //check if data type
       for( i=0;i<7;i++)
        {
            if(strcmp(temp,Type[i])==0)
        {TOKENS.push_back("DT"); return; }
        }
       //check if isn't data tupe
       for(int i=0;i<14;i++)
       {
            string Tok="Key_";
           if(strcmp(temp,keyword[i])==0)
            {
           if(strcmp(temp,"define")==0)
           {
              Tok+=temp;
             TOKENS.push_back(Tok);
             return ;
           }

           else if(strcmp(temp,"include")==0)
            {
             Tok+=temp;
             TOKENS.push_back(Tok);

             string head;
             head+=ch;
           while((ch=fgetc(source))!='>'){head+=ch;}
           head+=ch;
           ch=fgetc(source);
          //check if this header is okey
           for(i=0;i<5;i++)
           if(head==heads[i])
           TOKENS.push_back("Header");
           return;
         }
         else {Tok+=temp;  TOKENS.push_back(Tok); return;}
     }
       }
       TOKENS.push_back("ID");
       return;
   }


//check operators
void check_operator()
{
char c=fgetc(source);
    //relational operators
if(ch=='>'||ch=='<')
{

if(c=='=')
{
    TOKENS.push_back("Rop");
     ch=fgetc(source); return;}
else {  TOKENS.push_back("Rop"); ch=c; return;}
}
//assignment operator
else if(ch=='=' )
{
if(c=='='){ TOKENS.push_back("Rop");  ch=fgetc(source);  return;}
else {  TOKENS.push_back("Assign"); ch=c;  return;}
}
//---
else if(c=='!' )
{
   if(ch=='='){  TOKENS.push_back("Rop"); ch=fgetc(source);  return;}
else { TOKENS.push_back("Lop"); ch=c;  return;}
}
//logical operator
 if((ch=='|'||ch=='&')&&(c=='|'||c=='&'))
{
     TOKENS.push_back("Lop");
 ch=fgetc(source);    return;
 }


    //arithmetic operators
if(ch=='+'||ch=='-')
{
    if(c=='-' || c=='+')
     {TOKENS.push_back("op");  ch=fgetc(source);   return;}
     else if(c=='=')
     { TOKENS.push_back("Assign"); ch=fgetc(source);    return;}
     else {}
}
if(ch=='/'||ch=='*')
{
   if(c=='=')
     {TOKENS.push_back("Assign"); ch=fgetc(source);    return;}
     else { TOKENS.push_back("op");   ch=c;  return;}
}
TOKENS.push_back("op");
return;
}
int check_symbol()
{

    char c=fgetc(source);
    if(ch=='/')
    {
        if( c=='/'){
        while (fgetc(source)!='\n');
        ch=fgetc(source);
        return 0;
        }
        else if(c=='*')
            {

          while (fgetc(source)!='/');
          ch=fgetc(source);
          return 0;
    }
        else return 1;
    }


    else if(ch=='\"')
    {
        string VAL;
     while (((ch=fgetc(source))!='\"') && ch!=EOF) {VAL+=ch;}

        ch=fgetc(source);
        TOKENS.push_back("Val");
        return 0;
    }

    else if(ch=='\n')
    {

       string tok="End_lin";
        TOKENS.push_back(tok);
        ch=c;
        return 0;
    }
    else if(ch!=' ' && ch!='\t')
        {   string tok="Sym_"; tok+=ch; ch=c;  TOKENS.push_back(tok); return 0;}
    return 1;
}
void read_iden_key(int iden)
{
    while (isalpha(ch) || isdigit(ch) || ch=='_')
       {
       temp[i++]=ch;
       ch=fgetc(source);
       if((ch=='_' || isdigit(ch)) && (iden==0) ){iden=1;}
       }
       temp[i]='\0';

       return;
}

void LEXAL ()
{

 source = fopen("code.txt","r");

      ch=fgetc(source);

  while(ch!=EOF)
   {
    while(ch=='\t' || ch=='\n'|| ch==' ')
        {
            ch=fgetc(source);
        }

       //if token is number
	if(ch == '.' || ch == '-' || isdigit(ch))
	{
	while(ch == '.' || ch == '-' || isdigit(ch))
	{
	temp[i++]=ch;
    ch=fgetc(source);
	}
	temp[i] = '\0';
	i = 0 ;
	        TOKENS.push_back("Val");
	}
	//if token is keyword or identifier
     else if(isalpha(ch))
       {
           int iden=0;
       while (isalpha(ch) || isdigit(ch) || ch=='_')
     read_iden_key(iden);

      if(iden==0) check_keyword_identif();
      else TOKENS.push_back("ID");
       i=0;


       }
//symbol or operator
      else
       {


          int op=1;

    //check if symbol
 	 for(j=0;j<16;j++)
    {  if(ch==symbols[j]) {op=check_symbol(); break;}  }
    // check if operator
       if(op==1)
         {
           for(j=0;j<12;j++)
        {
         if(ch==operators[j])
        {check_operator(); op=1; break;}

        }
         }
    }
}
fclose(source);

}
#endif // LEX
