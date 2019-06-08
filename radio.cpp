#include <SPI.h>
#include <LoRa.h>

#include "radio.h"

const int RFM95_CS = 7;
const int RFM95_RST = 5;
const int RFM95_INT = 3;

bool isIdle = false;
bool isAsleep = false;

void ConfigureRadio() {
  LoRa.setPins(RFM95_CS, RFM95_RST, RFM95_INT);
  LoRa.setSpreadingFactor(12);
  LoRa.setCodingRate4(8);
  LoRa.setTxPower(15);
}

bool StartRadio() {
  return LoRa.begin(915E6);
}

void IdleRadio(){
  LoRa.idle();
  isIdle = !isIdle;
}

void SleepRadio(){
  LoRa.sleep();
  isAsleep = !isAsleep;
}

bool IsAsleep() {
  return isAsleep;
}
bool IsIdle() {
  return isIdle;
}

