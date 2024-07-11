#include <iostream>
using namespace std;

int checkSequenceAux(char* p1, char* p2){
	if(*p2 == '\0') return 0;
	if(*p1 == 'a' && *p2 == 'r') {
    return 1 + checkSequenceAux(++p1, ++p2);
  } else { 
    return 0 + checkSequenceAux(++p1, ++p2);
  }
}

int checkSequence(char* array, int dim){
	if(dim < 2) return 0;
	char* point1 = array;
	char* point2 = point1 + 1;
  cout << "iniziamo" << endl;
	return checkSequenceAux(point1, point2); 
}

int main(){
	char arr[7] = {'a','r','o','o','a','r','o'};
	cout << checkSequence(arr, 7) << endl;
	return 0;
}
