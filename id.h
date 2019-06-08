#pragma once
#include <Arduino.h>

const int MASTER_ID_LENGTH = 32; // GUID, digits only

unsigned long GetSelfId();
void SetSelfId(unsigned long selfId);
void GenerateSelfId();
boolean IsSelfIdValid();

char* GetMasterId();
void SetMasterId(char* masterId);
boolean IsMasterIdValid();
