#include <iostream>
#include "include/Figurearray.hpp"
const double pi=M_PI;
using namespace std;

int main()
{/*Point a(0,0);
Point b(2,3);
Point c(4,0);
Point d(2,-3);
Point a1(0,0);
Point b1(1,3);
Point c1(4,4);
Point d1(3,1);
Romb fr(a1,b1,c1,d1);
Romb R(1);
cout<<fr.geometric_center()<<endl;
cout<<R.geometric_center()<<endl;
cout<<fr.area()<<" "<<static_cast<double>(fr)<<endl;
cout<<R.area()<<endl;
cout<<(R==fr)<<endl;
cout<<R<<endl;
R=fr;
cout<<R<<endl;
cout<<(R==fr)<<endl;
//cin>>R;
cout<<R<<endl;
cout<<(R==fr)<<endl;*/

Point a2(0,100);
Point b2(sqrt(6250+1250*sqrt(5)),-25+25*sqrt(5));
Point c2(25*(-sqrt(2)+sqrt(10))*sqrt(sqrt(5)+5)/2,-25-25*sqrt(5));
Point d2(-25*(-sqrt(2)+sqrt(10))*sqrt(sqrt(5)+5)/2,-25-25*sqrt(5));
Point e2(-sqrt(6250+1250*sqrt(5)),-25+25*sqrt(5));
Pentagon z(a2,b2,c2,d2,e2);
Pentagon z1(10);
cout<<(z==z1)<<endl;
cout.precision(20);
    cout << static_cast<double>(z) << endl;
    cout<<z.geometric_center()<<endl;
cout<<z<<endl;


Point a(-3+9,0);
Point d(9+3,0);
Point c(9+3/2,2.59808);
Point b(9+-3/2,2.59808);
Point e(9+3/2,-2.59808);
Point g(9+-3/2,-2.59808);
double side=10,Radius=side;
a=Point(9+Radius*std::cos(0),Radius*std::sin(0));
cout<<a<<endl;
b=Point(9+Radius*std::cos(1*2*pi/6),Radius*std::sin(1*2*pi/6));
c=Point(9+Radius*std::cos(2*2*pi/6),Radius*std::sin(2*2*pi/6));
d=Point(9+Radius*std::cos(3*2*pi/6),Radius*std::sin(2*3*pi/6));
e=Point(9+Radius*std::cos(4*2*pi/6),Radius*std::sin(4*2*pi/6));
g=Point(9+Radius*std::cos(5*2*pi/6),Radius*std::sin(5*2*pi/6));
Hexagon oleg(a,b,c,d,e,g);
cout<<(double)oleg<<endl;
cout<<oleg.geometric_center()<<endl;
cout.precision(20);
cout<<oleg;
FigureArray az;
cin>>az;
az.print_geometric_center();
cout<<az.sum_area()<<endl;
cout<<static_cast<double>(az)<<endl;
cout<<az;

    return 0;
}
