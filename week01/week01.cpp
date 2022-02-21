#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <string>
#include <iostream>


using namespace Graph_lib;

int main(){

try{

Point t1 {100, 100};
Simple_window win {t1, 600, 400, "Canvas"};
win.wait_for_button();

Axis xa {Axis::x, Point{40,300}, 200, 10, "x.axis"};
xa.set_color(Color::red);
win.attach(xa);
win.set_label("Canvas #2");
win.wait_for_button();

Axis ya {Axis::y, Point{40,300}, 200, 10, "y.axis"};
ya.set_color(Color::yellow);
win.attach(ya);
win.set_label("Canvas #3");
win.wait_for_button();

Function sine {sin,0, 10, Point{20,150}, 1000, 50, 50};
win.attach(sine);
win.set_label("Canvas #4");
win.wait_for_button();

Polygon poly;
poly.add(Point{300,200});
poly.add(Point{350,150});
poly.add(Point{450,200});
poly.set_color(Color::red);
poly.set_style(Line_style::dash);
win.attach(poly);
win.set_label("Canvas #5");

Rectangle r {Point{200,200}, 10, 50};
win.attach(r);
win.set_label("Canvas #6");
win.wait_for_button();

Closed_polyline poly_rect;
poly_rect.add(Point{100,50});
poly_rect.add(Point{200,50});
poly_rect.add(Point{200,100});
poly_rect.add(Point{100,100});
poly_rect.add(Point{50,85});
win.attach(poly_rect);

r.set_fill_color(Color::blue);
poly.set_style(Line_style(Line_style::dash,4));
poly_rect.set_style(Line_style(Line_style::dash,8));
poly_rect.set_fill_color(Color::green);
win.set_label("Canvas #7");
win.wait_for_button();

Text t {Point{150,200}, "Hello, graphical world!"};
win.attach(t);
win.set_label("Canvas #8");
win.wait_for_button();

t.set_font(Graph_lib::Font::times_bold);
t.set_font_size(30);
win.set_label("Canvas #9");
win.wait_for_button();

Image ii {Point{100,50},"nyuszi.jpg"};
win.attach(ii);
win.set_label("Canvas #10");
win.wait_for_button();

ii.move(20,20);
win.set_label("Canvas #11");
win.wait_for_button();

Circle c {Point{100,300},50};
Ellipse e {Point{100,300}, 75,25};
e.set_color(Color::dark_blue);
Mark m {Point(100,200),'x'};
ostringstream oss;
oss << "screen size: " << x_max() << "*" << y_max()
<< "; window size: " << win.x_max() << "*" << win.y_max();
Text sizes {Point{100,20},oss.str()};
Image cal {Point{225,225},"nyuszi.jpg"};
cal.set_mask(Point{40,40},200,150); 
win.attach(c);
win.attach(m);
win.attach(e);
win.attach(sizes);
win.attach(cal);
win.set_label("Canvas #12");
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
}
