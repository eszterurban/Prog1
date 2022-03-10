#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
using namespace std;

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double cosinus(double x) {return cos(x);}
double sloping_cos(double x) {return (cosinus(x)+slope(x));}

struct Person{
	public:
		Person(){}
		Person(string f,string l, int a) : f{f}, l{l}, a{a}{
			if(a<0 || a>=150){
				throw runtime_error("Invalid age!");
				}
			for (char c : f + l){
				switch(c){
					case ';':
					case ':':
					case '"':
					case '[':
					case ']':
					case '*':
					case '&':
					case '^':
					case '%':
					case '$':
					case '#':
					case '@':
					case '!':
				throw runtime_error("Invalid age!");}
				}
			}; //4.
		string first() const{return f;}
		string last() const{return l;}
		int age() const{return a;}
	private:
		string f;
		string l;
		int a;
};

ostream& operator <<(ostream& os, const Person& p)
{
	return  os << p.last() << p.first() << " " << p.age();
}

istream& operator >>(istream& is, Person& p)
{
	string f;
	string l;
	int a;
	is >> f >> l  >> a;
	p=Person(f, l,a);
	return is;
}

int main(){
	try{
		Point t1 {100, 100};
		Simple_window win {t1, 600, 600, "Function graphs"};
		
		Axis xa {Axis::x, Point{100,300}, 400, 20, "x axis"};
		xa.set_color(Color::red);
		win.attach(xa);

		Axis ya {Axis::y, Point{300,500}, 400, 20, "y axis"};
		ya.set_color(Color::red);
		win.attach(ya);
		
		Point orig{300,300};
		Function s{one,-10,11,orig,400,20,20};
		win.attach(s);
		
		Function s2{slope,-10,11,orig,400,20,20};
		win.attach(s2);
		Text ts{Point{100,430},"x/2"};
		win.attach(ts);
		
		Function s3{square,-10,11,orig,400,20,20};
		win.attach(s3);
		
		Function s4{cosinus,-10,11,orig,400,20,20};
		s4.set_color(Color::blue);
		win.attach(s4);
		
		Function s5{sloping_cos,-10,11,orig,400,20,20};
		win.attach(s5);
		
		win.wait_for_button();
	}
	catch (exception& e){
		cerr << "exception: " << e.what() << "\n";
		return 1;
	}
	catch (...) {
		cerr << "error \n";
		return 2;
	}
	
	Person p=Person("Goffy", "Goff", 63);
	cout << p.first() << " " << p.last() << " " << p.age() << endl;
	cout << p << endl;
	cout << p << p << p << endl;
	
	Person p2;
	cin >> p2;
	cout << p2 << endl;
	
	vector<Person> vec;
	for(Person p; cin >> p;){
		if(p.first() == "end") break;
		vec.push_back(p);
	}
	
	for(Person p :vec)
	{
		cout << p << endl;
	}
}
