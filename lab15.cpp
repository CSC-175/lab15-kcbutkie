#include<iostream>
using namespace std;

// Function prototypes
void getInfo(int&, int&);
double computeWays(int, int);
double factorial(int);

/*******************************************************************
* getLotteryInfo                                                   *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
********************************************************************/

void getInfo(int& num1, int& num2) {
cout << "How many balls (1-12) are in the pool to pick from? ";
    cin >> num1;
    while ((num1 > 12)){
        cout << "Input error! There must be between 1 and 12 balls." << endl;
        cout << "How many balls (1-12) are in the pool to pick from? " << endl;
        cin >> num1;
    }
    cout << "How many balls (1-" << num1 << ") will be drawn? ";
    cin >> num2;
    while (num2 > num1) {
        cout << "Input error!" << endl;
        cout << "How many balls (1-" << num1 << ") will be drawn? ";
        cin >> num2;
    }

}

/*******************************************************************
* computeWays                                                      *
* Computes and returns the number of different possible sets       *
* of k numbers that can be chosen from a set of n numbers.         *
* The formula for this is     k!(n- k)!                            *
*                             --------                             *
*                                 n!                               *
* Note that the computation is done in a way that does not require *
* multiplying two factorials together. This is done to prevent any *
* intermediate result becoming so large that it causes overflow.   *
********************************************************************/

double computeWays (int n, int k) {
    return (factorial(k)*factorial(n-k))/(factorial(n));
}

/*******************************************************************
* factorial                                                        *
* This function computes factorials recursively.                   *
*******************************************************************/

double factorial(int number) {
    if (number == 0) { //referred to as base case; we know the result
        return 1;
    }
    else {
        return number * factorial(number - 1);
    }
}
