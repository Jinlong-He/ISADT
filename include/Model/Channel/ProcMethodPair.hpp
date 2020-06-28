#ifndef Model_ProcMethodPair_hpp
#define Model_ProcMethodPair_hpp
#include "../Process/Process.hpp"
#include "../Process/CommMethod.hpp"
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