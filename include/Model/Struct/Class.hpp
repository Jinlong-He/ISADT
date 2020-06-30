//
//  Class.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Class_hpp
#define Model_Class_hpp
#include "../Process/Method.hpp"
#include "Struct.hpp"

namespace isadt {
    class Class : public Struct {
    public:
        Class() : Struct() {}

        Class(const string& name)
            : Struct(name) {}

        ~Class() {
            for (auto m : methods_) {
                delete m;
                m = nullptr;
            }
        }

        Method* mkMethod(const string& name, UserType* returnType,
                         const string& algorithmId, const string& userCode);
        Method* mkMethod(const string& name);
        Method* getMethodByName(const string& name);
        const list<Method*>& getMethods() const;
    private:
        list<Method*> methods_;
        unordered_map<string, Method*> methodMap;
    };
}

#endif /* Model_Struct_hpp */
