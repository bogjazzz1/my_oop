#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED
#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>
#include <shared_mutex>

enum NpcType
{
    Unknown = 0,
    SquirrelType = 1,
    DruidType = 2,
    OrcType = 3
};
static std::shared_mutex print_mutex;
const int MAX_X{100};
const int MAX_Y{100};

class NPC;
class Squirrel;
class Druid;
class Orc;
class Visitor;
class PairNPC;
using set_t = std::set<std::shared_ptr<NPC>>;
class IFightObserver{

    public:
    virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender,bool win) = 0;
};;
class NPC :public std::enable_shared_from_this<NPC>{
NpcType type;

int x{0};
int y{0};
std::string name;
mutable std::mutex mtx;
bool alive=true;
std::vector<std::shared_ptr<IFightObserver>> observers;
public:
NPC(NpcType t, int _x, int _y,std::string _name);
NPC(NpcType t, std::istream &is);

void subscribe(std::shared_ptr<IFightObserver>observer );
void fight_notify(const std::shared_ptr<NPC> defender,bool win);
virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;
virtual void print() = 0;
virtual void save(std::ostream &os);
friend std::ostream &operator<<(std::ostream &os, NPC &npc);
virtual int accept(Visitor& visitor) = 0;
std::pair<int, int> position();
void move(int shift_x, int shift_y, int max_x, int max_y);
bool is_alive();
void must_die();
};
class Visitor{
    public:
virtual int visit(Squirrel& element) = 0;
virtual int visit(Druid& element) = 0;
virtual int visit(Orc& element) = 0;
virtual int visit(PairNPC& element) = 0;
};
#endif // NPC_H_INCLUDED
