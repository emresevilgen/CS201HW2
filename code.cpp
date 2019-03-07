#include <iostream>
#include <ctime>
using namespace std;


int recursiveFib(int n){
	// Precondition: n is a positive integer
	// Postcondition: Returns the nth Fib. number
	if ( n <= 2 )
		return 1;
	else
		return recursiveFib(n-1) + recursiveFib(n-2);
}

int iterativeFib(int n){
						// Initialize base cases:
	int previous = 1; 		// initially fib(1)
	int current = 1;  		// initially fib(2)
	int next = 1;     		// result when n is 1 or 2

	// compute next Fibonacci values when n >= 3
	for (int i = 3; i <= n; ++i){
						// current is fib(i-1)
						// previous is fib(i-2)
		next = current + previous; // fib(i)

		previous = current; 	// get ready for the
		current = next;		// next iteration
	}
	return next;
}

double calculateRecursive( int n){
    int times;
    double duration = 0;

    if(n < 5)
        times = 10000000;
    else if (n < 10)
        times = 1000000;
    else if (n < 15)
        times = 100000;
    else if (n < 20)
        times = 10000;
    else if (n < 25)
        times = 1000;
    else if (n < 30)
        times = 100;
    else if (n < 35)
        times = 10;
    else
        times = 1;

    //Store the starting time
    clock_t startTime = clock();
    //Code block
    for (int i = 0; i< times; i++){
        recursiveFib(n);
    }
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    return duration/double(times);

}

double calculateIterative(int n){
    double duration = 0;

    //Store the starting time
    clock_t startTime = clock();
    //Code block
    iterativeFib(n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    return duration;
}

int main(){
    cout << "\nIterative method" << endl;
    for(int i = 10000000; i <= 1000000000; i = i + 10000000 ) //1000000000
        cout << i << ": " << calculateIterative(i) << endl;

    cout << endl;

    cout << "Recursive method" << endl;
    for(int i = 1; i <= 55; i++ ) //55
        cout << i << ": " << calculateRecursive(i) << endl;
    return 0;
}
