#include <vector>
using namespace std;

/// \brief Ordena as habitações do Condominio por área habitacional.
void insertionSort(vector<Habitacao *> &v) {
    for (unsigned int p = 1; p < v.size(); p++)
    {
        Habitacao *tmp = v[p];
        int j;
        for (j = p; j > 0 && !(tmp->getAreaHabitacional() < v[j-1]->getAreaHabitacional()); j--)
            v[j] = v[j-1];
        v[j] = tmp;
    }
}
