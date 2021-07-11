/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: overcurrent
 *** Description: Template for a simple Basic Function Block Type
 *** Version: 
 ***     1.0: 2021-02-27/badger - null - 
 *************************************************************************/

#include "overcurrent.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "overcurrent_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_overcurrent, g_nStringIdovercurrent)

const CStringDictionary::TStringId FORTE_overcurrent::scm_anDataInputNames[] = {g_nStringIdIpickup_current, g_nStringIdcurrent, g_nStringIdcurve_type, g_nStringIdtime_dial_setting, g_nStringIdmin_trip_time};

const CStringDictionary::TStringId FORTE_overcurrent::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdINT, g_nStringIdREAL, g_nStringIdTIME};

const CStringDictionary::TStringId FORTE_overcurrent::scm_anDataOutputNames[] = {g_nStringIdtrip, g_nStringIdtrip_time};

const CStringDictionary::TStringId FORTE_overcurrent::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdTIME};

const TForteInt16 FORTE_overcurrent::scm_anEIWithIndexes[] = {0, 5, -1, -1, -1};
const TDataIOID FORTE_overcurrent::scm_anEIWith[] = {0, 2, 3, 4, 255, 1, 255};
const CStringDictionary::TStringId FORTE_overcurrent::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRESET, g_nStringIdTIME_UP, g_nStringIdCLEAR};

const TDataIOID FORTE_overcurrent::scm_anEOWith[] = {0, 255, 1, 255};
const TForteInt16 FORTE_overcurrent::scm_anEOWithIndexes[] = {-1, 0, 2, -1, -1};
const CStringDictionary::TStringId FORTE_overcurrent::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdSTART_TIMER, g_nStringIdRESET_OUT};

const SFBInterfaceSpec FORTE_overcurrent::scm_stFBInterfaceSpec = {
  5,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

using std::cout;
using std::string;
using std::to_string;

//
// calcInverseOvercurrent()
// ========================
// Calculates the trip time in milliseconds for a specified overcurrent. The
// algorithm uses a different formulae for each type of curve based on 
// ANSI standard for overcurrent protection.
//
// curveType         Specifies which ANSI-standard Time-overcurrent curves is to be used.
//                   The value is one of the ANSI_Time_Curve constants. 
//
// Ipickup           The current limit in amperes that defines when there is an overcurrent
//                   fault in-progress.
//
// Icurrent          The measured current in amperes. This must always be greater than Ipickup.
//                   This algorithm will return a result of zero if Icurrent is less than 
//                   or equal to Ipickup. 
//
// timeDialSetting   The ANSI time dial setting. This is a number between 0.5 and 15. Refer to
//                   ABB and Siemens documentation for a detailed explanation of this parameter.
// 
//
CIEC_TIME FORTE_overcurrent::calcInverseOvercurrent(int curveType, double Ipickup, double Icurrent, double timeDialSetting) {
	CIEC_TIME tripTime = CIEC_TIME(1);
	double timeValue = 0;
	double Mvalue = 0;
	
	if (Ipickup > 0) {
		Mvalue = Icurrent / Ipickup;	

		switch (curveType) {
		case CURVE_TYPE_NORMAL_INVERSE:
	   	timeValue = timeDialSetting * (0.18 + (5.95 / (( Mvalue * Mvalue) - 1)));
	   	cout << "timeValue = " << to_string(timeValue) << "\n";
	   	tripTime = CIEC_TIME((long int) (timeValue * 1000000000));
	   	break;
	         
		case CURVE_TYPE_VERY_INVERSE:
	   	timeValue = timeDialSetting * (0.0963 + (3.88 / (( Mvalue * Mvalue) - 1)));
	   	tripTime = CIEC_TIME((long int) (timeValue * 100000000));
	   	cout << "ANSI curve " << to_string(CURVE_TYPE_VERY_INVERSE) << " trip_time = " << to_string(tripTime) << "ms\n";
	   	break;
	   			
		case CURVE_TYPE_EXTREME_INVERSE:
	   	timeValue = timeDialSetting * (0.0352 + (5.67 / (( Mvalue * Mvalue) - 1)));
	   	cout << "timeValue = " << to_string(timeValue) << "\n";
	   	tripTime = CIEC_TIME((long int) (timeValue * 1000000000));
	   	break;
	   			 
		case CURVE_TYPE_LONG_TIME_INVERSE:
	   	timeValue = timeDialSetting * ((120 / (( Mvalue * Mvalue) - 1)));
	   	cout << "timeValue = " << to_string(timeValue) << "\n";
	   	tripTime = CIEC_TIME((long int) (timeValue * 1000000000));
	   	break;
	   	
	   case CURVE_TYPE_SHORT_TIME_INVERSE:
	   	timeValue = timeDialSetting * ((0.05 / (( Mvalue * Mvalue) - 1)));
	   	cout << "timeValue = " << to_string(timeValue) << "\n";
	   	tripTime = CIEC_TIME((long int) (timeValue * 1000000000));
		}
	}	
	return tripTime;
}

//
// alg_INIT()
// ==========
void FORTE_overcurrent::alg_INIT(void){
	cout << "overcurrent alg_INIT -"
	     << "\nIpickup_current   " << to_string(Ipickup_current())
	     << "\ncurve_type        " << to_string(curve_type())
	     << "\ntime_dial_setting " << to_string(time_dial_setting())
	     << "\nmin_trip_time     " << to_string(min_trip_time()) << "\n\n";
	fault = false; 
	
	// RA_BRD debug
	//current() = 9.0;
	//trip_time() = calcInverseOvercurrent(curve_type(), Ipickup_current(),
//	                                     current(), time_dial_setting());    
 	//c//out << "trip_time = " << to_string(trip_time()) << "\n";
}
//	CIEC_TIME time1;
//	time1.setFromMiliSeconds(200);
//	cout << "time1 = " << to_string(time1) << "\n";
	
//	time1.setFromMicroSeconds(200);
//	cout << "time1 = " << to_string(time1) << "\n";
	     
//	trip_time() = calc_trip_time(curve_type(), min_trip_time() );
//	cout << "overcurrent alg_INIT\n" << " trip_time() " << to_string(trip_time()) << "\n";

void FORTE_overcurrent::alg_TRIP(void){
	cout << "alg_TRIP\n";
}

void FORTE_overcurrent::enterStateNORMAL(void){
  	m_nECCState = scm_nStateNORMAL;
}

void FORTE_overcurrent::enterStateINIT(void){
	m_nECCState = scm_nStateINIT;
  	alg_INIT();
  	sendOutputEvent(scm_nEventINITOID);
}

void FORTE_overcurrent::enterStateFAULT(void){
	cout << "overcurrent enterStateFAULT\n";
  	m_nECCState = scm_nStateFAULT; 
}

void FORTE_overcurrent::enterStateSTART_TIMER(void){
	cout << "\nFORTE_overcurrent::enterStateSTART_TIMER\n";
	m_nECCState = scm_nStateSTART_TIMER;
  	alg_START_TIMER();
  	sendOutputEvent(scm_nEventSTART_TIMERID);
}

void FORTE_overcurrent::alg_START_TIMER(void){
	cout << "alg_START_TIMER\n";
	fault = true;
	
	if (curve_type() == CURVE_TYPE_SHORT_TIME) {
		cout << "CURVE_TYPE_SHORT_TIME. min_trip_time = " <<to_string(min_trip_time()) << "\n";
		// The min_trip_time is specified in the function block
		// parameter as 10000 which is 10 seconds with an implied 
		// unit of milliseconds. However, FORTE thinks that is a time 
		// in seconds. Hence the division by 1,000 below.
		trip_time().setFromMicroSeconds(min_trip_time() / 1000);    
	} else {
		// Calculate the inverse curve overcurrent time
		trip_time() = calcInverseOvercurrent(curve_type(), Ipickup_current(),
	                                    	 current(), time_dial_setting());  
	   cout << "CURVE TYPE = " << to_string(curve_type()) << ". Calculated trip_time = "
	        << to_string(trip_time()) << "\n";                                	   
	}
}

void FORTE_overcurrent::enterStateTRIP(void){
  	m_nECCState = scm_nStateTRIP;
  	alg_TRIP();
  	sendOutputEvent(scm_nEventCNFID);
}

void FORTE_overcurrent::enterStateRESET(void){
	m_nECCState = scm_nStateRESET;
  	alg_RESET();
  	sendOutputEvent(scm_nEventRESET_OUTID);
}

void FORTE_overcurrent::alg_RESET(void){
	cout << "alg_RESET\n";
	fault = false;
}

//
// executeEvent()
// ==============
//
void FORTE_overcurrent::executeEvent(int pa_nEIID){
	bool bTransitionCleared;
  	do	{
    	bTransitionCleared = true;
    	switch(m_nECCState){
      case scm_nStateNORMAL:
      	if (scm_nEventINITID == pa_nEIID) {
          	enterStateINIT();
        	} else {
        		if (scm_nEventREQID == pa_nEIID){
        			cout << "overcurrent REQ fired\n";
        			if (mathlib.compareGE(current(), Ipickup_current())) {
        				enterStateFAULT();	
        			} else {
        				bTransitionCleared  = false;
        			}
        		} else {
       	 		bTransitionCleared  = false; //no transition cleared	
       	 	}	
        	}
        	//	if	((scm_nEventREQID == pa_nEIID) && (mathlib.compareGE(current(), Ipickup_current()))) {
       	//		enterStateFAULT();
        	//	} else {
         //		bTransitionCleared  = false; //no transition cleared
         //	}
         //} 		
        	break;
        	
      case scm_nStateINIT:
      	if ((1))
         	enterStateNORMAL();
        	else
          	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateFAULT:
       	if ( !(fault) ) {
          	enterStateSTART_TIMER();
       	} else {
        		if	(scm_nEventTIME_UPID == pa_nEIID) {
          		enterStateTRIP();
        		} else {
        			if ((scm_nEventREQID == pa_nEIID) && (mathlib.compareLT(current(), Ipickup_current()))) {
          			enterStateRESET();
        			} else {
          			bTransitionCleared  = false; //no transition cleared
          		}
          	}
         } 			
        	break;
        	
      case scm_nStateSTART_TIMER:
      	if ((1))
        		enterStateFAULT();
        	else
          	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateTRIP:
      	if	(scm_nEventCLEARID == pa_nEIID) {
      		cout << "CLEAR event fired\n";
          	enterStateRESET();
        	} else {
         	bTransitionCleared  = false; //no transition cleared
        	}
        	break;
        	
      case scm_nStateRESET:
      	if	((1))
         	enterStateNORMAL();
        	else
         	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      default:
      	DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", m_nECCState.operator TForteUInt16 ());
        	m_nECCState = 0; //0 is always the initial state
        	break;
    	}
    	pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
	}	while	(bTransitionCleared);
}




