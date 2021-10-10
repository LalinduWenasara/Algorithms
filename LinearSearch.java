package linearsearch;
import java.util.Scanner;
public class LinearSearch {

public static void main(String args[]){
       int ar[] = new int[10];
       int i, number, m, d=0, position=0;
       Scanner sc = new Scanner(System.in);
      
       System.out.println("Enter your size of array");
       m = sc.nextInt();
      
       System.out.println("Enter your array");
       for(i=0; i<m; i++)
       {
           ar[i] = sc.nextInt();
       }
      
       System.out.println("what is the number you want to search position");
       number = sc.nextInt();
      
       for(i=0; i<m; i++)
       {
           if(ar[i] == number)
           {
               d = 1;
               position = i+1;
               break;
           }
       }
       if(d == 0)
       {
           System.out.println("Number Not Found..!! please try again!");
       }
       else
       {
           System.out.println(number+ " Position is: " + position);
       }
   }
}
