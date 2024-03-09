#include "Squirrel.h"

Squirrel::Squirrel(int x, int y,std::string name) : NPC(SquirrelType, x, y,name) {}
Squirrel::Squirrel(std::istream &is) : NPC(SquirrelType, is) {}
void Squirrel::print(){
std::cout<<*this;
}
std::ostream &operator<<(std::ostream &os, Squirrel &Squirrel)
{
    os << "Squirrel: " << *static_cast<NPC *>(&Squirrel) << std::endl;
    return os;
}
void Squirrel::save(std::ostream &os)
{
    os << SquirrelType << std::endl;
    NPC::save(os);
}
 int Squirrel::accept(Visitor& visitor){
    return visitor.visit(*this);
}
