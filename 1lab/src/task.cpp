#include <cctype>
#include "task.h"

static bool is_vowel(char c) {
    if (c == 'a' || c =='e' || c == 'i' || c == 'o' || c =='u'  || c == 'y') {
        return true;
    }
    return false;
}

using namespace std;
string task06(string s) {
    int cnt = s.length();
    for (int i = 0; i < cnt; i++)
        if (is_vowel(tolower(s[i]))) {
            s.erase(i, 1); --i; // Декриментируем индекс, так как после стирания литеры, индекс следующей литеры будет уменьшен, и так мы ее не пропустим
        }
    return s;
}