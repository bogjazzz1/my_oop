#include <iostream>
#include "include/Fight.h"
#include <ctime>
using namespace std;

int main()
{ srand(time(0));
    set_t array; // �������

    // ����������� ��������� ������������� ��������
    std::cout << "Generating ..." << std::endl;
    Factory factor;
    for (size_t i = 0; i < 10; ++i)
        array.insert(factor.factory(NpcType(std::rand() % 3 + 1),
                             std::rand() % 100,
                             std::rand() % 100,"name"));
    std::cout << "Saving ..." << std::endl;

    save(array, "npc.txt");

    std::cout << "Loading ..." << std::endl;
   array = load("npc.txt");

   std::cout << "Fighting ..." << std::endl
              << array;

    for (size_t distance = 20; (distance <= 100) && !array.empty(); distance += 10)
    {
        auto dead_list = fight(array, distance);
        for (auto &d : dead_list)
            array.erase(d);
        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl << std::endl;

    }

    std::cout << "Survivors:" << array;
    return 0;
}
