#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_map>
#define ULL unsigned long long
using namespace std;
unsigned long long fact[13];
int main()
{
    fact[0] = 1;
    for(int i = 1; i < 13; ++i)
    {
        fact[i] = i * fact[i - 1];
    }
    int n;
    cin >> n;
    unsigned long long ans = 0;

    unordered_map<int, bool> map;
    for(int i = 0; i < n - 1; ++i)
    {
        int x;
        cin >> x;
        int mul = x-1;
        for(int i = 1; i < x; i++){
            if(map[i]) mul--;
        }
        ans += mul * fact[n - i - 1];
        map[x] = true;
    }
    cout << ans+1 << endl;
}
