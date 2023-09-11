#include "task.h"

static bool is_vowel(char c) {
    if (c == 'a' || c =='e' || c == 'i' || c == 'o' || c =='u'  || c == 'y' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') {
        return true;
    }
    return false;
}

using namespace std;
string task06(string s) {
    int cnt = s.length();
    for (int i = 0; i < cnt; i++)
        if (is_vowel(s[i])) {
            s.erase(i, 1); --i;
        }
    return s;
}