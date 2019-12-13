#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: ** 
//=====================================================

// ** MYTOKEN DFA to be replaced by the WORD DFA
// ** Done by:
// ** RE:
bool mytoken(string s)
{
  int state = 0;
  int charpos = 0;

  while (s[charpos] != '\0') 
    {
      if (state == 0 && s[charpos] == 'a')
      state = 1;
      else
      if (state == 1 && s[charpos] == 'b')
      state = 2;
      else
      if (state == 2 && s[charpos] == 'b')
      state = 2;
      else
	  return(false);
      charpos++;
    }//end of while

  // where did I end up????
  if (state == 2) return(true);  // end in a final state
   else return(false);
}

// ** Add the PERIOD DFA here
// ** Done by:


// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, etc.
enum tokentype {ERROR, };

// ** string tokenName[30] = { }; for the display names of tokens


// ** Need the reservedwords table to be set up here. English will be
// ** used in Part C but it should be stored now.
// ** Do not require any file input for this.
// ** a.out should work without any additional files.

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// ** Done by: 
int scanner(tokentype& a, string& w)
{

  // ** Grab the next word from the file via fin

  /* 
  2. Call the token functions one after another (if-then-else)
     And generate a lexical error message if both DFAs failed.
     Let the token_type be ERROR in that case.
  3. Make sure WORDs are checked against the reservedwords list
     If not reserved, token_type is WORD1 or WORD2.
  4. Return the token type & string  (pass by reference)
  */

}//the end



// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS except to stop the loop when eofm is seen
// Done by:  Rika
int main()
{
  tokentype thetype;
  string theword; 
  string filename;


  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

   while (true)
    {
      scanner(thetype, theword);  // call the scanner

       cout << "Type is:" << tokenName[thetype] << endl;
       cout << "Word is:" << theword << endl;   

    }

  fin.close();

}// end



