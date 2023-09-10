#include <iostream>
#include <string>

bool is_vowel(char c) {
    if (c == 'a' || c =='e' || c == 'i' || c == 'o' || c =='u'  || c == 'y' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') {
        return true;
    }
    return false;
}

using namespace std;
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (is_vowel(s[i])) {
            s.erase(i, 1);
        }
    }
    cout << s << endl;
} 