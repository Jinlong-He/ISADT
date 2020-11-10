import os
import sys

#os.system("rm -rf ~/Desktop/generated")

xmlPath = "../backxml/backxml2.xml"
os.system("rm -rf ../generated/generatedSrc")
os.system("rm -rf ../generated/generatedHeader")
os.system("rm ../generated/UserType.hpp")
os.system("rm ../generated/UserType.")
os.system("mkdir ../generated/generatedSrc")
os.system("mkdir ../generated/generatedHeader")
os.system("cd build/bin && ./isadt -i ../../" + xmlPath + " -g " + sys.argv[1])
os.system("cd ../generated/ && python3 compile.py")

# not general, used for demonstration
os.system("gnome-terminal -e 'bash -c \"echo PROCESS BOB------ && sudo ../generated/Bob; exec bash\"'")

os.system("gnome-terminal -e 'bash -c \"echo PROCESS ALICE------ && sudo ../generated/Alice; exec bash\"'")
