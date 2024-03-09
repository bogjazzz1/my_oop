#ifndef DRUID_H_INCLUDED
#define DRUID_H_INCLUDED
#include "../include/NPC.h"
class Druid final: public NPC {
    public:
Druid(int x,int y,std::string name);
Druid(std::istream &is);
void print() override;
void save(std::ostream &os) override;
friend std::ostream &operator<<(std::ostream &os, Druid &Druid);
virtual int accept(Visitor& visitor) override;
};


#endif // DRUID_H_INCLUDED
