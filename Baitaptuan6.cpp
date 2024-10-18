#include <iostream>

using namespace std;

void selectionSort(int a[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
       min_idx = i;
      for (j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;
                swap(a[min_idx], a[i]);
        cout << "Vong lap " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;

    }
}
void insertionSort(int b[], int h) {
    for (int i = 1; i < h; i++) {
        int key = b[i];
        int j = i - 1;
        while (j >= 0 && b[j] > key) {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
        cout << "Vong lap " << i << ": ";
        for (int k = 0; k < h; k++) {
            cout << b[k] << " ";
        }
        cout << endl;

    }
}

   void bubbleSort(int c[], int v) {
    for (int i = 0; i < v - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < v - i - 1; j++) {
            if (c[j] > c[j + 1]) {
                swap(c[j], c[j + 1]);
                swapped = true;
            }
        }
        cout << "Vong lap " << i + 1 << ": ";
        for (int l = 0; l < v; l++) {
            cout << c[l] << " ";
        }
        cout << endl;
        if (!swapped) {
            break;
            }
    }
}
void printfselection(int a[], int size) {
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

void printfinsertion(int b[], int size) {
    for (int i = 0; i < size; i++)
        cout << b[i] << " ";
    cout << endl;
}

void printfbubbleSort(int c[], int size) {
    for (int i = 0; i < size; i++)
        cout << c[i] << " ";
    cout << endl;

}

int main() {
    int a[12] = {17,23,201,98,67,83,13,23,10,191,84,58};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Mang ban dau: ";
    printfselection(a,n);
    cout<< "selectionSort"<<endl;
    selectionSort(a, n);
    cout << "Mang sau khi sap xep: ";
    printfselection(a, n);
    cout<<endl;

    int b[12] = {17,23,201,98,67,83,13,23,10,191,84,58};
    int h = sizeof(b) / sizeof(b[0]);
    cout << "Mang ban dau: ";
    printfinsertion(b,n);
    cout<<"insertionSort"<<endl;
    insertionSort(b,n);
    cout<<"Mang sau sap xep: ";
    printfinsertion(b,n);
    cout<<endl;

    int c[12] = {17,23,201,98,67,83,13,23,10,191,84,58};
    int v = sizeof(c) / sizeof(c[0]);
    cout << "Mang ban dau: ";
    printfbubbleSort(c,v);
    cout<< "bubbleSort"<<endl;
    bubbleSort(c, v);
    cout << "Mang sau khi sap xep: ";
    printfbubbleSort(c, v);


    return 0;
}


