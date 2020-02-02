#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> urls;
    urls.push_back("http://mytona.com/index.html");
    urls.push_back("https://mytona.com:8080/");
    urls.push_back("mytona.com");
    for (auto &url : urls) {
        string s;
        auto ptl = url.find("://");
        if (ptl == string::npos) {
            cout << "Protocol:" << "http" << ' ';
            s = url;
        } else {
            cout << "Protocol:" << url.substr(0, ptl) << ' ';
            s = url.substr(ptl + 3);
        }
        auto port = s.find(':');
        if (port == string::npos) {
            auto page = s.find('/');
            if (s.substr(page + 1) == "") {
                page = string::npos;
            }
            if (page == string::npos) {
                cout << "Host:" << s << ' ';
                cout << "Port:" << "80" << ' ';
                cout << "Page:" << "/";
            } else {
                cout << "Host:" << s.substr(0, page) << ' ';
                cout << "Port:" << "80" << ' ';
                cout << "Page:" << s.substr(page + 1);
            }
        } else {
            cout << "Host:" << s.substr(0, port) << ' ';
            auto page = s.substr(0).find('/');
            if (page == string::npos) {
                cout << "Port:" << s.substr(port + 1) << ' ';
                cout << "Page:" << "/";
            } else {
                cout << "Port:" << s.substr(port + 1, page - port - 1) << ' ';
                cout << "Page:" << s.substr(page + 1);
            }
        }
        cout << "\n";
    }
    return 0;
}
