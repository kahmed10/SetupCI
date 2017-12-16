#include "ci_calls.h"

using namespace std;

CICall::CICall()
{
	regexParen = "\\((.*)\\)";
	regParen = regex(regexParen);
}

string CICall::Search(string str)
{
	string call, fullCommand;
	if (regex_search(str, sm, regCI))
        {
            call = sm[1];
        }
    else
        return "";

    // append prompts to commands if necessary
    string appendYes = "yes | ";
    string appendNo = "yes N | ";
	if (regex_search(call, smParen, regParen))
    {
        if (smParen[1].str().size() != 0)
        {
            fullCommand = smParen[1].str();
            if (str.find("_PROMPT") != string::npos)
            {
                if (str.find("_NO") != string::npos)
                    fullCommand = appendNo + smParen[1].str();
                else
                    fullCommand = appendYes + smParen[1].str();
            }
                commands.push_back(fullCommand);
        }
    }
    else
        return "";
    return fullCommand;
}

void CICall::AddCommand(string str)
{
    commands.push_back(str);
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
    regexCI = "\\s*(CI_RUN_UNIX(_PROMPT(_NO)?)?\\(.*\\))";
    regCI = regex(regexCI);
    identifier = "unix";
}

UbuntuCall::UbuntuCall()
{
	regexCI = "\\s*(CI_RUN_UBUNTU(_PROMPT(_NO)?)?\\(.*\\))";
	regCI = regex(regexCI);
    identifier = "ubuntu";
}

MacOSCall::MacOSCall()
{
	regexCI = "\\s*(CI_RUN_MACOS(_PROMPT(_NO)?)?\\(.*\\))";
	regCI = regex(regexCI);
    identifier = "macos";
}