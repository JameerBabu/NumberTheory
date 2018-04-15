Consider sequences of parentheses (‘(’ and ‘)’) and square brackets (‘[’ and ‘]’). Sequence 
s
 is called regular if at least one of the following is true:
s
 is empty;
t
 is regular, and 
s
=
(
t
) or 
s
=
[
t
];
t
1
 and 
t
2
 are regular, and 
s
=
t
1
t
2
.
You are given integer 
n
. Print all regulard sequences of length 
n
 in lexicographical order. Brackets are compared as follows: ‘(’ 
<
 ‘[’ 
<
 ‘)’ 
<
 ‘]’.

Input format
The input consists of one integer 
n
 (
0
≤
n
≤
1
6
).
Output format
Print all sequences in lexicographical order. Print each sequence on a new line.


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
#define vvi vector<vector<int> >
#define vvb vector<vector<bool> >

#define epsilon 1e-7
#define MAX 1e10

#define WH 0
#define GR 1
#define BL 2


int n;

vector<vector<string>> v;
vector<unordered_map<string, bool> > m;



int main(){

	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	cin >> n;
if(!n || n&1)
	return 0;

	v.resize(n+1);
	m.resize(n+1);

	v[2].pb("(a");
	v[2].pb("[b");
	m[2]["(a"] = true;
	m[2]["[b"] = true;


	for (int a=4;a<=n;a+=2){

		for (auto x : v[a-2]){
			v[a].pb("(" + x + "a");
			m[a]["(" + x + "a"] = true;
		}

		for (int b=a-2; b>=2;b-=2){
			for (int i=0;i<v[b].size()/2;i++){
				for (auto x : v[a-b]){
					string s = v[b][i] + x;
					if (!m[a][s]){
						m[a][s] = true;
						v[a].pb(s);
					}
				}
			}
		}

		for (auto x : v[a-2]){
			v[a].pb("[" + x + "b");
			m[a]["[" + x + "b"] = true;
		}

		for (int b=a-2; b>=2;b-=2){
			for (int i=v[b].size()/2;i<v[b].size();i++){
				for (auto x : v[a-b]){
					string s = v[b][i] + x;
					if (!m[a][s]){
						m[a][s] = true;
						v[a].pb(s);
					}
				}
			}
		}
		sort(v[n].begin(), v[n].end());
	}


	for (auto x : v[n]){
		replace(x.begin(), x.end(), 'a',')');
		replace(x.begin(), x.end(), 'b',']');
		printf("%s\n",x.c_str());
	}
}
