#include <iostream>
#include <list>

using namespace std;

#define N 8

enum Vertices {s,t,u,v,x,y,w,z};
enum Cor {branco, preto, cinza};

list<int> *Adj;
int cor[N];
int d[N];
int pi[N];
int f[N];

int tempo;

list<int>::iterator it;

void DFS_VISIT(int vert) {
   cor[vert] = cinza;
   d[vert] = tempo + 1;
   tempo++;
list<int>::iterator it;
   for (it = Adj[vert].begin(); it != Adj[vert].end(); it++) {
      if (cor[*it] == branco) {
         pi[*it] = vert;
         DFS_VISIT(*it);
      }
   }
   cor[vert] = preto;
   f[vert]= tempo + 1;
   tempo++;
}

void DFS() {
     for(int i = 0; i < N; i++) {
          cor[i] = branco;
          pi[i] = -1;
     }
     tempo = 0;

     for(int i = 0; i < N;i++){
          if (cor[i] == branco)
               DFS_VISIT(i);
     }
}

void inicializa_grafo() {
     Adj = new list<int>[N];
    Adj[s].push_back(z);
   Adj[s].push_back(w);
   Adj[z].push_back(y);
   Adj[z].push_back(w);
   Adj[y].push_back(x);
   Adj[x].push_back(z);
   Adj[w].push_back(x);
   Adj[t].push_back(v);
   Adj[t].push_back(u);
   Adj[v].push_back(w);
   Adj[v].push_back(s);
   Adj[u].push_back(v);
   Adj[u].push_back(t);
}

int main() {
    inicializa_grafo();
    DFS();
    int i;
    for(i = 0; i < 8; i++)
        cout << d[i] << " ";
    cout << endl;
    for(i = 0; i < 8; i++)
        cout << f[i] << " ";
    cout << endl;
    for(i = 0; i < 8; i++)
        cout << pi[i] << " ";
     return 0;
}