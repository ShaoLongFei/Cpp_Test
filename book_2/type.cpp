#include <iostream>

int main() {
    unsigned char c = -1; // 假设char占8比特，c的值为255
    signed char c2 = 256; // 假设char占8比特，c2的值是未定义的
    std::cout << (int) c << "   " << (int) c2 << std::endl; // 因为 c2 转了 int 所以打印出来是 0 ，其本身应是未定义的

    std::cout << "--------------------------------" << std::endl;

    unsigned u = 10;
    int i = -42;
    std::cout << i + i << std::endl; // 输出 -84
    std::cout << u + i << std::endl; // 如果 int 占 32 位，输出 4294967264

    std::cout << "--------------------------------" << std::endl;

    unsigned u1 = 42, u2 = 10;
    std::cout << u1 - u2 << std::endl; // 正确：输出 32
    std::cout << u2 - u1 << std::endl; // 正确：不过，结果是取模后的值，4294967264
}

