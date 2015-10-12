#ifndef VIEWDIRECTORYCOMMAND_H
#define VIEWDIRECTORYCOMMAND_H

#include <iostream>
#include <dirent.h>

#include "Command.h"


class ViewDirectoryCommand : public Command
{
    public:
        ViewDirectoryCommand();

        void execute(std::string);
    private:
};

#endif // VIEWDIRECTORYCOMMAND_H
