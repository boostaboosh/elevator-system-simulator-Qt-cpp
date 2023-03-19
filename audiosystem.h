#ifndef AUDIOSYSTEM_H
#define AUDIOSYSTEM_H

#include <string>
using namespace std;

/**
 * @brief The AudioSystem class models an audio system which can play audio messages.
 */
class AudioSystem
{
public:
    AudioSystem();
    void playMessage(string);
};

#endif // AUDIOSYSTEM_H
