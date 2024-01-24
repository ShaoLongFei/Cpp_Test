#include <iostream>

#include "ByteBuffer.h"

using namespace std;

int main() {
    ByteBuffer byteBuffer(10, "测试");

    byteBuffer.putBytes((uint8_t *) string("12345").c_str(), 5);

    auto *result = (uint8_t *) calloc(4, sizeof(uint8_t));
    byteBuffer.getBytes(result, 4);
    cout << result << endl;

    byteBuffer.putBytes((uint8_t *) string("1234567").c_str(), 7);

    byteBuffer.getBytes(result, 5);
    cout << result << endl;

    byteBuffer.putBytes((uint8_t *) string("1234567").c_str(), 7);

    byteBuffer.getBytes(result, 5);
    cout << result << endl;

    byteBuffer.putBytes((uint8_t *) string("1234567").c_str(), 7);

    byteBuffer.getBytes(result, 5);
    cout << result << endl;

    byteBuffer.putBytes((uint8_t *) string("1234567").c_str(), 7);

    byteBuffer.getBytes(result, 5);
    cout << result << endl;

}
