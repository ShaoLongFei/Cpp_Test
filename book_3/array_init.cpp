#include <string>
#include <iostream>
#include <altivec.h>

using std::string;
using std::cout;
using std::endl;

int main() {
    const unsigned sz = 3;
    int ial[sz] = {0, 1, 2}; // 含有 3 个元素的数组,元素值分别是 0, 1, 2
    int a2[] = {0, 1, 2}; // 维度是 3 的数组
    int a3[5] = {0, 1, 2}; // 等价于 a3[] = {0,1,2,0，0}
    string a4[3] = {"hi", "bye"}; // 等价于 a4[] = {"hi", "bye", ""}
    int a5[2] = {0, 1, 2}; // 错误:初始值过多

    char a3[] = "C++"; // 自动添加表示字符串结束的空字符
    const char a4[6] = "Daniel"; // 错误:没有空间可存放空字符!

    int a[] = {0, 1, 2}; // 含有 3 个整数的数组
    int a2[] = a; // 错误:不允许使用一个数组初始化另一个数组
    a2 = a; // 错误:不能把一个数组直接赋值给另一个数组

    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // ia 是一个含有 10 个整数的数组
    auto ia2(ia); // ia2 是一个整型指针，指向 ia 的第一个元素
    ia2 = 42; // 错误: ia2 是一个指针，不能用 int 值给指针赋值

    // ia3 是一个含有 10 个整数的数组
    decltype(ia) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num = 10;
    int *p = &num;
    ia3 = p; // 错误:不能用整型指针给数组赋值
    ia3[4] = 10; // 正确:赋值给 ia3 的一个元素

    // 用数组初始化 vector
    int int_arr[] = {0, 1, 2, 3, 4, 5};
    // ivec 有 6 个元素，分别是 int_arr 中对应元素的副本.
    vector<int> ivec(begin(int_arr), end(int_arr));
}
