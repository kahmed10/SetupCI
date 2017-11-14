#include "ci_calls.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <unordered_set>
#include <vector>


using namespace std;

static const string osSupported[] =
{
    "unix",
    "ubuntu",
    "macos"
    };

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
    else
        cout << argc << endl;
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
   
    ifstream inFile(argv[1]);

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
        cout << "Error: Unable to open file: " << argv[1] << endl;
        return -1;
    }

    vector<CICall*> callers;

    // build command files based on supported OS
    for (int i = 2; i < argc; i++)
    {
        cout << argv[i] << endl;
        CICall* caller = NULL;
        if (!strncmp(argv[i],"unix",5))
            caller = new UnixCall();
        else if (!strncmp(argv[i],"ubuntu",7))
            caller = new UbuntuCall();
        else if (!strncmp(argv[i],"macos",6))
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
        for (auto result: results)
            cout << result << endl;
        cout << "***" << endl;
    }
    

    // CLEANUP
    for (auto caller : callers)
    {
        delete caller;
    }

	return 0;
}
