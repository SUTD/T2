#define N 1000

#include "llbmc.h"

struct queue {
    int nelem;
    int head;
    int tail;
    int buffer[N];
} global_queue;

inline void insert(int i) {
    if (global_queue.nelem == N) {
        return;
    } else {
        global_queue.buffer[global_queue.tail] = i;
        if (global_queue.tail == N - 1) {
            global_queue.tail = 0;
        } else {
            global_queue.tail++;
        }
        global_queue.nelem++;
    }
}

int r;
inline void retrieve() {
    if (global_queue.nelem == 0) {
        return;
    } else {
        r = global_queue.buffer[global_queue.head];
        if (global_queue.head == N - 1) {
            global_queue.tail = 0;
        } else {
            global_queue.head++;
        }
        global_queue.nelem--;
    }
}

int main() {
    int i = 0;
    global_queue.nelem = global_queue.head = global_queue.tail = 0;
    for (i = 0; i < N; ++i) {
        insert(i);
    }
    for (i = 0; i < N; ++i) {
        retrieve();
        __llbmc_assert(r == i);
    }
    return r;
}
