#include <iostream>

#include "include/Sixnumber.hpp"
using namespace std;

int main()
{
Six o1(10,'1');
string s;
cout<<o1<<endl;
cin>>s;
Six p(s);
cout<<p<<endl;
Six o{'5','5','5','5'};
Six ok{'5','5','5','5'};
Six o2{'1','2','5'};
Six p1;
    cout << (o1==o)<<" "<<(o1!=o) << endl;
    cout<<(o>o2)<<" "<<(o<o2)<<endl;
    cout<<(o>ok)<<" "<<(o<ok)<<endl;
    cout<<o<<" "<<o2<<endl;
cout<<o+ok;
cout<<endl;
cout<<o;
cout<<endl;
    o+=ok;
    cout<<o<<endl;
    o+=p1;
    cout<<o<<endl;
    o-=p1;
    cout<<o<<endl;
    o-=ok;
    cout<<o<<endl;
    o-=ok;
    cout<<o<<endl;
    cout<<p+o2<<endl;
    return 0;
}
