// Finding prime factors of a number for multiple queries in log(n) time.
// Sieve complexity: n*log(log(n))

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
#define MAXN 101010

const ld PI = acosl(-1.0);

//"Focus" on constraints.

ll spf[MAXN];

void modified_sieve()
{
	spf[1] = 1;
	for(ll i=2; i<MAXN; i++)
		spf[i]=i;

	for(ll i=4; i<MAXN; i+=2)
		spf[i]=2;

	for(ll i=3; i*i<MAXN; i++)
	{
		if(spf[i]==i)
		{
			for(ll j=i*i; j<MAXN; j+=i)
				if(spf[j]==j) spf[j]=i;
		}
	}
}

vi getfactors(ll n)
{
	vi v;
	while(n!=1)
	{
		v.pb(spf[n]);
		n/=spf[n];
	}
	return v;
}

int main()
{
	alpha
	
	modified_sieve();
	ll n;
	cin>>n;
	vi v = getfactors(n);
	output(v, v.size());
	return 0;
}
