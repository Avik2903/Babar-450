#include <iostream>
using namespace std;
#define n 4
void solveWordWrap(int a , int arr[], int k){
	int total_cost = 0;
	for(int i = 0; i < a - 1; i++){
	//size of window left after the current element
		int size = k - 1 - arr[i];
	//cost of current line
		int sum = k - arr[i];
		while(size >= 0){
			size = size - arr[i+1] - 1;
		// breaks immediately
			if(size < 0){break;}
			sum = sum - arr[i] - 1;
			i++;
		}
	//add current cost to total cost
		total_cost = total_cost + (sum*sum);
	}
//print the total cost
	cout << total_cost;
}

int main(){
	int nums[n] = {3,2,2,5};
	int k = 6;
	solveWordWrap(n, nums, k);
}
