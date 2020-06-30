#include "Model/StateMachine/StateMachine.hpp"
#include <iostream>
namespace isadt{
	Vertex* StateMachine::mkStartVertex(const string& name) {
		Vertex* vertex = mkVertex(name);
		startVertex_ = vertex;
        return vertex;
	}

	Vertex* StateMachine::getStartVertex() {
		return startVertex_;
	}

	Vertex* StateMachine::getParent() {
		return parent_;
	}

	Vertex* StateMachine::getVertexByName(const string& name) {
        if (vertexMap.count(name) == 0) return mkVertex(name);
        return vertexMap[name];
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

	Edge* StateMachine::mkEdge(Vertex* source, Vertex* target) {
        Edge* edge = new Edge(source, target);
		edges_.push_front(edge);
        return edge;
	}

}
