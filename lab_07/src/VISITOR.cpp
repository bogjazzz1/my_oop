#include "VISITOR.h"
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
int result=0;
    if (element.first->is_alive()){     // no zombie fighting!
    if (element.second->is_alive()){ // already dead!
    int roll_first=std::rand()%6+1;
    int roll_second=std::rand()%6+1;

 result=(roll_first>roll_second);
    }
    }

if(result==1){
    element.second->must_die();
    element.first->fight_notify(element.second,true);

    return true;
} else{
element.first->fight_notify(element.second,false);
return false;
}

}
int MoveVisitor::visit(Squirrel& element){
if(element.is_alive()){
                int shift_x = abs(std::rand()) % 10 - 5;//����� ��������
                int shift_y = abs(std::rand()) % 10 - 5;
                element.move(shift_x, shift_y, MAX_X, MAX_Y);
                return true;
}
return false;
}
int MoveVisitor::visit(Druid& element){
if(element.is_alive()){
                int shift_x = abs(std::rand()) % 20 - 10;//����� ��������
                int shift_y = abs(std::rand()) % 20 - 10;
                element.move(shift_x, shift_y, MAX_X, MAX_Y);
                return true;
}
return false;
}
int MoveVisitor::visit(Orc& element){
if(element.is_alive()){
                int shift_x =abs(std::rand()) % 40 - 20;//����� ��������
                int shift_y = abs(std::rand()) % 40 - 20;
                element.move(shift_x, shift_y, MAX_X, MAX_Y);
                return true;
}
return false;
}
int MoveVisitor::visit(PairNPC& element){

return false;
}
int DistanceVisitor::visit(Squirrel& element){
return 5;
}
int DistanceVisitor::visit(Druid& element){
return 10;
}
int DistanceVisitor::visit(Orc& element){
return 10;
}
int DistanceVisitor::visit(PairNPC& element){
 if (element.first->is_alive()){     // no zombie fighting!
    if (element.second->is_alive()){
int DISTANCE=element.first->accept(*this);
if ((element.first != element.second)&&(element.first->is_close(element.second, DISTANCE))){
    return true;
}

}
 }
 return false;
}

int MapMoveVisitor::visit(Squirrel& element){
    if(element.is_alive()){
return static_cast<int>('S');
    }
return static_cast<int>('.');
}
int MapMoveVisitor::visit(Druid& element){
    if(element.is_alive()){
return static_cast<int>('D');
    }
return static_cast<int>('.');
}
int MapMoveVisitor::visit(Orc& element){
  if(element.is_alive()){
return static_cast<int>('O');
    }
return static_cast<int>('.');
}
int MapMoveVisitor::visit(PairNPC& element){

 return false;
}
