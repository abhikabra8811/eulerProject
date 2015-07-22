#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//soltuion 1 - not recommended because number of iterations increses with input size
//not efficient
long long sumOfMultiplesOf3And5Loop(long long iInputSize){
	long long multipleOf3(3), multipleOf5(5);
	long long result(0);
	while (multipleOf3 < iInputSize || multipleOf5 < iInputSize){
		if (multipleOf3 < iInputSize){
			if (multipleOf3 % 5 != 0){
				result += multipleOf3;
			}
			multipleOf3 += 3;
		}
		if (multipleOf5 < iInputSize){
			result += multipleOf5;
			multipleOf5 += 5;
		}
	}
	return result;
}

//solution 2 -- only works with with series of 3 and 5 altough efficient
long long sumOfMultiplesOf3And5(long long iInputSize){
	long long result;

	long long sumOfTermsOf3, sumOfTermsOf5, sumOfTermsOf15;
	sumOfTermsOf3 = ((iInputSize - 1) / 3) * (3 + (iInputSize - 1) / 3 * 3) / 2;
	sumOfTermsOf5 = ((iInputSize - 1) / 5) * (5 + (iInputSize - 1) / 5 * 5) / 2;
	sumOfTermsOf15 = ((iInputSize - 1) / 15)* (15 + (iInputSize - 1) / 15 * 15) / 2;

	result = sumOfTermsOf3 + sumOfTermsOf5 - sumOfTermsOf15;
	return result;
}

//solution 3 -- more general
//parameters - n: input size, d: common difference of arithmatic series
long long sumOfSeries(long long n, int d){
	return (d + (n - 1) / d * d) * ((n - 1) / d) / 2;
}

int main_problem_1() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	long long num_of_test_cases;

	//getline (cin,num_of_test_cases);
	cin >> num_of_test_cases;

	for (long long i = 0; i<num_of_test_cases; i++){
		long long inputSize;
		//getline(cin, inputSize);
		cin >> inputSize;
		if (inputSize){
			//solution 1
			long long result = sumOfMultiplesOf3And5Loop(inputSize);
			cout << result << endl;

			//solution 2
			result = sumOfMultiplesOf3And5(inputSize);
			cout << result << endl;

			//solution 3
			cout << sumOfSeries(inputSize, 3) + sumOfSeries(inputSize, 5) - sumOfSeries(inputSize, 15) << endl;
			
		}
	}

	return 0;
}