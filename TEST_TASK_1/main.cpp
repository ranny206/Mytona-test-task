#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    char symbol;
    cin >> symbol;
    vector<string> result;
    string tmp = "";
    int sym_count = 0;
    for (char i : str) {
        if(i == symbol) {
            if (sym_count > 0) {
                continue;
            }
            sym_count++;
            result.push_back(tmp);
            tmp = "";
            continue;
        }
        sym_count = 0;
        tmp += i;
    }
    result.push_back(tmp);
    if(result[0].empty()) {
        result.erase(result.begin());
    }
    for (const auto & k : result) {
        cout << k << ' ';
    }
    return 0;
}
