#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 999999;

int main()
{
    int n, i, x, j;
    cout << " \n No. of denoms : ";
    cin >> n;
    int a[n];
    cout << " \n Enter unique denoms : (Containing 1)";
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << "\n Enter amount to give change :  ";
    cin >> x;
    int ans[x + 1], tot[x + 1][n] = {0};
    ans[0] = 0;
    ans[1] = 1;
    bool chk[x + 1] = {false};
    chk[0] = chk[1] = true;
    for (i = 0; i <= x; i++)
    {
        j = 0;
        if (chk[i] = true)
        {
            continue;
        }
        ans[i] = INF;
        for (auto c : a) // every coin
        {
            if ((i - c) >= 0 && (ans[i] > ans[i] + 1))
            {
                ans[i] = ans[i - c] + 1;
                tot[i][j] = c;
            }
        }
    }
    for (i = 0; i <= x; i++)
    {
        cout << "\n For amount " << i << " the number of coins is :  " << ans[i];
    }
    return 0;
}