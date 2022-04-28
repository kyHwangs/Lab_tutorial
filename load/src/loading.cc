#include "loading.hh"

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

LoadingRawData::LoadingRawData()
: fnevt(0), fevt(0), fInputFile(0), {

    // Set_fnevt(0);
    // Set_evt(0);

    SetTemp(0);
    Set_channel(0);
    Set_ch_to_plot(0);
    Set_file_size(0);
    Set_data_length(0);
    Set_run_number(0);
    Set_tcb_trig_type(0);
    Set_tcb_trig_number(0);
    Set_tcb_trig_time(0);
    Set_mid(0);
    Set_local_trig_number(0);
    Set_local_trigger_pattern(0);
    Set_local_trig_time(0);
    Set_diff_time(0);
    Set_fine_time(0);
    Set_coarse_time(0);
    Set_channel(0);
}

LoadingRawData::~LoadingRawData() {
    fclose(fInputFile);
}

LoadingRawData::OpenFile(TString filename) {

    fInputFile = fopen(filename.Data(), "rb");
    fseek(fInputFile, 0L, SEEK_END);
    int file_size = ftell(fInputFile);
    fclose(fInputFile);
    Set_nevt( file_size / 65536 );

    fInputFile = fopen(filename.Data(), "rb");
}

