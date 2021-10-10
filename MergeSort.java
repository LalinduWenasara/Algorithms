package mergesort;

public class MergeSort {
 
void mge(int ar[], int st, int mi, int en)  
{  
  
int l = mi - st + 1;  
int r = en - mi;  
  
int LArray[] = new int [l];  
int RArray[] = new int [r];  
  
for (int i=0; i<l; ++i)  
LArray[i] = ar[st + i];  
  
for (int j=0; j<r; ++j)  
RArray[j] = ar[mi + 1+ j];  
  
  
int i = 0, j = 0;  
int k = st;  
while (i<l&&j<r)  
{  
if (LArray[i] <= RArray[j])  
{  
ar[k] = LArray[i];  
i++;  
}  
else  
{  
ar[k] = RArray[j];  
j++;  
}  
k++;  
}  
while (i<l)  
{  
ar[k] = LArray[i];  
i++;  
k++;  
}  
  
while (j<r)  
{  
ar[k] = RArray[j];  
j++;  
k++;  
}  
}  
  
void sort(int ar[], int st, int en)  
{  
if (st<en)  
{  
int mi = (st+en)/2;  
sort(ar, st, mi);  
sort(ar , mi+1, en);  
mge(ar,st,mi,en);  
}  
}  
public static void main(String args[])  
{  
int ar[] = {15,60,67,3,54,45,1,89,77,22,16,44,54};  
MergeSort ob = new MergeSort();  
ob.sort(ar, 0, ar.length-1);  
  
System.out.println("\nSorted array");  
for(int i =0; i<ar.length;i++)  
{  
    System.out.println(ar[i]+"");  
}  
}  
}  

