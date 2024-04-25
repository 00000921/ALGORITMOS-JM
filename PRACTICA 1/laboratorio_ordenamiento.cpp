#include <iostream>
#include <vector>

using namespace std;

class Estudiante
{
public:
    int materias;
    int edad;

    Estudiante(int m, int e) : materias(m), edad(e) {}
};

void imprimirEstudiantes(const vector<Estudiante> &estudiantes)
{
    for (const Estudiante &estudiante : estudiantes)
    {
        cout << "Materia: " << estudiante.materias << ", Edad: " << estudiante.edad << "\n";
    }
}

void selectionSortAsc(vector<Estudiante> &estudiantes)
{
    int n = estudiantes.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (estudiantes[j].edad < estudiantes[min].edad)
            {
                min = j;
            }
        }
        swap(estudiantes[i], estudiantes[min]);
    }
}

void bubbleSortDesc(vector<Estudiante> &estudiantes)
{
    int n = estudiantes.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (estudiantes[j].materias < estudiantes[j + 1].materias)
            {
                swap(estudiantes[j], estudiantes[j + 1]);
            }
        }
    }
}

int main()
{
    vector<Estudiante> estudiantes;
    estudiantes.push_back(Estudiante(5, 22));
    estudiantes.push_back(Estudiante(3, 20));
    estudiantes.push_back(Estudiante(4, 23));
    estudiantes.push_back(Estudiante(5, 23));
    estudiantes.push_back(Estudiante(3, 25));
    estudiantes.push_back(Estudiante(2, 19));
    estudiantes.push_back(Estudiante(4, 23));

    cout << "Lista de estudiantes sin ordenar:"
         << "\n";
    imprimirEstudiantes(estudiantes);

    selectionSortAsc(estudiantes);
    cout << "\nLista de estudiantes ordenada por edad de forma ascendente:"
         << "\n";
    imprimirEstudiantes(estudiantes);

    bubbleSortDesc(estudiantes);
    cout << "\nLista de estudiantes ordenada por materia de forma descendente:"
         << "\n";
    imprimirEstudiantes(estudiantes);

    return 0;
}
