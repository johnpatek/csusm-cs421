#include<iostream>
#include<string>

// CS421 HW1 Write a recognizer in C++ for L = {x | x is a binary number}.

// Your name: John Patek

//  The recognizer function should return TRUE or FALSE 
//  checking each character
//  to make sure it is 0 or 1. (leading 0's are allowed).
bool recognizer(const std::string& s)
{
    bool result(false);
    if(s.size() > 0)
    {
        std::string::const_iterator string_iterator = s.begin();
        result = *string_iterator == '1';
        
        if(s.size() > 1)
        {
            string_iterator = std::next(string_iterator);
            while(result && string_iterator != s.end())
            {
                result = *string_iterator == '0' || *string_iterator == '1';
                string_iterator = std::next(string_iterator);
            }
        }
    }
    return result;
}

//main: Given a string (from E) cined from the user, pass it to
//      the recognizer function.
//      Cout YES IN L or NO NOT IN L depending on what was returned.
int main(const int argc, const char ** argv)
{
    std::string message("NO NOT IN L");
    std::string input;
    std::cerr << "Enter a string: ";
    std::cin >> input;
    if(recognizer(input))
    {
        message = "YES IN L";
    }
    std::cerr << message << std::endl;
    return 0;
}
