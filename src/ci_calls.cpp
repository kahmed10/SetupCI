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
	if (regex_search(call, smParen, regParen))
    {
        if (smParen[1].str().size() != 0)
            commands.push_back(smParen[1]);
    }
}

vector<string> CICall::GetCommands()
{
	return commands;
}

UbuntuCall::UbuntuCall()
{
	regexCI = "\\s*(CI_RUN_UBUNTU\\(.*\\))";
	regCI = regex(regexCI);

}

MacOSCall::MacOSCall()
{
	regexCI = "\\s*(CI_RUN_MACOS\\(.*\\))";
	regCI = regex(regexCI);
}