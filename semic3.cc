#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

struct lletra {
    int x, y, cops;
    char digit;

    lletra(int x, int y, int cops, char c) {
        this -> x = x;
        this -> y = y;
        this -> cops = cops;
        this -> digit = c;
    }

    lletra buscar_coordenada(char c) {
        switch (c)
        {
            case 'a': return lletra(0, 1, 1, '2'); break;
            case 'b': return lletra(0, 1, 2, '2'); break;
            case 'c': return lletra(0, 1, 3, '2'); break;
            case 'd': return lletra(0, 2, 1, '3'); break;
            case 'e': return lletra(0, 2, 2, '3'); break;
            case 'f': return lletra(0, 2, 3, '3'); break;
            case 'g': return lletra(1, 0, 1, '4'); break;
            case 'h': return lletra(1, 0, 2, '4'); break;
            case 'i': return lletra(1, 0, 3, '4'); break;
            case 'j': return lletra(1, 1, 1, '5'); break;
            case 'k': return lletra(1, 1, 2, '5'); break;
            case 'l': return lletra(1, 1, 3, '5'); break;
            case 'm': return lletra(1, 2, 1, '6'); break;
            case 'n': return lletra(1, 2, 2, '6'); break;
            case 'o': return lletra(1, 2, 3, '6'); break;
            case 'p': return lletra(2, 0, 1, '7'); break;
            case 'q': return lletra(2, 0, 2, '7'); break;
            case 'r': return lletra(2, 0, 3, '7'); break;
            case 's': return lletra(2, 0, 4, '7'); break;
            case 't': return lletra(2, 1, 1, '8'); break;
            case 'u': return lletra(2, 1, 2, '8'); break;
            case 'v': return lletra(2, 1, 3, '8'); break;
            case 'w': return lletra(2, 2, 1, '9'); break;
            case 'x': return lletra(2, 2, 2, '9'); break;
            case 'y': return lletra(2, 2, 3, '9'); break;
            case 'z': return lletra(2, 2, 4, '9'); break;
            case ' ': return lletra(3, 1, 1, '0'); break;
            case '#': return lletra(3, 2, 1, '#'); break;
            case '1': return lletra(0, 0, 1, '1'); break;
            case '2': return lletra(0, 1, 4, '2'); break;
            case '3': return lletra(0, 2, 4, '3'); break;
            case '4': return lletra(1, 0, 4, '4'); break;
            case '5': return lletra(1, 1, 4, '5'); break;
            case '6': return lletra(1, 2, 4, '6'); break;
            case '7': return lletra(2, 0, 5, '7'); break;
            case '8': return lletra(2, 1, 4, '8'); break;
            case '9': return lletra(2, 2, 5, '9'); break;
            case '0': return lletra(3, 1, 2, '0'); break;
            default: return lletra(0, 0, 0, ' '); break;
        }
    }

    lletra(char c)
    {
        lletra nova = this -> buscar_coordenada(c);
        this -> x = nova.x;
        this -> y = nova.y;
        this -> cops = nova.cops;
        this -> digit = nova.digit;
    }

};

bool blok_mayus = false;


void eliminar_espais(string& s) {
    for (int i=0; i<s.size();) {
        if (s[i] == ' ' and (i == 0 or s[i-1] == ' ')) {
            s.erase(i, 1);
        } else ++i;
    }
}

void eliminar_merda(string& s)
{
    for (int i=0; i<s.size();) {
        char c = s[i];
        bool especial = c >= 'A' and c <= 'Z';
        especial = especial || c >= 'a' and c <= 'z';
        especial = especial || c >= '0' and c <= '9';
        especial = especial || c == ' ';
        if (!especial) {
            s.erase(i, 1);
        } else ++i;
    }
}

void canviar_paraula(string& frase, const string str1, const string str2) {
    int aux = 0;
    while ((aux = frase.find(str1)) != -1) {
        frase.replace(aux, str1.size(), str2);
    }
}

void separar_paraules(vector<string>& paraules, string& l) {
    canviar_paraula(l, "que tal", "ktal");
    canviar_paraula(l, "que carajo", "wtf");
    canviar_paraula(l, "que", "k");
    canviar_paraula(l, "adios", "dw");
    canviar_paraula(l, "te quiero mucho", "tkm");
    canviar_paraula(l, "gracias", "thx");
    canviar_paraula(l, "besos y abrazos", "xoxo");

    string aux = "";
    for (int i=0; i<l.size(); ++i) {
        if (l[i] == ' ') {
            paraules.push_back(aux);
            aux = "";
        } else aux += l[i];
    }
    paraules.push_back(aux);
}

void cami_letra2lletra(lletra& inici, const lletra& fi)
{    
    while (inici.x > fi.x)
    {
        cout << "arriba ";
        inici.x--;
    }
    while (inici.x < fi.x)
    {
        cout << "abajo ";
        inici.x++;
    }
    while (inici.y > fi.y)
    {
        cout << "izquierda ";
        inici.y--;
    }
    while (inici.y < fi.y)
    {
        cout << "derecha ";
        inici.y++;
    }


    for (int i = 0; i < fi.cops; ++i)
    {
        cout << fi.digit;
    }
    cout << ' ';
    inici = fi;
}

void escriure_paraula(const string& s, lletra& inici) {
    for(int i =0; i < s.size(); ++i) {
        if (s[i] >= 'A' and s[i] <= 'Z')
        {
            //Quan majuscula
            if (!blok_mayus){
                blok_mayus = true;
                cami_letra2lletra(inici, lletra('#'));
            }
            cami_letra2lletra(inici, lletra(s[i]-'A'+'a'));
        }
        else
        {
            //Quan minuscula
            if (blok_mayus){
                blok_mayus = false;
                cami_letra2lletra(inici, lletra('#'));
            }
            cami_letra2lletra(inici, lletra(s[i]));
        }
    }
}

int main() {
    int n, i = 1;
    cin >> n;
    string line;
    while (getchar() != '\n');
    while (i <= n) {
        vector<string> paraules;
        getline(cin, line);
        eliminar_espais(line);
        eliminar_merda (line);
        separar_paraules(paraules, line);

        cout << "Case #" << i << ':';
        lletra actual('#');
        for (int j=0; j<paraules.size(); ++j) {
            escriure_paraula(paraules[j], actual);
            if (j != paraules.size()-1)cami_letra2lletra(actual, lletra(' '));
        }
        cout << endl;
        ++i;
    }
}
