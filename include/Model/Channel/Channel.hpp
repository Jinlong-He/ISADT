#ifndef Model_Channel_hpp
#define Model_Channel_hpp
#include "../Process/CommMethod.hpp"
namespace isadt {
    class Process;
    class Channel  {
        public: 
            Channel();
            ~Channel();
        private:
            struct ProcMethodPair {
                Process* proc_;
                CommMethod* commMethod_;
            };
            ProcMethodPair* srcPair_;
            ProcMethodPair* dstPair_;
            bool privacy_;
    };
}


#endif
