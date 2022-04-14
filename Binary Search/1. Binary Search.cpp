#include <bits/stdc++.h>
using namespace std;

#define N 10

int binarySearch(int* ara, int x)
{
    int l=0, r = N - 1;
    int mid = (l+r)/2;
    int ind = -1;

    while(l<=r){
        mid = (l+r)/2;
        if(ara[mid] == x){
            return mid;
        }
        else if(ara[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return ind;
}

int recBinarySearch(int *ara, int l, int r, int x)
{
    if( l <= r ){
        int mid = (l+r) / 2;
        if(ara[mid] == x) return mid;
        else if(ara[mid] < x)  return recBinarySearch(ara, mid + 1, r, x);
        else  return recBinarySearch(ara, l, mid - 1, x);
    }
    return -1;
}

int main()
{
    int ara[N] = {1,2,3,4,5,5,7,8,9,10};
    for(int x=1; x<=N; x++)
        cout << "X : " << x << " => " << recBinarySearch(ara, 0, N-1, x) << endl;
    
    return 0;
}