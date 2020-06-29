//
//  Process.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Process_hpp
#define Model_Process_hpp
#include <unordered_map>
#include <unordered_set>
#include "Method.hpp"
#include "CommMethod.hpp"
#include "Attribute.hpp"
#include "../StateMachine/StateMachine.hpp"

namespace isadt {
    class Model;
    class VertexSmPair{
        public: 
            VertexSmPair(Vertex* v, StateMachine* m);
        private:
            Vertex *v;
            StateMachine* sm;
    };
    /// \brief the process of model.
    class Process {
    public:
        Process()
            : model_(nullptr) {}

        Process(Model* model) 
            : model_(model) {}

        ~Process() {
            for (auto attr : attributes_) {
                delete attr;
                attr = nullptr;
            }
            for (auto method : methods_) {
                delete method;
                method = nullptr;
            }
            for (auto commMethod : commMethods_) {
                delete commMethod;
                commMethod = nullptr;
            }
            for (auto stateMachine : stateMachines_) {
                delete stateMachine;
                stateMachine = nullptr;
            }
            delete stateMachine_;
            stateMachine_ = nullptr;
        }

        Model* getModel() const;
        void setModel(Model* model);
        
        StateMachine* mkStateMachine();

        const list<Attribute*>& getAttributes();
        void addAttribute(Attribute* attr);
        void addMethod(Method* m);
        void addCommMethod(CommMethod* m);

        const std::string& getProcName();
        void setProcName(std::string procName);

        const list<Method*>& getMethods() const;
        const list<CommMethod*>& getCommMethods() const;
        const StateMachine* getStateMachine();
        
    private:
        Model* model_;                       ///< the model this process from.
        std::string procName_;
        list<Attribute*> attributes_;        ///< the attributes for this process.
        list<Method*> methods_;              ///< the methods for this process.
        list<CommMethod*> commMethods_;      ///< the communication methods for this process.
        list<StateMachine*> stateMachines_;  ///< the finite state machines for this process.
        //TODO map (state,sm) to sm
        std::unordered_map<VertexSmPair*, StateMachine*> stateSmMap;
        StateMachine* stateMachine_;
        std::unordered_set<std::string> nameSet_;
    };
}

#endif /* Model_Process_hpp */
