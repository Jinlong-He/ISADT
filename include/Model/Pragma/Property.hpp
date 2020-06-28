//
//  Property.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Property_hpp
#define Model_Property_hpp 
#include "../Process/Attribute.hpp"

namespace isadt {
    class Process;
    class Property {
        Property();
        private:
    };
    class SecurityProperty : Property {
        SecurityProperty();
    private:
    };

    class SafetyProperty : Property{
        SafetyProperty();
    private:
    };

    class ConfidentialProperty : public SecurityProperty {
        ConfidentialProperty();
        ConfidentialProperty(Process* process, Attribute* attribute);
    private:
        Process* process_;
        Attribute* attribute_;
    };

    class AuthenticityProperty : public SecurityProperty {
        AuthenticityProperty();
        AuthenticityProperty(Process* process1, Vertex* vertex1, Attribute* attribute1,
                             Process* process2, Vertex* vertex2, Attribute* attribute2);
    private:
        struct Value {
            Process* process;
            Vertex* vertex;
            Attribute* attribute;
            Attribute* inner;
        };
        Value* value1_;
        Value* value2_;
    };

    class IntegratyProperty : public SecurityProperty {
        IntegratyProperty();
        IntegratyProperty(Process* process1, Vertex* vertex1, Attribute* attribute1,
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
    
    class CTLProperty : public SafetyProperty{
        CTLProperty();
        private:
            string CTLString;
    };

    class InvariantProperty : public SafetyProperty{
        InvariantProperty();
        private:
            string InvariantString;
    };
}

#endif /* Model_Property_hpp */
