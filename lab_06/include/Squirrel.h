#ifndef SQUIRREL_H_INCLUDED
#define SQUIRREL_H_INCLUDED
#include "../include/NPC.h"
class Squirrel final: public NPC {
    public:
Squirrel(int x,int y,std::string name);
Squirrel(std::istream &is);
void print() override;
void save(std::ostream &os) override;
friend std::ostream &operator<<(std::ostream &os, Squirrel &Squirrel);
virtual int accept(Visitor& visitor) override;
};

#endif // SQUIRREL_H_INCLUDED
