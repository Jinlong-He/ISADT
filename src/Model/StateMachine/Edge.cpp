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

    Guard* Edge::mkGuard(Expression* exp) {
        guard_ = new Guard(exp);
        return guard_;
    }
    
    Guard* Edge::getGuard() {
        return guard_;
    }

    AssignmentAction* Edge::mkAssignmentAction(Term* lhs, Term* rhs) {
        AssignmentAction* action = new AssignmentAction(lhs, rhs);
        actions_.push_back(action);
        return action;
    }

    DeclarationAction* Edge::mkDeclarationAction(Attribute* attr) {
        DeclarationAction* action = new DeclarationAction(attr);
        actions_.push_back(action);
        return action;
    }

    //MethodAction* Edge::mkMethodAction(MethodTerm* methodTerm) {
    //    MethodAction* action = new MethodAction(methodTerm);
    //    actions_.push_back(action);
    //    return action;
    //}

    AttributeTerm* Edge::mkAttributeTerm(Attribute* attr) {
        AttributeTerm* term = new AttributeTerm(attr);
        terms_.push_back(term);
        return term;
    }

    MethodTerm* Edge::mkMethodTerm(MethodBase* method) {
        MethodTerm* term = new MethodTerm(method);
        terms_.push_back(term);
        return term;
    }

    ConstTerm* Edge::mkConstTerm(const string& type, const string& value) {
        ConstTerm* term = new ConstTerm(type, value);
        terms_.push_back(term);
        return term;
    }

    ListTerm* Edge::mkListTerm() {
        ListTerm* term = new ListTerm();
        terms_.push_back(term);
        return term;
    }

    Expression* Edge::mkExpression(const string& op, Term* term1, Term* term2) {
        Expression* exp = new Expression(op, term1, term2);
        exps_.push_back(exp);
        return exp;
    }

    void Edge::addAction(Action* action) {
        actions_.push_back(action);
    }

    const list<Action*>& Edge::getActions() {
        return actions_;
    }

    Action* Edge::getActionByIndex(int index) {
    }

    string Edge::to_string() const {
        string res = "Guard: ";
        if (guard_) res += guard_ -> getExpression() -> to_string() + "\n";
        res += "Actions: \n";
        for (auto action : actions_) {
            res += action -> to_string() + "\n";
        }
        return res;
    }
}
