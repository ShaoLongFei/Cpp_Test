#include <vector>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::toupper;
using std::vector;

int main() {
    vector<string>::iterator it; // it 能读写 vector<string> 的元素
    string::iterator it2; // it2 能读写 string 对象中的字符
    vector<int>::const_iterator it3; // it3 只能读元素，不能写元素
    string::const_iterator it4; // it4 只能读字符，不能写字符

    vector<int> v;
    const vector<int> cv;
    auto it5 = v.begin(); // it5 的类型是 vector<int>::iterator
    auto it6 = cv.begin(); // it6 的类型是 vector<int>::const_iterator
    auto it7 = v.cbegin(); // it7 的类型是 vector<int>::const_iterator

    (*it).empty(); // 解引用 it，然后调用结果对象的 empty 成员
    *it.empty(); // 错误:试图访问 it 的名为 empty 的成员，但 it 是个迭代器，没有 empty 成员

    // 依次输出 text 的每一行直至遇到第一个空白行为止
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
        cout << *it << endl;
    }

    // 利用迭代器的运算来完成二分查找算法的示例：
    // text 必须是有序的
    // beg 和 end 表示我们搜索的范围
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg) / 2; // 初始状态下的中间点
    // 当还有元素尚未检查并且我们还没有找到 sought 时执行循环
    while (mid != end && *mid != sought) {
        if (sought < *mid) { // 我们要找的元素在前半部分吗?
            end = mid; // 如果是，调整搜索范围使得忽略掉后半部分
        } else { // 我们要找的元素在后半部分;
            beg = mid + 1; // 在mid之后寻找
        }
        mid = beg + (end - beg) / 2; // 新的中间点.
    }
}