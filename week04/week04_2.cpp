#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main(){
	std::vector<int> v {1,2,3,4,5,6,7,8,9,10};
	
	std::transform(v.begin(), v.end(), v.begin(), [](int n){return n+(n*2);});

	std::for_each(v.begin(), v.end(), [](const int&x){cout << x << endl;});
}
