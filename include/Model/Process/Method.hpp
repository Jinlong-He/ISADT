//
//  Method.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Method_hpp
#define Model_Method_hpp 
#include <list>
#include "Attribute.hpp"
using std::list;

namespace isadt {
    /// \brief the method of process.
    class Method {
        Method()
            : returnType(nullptr) {}

        Method(const string& _name, Type* _returnType, list<Attribute*> _parameters)
            : name(_name),
              returnType(_returnType),
              parameters(_parameters) {}

        ~Method() {
            for (auto p : parameters) {
                delete p;
            }
        }

        const string& getName() const;
        void setName(const string& _name) ;

        Type* getReturnType() const ;
        void setReturnType(Type* _returnType);

        const list<Attribute*>& getParamters() const;
        void setParameters(const list<Attribute*>& _parameters);

    private:
        string name;                    //< the method name.
        Type* returnType;               //< the return data type.
        list<Attribute*> parameters;    //< the parameters.
        string algorismId;
        string userCode;
    };
}

#endif /* Model_Method_hpp */
