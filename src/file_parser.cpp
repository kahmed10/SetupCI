#include "ci_calls.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <stdlib.h>
#include <unordered_set>
#include <vector>

#define MD_CLEAN_OFF 9 // supporting MD files for now

using namespace std;

static const string intFilePath = "/int/commands/";

static const string osSupported[] =
{
    "unix",
    "ubuntu",
    "macos"
    };


// used to get the final app name after removing other directories
string getLastItem(string s)
{
    int pos = s.find('/');
    while (pos != string::npos)
    {
        pos = s.find('/');
        s.erase(0,pos + 1); // plus 1 for delimiter
    }
    return s;
}


int main(int argc, char* argv[])
{
	if (argc < 3)
	{
        cout << "Error: Insufficient Arguments" << endl;
        cout << "Usage: ./file_parser [clean_md_file] [OS1 (OS2) ...]" << endl;
        cout << "Currently supported operating systems:" << endl;
        cout << "unix ubuntu macos" << endl;
        return -1;
	}

    // Create list of supported OS;
    unordered_set<string> osList;
    for (auto os : osSupported)
    {
        osList.insert(os);
    }

    for (int i = 2; i < argc; i++)
    {
        if (osList.find(argv[i]) == osList.end())
        {
            cout << "Error, incorrect OS parameter" << endl;
            return -1;
        }
    }

    string line;
    vector<string> fileList;
   
    string cleanFile(argv[1]);
    ifstream inFile(cleanFile);

    // get the original file name
    string origFile = getLastItem(cleanFile);
    origFile = origFile.erase(origFile.size()-MD_CLEAN_OFF, origFile.size() - 1);



    auto setupCIPath = getenv ("SETUP_CI");
    // if (setupCIPath != NULL)
    //     cout << "setupCIPath = " << setupCIPath << endl;
    if (setupCIPath == NULL)
    {
        cout << "Error: path not set up correctly. Run ./install.sh" << endl;
        return -1;
    }

    if (inFile.is_open())
    {
        while(getline(inFile,line))
        {
            fileList.push_back(line);
        }
        inFile.close();
    }

    else
    {
        cout << "Error: Unable to open file: " << cleanFile << endl;
        return -1;
    }

    vector<CICall*> callers;

    // build command files based on supported OS
    for (int i = 2; i < argc; i++)
    {
        CICall* caller = NULL;
        if (argv[i] == "unix")
            caller = new UnixCall();
        else if (argv[i] == "ubuntu")
            caller = new UbuntuCall();
        else if (argv[i] == "macos")
            caller = new MacOSCall();
        callers.push_back(caller);
    }

    // go through each API call in file
    vector<string> results;


    for (auto caller : callers)
    {
        for (auto entry: fileList)
        {
            caller->Search(entry);            
        }
        results = caller->GetCommands();

        if (results.size() != 0)
        {
            string outName = setupCIPath + intFilePath + origFile + 
                "_" + caller->GetIdentifier() + "_commands.txt";
            cout << outName << endl;
            ofstream outFile;
            outFile.open(outName);

            if (outFile.is_open())
            {
                for (auto result: results)
                {
                    //cout << result << endl; DEBUGGING
                    outFile << result << endl;
                }
            }
            else
                cout << "Error in opening output file" << endl;
            outFile.close();
        }
        
            
    }
    

    // CLEANUP
    for (auto caller : callers)
    {
        delete caller;
    }

	return 0;
}
