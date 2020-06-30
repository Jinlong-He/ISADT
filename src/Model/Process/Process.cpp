#include "Model/Process/Process.hpp"
#include <iostream>
namespace isadt{
    Model* Process::getModel() const{
        return model_;
    }
    void Process::setModel(Model* model){
        model_ = model;
    }

    StateMachine* Process::mkStateMachine(Vertex* parent) {
        StateMachine* sm = new StateMachine(parent, this);
        stateMachines_.push_back(sm);
        return sm;
    }

    CommMethod* Process::mkCommMethod(const string& name, 
                               UserType* returnType,
                               bool inout, 
                               const string& commId) {
        CommMethod* method = new CommMethod(name, returnType, inout, commId);
        commMethods_.push_back(method);
        commMethodMap[name] = method;
        return method;
    }

    CommMethod* Process::mkCommMethod(const string& name) {
        return mkCommMethod(name, nullptr, 0, "");
    }

    CommMethod* Process::getCommMethodByName(const string& name) {
        if (commMethodMap.count(name) == 0) return mkCommMethod(name);
        return commMethodMap[name];
    }
    
    const list<CommMethod*>& Process::getCommMethods() const{
        return commMethods_;
    }
    const StateMachine* Process::getStateMachine(){
        return stateMachine_;
    }
    void Process::addVertex(Vertex* vertex) {
        vertexMap[vertex -> getName()] = vertex;
    }
    Vertex* Process::getVertexByName(const string& name) {
        if (vertexMap.count(name) == 0) return nullptr;
        return vertexMap[name];
    }
}
        
