# include <iostream>

using std::cout;
using std::endl;

int main() {
    int i = 0, j = 10;
    cout << i << " " << i++ << endl;
    // 进行强制类型转换以便执行浮点数除法
    double slope = static_cast<double>(j) / i;

    const char *pc;
    char *p = const_cast<char *>(pc); // 正确:但是通过 p 写值是未定义的行为

    int *ip;
    char *pd = reinterpret_cast<char *> (ip);
}

