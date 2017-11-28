#include "ci_calls.h"

using namespace std;

CICall::CICall()
{
	regexParen = "\\((.*)\\)";
	regParen = regex(regexParen);
}

void CICall::Search(string str)
{
	string call;
	if (regex_search(str, sm, regCI))
        {
            call = sm[1];
        }
    string appendYes = "yes | ";
	if (regex_search(call, smParen, regParen))
    {
        string fullCommand;
        if (smParen[1].str().size() != 0)
        {
            fullCommand = smParen[1].str();
            if (str.find("_PROMPT") != string::npos)
            {
                fullCommand = appendYes + smParen[1].str();
            }
                commands.push_back(fullCommand);
        }
    }
}

string CICall::GetIdentifier()
{
    return identifier;
}

vector<string> CICall::GetCommands()
{
	return commands;
}

UnixCall::UnixCall()
{
    regexCI = "\\s*(CI_RUN_UNIX(_PROMPT)?\\(.*\\))";
    regCI = regex(regexCI);
    identifier = "unix";
}

UbuntuCall::UbuntuCall()
{
	regexCI = "\\s*(CI_RUN_UBUNTU(_PROMPT)?\\(.*\\))";
	regCI = regex(regexCI);
    identifier = "ubuntu";
}

MacOSCall::MacOSCall()
{
	regexCI = "\\s*(CI_RUN_MACOS(_PROMPT)?\\(.*\\))";
	regCI = regex(regexCI);
    identifier = "macos";
}