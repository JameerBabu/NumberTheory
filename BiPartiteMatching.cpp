Legend
Let us consider a bipartite graph with n+m vertexes. The left set contains n vertexes. Every vertex has a integer written in it a1, a2, …, an. The right set contains m vertexes. Every vertex has a integer written in it b1, b2, …, bm. i-th vertex of left set and j-th vertex of right set are connected by edge only if ai 
≥
 bj.

Count the number of different matchings containing m edges in this graph.

Input format
First line contains two integers n and m, 1 
≤
 n, m 
≤
 105. Second line contains integers a1, a2, …, an, 1 
≤
ai 
≤
 106 separated by a space. Third line contains integers b1, b2, …, bm, 1 
≤
 bi 
≤
 106 separated by a space.

Output format
Output one integer - answer to the problem modulo 109+7.

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vvb vector<vector<bool> >

#define epsilon 1e-7
#define MAX 1e10
#define MOD 1000000007

int n,m;
vi a,b;

struct comp{
	bool operator() (const int& x, const int& y){
		return (x<=y);
	};
};

int main(){

	cin >> n >> m;
	a.resize(n);
	b.resize(m);

	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	for (int i=0;i<m;i++){
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll ans = 1;
	for (int i=m-1;i>=0;i--){
		auto it = upper_bound(a.begin(), a.end(), b[i], comp());
		// cout << "here " << *it << endl;
		ll num = (a.end() - it) - (m-1-i);
		if (num<=0){
			cout << 0 << endl;
			exit(0);
		}
		ans = (ans*num) % MOD;
	}

	cout << ans << endl;
	return 0;
}
