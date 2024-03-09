#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED
#include "Fabric.h"
#include "PairNPC.h"
class FightVisitor:public  Visitor{
    public:
virtual int visit(Squirrel& element) override ;
virtual int visit(Druid& element) override;
virtual int visit(Orc& element) override;
virtual int visit(PairNPC& element) override;

};
class MoveVisitor:public Visitor{
    public:
virtual int visit(Squirrel& element) override ;
virtual int visit(Druid& element) override;
virtual int visit(Orc& element) override;
virtual int visit(PairNPC& element) override;
};
class DistanceVisitor:public Visitor{
    public:
virtual int visit(Squirrel& element) override ;
virtual int visit(Druid& element) override;
virtual int visit(Orc& element) override;
virtual int visit(PairNPC& element) override;
};

class MapMoveVisitor:public Visitor{
    public:
virtual int visit(Squirrel& element) override ;
virtual int visit(Druid& element) override;
virtual int visit(Orc& element) override;
virtual int visit(PairNPC& element) override;
};
#endif // VISITOR_H_INCLUDED
