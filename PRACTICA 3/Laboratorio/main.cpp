using namespace std;

#include "reader.hpp"
#include "BinarySearchTree.hpp"

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

    while (opcion2 != 10)
    {
        cout << endl;
        cout << "Binary Search \n";
        cout << "Seleccione una opción:\n";
        cout << "1. Buscar\n";
        cout << "2. Minimo\n";
        cout << "3. Maximo\n";
        cout << "4. Sucesor\n";
        cout << "5. Predecesor\n";
        cout << "6. Eliminar\n";
        cout << "7. Mostrar in-orden\n";
        cout << "8. Mostrar pre-orden\n";
        cout << "9. Mostrar pos-torden\n";
        cout << "10. Salir\n";

        cin >> opcion;

        switch (opcion)
        {
        case 1: // busqueda
            float valorBuscado;
            cout << "Ingrese el valor a buscar: ";
            cin >> valorBuscado;
            CallSearch(valorBuscado);
            break;

        case 2: // minimo
            foundMin();
            break;

        case 3: // maximo
            foundMax();
            break;

        case 4: // sucesor
            float valorSucesor;
            cout << "Ingrese el valor cuyo sucesor desea encontrar: ";
            cin >> valorSucesor;
            foundSuccessor(valorSucesor);
            break;

        case 5: // predecesor
            float valorPredecesor;
            cout << "Ingrese el valor cuyo predecesor desea encontrar: ";
            cin >> valorPredecesor;
            foundPredecessor(valorPredecesor);
            break;

        case 6: // eliminar
            float valorEliminar;
            cout << "Ingrese el valor que desea eliminar: ";
            cin >> valorEliminar;
            Delete(valorEliminar);
            break;

        case 7: // in-order
            showInOrder();
            break;

        case 8: // pre-order
            showPreOrder();
            break;

        case 9: // post-order
            showPostOrder();
            break;

        default:
            break;
        }

        cout << endl;
        cout << "Salir: 10, Continuar: 1 \n";
        cin >> opcion2;
    }

    cout << endl;

    return 0;
}
