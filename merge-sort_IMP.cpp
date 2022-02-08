#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int m, int r) // T.C : O(n)
{
    int i, j, k, nl, nr;
    nl = m - l + 1;
    nr = r - m;
    int la[nl], ra[nr];
    for (i = 0; i < nl; i++) //left subarray la[] filled with elements upto middle of a[]
        la[i] = a[l + i];
    for (j = 0; j < nr; j++)
        ra[j] = a[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    //reassigning array a[]
    while (i < nl && j < nr) //condition such that every element in la[] and ra[] are taken in SORTED MERGED ARRAY.
    {
        if (la[i] <= ra[j])
        {
            a[k] = la[i];
            i++;
        }
        else
        {
            a[k] = ra[j];
            j++;
        }
        k++;
    }
    while (i < nl) //if all ra[] elements are consumed and la[] left.
    {
        a[k] = la[i];
        i++;
        k++;
    }
    while (j < nr) //if all la[] elements are consumed and ra[] left.
    {
        a[k] = ra[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid = (beg) + ((end - beg) / 2);
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}
// T(n)=2T(n/2)+ O(n)
// using 2nd case of Master's Theorem :
//O(nlogn)
int main()
{
    int i, n;
    cout << "Enter sizes array : ";
    cin >> n;
    int a[n];
    cout << "\n Enter  array Elements : ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    cout << endl;
    for (i = 0; i < n; i++)
    {
        cout << "  " << a[i];
    }
    return 0;
}
//O(n)
//overall O(nlogn)