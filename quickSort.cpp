#include <bits/stdc++.h>
using namespace std;
class qkSort
{
public:
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    int partit(int a[], int low, int hi, int n)
    {
        int st, end, pivot, i;
        st = low;
        end = hi;
        pivot = low;
        while (st < end)
        {
            while (a[st] < a[pivot])
                st++;
            while (a[end] > a[pivot])
                end--;
            if (st < end)
            {
                swap(&a[st], &a[end]);
            }
        }
        swap(&a[end], &a[pivot]);
        return end;
    }
    void quicksrt(int a[], int low, int high, int n)
    {
        if (low < high)
        {
            int pivot = partit(a, low, high, n);
            quicksrt(a, low, pivot - 1, n);
            quicksrt(a, pivot + 1, high, n);
        }
    }
};
int main()
{
    qkSort q;
    int a[] = {7, 6, 1, 3, 4, 9};
    int n = 6, i;
    q.quicksrt(a, 0, n - 1, n);
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}