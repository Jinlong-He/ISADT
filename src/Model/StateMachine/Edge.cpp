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

    AssignmentAction* Edge::mkAssignmentAction(AttributeTerm* lhs, Term* rhs) {
        AssignmentAction* action = new AssignmentAction(lhs, rhs);
        actions_.push_back(action);
        return action;
    }

    DeclarationAction* Edge::mkDeclarationAction(Attribute* attr, const string& value) {
        DeclarationAction* action = new DeclarationAction(attr, value);
        actions_.push_back(action);
        return action;
    }

    MethodAction* Edge::mkMethodAction(MethodTerm* methodTerm) {
        MethodAction* action = new MethodAction(methodTerm);
        actions_.push_back(action);
        return action;
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
