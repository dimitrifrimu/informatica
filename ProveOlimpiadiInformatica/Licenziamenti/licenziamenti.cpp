#include <stdio.h>
#include <assert.h>

#define MAXN 100000


int BravuraMin(int brMin,int i,int N, int B[], int C[]){

    if (C[i]==-1)
        return brMin;
    else
        brMin= B[i]<brMin ? B[i] : brMin;
        BravuraMin(B[C[i]],i,N,B,C);


}


int licenzia(int N, int B[], int C[]) {
    int nl=1231244;
    int brMin=B[0];

    for (int i=1;i<N;i++){
        BravuraMin(brMin,i, N, B, C);
    }


    return nl;
}


int B[MAXN], C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d %d", &B[i], &C[i]));

    fprintf(fw, "%d\n", licenzia(N, B, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
