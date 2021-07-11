/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: earth_fault
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 3/23/2016/gulzha - nxtControl GmbH - Template
 ***     1.0: 22/02/2021/Badger - 4diac - Refactored and migrated to 4diac
 *************************************************************************/

#include "earth_fault.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "earth_fault_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_earth_fault, g_nStringIdearth_fault)

const CStringDictionary::TStringId FORTE_earth_fault::scm_anDataInputNames[] = {g_nStringIdpickup_voltage, g_nStringIdvoltage};

const CStringDictionary::TStringId FORTE_earth_fault::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_earth_fault::scm_anDataOutputNames[] = {g_nStringIdtrip};

const CStringDictionary::TStringId FORTE_earth_fault::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_earth_fault::scm_anEIWithIndexes[] = {0, 2, -1, -1, -1};
const TDataIOID FORTE_earth_fault::scm_anEIWith[] = {0, 255, 0, 1, 255};
const CStringDictionary::TStringId FORTE_earth_fault::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRESET, g_nStringIdTIME_UP, g_nStringIdCLEAR};

const TDataIOID FORTE_earth_fault::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_earth_fault::scm_anEOWithIndexes[] = {0, -1, -1, -1};
const CStringDictionary::TStringId FORTE_earth_fault::scm_anEventOutputNames[] = {g_nStringIdCNF, g_nStringIdSTART_TIMER, g_nStringIdRESET_OUT};

const CStringDictionary::TStringId FORTE_earth_fault::scm_anInternalsNames[] = {g_nStringIdfault};

const CStringDictionary::TStringId FORTE_earth_fault::scm_anInternalsTypeIds[] = {g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_earth_fault::scm_stFBInterfaceSpec = {
  5,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

const SInternalVarsInformation FORTE_earth_fault::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};

using std::cout;
using std::string;
using std::to_string;
using std::max;
using std::abs;

void FORTE_earth_fault::alg_INIT(void){
	cout << "alg_INIT\n";
	trip() = false;
	fault() = false;
}

void FORTE_earth_fault::alg_REQ(void){
	cout << "alg_REQ\n";
	//trip() = false;
}

void FORTE_earth_fault::alg_RESET(void){
	cout << "alg_RESET\n";
	trip() = false;
	fault() = false;
}

void FORTE_earth_fault::alg_START_TIMER(void){
	cout << "alg_START_TIMER\n";
	fault() = true;
}

void FORTE_earth_fault::alg_TRIP(void){
	cout << "alg_TRIP()\n";
}

void FORTE_earth_fault::enterStateNORMAL(void){
	cout << "enterStateNORMAL\n";
  	m_nECCState = scm_nStateNORMAL;
}

void FORTE_earth_fault::enterStateINIT(void){
	cout << "enterStateINIT\n";
	m_nECCState = scm_nStateINIT;
  	alg_INIT();
}

void FORTE_earth_fault::enterStateFAULT(void){
	cout << "enterStateFAULT\n";
	m_nECCState = scm_nStateFAULT;
}

void FORTE_earth_fault::enterStateTRIP(void){
	cout << "enterStateTRIP\n";
	m_nECCState = scm_nStateTRIP;
  	alg_TRIP();
  	sendOutputEvent( scm_nEventCNFID);
}

void FORTE_earth_fault::enterStateRESET(void){
	cout << "enterStateRESET\n";
  	m_nECCState = scm_nStateRESET;
  	alg_RESET();
  	sendOutputEvent( scm_nEventRESET_OUTID);
}

void FORTE_earth_fault::enterStateSTART_TIMER(void){
	cout << "enterStateSTART_TIMER\n";
  	m_nECCState = scm_nStateSTART_TIMER;
  	alg_START_TIMER();
  	sendOutputEvent( scm_nEventSTART_TIMERID);
}

void FORTE_earth_fault::executeEvent(int pa_nEIID){
	cout << "FORTE_earth_fault executeEvent()\n";
	cout << "voltage = " << to_string(voltage()) << " " 
	     << "pickup_voltage = " << to_string(pickup_voltage()) << "\n";
	     
//	if (mathlib.compareGE(voltage(), pickup_voltage())) {
//		cout << "GE test true\n";
//	} else {
//		cout << "GE test false\n";
//	}	
	
//	if (mathlib.compareEQ(voltage(), pickup_voltage())) {
//		cout << "EQ test true\n";
//	} else {
//		cout << "EQ test false\n";
//	}	
	
//	if (mathlib.compareLT(voltage(), pickup_voltage())) {
//		cout << "LT test true\n";
//	} else {
//		cout << "LT test false\n";
//	}
    
  	bool bTransitionCleared;
  	do	{
    	bTransitionCleared = true;
    	switch(m_nECCState){
      case scm_nStateNORMAL:
      	if (scm_nEventINITID == pa_nEIID)
          	enterStateINIT();
        	else
        		if ((scm_nEventREQID == pa_nEIID) && (mathlib.compareGE(voltage(), pickup_voltage()))) 
          		enterStateFAULT();
        		else
          		bTransitionCleared  = false; //no transition cleared
        	break;
        
      case scm_nStateINIT:
      	if((1))
         	enterStateNORMAL();
        	else
         	 bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateFAULT:
      	if (pa_nEIID == scm_nEventTIME_UPID)
         	enterStateTRIP();
        	else
        		if ((pa_nEIID == scm_nEventREQID) && (mathlib.compareLT(voltage(), pickup_voltage()))) 
          		enterStateRESET();
        		else
        			if (!fault())
          			enterStateSTART_TIMER();
        			else
          			bTransitionCleared  = false; //no transition cleared
       	break;
       	
      case scm_nStateTRIP:
      	if ((pa_nEIID == scm_nEventRESETID))
         	enterStateRESET();
        	else
         	bTransitionCleared  = false; //no transition cleared
        	break;
        
      case scm_nStateRESET:
        	if (pa_nEIID == scm_nEventRESETID)
        		enterStateNORMAL();
        	else
        		bTransitionCleared  = false; //no transition cleared
        	break;
        
      case scm_nStateSTART_TIMER:
      	if((1))
         	enterStateFAULT();
        	else
         	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      default:
      	DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", m_nECCState.operator TForteUInt16 ());
        	m_nECCState = 0; //0 is always the initial state
        	break;
    	}
    	pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
	}	while(bTransitionCleared);
}

