#include <bits/stdc++.h>
using namespace std;

int main()
{	

	long long n, i ,j;

	cin >> n;
	vector<int> v(n+1, true); 

	v[0] = v[1] = false;

	for(i = 2; i <= n; i++){
		if(v[i] && i*i <= n){
			// cout << i << "\n";
			for(j = i*i; j <= n; j+=i) v[j] = false;
		}
	}

	if(v[i]) cout << "\nPrime";
	else cout << "\nNot";
	cout << endl;


	
	return 0;
}