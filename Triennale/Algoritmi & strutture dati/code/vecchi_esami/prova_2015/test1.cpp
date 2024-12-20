#include <iostream>
using namespace std;

int checkSequenceAux(char *p1, char *p2) {
  if (*p2 == '\0')
    return 0;
  if (*p1 == 'a' && *p2 == 'r') {
    return 1 + checkSequenceAux(++p1, ++p2);
  } else {
    return 0 + checkSequenceAux(++p1, ++p2);
  }
}

int checkSequenceUsingOrder(char array[], int min, int max) {
  if (min >= max)
    return 0;
  int mid = min + (max - min) / 2;
  int check = 0;
  (array[mid] == 'a' && array[mid + 1] == 'r') ? check += 1 : check = check;
  return check + checkSequenceUsingOrder(array, min, mid) +
         checkSequenceUsingOrder(array, mid + 1, max);
}

int checkSequence(char *array, int dim) {
  if (dim < 2)
    return 0;
  char *point1 = array;
  char *point2 = point1 + 1;
  cout << "iniziamo" << endl;
  // return checkSequenceAux(point1, point2);
  return checkSequenceUsingOrder(array, 0, dim - 1);
}

int main() {
  char arr[9] = {'a', 'r', 'o', 'o', 'a', 'r', 'o', 'a', 'r'};
  cout << checkSequence(arr, 9) << endl;
  return 0;
}
