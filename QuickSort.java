package quicksort;
import java.util.Scanner;

public class QuickSort {

void inArr(int arr[],int length)
 {
     Scanner sc=new Scanner(System.in);
     System.out.print("Input "+length+" elements: ");
    
     for(length--;length>=0;length--){
        arr[length]=sc.nextInt();
     }
 }
void pArray(int arr[],int length)
 {
     System.out.print("Given array Elements are: ");
     for(int i=0;i<length;i++)System.out.print(arr[i]+" ");
 }
void swap(int arr[],int i,int j)
{
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int part (int arr[], int low, int up)
{
    int i = (low - 1); 
    for (int j = low; j < up; j++)
    {
        if (arr[j] <= arr[up])
        {
            i++; 
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,up);
  
    return (i + 1);
}
void QuickSort(int arr[], int low, int up)
{
    if (low < up)
    {
        int piIndex = part(arr, low, up);
        QuickSort(arr, low, piIndex - 1);
        QuickSort(arr, piIndex + 1, up);
    }
}
public static void main(String args[])
{
    QuickSort ob = new QuickSort();
    int arr[] = new int[10];
    ob.inArr(arr,10);
    ob.QuickSort(arr,0,10-1);
    ob.pArray(arr,10);
}
}