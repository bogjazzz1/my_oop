#include "Orc.h"

Orc::Orc(int x, int y,std::string name) : NPC(OrcType, x, y,name) {}
Orc::Orc(std::istream &is) : NPC(OrcType, is) {}
void Orc::print(){
std::cout<<*this;
}
std::ostream &operator<<(std::ostream &os, Orc &Orc)
{
    os << "Orc: " << *static_cast<NPC *>(&Orc) << std::endl;
    return os;
}
void Orc::save(std::ostream &os)
{
    os << OrcType << std::endl;
    NPC::save(os);
}
 int Orc::accept(Visitor& visitor){
    return visitor.visit(*this);
}
