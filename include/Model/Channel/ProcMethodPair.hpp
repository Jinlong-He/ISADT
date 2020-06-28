#ifndef Model_ProcMethodPair_hpp
#define Model_ProcMethodPair_hpp
#include "../Process/CommMethod.hpp"
class Process;
namespace isadt{
    class ProcMethodPair {
    public:
        ProcMethodPair();
        ~ProcMethodPair();
    private:
        Process* proc_;
        //MAKESURE 
        CommMethod* commMethod_;
    };

}

#endif
