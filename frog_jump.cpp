#include <bits/stdc++.h>
#include <iostream>
#pragma GCC optimize("Ofast")
using namespace std;
int N=6;

#define NL "\n"
#define int long long int
#define all(x) x.begin() x.end()
const int mod = 1e9 + 7;

void readInputFile()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int N;

int minCost(int a, int b)
{
    return a > b ? b : a;
}

int minJump(int *a, int i)
{
    if (i + 1 == N)
    {
        return 0;
    }

    if (i + 2 == N)
    {
        return minJump(a, i + 1) + llabs(a[i] - a[i + 1]);
    }

    return minCost(minJump(a, i + 1) + llabs(a[i] - a[i + 1]), minJump(a, i + 2) + llabs(a[i] - a[i + 2]));
}

void solve()
{
    cout<<"\n The number of stones is 6 ...";
    int arr[N];
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << minJump(arr, 0);
}

int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    readInputFile();
    solve();

    return 0;
}