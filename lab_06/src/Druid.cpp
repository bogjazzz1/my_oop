#include "../include/Druid.h"

Druid::Druid(int x, int y,std::string name) : NPC(DruidType, x, y,name) {}
Druid::Druid(std::istream &is) : NPC(DruidType, is) {}
void Druid::print(){
std::cout<<*this;
}
std::ostream &operator<<(std::ostream &os, Druid &Druid)
{
    os << "Druid: " << *static_cast<NPC *>(&Druid) << std::endl;
    return os;
}
void Druid::save(std::ostream &os)
{
    os << DruidType << std::endl;
    NPC::save(os);
}
 int Druid::accept(Visitor& visitor){
    return visitor.visit(*this);
}
