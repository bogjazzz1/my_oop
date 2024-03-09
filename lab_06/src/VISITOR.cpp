#include "../include/VISITOR.h"
int FightVisitor::visit(Squirrel& element){
return 1;
}
int FightVisitor::visit(Druid& element){
return 2;
}
int FightVisitor::visit(Orc& element){
return 3;
}
int FightVisitor::visit(PairNPC& element){
    FightVisitor temp;
int result=element.first->accept(temp);

result-=element.second->accept(temp);

if(result==1){
    element.first->fight_notify(element.second,true);
    return true;
} else{
element.first->fight_notify(element.second,false);
return false;
}

}
