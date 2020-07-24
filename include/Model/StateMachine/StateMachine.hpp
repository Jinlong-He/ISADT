//
//  StateMachine.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_StateMachine_hpp
#define Model_StateMachine_hpp
#include <list>
#include <unordered_map>
#include "Vertex.hpp"
#include "Edge.hpp"
using std::string;
namespace isadt {
    class Process;

    /// \brief StateMachine class
	class StateMachine {
	public:
		StateMachine()
            : startVertex_(nullptr),
              parent_(nullptr),
              proc_(nullptr) {}

		StateMachine(Vertex* parent,
                     Process* proc)
            : startVertex_(nullptr),
              parent_(parent),
              proc_(proc) {}

		StateMachine(Process* proc)
            : startVertex_(nullptr),
              parent_(nullptr),
              proc_(proc) {}

		~StateMachine() {
            for (auto vertex : vertices_) {
                delete vertex;
                vertex = nullptr;
            }
            for (auto edge : edges_) {
                delete edge;
                edge = nullptr;
            }
        }


		Vertex* mkStartVertex(const string& name);
		Vertex* getStartVertex();

		Vertex* mkEndVertex(const string& name);
		const std::list<Vertex*>& getEndVertices() const;

		const std::list<Vertex*>& getVertices() const;
		Vertex* mkVertex(const string& name);
		Vertex* getVertexByName(const string& name);
		Vertex* getParent();

		const std::list<Edge*>& getEdges() const;
		Edge* mkEdge(Vertex* source, Vertex* target);
	private:
    	std::list<Vertex*> vertices_;    //< the set of the states of this fsm.
    	std::list<Edge*> edges_;         //< the set of the transitions of this fsm.
        std::unordered_map<string, Vertex*> vertexMap;
    	Vertex* startVertex_;            //< record the start state of this fsm.
		list<Vertex*> endVertices_;
        Vertex* parent_;
    	Process* proc_;               //< the StateMachine belongs to the process.
	};
}
#endif /* Model_StateMachine_hpp */
