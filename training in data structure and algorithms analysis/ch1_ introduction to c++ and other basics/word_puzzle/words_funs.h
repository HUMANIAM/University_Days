#ifndef WORDS_FUNS_H_INCLUDED
#define WORDS_FUNS_H_INCLUDED

#include <iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

struct position{
int r;
int c;
string directon;
};

void search_values();
int num_of_ones(int);
void display_position(const position&  , const position&  , const char* );
void get_vertical_word(char* , int );
void display_onedigit(int );
void display_float(double );
void reverse_cstring(char* );
int substr_str (const char* , const char* );
void horizontal_search (const char* , position& , position&);
void  vertical_search  (const char* , position& , position&);
void  diagonal_search  (const char* , position& , position&);

#endif // WORDS_FUNS_H_INCLUDED
