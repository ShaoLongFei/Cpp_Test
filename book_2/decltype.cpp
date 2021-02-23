
int main(){
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0; // x 的类型是 const int
    decltype(cj) y = x; // y 的类型是 const int&，y 绑定到变量 x
    decltype(cj) z; // 错误:z 是一个引用，必须初始化

    // decltype 的结果可以是引用类型
    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b; // 正确:加法的结果是 int，因此 b 是一个(未初始化的) int
    decltype(*p) c; // 错误:c 是 int&，必须初始化
    // decltype 的表达式如果是加上了括号的变量，结果将是引用
    decltype((i)) d; // 错误:d 是 int&，必须初始化
    decltype(i) e; // 正确: e 是一个(未初始化的) int
}

