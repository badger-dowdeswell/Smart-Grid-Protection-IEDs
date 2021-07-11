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

const CStringDictionary::TStringId FORTE_overcurrent::scm_anDataInputNames[] = {g_nStringIdIpickup_current, g_nStringIdcurrent, g_nStringIdcurve_type, g_nStringIdIpickup_Mvalue, g_nStringIdtime_dial_setting, g_nStringIdmin_trip_time};

const CStringDictionary::TStringId FORTE_overcurrent::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdINT, g_nStringIdINT, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_overcurrent::scm_anDataOutputNames[] = {g_nStringIdtrip, g_nStringIdtrip_time};

const CStringDictionary::TStringId FORTE_overcurrent::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdREAL};

const TForteInt16 FORTE_overcurrent::scm_anEIWithIndexes[] = {0, 6, -1, -1, -1};
const TDataIOID FORTE_overcurrent::scm_anEIWith[] = {0, 2, 3, 4, 5, 255, 1, 255};
const CStringDictionary::TStringId FORTE_overcurrent::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRESET, g_nStringIdTIME_UP, g_nStringIdCLEAR};

const TDataIOID FORTE_overcurrent::scm_anEOWith[] = {0, 255, 1, 255};
const TForteInt16 FORTE_overcurrent::scm_anEOWithIndexes[] = {-1, 0, 2, -1, -1};
const CStringDictionary::TStringId FORTE_overcurrent::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdSTART_TIMER, g_nStringIdRESET_OUT};

const SFBInterfaceSpec FORTE_overcurrent::scm_stFBInterfaceSpec = {
  5,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  6,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

using std::cout;
using std::string;
using std::to_string;

//void FORTE_overcurrent::alg_initialize(void){
//	cout <<"alg_initialise\n"
//}

//void FORTE_overcurrent::alg_deInitialize(void){
//}

//void FORTE_overcurrent::alg_normalOperation(void){
//QO = QI;
//};

void FORTE_overcurrent::alg_INIT(void){
	cout << "overcurrent alg_INIT\n";
}

void FORTE_overcurrent::alg_START_TIMER(void){
	cout << "alg_START_TIMER\n";
}

void FORTE_overcurrent::alg_RESET(void){
	cout << "alg_RESET\n";
}

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
  m_nECCState = scm_nStateFAULT;
}

void FORTE_overcurrent::enterStateSTART_TIMER(void){
	m_nECCState = scm_nStateSTART_TIMER;
  	alg_START_TIMER();
  	sendOutputEvent(scm_nEventSTART_TIMERID);
}

void FORTE_overcurrent::enterStateTRIP(void){
  	m_nECCState = scm_nStateTRIP;
  	alg_TRIP();
  	sendOutputEvent(scm_nEventCNFID);
}

void FORTE_overcurrent::enterStateRESET(void){
	m_nECCState = scm_nStateRESET;
  	alg_RESET();
  	sendOutputEvent( scm_nEventRESET_OUTID);
}

void FORTE_overcurrent::executeEvent(int pa_nEIID){
	bool bTransitionCleared;
  	do	{
    	bTransitionCleared = true;
    	switch(m_nECCState){
      case scm_nStateNORMAL:
      	if (scm_nEventINITID == pa_nEIID)
          	enterStateINIT();
        	else
        		if	((scm_nEventREQID == pa_nEIID) && (mathlib.compareGE(current(), Ipickup_current())))
        			enterStateFAULT();
        		else
          		bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateINIT:
      	if ((1))
         	enterStateNORMAL();
        	else
          	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateFAULT:
      	if (!fault())
          	enterStateSTART_TIMER();
        	else
        		if	(scm_nEventTIME_UPID == pa_nEIID)
          		enterStateTRIP();
        		else
        			if ((scm_nEventREQID == pa_nEIID) && (mathlib.compareLT(current(), Ipickup_current())))
          			enterStateRESET();
        			else
          			bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateSTART_TIMER:
      	if((1))
        		enterStateFAULT();
        	else
          	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateTRIP:
      	if	(scm_nEventCLEARID == pa_nEIID)
          	enterStateRESET();
        	else
         	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateRESET:
      	if	(scm_nEventCLEARID == pa_nEIID)
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


