#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

#define N 8

enum vertices {s, w, r, t, x, v, u, y};
enum cores {branco, cinza, preto};

list<int> *Adj;
list<int> fila;

int cor[N];
int d[N];
int pi[N];

void BFS(int vert) {
     list<int>::iterator it;
     for(int i = 0; i < N; i++) {
          cor[i] = branco;
          d[i] = INT_MAX;
          pi[i] = -1;
     }

     cor[vert] = cinza;
     d[vert] = 0;
     pi[vert] = -1;

     fila.push_front(vert);
     while (!fila.empty()) {
           vert = fila.front();
         fila.pop_front();
          for (it = Adj[vert].begin(); it != Adj[vert].end(); it++) {
               if (cor[*it] == branco) {
                    cor[*it] = cinza;
                    pi[*it] = vert;
                    d[*it] = d[pi[*it]] + 1;
                    fila.push_back(*it);
               }
          }

          cor[vert] = preto;
     }
}

void inicializa_grafo() {
    Adj = new list<int>[N];
   Adj[s].push_back(w);
   Adj[s].push_back(r);
   Adj[r].push_back(s);
   Adj[r].push_back(v);
   Adj[v].push_back(r);
   Adj[w].push_back(s);
   Adj[w].push_back(t);
   Adj[w].push_back(x);
   Adj[t].push_back(w);
   Adj[t].push_back(x);
   Adj[t].push_back(u);
   Adj[x].push_back(w);
   Adj[x].push_back(t);
   Adj[x].push_back(u);
   Adj[x].push_back(y);
   Adj[u].push_back(t);
   Adj[u].push_back(x);
   Adj[u].push_back(y);
   Adj[y].push_back(x);
   Adj[y].push_back(u);
}

int main() {
     inicializa_grafo();
     BFS(s);
     int i;
     for (i = 0; i < 8; i++)
         cout << d[i] << " ";
     cout << endl;
     for (i = 0; i < 8; i++)
         cout << pi[i] << " ";
     return 0;
}
