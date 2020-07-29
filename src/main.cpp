#include <iostream>
#include <list>
#include "../include/Model/Model.hpp"
#include "../include/Parser/XmlParser/XmlParser.hpp"
#include "../include/Parser/LParser/LParser.hpp"
#include "../include/CodeGenerator/CCodeGenerator.hpp"
#include "../include/Manage.hpp"
#include "../include/Parser/ArgParser/argparse.hpp"
using namespace std;
using namespace isadt;
using namespace argparse;

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
        ArgumentParser program("isadt");
        program.add_argument("-i", "--input")
            .required()
            .nargs(1)
            .help("the input file of model");
        program.add_argument("-v", "--verify")
            .help("verify the properties of a given model")
            .default_value(false)
            .implicit_value(true);
        program.add_argument("-g", "--generate")
            .help("generate the codes of a given model")
            .default_value(false)
            .implicit_value(true);
        program.add_argument("-engine=beagle")
            .help("set the engine for verifier")
            .default_value(false)
            .implicit_value(true);
        program.add_argument("-engine=proverif")
            .help("set the proverif engine for verifier")
            .default_value(false)
            .implicit_value(true);
        program.add_argument("-engine=simulation")
            .help("set the simulation engine for generator")
            .default_value(false)
            .implicit_value(true);
        program.add_argument("-engine=real")
            .help("set the real engine for generator")
            .default_value(false)
            .implicit_value(true);
        try {
            program.parse_args(argc, argv);
        } catch (const std::runtime_error& err) {
          std::cout << err.what() << std::endl;
          std::cout << program;
          exit(0);
        }
        auto file = program.get<vector<string>>("-i")[0];
        Model model;
        XmlParser::parse(file.c_str(), &model);
        if (program["-v"] == true) {
            cout << "-v" << endl;
            if (program["-engine=proverif"] == true) {
            } else if (program["-engine=beagle"] == true) {
                //this is an example for make a statemahine for beagle.
                auto proc = model.getProcesses().front();
                auto sm = proc -> getStateMachines().front();
                auto bsm = proc -> mkBeagleStateMachine(sm);
                bsm -> print();
            } else {
                //this is an example for make a statemahine for beagle.
                auto proc = model.getProcesses().front();
                auto sm = proc -> getStateMachines().front();
                auto bsm = proc -> mkBeagleStateMachine(sm);
                bsm -> print();
            }
        }
        if (program["-g"] == true) {
            cout << "-g" << endl;
            if (program["-engine=simulation"] == true) {
                cout << "simulation" << endl;
            } else if (program["-engine=real"] == true) {
                cout << "real" << endl;
            } else {
                cout << "simulation" << endl;
            }
        }
    } catch (string e) {
        cout << e << endl;
        exit(1);
    }
}
