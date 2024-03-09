#ifndef FIGHTMANAGER_H_INCLUDED
#define FIGHTMANAGER_H_INCLUDED
#include <sstream>

#include <thread>
#include <mutex>
#include <shared_mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>
#include "VISITOR.h"
using  namespace std::literals::chrono_literals;
struct FightEvent
{
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager
{
private:
    std::queue<FightEvent> events;
    std::shared_mutex mtx;
 bool fight_flag=true;
    FightManager();

public:
    static FightManager &get();
   void change_flag();

    void add_event(FightEvent &&event);


    void operator()();

};


#endif // FIGHTMANAGER_H_INCLUDED
