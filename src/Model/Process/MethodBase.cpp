#include "Model/Process/MethodBase.hpp"
namespace isadt {
    const string& MethodBase::getName() const{
        return name_;
    }

    void MethodBase::setName(const string& name){
        name_ = name;
    }

    Type* MethodBase::getReturnType() const{
        return returnType_;
    }

    void MethodBase::setReturnType(Type* returnType){
        returnType_ = returnType;
    }

    const list<Attribute*>& MethodBase::getParameters() const{
        return parameters_;
    }

    void MethodBase::addParameter(Attribute* attr) {
        parameters_.push_back(attr);
    }
    
}
