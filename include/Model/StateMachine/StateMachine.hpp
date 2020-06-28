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
	public:
		StateMachine();
		StateMachine(Process* p);
		~StateMachine();
		void mkStartVertex(std::string name);
		Vertex* getVertexByName(std::string name);

		const Vertex* getStartVertex();

		const std::list<Vertex *>& getVertices() const;

		const std::list<Edge*>& getEdges() const;
		void addVertex(std::string name);

		void delVertex(std::string name);

		void addEdge(Edge* edge);

	private:
    	std::list<Vertex*> vertices_;    //< the set of the states of this fsm.
    	std::list<Edge*> edges_;         //< the set of the transitions of this fsm.
    	Vertex* startVertex_;            //< record the start state of this fsm.
		list<Vertex*> endVertices_;
    	Process* process_;               //< the StateMachine belongs to the process.
	};
}
#endif /* Model_StateMachine_hpp */
