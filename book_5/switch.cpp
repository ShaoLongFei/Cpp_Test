#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main() {
    bool ret = true;
    switch (ret) {
        case true : // 因为程序的执行流程可能绕开下面的初始化语句，所以该 switch 语句不合法
            string file_name; // 错误:控制流绕过一个隐式初始化的变量
            int ival = 0; // 错误:控制流绕过一个显式初始化的变量
            int jval; // 正确:因为 jval 没有初始化
            break;
        case false: // 正确:jval 虽然在作用域内，但是它没有被初始化
            jval = 666; //正确:给 jval 赋一个值
            if (file_name.empty()) { // file_name 在作用域内，但是没有被初始化
                cout << "file_name is empty" << endl;
            }
            break;
    }
}

