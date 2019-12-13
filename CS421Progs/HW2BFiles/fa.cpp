#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// CS421 File fa.cpp for HW2B

//-----------------------------------------------------------------
// Your name: **

// ** Change this to fit the HW3C specification - look for **
// ** Must have the same types of tracing couts as mytoken.
// ** Must complete the ** comments with RE
//-----------------------------------------------------------------

// MYTOKEN DFA done by Rika Sensei has a sample
 // This FA is for a b^+
bool mytoken(string s)
{ 
  int state = 0;
  int charpos = 0;

  cout << "Trying the mytoken machine..." << endl;  
 
  while (s[charpos] != '\0') 
    {
      cout << "current state: " << state << endl;
      cout << "character: " << s[charpos] << endl;
 
      if (state == 0 && s[charpos] == 'a')
      state = 1;
      else
      if (state == 1 && s[charpos] == 'b')
      state = 2;
      else
      if (state == 2 && s[charpos] == 'b')
      state = 2;
      else
	{
	  cout << "I am stuck in state " << state << endl;
	  return(false);
	}
      charpos++;
    }//end of while

  // where did I end up????
  if (state == 2) return(true);  // end in a final state
   else return(false);
}


// IDENT DFA 
 // This FA is for **
bool ident_token(string s)
{
  // ** complete this based on mytoken
}


// REAL DFA 
// This FA is for **
bool real_token(string s)
{
  // ** complete this based on mytoken
}


//INT DFA 
// This FA is for **
bool integer_token(string s)
{
  // ** complete this based on mytoken
}


// -----------------------------------------------------

enum tokentype {ERROR, MYTOKEN, IDENT, REAL, INT};
int scanner(tokentype& , string& );  // to be called by main
fstream fin;   // file stream to use

// The test-driver
int main()
{ string fname;
  cout << "Enter the input file name:";
  cin >> fname; 

  fin.open( fname.c_str(), fstream::in);

  string tokens[5] = {"ERROR", "MYTOKEN", "IDENT", "REAL", "INT"};
  tokentype thetype;
  string theword; 

  while (true)  // keep on going 
    {
      scanner(thetype, theword);  // the paramers will be set by Scanner
      if (theword == "EOF") break;

      cout << "Type is:" << tokens[thetype]  << endl;
    }
  
  fin.close();
}// end of main


// sets the_type and w 
int scanner(tokentype& the_type, string& w)
{
  
  // This goes through all machines one by one on the input string w

  cout << ".....Scanner was called..." << endl;

  fin >> w;  // grab next word from fain.txt
  cout << "Word is:" << w << endl;   

  if (mytoken(w))
    { the_type = MYTOKEN; }
  
  // ** add other if-then's here in the right order to go through
  // ** all FAs one by one and set the_type to be IDENT, REAL or INT.

  else //none of the FAs returned TRUE
    { cout << "Lexical Error: The string is not in my language" << endl;
      the_type = ERROR; }

}//the very end of scanner




