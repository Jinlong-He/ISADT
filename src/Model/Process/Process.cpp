#include "Model/Process/Process.hpp"
#include <iostream>
using std::cout, std::endl;
namespace isadt{
    Model* Process::getModel() const{
        return model_;
    }
    void Process::setModel(Model* model){
        model_ = model;
    }

    StateMachine* Process::mkStateMachine(Vertex* parent) {
        StateMachine* sm = new StateMachine(parent, this);
        stateMachines_.push_back(sm);
        return sm;
    }

    CommMethod* Process::mkCommMethod(const string& name, 
                                      UserType* returnType,
                                      bool inout, 
                                      const string& commId) {
        CommMethod* method = new CommMethod(name, returnType, inout, commId);
        commMethods_.push_back(method);
        commMethodMap[name] = method;
        return method;
    }

    Attribute* Process::mkNewAttribute(UserType* type, const string& name) {
        string id = name;
        while (this -> attributeMap_.count(id) > 0) {
            id += "_";
        }
        return mkAttribute(type, id);
    }

    CommMethod* Process::mkCommMethod(const string& name) {
        return mkCommMethod(name, nullptr, 0, "");
    }

    CommMethod* Process::getCommMethodByName(const string& name) {
        if (commMethodMap.count(name) == 0) return nullptr;
        return commMethodMap[name];
    }

    bool Process::hasCommMethod(const string& name) {
        return commMethodMap.count(name);
    }
    
    const list<CommMethod*>& Process::getCommMethods() const{
        return commMethods_;
    }

    StateMachine* Process::getStateMachine() const {
        return stateMachine_;
    }

    const list<StateMachine*> Process::getStateMachines() const {
        return stateMachines_;
    }

    void Process::addVertex(Vertex* vertex) {
        vertexMap[vertex -> getName()] = vertex;
    }

    Vertex* Process::getVertexByName(const string& name) {
        if (vertexMap.count(name) == 0) return nullptr;
        return vertexMap[name];
    }

    bool isBeagleAvailable(StateMachine* sm) {
        for (auto e : sm -> getEdges()) {
            if (!(e -> getGuard() -> getExpression() -> isBeagleAvailable())) return false;
        }
        return true;
    }

    Term* Process::cpBeagleTerm(Term* term, Edge* edge1, Edge* edge2) {
        if (term == nullptr) return nullptr;
        auto termType = term -> getTermType();
        switch (termType) {
            case EXP: {
                if (Manage::isArOp(((Expression*) term) -> getOp())) {
                    auto type = ((Expression*) term) -> getType();
                    string id = edge2 -> getFromVertex() -> getName() + "_id";
                    auto attr = mkNewAttribute(type, id);
                    auto resTerm = edge2 -> mkAttributeTerm(attr);
                    edge1 -> mkAssignmentAction(resTerm, term);
                    return resTerm;
                } else {
                    auto term1 = cpBeagleTerm(((Expression*) term) -> getTerm1(), edge1, edge2);
                    auto term2 = cpBeagleTerm(((Expression*) term) -> getTerm2(), edge1, edge2);
                    return edge2 -> mkExpression(((Expression*) term) -> getOp(), term1, term2);
                }
            } case AT: {
                return edge1 -> mkAttributeTerm(((AttributeTerm*) term) -> getAttribute());
            } case CT: {
                auto type = ((ConstTerm*) term) -> getType();
                auto value = ((ConstTerm*) term) -> getValueStr();
                return edge2 -> mkConstTerm(type, value);
            } default : {
                return nullptr;
            }
        }
    }

    StateMachine* Process::mkBeagleStateMachine(StateMachine* sm) {
        if (!isBeagleAvailable(sm)) return nullptr;
        StateMachine* res = mkStateMachine();
        unordered_map<Vertex*, Vertex*> vertex2Map;
        for (const auto edge : sm -> getEdges()) {
            if (edge -> getGuard() -> getExpression() -> isAtomic()) {
                res -> cpEdge(edge, vertex2Map);
            } else {
                auto source = res -> cpVertex(edge -> getFromVertex(), vertex2Map);
                auto target = res -> cpVertex(edge -> getToVertex(), vertex2Map);
                auto mid = res -> mkMidVertex(source, target);
                auto edge1 = res -> mkEdge(source, mid);
                auto edge2 = res -> mkEdge(mid, target);
                auto exp = (Expression*) cpBeagleTerm(edge -> getGuard() -> getExpression(), edge1, edge2);
                edge2 -> mkGuard(exp);
            }
        }
        return res;
    }
}
        
