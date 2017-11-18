#pragma once

#include <regex>
#include <vector>

using namespace std;

class CICall
{
public:
	CICall();
    void Search(string str);
    string GetIdentifier();
    vector<string> GetCommands();
protected:
	string regexCI;
	string regexParen;
    string identifier;
    regex regCI, regParen;
    smatch sm, smParen;
    vector<string> commands;
};

class UnixCall : public CICall
{
public:
    UnixCall();
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
