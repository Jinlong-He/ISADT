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

    Channel* Model::mkChannel(Process* p1, CommMethod* cm1,
                              Process* p2, CommMethod* cm2, bool privacy) {
        auto channel = new Channel(p1, cm1, p2, cm2, privacy);
        channels_.push_back(channel);
        return channel;
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

    struct hash_pair {
        template <class T1, class T2> 
        size_t operator()(const std::pair<T1, T2>& p) const {
            return ((size_t)p.first ^ (size_t)p.second);
        }
    };

    StateMachine* Model::mkCommProductStateMahine(StateMachine* sm1, StateMachine* sm2) {
        auto proc = getProcesses().front();
        auto res = proc -> mkStateMachine();
        unordered_map<std::pair<Vertex*, Vertex*>, Vertex*, hash_pair> vertexMap;
        for (auto vertex1 : sm1 -> getVertices()) {
            for (auto vertex2 : sm2 -> getVertices()) {
                auto vertex = res -> mkVertex(vertex1 -> getName() + "," + vertex2 -> getName());
                vertexMap[std::pair(vertex1, vertex2)] = vertex;
            }
        }
        for (auto edge1 : sm1 -> getEdges()) {
            for (auto edge2 : sm2 -> getEdges()) {
                auto s1 = edge1 -> getFromVertex();
                auto s2 = edge2 -> getFromVertex();
                auto t1 = edge1 -> getToVertex();
                auto t2 = edge2 -> getToVertex();
                auto s = vertexMap.at(std::pair(s1, s2));
                auto t = vertexMap.at(std::pair(t1, t2));
                auto e = res -> mkEdge(s, t);
                res -> cpEdge(e, edge1);
                res -> cpEdge(e, edge2);
            }
        }
        return res;
    }
}
