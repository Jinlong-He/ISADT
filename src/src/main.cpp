#include <iostream>
#include <list>
#include "../include/Model/Type/Type.hpp"
#include "../include/Model/Model.hpp"
#include "../include/Parser/XmlParser/XmlParser.hpp"
#include "../include/CodeGenerator/CCodeGenerator.hpp"
using namespace std;
using namespace isadt;

int main(int argc, char *argv[]) {
    XmlParser parser;
    Model model;
    parser.parse(argv[2], &model);
}
