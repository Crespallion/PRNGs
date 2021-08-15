#include <math.h>
#include <iostream>

int rand1(int number) {
	unsigned long phase1 = number * 9521 + 7001;
   return phase1 % 10000;
}

int rand2(int number) {
   unsigned long phase1 = number * number * number * 2081 + number * number * 5657 + 
   number * 9521 + 7001;
   return phase1 % 10000;
}

float average(int arr[], int amount){
	int sum = 0;
	for (int i = 0; i < amount; ++i){
		sum += arr[i];
	}
	return (float)sum/amount;
}

float dev(int arr[], int amount){
	int sum = 0, av = average(arr, amount);
	for (int i = 0; i < amount; ++i){
		sum += (arr[i] - av) * (arr[i] - av);
	}
	return pow((float)sum/(amount-1), 0.5);
}

float coef_var(int arr[], int amount){
	return dev(arr, amount)/average(arr, amount);
}

float hi_square(int arr[], int amount, int max){
	float hi_res = 0;
	int in_one_part = amount/10;
	int counts[10] = { 0 };
	for (int i = 0; i < amount; ++i){
		++counts[arr[i]/(max/10)];
	}
	for (int i = 0; i < 10; ++i){
		hi_res += (float)(counts[i]-in_one_part)*(counts[i]-in_one_part)/in_one_part;
	}
	return hi_res;
}

float hi_square_same(int arr1[], int arr2[], int amount, int max){
	float hi_res = 0;
	int in_one_part = amount/10;
	int counts1[10] = { 0 };
	int counts2[10] = { 0 };
	for (int i = 0; i < amount; ++i){
		++counts1[arr1[i]/(max/10)];
		++counts2[arr2[i]/(max/10)];
	}
	for (int i = 0; i < 10; ++i){
		hi_res += (float)(counts1[i]-counts2[i])*(counts1[i]-counts2[i])/(counts1[i]+counts2[i]+1);
	}
	return hi_res;
}