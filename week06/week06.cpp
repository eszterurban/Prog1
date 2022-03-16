#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
struct S{
	S(T vv = 0):val{vv} {}
	
	T& get();
	const T& get() const;
	void set(T new_t) {val = new_t;}
	
	S<T>& operator=(const T& s);
	
	private:
		T val;
};

template<typename T>
T& S<T>::get(){
	return val;
}

template<typename T>
const T& S<T>::get() const{
	return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& s){
	val = s;
	return *this;
}

template<typename T> void read_val(T& v){
	cin >> v;
}

template<typename T>
std::ostream& operator <<(ostream& os, vector<T>& v){
	os << "{";
	for(int i =0; i<v.size(); ++i){
		os << v[i] << (i < v.size()-1 ? ", " : "");
	}
	os << "}\n";
	return os;
}

template<typename T>
istream& operator >>(istream& is, vector<T>& v){
	char ch = 1;
	is >> ch;
	if(ch != '{'){
		is.unget();
		return is;
	}
	for(T val; is >> val;){
		v.push_back(val);
		is >> ch;
		if (ch != ',') break;
	}
	return is;
}

int main(){
	S<int> s;
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {1.34};
	S<std::string> ss {"Hello"};
	S<std::vector<int>> svi {std::vector<int>{1,2,3,4,5,6}};
	
	cout << "S<int> : " << s.get() << endl;
	cout << "S<int> : " << si.get() << endl;
	cout << "S<char> : " << sc.get() << endl;
	cout << "S<double> : " << sd.get() << endl;
	cout << "S<string> : " << ss.get() << endl;
	cout << "S<vecor<int>> : ";
	for(auto& a:svi.get()){
		cout << a <<' ';
	}
	cout << endl;
	
	sc.set('s');
	cout << "S<char> : " << sc.get() << endl;
	
	sd = 3.21;
	cout << "S<double> : " << sd.get() << endl;
	
	int ii;
	read_val(ii);
	S<int> si2 {ii};
	
	char cc;
	read_val(cc);
	S<char> sc2 {cc};
	
	double dd;
	read_val(dd);
	S<double> sd2 {dd};
	
	cout << "S<int> : " << si2.get() << endl;
	cout << "S<char> : " << sc2.get() << endl;
	cout << "S<double> : " << sd2.get() << endl;
	
	cout << "S<vecor<int>>: (format: {val, val, val})" << endl;
	vector<int> vi2;
	read_val(vi2);
	S<std::vector<int>> svi2 {vi2};
	cout << "S<vecor<int>>: " << svi2.get() << endl;
	
}
