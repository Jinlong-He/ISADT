//
//  Edge.hpp
//
//  Created by Jinlong He on 2019/11/14.
//  Copyright © 2019 All rights reserved.
//

#ifndef Model_Edge_hpp
#define Model_Edge_hpp
#include <list>
#include "Vertex.hpp"
#include "Guard/Guard.hpp"
#include "Action/Action.hpp"
using std::list;

namespace isadt {
	/// \brief transition in the StateMachine 
	class Edge {
    public:
    	/// \brief Edge constructor 
        Edge() 
            : from_(nullptr),
              to_(nullptr),
              guard_(nullptr) {}

    	Edge(Vertex* from, Vertex* to)
            : from_(from),
              to_(to),
              guard_(nullptr) {}

    	Edge(Vertex* from, Vertex* to, 
             Guard* guard, 
             const std::initializer_list<Action*>& actions)
            : from_(from),
              to_(to),
              guard_(guard),
              actions_(actions) {}

    	Edge(Vertex* from, Vertex* to, 
             const string& guardStr, 
             const std::initializer_list<string>& actionStrs);

    	Vertex* getFromVertex();
    	void SetFromVertex(Vertex* from);

    	Vertex* getToVertex();
    	void SetToVertex(Vertex* to);

    	Guard* getGuard();
    	void setGuard(Guard* guard);
    	Guard* mkGuard(const string& guardStr);

    	const list<Action*>& getActions();
    	Action* getActionByIndex(int index);

    	Action* mkAction(const string& actionStr);
    	void addAction(Action* action);

    	bool hasNonDeterministicGuard();
    	bool isEmpty();
    	bool hasActions();
    	void removeAllActions();
    	void removeFirstAction();
	private:
    	Vertex* from_;               //< from Vertex
    	Vertex* to_;                 //< to Vertex
    	Guard* guard_;               //< transtion guard
        string guardStr_;
    	list<Action*> actions_;      //< actions on the transition
        list<string> actionStrs_;
	};
}


#endif /* Model_Edge_hpp */
