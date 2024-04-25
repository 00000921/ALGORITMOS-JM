#include <iostream>
#include "reader.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Agent data[1000];
    load_data(data);

    for (int j = 0; j < 1000; j++)
    {
        insert(data[j]);
    }

    int opcion;
    int opcion2;

    while (opcion2 != 4)
    {
        cout << endl;
        cout << "Programa de Autocompletado" << endl;
        cout << "Seleccione una opción:" << endl;
        cout << "1. Agregar Palabra" << endl;
        cout << "2. Autocompletar" << endl;
        cout << "3. Mostrar Diccionario Actual" << endl;
        cout << "4. Salir" << endl;

        cin >> opcion;

        switch (opcion)
        {
        case 1: // Agregar Palabra
        {
            string palabra;
            cout << "Ingrese la palabra que desea agregar: ";
            cin >> palabra;
            insert(Agent("", 0, palabra, "", 0.0, 0.0, 0));
        }
        break;

        case 2: // Autocompletar
        {
            string prefijo;
            cout << "Ingrese el prefijo para autocompletar: ";
            cin >> prefijo;
            AutocompleteHelper(root, prefijo);
        }
        break;

        case 3: // Mostrar Diccionario Actual
            inOrder(root);
            break;

        default:
            break;
        }

        cout << endl;
        cout << "Salir: 4, Continuar: 1" << endl;
        cin >> opcion2;
    }

    cout << endl;

    return 0;
}
