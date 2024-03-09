#include "include/Figurearray.hpp"
#include "include/Romb.hpp"
#include "include/hexagon.hpp"
#include "include/pentagon.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "Number of figures";
    int64_t p = 0;
    cin >> p;
    FigureArray<shared_ptr<Figure<double>>> array_F(p);
    char ii = '1';

    for (size_t i = 0; i < p; ++i) {
        cin >> ii;
        if (ii == 'r') {
            shared_ptr<Romb<double>> a1 = shared_ptr<Romb<double>>(new Romb<double>());
            cin >> (*(a1.get()));
            array_F[i] = a1;
        }
        else if (ii == 'p') {
            shared_ptr<Pentagon<double>> a1 = shared_ptr<Pentagon<double>>(new Pentagon<double>());
            cin >> (*(a1.get()));
            array_F[i] = a1;
        }
        else if (ii == 'h') {
            shared_ptr<Hexagon<double>> a1 = shared_ptr<Hexagon<double>>(new Hexagon<double>());
            cin >> (*(a1.get()));
            array_F[i] = a1;
        }
        else {
            throw std::logic_error("required type of figure ");
        }
    }

    ii = 'i';
    cin >> ii;
    while (ii != 'E' && array_F.size() > 0) {
        if (ii == 'S') {
            double temp_a = 0;
            for (size_t i = 0; i < array_F.size(); ++i) {
                temp_a += static_cast<double>(*array_F[i].get());
            }
            cout << temp_a << endl;
        }
        else if (ii == 'C') {
            std::cout << "Geometric centers" << std::endl;
            for (size_t i = 0; i < array_F.size(); ++i) {
                std::cout << array_F[i]->geometric_center() << std::endl;
            }
        }
        else if (ii == 'P') {
            for (size_t i = 0; i < array_F.size(); ++i) {
                array_F[i]->print();
                cout << endl;
            }
        }
        else if (ii == 'R') {
            cout << "INDEX" << endl;
            size_t index = 0;
            cin >> index;
            array_F.erase(index);
        }
        cin >> ii;
    }
    return 0;
}
