#include <algorithm>

using namespace std;

int dist_edicao(char A[], char B[], int m, int n){
    int matriz[m+1][n+1];

    matriz[0][0] = 0;
    
    for(int i = 1; i <= m; i++){
        matriz[i][0] = i;    
    }
    
    for(int j = 1; j <= n; j++){
        matriz[0][j] = j;    
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(A[i] == B[j]){
                matriz[i][j] = matriz[i-1][j-1];
            }
            else{
                matriz[i][j] = 1 + min(min(matriz[i-1][j-1], matriz[i][j-1]), matriz[i-1][j]);
            }
        }

    }
    return matriz[m][n];
}