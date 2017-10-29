#include "ci_calls.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Pass in clean .md file" << endl;
        return -1;
	}

    UbuntuCall ubuntuCaller;
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

    

    for (auto entry: fileList)
    {
    	ubuntuCaller.Search(entry);
    }
    vector<string> results = ubuntuCaller.GetCommands();

    for (auto result: results)
    	cout << result << endl;


	return 0;
}
