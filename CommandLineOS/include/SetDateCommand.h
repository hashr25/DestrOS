#ifndef SETDATECOMMAND_H
#define SETDATECOMMAND_H

#include <Command.h>


class SetDateCommand : public Command
{
    public:
        SetDateCommand();

        void execute(std::string);
    protected:
    private:
};

#endif // SETDATECOMMAND_H
