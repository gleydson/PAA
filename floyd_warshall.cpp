#include <algorithm>

template <const unsigned int N>

void floyd_warshall(double w[N+1][N+1], double D[N+1][N+1][N+1]){
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            D[i][j][0] = w[i][j];
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                D[i][j][k] = min(D[i][j][k - 1], D[i][k][k - 1] + D[k][j][k - 1]);
            }
        }
    }
}
