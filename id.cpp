#include <TrueRandom.h>
#include <EEPROM.h>

#include "id.h"

unsigned long GetSelfId(){
  int address = 0;
  long four = EEPROM.read(address);
  long three = EEPROM.read(address + 1);
  long two = EEPROM.read(address + 2);
  long one = EEPROM.read(address + 3);

  return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}

void SetSelfId(unsigned long selfId) {
  int address = 0;

  byte four = (selfId & 0xFF);
  byte three = ((selfId >> 8) & 0xFF);
  byte two = ((selfId >> 16) & 0xFF);
  byte one = ((selfId >> 24) & 0xFF);


  EEPROM.write(address, four);
  EEPROM.write(address + 1, three);
  EEPROM.write(address + 2, two);
  EEPROM.write(address + 3, one);
}

void GenerateSelfId() {
  unsigned long id = TrueRandom.random(100000000, 999999999);
  SetSelfId(id);
}

boolean IsSelfIdValid() {
  unsigned long selfId = GetSelfId();
  
  return !isnan(selfId);
}

char* GetMasterId() {
  int addr = 100;
  int index = 0;
  char masterId[MASTER_ID_LENGTH + 1] = {};
  for (int i = addr; i < MASTER_ID_LENGTH + addr; i++) {
    masterId[index] = EEPROM.read(i);
    index++;
  }
  return masterId;
}

void SetMasterId(char* masterId) {
  int addr = 100;
  int index = 0;
  for (int i = addr; i < MASTER_ID_LENGTH + 1 + addr; i++) {
   EEPROM.write(i, masterId[index]);
   index++;
  } 
}

boolean IsMasterIdValid() {
  boolean returnMessage = true;
  char* masterId = GetMasterId();
  for (int i = 0; i < sizeof(masterId) - 2; i++) {
    if (!isDigit(masterId[i]) || !isAlpha(masterId[i])) {
      returnMessage = false;
    }
  }
  return returnMessage;
}

