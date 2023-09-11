#include "task.h"

using namespace std;
int main() {
    cout << "Введите строку: ";
    string s; getline(cin, s);
    cout << "Результат: " << task06(s) << endl;
    return 0;
}