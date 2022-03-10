#include <iostream>
#include <cmath>
using namespace std;

double absolute(double n){
	cout << "Abszolutertek előtt: " << n << endl;
	return abs(n);
}

int main(){
	cout << abs(0.25) << endl;
	cout << absolute(0.25) << endl;
}
