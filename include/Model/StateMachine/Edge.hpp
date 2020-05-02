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
    	Edge(Vertex* from, 
             Vertex* to, 
             Guard* guard, 
             const list<Action*>& actions)
            : from_(from),
              to_(to),
              guard_(guard),
              actions_(actions) {}

    	Guard* getGuard() {
    		return guard_;
    	}
    	void setGuard(Guard* guard);
    	void setGuard(string guard);

    	Vertex* getFromVertex() {
            return from_;
        }
    	void SetFromVertex(Vertex* from);

    	Vertex* getToVertex() {
            return to_;
        }
    	void SetToVertex(Vertex* to);

    	const list<Action*>& getActions() {
            return actions_;
        }
    	Action* getActionByIndex(int index);

    	void addAction(string _action);
    	void addAction(Action* _action);

    	bool hasNonDeterministicGuard();

    	bool isEmpty();

    	bool hasActions();

    	void removeAllActions();

    	void removeFirstAction();
	private:
    	Vertex* from_;               //< from Vertex
    	Vertex* to_;                 //< to Vertex
    	Guard* guard_;               //< transtion guard
    	list<Action*> actions_;      //< actions on the transition
	};
}


#endif /* Model_Edge_hpp */
