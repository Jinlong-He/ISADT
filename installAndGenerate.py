import os
import sys
xmlPath = sys.argv[1]
os.system("sudo apt-get install git")
os.system("sudo apt-get install g++")
os.system("sudo apt-get install libpcap-dev")
os.system("sudo apt-get install libboost-dev libboost-all-dev")
os.system("sudo apt-get install openssl libssl-dev")

#os.system("rm -rf ~/Desktop/generated")\
os.system("mkdir ~/Desktop/generated")
os.system("mkdir ~/Desktop/generated/CommLib")
os.system("mkdir ~/Desktop/generated/CryptoLib")
os.system("git clone https://github.com/SpencerL-Y/CryptoLib ~/Desktop/generated/CryptoLib")
os.system("git clone https://github.com/SpencerL-Y/CommLib ~/Desktop/generated/CommLib")
os.system("rm -rf ~/Desktop/generated/generatedSrc")
os.system("rm -rf ~/Desktop/generated/generatedHeader")
os.system("mkdir ~/Desktop/generated/generatedSrc")
os.system("mkdir ~/Desktop/generated/generatedHeader")
os.system("cd build && cmake .. && make && cd bin && ./isadt -i ../../" + xmlPath + " -g")