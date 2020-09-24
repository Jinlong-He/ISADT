#include "CodeGenerator/CCodeGenerator.hpp"
#define INCLUDE_HEADER "#include <stdio.h>\n#include <thread>\n#include <stdlib.h>\n"
#define SIM_INCLUDE ""
#define REAL_INCLUDE "#include \"../CommLib/NetComm/include/EtherReceiver.hpp\"\n\
#include \"../CommLib/NetComm/include/EtherSender.hpp\"\n\
#include \"../CommLib/NetComm/include/UDPSender.hpp\"\n\
#include \"../CommLib/NetComm/include/UDPReceiver.hpp\"\n"
#define CRYPTO_INCLUDE "#include \"../CryptoLib/include/Cryptor.hpp\""
#define SERIALIZATION_INCLUDE "#include <boost/archive/text_oarchive.hpp>\n\
#include <boost/archive/text_oarchive.hpp>\n\
#include <boost/serialization/vector.hpp>\n\
#include <boost/serialization/map.hpp>\n\\
#include <boost/serialization/string.hpp>\n"
#define CR "\n"
#define TAB "\t"
namespace isadt{
        std::list<Plugin*>  CCodeGenerator::getPlugins()
        {
            return this->plugins;
        }
        // methods for generating header file 
        void  CCodeGenerator::generateHeaderFile(std::string path, Process* proc)
        {
            std::ofstream outHeadFile;
		    //TODO: make sure here
		    std::string tempFileName = proc->getName() + ".h";
		    std::string outStr = "";
		    // if def
		    outStr += generateHeaderIfDef(proc);
		    // generate includes 
		    outStr += this->generateCommonIncludes();
		    outStr += this->generateCommunicationIncludes();
			outStr += this->generateCryptoIncludes();
		    outStr += this->generateDependIncludes(proc);
			std::cout << "generateStateDef" << std::endl;
			outStr += this->generateStateDef(proc);
			std::cout << "generateStateDefOver" << std::endl;

			std::cout << "generate temp stores" << std::endl;
			outStr += this->generateTempStorage(proc);
			std::cout << "generate temp stores end" << std::endl;
		    // generate attrs and methods declaration
		    // attrs
			outStr += this->generateClassPre(proc);
			outStr += "\tprivate:\n";
		    for (Attribute* attr : proc->getOriginalAttributes()) {
		    	outStr += "\t\t" + this->appendAttrDef(outStr, attr);
		    }
			outStr += "\tpublic: \n";
		    // methods
		    for (Method* m : proc->getMethods()) {
		    	outStr += "\t\t" + this->appendMethodDeclaration(outStr, m);
		    }
			for (CommMethod* m : proc->getCommMethods()){
				outStr += "\t\t" + this->appendCommMethodDeclaration(outStr, m);   
			}
			outStr += "\t\tvoid SMLMain" + proc->getName() + "();\n"; 
			outStr += "};\n";
			
			
			std::cout << "genSrcMain" << std::endl;
		    outStr += this->generateMain(proc);
			
			std::cout << "genSrcMainOver" << std::endl;
		    //endif
		    outStr += "#endif\n";
			std::cout << outStr << std::endl;
		    outHeadFile.open(path + "/generatedHeader" + "/" + tempFileName, std::ofstream::out | std::ostream::out);
		    outHeadFile << outStr << std::endl;
		    outHeadFile.close();
        }

		std::string CCodeGenerator::generateClassPre(Process* proc){
			std::string result = "class " + proc->getName() + " {" + CR;
			result += "\tprivate: \n";
			return result;
		}

        std::string  CCodeGenerator::generateCommonIncludes()
        {
            std::string commonIncludes =
			"#include <iostream>\n#include <string>\n#include <vector>\n#include <stdlib.h>\n#include <thread>\n#include <stdlib.h>\n#include <sstream>\n";
		    commonIncludes += INCLUDE_HEADER;
		    commonIncludes += SERIALIZATION_INCLUDE;
			return commonIncludes;
        }

        std::string  CCodeGenerator::generateCommunicationIncludes()
        {
			// for real world we use libcap or libnet for the ethernet comm
			// use linux socket for the udp transmission
            std::string communicationIncludes = SIM_INCLUDE;
			communicationIncludes += REAL_INCLUDE;
		    return communicationIncludes;
        }

		std::string CCodeGenerator::generateCryptoIncludes()
		{
			std::string cryptoIncludes = CRYPTO_INCLUDE;
			return cryptoIncludes;
		}

        std::string  CCodeGenerator::generateDependIncludes(Process* currentProc)
        {
            //TODO: make sure here
            std::string dependHeaders = CR;
            /*
		    std::string dependHeaders = CR;
		    for (Process* p : currentProc->getDependProcs()) {
		    	//TODO: add path for process here
		    	std::string headerPath;
		    	dependHeaders += "#include \"" + headerPath + "\\" + p->getName() + ".h\" \n";
		    }
            */
            dependHeaders += "#include \"../UserType.hpp\" \n";
		    return dependHeaders;
        }

        std::string  CCodeGenerator::appendAttrDef(std::string inStr, Attribute* attr)
        {
            std::string result = "";
		    result += attr->getType()->getName() + " " + attr->getIdentifier() + ";\n";
		    return result;
        }

        std::string CCodeGenerator::appendMethodDeclaration(std::string inStr, Method* method)
        {
			std::cout << "appendMethod Declare" << std::endl;
            std::string result = "";
		    std::string attrStr;
		    int i = 1;
		    for (Attribute* a : method->getAttributes()) 
			{
		    	attrStr += a->getType()->getName() + " " + a->getIdentifier();
		    	if (i < method->getAttributes().size()) 
				{
		    		attrStr += ", ";
		    	}
		    	i++;
		    }
		    result += method->getReturnType()->getName() + " " + method->getName() + "(" + attrStr + ");\n";
			std::cout << "appendMethod Declare End" << std::endl;
		    return result;
        }

		std::string CCodeGenerator::appendCommMethodDeclaration(std::string inStr, CommMethod* method){
			
			std::cout << "appendCommMethod Declare" << std::endl;
			std::string result = "";
		    std::string attrStr;
		    int i = 1;
		    for (Attribute* a : method->getAttributes()) 
			{
				std::cout << "here" << std::endl;
		    	attrStr += a->getType()->getName() + " " + a->getIdentifier();
		    	if (i < method->getAttributes().size()) 
				{
		    		attrStr += ", ";
		    	}
		    	i++;
		    }
		    result +="int " + method->getName() + "(" + attrStr + ");\n";
			
			std::cout << "appendMethod Declare End" << std::endl;
		    return result;
		} 

        std::string CCodeGenerator::generateHeaderIfDef(Process* proc)
        {
            std::string result = "#ifndef " + proc->getName() + "_" + "h" + CR;
		    result += "#define " + proc->getName() + "_" + "h" + CR;
            return result;
        }

        // methods for generating src file
        void  CCodeGenerator::generateSrcFile(std::string path, Process* proc)
        {
            //TODO: imple later
            std::string outStr = "";
		    std::ofstream outSrcFile;
		    std::string tempFileName = proc->getName() + ".cpp";
			std::cout << "genSrcInclude" << std::endl;
		    outStr += this->generateSrcIncludes(proc);
			std::cout << "genSrcInclude Over" << std::endl;
			std::cout << "genSrcMethod" << std::endl;
		    outStr += this->generateSrcMethods(proc);
			
			std::cout << "genSrcMethodOver" << std::endl;
			std::cout << outStr << std::endl;
		    outSrcFile.open(path + "/generatedSrc" + "/" + tempFileName, std::ofstream::out | std::ostream::out);
		    outSrcFile << outStr << std::endl;
		    outSrcFile.close();
        }

        std::string  CCodeGenerator::generateStateDef(Process* proc)
        {
            std::string defs = "";
		    //defs += "#define STATE__START__STATE 0\n";
		    int i = 0;
			int loop_count = 0;
			for(StateMachine* sm : proc->getStateMachines()){
				for (Vertex* v : sm->getVertices()) 
				{
		    		//TODO: refine the state definition later
		    		defs += "#define STATE__" + v->getName() + " " + std::to_string(i) + "\n";
		    		i++;
		   	 	}
				loop_count++;
			}
		    
		    //defs += "#define STATE__STOP__STATE " + std::to_string(i) + "\n";
		    return defs;
        }
        
        std::string CCodeGenerator::generateTempStorage(Process* proc){
			std::string outStr = "";
			outStr += "static pcap_t* dev" + proc->getName() + ";\n";
			outStr += "static char* tempData" + proc->getName() + "\n;";
			return outStr;
		}

		std::string  CCodeGenerator::generateSrcIncludes(Process* proc)
		{
			//TODO: add path latter
			std::string headerPath;
			std::string srcIncludeStr = "#include \"../generatedHeader/" + proc->getName() + ".h\"\n";
			return srcIncludeStr;
		}

        std::string  CCodeGenerator::generateSrcMethods(Process* proc)
		{		
			std::string outStr = "";
			/*code generation for base methods*/
			std::cout << "generate Methods" << std::endl;
			for (Method* m : proc->getMethods())
			{
				if(!m->getAlgorithmId().compare(""))
				{
					std::string rttStr =  m->getReturnType()->getName();
					std::string classNamespace = proc->getName() + "::";
					std::string methodName = m->getName();
					std::string attrStr = "(";
					int i = 1;
					for (Attribute* a : m->getAttributes()) 
					{
						std::string termStr = a->getType()->getName() + " " + a->getIdentifier();
						attrStr += termStr;
						if (i < m->getAttributes().size()) 
						{
							attrStr += ", ";
						}
						i++;
					}
					attrStr += ")";
					std::string methodDef = rttStr + " " + classNamespace + methodName + attrStr;
					std::string returnVal = "\t" + rttStr + " result;" + CR;
					std::string ret = "\treturn result;\n";
					std::string methodBody = "{\n" + returnVal + ret + "\n}\n";
					outStr += (methodDef + methodBody);
				}
			}
			std::cout << "generate Methods Over" << std::endl;
			/*code generation for communication methods*/
			std::cout << "generate Communication Methods" << std::endl;
			for (CommMethod* m : proc->getCommMethods()){
				std::string commStr = "";
				std::string commHandlerStr = "";
				//std::string rttStr = m->getReturnType()->getName();
				if(!m->getCommId().compare("NativeEthernetFrame") && !m->getInOut()){
					//generate the handler
					commHandlerStr += "static void dataHandler" + proc->getName() + m->getName() + "(u_char* param, const struct pcap_pkthdr* header, const u_char* packetData){\n";
					commHandlerStr += "\tether_header* eh;\n";
					commHandlerStr += "\teh = (ether_header*)packetData;\n";
					commHandlerStr += "\t/*Configure your own protocol number of ethernet frame*/\n";
					commHandlerStr += "\tif(ntohs(eh->type) == 0x888f){\n";
					commHandlerStr += "\t\t/*Add your own packet handling logic, tempData is used to store the packet after breaking the listening loop*/\n";
					commHandlerStr += "\t\ttempData" + proc->getName() + " = NULL;\n";
					commHandlerStr += "\t\tint breakingLoopCondition = 0;\n";
					commHandlerStr += "\t\tif(breakingLoopCondition){\n";
					commHandlerStr += "\t\t\tpcap_breakloop(dev" + proc->getName() + ");\n";
					commHandlerStr += "\t\t}\n";
					commHandlerStr += "\t}\n";
					commHandlerStr += "}\n";
				}
				
				std::string rttStr = "int";
				std::string classNamespace = proc->getName() + "::";
				std::string methodName = m->getName();
				std::string attrStr = "(";
				int i = 1;
				for (Attribute* a : m->getAttributes()) 
				{
					std::string termStr = a->getType()->getName() + " " + a->getIdentifier();
					attrStr += termStr;
					if (i < m->getAttributes().size()) 
					{
						attrStr += ", ";
					}
					i++;
				}
				attrStr += ")";
				std::string methodDef = rttStr + " " + classNamespace + methodName + attrStr;
				std::string returnVal = '\t' + rttStr + " result;" + CR;
				std::string ret = "\treturn result;\n";
				
				if(!m->getCommId().compare("NativeEthernetFrame")){
					commStr += "\t/*Configure your own implementation of length_*/\n";
					commStr += "\tint length_ = 0;\n";
					commStr += "\tu_char* data_ = (u_char*)malloc(length_*sizeof(u_char));\n"; 	
					commStr += "\tu_char* dst_;";
					if(!m->getInOut()){
						//IN
						commStr += "\t/*Add MAC Address here*/\n";
						commStr += "\tushort mac[6];\n";
						commStr += "\tEtherReceiver er;\n";
						commStr += "\tpcap_if_t* dev = er.getDevice();\n";
						commStr += "\tchar errbuf[500];\n";
						commStr += "\tpcap_t* selectedAdp = pcap_open_live(dev->name, 65536, 1, 1000, errbuf);\n";
						commStr += "\tdev" + proc->getName() + " = selectedAdp;\n";
						commStr += "\t/*Add self defined dataHandler to handle data received*/\n";
						commStr += "\t/*parameters: u_char* param, const struct pcap_pkthdr* header, const u_char* packetData*/\n";
						commStr += "\ter.listenWithHandler(dev, dataHandler" + proc->getName() + m->getName() +  ", data_);\n";
						commStr += "\t/*Add your own data processing logic here*/\n";
						commStr += "\tfree(data_);\n";
						commStr += "\tint result;\n";
						commStr += "\treturn result;\n";

					} else {
						//OUT
						commStr += "\t/*Add MAC Address here*/\n";
						commStr += "\tushort mac[6];\n";
						commStr += "\tEtherSender snd(mac);\n";
						commStr += "\tsnd.getDevice();\n";
						commStr += "\t/*add your identifier of the sender*/\n";
						commStr += "\tint success =snd.sendEtherBroadcast(data_, length_);\n";
					}
					
				} else if(!m->getCommId().compare("UDP")){
					if(!m->getInOut()){
						commStr += "\t/*Add IP Str and portNUm here*/\n";
						commStr += "\tstd::string IPStr_;\n";
						commStr += "\tu_short portNum_;\n";
						commStr += "\tUDPReceiver  er;\n";
						commStr += "\t/*allocation for dst_ here*/\n";
						commStr += "\tu_char* dst_;\n";
						commStr += "\ter.receivePacket(IPStr_, portNum_);\n";
						commStr += "\tdst_ = er.getDstData();\n";
					} else {
						commStr += "\t/*Add Ip Str and portNum here*/\n";
						commStr += "\tstd::string IPStr_;\n";
						commStr += "\tu_short portNum_;\n";
						commStr += "\tUDPSender snd;\n";
						commStr += "\t/*Add length and data content to send here*/\n";
						commStr += "\tu_char* data_;\n";
						commStr += "\tint length_;\n";
						commStr += "\tsnd.sendPacket(data_, length_, IPStr_, portNum_);\n";
					}
				} else {
					std::cout << "Invalid commway num." << std::endl;
				}

				std::string methodBody = "{\n" + commStr + returnVal + ret + "\n}\n";
				outStr += (commHandlerStr + methodDef + methodBody);
			}
			std::cout << "generate Communication Methods Over" << std::endl;

			std::cout << "generate Crypt Methods" << std::endl;
			for(Method* m : proc->getMethods())
			{
				std::string rttStr =  m->getReturnType()->getName();
				std::string classNamespace = proc->getName() + "::";
				std::string methodName = m->getName();
				std::string attrStr = "(";
				int i = 1;
				for (Attribute* a : m->getAttributes()) 
				{
					std::string termStr = a->getType()->getName() + " " + a->getIdentifier();
					attrStr += termStr;
					if (i < m->getAttributes().size()) 
					{
						attrStr += ", ";
					}
					i++;
				}
				attrStr += ")";
				std::string methodDef = rttStr + " " + classNamespace + methodName + attrStr;
				std::string returnVal = rttStr + " result;" + CR;
				std::string ret = "\treturn result;\n";
				std::string cryptStr = "";
				std::string methodBody = "{\n" + cryptStr + returnVal + ret + "\n}\n";
				if(m->getAlgorithmId().compare(""))
				{
					
					if(!m->getAlgorithmId().compare("AES")){
						if(m->getName().find("Enc") != string::npos){
							Attribute* a = m->getAttributes().front();
							cryptStr += "\tstd::string key;\n";
							cryptStr += "\t/*Add your own serialization logic here*/\n";	
							cryptStr += "\tstd::ostringstream os;\n";
							cryptStr += "\tboost::archive::text_oarchive oa(os);\n";
							cryptStr += "\toa << " + a->getIdentifier() + ";\n";
							cryptStr += "\tstd::string content = os.str();\n";
							cryptStr += "\t/*Configure the mod and the length of the cryptLib*/\n";
							cryptStr += "\tint length = 1000;\n";
							cryptStr += "\tchar* out = (char*)malloc(sizeof(char) * length);\n";
							cryptStr += "\tmemset(out, 0, content.size());\n";
							cryptStr += "\tCryptor cryptor;\n";
							cryptStr += "\tcryptor.aes_encrypt((char*)content.c_str(), key, out)\n";
						} else if(m->getName().find("Dec") != string::npos){
							Attribute* a = m->getAttributes().front();
							cryptStr += "\t/*Add your input data here*/\n";
							cryptStr += "\tstd::string input;\n";
							cryptStr += "\tstd::string key;\n";
							cryptStr += "\tchar* out = (char*)malloc(sizeof(char) * 1000);\n";
							cryptStr += "\tint length = 1000;\n";
							cryptStr += "\tmemset(out, 0, length);\n";
							cryptStr += "\tCryptor cryptor;\n";
							cryptStr += "\tcryptor.aes_decrypt(input.c_str(), key.c_str(), out);\n";
							cryptStr += "\tstd::string content = out;\n";
							cryptStr += "\tstd::istringstream is(content);\n";
							cryptStr += "\tboost::archive::text_iarchive ia(is);\n";
							cryptStr += "\tia >> " + a->getIdentifier() + ";\n";
							cryptStr += "\tfree(out);\n";
						}

					} else if(!m->getAlgorithmId().compare("RSA")){
						if(m->getName().find("Enc") != string::npos){
							Attribute* a = m->getAttributes().front();
							cryptStr += "\tstd::string pubkey;\n";
							cryptStr += "\t/*Add your own serialization logic here*/\n";	
							cryptStr += "\tstd::ostringstream os;\n";
							cryptStr += "\tboost::archive::text_oarchive oa(os);\n";
							cryptStr += "\toa << " + a->getIdentifier() + ";\n";
							cryptStr += "\tstd::string content = os.str();\n";
							cryptStr += "\t/*Configure the mod and the length of the cryptLib*/\n";
							cryptStr += "\tint length = 1000;\n";
							cryptStr += "\tchar* out = (char*)malloc(sizeof(char) * length);\n";
							cryptStr += "\tmemset(out, 0, content.size());\n";
							cryptStr += "\tCryptor cryptor;\n";
							cryptStr += "\tcryptor.rsa_encrypt((char*)content.c_str(), pubkey, out)\n";
						} else if(m->getName().find("Dec") != string::npos){
							Attribute* a = m->getAttributes().front();
							cryptStr += "\t/*Add your input data here*/\n";
							cryptStr += "\tstd::string input;\n";
							cryptStr += "\tstd::string prikey;\n";
							cryptStr += "\tchar* out = (char*)malloc(sizeof(char) * 1000);\n";
							cryptStr += "\tint length = 1000;\n";
							cryptStr += "\tmemset(out, 0, length);\n";
							cryptStr += "\tCryptor cryptor;\n";
							cryptStr += "\tcryptor.rsa_decrypt(input.c_str(), prikey.c_str(), out);\n";
							cryptStr += "\tstd::string content = out;\n";
							cryptStr += "\tstd::istringstream is(content);\n";
							cryptStr += "\tboost::archive::text_iarchive ia(is);\n";
							cryptStr += "\tia >> " + a->getIdentifier() + ";\n";
							cryptStr += "\tfree(out);\n";
						}
					}
					else {
						//TODO later modify here
						cryptStr += "\t/*Add your input data here*/\n";
						cryptStr += "\t/*Configure the mod and the length of the cryptLib*/\n";
						cryptStr += "\tint length_;\n";
						cryptStr += "\tint mod_ = -1;\n";
						cryptStr += "\tchar* in_ = (char*)malloc(sizeof(char)*length);\n";
						cryptStr += "\tchar* out_;\n";
						cryptStr += "\t/*configure the key*/\n";
						cryptStr += "\tchar* key_;\n";
						cryptStr += "\tCryptor crypt = new Cryptor();\n";
						cryptStr += "\tcrypt.crypt(in_, key_, length_, out_, mod_);\n";		
					}			
				}
				outStr += (methodDef + methodBody);
			}
			
			std::cout << "generate Crypt Methods Over" << std::endl;

			std::cout << "generate SML Main loop method" << std::endl;
			outStr += ("void " + proc->getName() + "::SMLMain" + proc->getName() + "(){\n");
			outStr += this->generateSMLoop(proc);
			outStr += "}\n";
			std::cout << "generate SML Main loop method end" << std::endl;
			return outStr;
		}

        std::string CCodeGenerator::generateMain(Process* proc)
		{
			std::string outStr = "";
			// current state 
			outStr += "static int __currentState = STATE__" + proc->getStateMachines().front()->getStartVertex()->getName()+ ";\n";
			
			outStr += "int main(int argc, char** argv) {\n";
			outStr += "\t" + this->generateInstObject(proc);
			outStr += ("\tobj.SMLMain" + proc->getName() + "();\n");
			outStr += "}\n";
			return outStr;
		}

		std::string CCodeGenerator::generateInstObject(Process* proc){
			std::string outStr = "";
			outStr += proc->getName() + " obj;\n";
			outStr += "/*Initialize the object by user*/\n";
			return outStr;
		}

        //std::string  CCodeGenerator::generateGuardVarsDef(Process* proc);
        std::string  CCodeGenerator::generateSMLoop(Process* proc)
		{
			std::string outStr = "";
			std::cout << "generateSMLoopMain" << std::endl;
			outStr += "\twhile(__currentState != -100) {\n";
			outStr += "\t\tswitch(__currentState){\n";
			//make sure that start state is included
			//TODO
			outStr += this->generateStateBehavior((StateMachine *)proc->getStateMachines().front());
			outStr += "\t\t\tdefault: break;\n";
			outStr += "\t\t}\n";
			outStr += "\t}\n";
			std::cout << "generateSMLoopMain Over" << std::endl;
			
			std::cout << "generateSMLoopOther" << std::endl;
			std::cout << "SM size: " << proc->getStateMachines().size() << std::endl;
			if(proc->getStateMachines().size() > 1){
				int stateMachineId = 1;
				std::list<StateMachine*> sms = proc->getStateMachines();
				for(std::list<StateMachine*>::iterator it = (++sms.begin()); it != sms.end(); ++it){
					std::string stateMachineFunctionStr = "void stateMachine" + std::to_string(stateMachineId) + "Behavior(){\n";
					stateMachineFunctionStr += "int __sm" + std::to_string(stateMachineId) + "State = " + "STATE__"+(*it)->getStartVertex()->getName() + ";\n";
					stateMachineFunctionStr += "while(__sm" + std::to_string(stateMachineId) + "State != " + (*it)->getEndVertex()->getName() + "){\n";
					stateMachineFunctionStr += "\tswitch(__sm" + std::to_string(stateMachineId) + "State){\n";
					std::cout << "HERE"<< stateMachineId << std::endl;
					stateMachineFunctionStr += this->generateStateBehavior((*it));
					std::cout << "HERE" << std::endl;
					stateMachineFunctionStr += "\t}\n";
					stateMachineFunctionStr += "\t\tdefault: break;\n";
					stateMachineFunctionStr += "\t}\n";
					stateMachineFunctionStr += "}\n";
					outStr += stateMachineFunctionStr + "\n";
					stateMachineId ++;
				}
			}
			std::cout << "generateSMLoopOther Over" << std::endl;
			return outStr;
		}

		std::string CCodeGenerator::generateStateBehavior(StateMachine* sm)
		{
			std::string casesBody;
			std::string caseTab = "\t\t\t";
			std::string caseBodyTab = "\t\t\t\t";
			
			std::cout << "GenStateBehave" << std::endl;
			for(Vertex* v : sm->getVertices()){
				
				std::cout << "vertex " + v->getName() << std::endl;
				casesBody += (caseTab + "case STATE__" + v->getName() + ":") + CR;
				casesBody += (caseBodyTab + "std::cout << \"--------------------STATE__" + v->getName() + "\" << std::endl;\n");
				bool elseIf = false;
				for(Edge* e : sm->getEdges()){
					std::cout << "edge loop" << std::endl;
					if(!e->getFromVertex()->getName().compare(v->getName())){
						// if the edge starts from v
						// makesure Make sure guard to string method
						std::cout << e->getFromVertex()->getName() << v->getName() << std::endl;
						
						std::cout << "caseBody"<< std::endl;
						if(e->getGuard() != nullptr){
							std::cout << "generate If branch: " << e->getGuard()->to_string() << std::endl;
							casesBody += (caseBodyTab + (elseIf ? "else if(" : "if(") + e->getGuard()->to_string() + "){") + CR;
							for(Action* a : e->getActions()){
								if(!a->hasNext()){
									casesBody += TAB + (caseBodyTab + a->to_string() + ";") + CR;
								}
							}
							casesBody += ("\t\t\t\t__currentState = STATE__" + e->getToVertex()->getName()) + ";\n";
							std::cout << "generate If branch end" << std::endl;
							casesBody += (caseBodyTab + "}") + CR;
							
							elseIf = true;
						} else {
							casesBody += (caseBodyTab + (elseIf ? "else {"  : "") + CR);
							for(Action* a : e->getActions()){
								casesBody += TAB + (caseBodyTab + a->to_string() + ";") + CR;
							}
							casesBody += ("\t\t\t\t__currentState = STATE__" + e->getToVertex()->getName()) + ";\n";
							casesBody += (caseBodyTab + (elseIf ? "}"  : "") + CR);
						}
					}
					
					std::cout << "edge loop end" << std::endl;
				}
				casesBody += "\t\t\t\tbreak;\n";
			}
			std::cout << "GenStateBehave Over" << std::endl;
			return casesBody;
		}

        /*-------------Generate UserTypes-------------*/
		void CCodeGenerator::generateUserTypes(std::string path, Model* model)
		{
			std::ofstream outUserTypeFile;
		    //TODO: make sure here
		    std::string fileName = "UserType.hpp";
		    std::string outStr = "";
			std::cout << "generate Usertype" << std::endl;
			outStr += this->generateCommonIncludes();
			for(UserType* u : model->getUserTypes())
			{
				//make sure 
				if(u->getBase()){
					outStr += ("class " + u->getName() + " : " + u->getBase()->getName() + "{") + CR;
				} else {
					outStr += ("class " + u->getName() + "{") + CR;
				}
				outStr += "\tprivate:\n";
				for(Attribute* a : u->getAttributes())
				{
					outStr += "\t\t" + (a->getType()->getName() + " " + a->getIdentifier()) + ";\n";
				}
				outStr += "\tpublic:\n";
				for(Method* m : u->getMethods()){
					outStr += "\t\t" + (m->getReturnType()->getName() + " " + m->getName() + "(");
					int i = 1;
					if(m->getAttributes().size() > 0){
						for(Attribute* a : m->getAttributes()){
							if(i < m->getAttributes().size()){	
								outStr += a->getType()->getName() + " " + a->getIdentifier() + ", ";
							} else {
								outStr += a->getType()->getName() + " " + a->getIdentifier() + "){\n";
							}
						}
					} else {
						outStr += "){\n";
					}
					
					outStr += "\t\t\t" + m->getReturnType()->getName() + " " + "result;\n";
					outStr += "\t\t\treturn result;\n"; 
					outStr += "\t\t}\n";
				}
				outStr += "};\n";
				std::cout << outStr << std::endl;
				outStr += this->generateSerializeBinding(model);
			}
			std::cout << "end usertypes" << std::endl;
			outUserTypeFile.open(path  + "/" + fileName, std::ofstream::out | std::ostream::out);
			outUserTypeFile << outStr << std::endl;
			outUserTypeFile.close();
		}

		std::string CCodeGenerator::generateSerializeBinding(Model* model){
			std::string outStr = "namespace boost{\n";
			outStr += "\tnamespace serialization{\n";
			
			for(UserType* ut : model->getUserTypes()){
				outStr += "\t\ttemplate<class Archive>\n";
				outStr += "\t\tvoid serialize(Archive & ar, " + ut->getName() + " & d, const unsigned int version){\n";
				for(Attribute* a : ut->getAttributes()){
					outStr += "\t\t\tar& d." + a->getIdentifier() + ";\n";
				}
				outStr += "\t\t}\n";
			}
			outStr += "\t}\n";
			outStr += "}\n";
			return outStr;
		}

		/*---------Generate Compile Auxiliary--------*/
		void CCodeGenerator::generateCompileFile(std::string path, Model* model)
		{
			std::ofstream outCompileFile;
			std::cout << "generate compile auxiliary" << std::endl;
			std::string outStr = "import os\n";
			outStr += "import sys\n";
			outStr += "os.system(\"g++ -g -c CommLib/NetComm/src/*.cpp\")\n";
			outStr += "os.system(\"ar cqs libnetcomm.a ./*.o\")";
			outStr += "os.system(\"mv *.o CommLib/NetComm/src/\")\n";
			outStr += "os.system(\"mv *.a CommLib/NetComm/src/\")\n";
			outStr += "os.system(\"g++ -g -c CryptoLib/src/*.cpp\")\n";
			outStr += "os.system(\"ar cqs libcryptorlib.a ./*.o\"\n)";
			outStr += "os.system(\"mv *.o CryptoLib/src/\")\n";
			outStr += "os.system(\"mv *.a CryptoLib/src/\")\n";
			for(Process* proc : model->getProcesses())
			{
				outStr += "os.system(\"g++ -g -o " + proc->getName() + " ./generatedSrc/" + proc->getName() +  
				".cpp -L./CommLib/NetComm/src/ -lnetcomm -L./CryptoLib/src/ -lcryptorlib -lssl -lcrypto -lpcap -lboost_serialization\")";
			}
			outCompileFile.open(path  + "/compile.py", std::ofstream::out | std::ostream::out);
			outCompileFile << outStr << std::endl;
			std::cout << outStr << std::endl;
			outCompileFile.close();
		}

		/*---------Gen---------*/
        void  CCodeGenerator::generateCodeProc(std::string path, Process* proc)
		{
			this->generateHeaderFile(path, proc);
			this->generateSrcFile(path, proc);
		}

        void CCodeGenerator::generateAll(std::string path, Model* model)
		{
			this->generateUserTypes(path, model);
			for(Process* proc : model->getProcesses())
			{
				this->generateCodeProc(path, proc);
			}
			this->generateCompileFile(path, model);
		}


        //constructors
         CCodeGenerator::CCodeGenerator(/*args*/)
         {

         }

         CCodeGenerator::~CCodeGenerator()
         {

         }
    
}