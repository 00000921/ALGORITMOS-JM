#include <iostream>
#include "reader.hpp"
#include "minheap.hpp"

using namespace std;

int main()
{
    const int numRows = 1000;
    StockData data[numRows];

    load_data(data, numRows);

    MinHeapSort(data, numRows);

    cout << "Datos ordenados por precio de vuelo:" << endl;
    for (int i = 0; i < numRows; i++)
    {
        cout << "ID: " << data[i].stock_id << ", Nombre: " << data[i].company_name << ", Fecha: " << data[i].trade_date << ", Precio: " << data[i].trade_price << ", Volumen: " << data[i].trade_volume << endl;
    }

    return 0;
}