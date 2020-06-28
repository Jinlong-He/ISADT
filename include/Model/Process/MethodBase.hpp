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
            MethodBase();
    
            MethodBase(const string& name, 
                   Type* returnType, 
                   const list<Attribute*>& parameters);
    
            ~MethodBase();
    
            const string& getName() const;
            void setName(const string& name) ;
    
            Type* getReturnType() const;
            void setReturnType(Type* returnType);
    
            const list<Attribute*>& getParameters() const;
            void setParameters(const list<Attribute*>& parameters);
    
            const string& getName();
        private:
           string name_;
           Type* returnType_;
           list<Attribute*> parameters_;  
    };
}

#endif /* Model_Method_hpp */
