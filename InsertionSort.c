#include <iostream>
#include <conio.h>

int main()
{
    int a[16], i, j, k, tmp;
    cout << "enter the number of elements\n";
    for (i = 0; i < 6; i++) { cin >> a[i];
    }
    for (i = 1; i < 6; i++) { for (j = i; j >= 1; j--) {
            if (a[j] < a[j - 1]) {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
            else
                break;
        }
    }
    cout << "sorted array\n" << endl;
    for (k = 0; k < 6; k++) {
        cout << a[k] << "\t";
    }
}
