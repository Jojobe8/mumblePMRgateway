#include <wiringPi.h>
#include <cstdio>
#include "ExternalPTT.h"

ExternalPTT::ExternalPTT() {
  this->save_bInitialized = false;
  this->save_bPTTState = false;
  //___PINCONFIG___
  // sqlPIN: Physical pin 15, BCM GPIO 22, and WiringPi pin 3. --> Ausgang (SQL) wenn Mumble Audio empfängt
  this->SQLpin = 3;
  // pttPIN: Physical pin 11, BCM GPIO 27, and WiringPi pin 0. --> Eingang um Mumble auf TX zu schalten
  this->PTTpin = 0;
  //_______________
  printf("ExternalPTT() called!\n");
}

ExternalPTT::~ExternalPTT() {
  printf("~ExternalPTT() called!\n");
}

bool ExternalPTT::init() {
  if(this->save_bInitialized) return false; // Nur einmal initialisieren!
  
  printf("ExternalPTT::init() called!\n");
  wiringPiSetup();
  printf("SETUP...\n");
  pinMode(SQLpin, OUTPUT);
  pinMode(PTTpin, INPUT);
  pullUpDnControl(PTTpin, PUD_UP);
  
  this->save_bInitialized = true;
  return true;
}
bool ExternalPTT::getPINsetting(){
  if(!this->save_bInitialized) return false;
  printf("-----------------\n");
  printf("-- PTT Pin = %i --\n", this->PTTpin);
  printf("-- SQL Pin = %i --\n", this->SQLpin);
  printf("-----------------\n");
  return true;
}

bool ExternalPTT::getSavePTTstate() {
  return this->save_bPTTState;
}

bool ExternalPTT::getPTTstate() {
  if(!this->save_bInitialized) return false;
  bool state = digitalRead(this->PTTpin) != HIGH;
  if(state != this->save_bPTTState) {
    printf("PTT Status = \t %s \n", state ? "Aktiv":"Inaktiv");
    this->save_bPTTState = state;
  }
  return state;
}

bool ExternalPTT::setSQLstate(bool sqlstate) {
  if(!this->save_bInitialized) return false;
  digitalWrite(this->SQLpin, sqlstate ? HIGH : LOW);
  printf("Setzte SQL PIN-> %s\n", sqlstate ? "low":"high");
  return true;
}
