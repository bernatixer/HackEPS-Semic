#include<iostream>
#include <vector>
using namespace std;

int posicio(int x, const vector<int>& v, int esq, int dre) {
    if (esq > dre) return esq;
    int mid = (esq+dre)/2;
    if (x < v[mid]) return posicio(x, v, esq, mid-1);
    if (x > v[mid]) return posicio(x, v, mid+1, dre);
    return mid;
}

int reverse(int x,int y) {
  y *= 10;
  if(x > 9) {
  int n;
  n = x%10;
  x /=10;
  y = reverse(x, y+n);
  } else y+=x;
  return y;
}

void calcular_nombres(vector<int>& sols) {
  int num, x, xant;
  bool si;
  for(int i=1; i<=4; ++i) sols.push_back(i);
  for (int i =10; i<=999000; ++i) {
    si = false;
    num = i+reverse(i, 0);
    xant = num%10;
    while(num > 9 and not si) {
      num /= 10;
      x = num%10;
      if(x != xant) si = true;
      xant = x;
    }

    if(not si) sols.push_back(i);
  }
}

int main() {
  vector<int> sols;
  calcular_nombres(sols);
  int n;
  cin >> n;
  int a, b, i = 0;
  while (i < n) {
    cin >> a >> b;
    int pos_a = posicio(a, sols, 0, sols.size()-1);
    int pos_b = posicio(b, sols, 0, sols.size()-1);
    int count = pos_b - pos_a;
    cout << "Case #" << i+1 << ": " << count << endl;
    ++i;
  }
}
