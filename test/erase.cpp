#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> count{0, 0, 0, 437, 0, 0, 0};
    vector<int>::iterator iter;

    for (iter = count.begin(); iter != count.end();) {
        if (*iter == 0) {
            count.erase(iter);
        } else {
            iter++;
        }
    }
    for (int i: count) {
        std::cout << i << std::endl;
    }

    int a = 327672;
    short b = a;
    cout << b << endl;
}

