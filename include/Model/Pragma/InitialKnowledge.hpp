//
//  InitialKnowledge.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_InitialKnowledge_hpp
#define Model_InitialKnowledge_hpp 
#include "../Process/Attribute.hpp"

namespace isadt {
    class Process;
    class InitialKnowledge {
    public:
        InitialKnowledge();
        InitialKnowledge(Process* process, Attribute* attribute);
        bool isKeyPair();
    private:
        Process* process_;
        Attribute* attribute_;
        InitialKnowledge* pkKnowledge_;
    };
}

#endif /* Model_InitialKnowledge_hpp */
