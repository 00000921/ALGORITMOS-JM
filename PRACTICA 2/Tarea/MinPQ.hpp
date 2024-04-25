#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include <iostream>
#include <climits>
#include "reader.hpp"

using namespace std;

struct PriorityQueueElement {
    double key;
    StockData value;
};

class MinPriorityQueue {
private:
    PriorityQueueElement* heap;
    int capacity;
    int size;

    int Parent(int i) {
        return (i - 1) / 2;
    }

    int LeftChild(int i) {
        return 2 * i + 1;
    }

    int RightChild(int i) {
        return 2 * i + 2;
    }

    void MinHeapify(int i) {
        int left = LeftChild(i);
        int right = RightChild(i);
        int smallest = i;

        if (left < size && heap[left].key < heap[i].key)
            smallest = left;
        if (right < size && heap[right].key < heap[smallest].key)
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            MinHeapify(smallest);
        }
    }

public:
    MinPriorityQueue(int capacity) {
        this->capacity = capacity;
        heap = new PriorityQueueElement[capacity];
        size = 0;
    }

    ~MinPriorityQueue() {
        delete[] heap;
    }

    void Insert(double key, const StockData& value) {
        if (size == capacity) {
            cerr << "La cola de prioridad está llena." << endl;
            return;
        }

        size++;
        int i = size - 1;
        heap[i].key = key;
        heap[i].value = value;

        while (i > 0 && heap[i].key < heap[Parent(i)].key) {
            swap(heap[i], heap[Parent(i)]);
            i = Parent(i);
        }
    }

    PriorityQueueElement GetMinimum() {
        if (size == 0) {
            cerr << "La cola de prioridad está vacía." << endl;
            PriorityQueueElement emptyElement;
            emptyElement.key = INT_MAX;
            return emptyElement;
        }

        return heap[0];
    }

    PriorityQueueElement ExtractMinimum() {
        if (size == 0) {
            cerr << "La cola de prioridad está vacía." << endl;
            PriorityQueueElement emptyElement;
            emptyElement.key = INT_MAX;
            return emptyElement;
        }

        if (size == 1) {
            size--;
            return heap[0];
        }

        PriorityQueueElement minElement = heap[0];
        heap[0] = heap[size - 1];
        size--;

        MinHeapify(0);

        return minElement;
    }

    void DecreaseKey(int index, double newKey) {
        if (index >= size) {
            cerr << "Índice fuera de rango." << endl;
            return;
        }

        if (newKey > heap[index].key) {
            cerr << "La nueva clave es mayor que la clave actual." << endl;
            return;
        }

        heap[index].key = newKey;

        int i = index;
        while (i > 0 && heap[i].key < heap[Parent(i)].key) {
            swap(heap[i], heap[Parent(i)]);
            i = Parent(i);
        }
    }
};

#endif
