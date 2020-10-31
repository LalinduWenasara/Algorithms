#include <iostream>
using namespace std;

int main()
{
    int a[100], i, n, p, k, min, loc, tmp;

    cout << "\n------------ SELECTION SORT ------------ \n\n";
    cout << "Enter No. of Elements:"; cin >> n;

    cout << "\nEnter Elements:\n";
    for (i = 1; i <= n; i++) { cin >> a[i];
    }

    for (p = 1; p <= n - 1; p++) // Loop for Pass
    {
        min = a[p]; // Element Selection
        loc = p;

        for (k = p + 1; k <= n; k++) // Finding Min Value { if (min > a[k]) {
                min = a[k];
                loc = k;
            }
        }

        tmp = a[p];
        a[p] = a[loc];
        a[loc] = tmp;
    }
    cout << "\nAfter Sorting: \n";
    for (i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }
}
