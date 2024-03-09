#include "FightMAnager.h"
FightManager::FightManager(){}
FightManager &FightManager::get(){
        static FightManager instance;
        return instance;
    }
void FightManager::add_event(FightEvent &&event){
        std::lock_guard<std::shared_mutex> lock(mtx);
        events.push(event);
    }
void FightManager::operator()(){
        while (fight_flag)
        {
            {
                std::optional<FightEvent> event;

                {
                    std::lock_guard<std::shared_mutex> lck(mtx);
                    if (!events.empty())
                    {
                        event = events.back();
                        events.pop();
                    }
                }

                if (event)
                {
                    try
                    {PairNPC fighters;
                     FightVisitor visitor;
                     fighters.first=event->attacker;
                     fighters.second=event->defender;
                     fighters.accept(visitor);
                       /* if (event->attacker->is_alive())     // no zombie fighting!
                            if (event->defender->is_alive()) // already dead!
                                if (event->defender->accept(event->attacker))
                                    event->defender->must_die();*/
                    }
                    catch (...)
                    {
                        std::lock_guard<std::shared_mutex> lck(mtx);
                        events.push(*event);
                    }
                }
                else
                    std::this_thread::sleep_for(100ms);
            }
        }
    }
void FightManager::change_flag(){
    fight_flag=false;
}
