#include "Model/Process/Method.hpp"

namespace isadt {
    Method::Method()
            : returnType_(nullptr) {}

    Method::Method(const string& name, 
               Type* returnType, 
               const list<Attribute*>& parameters,
               const string& algorithmId,
               const string& userCode)
            : name_(name),
              returnType_(returnType),
              parameters_(parameters),
              algorithmId_(algorithmId),
              userCode_(userCode) {}

    Method::~Method() {
            for (auto p : parameters_) {
                delete p;
            }
        }

        const string& Method::getName() const{
            return this->name_;
        }
        void Method::setName(const string& name){
            this->name_ = name;
        }

        Type* Method::getReturnType() const{
            return this->returnType_;
        }
        void Method::setReturnType(Type* returnType){
            this->returnType_ = returnType;
        }

        const list<Attribute*>& Method::getParameters() const{
            return this->parameters_;
        }
        void Method::setParameters(const list<Attribute*>& parameters){
            this->parameters_ = parameters;
        }

        const string& Method::getAlgorithmId() const{
            return this->algorithmId_;
        }
        void Method::setAlgorithmId(const string& algorithmId){
            this->algorithmId_ = algorithmId;
        }

        const string& Method::getUserCode() const{
            return this->userCode_;
        }
        void Method::setUserCode(const string& userCode){
            this->userCode_ = userCode;
        }

        const string& Method::getName(){
            return this->name_;
        }
}