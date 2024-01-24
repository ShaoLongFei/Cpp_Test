#include <cstdint>

#ifndef C___TEST_BYTEQUEUE_H
#define C___TEST_BYTEQUEUE_H

/**
 * 空间类型
 */
enum StorageType {
    // 尾部就足够了
    ONLY_TAIL,
    // 头部和尾部加起来才够
    HEAD_AND_TRAIL,
    // 空间不足
    NOT_ENOUGH
};

class ByteQueue {
public:
    ByteQueue(uint32_t size);

    bool push(uint8_t *data, uint32_t size);

    bool push(int16_t *data, uint32_t size);

    bool push(int32_t *data, uint32_t size);

    bool pop(uint8_t *data, uint32_t size);

    bool pop(int16_t *data, uint32_t size);

    bool pop(int32_t *data, uint32_t size);

    bool isFull();

    uint32_t size();

    void release();

private:
    int32_t *buffer;
    uint32_t capacity;
    uint32_t head;
    uint32_t tail;
    uint32_t currentSize;

    bool checkFreeSize(uint32_t size);
    bool checkDataSize(uint32_t size);
    void printCurrentInfo();
};

#endif //C___TEST_BYTEQUEUE_H
