#include <stdio.h>
#include <stdlib.h>

int A[] = {-1, 4, 58, 5489, 23, 0, 2, 1, 41};
void merge(int *A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j;
    int L[n1+1];
    int R[n2+1];
    for(i = 1; i<=n1; i++)
    {
        L[i] = A[p+i-1];
    }

    for(j = 1; j <= n2; j++)
    {
        R[j] = A[q+j];
    }
    i = 1;
    j = 1;
    int k = p;
    while(i <= n1 && j <= n2){
        if(L[i] <= R[j]){
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }
    while(i <= n1){
        A[k++] = L[i++];
    }
    while(j <= n2){
        A[k++] = R[j++];
    }
}
void merge_sort(int *A, int p, int r)
{
    int q = (p+r) >> 1;
    if(p < r)
    {
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A, p, q, r);
    }
}
int main()
{
    merge_sort(A, 1, 8);
    int i;
    for(i = 1; i<=8; i++)
    {
        printf("%d\t", A[i]);
    }
    return 0;
}
