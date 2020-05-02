//
//  Property.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Property_hpp
#define Model_Property_hpp 
#include "../Process/Process.hpp"

namespace isadt {
    class Property {
        Property();
    private:
    };

    class ConfidentialProperty : public Property {
        ConfidentialProperty();
        ConfidentialProperty(Process* process, Attribute* attribute);
    private:
        Process* process_;
        Attribute* attribute_;
    };

    class AuthenticityProperty : public Property {
        AuthenticityProperty();
        AuthenticityProperty(Process* process1, Vertex* vertex1, Attribute* attribute1,
                             Process* process2, Vertex* vertex2, Attribute* attribute2);
    private:
        struct Value {
            Process* process;
            Vertex* vertex;
            Attribute* attribute;
        };
        Value* value1_;
        Value* value2_;
    };
}

#endif /* Model_Property_hpp */
