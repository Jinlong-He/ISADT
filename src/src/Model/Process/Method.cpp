#include "Model/Process/Method.hpp"
namespace isadt {
    //const string& Method::getName() const{
    //    return this->name_;
    //}
    //void Method::setName(const string& name){
    //    this->name_ = name;
    //}

    //Type* Method::getReturnType() const{
    //    return this->returnType_;
    //}
    //void Method::setReturnType(Type* returnType){
    //    this->returnType_ = returnType;
    //}

    //const list<Attribute*>& Method::getParameters() const{
    //    return this->parameters_;
    //}
    //void Method::setParameters(const list<Attribute*>& parameters){
    //    this->parameters_ = parameters;
    //}

    const string& Method::getAlgorithmId() const{
        return algorithmId_;
    }
    void Method::setAlgorithmId(const string& algorithmId){
        algorithmId_ = algorithmId;
    }

    const string& Method::getUserCode() const{
        return userCode_;
    }
    void Method::setUserCode(const string& userCode){
        userCode_ = userCode;
    }
}
