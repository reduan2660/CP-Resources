#include <bits/stdc++.h>
using namespace std;


int SieveOfEratosthenes()
{	

	long long n, i ,j;

	cin >> n;
	vector<int> flag(n+1, true); 

	flag[0] = flag[1] = false;
	for(j = 4; j <= n; j+=2) flag[j] = false;

	for(i = 3; i <= n; i+=2){
		if(flag[i] && i*i <= n){  // to check prime
		// if(flag[i]){           // to find all primes up to n
		// 	cout << i << "\n";
			for(j = i*i; j <= n; j+=i) flag[j] = false;
		}
	}

	if(flag[i]) cout << "Prime";
	else cout << "Not";
	cout << endl;


	
	return 0;
}


/// Yarin's Sieve

bool Check(int N, int pos){
	return (bool)(N & (1<<pos));
}
int Set(int N, int pos){
	return N= N | (1<<pos);
}
int yarinsSieve()
{
	int n, i,j;
	cin >> n;
	int flagSize = ceil(n/32);
	int flag[flagSize] = {0};

	flag[2/32] = Set(flag[2/32], 2/32);
	for(j = 4; j <= n; j +=2)
	{
		flag[j/32] = Set(flag[j/32], j%32);
	}

	for(i = 3;i<=n; i+=2){
		if(!Check(flag[i>>5], i&31) && i*i <= n){  //if(!Check(flag[i/32], i%32) && i*i <= n)
		// if( Check(flag[i/32], i%32) == 0){    // to find all primes up to N
			// cout << i << endl;
			for(j = i*i; j <= n; j += 2*i)
			{
				flag[j>>5] = Set(flag[j>>5], j&31);
			}
		}
	}

	if(!Check(flag[n/32], n%32)) cout << "Prime" << endl;
	else cout << "Not" << endl;
	return 0;

}

int main()
{

	// SieveOfEratosthenes();
	yarinsSieve();
	return 0;
}
