#include <iostream>
using namespace std;

// Function that swaps values using pointers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;      
    *b = temp;      
}

int main() {
    int x = 5;
    int y = 10;
    cout << "Before swap:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    swap(&x, &y);
    cout << "After swap:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}