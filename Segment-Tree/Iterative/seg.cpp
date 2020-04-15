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
#define input(v,n) for(ll ppp=0; ppp<n; ppp++) cin>>v[ppp]
#define output(v,n) for(ll ppp=0; ppp<n; ppp++) cout<<v[ppp]<<" "
#define min3(a, b, c) min(a,min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a,max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define vi vector<ll>
#define vii vector<pair<ll, ll> >

const ld PI = acosl(-1.0);

//"Focus" on constraints.

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  	for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  	for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  	int res = 0;
  	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    	if (l&1) res += t[l++];
    	if (r&1) res += t[--r];
  }
  return res;
}

int main()
{
	alpha

	scanf("%d", &n);
  	for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  	build();
  	// for(int i=0; i<2*n; i++) cout<<t[i]<<" ";
  	modify(0, 1);
  	printf("%d\n", query(0, n));
	return 0;
}
