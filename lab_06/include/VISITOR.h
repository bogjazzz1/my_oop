#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED
#include "../include/Fabric.h"
#include "../include/PairNPC.h"
class FightVisitor:public  Visitor{
    public:
virtual int visit(Squirrel& element) ;
virtual int visit(Druid& element) ;
virtual int visit(Orc& element);
virtual int visit(PairNPC& element) ;

};

#endif // VISITOR_H_INCLUDED
