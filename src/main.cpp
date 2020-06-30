#include <iostream>
#include <list>
#include "../include/Model/Model.hpp"
#include "../include/Parser/XmlParser/XmlParser.hpp"
#include "../include/Parser/LParser/LParser.hpp"
#include "../include/CodeGenerator/CCodeGenerator.hpp"
using namespace std;
using namespace isadt;

int main(int argc, char *argv[]) {
    Model model;
    //vector<string> text;
    //LParser::parse(text, &model);
    XmlParser::parse(argv[1], &model);
}
