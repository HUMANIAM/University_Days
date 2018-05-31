#ifndef SUBSTITUTION_CIPHER_H_INCLUDED
#define SUBSTITUTION_CIPHER_H_INCLUDED
#include <string>
#include <stdlib.h>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

const int KEY = rand()%26;
const int ALPHASIZE = 26;
const string ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
stringstream ss;

//ceaser cipher for encryption
string encrypt_with_ceaser(const string& plaintxt){
    string encryptedMsg = "";
    string ss = plaintxt;
    transform(ss.begin(), ss.end(), ss.begin(), ::tolower);

    for(size_t i=0; i<ss.size(); i++){
        if(ss[i] == ' '){
            encryptedMsg.append(1, ss[i]);
        }else{
            size_t j = ((ss[i]-'a') + KEY)%26;
            encryptedMsg.append(1, ALPHABETS[j]);
        }
    }
    return encryptedMsg;
}

//decryption of cipher text that encrypted with ceaser/additive cipher
string decrypt_with_ceaser(const string& ciphertxt, int k=KEY){
    string decryptedMsg = "";

     for(size_t i=0; i<ciphertxt.size(); i++){
        if(ciphertxt[i] == ' '){
            decryptedMsg.append(1, ciphertxt[i]);
        }else{
            int j = ((ciphertxt[i]-'A') - k)%26;
            j<0? j= ALPHASIZE + j : false;
            decryptedMsg.append(1, tolower(ALPHABETS[j]));
        }
    }
    return decryptedMsg;
}

//cryptanalysis of caeser cipher using brute force attack
string caeser_bruteForce_attack(const string& ciphertxt){
    string bfresult = "";

    for(int i=1; i<ALPHASIZE; i++){
        ss<<i;
        bfresult += "Key = "+ss.str()+"\n"+decrypt_with_ceaser(ciphertxt, i)+"\n";
        ss.clear();
        ss.str(std::string());
    }
    return bfresult;
}

/**
frequency analysis is another method beside brute force for decrypting intercept cipher text
- we evaluate the frequency of every char in the cipher text then find the char with max occurrence
- map this char to one of the max occurrence chars in English language say (e, t, a, ..).
- evaluate the pairs chars to see which one of them we will choose.
- we find the key then decrypt the cipher msg

problems:
*cipher msg must be long to make meaningful frequency analysis
*letter frequencies of a text is the subject matter of the text. say cipher text about cat then c char will mislead us if
we map it to e, t or e
*/
string caser_frequencyAnalysis_attack(const string& ciphertxt){
    if(ciphertxt.size() == 0) return "";

    map<char, int> char_freq;
    string decMsg = "";

    //histogram of letters
    for(size_t i=0; i<ciphertxt.size(); i++){
        char c = ciphertxt[i];
        if(c != ' ' && char_freq.count(c)>0)
            char_freq[c]++;
        else if(c!=' ')
            char_freq[c] = 1;
    }

    //letter with the max occurrence in the cipher text
    int maxv = -1;
    char maxc;
    for(auto it=char_freq.begin(); it != char_freq.end(); it++)
        if(it->second > maxv){
            maxv = it->second;
            maxc = it->first;
        }

    //here we can find the histogram of pairs of letters to help us in mapping max letter in cipher text
    //to one of max letter in English. But we assume that max letter in cipher text will mapped into e

    int w = tolower(maxc) - 'e';
    if(w<0) w += ALPHASIZE;
    cout<<w<<endl;
    return decrypt_with_ceaser(ciphertxt, w);
}


#endif // SUBSTITUTION_CIPHER_H_INCLUDED
