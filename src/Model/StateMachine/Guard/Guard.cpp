#include "Model/StateMachine/Guard/Guard.hpp"

namespace isadt {
    Guard::Guard(){

    }
    Guard::Guard(const string& toParse){
        
    }
    Guard::Guard(Expression* expression){

    }

    Expression* Guard::getGuardExpression(){

    }
    void Guard::setGuardExpression(Expression* expression){

    }
    string Guard::to_string() const{
        //TODO  for testing remove later
        return "true";
    }
}