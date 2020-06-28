#ifndef Model_Channel_hpp
#define Model_Channel_hpp
#include "./ProcMethodPair.hpp"

namespace isadt {
    class Channel  {
        public: 
            Channel();
            ~Channel();
        private:
            ProcMethodPair* srcPair_;
            ProcMethodPair* dstPair_;
            bool privacy_;

    };
}


#endif