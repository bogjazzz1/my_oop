#include <iostream>
#include "PairNPC.h"
#include "VISITOR.h"
#include "PairNPC.h"
#include "FightMAnager.h"
#include <pthread.h>
const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
std::array<char,grid*(grid*2)> fields{' '};
set_t fight(const set_t &array, size_t distance){
set_t dead_list;
    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {
                PairNPC fighters;
            FightVisitor visitor;
                fighters.first=attacker;
                fighters.second=defender;
                int result=fighters.accept(visitor);
                if(result==1){
                    dead_list.insert(defender);
                }



}
 return dead_list;
}
std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        n->print();
    return os;
}
void save(const set_t &array, const std::string &filename)
{
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename)
{
    set_t result;
    std::ifstream is(filename);
    Factory factor;
    if (is.good() && is.is_open())
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factor.factory(is));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}
int main()
{
    set_t array; // монстры
const int MAXX=MAX_X;
const int MAYY=MAX_Y;

    // Гененрируем начальное распределение монстров
    std::cout << "Generating ..." << std::endl;
    Factory factor;
    for (size_t i = 0; i < 50; ++i)
        array.insert(factor.factory(NpcType(std::rand() % 3 + 1),
                             std::rand() % MAX_X,
                             std::rand() % MAX_Y,"NAME"));

   std::cout << "Fighting ..." << std::endl
              << array;

  std::thread fight_thread(std::ref(FightManager::get()));
bool flag=true;
    std::thread move_thread([&array, MAXX, MAYY,&flag]()
                            {
            while (flag)
            {
                // move phase
                MoveVisitor movie;
                for (std::shared_ptr<NPC> npc : array)
                {
                            npc->accept(movie);

                }
                // lets fight
                for (std::shared_ptr<NPC> npc : array)
                    for (std::shared_ptr<NPC> other : array){
                    PairNPC fighters;
                     DistanceVisitor visitor;
                     fighters.first=npc;
                     fighters.second=other;
                    if( fighters.accept(visitor))
                               FightManager::get().add_event({npc, other});
                    }

                std::this_thread::sleep_for(1s);

            } });
int couunter=31;
    while (couunter>=0)
    {--couunter;
    if(couunter==0){
        flag=false;
FightManager::get().change_flag();
    }
      std::fill(fields.begin(), fields.end(), ' ');
        {
             MapMoveVisitor visit;

            for (std::shared_ptr<NPC> npc : array)
            {
                auto [x, y] = npc->position();
                int i = x / step_x;
                int j = y / step_y;


                    fields.at(i + grid * j) = static_cast<char>(npc->accept(visit));
            }

        std::lock_guard<std::shared_mutex> lck(print_mutex);
           for (int jj = 0; jj < grid; ++jj)
           {
                for (int ii = 0; ii < grid; ++ii)
                {

                    char c1 = fields.at(ii + jj * grid);

                   if (c1 != ' ')
                       std::cout << "[" << c1 << "]";
                   else
                        std::cout << "[ ]";

                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(1s);
    };

move_thread.join();


fight_thread.join();
std::cout<<"alive at the moment"<<std::endl;
for (std::shared_ptr<NPC> npc : array){
    if(npc->is_alive()){
        npc->print();
    }
}



    return 0;
}
