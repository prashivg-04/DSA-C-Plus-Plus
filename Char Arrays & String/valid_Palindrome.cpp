//Valid Palindrome 

#include<iostream>
using namespace std;

bool chechPalindrome(char word[]) {
    int start = 0;
    int end = strlen(word) - 1;
    while(start < end) {
        if(word[start] != word[end]) {
            cout << "Not a Palindrome!!" << endl;
            return false;
        }
        start++;
        end--;
    }
    
    cout << "Valid Palindrome!!" << endl;
    return true;
}

int main() {
    char word[] = "racecar";
    chechPalindrome(word);
    return 0;
}