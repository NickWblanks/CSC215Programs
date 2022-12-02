#define CATCH_CONFIG_RUNNER
#include "thpe04.h"


int main(int argc, char** argv)
{
    if (RUNCATCH) //catch test 
    {
        Catch::Session session;
        int returnCode;
        returnCode = session.run(argc, argv);
        if (returnCode != 0)
            cout << "A Test case failed" << endl;
        return 0;
    }
    int seed1, seed2;
    bool check;
    card deck1[52];
    int checkCmd = CmdCheck(argc, argv[1]);
    if (checkCmd == 0)
    {
        usageStatement();
        return 0;
    }
    if (strcmp(argv[1], "-s") == 0)
    {
        seed1 = stoi(argv[2]);
        seed2 = stoi(argv[3]);
    }
    chooseRun(argv[1], seed1, seed2, argv[2], argv[3]);
    return 0;
}