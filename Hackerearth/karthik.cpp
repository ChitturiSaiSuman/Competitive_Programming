#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define mod 1000000009

vector<vector <ll>> bitpow (vector<vector <ll>> mat, ll n){
	vector<vector <ll>> res={{1,0},{0,1}};
	vector<vector <ll>> temp={{1,0},{0,1}};
	while(n>0){
		if(n&1){
temp[0][0]=res[0][0]*mat[0][0]%mod+res[0][1]*mat[1][0]%mod;
temp[0][1]=res[0][0]*mat[0][1]%mod+res[0][1]*mat[1][1]%mod;
temp[1][0]=res[1][0]*mat[0][0]%mod+res[1][1]*mat[1][0]%mod;
temp[1][1]=res[1][0]*mat[0][1]%mod+res[1][1]*mat[1][1]%mod;
	res[0][0]=temp[0][0];
	res[0][1]=temp[0][1];
	res[1][0]=temp[1][0];
	res[1][1]=temp[1][1];
		}
temp[0][0]=mat[0][0]*mat[0][0]%mod+mat[0][1]*mat[1][0]%mod;
temp[0][1]=mat[0][0]*mat[0][1]%mod+mat[0][1]*mat[1][1]%mod;
temp[1][0]=mat[1][0]*mat[0][0]%mod+mat[1][1]*mat[1][0]%mod;
temp[1][1]=mat[1][0]*mat[0][1]%mod+mat[1][1]*mat[1][1]%mod;	
	mat[0][0]=temp[0][0];
	mat[0][1]=temp[0][1];
	mat[1][0]=temp[1][0];
	mat[1][1]=temp[1][1];
n>>=1;
	}
	return res;
}

void solve(ll n){
	vector<vector <ll>> mat{{9,1},
						  {8,1}};
	mat=bitpow(mat,n);	
	ll res=(mat[0][0]+mat[0][1])%mod;
	cout << res <<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
	    solve(n);
	}
	return 0;
}