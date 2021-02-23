#include <string>
#include <iostream>
#include <cctype>

using std::string;
using std::cout;
using std::endl;
using std::toupper;
using std::vector;

int main() {
    string s("Hello World!!!");
    // 转换成大写形式
    for (auto &c :s) {
        c = toupper(c);
    }
    cout << s << endl;

    string s1("some string");
    if (s1.begin() != s1.end()) { // 确保 s 非空
        auto it = s1.begin(); // it 表示 s 的第一个字符
        *it = toupper(*it); // 将当前字符改成大写形式
    }
    cout << s1 << endl;
    // 依次处理 s 的字符直至我们处理完全部字符或者遇到空白
    for (auto it = s1.begin(); it != s1.end() && !isspace(*it); ++it) {
        *it = toupper(*it); // 将当前字符改成大写形式
    }
    cout << s1 << endl;
}

