#ifndef MINHEAP_H
#define MINHEAP_H

#include "reader.hpp"

using namespace std;

void MinHeapify(StockData data[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && data[left].trade_price < data[smallest].trade_price)
        smallest = left;

    if (right < n && data[right].trade_price < data[smallest].trade_price)
        smallest = right;

    if (smallest != i)
    {
        swap(data[i], data[smallest]);

        MinHeapify(data, n, smallest);
    }
}

void MinHeapSort(StockData data[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        MinHeapify(data, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(data[0], data[i]);

        MinHeapify(data, i, 0);
    }
}

#endif