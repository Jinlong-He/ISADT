#include "Model/StateMachine/StateMachine.hpp"
#include <iostream>
namespace isadt{
	void StateMachine::mkStartVertex(const string& name) {
		Vertex* vertex = mkVertex(name);
		startVertex_ = vertex;
	}

	Vertex* StateMachine::getStartVertex() {
		return startVertex_;
	}

	Vertex* StateMachine::getVertex(const string& name) {
        if (vertexMap.count(name) > 0) return vertexMap[name];
        return nullptr;
	}

	const std::list<Vertex*>& StateMachine::getVertices() const {
		return vertices_;
	}
	const std::list<Edge*>& StateMachine::getEdges() const {
		return edges_;
	}
	
	Vertex* StateMachine::mkVertex(const string& name) {
		Vertex* vertex = new Vertex(name);
        vertices_.push_back(vertex);
        vertexMap[name] = vertex;
        return vertex;
	}

	Edge* StateMachine::mkEdge(Edge* edge) {
		edges_.push_front(edge);
	}

}
