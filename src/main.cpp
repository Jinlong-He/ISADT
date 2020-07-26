#include <iostream>
#include <list>
#include "../include/Model/Model.hpp"
#include "../include/Parser/XmlParser/XmlParser.hpp"
#include "../include/Parser/LParser/LParser.hpp"
#include "../include/CodeGenerator/CCodeGenerator.hpp"
using namespace std;
using namespace isadt;

int main(int argc, char *argv[]) {
    try {
        Model model;
        XmlParser::parse(argv[1], &model);
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
        CCodeGenerator* codegen = new CCodeGenerator();
        //codegen->generateCodeProc("/home/clexma/Desktop/generated", p);
        codegen->generateCodeProc("/home/clexma/Desktop/generated", model.getProcesses().front());
    } catch (string e) {
        cout << e << endl;
        exit(1);
    }
}
