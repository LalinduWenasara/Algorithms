
package selectionsort;

public class SelectionSort { 
    public static void selectionSort(int[] arr){  
        for (int i = 0; i < arr.length - 1; i++)  
        {  
            int in = i;  
            for (int k = i + 1; k < arr.length; k++){  
                if (arr[k] < arr[in]){  
                    in = k; 
                }  
            }  
            int sNumber = arr[in];   
            arr[in] = arr[i];  
            arr[i] = sNumber;  
        }  
    }  
       
    public static void main(String a[]){  
        int[] ar = {30,25,66,100,1,89,174,23,77,91,3};  
        System.out.println("Input Values before sorting");  
        for(int i:ar){  
            System.out.print(i+" ");  
        }  
        System.out.println();  
          
        selectionSort(ar);//sorting array using selection sort  
         
        System.out.println("Input Values After sorting");  
        for(int i:ar){  
            System.out.print(i+" ");  
        }  
    }  
}  