//maximum subset sum less than s

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define alpha ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
#define fr(i, a, b) for(ll i=a; i<b; i++)
#define fr1(i, a, b) for(ll i=a; i>=b; i--)
#define input(arr,n) fr(i, 0, n) cin>>arr[i]
#define output(arr,n) fr(i, 0, n) cout<<arr[i]<<" "
#define min3(a, b, c) min(a,min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a,max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define vi vector<ll>
#define vii vector<pair<ll, ll> >
#define fixd(x) cout<<fixed<<setprecision(x);

#define dbg(args ...) cerr << __LINE__ << ": ", err(new istringstream(string(#args)), args), cerr << '\n'
void err(istringstream *iss) {}
template<typename T, typename ... Args> void err(istringstream *iss, const T &_val, const Args & ... args) {
    string _name;
    *iss >> _name;
    if (_name.back()==',') _name.pop_back();
    cerr << _name << " = " << _val << "; ", err(iss, args ...);
}

const ld PI = acosl(-1.0);

//"Focus" on constraints.

void calcsubsetsum(ll arr[], vi &a, ll n, ll c){
	ll sum;
	fr(i,0,1<<n){
		sum=0;
		fr(j,0,n){
			if(i & 1<<j)
				sum+=arr[j+c];
		}
		a[i]=sum;
	}
}

void solve(){
	ll n,s;
	cin>>n>>s;
	ll arr[n];
	input(arr, n);
	vi x(1<<n/2),y(1<<(n-n/2));
	calcsubsetsum(arr, x, n/2, 0);
	calcsubsetsum(arr, y, n-n/2, n/2);

	sort(all(y));

	ll mx=0;
	fr(i,0,x.size()){
		if(x[i]<=s){
			ll p = lower_bound(all(y), s-x[i])-y.begin();

			if(p==y.size() || y[p]!=(s-x[i])) p--;
			mx=max(mx, x[i]+y[p]);
		}
	}
	cout<<mx<<"\n";
}

int main(){
	alpha

	ll t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
