#pragma once

#include <regex>
#include <vector>

using namespace std;

class CICall
{
public:
	CICall();
    void Search(string str);
    vector<string> GetCommands();
protected:
	string regexCI;
	string regexParen;
    regex regCI, regParen;
    smatch sm, smParen;
    vector<string> commands;
};


class UbuntuCall : public CICall
{
public:
    UbuntuCall();
};

class MacOSCall : public CICall
{
public:
	MacOSCall();	
};
