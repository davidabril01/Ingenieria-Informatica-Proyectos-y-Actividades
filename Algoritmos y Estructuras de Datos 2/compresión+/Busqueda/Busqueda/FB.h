#include <iostream>
using namespace std;

class FB
{
private:
    string texto, patron;

public:
    FB(string text, string pattern);
    void find();
    ~FB();
};

FB::FB(string text, string pattern)
{
    texto = text;
    patron = pattern;
}

FB::~FB()
{
}

void FB::find()
{
    int n = texto.size();
    int m = patron.size();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (texto[i + j] != patron[j])
                break;
        if (j == m)
            cout << "patron en el siguiente indice " << i << endl;
    }
}