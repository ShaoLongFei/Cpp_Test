
int main() {
    int i = 0;
    int *const p1 = &i; // 不能改变 p1 的值，这是一个顶层 const
    const int ci = 42; // 不能改变 ci 的值，这是一个顶层 const
    const int *p2 = &ci; // 允许改变 p2 的值，这是一个底层 const
    const int *const p3 = p2; // 靠右的 const 是顶层 const，靠左的是底层 const
    const int &r = ci; // 用于声明引用的 const 都是底层 const
    i = ci; // 正确:拷贝 ci 的值，ci 是一个顶层 const，对此操作无影响
    p2 = p3; // 正确: p2 和 p3 指向的对象类型相同，p3 顶层 const 的部分不影响
    int *p = p3; // 错误: p3 包含底层 const 的定义，而 p 没有
    p2 = p3; // 正确:p2 和 p3 都是底层 const
    p2 = &i; // 正确: int* 能转换成 const int*
    int &r = ci; // 错误:普通的 int& 不能绑定到 int 常量上
    const int &r2 = i; // 正确: const int& 可以绑定到一个普通 int 上
}
