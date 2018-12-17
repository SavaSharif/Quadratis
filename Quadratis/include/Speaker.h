#ifndef Speaker_H
#define Speaker_H

#include <Arduino.h>
#include "HardwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define TX_MP3 35
#define RX_MP3 33

class Speaker
{
  public:
    Speaker();
    ~Speaker();
    void setMusic();
    void getSongNumber();
    void playSong(int fileNumber);

  private:
    DFRobotDFPlayerMini* myDFPlayer = new DFRobotDFPlayerMini();

    void printDetail(uint8_t type, int value);
};

#endif
