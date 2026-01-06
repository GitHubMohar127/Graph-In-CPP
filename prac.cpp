#include<iostream>
#include<string>
#include <unordered_map>
using namespace std;

char firstNonRepeatingChar(string s) {
    unordered_map<char, int> freq;

    // 1st pass: count frequency
    for (char ch : s) {
        freq[ch]++;
    }

    // 2nd pass: find first char with freq = 1
    for (char ch : s) {
        if (freq[ch] == 1) {
            return ch;
        }
    }

    return '\0'; // if no non-repeating character
}
