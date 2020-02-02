#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> str;
    ifstream fin;
    fin.open("input.txt");
    while(!fin.eof()) {
        string tmp;
        fin >> tmp;
        str.push_back(tmp);
    }
    for (auto & i : str) {
        for (int j = 0; j < i.size(); ++j) {
            if(i[j] == '0' || i[j] == '1' || i[j] == '2' || i[j] == '3' ||
            i[j] == '4' || i[j] == '5' || i[j] == '6' || i[j] == '7' || i[j] == '8' ||
            i[j] == '9') {
                i.erase(j, 1);
                j--;
            }
        }
    }
    string result;
    for (const auto & k : str) {
        result += k;
    }
    remove("input.txt");
    ofstream tmp;
    tmp.open("tmp.txt", ios::app | ios::out);
    tmp << result;
    rename("mp.txt",
            "input.txt");
    ofstream fout;
    fout.open("input.txt");
    fout << result;
    return 0;
}
