//
//  Method.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_MethodBase_hpp
#define Model_MethodBase_hpp 
#include <list>
#include "./Attribute.hpp"
using std::list;
namespace isadt {
    /// \brief the method of process.
    class MethodBase {
        public:
            MethodBase()
                : name_(""),
                  returnType_(nullptr) {}
    
            MethodBase(const string& name, 
                       Type* returnType,
                       const std::initializer_list<Attribute*>& parameters)
                : name_(name),
                  returnType_(returnType),
                  parameters_(parameters) {}
    
            MethodBase(const string& name, 
                       Type* returnType)
                : name_(name),
                  returnType_(returnType) {}
    
            ~MethodBase() {
                for (auto p : parameters_) {
                    delete p;
                    p = nullptr;
                }
            }
    
            const string& getName() const;
            void setName(const string& name) ;
    
            Type* getReturnType() const;
            void setReturnType(Type* returnType);
    
            const list<Attribute*>& getParameters() const;
            void addParameter(Attribute* attr);
        private:
           string name_;
           Type* returnType_;
           list<Attribute*> parameters_;  
    };
}

#endif /* Model_Method_hpp */
