#include <iostream>
using namespace std;

void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
mid=(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,high,mid);
    }
    return;
}
// Merge sort concepts starts here
void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
if (a[i] < a[j])
{
    c[k] = a[i];
    k++;
    i++;
}
else
{
    c[k] = a[j];
    k++;
    j++;
}
    }
    while (i <= mid)
    {
c[k] = a[i];
k++;
i++;
    }
    while (j <= high)
    {
c[k] = a[j];
k++;
j++;
    }
    for (i = low; i < k; i++)
    {
a[i] = c[i];
    }
}
// from main mergesort function gets called
int main()
{
    int a[30], i, b[30];
    cout<<"enter  the number of elements:";
    for (i = 0; i <= 5; i++) { cin>>a[i];
    }
    mergesort(a, 0, 4);
    cout<<"sorted array\n";
    for (i = 0; i < 5; i++)
    {
cout<<a[i]<<"\t";
    }
    cout<<"enter  the number of elements:";
    for (i = 0; i < 5; i++) { cin>>b[i];
    }
    mergesort(b, 0, 4);
    cout<<"sorted array:\n";
    for (i = 0; i < 5; i++)
    {
cout<<b[i]<<"\t";
    }
    getch();
}

