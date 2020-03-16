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
        CommMethod(const string& _name, bool _inout, Attribute* _parameter);
        ~CommMethod() {
            delete parameter;
        }

        const string& getName() const;
        void setName(const string& _name) ;

        bool getInOut() const ;
        void setInOut(bool _inout);

        Attribute* getParamter() const;
        void setParameters(Attribute* _parameter);

    private:
        string name;                //< the signal name.
        bool inout;                 //< the in_out value.
        Attribute* parameter;       //< the parameter to send/receive.
    };
}

#endif /* Model_CommMethod_hpp */
