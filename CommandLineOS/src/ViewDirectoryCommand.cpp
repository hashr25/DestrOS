#include "ViewDirectoryCommand.h"

ViewDirectoryCommand::ViewDirectoryCommand()
{
    setAlias("vdir");
    setDesc("Displays files and subdirectories");
    setHelp("Using no argument will give you the information on current directory.\nFollowing this command with a directory will list the files in that directory");
}


void ViewDirectoryCommand::execute(std::string arg)
{
    // Modified version of methods explained at www.dreamincode.net
    DIR* directory = NULL;

    if(arg == "")
    {
        directory = opendir (".");
    }
    else
    {
        directory = opendir(arg.c_str());
    }

    struct dirent* directoryItem = NULL;



    if (directory == NULL)
    {
        std::cout << "Error: Could not initialize directory";
        return;
    }


    std::cout << "Files contained in that directory:" << std::endl;
    while ( (directoryItem = readdir (directory)) )
    {
        if (directoryItem == NULL)
        {
            std::cout << "Error: File or Directory not loaded correctly";
        }

        std::cout << directoryItem->d_name << std::endl;
    }

    closedir(directory);
}
