#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef priority_queue<int> pqb;
typedef priority_queue<int, vi, greater<int> > pqs;

#define iamtheflash         ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod                 1000000007
#define debug1(x)           cout<<"#x: "<<x<<"\n"
#define debug2(x,y)         cout<<"#x: "<<x<<" #y: "<<y<<"\n"
#define debug3(x,y,z)       cout<<"#x: "<<x<<" #y: "<<y<<" #z: "<<z<<"\n"
#define debug4(x,y,z,w)     cout<<"#x: "<<x<<" #y: "<<y<<" #z: "<<z<<" #w: "<<w<<"\n"
#define rep(i,n)            for(int i=0;i<(n);i++)
#define repl(i,n)           for(ll i=0;i<(n);i++)
#define fori(i,a,b)         for(int i=(a);i<=(b);i++)
#define forl(i,a,b)         for(ll i=(a);i<=(b);i++)
#define ford(i,a,b)         for(int i=(a);i>=(b);i--)
#define fordl(i,a,b)        for(ll i=(a);i>=(b);i--)
#define pb                  push_back
#define mp                  make_pair
#define ff                  first
#define ss                  second
#define mid(s,e)            (s+(e-s)/2)
#define setbits(x)          __builtin_popcountll(x)
#define zrobits(x)          __builtin_ctzll(x)
#define ps(x,y)             fixed<<setprecision(y)<<x
#define w(x)                int x; cin>>x; while(x--)
#define in(x)               int x; cin>>x;
#define ins(x)              string x; cin>>x;
#define endl                '\n'
#define infi                INT_MAX
#define infll               LLONG_MAX
#define infim               INT_MIN
#define infllm              LLONG_MIN
#define mk(arr,n,type)      type *arr = new type[n];
#define umap(x,type1,type2) unordered_map<type1, type2 > x;


struct activity {
	int a, b, c;
};

int solve(activity* arr, int n) {
	int dp[n + 1][3];
	dp[1][0] = arr[1].a;
	dp[1][1] = arr[1].b;
	dp[1][2] = arr[1].c;

	fori(i, 2, n) {
		dp[i][0] = arr[i].a + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = arr[i].b + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = arr[i].c + max(dp[i - 1][0], dp[i - 1][1]);
	}

	return max({dp[n][0], dp[n][1], dp[n][2]});
}

int32_t main() {
	iamtheflash

	in(n);

	mk(arr, n + 1, activity);
	fori(i, 1, n) {
		cin >> arr[i].a;
		cin >> arr[i].b;
		cin >> arr[i].c;
	}

	cout << solve(arr, n);

	return 0;
}
