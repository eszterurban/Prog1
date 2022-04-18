#include <iostream>
#include <stdexcept>
#include <string>
#include <numeric>
#include <map>
using namespace std;

template<typename K, typename V>
void print(const map<K, V> &m){
	for(const auto& a : m){
		cout << a. first << '\t' << a.second << endl;
	}
}

void read_map(map<string, int>& m){
	string s;
	int i=0;
	while(m.size()<10)
		{
			cin >> s >> i;
			m.insert(make_pair(s,i));
		}
	}

int main(){
try{
	map<string,int> msi;
	msi["a"] = 1;
	msi["b"] = 2;
	msi["c"] = 3;
	msi["d"] = 4;
	msi["e"] = 5;
	msi["f"] = 6;
	msi["g"] = 7;
	msi["h"] = 8;
	msi["i"] = 9;
	msi["j"] = 10;
	
	print(msi);
	
	cout << "törlés: " << endl;
	msi.erase("a");
	print(msi);
	
	cout << "teljes törlés: " << endl;
	msi.erase(msi.begin(), msi.end());
	print(msi);
	
	cout << "10 kulcs érték pár megadasa: " << endl;
	read_map(msi);
	cout << "10 kulcs érték pár kiirása: " << endl;
	print(msi);
	
	int total=0;
	for(pair <string, int> a: msi){
			total += a.second;
		}
	cout<< "összeg: " << endl;
	cout << total << endl;

	map<int, string> mis;
	for(const auto& a:msi){
		mis[a.second] = a.first;
	}
	print(mis);
}
catch (exception& e){
cerr << "exception: " << e.what() << "\n";
return 1;
}
catch (...) {
cerr << "error \n";
return 2;
}
}
