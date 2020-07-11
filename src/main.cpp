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
    } catch (string e) {
        cout << e << endl;
        exit(1);
    }
}
