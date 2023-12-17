#include <iostream>
#define MAX_SIZE 100 // Set an appropriate value for MAX_SIZE

using namespace std;

//Tracking No. (sorting) - use mergesort, I.array[8]

void merge(int theArray[], int first, int mid, int last) {
    {
        int tempArray[MAX_SIZE]; // temp array
        int first1 = first; // first subarray begin
        int last1 = mid; // end of first subarray
        int first2 = mid + 1; // second subarray begin
        int last2 = last; // end of second subarray
        int index = first1; // next available location in tempArray

        for (; (first1 <= last1) && (first2 <= last2); ++index) {
            if (theArray[first1] < theArray[first2]) {
                tempArray[index] = theArray[first1];
                ++first1;
            }
            else {
                tempArray[index] = theArray[first2];
                ++first2;
            }
        }

        for (; first1 <= last1; ++first1, ++index) //copying elements from one array (theArray) to another (tempArray) within a specified range [first1, last1].
            tempArray[index] = theArray[first1];

        for (; first2 <= last2; ++first2, ++index)
            tempArray[index] = theArray[first2];

        for (index = first; index <= last; ++index)
            theArray[index] = tempArray[index];
    }
}

void mergeSort(int theArray[], int first, int last) {
    {
        cout << "Mergesort(arr, " << first << ", " << last << ")\n";
        if (first < last) {
            int mid = (first + last) / 2; // index of midpoint

            mergeSort(theArray, first, mid);
            mergeSort(theArray, mid + 1, last);
            merge(theArray, first, mid, last);
        }
    }
}

void dispItems(int theArray[], int n) {
    {
        for (int i = 0; i < n; ++i) {
            cout << theArray[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of data: ";
    cin >> n;

    int arr[n];
    cout << "Enter list of data: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    dispItems(arr, n);

    return 0;
}


