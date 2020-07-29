#include <iostream>
#include <list>
#include "../include/Model/Model.hpp"
#include "../include/Parser/XmlParser/XmlParser.hpp"
#include "../include/Parser/LParser/LParser.hpp"
#include "../include/CodeGenerator/CCodeGenerator.hpp"
#include "../include/Manage.hpp"
using namespace std;
using namespace isadt;

unordered_set<string> Manage::eqOps_({"==", "!=", ">", ">=", "<", "<="});
unordered_set<string> Manage::arOps_({"+", "-", "*", "/"});
UserType* Manage::intType_(new UserType("int"));
UserType* Manage::boolType_(new UserType("bool"));
UserType* Manage::numberType_(new UserType("number"));
UserType* Manage::byteType_(new UserType("byte"));
UserType* Manage::byteVecType_(new UserType("ByteVec"));
UserType* Manage::timerType_(new UserType("Timer"));
unordered_map<string, UserType*> Manage::typeMap_({{"int", Manage::intType_},
                                                   {"bool", Manage::boolType_},
                                                   {"number", Manage::numberType_},
                                                   {"byte", Manage::byteType_},
                                                   {"ByteVet", Manage::byteVecType_},
                                                   {"Timer", Manage::timerType_}});

int main(int argc, char *argv[]) {
    try {
        Model model;
        XmlParser::parse(argv[1], &model);
        auto proc = model.getProcesses().front();
        auto sm = proc -> getStateMachines().front();
        sm -> print();
        cout << endl;
        auto sm1 = proc -> mkBeagleStateMachine(sm);
        sm1 -> print();
        //Process* p = model.mkProcess("TestProc");
        //UserType* type = new UserType();
        //type->setName("Integer");
        //p->mkAttribute(type, "myInt");
        //p->mkMethod("testMethod", type, "", "/*Here is the user code*/\n");
        //p->mkMethod("cryptMethod", type, "1", "");
        //p->mkCommMethod("commMethod", type, true, "id1");
        //StateMachine* sm = p->mkStateMachine(new Vertex("INIT"));
        //Vertex* first = sm->mkVertex("FIRST");
        //Vertex* second = sm->mkVertex("SECOND");
        //Vertex* end = sm->mkEndVertex("END");
        //sm->mkEdge(first, second)->addAction(new Action());
        //sm->mkEdge(second, end)->addAction(new Action());
        //CCodeGenerator* codegen = new CCodeGenerator();
        //codegen->generateCodeProc("/Users/hejl/Projects/ISADT/generated", model.getProcesses().front());
    } catch (string e) {
        cout << e << endl;
        exit(1);
    }
}
