#ifndef PLAYFAIR_H_INCLUDED
#define PLAYFAIR_H_INCLUDED
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const int ALPHASIZE = 26;
const string ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char KEY [5][5];

void generateRandom_squareKey(){
}

void generateKey(const string& key){
}

void preparePlainText(string& plaintxt){
    string nplaintxt = "";
    size_t k = 0;
    transform(plaintxt.begin(), plaintxt.end(), plaintxt.begin(), ::toupper);

    for(size_t i=0; i<plaintxt.size(); i++){
        char c = plaintxt[i];

        if(ALPHABETS.find(c) != string::npos){
            if(k!=0 && nplaintxt[k-1] == c)
                nplaintxt.append(1, 'X');
            else
                nplaintxt.append(1, c);
            k++;
        }
    }
    if(k%2==1) nplaintxt.append(1, 'X');        //ensure size of text is even
    plaintxt = nplaintxt;
}


string playFair_encrypt(const string& plaintxt, const string& key=""){
    if(plaintxt.size()==0) return "";

    if(key.size() == 0)
        generateRandom_squareKey();
    else
        generateKey(key);

    //prepare plain text for PlayFair cipher
    /**
     1-remove non alphabetic letters
     2-replace the second letter of every duplicate letter with letter
     3-if number of letters is odd add x at the end of the plain text
     4-divide the new plain text into pairs of letters then apply playFair rules
    */
    preparePlainText(plaintxt);

    //apply rules of playFair to encrypt plain text
    string encrypted_str = "";
    for(size_t i=0; i<plaintxt.size(); i+=2){
        char c1 = plaintxt[i];
        char c2 = plaintxt[i+1];

        //find row and column for c1 and c2


        //apply rules of PlayFair

    }
}

#endif // PLAYFAIR_H_INCLUDED
