#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int n, i, j, k, fans;
    cout << "\n Enter Size :  ";
    cin >> n;
    int a[n][2];
    int ans[n], tv = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    int min, MIN, val;
    for (i = 0; i < n - 1; i++) // iterate n-1 times as n-1 times it is being multiplied in pairs
    {
        min = 0;
        MIN = (a[0][0] * a[0][1] * a[1][1]);
        for (j = 1; j < n; j++)
        {
            val = a[j][0] * a[j][1] * a[j + 1][1];
            if (MIN > val)
            {
                MIN = val;
                min = j;
            }
        }
        cout << "\n Minimum is " << MIN;
        ans[i] = min;
        tv += MIN;
        a[min][1] = a[min + 1][1];

        for (j = min + 1; j < n - 1; j++)
        {
            a[j][0] = a[j + 1][0];
            a[j][1] = a[j + 1][1];
        }
    }
    ans[n - 1] = 0;
    cout << "\n Minimum Cost is :  " << tv << "\n";
    for (i = 0; i < n; i++)
    {
        cout << "\n  The array A[" << ans[i] + 1 << "] is contracted with A[" << ans[i] + 1 << "]  ..";
    }
    for (i = 0; i < n; i++)
    {
        cout << "\n " << a[i][0] << " : " << a[i][1];
    }
    return 0;
}