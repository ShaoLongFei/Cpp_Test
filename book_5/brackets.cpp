# include <iostream>

using std::cout;
using std::endl;

int main() {
    int i = 5;
    if (i < 10)
        cout << "i 小于 10，输出一下" << endl;
    else
        cout << "i 不小于 10，输出一下" << endl;
        cout << "这句话无论 i 为何值都会被打印，这就是要加花括号的重要性" << endl;

    cout << "------------------------------" <<endl;

    if (i < 100)
        cout << "i 小于 100，输出一下" << endl;
        if (i > 10)
            cout << "i 大于 10，输出一下" << endl;
    else
        cout << "i 不小于 100，输出一下" << endl; // 这句话会被打印，因为 else 总是找最近的 if 结合，得加花括号
}

