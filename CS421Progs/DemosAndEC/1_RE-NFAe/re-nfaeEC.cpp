#include <iostream>
#include <fstream>
#include <vector>

constexpr std::string LINE_BREAK = "================================";
constexpr int NFA_SIZE = 10;

// Each transition 
struct transition
{
    int start;    // start state
    char arrow;   // what to see in an arrow
    int end;      // next state
};

std::ostream & operator << (std::ostream & out, const transition& t)
{
    out << t.start
        << "--"
        << t.arrow
        << "--"
        << t.end;
}

std::vector<transition> NFA[NFA_SIZE];  // each NFA machine is a vector of transitions
std::string NFA_LABELS[NFA_SIZE];
int counter, currentInitial, currentFinal;

// ------------- Put utility functions here --------------------


void processConcat()
{ 
    std::string label;
    std::vector<transition> result;
    int M1, M2;
    std::cout << "Enter number of the first machine: "; 
    std::cin >> M1; 
    std::cout << "Enter number of the second machine: "; 
    std::cin >> M2; 
    
    if (M1 == M2) 
    { 
        std::cout << "copying the machine first ...." << std::endl;
        // copy the machine and display it

    }

    // create trasition from M1's end to M2's start
    // add the new machine to NFA
    NFA[counter] = result;
    counter++;
} 

void processOr()
{ 
    int M1, M2;
    std::cout << "Enter number of the first machine: "; 
    std::cin >> M1; 
    std::cout << "Enter number of the second machine: "; 
    std::cin >> M2; 
    
    while (M1 == M2) 
    {
        // must be a different one from M1
        std::cout << "Enter different number for the second machine: ";  
        std::cin >> M2;
    }

    // create new start 
    
    // create new final
    // For the new machine in NFA:
    // add transition from new start to M1 start
    // add transition from new start to M2 start
    // add M1 and M2 
    // add transition from M1 end to new final
    // add transition from M2 end to new final
} 


void processStar()
{ 
    int M1;
    std::cout << "Enter number of the machine: "; std::cin >> M1; 

    // create new start 
    // create new final
    // For the new machine in NFA:
    // add transition from new start to M1 start
    // add M1 
    // add transition (back) from M1 end to M1 start
    // add transition from M1 end to new final
    // add transition (skip) from new to new final

} 

void processPlus()
{ 
    int M1;
    std::cout << "Enter number of the machine: "; 
    std::cin >> M1;
    // create new start

    // create new final
    
    // For the new machine in NFA:
    
    // add transition from new start to M1 start
    
    // add M1 
    
    // add transition (back) from M1 end to M1 start
    
    // add transition from M1 end to new final

} 


int main()
{
    std::cout << "This program will transform regular expressions into NFA-e" << std::endl;
    std::cout << "But it is done interactively by asking you to apply operators" << std::endl;
    std::cout << "to component machines." << std::endl;

    std::ifstream fin ("re.txt", std::ios::in);  // components  come from re.txt

    char c;
    transition s;

    counter = 0;
    currentInitial = 0;
    currentFinal = 1;

    while (fin >> c)
    { 
        std::string label;
        std::vector<transition> nfa;
        // build a transition for arrow label c
        s.start = currentInitial;
        s.arrow = c;
        s.end = currentFinal;
        nfa.push_back(s);
        // display the transition
        std::cout << s;
        // add it to NFA
        NFA_LABELS[counter] = label;
        NFA[counter++] = nfa;
    }
    fin.close();
    // finished creating component machines


    char A;  // user choice
    while (A != 'n' && counter < 10)
    {
        std::cout << "---- MENU -----" 
                  << std::endl
                  << "* for a machine" 
                  << std::endl
                  << "+ for a machine" 
                  << std::endl
                  << "| for two machines" 
                  << std::endl
                  << "- for appending two machines" 
                  << std::endl
                  << "n to quit" 
                  << std::endl;

        std::cin >> A;

        if (A == '*')
        {
            processStar();
        }
        else if (A == '+')
        { 
            processPlus();
        }
        else if (A == '|')
        {
            processOr();
        }
        else if (A == '-')
        { 
            processConcat();
        }
        else
        {
            std::cerr << "Uncrecognized option: "
                      << A
                      << std::endl;
        }
        
    }
    std::cout << "Outputting all machines to nfa-e.txt... " << std::endl;
    //std::ofstream fout ("nfa-e.txt", std::ios::out);
    // send all NFA contents to the output file
    for(int i = 0; i < NFA_SIZE; i++)
    {
        int initial_state;
        int final_state;
        for(const transition& t : NFA[i])
        {
            std::cout << t;
        }
        std::cout << std::endl
                  << "Initial="
                  << initial_state
                  << std::endl
                  << "Final="
                  << final_state
                  << std::endl;
    }
} 
