#include "discriminator.hh"

#include "TROOT.h"
#include "TStyle.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TPaveStats.h"
#include "TString.h"
#include "TLorentzVector.h"
#include "TGraph.h"

#include <iostream>
#include <string>


Discriminator::Discriminator(TString option, double IntThres) {
    
    fDiscrimOpt = option;
}

void Discriminator::SetThres(double Thres) {
    if ( fDiscrimOpt == "integral" ) SetIntThres(Thres);
}


Discriminator::~Discriminator() {

}

bool Discriminator::IsSignal(TH1F* waveform) {

    if ( fDiscrimOpt == "integral" ) return IntDiscriminator(waveform);

    return false;
}

bool Discriminator::IntDiscriminator(TH1F* waveform) {

    return true;

}