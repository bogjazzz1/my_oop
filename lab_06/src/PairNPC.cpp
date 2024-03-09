#include "../include/PairNPC.h"
int PairNPC::accept(Visitor& visitor){
return visitor.visit(*this);
}
