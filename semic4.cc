#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
using namespace std;

struct point {
    int x, y, xa, ya;
};

typedef vector< vector<string> > graph;

point create_point(int x, int y, int xa, int ya) {
    point p;
    p.x = x;
    p.y = y;
    p.xa = xa;
    p.ya = ya;
    return p;
}

void read_matrix(graph& map, point& p) {
    string line;
    getline(cin, line);
    while(line.empty()) getline(cin, line);
    int m = line.size()+2;
    int cont = 1;
    vector<string> va(m, "#");
    map.push_back(va);
    while (line.size() == m-2) {
        vector<string> v(m, "#");
        for (int i=1; i<m-1; ++i) {
            v[i] = line[i-1];
            if (v[i] == "A") {
                p.x = cont;
                p.y = i;
                p.xa = -1;
                p.ya = -1;
            }
        }
        ++cont;
        map.push_back(v);
        getline(cin, line);
    }
    map.push_back(va);
}

void bfs_ite(graph& G, vector<point>& v, point& b) {
    int i = 0;
    while (true) {
        point p = v[i];
        if (G[p.x][p.y] == "B") {
            b = p;
            return;
        } else if (G[p.x][p.y] == ".") {
            if (G[p.x-1][p.y] != "#") v.push_back(create_point(p.x-1, p.y, p.x, p.y));
            if (G[p.x+1][p.y] != "#") v.push_back(create_point(p.x+1, p.y, p.x, p.y));
            if (G[p.x][p.y-1] != "#") v.push_back(create_point(p.x, p.y-1, p.x, p.y));
            if (G[p.x][p.y+1] != "#") v.push_back(create_point(p.x, p.y+1, p.x, p.y));
            G[p.x][p.y] = "#";
        }
        ++i;
    }
}

int main() {
    int n, c;
    cin >> n >> c;
    while (c <= n) {
        point p, b;
        graph map;
        read_matrix(map, p);
        map[p.x][p.y] = ".";
        graph map2 = map;
        vector<point> v;
        v.push_back(p);
        bfs_ite(map, v, b);
        point l = b;
        vector<point> cami;
        for (int i=v.size()-1; i>=0; --i) {
            if (v[i].x == l.xa and v[i].y == l.ya) {
                l = v[i];
                cami.push_back(l);
            }
        }

        for (int i=1; i<cami.size()-1; ++i) {
            if (cami[i].x == cami[i-1].x+1 and cami[i].x == cami[i+1].x-1) map2[cami[i].x][cami[i].y] = "|";
            else if (cami[i].x == cami[i+1].x+1 and cami[i].x == cami[i-1].x-1) map2[cami[i].x][cami[i].y] = "|";

            else if (cami[i].y == cami[i-1].y-1 and cami[i].y == cami[i+1].y+1) map2[cami[i].x][cami[i].y] = "-";
            else if (cami[i].y == cami[i+1].y-1 and cami[i].y == cami[i-1].y+1) map2[cami[i].x][cami[i].y] = "-";

            else if (cami[i].x == cami[i-1].x-1 and cami[i].y == cami[i+1].y-1) map2[cami[i].x][cami[i].y] = "┌";
            else if (cami[i].x == cami[i+1].x-1 and cami[i].y == cami[i-1].y-1) map2[cami[i].x][cami[i].y] = "┌";

            else if (cami[i].x == cami[i-1].x-1 and cami[i].y == cami[i+1].y+1) map2[cami[i].x][cami[i].y] = "┐";
            else if (cami[i].x == cami[i+1].x-1 and cami[i].y == cami[i-1].y+1) map2[cami[i].x][cami[i].y] = "┐";

            else if (cami[i].x == cami[i-1].x+1 and cami[i].y == cami[i+1].y-1) map2[cami[i].x][cami[i].y] = "└";
            else if (cami[i].x == cami[i+1].x+1 and cami[i].y == cami[i-1].y-1) map2[cami[i].x][cami[i].y] = "└";

            else if (cami[i].x == cami[i-1].x+1 and cami[i].y == cami[i+1].y+1) map2[cami[i].x][cami[i].y] = "┘";
            else if (cami[i].x == cami[i+1].x+1 and cami[i].y == cami[i-1].y+1) map2[cami[i].x][cami[i].y] = "┘";
        }

        if (cami[0].x == b.x+1 and cami[0].x == cami[1].x-1) map2[cami[0].x][cami[0].y] = "|";
        else if (cami[0].x == cami[1].x+1 and cami[0].x == b.x-1) map2[cami[0].x][cami[0].y] = "|";

        else if (cami[0].y == b.y-1 and cami[0].y == cami[1].y+1) map2[cami[0].x][cami[0].y] = "-";
        else if (cami[0].y == cami[1].y-1 and cami[0].y == b.y+1) map2[cami[0].x][cami[0].y] = "-";

        else if (cami[0].x == b.x-1 and cami[0].y == cami[1].y-1) map2[cami[0].x][cami[0].y] = "┌";
        else if (cami[0].x == cami[1].x-1 and cami[0].y == b.y-1) map2[cami[0].x][cami[0].y] = "┌";

        else if (cami[0].x == b.x-1 and cami[0].y == cami[1].y+1) map2[cami[0].x][cami[0].y] = "┐";
        else if (cami[0].x == cami[1].x-1 and cami[0].y == b.y+1) map2[cami[0].x][cami[0].y] = "┐";

        else if (cami[0].x == b.x+1 and cami[0].y == cami[1].y-1) map2[cami[0].x][cami[0].y] = "└";
        else if (cami[0].x == cami[1].x+1 and cami[0].y == b.y-1) map2[cami[0].x][cami[0].y] = "└";

        else if (cami[0].x == b.x+1 and cami[0].y == cami[1].y+1) map2[cami[0].x][cami[0].y] = "┘";
        else if (cami[0].x == cami[1].x+1 and cami[0].y == b.y+1) map2[cami[0].x][cami[0].y] = "┘";

        cout << c << endl;
        map2[p.x][p.y] = "A";
        for (int i=1; i<map2.size()-1; ++i) {
            for (int j=1; j<map2[0].size()-1; ++j) cout << map2[i][j];
            cout << endl;
        }
        ++c;
    }
}

