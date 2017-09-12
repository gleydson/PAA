
/*
Retorna valor ótimo da mochila, e grava em pred o vetor de predecessores.
- W: tamanho inicial da mochila.
- n: número de itens.
- P: vetor de pesos dos itens, do índice 1 até n (inclusive).
- V: vetor de valores dos itens, do índice 1 até n (inclusive).
- pred: vetor de predecessores (inicializado com -1). 
        Ou seja, pred[w] contém o índice do item escolhido quando mochila tem 
        capacidade w, ou -1 se nenhum item cabe na mochila.
*/
double mochila_prog_din(int W, int n, int P[], double V[], int pred[]) {
    double mat[W+1][n+1];
    for(int w = 0; w <= W; w++) {
        for(int i = 0; i <= n; i++) {
            double maior = mat[w][i-1];
            if(P[i] <= w) {
                double v = V[i] + mat[w-P[i]][i-1];
                if(v > maior) {
                    maior = v;
                    pred[w] = i;
                }
            }
            mat[w][i] = maior;
        }
    }
    return mat[W][n];
}
