#include "bits/stdc++.h"
#define ll long long
#define lld long double
#define itn int
#define MOD 1000000007LL
#define inf 1000000000000000000LL
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
ll power(ll x,ll y, ll md=MOD){ll res = 1;x%=md;while(y>0){if(y&1)res = (res*x)%md;x *= x; if(x>=md) x %= md; y >>= 1;}return res;}

#define endl '\n'
#define int ll

struct node {
	vector<int> v,w;
};

signed main() {
	fast;

	int t = 1;
	cin>>t;

	for(int a0=1;a0<=t;a0++) {

		int x, y;
		cin>>x>>y;

		string s;
		cin>>s;

		int n = s.size();

		int ans = inf;

		if(x==0 && y==0) ans = 0;

		for(int i=0;i<n;i++) {
			if(s[i]=='S') y--;
			else if(s[i]=='N') y++;
			else if(s[i]=='E') x++;
			else if(s[i]=='W') x--;

			if(abs(x)+abs(y)<=i+1) {
				ans = min(ans, i+1);
				break;
			}
		}

		if(ans==inf) cout<<"IMPOSSIBLE\n";
		else cout<<ans<<endl;
	}
}
