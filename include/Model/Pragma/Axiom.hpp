

#ifndef Model_Axiom_hpp
#define Model_Axiom_hpp 
#include "Process.hpp"
namespace isadt {
    class Axiom {
    public:
       
    private:
        struct ProcessMethod {
            Process* proc;
            Method* method;
        };
        list<ProcessMethod> processMethods_;
        list<string> axiomStrings_;
    };
}

#endif /* Axiom_hpp */
