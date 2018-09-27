#include <iostream>

/*Вариант 1*/ 

using namespace std;
typedef unsigned long long ull;

ull getValue();
ull rec(ull n, ull m);

int main()
{
	/*reading data from the input stream*/
    cout << "Enter the number for which you want to calculate the binomial coefficient: ";
    ull n = getValue();
    cout << n << endl;

    cout << "Enter the number of the coefficient: " ;
    ull m = getValue();
    cout << m << endl;

	/*checking the entered data for correctness*/
    if(m > n){
        cerr << "Invalid input. M can't be larger than N. Aborting!\n";
        exit(1);
    }
    ull r=rec(n,m);
    cout << "Answer: [" << r << "]\n";

    return 0;
}

ull getValue() {
    ull value;
    cin >> value;
    if(!cin.good()) { 
		/* If cin have an exception like ERANGE value or symbols in cin it returns false*/
        cerr << "Error with input. Aborting!";
        exit(1);
    }
    return value;
}

ull rec(ull n, ull m){

	if (m>n/2)
        m=n-m;
	/*checking for 0 or 1*/
    if (m==1)
        return n;
    if (m==0)
        return 1;
	/*algorithm for calculating binomial coefficients*/
    ull r;
	r=rec(n-1,m);
    r=r+rec(n-1,m-1);
    return r;
}
