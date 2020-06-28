#ifndef Model_Axiom_hpp
#define Model_Axiom_hpp 
#include "../Process/MethodBase.hpp"

namespace isadt {
    class Process;
    class Axiom {
    public:
    private:
        struct ProcessMethod {
            Process* proc;
            MethodBase* method;
        };
        list<ProcessMethod*> processMethods_;
        list<string> axiomStrings_;
    };
}

#endif /* Axiom_hpp */
