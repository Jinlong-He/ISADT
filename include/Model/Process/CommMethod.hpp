//
//  CommMethod.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_CommMethod_hpp
#define Model_CommMethod_hpp 
#include "Attribute.hpp"
#include "MethodBase.hpp"

namespace isadt {
    /// \brief the signal of process.
    class CommMethod : public MethodBase{
    public:
        CommMethod()
            : MethodBase() {}

        CommMethod(const string& name, 
                   Type* returnType,
                   const std::initializer_list<Attribute*>& parameters,
                   bool inout, 
                   const string& commId = "")
            : MethodBase(name, returnType, parameters),
              inout_(inout),
              commId_(commId) {}

        CommMethod(const string& name, 
                   Type* returnType,
                   bool inout, 
                   const string& commId = "")
            : MethodBase(name, returnType),
              inout_(inout),
              commId_(commId) {}

        ~CommMethod() {
        }

        bool getInOut() const ;
        void setInOut(bool _inout);

    private:
        bool inout_;                 //< the in_out value.
        string commId_;              //< the communication identifier.
    };
}

#endif /* Model_CommMethod_hpp */
