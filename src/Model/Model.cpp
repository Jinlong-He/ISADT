#include "Model/Model.hpp"
#include <iostream>
namespace isadt{
    Model::Model(){

    }
    Model::~Model() {
            //delete processes, properties, initialknowledges.
    }

    Process* Model::mkProcess(){
        Process* p = new Process(this);
        this->processes_.push_front(p);
        return p;
    }
    Process* Model::mkProcess(std::string procName){
        for(Process* p : this->processes_){
            if(!procName.compare(p->getProcName())){
                std::cout << "Process Exists" << std::endl;
                return NULL;
            }
        }
        Process* p = new Process(this);
        p->setProcName(procName);
        this->processes_.push_front(p);
        return p;
    }

    ConfidentialProperty*
    Model::mkConfidentialProperty(Process* process, Attribute* attribute){
        
    }
    AuthenticityProperty* 
    Model::mkAuthenticityProperty(Process* process1, Vertex* vertex1, Attribute* attribute1,
                           Process* process2, Vertex* vertex2, Attribute* attribute2){

                           }
    InitialKnowledge* 
    Model::mkInitialKnowledge(Process* process, Attribute* attribute){

    }
    
    const list<Process*>& Model::getProcesses() const{
        return this->processes_;
    }
    list<UserType*> Model::getUserTypes(){
        return this->userTypes_;
    }
}