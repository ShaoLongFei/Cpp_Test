#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main() {
    string s1 = "Hello";
    string s2 = "World";
    string s3 = s1 + " " + s2; // 正确
    string s4 = s1 + s2; // 正确
    string s5 = "Hello" + "World"; // 错误
}

