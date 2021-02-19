
int main() {
    int i = 42;
    int &r = i; // & 紧随类型名出现，因此是声明的一部分，r 是一个引用
    int *p; // * 紧随类型名出现，因此是声明的一部分，P 是一个指针
    p = &i; // & 出现在表达式中，是一个取地址符
    *p = i; // * 出现在表达式中，是一个解引用符
    int &r2 = *p; // & 是声明的一部分，* 是一个解引用符
}
