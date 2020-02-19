#include<iostream>
#include<fstream>
#include<string>

// CS421 File fa.cpp for HW2B

//-----------------------------------------------------------------
// Your name: John Patek

// ** Change this to fit the HW3C specification - look for **
// ** Must have the same types of tracing couts as mytoken.
// ** Must complete the ** comments with RE
//-----------------------------------------------------------------

// MYTOKEN DFA done by Rika Sensei has a sample
 // This FA is for a b^+
bool mytoken(const std::string s)
{ 
    int state = 0;
    int charpos = 0;

    std::cout << "Trying the mytoken machine..." << std::endl;  

    while (s[charpos] != '\0') 
    {
        std::cout << "current state: " << state << std::endl;
        std::cout << "character: " << s[charpos] << std::endl;

        if (state == 0 && s[charpos] == 'a')
        {
            state = 1;
        }
        else if (state == 1 && s[charpos] == 'b')
        {
            state = 2;
        }
        else if (state == 2 && s[charpos] == 'b')
        {
            state = 2;
        }
        else
        {
            std::cout << "I am stuck in state " << state << std::endl;
            return(false);
        }
        charpos++;
    }//end of while

    // where did I end up????
    if (state == 2) 
    {
        return(true);  // end in a final state
    }
    else
    { 
        return(false);
    }
}


// IDENT DFA 
 // This FA is for **
bool ident_token(const std::string & s)
{
    bool result(false);
    std::string::const_iterator string_iterator;
    if(s.size() > 0)
    {
        string_iterator = s.begin();
        result = (*string_iterator >= 'a' 
               && *string_iterator <= 'z')
               || (*string_iterator >= 'A' 
               && *string_iterator <= 'Z')
               || *string_iterator == '_';
        string_iterator++;
        while(result && string_iterator != s.end())
        {
            result = (*string_iterator >= '0' 
                   && *string_iterator <= '9')
                   || (*string_iterator >= 'a' 
                   && *string_iterator <= 'z')
                   || (*string_iterator >= 'A' 
                   && *string_iterator <= 'Z')
                   || *string_iterator == '_';
            string_iterator++;
        }
    }
    return result;
}


// REAL DFA 
// This FA is for **
bool real_token(const std::string & s)
{
    bool result(false);
    std::string::const_iterator string_iterator;
    if(s.size() > 0 && s.find('.') != std::string::npos)
    {
        if(s.find_first_of('.') == s.find_last_of('.'))
        {
            string_iterator = s.begin();
            result = (*string_iterator >= '0' 
                && *string_iterator <= '9');
            string_iterator++;
            while(result && string_iterator != s.end())
            {
                result = (*string_iterator >= '0' 
                    && *string_iterator <= '9')
                    || (*string_iterator == '.' 
                    && string_iterator + 1 != s.end());
                string_iterator++;
            }
        }
    }
    return result;
}


//INT DFA 
// This FA is for **
bool integer_token(const std::string & s)
{
    bool result(false);
    std::string::const_iterator string_iterator;
    if(s.size() > 0)
    {
        string_iterator = s.begin();
        result = (*string_iterator >= '0' 
               && *string_iterator <= '9');
        string_iterator++;
        while(result && string_iterator != s.end())
        {
            result = (*string_iterator >= '0' 
                   && *string_iterator <= '9');
            string_iterator++;
        }
    }
    return result;
}


// -----------------------------------------------------

enum tokentype {ERROR, MYTOKEN, IDENT, REAL, INT};
void scanner(tokentype& , std::string& );  // to be called by main
std::fstream fin;   // file stream to use

// The test-driver
int main()
{ 
    std::string fname;
    std::cout << "Enter the input file name:";
    std::cin >> fname; 

    fin.open( fname.c_str(), std::fstream::in);

    std::string tokens[5] = {"ERROR", "MYTOKEN", "IDENT", "REAL", "INT"};
    tokentype thetype;
    std::string theword; 
    bool loop(true);
    while(loop)
    {
        scanner(thetype, theword);  // the paramers will be set by Scanner
        if (theword == "EOF")
        {
            loop = false;
        }
        else
        {
            std::cout << "Type is:" << tokens[thetype]  << std::endl;
        }
    }
    fin.close();
}// end of main


// sets the_type and w 
void scanner(tokentype& the_type, std::string& w)
{

    // This goes through all machines one by one on the input string w

    std::cout << ".....Scanner was called..." << std::endl;

    fin >> w;  // grab next word from fain.txt
    std::cout << "Word is:" << w << std::endl;   

    if (mytoken(w))
    { 
        the_type = MYTOKEN; 
    }
    else if(ident_token(w))
    {
        the_type = IDENT;
    }
    else if(real_token(w))
    {
        the_type = REAL;
    }
    else if(integer_token(w))
    {
        the_type = INT;
    }
    else //none of the FAs returned TRUE
    { 
        std::cout << "Lexical Error: The string is not in my language" << std::endl;
        the_type = ERROR; 
    }

}//the very end of scanner




