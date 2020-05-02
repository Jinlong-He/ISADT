//
//  CommMethod.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_CommMethod_hpp
#define Model_CommMethod_hpp 
#include "Attribute.hpp"

namespace isadt {
    /// \brief the signal of process.
    class CommMethod {
        CommMethod();
        CommMethod(const string& name, 
                   bool inout, 
                   Attribute* parameter, 
                   const string& commId)
            : name_(name),
              inout_(inout),
              parameter_(parameter),
              commId_(commId) {}

        ~CommMethod() {
            delete parameter_;
        }

        const string& getName() const;
        void setName(const string& _name) ;

        bool getInOut() const ;
        void setInOut(bool _inout);

        Attribute* getParamter() const;
        void setParameters(Attribute* _parameter);

    private:
        string name_;                //< the signal name.
        bool inout_;                 //< the in_out value.
        Attribute* parameter_;       //< the parameter to send/receive.
        const string& commId_;       //< the communication identifier.
    };
}

#endif /* Model_CommMethod_hpp */
