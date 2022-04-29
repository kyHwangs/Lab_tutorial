#ifndef loading_hh
#define loading_hh 1

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "TH1.h"

using namespace std;

class LoadingRawData{
public:

    LoadingRawData(TString filename);
    virtual ~LoadingRawData();

	void Set_channel( int channel ) { fchannel = channel; }
	int Get_channel() { return fchannel; }
	void Set_ch_to_plot( int ch_to_plot ) { fch_to_plot = ch_to_plot; }
	int Get_ch_to_plot() { return fch_to_plot; }

	void Set_nevt( int nevt ) { fnevt = nevt; }
	int Get_nevt() { return fnevt; }
	void Set_evt( int evt ) { fevt = evt; }
	int Get_evt() { return fevt; }

	void Set_data_length( int data_length ) { fdata_length = data_length; }
	int Get_data_length() { return fdata_length; }
	void Set_run_number( int run_number ) { frun_number = run_number; }
	int Get_run_number() { return fchannel; }

	void Set_tcb_trig_type( int tcb_trig_type ) { ftcb_trig_type = tcb_trig_type; }
	int Get_tcb_trig_type() { return ftcb_trig_type; }
	void Set_tcb_trig_number( int tcb_trig_number ) { ftcb_trig_number = tcb_trig_number; }
	int Get_tcb_trig_number() { return ftcb_trig_number; }
	void Set_tcb_trig_time( long long tcb_trig_time ) { ftcb_trig_time = tcb_trig_time; }
	long long Get_tcb_trig_time() { return ftcb_trig_time; }
	
	void Set_mid( int mid ) { fmid = mid; }
	int Get_mid() { return fmid; }
	void Set_local_trig_number( int local_trig_number ) { flocal_trig_number = local_trig_number; }
	int Get_local_trig_number() { return flocal_trig_number; }
	void Set_local_trigger_pattern( int local_trigger_pattern ) { flocal_trigger_pattern = local_trigger_pattern; }
	int Get_local_trigger_pattern() { return flocal_trigger_pattern; }
	void Set_local_trig_time( long long local_trig_time ) { flocal_trig_time = local_trig_time; }
	long long Get_local_trig_time() { return flocal_trig_time; }
	
	void Set_diff_time( long long diff_time ) { fdiff_time = diff_time; }
	long long Get_diff_time() { return fdiff_time; }
	void Set_fine_time( long long fine_time ) { ffine_time = fine_time; }
	long long Get_fine_time() { return ffine_time; }
	void Set_coarse_time( long long coarse_time ) { fcoarse_time = coarse_time; }
	long long Get_coarse_time() { return fcoarse_time; }

	
private:

	FILE *fInputFile;
	TString fFilename;

	char data[64];
	short adc[32736];
    
	int fchannel;
	int fch_to_plot;
	
	int fnevt;
	int fevt;
    
    int fdata_length;
	int frun_number;
	
    int ftcb_trig_type;
	int ftcb_trig_number;
	long long ftcb_trig_time;
	
    int fmid;
	int flocal_trig_number;
	int flocal_trigger_pattern;
	long long flocal_trig_time;

	long long fdiff_time;
	long long ffine_time;
	long long fcoarse_time;
	
	int fitmp;
	long long fltmp;
	int i;
	int cont;

	void OpenFile(TString filename);
};

#endif