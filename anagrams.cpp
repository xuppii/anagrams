#include <iostream>
#include <cctype>
#include <hunspell.hxx>

using namespace std;

int main(){
    char c;
    Hunspell hunspell("/usr/share/hunspell/en_US.aff", "/usr/share/hunspell/en_US.dic");
    string inputString;
    cout << "enter word: ";
    // while(true){
    //     cout << "enter character" << endl;
    //     cin >> c;
    //     if(isdigit(c))
    //     {
    //         break;
    //     }
    //     inputString += c;
    // }
    cin >> inputString;
    //cout << inputString << endl;
    if (hunspell.spell(inputString) && (inputString.length() > 2)) {
        cout << inputString << " is a word" << endl;
    } else {
       cout << inputString << " is not a word" << endl;
    }
    return 0;
}