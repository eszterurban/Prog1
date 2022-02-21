#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <string>
#include <iostream>


using namespace Graph_lib;

int main(){

try{

Point t1 {100, 100};
Simple_window win {t1, 800, 1000, "Canvas"};
win.wait_for_button();

Lines grid;
int x_size = 800;
int y_size = 800;
for(int i=100; i<=x_size; i+=100){
	grid.add(Point(i, 0), Point(i, y_size));
	grid.add(Point(0, i), Point(x_size, i));
}
win.attach(grid);
win.wait_for_button();

Vector_ref<Rectangle> vr;
for(int i=0; i<8; ++i){
	vr.push_back(new Rectangle(Point(i*100, i*100),101, 101));
	vr[vr.size()-1].set_fill_color(Color::red);
	win.attach(vr[vr.size()-1]);
}
win.wait_for_button();

Image nyuszi(Point(200,0),"nyuszi.jpg");
nyuszi.set_mask(Point(200,0),200,200);
win.attach(nyuszi);
Image nyuszi1(Point(500,200),"nyuszi.jpg");
nyuszi1.set_mask(Point(200,0),200,200);
win.attach(nyuszi1);
win.wait_for_button();

for(;;){
	Image mozgo(Point(0,0),"badge.jpg");
	mozgo.set_mask(Point(200,0),100,100);			
	int randx=rand()%8;
	int randy=rand()%8;
	win.attach(mozgo);
	mozgo.move(randx*100,randy*100);
	win.wait_for_button();
}

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
