#include "audiosystem.h"
#include <string>
using namespace std;
#include <QDebug>
#include <QString>

AudioSystem::AudioSystem()
{

}

void AudioSystem::playMessage(string audioMessage)
{
  qInfo() << "Elevator audio system play message: " << QString::fromStdString(audioMessage);
}
