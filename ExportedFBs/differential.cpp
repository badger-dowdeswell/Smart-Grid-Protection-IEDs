/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: differential
 *** Description: Restrained differential protection device
 *** Version: 
 ***     1.0: 2021-03-23/Badger - AUT EMSOFT - 
 *************************************************************************/

#include "differential.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "differential_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_differential, g_nStringIddifferential)

const CStringDictionary::TStringId FORTE_differential::scm_anDataInputNames[] = {g_nStringIdpoll_time, g_nStringIddifferential_percentage, g_nStringIdIcurrent_1, g_nStringIdIcurrent_2};

const CStringDictionary::TStringId FORTE_differential::scm_anDataInputTypeIds[] = {g_nStringIdTIME, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_differential::scm_anDataOutputNames[] = {g_nStringIdpoll_time_set, g_nStringIdtrip};

const CStringDictionary::TStringId FORTE_differential::scm_anDataOutputTypeIds[] = {g_nStringIdTIME, g_nStringIdBOOL};

const TForteInt16 FORTE_differential::scm_anEIWithIndexes[] = {0, 3, -1, -1};
const TDataIOID FORTE_differential::scm_anEIWith[] = {1, 0, 255, 2, 3, 255};
const CStringDictionary::TStringId FORTE_differential::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRESET, g_nStringIdPOLL};

const TDataIOID FORTE_differential::scm_anEOWith[] = {1, 255, 0, 255};
const TForteInt16 FORTE_differential::scm_anEOWithIndexes[] = {-1, 0, 2, -1, -1, -1};
const CStringDictionary::TStringId FORTE_differential::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdSTART_POLL, g_nStringIdSTOP_POLL, g_nStringIdRESET_OUT};

const SFBInterfaceSpec FORTE_differential::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  5,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

using std::cout;
using std::string;
using std::to_string;

void FORTE_differential::alg_initialize(void){
	cout << "alg_initialise\n";
	cout << "poll_time = " << to_string(poll_time()) << "\n";
	cout << "differential_percentage = " << to_string(differential_percentage()) << "\n";	
	cout << "Icurrent_1 = " << to_string(Icurrent_1()) << "\n";	
	cout << "Icurrent_2 = " << to_string(Icurrent_2()) << "\n";
}

void FORTE_differential::alg_START_TIMER(void){
	cout << "alg_START_TIMER\n";
	poll_time_set() = poll_time();
}

void FORTE_differential::alg_REQ(void){
	cout << "alg_REQ\n";
}

void FORTE_differential::alg_POLL(void){
	cout << "alg_POLL\n";
}

void FORTE_differential::alg_RESET(void){
	cout << "alg_RESET\n";
}

void FORTE_differential::alg_TRIP(void){
	cout << "alg_TRIP\n";
}

//
// alg_differential()
// ==================
bool FORTE_differential::alg_differential(CIEC_REAL differential_percentage, CIEC_REAL Icurrent_1, CIEC_REAL Icurrent_2) {
	cout << "alg_differential\n";
}


void FORTE_differential::enterStateNORMAL(void){
  m_nECCState = scm_nStateNORMAL;
}

void FORTE_differential::enterStateInit(void){
	m_nECCState = scm_nStateInit;
  	alg_initialize();
  	sendOutputEvent( scm_nEventINITOID);
  	alg_START_TIMER();
  	sendOutputEvent( scm_nEventSTART_POLLID);
}

void FORTE_differential::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
}

void FORTE_differential::enterStatePOLL(void){
	m_nECCState = scm_nStatePOLL;
  	alg_POLL();
}

void FORTE_differential::enterStateTRIP(void){
  m_nECCState = scm_nStateTRIP;
  alg_TRIP();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_differential::enterStateRESET(void){
	m_nECCState = scm_nStateRESET;
  	alg_RESET();
  	sendOutputEvent( scm_nEventRESET_OUTID);
}

void FORTE_differential::executeEvent(int pa_nEIID){
	bool bTransitionCleared;
  	do	{
    	bTransitionCleared = true;
    	switch(m_nECCState){
      case scm_nStateNORMAL:
			if (scm_nEventINITID == pa_nEIID)
        		enterStateInit();
        	else
        		if(scm_nEventREQID == pa_nEIID)
          		enterStateREQ();
        		else
        			if(scm_nEventPOLLID == pa_nEIID)
          			enterStatePOLL();
        			else
          			bTransitionCleared  = false; //no transition cleared
        break;
        
      case scm_nStateInit:
      	if((1))
         	enterStateNORMAL();
        	else
         	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateREQ:
      	if ((1))
         	enterStateNORMAL();
        	else
         	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStatePOLL:
        	if ( ( alg_differential((differential_percentage()), (Icurrent_1()), (Icurrent_2()) ) ) == true )
         	enterStateTRIP();
        else
        		if((1))
          		enterStateNORMAL();
        		else
          		bTransitionCleared  = false; //no transition cleared
        break;
        
      case scm_nStateTRIP:
      	if(scm_nEventRESETID == pa_nEIID)
         	enterStateRESET();
        	else
         	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateRESET:
      	if((1))
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
	}	while(bTransitionCleared);
}


