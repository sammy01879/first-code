
#include <iostream>
using namespace std;

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements (sorted): ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    int pos = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key) {
            pos = mid;
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if(pos != -1)
        cout << "Element found at index: " << pos << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
