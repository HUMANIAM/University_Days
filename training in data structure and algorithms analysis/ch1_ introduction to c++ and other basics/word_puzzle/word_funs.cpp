#include "words_funs.h""
#define ROWS_PUZZ 4
#define WD_NUM 5

const char* words[5]={"this","that","is","at","two"};
const char* puzzles_words[4]={"this","wats","oahg","fgdt"};

///////////////////////////////////////////
//number of ones
int num_of_ones(int n)
{
static int no=0;
if(n==0)   //base case
{return no;}

else{
if(n%2==1)
{ no++;}
no =num_of_ones(n/2); return no;
}0
return no;
}
/////////////////////////////////////////
//display result of search
void display_position(const position& from , const position& to , const char* word)
{

cout<<"I find "<<word<<" word in";
cout<<" position ("<<from.r<<","<<from.c<<")";

cout<<"to position ("<<to.r<<","<<to.c<<")";

cout<<"from "<<from.directon<<endl;

}
//////////////////////////////////////////////
//search for values in the word puzzle
void search_values()
{

position from,to;
for(int i=0;i<5;i++)
{
//search in diagnal word
diagonal_search(words[i], from,to);
if(from.c!=-1)
{ display_position(from,to,words[i]);}
else
{
//search in vertical words
vertical_search(words[i], from,to);
if(from.c!=-1)
{display_position(from,to,words[i]);}
else
{
//search in horizontal words
horizontal_search(words[i], from,to);
if(from.c!=-1)
{display_position(from,to,words[i]);}
else
{cout<<"this word isn't in the word_puzzle\n";}
}
}//end the outer else
}
}
///////////////////////////////////////////////////
//display integer values digit by digit
void display_onedigit(int n)
{
if(n<0) {n*=-1; cout<<'-';}

if(n/10 != 0)
display_onedigit(n/10);

cout<<n%10;

}
/////////////////////////////////////////
//display float numbers
void display_float(double n)
{
//check if n is less than 0
if(n<0) {n*=-1; cout<<'-';}

int nn = int(n);        //get interger value
float par =n-nn;        //get float value
display_onedigit(nn);   //display integer digit by digit
cout<<'.';

double z;
int y;

if(int(par*10)==0)
{ cout<<0; return; }
else
{
while(( y=(int(z=par*10)) )!=0)
{ cout<<y;  par=z-int(z); }
}
}
///////////////////////////////////////////////////
//reverse cstring
void reverse_cstring(char* str)
{
int len=strlen(str);
char* endstr = str+len-1;
char* startstr = str;

for(int i=0; i<len/2;i++)
{ swap(*(endstr-i),*(startstr+i)); }
}

//////////////////////////////////////////////////////////
//this function check if str2 is substring from str1
int substr_str (const char* str , const char* sub_str)
{

const char* str1 = str;
const char* str2 = sub_str;
//specific case
if(strlen(sub_str)>strlen(str))
return -1;
//go through characters
while(*str1!='\0' && *str2 != '\0')
{
if(*str1 == *str2)
{
++str2; ++str1;
//cout<<"hello world"<<endl;
while( *(str1) != '\0' && *(str2) != '\0')
{
if(*str1 != *str2)
{ str2=sub_str; break;}

str2++; str1++;    //increment str1 and str2
}//end of while
}//end if
//check while because it may mach in inner while
if(*(str1) == '\0')
{ str1++; break; }

str1++;
}//end of outer while

if(*str2 == '\0')
{ return (str1 - strlen(sub_str) ) - str;}
else
return -1;
}
//////////////////////////////////////////////
//horizontal_search() function
void horizontal_search (const char* word , position& from , position& to)
{
int len=strlen(word);
//go through words in puzzles
for(int i=0; i<ROWS_PUZZ ; i++)
{
char wrd [5];
strcpy(wrd,puzzles_words[i]);
//find word from left to right
int col = substr_str(wrd,word);
if(col != -1)
{

from.r =i+1 ;  from.c=col;
to.r=i+1;      to.c = from.c+len-1;
from.directon = to.directon="left to right";
return;
}
//reverse the word
reverse_cstring(wrd);
//find from right to left
 col = substr_str(wrd,word);
if(col != -1)
{
cout<<col<<endl;
int len_puzzle=strlen(puzzles_words[i]);
from.r =i+1 ;   from.c=len_puzzle-col+1;
to.r=i+1;      to.c = from.c-len+1;
from.directon = to.directon="right to left"; return;
}
}
from.c=-1;
return;
}
////////////////////////////////////////////
//get vertical word
void get_vertical_word(char* , int )
{}
///////////////////////////////
//vertical function

void vertical_search (const char* word , position& from , position& to)
{
int len =strlen(word);
char temp[5];
//go through all the vertical words
for(int c=0;c<5;c++)
{
//get the vertical word number c+1
int cn=0;
for(int r=0;r<4;r++)
{
if(c<strlen(puzzles_words[r]))
{ temp[cn++]=puzzles_words[r][c];  }
}
temp[cn]='\0';
/////////////////////////
//check if the word in this vertical word
char wrd [5];
strcpy(wrd,temp);
//find word from left to right
int col = substr_str(wrd,word);

if(col != -1)
{

from.r =col ;      from.c=c+1;
to.r=col+len-1;     to.c=c+1;
from.directon = to.directon="up to down";
 return;
}
//reverse the word
reverse_cstring(wrd);
//find from right to left
 col = substr_str(wrd,word);
if(col != -1)
{
from.r =cn-col+1 ;  from.c=c+1;
to.r =from.r-len+1;  to.c=c+1;
from.directon = to.directon="down to up";
return;
}
}

from.c=-1;
return;
}
////////////////////////////////////////
//diagonal_search
void diagonal_search(const char* word , position& from , position& to)
{
int len =strlen(word);
char temp[5];
int cn=0;
//get the dignal word number
///////////////////
for(int cr=0;cr<5;cr++)
{
if(puzzles_words[cr][cr] != '\0')
{ temp[cn++]=puzzles_words[cr][cr]; }
}
temp[cn]='\0';
//////////////////
//check if the word in this diagnal word
char wrd [5];
strcpy(wrd,temp);

//find word from left to right
int col = substr_str(wrd,word);

if(col != -1)
{

from.r =col ;      from.c=col;
to.r=col+len-1;     to.c=to.r;
from.directon = to.directon="left to right";
 return;
}
//reverse the word
reverse_cstring(wrd);
//find from right to left
 col = substr_str(wrd,word);
if(col != -1)
{
from.r =cn-col+1 ;  from.c=from.r;
to.r =from.r-len+1;  to.c=to.r;
from.directon = to.directon="right to left";
return;
}

from.c=-1;
return;
}
