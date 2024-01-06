#include <iostream>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int partition(int punteggi[], int low, int high){
	int i = low-1;
	int pivot = punteggi[high];

	for(int j = low; j < high; j++){
		if(punteggi[j] % 3 <= pivot % 3){
      i++;
			swap(punteggi[j],punteggi[i]);
		}
	}

	swap(punteggi[i+1],punteggi[high]);
	return i+1;
}

void quick(int punteggi[], int low, int high){
	if(low < high){
		int pivot_location = partition(punteggi, low, high);
		quick(punteggi, low, pivot_location-1);
		quick(punteggi, pivot_location+1, high);
	}
}

int scarto(int n, int punteggi[]){
	quick(punteggi,0,n-1);// ricordo che n è pari
	int scart = 0;
	for(int i = 0; i < n; i += 2){
		scart = scart + abs(punteggi[i] - punteggi[i+1]);
	}
	return scart;
}

int main(){
	int arr[12] = {0,2,5,3,8,12,9,1,7,13,17,16};
	cout << scarto(12, arr) << endl;
  for(int i=0; i < 12; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
	return 0;
}
