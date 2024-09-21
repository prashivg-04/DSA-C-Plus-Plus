//Convert to UpperCase

#include<iostream>
using namespace std;

void toUppercase(char word[]) {
    for(int i = 0; i<strlen(word); i++) {
        char ch = word[i];
        if(ch >= 'A' && ch <= 'Z') {
            continue;
        } else {
            word[i] = ch - 'a' + 'A';
        }
    }

}

int main() {
    char word[] = "ApPle";
    toUppercase(word);
    cout << word << endl;
    return 0;
}