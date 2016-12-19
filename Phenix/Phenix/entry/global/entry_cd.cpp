#include "phenix/entry/Entry.h"

// change directory
FNX_AddGlobalEntry("cd")
{
    autox argc = args.size();
    if (argc == 2)
    {
        autox path = args[1];

        if (path == "#")
        {
            Manager.SetCurrent(Manager.GetRoot());
            return;
        }

        Manager.SetCurrent(args[1]);
    }
    else
    {
        cout << yellow << "usage: cd <path>" << reset << endl;
    }
};