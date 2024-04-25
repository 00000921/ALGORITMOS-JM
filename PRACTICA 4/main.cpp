#include <iostream>
#include "rb_tree.hpp"
#include "utility.hpp"
#include "pcb.hpp"

using namespace std;

void Menu(Red_Black_Tree &rbTree);

int main()
{
    Red_Black_Tree rbTree;

    // Crear PCBs con valores específicos
    PCB pcb1(1, 5, 20);
    PCB pcb2(2, 8, 15);
    PCB pcb3(3, 10, 30);
    PCB pcb4(4, 3, 25);

    // Insertar PCBs en el árbol rojo-negro
    rbTree.Insert(pcb1);
    rbTree.Insert(pcb2);
    rbTree.Insert(pcb3);
    rbTree.Insert(pcb4);

    // Mostrar el árbol
    rbTree.DisplayTreeShape();

    // Llamar a la función del menu
    Menu(rbTree);

    return 0;
}

void Menu(Red_Black_Tree &rbTree)
{
    int processID, virtualRuntime, timeToComplete;
    int searchKey;

    while (true)
    {
        cout << "Red-Black Tree Operaciones:" << endl;
        cout << "1. Insertar PCB" << endl;
        cout << "2. Eliminar PCB" << endl;
        cout << "3. Mostrar Tree" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        int o;
        cin >> o;

        switch (o)
        {
        case 1:
            cout << "Enter PCB information (ProcessID, VirtualRuntime, TimeToComplete): ";
            cin >> processID >> virtualRuntime >> timeToComplete;
            {
                PCB pcb(processID, virtualRuntime, timeToComplete);
                rbTree.Insert(pcb);
            }
            cout << "PCB insertado exitosamente" << endl;
            break;
        case 2:
            cout << "Enter el PCB a eliminar ";
            cin >> searchKey;
            {
                PCB searchPCB(searchKey, 0, 0);
                rbTree.Delete(searchPCB);
            }
            cout << "PCB " << searchKey << " eliminado exitosamente" << endl;
            break;
        case 3:
            cout << "Mostrar Red-Black Tree:" << endl;
            rbTree.DisplayTreeShape();
            break;
        case 4:
            cout << "Saliendo..." << endl;
            return;
        default:
            cout << "Opcion invalida, seleccione nuevamente" << endl;
        }
    }
}
