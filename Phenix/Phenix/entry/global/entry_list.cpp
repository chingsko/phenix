#include "PrecompiledHeader.hpp"
#include "phenix/entry/Entry.hpp"

// list current directory's entries
FNX_AddGlobalEntry("ls")
{
    autox current = Manager.GetCurrent();
    autox entries = current->GetChidren();

    cout << yellow << "included objects:" << endl;
    for (autox entry : entries)
    {
        cout << ((entry->GetType() == EntryType::Item) ? green : cyan)
            << "    " << entry->GetName()
            << endl;
    }
    cout << reset;
};