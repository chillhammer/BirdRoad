#ifndef RANDOMGEN_H
#define RANDOMGEN_H


//shorthand
#define randGen RandomGen::Instance()


//singleton object
class RandomGen{
private:
    RandomGen();

public:
    ~RandomGen();


    static RandomGen* Instance();
    int rInt(int);
    
};

#endif
