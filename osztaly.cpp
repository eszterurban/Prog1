#include <string>
#include <iostream>

using namespace std;

class osztaly{
	public:
		virtual void elso() {cout << "osztaly::elso()\n";}
		void masodik() {cout << "osztaly::masodik()\n";}
		virtual void harmadik() = 0;
};

class osztalyk : public osztaly{
	public:
		virtual void elso() {cout << "osztalyk::elso()\n";}
		void masodik() {cout << "osztalyk::masodik()\n";}
};

int main(){
	osztaly a1;
	a1.elso();
	a1.masodik();
	for (int i=0; i<=4; ++i){
		a1.harmadik();
	}
	
	osztalyk b1;
	b1.elso();
	for (int i=0; i<=3; ++i){
		b1.masodik();
	}
}
