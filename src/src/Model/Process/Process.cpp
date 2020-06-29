#include "Model/Process/Process.hpp"
#include <iostream>
namespace isadt{
    Model* Process::getModel() const{
        return model_;
    }
    void Process::setModel(Model* model){
        model_ = model;
    }

    StateMachine* Process::mkStateMachine(){
        //StateMachine* sm = new StateMachine(this);
        //this->statemachine_ = sm;
        //return sm;
    }

    const list<Attribute*>& Process::getAttributes(){
        return attributes_;
    }

    void Process::addAttribute(Attribute* attr) {
        attributes_.push_back(attr);
    }
    void Process::addMethod(Method* m) {
        methods_.push_back(m);
    }

    void Process::addCommMethod(CommMethod* m) {
        commMethods_.push_back(m);
    }

    const std::string& Process::getProcName(){
        return procName_;
    }
    void Process::setProcName(std::string procName){
        procName_ = procName;
    }
    const list<Method*>& Process::getMethods() const{
        return methods_;
    }
    const list<CommMethod*>& Process::getCommMethods() const{
        return commMethods_;
    }
    const StateMachine* Process::getStateMachine(){
        return stateMachine_;
    }
}
        
