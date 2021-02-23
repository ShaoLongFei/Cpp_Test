
int main() {
    auto k = ci, &l = i; // k是整数，i 是整型引用
    auto &m = ci, *p = &ci; // m 是对整型常量的引用，p 是指向整型常量的指针
    auto &n = i, *p2 = &ci; // 错误: i 的类型是 int 而 &ci 的类型是 const int
}

