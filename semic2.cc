
#include <iostream>
#include <vector>

using namespace std;

int posicio(int x, const vector<int>& v, int esq, int dre) {
    if (esq > dre) return esq;
    int mid = (esq+dre)/2;
    if (x < v[mid]) return posicio(x, v, esq, mid-1);
    if (x > v[mid]) return posicio(x, v, mid+1, dre);
    return mid;
}

vector<bool> get_sieve() {
    vector<bool> sieve(10000001, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i=2; i<=10000000; ++i) {
        if (sieve[i]) for (int j=2*i; j<=10000000; j+=i) sieve[j] = false;
    }
    return sieve;
}

int main() {
    
    int ncasos = 0, min,max;
    
    vector<bool> sieve = get_sieve();  //Inicialització de vector
    vector<int> primers;

    for (int i = 0; i < sieve.size(); i++) {
        if (sieve[i]) primers.push_back(i);
    }

    int inici = 0, fi = primers.size();
    cin >> ncasos;

    for (int i = 0; i < ncasos; i++) {
        cin >> min >> max;

        long long int res = 0;

        int primera_pos = posicio(min,primers, inici, fi);

        for (int i = primera_pos; i < primers.size() and primers[i] <= max; ++i) {

            res += primers[i];
        }

        cout << "Case #" << i+1 << ": " << res << endl;

    }

}
