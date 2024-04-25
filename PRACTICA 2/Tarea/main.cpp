#include <iostream>
#include "MinPQ.hpp"

using namespace std;

int main()
{
    const int numRows = 1000;
    const int numColumns = 5;

    StockData *stockData = new StockData[numRows];

    load_data(stockData, numRows, numColumns);

    MinPriorityQueue minQueue(numRows);

    // Insertar algunos datos de stock en la cola de prioridad
    minQueue.Insert(stockData[0].trade_price, stockData[0]);
    minQueue.Insert(stockData[1].trade_price, stockData[1]);
    minQueue.Insert(stockData[2].trade_price, stockData[2]);

    // Obtener el elemento mínimo
    PriorityQueueElement minElement = minQueue.GetMinimum();
    cout << "Elemento mínimo: " << minElement.key << " - " << minElement.value.company_name << endl;

    // Extraer el elemento mínimo
    minQueue.ExtractMinimum();
    minElement = minQueue.GetMinimum();
    cout << "Elemento mínimo después de extraer: " << minElement.key << " - " << minElement.value.company_name << endl;

    // Reducir la clave del elemento restante
    minQueue.DecreaseKey(1, 10.0);
    minElement = minQueue.GetMinimum();
    cout << "Elemento mínimo después de reducir clave: " << minElement.key << " - " << minElement.value.company_name << endl;

    delete[] stockData;

    return 0;
}
