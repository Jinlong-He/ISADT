//
//  Process.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Process_hpp
#define Model_Process_hpp
#include <map>
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
        Process();
        Process(Model* model);
        ~Process();

        Model* getModel() const;
        void setModel(Model* model);

        Attribute* mkAttribute(Type* type, const string& name);
        Method* mkMethod(const string& name, Type* returnType, list<Attribute*> parameters);
        CommMethod* mkCommMethod(const string& name, bool inout, Attribute* parameter);
        
        StateMachine* mkFst();

        const list<Attribute*>& getAttributes();

        const std::string& getProcName();

        void setProcName(std::string procName);

        const list<Method*>& getMethods() const;
        const list<CommMethod*>& getCommMethods() const;
        const StateMachine* getStateMachine();
        
    private:
        std::string procName_;
        list<Attribute*> attributes_;        ///< the attributes for this process.
        list<Method*> methods_;              ///< the methods for this process.
        list<CommMethod*> commMethods_;      ///< the communication methods for this process.
        list<StateMachine*> stateMachines_;  ///< the finite state machines for this process.
        //TODO map (state,sm) to sm
        std::map<VertexSmPair*, StateMachine*> stateSmMap;
        StateMachine* stateMachine_;
        Model* model_;                       ///< the model this process from.
    };
}

#endif /* Model_Process_hpp */
