//
//  Model.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Model_hpp
#define Model_Model_hpp 
#include <vector>
#include "Type/UserType.hpp"
#include "Process/Process.hpp"
#include "Pragma/Property.hpp"
#include "Pragma/InitialKnowledge.hpp"
#include "SequenceDiagram/SequenceDiagram.hpp"
#include "Pragma/Axiom.hpp"
#include "Channel/Channel.hpp"
using std::vector;
namespace isadt {
    /// \brief the model in isadt.
    class Model {
    public:
        Model() {
        }

        ~Model() {
            for (auto proc : procs_) {
                delete proc;
                proc = nullptr;
            }
            for (auto prop : props_) {
                delete prop;
                prop = nullptr;
            }
            for (auto ik : initialKnowledges_) {
                delete ik;
                ik = nullptr;
            }
            for (auto ut : userTypes_) {
                delete ut;
                ut = nullptr;
            }
            for (auto axiom : axioms_) {
                delete axiom;
                axiom = nullptr;
            }
            for (auto channel : channels_) {
                delete channel;
                channel = nullptr;
            }
        }
        UserType* mkUserType(const string& name, 
                             UserType* base = nullptr);

        UserType* mkUserType(const string& name, 
                             const std::initializer_list<Attribute*>& parameters, 
                             UserType* base = nullptr);

        Process* mkProcess();
        Process* mkProcess(std::string procName);

        Attribute* mkAttribute(Type* type, const string& name);
        Method* mkMethod(const string& name, Type* returnType, 
                         const std::initializer_list<Attribute*>& parameters,
                         const string& algorithmId,
                         const string& userCode = "");

        Method* mkMethod(const string& name, Type* returnType, 
                         const string& algorithmId,
                         const string& userCode = "");

        CommMethod* mkCommMethod(const string& name, 
                                 const std::initializer_list<Attribute*>& parameters,
                                 bool inout,
                                 const string& commId);

        CommMethod* mkCommMethod(const string& name, 
                                 bool inout,
                                 const string& commId);
        ConfidentialProperty*
        mkConfidentialProperty(Process* process, Attribute* attribute);

        AuthenticityProperty* 
        mkAuthenticityProperty(Process* process1, Vertex* vertex1, Attribute* attribute1,
                               Process* process2, Vertex* vertex2, Attribute* attribute2);

        InitialKnowledge* 
        mkInitialKnowledge(Process* process, Attribute* attribute);
        
        const list<Process*>& getProcesses() const;
        const vector<UserType*>& getUserTypes() const;

        UserType* getUserTypeByName(const string& name);
        UserType* getUserTypeById(const string& id);
        UserType* getUserTypeById(int id);
    private:
        list<Process*> procs_;
        list<Property*> props_;
        list<InitialKnowledge*> initialKnowledges_;
        vector<UserType*> userTypes_;
        list<Axiom*> axioms_;
        list<Channel*> channels_;
        std::unordered_map<string, UserType*> userTypeMap;
        std::unordered_map<string, Attribute*> attributeMap;
        std::unordered_map<string, MethodBase*> methodMap;
        //list<SequenceDiagram*> sd_;
        // ProcMethodPair * 2, bool privacy

    };
}

#endif /* Model_Model_hpp */
