#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int mod(int a, int b)
{
    if (a > b)
    {
        return (a - b);
    }
    else
    {
        return (b - a);
    }
}
int main()
{
    int n, k, i, j;
    cin >> n >> k;
    int ht[n], cst[n + 1];
    cst[0] = cst[1] = 0;
    for (i = 0; i < n; i++)
    {
        cin >> ht[i];
    }
    for (i = 2; i <= n; i++)
    {
        cst[i] = 999;
        for (j = i - 1; j >= i - k; j--)
        {
            if (cst[i] > (cst[j] + mod(ht[j], ht[i])))
            {
                cout << "\n -> " << mod(ht[j], ht[i]);
                cst[i] = cst[j] + mod(ht[j], ht[i]);
            }
        }
    }
    for (i = 1; i < n; i++)
    {
        cout << "\n " << cst[i];
    }
    return 0;
}