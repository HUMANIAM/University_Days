#include <iostream>
#include "PlayFair.h"
using namespace std;
//const string ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
    string nplaintxt = "";
    string plaintxt = "hello world,,";
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
    cout<<nplaintxt;
    return 0;
}

