#include "Global.h"


void Global::alert(std::string text)
{
    message.setString(text);
    window.draw(message);
    window.display();
}