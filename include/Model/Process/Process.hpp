//
//  Process.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Process_hpp
#define Model_Process_hpp 
#include "Method.hpp"
#include "CommMethod.hpp"
#include "../StateMachine/StateMachine.hpp"

namespace isadt {
    class Model;

    /// \brief the process of model.
    class Process {
    public:
        Process();
        Process(Model* _model);
        ~Process() {
            //delete attributes, methods, signals and fst.
        }

        Model* getModel() const;
        void setModel(Model* _model);

        Attribute* mkAttribute(Type* type, const string& name);
        Method* mkMethod(const string& _name, Type* _returnType, list<Attribute*> _parameters);
        CommMethod* mkCommMethod(const string& _name, bool _inout, Attribute* _parameter);
        StateMachine* mkFst();
    private:
        list<Attribute*> attributes;        ///< the attributes for this process.
        list<Method*> methods;              ///< the methods for this process.
        list<CommMethod*> commMethods;      ///< the communication methods for this process.
        list<StateMachine*> statemachines;  ///< the finite state machines for this process.
        Model* model;                       ///< the model this process from.
    };
}

#endif /* Model_Process_hpp */
