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
            : proc_(nullptr),
              startVertex_(nullptr) {}

		StateMachine(Process* proc)
            : proc_(proc),
              startVertex_(nullptr) {}

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


		void mkStartVertex(const string& name);
		Vertex* getStartVertex();

		void mkEndVertex(const string& name);
		const std::list<Vertex*>& getEndVertices() const;

		const std::list<Vertex*>& getVertices() const;
		Vertex* mkVertex(const string& name);
		Vertex* getVertexByName(const string& name);

		const std::list<Edge*>& getEdges() const;
		Edge* mkEdge(Edge* edge);
	private:
    	std::list<Vertex*> vertices_;    //< the set of the states of this fsm.
    	std::list<Edge*> edges_;         //< the set of the transitions of this fsm.
        std::unordered_map<string, Vertex*> vertexMap;
    	Vertex* startVertex_;            //< record the start state of this fsm.
		list<Vertex*> endVertices_;
    	Process* proc_;               //< the StateMachine belongs to the process.
	};
}
#endif /* Model_StateMachine_hpp */
