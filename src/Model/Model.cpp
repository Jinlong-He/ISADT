#include "Model/Model.hpp"
#include <iostream>
namespace isadt{
    UserType* Model::mkUserType(const string& name, 
                                UserType* base) {
        UserType* type = new UserType(name, base);
        userTypes_.push_back(type);
        userTypeMap[name] = type;
        return type;
    }

    UserType* Model::getUserTypeByName(const string& name) {
        if (userTypeMap.count(name) == 0) return mkUserType(name);
        return userTypeMap[name];
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
        procMap[name] = proc;
        return proc;
    }

    Process* Model::getProcByName(const string& name) {
        if (procMap.count(name) == 0) return mkProcess(name);
        return procMap[name];
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
        return userTypeMap.count(name);
    }
}
