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

    Process* Model::mkSystemProcess() {
        systemProc_ = new Process("_sys_", this);
        return systemProc_;
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


    bool Model::isChannelPair(Process* proc1, Edge* edge1, Process* proc2, Edge* edge2) {
        if (edge1 -> getActions().size() > 1) return false;
        if (edge2 -> getActions().size() > 1) return false;
        auto action1 = edge1 -> getActions().front();
        auto action2 = edge2 -> getActions().front();
        if (!action1 -> isAssignmentAction() || !action2 -> isAssignmentAction()) return false;
        if (action1 -> getRhs() || action2 -> getRhs()) return false;
        if (action1 -> getLhs() -> getTermType() != MT || action2 -> getLhs() -> getTermType() != MT) return false;
        auto methodTerm1 = (MethodTerm*) action1 -> getLhs();
        auto methodTerm2 = (MethodTerm*) action2 -> getLhs();
        for (auto channel : channels_) {
            if (channel -> equal(proc1, methodTerm1 -> getMethod(),
                                 proc2, methodTerm2 -> getMethod())) return true;
        }
        return false;
    }

    struct hash_pair {
        template <class T1, class T2> 
        size_t operator()(const std::pair<T1, T2>& p) const {
            return ((size_t)p.first ^ (size_t)p.second);
        }
    };

    struct hash_vec {
        template <class T1> 
        size_t operator()(const std::vector<T1>& v) const {
            size_t seed = 0; 
            for (const auto& t : v) {
                seed ^= (size_t)(t) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };

    StateMachine* Model::mkCommProductStateMahine(const list<StateMachine*>& sms) {
        auto res = systemProc_ -> mkStateMachine();
        unordered_map<std::vector<Vertex*>, Vertex*, hash_vec> vertexMap;
        std::vector<std::vector<Vertex*> > verticesVec;
        std::vector<std::vector<Vertex*> > newVerticesVec;
        for (auto sm : sms) {
            if (verticesVec.size() == 0) {
                for (auto vertex : sm -> getVertices()) {
                    std::vector<Vertex*> vertices({vertex});
                    verticesVec.push_back(vertices);
                }
            } else {
                newVerticesVec.clear();
                for (const auto& vertices : verticesVec) {
                    for (auto vertex : sm -> getVertices()) {
                        std::vector<Vertex*> v = vertices;
                        v.push_back(vertex);
                        newVerticesVec.push_back(v);
                    }
                }
                verticesVec.clear();
                verticesVec = newVerticesVec;
            }
        }
        for (const auto& vertices : verticesVec) {
            string name = "_sys_";
            for (auto vertex : vertices) {
                name += vertex -> getName() + "_";
            }
            vertexMap[vertices] = res -> mkVertex(name);
        }
        for (const auto& vertices : verticesVec) {
            for (auto vertex : vertices) {
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
                if (isChannelPair(proc1, edge1, proc2, edge2)) {
                    std::cout << s -> getName() << std::endl;
                }
            }
        }
        return res;
    }
}
