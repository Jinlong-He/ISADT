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

    UserType* Model::mkUserType(const string& name, 
                                const std::initializer_list<Attribute*>& parameters, 
                                UserType* base) {
        UserType* type = new UserType(name, parameters, base);
        userTypes_.push_back(type);
        userTypeMap[name] = type;
        return type;
    }

    UserType* Model::getUserTypeByName(const string& name) {
        if (userTypeMap.count(name) == 0) return nullptr;
        return userTypeMap[name];
    }

    UserType* Model::getUserTypeById(const string& id) {
        return getUserTypeById(stoi(id));
    }

    UserType* Model::getUserTypeById(int id) {
        if (id == -1 || userTypes_.size() < id) return nullptr;
        return userTypes_[id - 1];
    }

    Process* Model::mkProcess(){
        Process* p = new Process(this);
        procs_.push_back(p);
        return p;
    }

    Attribute* Model::mkAttribute(Type* type, const string& name){
        if (attributeMap.count(name) > 0) {
            std::cout << "err: method already exists" << std::endl;
            return nullptr;
        }
        Attribute* attr = new Attribute(type, name);
        attributeMap[name] = attr;
        return attr;
    }

    Method* Model::mkMethod(const string& name, Type* returnType, 
                              const std::initializer_list<Attribute*>& parameters,
                              const string& algorithmId,
                              const string& userCode) {
        if (methodMap.count(name) > 0) {
            std::cout << "err: method already exists" << std::endl;
            return nullptr;
        }
        Method* method = new Method(name, returnType, parameters, algorithmId, userCode);
        methodMap[name] = method;
        return method;
    }

    Method* Model::mkMethod(const string& name, Type* returnType, 
                              const string& algorithmId,
                              const string& userCode) {
        if (methodMap.count(name) > 0) {
            std::cout << "err: method already exists" << std::endl;
            return nullptr;
        }
        Method* method = new Method(name, returnType, algorithmId, userCode);
        methodMap[name] = method;
        return method;
    }

    CommMethod* Model::mkCommMethod(const string& name, 
                                      const std::initializer_list<Attribute*>& parameters,
                                      bool inout,
                                      const string& commId){
        if (methodMap.count(name) > 0) {
            std::cout << "err: method already exists" << std::endl;
            return nullptr;
        }
        CommMethod* method = new CommMethod(name, nullptr, parameters, inout, commId);
        methodMap[name] = method;
        return method;
    }

    CommMethod* Model::mkCommMethod(const string& name, 
                                      bool inout,
                                      const string& commId){
        if (methodMap.count(name) > 0) {
            std::cout << "err: method already exists" << std::endl;
            return nullptr;
        }
        CommMethod* method = new CommMethod(name, nullptr, inout, commId);
        methodMap[name] = method;
        return method;
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

    const vector<UserType*>& Model::getUserTypes() const {
        return userTypes_;
    }
}
