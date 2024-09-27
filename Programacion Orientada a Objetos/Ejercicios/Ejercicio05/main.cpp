#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QDebug>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<string> expresiones;

    cout << "Ingrese Expresiones: "<<endl;
    for(int i= 0; i<5; i++){
        string x;
        getline(cin, x);
        expresiones.push_back(x);
      }

    sort(expresiones.begin(), expresiones.end());

    cout << "Expresiones ordenadas alfabeticamente:"<<endl;
        for(const auto& expresion : expresiones) {
            cout << expresion << endl;
        }
    return 0 ;
}
