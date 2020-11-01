#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nax = 1e6+2;
const int MOD = 1e9+7LL;
inline void mul(ll&a, ll b){
	a = ((a%MOD)*(b%MOD))%MOD;
}
ll powr(ll a, ll b){
	ll x = 1LL;
	while(b){
		if(b&1) mul(x, a);
		mul(a, a), b>>=1;
	}
	return x%MOD;
}
bitset<nax> isprm;
vector<int> ans(nax, 0);
void seive(){
    isprm.reset();
    isprm[0] = isprm[1] = 1;
	for(int i = 4;i < nax; i+=2) isprm[i] = 1;
	for(ll i = 3;i < nax; i += 2){
		if(isprm[i]) continue;
		for(ll j = 2*i;j < nax; j += i){
			isprm[j] = 1;
		}
	}
	for(int i = 2;i < nax; ++i){
		ans[i] = ans[i - 1] + (isprm[i]^1);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	seive();
    int t;
	cin >> t;
	assert(1 <= t <= 1e6);
	while(t--){
		int n;
		cin >> n;
		assert(1 <= n <= 1e6);
        if(n == 0 || n == 1){
            cout << 0 << "\n";
            continue;
        }
		int x = ans[n];
		cout << powr(2, x - 1) << "\n";
	}
    return 0;
}
