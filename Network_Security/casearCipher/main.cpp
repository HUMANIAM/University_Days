#include <iostream>
#include "Substitution_Cipher.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc > 2){
        string options = string(argv[1]);
        if(options == "-e")
            cout<<encrypt_with_ceaser(argv[2]);
        else if(options == "-d")
            cout<<decrypt_with_ceaser(argv[2]);
        else if(options == "-dbf")
            cout<<caeser_bruteForce_attack(argv[2]);
        else if(options == "-dfa")
            cout<<caser_frequencyAnalysis_attack(argv[2]);
        else
            cout<<"Please, path correct options (-d, -e, -dbf, -dfa)\n";
    }else{
        cout<<"Please, write command right.";
    }
    return 0;
}
