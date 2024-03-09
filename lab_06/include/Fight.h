#ifndef FIGHT_H_INCLUDED
#define FIGHT_H_INCLUDED
#include "../include/VISITOR.h"
#include"../include/PairNPC.h"
set_t fight(const set_t &array, size_t distance);
std::ostream &operator<<(std::ostream &os, const set_t &array);
void save(const set_t &array, const std::string &filename);
set_t load(const std::string &filename);
#endif // FIGHT_H_INCLUDED
