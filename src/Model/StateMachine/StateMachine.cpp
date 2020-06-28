#include "Model/StateMachine/StateMachine.hpp"
#include <iostream>
namespace isadt{
    StateMachine::StateMachine(){

    }
	StateMachine::StateMachine(Process* p)
	{
		this->process_ = p;
	}
	StateMachine::~StateMachine()
	{
        
	}
	void StateMachine::mkStartVertex(std::string name)
	{
		if(this->startVertex_ != nullptr){
			std::cout << "startVertex exist" << std::endl;
			return;
		}
		for(Vertex * v : this->getVertices()){
			if(!v->getName().compare(name)){
				std::cout << "vertex name exists" << std::endl;
				return;
			}
		}
		Vertex * vertex = new Vertex(name);
		this->startVertex_ = vertex;
		this->vertices_.push_front(vertex);
	}
	Vertex* StateMachine::getVertexByName(std::string name)
	{
		for(Vertex* v : this->vertices_)
		{
			if(!v->getName().compare("name")){
				return v;
			}
		}
	}
	const Vertex* StateMachine::getStartVertex()
	{
		return this->startVertex_;
	}
	const std::list<Vertex *>& StateMachine::getVertices() const
	{
		return this->vertices_;
	}
	const std::list<Edge*>& StateMachine::getEdges() const
	{
		return this->edges_;
	}
	void StateMachine::addVertex(std::string name)
	{
		for(Vertex * v : this->getVertices()){
			if(!v->getName().compare(name)){
				std::cout << "vertex name exists" << std::endl;
				return;
			}
		}
		// check name for repeatness
		// if not add to the list
		Vertex* vertex = new Vertex(name);
		this->vertices_.push_front(vertex);
	}
	void StateMachine::delVertex(std::string name)
	{
		for(Vertex * v : this->getVertices()){
			if(!v->getName().compare(name)){
				this->vertices_.remove(v);
				return;
			}
		}
	}
	void StateMachine::addEdge(Edge* edge)
	{
		this->edges_.push_front(edge);
	}

}