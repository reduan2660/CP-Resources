#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define N 10

// returns index which which compares greater than val.
int upperBound(int *ara, int x)
{
    int l=0, r = N-1, mid, ind = -1;

    // check 1: if x is greater than the greates value of x return -1
    if(x > ara[r]) return ind;

    while(l<=r){
        mid = (l+r)/2;
        ind = mid; // store the closest value so that even if x not found in array we get the closest value

        if(ara[mid] == x){
            if(mid == N-1) return -1; // there is no greater value than ara[mid]
            else if(ara[mid+1] == ara[mid]) l = mid + 1; // if next value is equal keep searching
            else return ++mid;
        }

        else if(ara[mid] < x) l = mid + 1;
        else r = mid - 1;
    }

    // check 2: if x not found value might be lower than x
    if(ara[mid] < x) ++mid;
    return ind;
}

// returns index which does not compare less than val.
int lowerBound(int *ara, int x)
{
    int l=0, r=N-1, mid, ind = -1;
    if(x > ara[r]) return ind;

    while(l<=r ){

        mid = (l+r) /2;

        ind = mid;
        if(mid == 0) return mid;
        else if(ara[mid] == x){
            
            if(ara[mid - 1] < x){
              return mid;
            }
            else r = mid - 1;
        }
        else if(ara[mid] < x) l = mid + 1;
        else if(ara[mid] > x) r = mid - 1;
    }

    return ind;
}


int maxMin(int* ara, int x)
{
    int l=0, r=N-1, ind = -1, mid;

    if(x < ara[0]) return ind;

    while(l<=r){
        mid = (l+r) / 2;
        // printf("%d %d %d\n", l, r, mid);
        
        ind = mid;
        if(ara[mid] == x){
            if(mid == 0) return -1;
            else if(ara[mid-1] -1 == ara[mid]) r = mid - 1;
            else return --mid;
        }
        else if(ara[mid] < x) l = mid + 1;
        else r = mid -1;
    }

    if(ara[ind] > x) --ind;
    return ind;
}


int minMax(int* ara, int x)
{
    int l=0, r=N-1, mid, ind = -1;

    if(ara[r] < x) return ind;
    while (l<=r)
    {
        mid = (l+r)/2;
        ind = mid;

        if(ara[mid] == x){
            if(mid == N-1) return -1;
            else if(ara[mid + 1] == ara[mid]) l = mid+1;
            else return ++mid;
        }

        else if(ara[mid] < x) l = mid + 1;
        else r = mid -1;
    }
    
    if(ara[ind] < x ) ++ind;
    return ind;
}


int main()
{
    int ara[N] = {1,2,3,4,5,5,7,8,9,10};

    vector<int> v;
    for(int x: ara) v.push_back(x);

    int xs[] = {5, 3, 6, 1, 10, 0, 11};
    for(auto x : xs){
        int lbi = lowerBound(ara,x), ubi = upperBound(ara, x), mxmni = maxMin(ara,x), mnmxi = minMax(ara, x);

        if(lbi == -1) cout  << x << " Lower Bound: X ";
        else cout  << x << " Lower Bound: " << ara[lbi] << " ";

        if(ubi == -1) cout << "Upper Bound: x" << " ";
        else cout << "Upper Bound: " << ara[ubi] << " ";

        if(lbi == -1) cout << "Max low: X ";
        else cout << "Highest Min: " << ara[mxmni] << " ";

        if(ubi == -1) cout << "Min high: x" << endl;
        else cout << "Min high: " << ara[mnmxi] << endl;
        

    }

    return 0;
}