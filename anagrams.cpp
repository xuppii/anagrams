#include <iostream>
#include <cctype>
#include <hunspell.hxx>
#include <time.h>
#include <unistd.h>
using namespace std;
int award_points(string);
int validate_word(string);
void print_game_start(char (&arr)[6]);
char calculate_letter( char (&arr)[5][5]);
char calculate_vowel(char (&arr)[5]);
int main(){
    char c;
    char random_letters[6];// = {'a','b','c','d','e','f'};
    int points;
    srand(time(0));

    print_game_start(random_letters);
    for(int i = 0; i < (sizeof(random_letters)/sizeof(char)); i++)
    {
        cout << random_letters[i] << " ";
    }
    cout << endl;
    
    int seconds = 0;
    while (seconds > 0) {
        if(seconds == 15 || seconds == 30){
            std::cout << seconds << " SECONDS LEFT!!! 😱😱😱 " <<  std::endl;
        }
        sleep(1);
        seconds--;
    }
    // while(true){
    //     cout << "enter character" << endl;
    //     cin >> c;
    //     if(isdigit(c))
    //     {
    //         break;
    //     }
    //     inputString += c;
    // }
    // int i = rand() % 26;
    // int j = rand() % 26;
    // char aChar = 'A' + i;
    // cout << i << j << " and " << aChar << endl;
    /*cin >> inputString;
    points = validate_word(inputString);
    cout << "you got " << points << " points." << endl;
    */
    return 0;
}
int validate_word(string inputString){
    Hunspell hunspell("/usr/share/hunspell/en_US.aff", "/usr/share/hunspell/en_US.dic");
    if (hunspell.spell(inputString) && (inputString.length() > 2)) {
        cout << inputString << " is a word 😀." << endl;
        return award_points(inputString);
    } else {
       cout << inputString << " is not a word" << endl;
       return 0;
    }
}
int award_points(string inputString){
    //3 100, 4 400, 5 800, 6 2000
    int array[] = {100,400,800,2000};
    return(array[inputString.length()-3]);
}
void print_game_start(char (&arr)[6])
{
    cout << "ANAGRAMS 🎲😹" << endl << "press any button to start game: ";
    string s;
    if(cin >> s)
    {
        // constants and vowels listed from highest to lowest frequencies
        // groups with higher frequencies have a higher chance to be chosen
        // RTNSL 4 CDPMH 3 GBFYW  2 KVXZJQ 1
        // eaiou
        char consonents[5][5]={{'R','T','N','S','L'}, {'C', 'D', 'P', 'M', 'H'}, {'G', 'B', 'F', 'Y', 'W'}, {'K','V','X','Z','J'},{'Q'}};
        char vowels[] = {'E', 'A', 'I', 'O', 'U'};
        for(int i = 0; i < 2; i++){
            char randomVowel = calculate_vowel(vowels);
            arr[i] = randomVowel;
        }
        for(int i = 2; i < 6; i++ ){
            char randomLetter = calculate_letter(consonents);
            //char randomLetter = 'A' + (rand() % 26);
            arr[i] = randomLetter;
            //cout << randomLetter << " ";
        }
        cout << endl;
    }
}
char calculate_letter(char (&arr)[5][5]){
    int key = rand() % 900;
    if(key < 90){
        key %= 6;
        if(key == 6)
        {
            return arr[4][0];
        }
        else return arr[3][key];
    }
    else if(key < 270){
        key %= 5;
        return arr[2][key];
    }
    else if(key < 540){
        key %= 5;
        return arr[1][key];
    }
    else if(key < 900){
        key %= 5;
        return arr[0][key];
    }
    return 'a';
}
char calculate_vowel(char (&arr)[5]){
    int key = rand() % 5;
    return arr[key];
}