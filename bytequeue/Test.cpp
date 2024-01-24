#include <cstdlib>
#include <iostream>
#include "ByteQueue.h"

using namespace std;

int main() {
    ByteQueue byteBuffer(20);
    uint8_t *data = (uint8_t *) calloc(10, sizeof(uint8_t));
    for (int i = 0; i < 10; i++) {
        data[i] = i;
    }
    auto *data2 = (uint8_t *) calloc(uint32_t(10), sizeof(uint8_t));

    for (int i = 0; i < 200; ++i) {
        int number = (rand() % 10) + 1;
        if (number % 2 == 0) {
            byteBuffer.push(data, number);
            cout << endl;
        } else {
            byteBuffer.pop(data2, number);
            for (int i = 0; i < number; i++) {
                cout << (int) data2[i];
            }
            cout << endl;
            cout << endl;
        }
    }

}

