#include "include/Vector.hpp"
#include "include/alacator.hpp"
#include <iostream>
#include <map>


using namespace std;

int main()
{
    std::map<int, int, std::less<int>, mai::Allocator<std::pair<const int, int>>> mapa;
    int64_t fact = 1;
    for (int64_t i = 1; i <= 10; ++i) {
        fact *= i;
        mapa[i] = fact;
    }
    for (const auto &[k, v]: mapa)
        std::cout << k << " " << v << std::endl;
    Vector<std::vector<int>, mai::Allocator<std::vector<int>>> k;
    k.resize(9, std::vector<int>(10));
    k.emplace_back(9);
    for (int64_t y = 0; y < 10; y++) {

        std::cout << k[y].size() << '\n';
    }
    std::cout << "copy constructor" << '\n';
    Vector<std::vector<int>, mai::Allocator<std::vector<int>>> kc(k);
    for (int64_t y = 0; y < kc.size(); y++) {
        std::cout << kc[y].size() << '\n';
    }
    std::cout << "list of initialization" << '\n';
    Vector<std::string, mai::Allocator<std::string>> sk({"a", "abb", "abaca"});
    sk.erase(sk.begin());
    sk.insert(sk.begin(), "AAAA", 5);


    for (auto y = sk.begin(); y != sk.end(); ++y) {
        std::cout << *y << '\n';
    }

    const Vector<int, mai::Allocator<int>> sk2(10, 123);
    for (auto y = sk2.cbegin(); y != sk2.cend(); ++y) {
        std::cout << *y << '\n';
    }
    Vector<int, mai::Allocator<int>> sk3;
    for (int64_t i = 0; i < 10; ++i) {
        sk3.push_back(i);
    }
    for (auto y = sk3.begin(); y != sk3.end(); ++y) {
        std::cout << *y << '\n';
    }
    return 0;
}
