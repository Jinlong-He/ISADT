#include "Model/Model.hpp"
#include <iostream>
namespace isadt{
    UserType* Model::mkUserType(const string& name, 
                                UserType* base) {
        UserType* type = new UserType(name, base);
        userTypes_.push_back(type);
        userTypeMap_[name] = type;
        return type;
    }

    UserType* Model::getUserTypeByName(const string& name) {
        if (userTypeMap_.count(name) == 0) return mkUserType(name);
        return userTypeMap_[name];
    }

    void Model::addUserType(UserType* type) {
        userTypeMap_[type -> getName()] = type;
    }

    //UserType* Model::getUserTypeById(const string& id) {
    //    return getUserTypeById(stoi(id));
    //}

    //UserType* Model::getUserTypeById(int id) {
    //    if (id == -1 || userTypes_.size() < id) return nullptr;
    //    return userTypes_[id - 1];
    //}

    Process* Model::mkProcess(const string& name) {
        Process* proc = new Process(name, this);
        procs_.push_back(proc);
        procMap_[name] = proc;
        return proc;
    }

    Process* Model::getProcByName(const string& name) {
        if (procMap_.count(name) == 0) return mkProcess(name);
        return procMap_[name];
    }

    ConfidentialProperty*
    Model::mkConfidentialProperty(Process* process, Attribute* attribute){
        
    }
    AuthenticityProperty* 
    Model::mkAuthenticityProperty(Process* process1, Vertex* vertex1, Attribute* attribute1,
                           Process* process2, Vertex* vertex2, Attribute* attribute2){

                           }
    InitialKnowledge* 
    Model::mkInitialKnowledge(Process* process, Attribute* attribute){

    }
    
    const list<Process*>& Model::getProcesses() const{
        return procs_;
    }

    const list<UserType*>& Model::getUserTypes() const {
        return userTypes_;
    }

    bool Model::hasUserType(const string& name) {
        return userTypeMap_.count(name);
    }

    StateMachine* Model::mkCommProductStateMahine(StateMachine* sm1, StateMachine* sm2) {
        auto proc = getProcesses().front();
        auto res = proc -> mkStateMachine();
        unordered_map<std::pair<Vertex*, Vertex*>, Vertex*> vertexMap;
        for (auto vertex1 : sm1 -> getVertices()) {
            for (auto vertex2 : sm2 -> getVertices()) {
                auto vertex = res -> mkVertex(vertex1 -> getName() + "," + vertex2 -> getName());
                vertexMap[std::pair(vertex1, vertex2)] = vertex;
            }
        }
        for (auto edge1 : sm1 -> getEdges()) {
            for (auto edge2 : sm2 -> getEdges()) {
                
            }
        }
        return res;
    }
}
