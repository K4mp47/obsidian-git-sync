#include <iostream>

using namespace std;

void insertion_sort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) 
      a[j + 1] = a[j]; j -= 1;
    a[j + 1] = key;
  }
}

int main() {
  int a[7];

  for(int i=0; i < 7; i++) {
    cin >> a[i];
  }

  insertion_sort(a, 7);
  
  for (int i = 0; i < 7; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
