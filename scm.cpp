#include <iostream>

using namespace std;


float scm_forca_bruta(float S[], int n) {
     int maior = 0;
     for(int i = 0; i < n; i++)
          for (int j = 0; j < i + 1; j++)
               if (S[j] - S[i] > maior)
                    maior = S[j] - S[i];
     return maior;
}

struct Value {
     float min;
     float max;
     float scm;
}

Value SCM_DC_REC(float S[], int ini, int fim) {
     if (ini + 1 == fim) {
          Value v;
          v.min = min(S[ini], S[fim]);
          v.max = max(S[ini], S[fim]);
          v.scm = max(0, S[fim]-S[ini]);
          return v;
     }
     int meio = (ini + fim) / 2;
     Value v1 = SCM_DC_REC(S, ini, meio);
     Value v2 = SCM_DC_REC(S, meio, fim);
     Value final;
     final.min = min(v1.min, v2.min);
     final.max = min(v1.max, v2.max);
     final.scm = max(max(v1.scm, v2.scm), v2.max - v1.min);
     return final;
}

float scm_divisao_conquista(float S[], int n) {
   Value v = SCM_DC_REC(S, 0, n);
   return v.scm;
}

float SCM_ITERATIVO(float S[], int n) {
     float min1 = 0;
     float scm1 = 0;
     for (int i = 1; i <= n; i++) {
          scm1 = max(scm1, S[i] - min1);
          min1 = min(min1, S[i]);
     }
     return scm1;
}
