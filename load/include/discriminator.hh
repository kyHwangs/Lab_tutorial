#ifndef discriminator_hh
#define discriminator_hh 1

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "TH1.h"


using namespace std;

class Discriminator{
public:

    Discriminator(TString option = "", double IntThres = 0);
    virtual ~Discriminator();
    void SetThres(double Thres);
    void SetIntThres(double Thres) { fIntThres = Thres; };

    bool IsSignal(TH1F* waveform);
    bool IntDiscriminator(TH1F* waveform);

private:

    TString fDiscrimOpt;
    double fIntThres;
};

#endif