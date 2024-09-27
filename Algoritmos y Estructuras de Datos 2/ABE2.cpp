#include <iostream>
#include <cmath>

using namespace std;
const int MAX_CITIES = 10;

class City
{
private:
    int x, y;

public:
    int getx()
    {
        return (x);
    }
    void setx()
    {
        cout<<"ingrese X: ";
        cin>>x;
    }
    int gety()
    {
        return (x);
    }
    void sety()
    {
        cout<<"ingrese Y: ";
        cin>>y;
    }
};

class TPS
{
private:
    int n;
    int tour[MAX_CITIES]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    double shortestLength = HUGE_VAL;
    int shortestTour[MAX_CITIES];
    City cities[MAX_CITIES];
public:
    TPS();
    ~TPS();
    double tourLength();
    double distance(City a,City b);
    bool nextPermutation();
};

TPS::TPS()
{
    cout << "Ingrese el número de ciudades: ";
    cin >> n;

    while (n > MAX_CITIES)
    {
        cout << "Numero de ciudades demasiado grande. El límite es " << MAX_CITIES << endl;
        cout << "Ingrese el número de ciudades: ";
        cin >> n;
    }

    for (int i = 0; i < n; ++i)
    {
        cout<<"Ciudad Numero "<<i+1<<": "<<endl;
        cities[i].setx();
        cities[i].sety();
    }
    do {
        double length = tourLength();
        if (length < shortestLength) {
            shortestLength = length;
            for (int i = 0; i < n; ++i) {
                shortestTour[i] = tour[i];
            }
        }
    } while (nextPermutation());

    cout << "El camino más corto es: ";
    for (int i = 0; i < n; ++i) {
        cout << shortestTour[i] << " ";
    }
    cout << endl;
    cout << "Longitud del camino más corto: " << shortestLength << endl;
}

double TPS::tourLength(){
    double length = 0.0;
    for (int i = 0; i < n - 1; ++i) {
        length += distance(cities[tour[i]], cities[tour[i + 1]]);
    }
    length += distance(cities[tour[n - 1]], cities[tour[0]]); // Regreso a la ciudad de inicio
    return length;
}

double TPS::distance(City a, City b){
    int dx = a.getx() - b.getx();
    int dy = a.gety() - b.gety();
    return sqrt(dx * dx + dy * dy);
}

bool TPS::nextPermutation(){
    int i = n - 2;
    while (i >= 0 && tour[i] >= tour[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false; // No hay más permutaciones
    }

    int j = n - 1;
    while (tour[j] <= tour[i]) {
        j--;
    }

    swap(tour[i], tour[j]);

    int left = i + 1;
    int right = n - 1;
    while (left < right) {
        swap(tour[left], tour[right]);
        left++;
        right--;
    }

    return true;
}

TPS::~TPS()
{
}

int main()
{
    TPS Vendedor;
    return 0;
}
