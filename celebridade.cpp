#include <iostream>

using namespace std;

void CELEBRIDADE(M, ini, fim) {
  if (ini == fim)
    return ini;
  if (M[ini,fim]) == 1)
    return CELEBRIDADE(M, ini + 1, fim);
  else
    return CELEBRIDADE(M, ini, fim - 1);
}

int main() {
  int c = CELEBRIDADE(M, 1, n);
  //verifique se c é celebridade
  return 0;
}
