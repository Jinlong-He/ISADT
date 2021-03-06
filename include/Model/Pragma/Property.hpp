//
//  Property.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Property_hpp
#define Model_Property_hpp 
#include "../Process/Attribute.hpp"
#include "../StateMachine/Vertex.hpp"

namespace isadt {
    class Process;
    class Property {
    public:
        Property();
    };

    class SecurityProperty : Property {
    public:
        SecurityProperty()
            : Property() {}
    };

    class SafetyProperty : Property{
    public:
        SafetyProperty()
            : Property() {}
    };

    class ConfidentialProperty : public SecurityProperty {
        ConfidentialProperty()
            : SecurityProperty(),
              proc_(nullptr),
              attribute_(nullptr) {}
        ConfidentialProperty(Process* proc, Attribute* attribute)
            : SecurityProperty(),
              proc_(proc),
              attribute_(attribute) {}
    private:
        Process* proc_;
        Attribute* attribute_;
    };

    class AuthenticityProperty : public SecurityProperty {
        AuthenticityProperty()
            : SecurityProperty(),
              value1_(nullptr),
              value2_(nullptr) {}
        AuthenticityProperty(Process* proc1, Vertex* vertex1, Attribute* attribute1, Attribute* inner1,
                             Process* proc2, Vertex* vertex2, Attribute* attribute2, Attribute* inner2)
            : SecurityProperty(),
              value1_(new Value(proc1, vertex1, attribute1, inner1)),
              value2_(new Value(proc2, vertex2, attribute2, inner2)) {}
        ~AuthenticityProperty() {
            delete value1_;
            value1_ = nullptr;
            delete value2_;
            value2_ = nullptr;
        }
    private:
        struct Value {
        public:
            Value()
                : proc_(nullptr),
                  vertex_(nullptr),
                  attribute_(nullptr),
                  inner_(nullptr) {}
            Value(Process* proc, Vertex* vertex, Attribute* attribute, Attribute* inner)
                : proc_(proc),
                  vertex_(vertex),
                  attribute_(attribute),
                  inner_(inner) {}
        private:
            Process* proc_;
            Vertex* vertex_;
            Attribute* attribute_;
            Attribute* inner_;
        };
        Value* value1_;
        Value* value2_;
    };

    class IntegratyProperty : public SecurityProperty {
        IntegratyProperty()
            : SecurityProperty(),
              value1_(nullptr),
              value2_(nullptr) {}
        IntegratyProperty(Process* proc1, Vertex* vertex1, Attribute* attribute1,
                          Process* proc2, Vertex* vertex2, Attribute* attribute2)
            : SecurityProperty(),
              value1_(new Value(proc1, vertex1, attribute1)),
              value2_(new Value(proc2, vertex2, attribute2)) {}
    private:
        struct Value {
        public:
            Value()
                : proc_(nullptr),
                  vertex_(nullptr),
                  attribute_(nullptr) {}
            Value(Process* proc, Vertex* vertex, Attribute* attribute)
                : proc_(proc),
                  vertex_(vertex),
                  attribute_(attribute) {}
        private:
            Process* proc_;
            Vertex* vertex_;
            Attribute* attribute_;
        };
        Value* value1_;
        Value* value2_;
    };
    
    class CTLProperty : public SafetyProperty{
        CTLProperty()
            : SafetyProperty() {}
        CTLProperty(const string& ctlStr)
            : SafetyProperty(),
              ctlStr_(ctlStr) {}
        private:
            string ctlStr_;
    };

    class InvariantProperty : public SafetyProperty{
        InvariantProperty()
            : SafetyProperty() {}
        InvariantProperty(const string invariantStr)
            : SafetyProperty(),
              invariantStr_(invariantStr) {}
        private:
            string invariantStr_;
    };
}

#endif /* Model_Property_hpp */
