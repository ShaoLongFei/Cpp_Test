#include "ByteQueue.h"
#include "ByteQueue.h"

#include <cstdlib>
#include <valarray>
#include <iostream>

using namespace std;

ByteQueue::ByteQueue(uint32_t size) {
    capacity = size;
    buffer = (int32_t *) calloc(capacity, sizeof(uint32_t));
    head = 0;//当前位置存储数据，未读
    tail = 0;//当前位置不存储数据，未写入
    currentSize = 0;
}

bool ByteQueue::push(uint8_t *data, uint32_t size) {
    if (checkFreeSize(size)) {
        if (head < tail) {
            if (capacity - tail >= size) {
                copy(data, data + size, buffer + tail);
            } else {
                copy(data, data + capacity - tail, buffer + tail);
                copy(data + capacity - tail, data + size, buffer);
            }
        } else if (head > tail) {
            copy(data, data + size, buffer + tail);
        } else if (head == tail) {
            if (capacity - tail >= size) {
                copy(data, data + size, buffer + tail);
            } else {
                copy(data, data + capacity - tail, buffer + tail);
                copy(data + capacity - tail, data + size, buffer);
            }
        }
        tail = (tail + size) % capacity;
        currentSize += size;
        cout << "存储 " << size << " 位 成功，当前数据量 " << currentSize << endl;
        printCurrentInfo();
        cout << "当前数据队列："<<endl;
        for (int i = 0; i < 20; i++) {
            cout << (int) buffer[i];
        }
        cout << endl;
        return true;
    } else {
        cout << "存储 " << size << " 位 失败，当前数据量 " << currentSize << endl;
        return false;
    }
}

void ByteQueue::printCurrentInfo() {
    cout << "头部位置：" << head << " 尾部位置：" << tail << endl;
}

bool ByteQueue::push(int16_t *data, uint32_t size) {
    return true;
}

bool ByteQueue::push(int32_t *data, uint32_t size) {
    return true;
}

bool ByteQueue::pop(uint8_t *data, uint32_t size) {
    if (checkDataSize(size)) {
        if (head < tail) {
            copy(buffer + head, buffer + head + size, data);
        } else if (head > tail) {
            if (capacity - head >= size) {
                copy(buffer + head, buffer + head + size, data);
            } else {
                copy(buffer + head, buffer + capacity, data);
                uint32_t headSize = size - (capacity - head);
                copy(buffer, buffer + headSize, data + capacity - head);
            }
        } else if (head == tail) {
            if (capacity - tail >= size) {
                copy(buffer + head, buffer + head + size, data);
            } else {
                copy(buffer + head, buffer + capacity, data);
                uint32_t headSize = size - (capacity - head);
                copy(buffer, buffer + headSize, data + capacity - head);
            }
        }
        head = (head + size) % capacity;
        currentSize -= size;
        cout << "取出 " << size << " 位 成功，当前数据量 " << currentSize << endl;
        printCurrentInfo();
        cout << "当前数据队列："<<endl;
        for (int i = 0; i < 20; i++) {
            cout << (int) buffer[i];
        }
        cout << endl;
    } else {
        cout << "取出 " << size << " 位 失败，当前数据量 " << currentSize << endl;
        return false;
    }
}

bool ByteQueue::pop(int16_t *data, uint32_t size) {
    return true;
}

bool ByteQueue::pop(int32_t *data, uint32_t size) {
    return true;
}

bool ByteQueue::isFull() {
    return true;
}

uint32_t ByteQueue::size() {
    return 0;
}

/**
 * 检查是否有剩余空间容纳指定数量的数据
 * @param size
 * @return
 */
bool ByteQueue::checkFreeSize(uint32_t size) {
    if (tail > head) {
        // 尾部剩余空间
        uint32_t allFree = capacity - tail + head;
        if (allFree >= size) {
            return true;
        }
    } else if (tail < head) {
        if (head - tail >= size) {
            return true;
        }
    } else if (tail == head) {
        if (currentSize == 0 && capacity >= size) {
            return true;
        }
    }
    return false;
}

/**
 * 检查是否有指定数量的数据来读取
 * @param size
 * @return
 */
bool ByteQueue::checkDataSize(uint32_t size) {
    if (tail > head) {
        if (tail - head >= size) {
            return true;
        }
    } else if (tail < head) {
        // 尾部数据量
        uint32_t tailData = capacity - head;
        if (tailData >= size) {
            return true;
        }
        if (tailData + tail >= size) {
            return true;
        }
    } else if (tail == head) {
        if (currentSize == capacity && capacity >= size) {
            return true;
        }
    }
    return false;
}

void ByteQueue::release() {
}

