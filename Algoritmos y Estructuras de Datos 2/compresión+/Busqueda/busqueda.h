#include <iostream>
#include <vector>
#include <string>

using namespace std;

class StringSearch {
private:
    string text;
    string pattern;

    vector<int> compute_lps_array() {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

public:
    StringSearch(string text, string pattern) : text(text), pattern(pattern) {}

    void Busqueda_fuerza_bruta() {
        int n = text.size();
        int m = pattern.size();
        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                    break;
            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }
    }

    void Busqueda_por_KMP() {
        int n = text.size();
        int m = pattern.size();
        vector<int> lps = compute_lps_array();
        int i = 0;
        int j = 0;
        while (i < n) {
            if (pattern[j] == text[i]) {
                j++;
                i++;
            }
            if (j == m) {
                cout << "Pattern found at index " << i - j << endl;
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
    }
};

