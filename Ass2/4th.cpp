#include<iostream>
#include<string>
using namespace std;

void Concat(string str1, string str2) {
    //Write a program to concatenate one string to another string.
    string result = str1 + str2;
    cout << "Concatenated string: " << result << endl;
}

void Rev(string str) {
    // Write a program to reverse a string.
    string result = str;
    int n = result.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = result[i];
        result[i] = result[n - i - 1];
        result[n - i - 1] = temp;
    }
    cout << "Reversed string: " << result << endl; 
}

bool isVowel(char ch) {
    ch = tolower(ch); // handle uppercase also
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void DelVowel(string str) {
    // Write a program to delete all the vowels from the string. 
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        if (!isVowel(str[i])) {   // if not a vowel, keep it
            result += str[i];
        }
    }
    cout << "String without vowels: " << result << endl;
}

void Alph(string str) {
    // Write a program to sort the strings in alphabetical order.
    string result = str;
    for (int j = 0; j < result.length() - 1; j++) {
        for (int i = 0; i < result.length() - j - 1; i++) {
            if (tolower(result[i]) > tolower(result[i + 1])) {
                char temp = result[i];
                result[i] = result[i + 1];
                result[i + 1] = temp;
            }
        }
    }
    cout << "String in Alphabetical order: " << result << endl;
}

void Case(char ch) {
    //lowercase = uppercase + 32.
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
        cout << ch << endl;
    }
    else {
        cout << "already in lowercase" << endl;
    }
}

int main() {
    string str1, str2;

    char ch = 'F';

    cout << "Enter first string: ";
    getline(cin, str1);

    cout << "Enter second string: ";
    getline(cin, str2);

    Concat(str1, str2);
    Rev(str1);
    DelVowel(str1);
    Alph(str1);
    Case(ch);
    return 0;
}