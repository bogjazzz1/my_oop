#include "Fabric.h"
std::shared_ptr<NPC> Factory::factory(std::istream &is)
{
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
        switch (type)
        {
        case OrcType:
            result = std::make_shared<Orc>(is);
            break;
        case SquirrelType:
            result = std::make_shared<Squirrel>(is);
            break;
        case DruidType:
            result = std::make_shared<Druid>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result){
        result->subscribe(TextObserver::get());
        result->subscribe(FileObserver::get());
    }

    return result;
}
std::shared_ptr<NPC> Factory::factory(NpcType type, int x, int y,std::string name)
{
    std::shared_ptr<NPC> result;

    switch (type)
    {
    case OrcType:
        result = std::make_shared<Orc>(  x,  y, name);
        break;
    case SquirrelType:
        result = std::make_shared<Squirrel>( x,  y, name);
        break;
    case DruidType:
        result = std::make_shared<Druid>(x,  y, name);
        break;
    default:
        std::cerr << "unexpected NPC type:" << type << std::endl;
        break;
    }



    if (result){
        result->subscribe(TextObserver::get());
        result->subscribe(FileObserver::get());
    }

    return result;
}
