// lightoj.com/problem/triangle-partitioning

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

double bisection(double ab, double ac, double bc, double rg)
{
    double ad, ae, de, ec, bd;
    double l=0, r=ab;

        while(abs(r-l) >= .00000001){
            ad = (l+r)/2.000000; bd = ab - ad;
            ae = (ad/ab) * ac;  ec = ac - ae;
            de = (ad/ab) * bc;

            double sADE = (ad + de + ae)/2.0;
            double areaADE = sqrt(sADE*(sADE-ad)*(sADE-de)*(sADE-ae));

            double a = de, b = bc, c = ec, d = bd;
            double sDEBC = (a + b + c + d)/2.0;
            double areaDEBC = ((a+b)/abs(a-b)) * (sqrt( (sDEBC-b)*(sDEBC-a)*(sDEBC-b-c)*(sDEBC-b-d) ));
            
            double rf = areaADE/areaDEBC;
            
            if(rf == rg) break;
            else if(rf > rg) r = ad;
            else l = ad;
        }
    
    return ad;
}

double solve(double ab, double rg)
{
    double rf = rg / (rg + 1);
    return ab* sqrt(rf);
}

int main()
{   
    ll tcs, tc; cin >> tcs;

    for(tc = 1; tc <= tcs; tc++){
        double ab, ac, bc, rg;  cin >> ab >> ac >> bc >> rg;

        // double ad = bisection(ab, ac, bc, rg);
        double ad = solve(ab, rg);
        printf("Case %d: %.8lf\n", tc, ad);
    }
    return 0;
}