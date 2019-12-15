#ifndef MYRANDOM_H
#define MYRANDOM_H

class MyRandom
{
    public:
        MyRandom();
        MyRandom(unsigned int seed);
        virtual ~MyRandom ();
        void setSeed(unsigned int seed);
        unsigned int getNextRnd();
        unsigned int getNextRnd(unsigned int MAX);

    private:
        unsigned int seed;
        static unsigned int A;
        static unsigned int M;

};
#endif // MYRANDOM _H
