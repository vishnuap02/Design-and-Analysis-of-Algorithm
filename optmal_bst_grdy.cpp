#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
class valpair
{
public:
    int val, fre;
    bool chk;
};
class optbst
{
public:
    int mini(valpair f[], int n)
    {
        int i, min = 0;
        for (i = 1; i < n; i++)
        {
            if ((f[i].fre < f[min].fre) && (f[i].chk == true))
            {
                min = i;
            }
        }
        f[min].chk = false;
        return min;
    }
    void optimal(valpair f[], int ans[], int n)
    {
        int i, j, k, sum = 0;
        for (i = 1; i <= n; i++)
        {
            k = mini(f, n);
            ans[i] = k;
            sum += ((f[k].fre) * i);
            cout << "\n " << sum << "  ";
        }
        cout << "\n The minimum Cost is :  " << sum;
    }
};
int main()
{
    optbst o;
    int n, i, fans;
    cout << "\n Enter Size :  ";
    cin >> n;
    valpair f[n]; // here we took frequency of occurence of elements , we can also take probability of occurence.
                  // cout << "\n Enter value of " << n << " elements  :  ";
    int ans[n];
    for (i = 0; i < n; i++)
    {
        cin >> fans;
        f[i].val = fans;
    }
    // cout << "\n Enter frequency of Occurence of " << n << " elements  :  ";
    for (i = 0; i < n; i++)
    {
        cin >> f[i].fre;
        f[i].chk = true;
    }
    o.optimal(f, ans, n);
    cout << "\n The Optimized BST  in  array format is  :    \n";
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << "  ";
        cout << f[ans[i]].val << "\n";
        cout << "  ";
        for (int j = 0; j < i; j++)
            cout << "  ";
    }
    return 0;
}
// T.C is O(nlogn)
/*
        bst < balanced bst < optimized bst

        if for example values be : 100  200  300
        and their frequency be   : 2  3  1
        there can be many ways to form BST. but optimized means there
        Summation of all height * frequency must be minimum

*/