#ifndef DEBUG_H
#define DEBUG_H
#include <string>
#include <SFML/Graphics.hpp>
#include <sstream>
// Inarut (Dan#9#): Improve on this
class Debug
{
    public:
        Debug();
        virtual ~Debug();
        void dint(int);
        void dstring(std::string);
        int test2 = 1;


    protected:
    private:

};

#endif // DEBUG_H
