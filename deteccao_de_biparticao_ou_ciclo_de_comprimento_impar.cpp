#include <iostream>
#include <list>
#include <stdlib.h>

using namespace std;

#define N 9
#define DENSIDADE 0.1

list<int> Adj[N];
enum Vertices{s,w,r,t,x,v,u,y};
enum Vertices2 {cueca, meia, calca, sapato, relogio, cinto, camisa, gravata, paleto};
enum Cor {branco, preto, cinza};

int cor[N];
int d[N];
int pi[N];
int f[N];
bool bi = true;
char c[N];

int tempo;

void imprime_ciclo_impar(int a, int b){
    int aux;
    cout << b << " ";
    aux = a;
    while(aux != b){
        cout << aux << " ";
        aux = pi[aux];
    }
}

bool DFS_VISIT(int n){
    cor[n] = cinza;
    d[n] = tempo;
    tempo = tempo + 1;
    list<int>::iterator it;
    for(it = Adj[n].begin(); it != Adj[n].end(); it++) {
        if (cor[*it] == branco) {
            pi[*it] = n;
            if(c[n] == 'A') {
                c[*it] = 'B';
            }
            else {
                c[*it] = 'A';
            }
            return  DFS_VISIT(*it);
        } else if(c[*it] == c[n]){
            imprime_ciclo_impar(n,*it);
            bi = false;
            return false;
        }
    }
    cor[n] = preto;
    f[n] = tempo;
    tempo = tempo + 1;
    return true;
}

bool DFS(){
    tempo = 1;
    for(int i = 0; i < N; i++){
        cor[i] = branco;
        pi[i] = -1;
    }
    for(int i = 0; i < N; i++){
        if(cor[i] == branco) {
            c[i] = 'A';
            if(DFS_VISIT(i) == false)
                return false;
        }
    }
    return true;
}

void inicializa_grafo() {
   enum Vertices {cueca, meia, calca, sapato, relogio, cinto, camisa, gravata, paleto};
                //    0     1      2       3        4      5       6        7       8
   Adj[cueca].push_back(calca);
   Adj[cueca].push_back(sapato);
   Adj[meia].push_back(sapato);
   Adj[calca].push_back(sapato);
   Adj[calca].push_back(cinto);
   Adj[camisa].push_back(cinto);
   Adj[camisa].push_back(gravata);
   Adj[cinto].push_back(paleto);
   Adj[gravata].push_back(paleto);

   // Transforma em não direcionado
   for (int u = 0; u < N; u++)
      for (list<int>::iterator v = Adj[u].begin(); v != Adj[u].end(); v++)
         Adj[*v].push_back(u);
}

int main(){
    int i;
    for(i = 0; i < N; i++)
        c[i] = '_';
    inicializa_grafo();
    DFS();
    cout << endl;
    cout << bi << endl;
    for(i = 0; i < N; i++)
        cout << c[i];
    return 0;
}