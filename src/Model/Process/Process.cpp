#include "Model/Process/Process.hpp"
#include <iostream>
namespace isadt{
    Process::Process(){

    }
    Process::Process(Model* model){
        this->model_ = model;
    }
    Process::~Process() {
        //delete attributes, methods, signals and fst.
    }
    Model* Process::getModel() const{
        return this->model_;
    }
    void Process::setModel(Model* model){
        this->model_ = model;
    }
    Attribute* Process::mkAttribute(Type* type, const string& name){
        Attribute* attr = new Attribute(type, name);
        this->attributes_.push_front(attr);
        return attr;
    }
    Method* Process::mkMethod(const string& name, Type* returnType, list<Attribute*> parameters){
        for(Method* m : this->methods_){
            if(!m->getName().compare(name)){
                std::cout << "err: method already exists" << std::endl;
                return NULL;
            }
        }
        Method* m = new Method(name, returnType, parameters, "0", "");
        this->methods_.push_back(m);
        return m;
    }
    CommMethod* Process::mkCommMethod(const string& name, bool inout, Attribute* parameter){

    }
    
    StateMachine* Process::mkFst(){
        StateMachine* sm = new StateMachine(this);
        this->statemachine_ = sm;
        return sm;
    }

    const list<Attribute*>& Process::getAttributes(){
        return this->attributes_;
    }
    const std::string& Process::getProcName(){
        return this->procName_;
    }
    void Process::setProcName(std::string procName){
        this->procName_ = procName;
    }
    const list<Method*>& Process::getMethods() const{
        return this->methods_;
    }
    const list<CommMethod*>& Process::getCommMethods() const{
        return this->commMethods_;
    }
    const StateMachine* Process::getStateMachine(){
        return this->statemachine_;
    }
}
        