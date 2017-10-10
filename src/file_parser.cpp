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
    //    return -1;
	}

    UbuntuCall ubuntuCaller;

    // currently testing if CIs can be parsed correctly
    string tests[2] = {"CI_RUN_UBUNTU(ls)","CI_RUN_UBUNTU()"};

    for (auto test: tests)
    {
    	ubuntuCaller.Search(test);
    }
    vector<string> results = ubuntuCaller.GetCommands();

    for (auto result: results)
    	cout << result << endl;


	return 0;
}
