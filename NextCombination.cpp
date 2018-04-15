#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
unsigned long long arr[52];
unsigned long long ans[52];
unsigned long long last[52];
int main()
{
    int n, k;
    cin >> n >> k;
    bool flag = false;
    for(int i = 0; i < k; ++i)
        cin >> arr[i];
    for(int i = 0; i < k; ++i)
    {
        last[i] = n - k + i + 1;
        if(last[i] != arr[i])
            flag = true;
    }
    if(!flag)
        cout << 0 << endl;
    else
    {
        if(arr[k - 1] != n)
        {
            arr[k - 1]++;
            for(int i = 0; i < k; ++i)
                cout << arr[i] << ' ';
        }
        else
        {
            int i;
            for(i = k - 2; i >= 0; --i)
            if(arr[i + 1] - arr[i] > 1)
                break;
            for(int j = 0; j < i; ++j)
                cout << arr[j] << ' ';
            ans[i] = arr[i] + 1;
            for(int j = i; j < k; ++j)
                cout << ans[i]++ << ' ';
        }
    }
}
