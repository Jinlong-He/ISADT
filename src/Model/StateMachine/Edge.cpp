#include "Model/StateMachine/Edge.hpp"
namespace isadt {
    Vertex* Edge::getFromVertex() {
        return from_;
    }
    void Edge::SetFromVertex(Vertex* from) {
        from_ = from;
    }

    Vertex* Edge::getToVertex() {
        return to_;
    }
    void Edge::SetToVertex(Vertex* to) {
        to_ = to;
    }

    void Edge::setGuard(Guard* guard) {
        guard_ = guard;
    }

    Guard* Edge::mkGuard(const string& guardStr) {
        guardStr_ = guardStr;
    }
    Guard* Edge::getGuard() {
        return guard_;
    }

    Action* Edge::mkAction(const string& actionStr) {
        actionStrs_.push_back(actionStr);
    }
    void Edge::addAction(Action* action) {
        actions_.push_back(action);
    }
    const list<Action*>& Edge::getActions() {
        return actions_;
    }
    Action* Edge::getActionByIndex(int index) {
    }
}
