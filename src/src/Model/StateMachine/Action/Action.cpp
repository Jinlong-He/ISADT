#include "Model/StateMachine/Action/Action.hpp"

namespace isadt{
    Action::Action(){

    }
    Action::Action(const string& toParse){

    }

    std::string Action::to_string() const{
        //TODO: assignment for testing remove later
        return "this->testAttr1_ = 0;";
    }
}