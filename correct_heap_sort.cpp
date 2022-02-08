//Heap sort
#include <iostream>
using namespace std;
void heapify(int a[], int n, int i) // complexity is O(logn)
{
    int temp;
    int lar = i;       //assuming i is largest
    int l = 2 * i + 1; //thhis is done for left child , and its location is 2*i when parent's locn is i.
    //but here it is 2*i +1 as i=0, here.
    int r = 2 * i + 2;
    if (l < n && a[l] > a[lar]) //if lth element is larger, l means left child
        lar = l;
    if (r < n && a[r] > a[lar]) //if rth element is larger , r means right child
        lar = r;
    if (lar != i) //if we find element which is larger other than assumed , We wil swap on orginal array.
    {
        temp = a[i];
        a[i] = a[lar];
        a[lar] = temp;
        heapify(a, n, lar);
    }
    return;
}
void heapSort(int arr[], int n) //complexity is O(n)* O(heapify) i.e = O(nlogn)
{
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--) // here i 's initail value is n/2 -1 as we know leaf nodes has no child .
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) //sending to last , every root node to sort and again heapifying remaining node
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
int main()
{
    int n, i;
    cout << "\n Enter Size of array : ";
    cin >> n;
    int arr[n];
    cout << "\n Enter Elements : " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    heapSort(arr, n);
    printf("\nThe sorted array is  :  \n");
    for (i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
//O(n)