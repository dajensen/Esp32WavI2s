#include "WavPlayer.h"
#include "sound/WavData.h"

WavPlayer player;


enum SpeechState {
  WAITING,
  HOUR,
  MINUTE
};

SpeechState speechstate;

void setup() {
  Serial.begin(115200);
  delay(1000);

  speechstate = HOUR;
  Serial.println("Starting to play");
  if(!player.StartPlaying(hourWav[11]))
    Serial.println("ERROR SETTING UP THE DATA");
}

void loop()
{
  if(!player.Update()){
    if(speechstate == HOUR) {
      speechstate = MINUTE;
      player.StartPlaying(minuteWav[39]);
    }
    else if(speechstate == MINUTE) 
      speechstate = WAITING;
    else
      delay(10);
  }

}
