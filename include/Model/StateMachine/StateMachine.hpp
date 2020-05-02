//
//  StateMachine.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_StateMachine_hpp
#define Model_StateMachine_hpp
#include <list>
#include "Vertex.hpp"
#include "Edge.hpp"
using std::string;
namespace isadt {
    class Process;

    /// \brief StateMachine class
	class StateMachine {
	private:
    	std::list<Vertex*> vertexes_;    //< the set of the states of this fsm.
    	std::list<Edge*> edges_;         //< the set of the transitions of this fsm.
    	Vertex* startVertex_;            //< record the start state of this fsm.
    	Process* process_;               //< the StateMachine belongs to the process.
	};
}
#endif /* Model_StateMachine_hpp */
