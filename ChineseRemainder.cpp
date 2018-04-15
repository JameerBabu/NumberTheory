Find integer solution for the following system of equations.
{
x
≡
a
(
mod
n
)
x
≡
b
(
mod
m
)
,
where 
n
 and 
m
 are guaranteed to be co-prime. If there are several valid 
x
 you should print minimal one.

Input format
The input contains four integers 
a
, 
b
, 
n
 and 
m
 (
1
≤
n
,
m
≤
1
0
6
, 
0
≤
a
<
n
, 
0
≤
b
<
m
).
Output format
Print minimal possible valid 
x
. It is guaranteed that at least one solution exists.


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;

int main()
{
    int n[2], r[2], ans = 1;
    cin >> r[0] >> r[1] >> n[0] >> n[1];
    while(true)
    {
        int i;
        for(i = 0; i < 2; i++)
        {
            if(ans%n[i] != r[i])
                break;
        }
        if(i == 2)
        {
            cout << ans << endl;
            return 0;
        }
        ++ans;
    }

}
