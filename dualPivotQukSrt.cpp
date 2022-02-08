//
#include <bits/stdc++.h>
using namespace std;
class DulqkSort
{
public:
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int partit(int *a, int l, int h, int *p2)
    {
        // here initially we assume 1st pivot 'p' is h(high) & 2nd 'q' is low and start bringing it to position.
        if (a[l] > a[h])
        {
            swap(&a[l], &a[h]);
        }
        int j = l + 1;
        int g = h - 1, k = l + 1, p = a[l], q = a[h]; // p and q are pivot 1 and pivot2.
        while (k <= g)
        {
            if (a[k] < p) // when i start finding position of pivot p , swap elements when a[k] starts becoming lesser than p.
            {
                swap(&a[k], &a[j]);
                j++;
            }
            else if (a[k] >= q)
            {
                while (a[g] > q && k < g) // for 2nd subarray , i.e values between 2 pivots : p<a[x]<q
                    g--;
                swap(&a[k], &a[g]);
                g--;
                if (a[k] < p) // if elements are lesser than pivot1 then swap with a[k]
                {
                    swap(&a[k], &a[j]);
                    j++;
                }
            }
            k++;
        }
        j--;
        g++;
        swap(&a[l], &a[j]); // bringing 2nd pivot to position
        swap(&a[h], &a[g]); // bringing 1st pivot to position
        *p2 = j;
        return g;
    }
    // T.C is O(n square) in worst case.
    void DualPtQk(int *arr, int low, int high)
    {
        if (low < high)
        {
            int lp, rp;
            rp = partit(arr, low, high, &lp);
            DualPtQk(arr, low, lp - 1);
            DualPtQk(arr, lp + 1, rp - 1);
            DualPtQk(arr, rp + 1, high);
        }
    }
};
// T.C is O(n cube ) , where O(n square) is from function partition.
int main()
{
    DulqkSort q;
    int n, i;
    cout << " \n Enter size of array :  ";
    cin >> n;
    int a[n];
    cout << " \n Enter  array Elements : \n ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    q.DualPtQk(a, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
// overall T.C is O(n cube ).