#include <string>
using std::string;

int main(){
    string s1; // 默认初始化，s1 是一个空串
    string s2 (s1); // s2 是 s1 的副本
    string s2 = s1; // 等价于 s2(s1)，s2 是 s1 的副本
    string s3 ("value"); // s3 是字面值"value"的副本，除了字面值最后的那个空字符外
    string s3 = "value"; // 等价于 s3("value")，s3 是字面值"value"的副本
    string s4(10,'C'); // 把 s4 初始化为由连续 10 个字符 c 组成的串

    string s5 = "hiya"; // 拷贝初始化
    string s6 ("hiya") ; // 直接初始化
}

