#ifndef FABRIC_H_INCLUDED
#define FABRIC_H_INCLUDED
#include "Observer.h"
#include "Squirrel.h"
#include "Orc.h"
#include "Druid.h"
class Factory{
    public:
std::shared_ptr<NPC> factory(std::istream &is);
std::shared_ptr<NPC> factory(NpcType type, int x, int y,std::string name);

};

#endif // FABRIC_H_INCLUDED
