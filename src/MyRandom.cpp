#include "MyRandom.h"

unsigned int MyRandom::A = 16807;
unsigned int MyRandom::M = 0x7fffffff;

MyRandom::MyRandom():seed(1){}
MyRandom::MyRandom(unsigned int seed){ this->seed = seed;}
MyRandom::~MyRandom (){}

void MyRandom::setSeed(unsigned int newSeed){
    this->seed = newSeed;}

  unsigned int MyRandom::getNextRnd(){
    this->seed = (this->seed * MyRandom::A) % MyRandom::M;
    return this->seed;}

unsigned int MyRandom::getNextRnd(unsigned int MAX){
    return this->getNextRnd() % MAX; }
