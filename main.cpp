#include <iostream>
#include <chrono>
#include "functions.cpp"

#define SAMPLES_AMOUNT 10
#define ELEMENTS_AMOUNT 50

/* Сортировка данных указанного объёма указанным методом */
void operation(int (*func)(int)){
	int current_number = 2, sum = 0;
	int sample[SAMPLES_AMOUNT][ELEMENTS_AMOUNT];
	for (int i = 0; i < SAMPLES_AMOUNT; ++i){
		for (int ii = 0; ii < ELEMENTS_AMOUNT; ++ii){
			sample[i][ii] = func(current_number);
			current_number = sample[i][ii];
			//std::cout << sample[i][ii] << ' ';
		}
		//std::cout << '\n';
	}

	std::cout << "Averages: ";
	for (int i = 0; i < SAMPLES_AMOUNT; ++i)
		std::cout << average(sample[i], ELEMENTS_AMOUNT) << ' ';
	std::cout << "\nDeviations: ";
	for (int i = 0; i < SAMPLES_AMOUNT; ++i)
		std::cout << dev(sample[i], ELEMENTS_AMOUNT) << ' ';
	std::cout << "\nCoef.vars: ";
	for (int i = 0; i < SAMPLES_AMOUNT; ++i) 
		std::cout << coef_var(sample[i], ELEMENTS_AMOUNT) << ' ';
	std::cout << "\nHomogeneity: ";
	for (int i = 0; i < SAMPLES_AMOUNT-1; ++i) 
		std::cout << hi_square_same(sample[i], sample[i+1], ELEMENTS_AMOUNT, 10000) << ' ';
	std::cout << "\nHi-squares: ";
	for (int i = 0; i < SAMPLES_AMOUNT; ++i) 
		std::cout << hi_square(sample[i], ELEMENTS_AMOUNT, 10000) << ' ';

	std::cout << "\nTime checking - 1000, 3000, 10000, \n30000, 100000, 300000, 1000000 elements: \n";
    int amounts[7] = {1000, 3000, 10000, 30000, 100000, 300000, 1000000};
    for (int i = 0; i < 7; ++i){
    	auto beg = std::chrono::high_resolution_clock::now();
		for (int ii = 0; ii < amounts[i]; ++ii){
			current_number = func(current_number);
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-beg);
		std::cout << duration.count() << '\n';
	}
}

int main(int argc, char* argv[])
{
	std::cout<<"1st function:\n";
	operation(rand1);
	std::cout<<"\n\n2nd function:\n";
	operation(rand2);
    return 0;
}