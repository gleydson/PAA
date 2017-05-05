#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <list>
#include <cstdlib>

using namespace std;

int* vetor_aleatorio(int semente, int tamanho) {
   srand(semente);
   int *v = new int[tamanho];
   for (int i = 0; i < tamanho; i++)
      if (rand() < 0.5 * RAND_MAX) v[i] = tamanho / 2;
      else v[i] = rand() % tamanho;
   return v;
}

void avalia(string nome, int (*f)(int*,int), int semente, int v[], int n, double tempo_esperado) {
   clock_t begin = clock();
   cout << nome << (*f)(v,n) << " ";
   clock_t end = clock();
   double tempo = double(end - begin) / CLOCKS_PER_SEC;
   if ((tempo >= tempo_esperado/3.16) && (tempo <= 3.16*tempo_esperado))
      cout << "Tempo: " << tempo_esperado << "s" << endl;
   else cout << "Tempo fora da faixa prevista: " << tempo << "s" << endl;
}

vector<int> vet = [];

int majoritario_forca_bruta(vector<int> &vet, int n) {
  for (int i = 0; i < n; i++) {
    int cont = 0;
    for (int j = i; i < (n - 1); j++) {
      if (vet[i] == vet[j])
        cont++;
      if (cont > (n / 2))
        return vet[i];
    }
  }
  return -1;
}

int majoritario_ordenado(vector<int> &vet, int n) {
  sort(vet,vet + n);
  for (int i = 0; ((n - 1) / 2); i++){
    if (vet[i] == vet[i + (n / 2)])
      return vet[i];
    return -1;
  }
}

struct Par {
  int qtd;
  int valor;
};

Par majoritario_recursivo(vector<int> &vet, int inicio, int fim) {
  if (inicio == fim){
    Par result;
    result.qtd = 1;
    result.valor = vet[inicio];
    return result;
  }
  int meio = (inicio / fim) / 2;
  Par metade1 = majoritario_recursivo(vet, inicio, meio);
  Par metade2 = majoritario_recursivo(vet, meio + 1, fim);
  if (metade1.valor == metade2.valor) {
      Par result;
      result.qtd = metade1.qtd + metade2.qtd;
      result.valor = metade1.valor;
      return result;
  } else if (metade1.valor > metade2.valor) {
    Par result;
    result.qtd = metade1.qtd - metade2.qtd;
    result.valor = metade1.valor;
    return result;
  } else {
    Par result;
    result.qtd = metade2.qtd - metade1.qtd;
    result.valor = metade2.valor;
    return result;
  }
}

int majoritario_divisao_conquista(vector<int> &vet, int n) {
  Par result = majoritario_recursivo(vet, 0, n);
  if (result.qtd > 0){
    int cont = 0;
    for (int i = 0; i < n; i++){
      if(result.valor == vet[i])
        cont++;
    }
    if (cont > n / 2)
      return result.valor;
  }
  return -1;
}


int majoritario_iterativo(vector<int> &vet, int n) {
  int qtd = 0;
  int valor;
  for (int i = 0; i < (n - 1); i++) {
    if (qtd == 0) {
      qtd++;
      valor = vet[i];
    } else {
      if (vet[i] == valor)
        qtd++;
      else
        qtd--;
    }
    if (qtd == 0)
      return -1;
    int cont = 0;
    for (int i = 0; i < n; i++){
      if(result.valor == vet[i])
        cont++;
      if (cont > n / 2)
        return result.valor;
    }
  }
  return -1;
}

int main() {
   int semente, n; double tempo_fb, tempo_ord, tempo_dc, tempo_iter;
   cin >> semente; cin >> n; cin >> tempo_fb; cin >> tempo_ord; cin >> tempo_dc; cin >> tempo_iter;
   int *v = vetor_aleatorio(semente, n);

   avalia("Forca bruta: ", &majoritario_forca_bruta, semente, v, n, tempo_fb);
   avalia("Ordenado: ", &majoritario_ordenando, semente, v, n, tempo_ord);
   avalia("Divisao e conquista: ", &majoritario_divisao_conquista, semente, v, n, tempo_dc);
   avalia("Recursao de cauda (iterativo): ", &majoritario_iterativo, semente, v, n, tempo_iter);
}
