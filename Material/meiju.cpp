#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

bool used[MAX_N];
int perm[MAX_N];

void permutation1(int pos, int n)
{
    if(pos==n) {
        for(int i=0;i<n;i++)
            printf("%d",perm[i]);
        printf("\n");
        return ;
    }
    
    for(int i=0;i<n;i++)
    {
        if(!used[i]){
            perm[pos] = i;
            used[i] = true;
            permutation1(pos+1, n);
            used[i] = false;
        }
    }

    return ;
}

void permutation2(int n) {
    for(int i=0;i<n;i++)
        perm[i] = i;
    do {
        for(int i=0;i<n;i++)
            printf("%d",perm[i]);
        printf("\n");
    } while (next_permutation(perm, perm+n));
    return ;
}

int main()
{
    permutation1(0,2);
    permutation2(3);
    return 0;
}