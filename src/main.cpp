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
    Manage::timerType_ -> mkMethod("reset");
    Manage::timerType_ -> mkMethod("time");
    ArgumentParser program("isadt");
    program.add_argument("-i", "--input")
        .required()
        .nargs(1)
        .help("the input file of model");
    program.add_argument("-o", "--output")
        .nargs(1)
        .default_value(vector<string>({"~/Desktop/generated"}))
        .help("the output dir for code generator");
    program.add_argument("-v", "--verify")
        .help("verify the properties of a given model")
        .default_value(false)
        .implicit_value(true);
    program.add_argument("-g", "--generate")
        .help("generate the codes of a given model")
        .default_value(false)
        .implicit_value(true);
    program.add_argument("-r", "--run")
        .help("generate and run the codes of a given model")
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
    program.add_argument("-w", "--win")
        .help("generate (and run) on windows")
        .default_value(false)
        .implicit_value(true);    
    program.add_argument("-lin", "--linux")
        .help("generate (and run) on linux")
        .default_value(false)
        .implicit_value(true);    
    program.add_argument("--c")
        .help("generate C code")
        .default_value(false)
        .implicit_value(true);    
    program.add_argument("--cpp")
        .help("generate c++ code")
        .default_value(false)
        .implicit_value(true);    
    program.add_argument("--java")
        .help("generate java code")
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
    try {
        Model model;
        XmlParser::parse(file.c_str(), &model);
        if (program["-v"] == true) {
            if (program["-engine=proverif"] == true) {
            } else if (program["-engine=beagle"] == true) {
                //this is an example for make a statemahine for beagle.
                auto proc = model.getProcesses().front();
                auto sm = proc -> getStateMachines().front();
                auto bsm = proc -> mkBeagleStateMachine(sm);
                bsm -> print();
            } else {
                //this is an example for make a statemahine for beagle.
                model.mkCommProductStateMahine();
            }
        }
        if (program["-g"] == true) {
            cout << "-g" << endl;
            if (program["-engine=simulation"] == true) {
                cout << "simulation" << endl;
            } else if (program["-engine=real"] == true) {
                cout << "real" << endl;
            } else {
                if (program["-w"] == true)
                {
                    if (program["--c"] == true)
                    {
                        /* generate code, windows, C code */
                        cout << "generate code, windows, C code" << endl;
                    }else if (program["--cpp"] == true)
                    {
                        /* generate code, windows, C++ code */
                        cout << "generate code, windows, C++ code" << endl;
                    }else if (program["--java"] == true)
                    {
                        /* generate code, windows, java code */
                        cout << "generate code, windows, java code" << endl;
                    }
                }else if (program["-lin"] == true)
                {
                    if (program["--c"] == true)
                    {
                        /* generate code, linux, C code */
                        cout << "generate code, linux, C code " << endl;
                    }else if (program["--cpp"] == true)
                    {
                        /* generate code, linux, C++ code */
                        cout << "generate code, linux, C++ code" << endl;
                    }else if (program["--java"] == true)
                    {
                        /* generate code, linux, java code */
                        cout << "generate code, linux, java code" << endl;
                    } 
                    
                }
                //auto path = program.get<vector<string>>("-o")[0];
                // std::string path = "/home/hejl/Desktop/generated";
                // CCodeGenerator gen = CCodeGenerator();
                // gen.generateAll(path, &model);
            }
        }else if (program["-r"] == true) {
            cout << "-r" << endl;
            if (program["-engine=simulation"] == true) {
                cout << "simulation" << endl;
            } else if (program["-engine=real"] == true) {
                cout << "real" << endl;
            } else {
                if (program["-w"] == true)
                {
                    if (program["--c"] == true)
                    {
                        /* generate and run code, windows, C code */
                        cout << "generate and run code, windows, C code" << endl;
                    }else if (program["--cpp"] == true)
                    {
                        /* generate and run code, windows, C++ code */
                        cout << "generate and run code, windows, C++ code" << endl;
                    }else if (program["--java"] == true)
                    {
                        /* generate and run code, windows, java code */
                        cout << "generate and run code, windows, java code" << endl;
                    }
                } else if (program["-lin"] == true)
                {
                    if (program["--c"] == true)
                    {
                        /* generate and run code, linux, C code */
                        cout << "generate and run code, linux, C code" << endl;
                    }else if (program["--cpp"] == true)
                    {
                        /* generate and run code, linux, C++ code */
                        cout << "generate and run code, linux, C++ code" << endl;
                    }else if (program["--java"] == true)
                    {
                        /* generate and run code, linux, java code */
                        cout << "generate and run code, linux, java code" << endl;
                    } 
                    
                } else {
                    auto path = program.get<vector<string>>("-o")[0];
                    std::string path = "/home/hejl/Desktop/generated";
                    CCodeGenerator gen = CCodeGenerator();
                    gen.generateAll(path, &model);
                }
              
            }
        }
    } catch (const string& e) {
        cout << e << endl;
        exit(1);
    } catch (const char* e) {
        cout << e << endl;
        exit(1);
    }
}
