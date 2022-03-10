#include <iostream>
using namespace std;


/* 
	[] lambda introducer
	() argument list
	{} fugvény törzs
	
	[]
	(&) capture by reference
	(=) capture by value
	(&A =B) capture a by reference b by value
	
	
*/

int main(){
	[](){
		cout <<"Hello c++ lambda" << endl;
	}
	();
	
	auto sum = [](double A, double B) {
		return A+B;
	};
	auto add = sum;
	cout << add(3.25, 5.45) << endl;
	
	auto add2 = [](double A, double B)->double{
		return A+B;
	};
	cout << add2(3.25, 5.45) << endl;
	
	double pi = 3.1416;
	auto func = [pi](){
		cout << "The value of pi: " << pi << endl;
	};
	func();
	
	auto gene_lambda = [] (auto arg){
		return arg + arg;
	};
	cout << gene_lambda(5) << endl;
	cout << gene_lambda(2.15) << endl;
	
}
