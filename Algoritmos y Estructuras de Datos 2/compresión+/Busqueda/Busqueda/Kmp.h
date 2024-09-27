#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Kmp
{
private:
    string texto, patron;
    vector<int> buscarLPS()
    {
        int m = patron.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        while (i < m)
        {
            if (patron[i] == patron[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

public:
    Kmp(string text, string pattern);
    void find();
    ~Kmp();
};

Kmp::Kmp(string text, string pattern)
{
    texto = text;
    patron = pattern;
}

void Kmp::find()
{
    int n = texto.size();
    int m = patron.size();
    vector<int> lps = buscarLPS();
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (patron[j] == texto[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            cout << "patron en el siguiente indice " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && patron[j] != texto[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
Kmp::~Kmp()
{
}
