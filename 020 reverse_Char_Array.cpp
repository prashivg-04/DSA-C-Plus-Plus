//Reverse Char array

#include<iostream>
using namespace std;

void reverseArray(char word[]) {
    int start = 0;
    int end = strlen(word) - 1;
    while(start < end) {
        swap(word[start], word[end]);
        start++;
        end--;
    }
}

int main() {
    char word[] = "code";
    reverseArray(word);
    cout << word << endl;
}