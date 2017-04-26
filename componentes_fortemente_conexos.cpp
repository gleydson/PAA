#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>

#define NULO -1

using namespace std;

enum Cores {branco, cinza, preto};

vector< list<int> >Adj;
vector< list<int> >AdjT;
vector<int> cor, pi, d, f;

list<int> ord_topologica;
int N;
int tempo;

bool DFS_VISIT(int u){
    cor[u] = cinza;
    d[u] = tempo;
    tempo = tempo + 1;
    list<int>::iterator it;

    for(it = Adj[u].begin(); it != Adj[u].end(); it++){
        if(cor[*it] == branco){
            pi[*it] = u;
            DFS_VISIT(*it);
        }
    }
    cor[u] = preto;
    f[u] = tempo;
    tempo = tempo + 1;
    ord_topologica.push_front(u);
    return true;
}

bool DFS(){
    for(int i = 0; i < N; i++){
        cor[i] = branco;
        pi[i] = NULO;
    }
    tempo = 1;
    for(int i = 0; i < N; i++){
        if(cor[i] == branco){
          DFS_VISIT(i);
        }
    }
    return true;
}

bool DFS_VISIT_T(int u){
    cor[u] = cinza;
    cout << u << " ";
    list<int>::iterator it;

    for(it = AdjT[u].begin(); it != AdjT[u].end(); it++){
        if(cor[*it] == branco) {
            DFS_VISIT_T(*it);
        }
    }
    cor[u] = preto;
    return true;
}

bool DFS_T() {
    for(int i = 0; i < N; i++){
        cor[i] = branco;
        pi[i] = NULO;
    }
    list<int>::iterator it;
    for(it = ord_topologica.begin(); it != ord_topologica.end(); it++){
        if(cor[*it] == branco){
            DFS_VISIT_T(*it);
            cout << endl;
        }
    }
    return true;
}

void le_grafo_lst() {
    string linha;
    for (int u = 0; getline(cin,linha); u++) {
        const string s = linha;
        Adj.push_back(list<int>());
        string::const_iterator ini = s.begin(), fim;
        if (ini == s.end()) continue;
        do {
            fim = find(ini,s.end(),' ');
            Adj[u].push_back(atoi(string(ini,fim).c_str()));
            ini = fim + 1;
        } while (fim != s.end());
    }
}

void inicializa(){
    cor.resize(Adj.size(),0);
    pi.resize(Adj.size(),0);
    d.resize(Adj.size(),0);
    f.resize(Adj.size(),0);
}

void transpor_list(){
    list<int>::iterator it;
    for (int i = 0; i < N; i++)
        for (it=Adj[i].begin(); it != Adj[i].end(); it++)
            AdjT[*it].push_back(i);
}


int main(){

    le_grafo_lst();
    inicializa();
    N = Adj.size();
    AdjT.resize(Adj.size());
    DFS();
    transpor_list();
    DFS_T();

    return 0;
}
