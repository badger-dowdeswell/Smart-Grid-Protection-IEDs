/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: trip_multiplexer
 *** Description: Template for a simple Basic Function Block Type
 *** Version: 
 ***     1.0: 2021-02-26/badger - null - 
 *************************************************************************/

#include "trip_multiplexer.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "trip_multiplexer_gen.cpp"
#endif

using std::cout;

DEFINE_FIRMWARE_FB(FORTE_trip_multiplexer, g_nStringIdtrip_multiplexer)

const TForteInt16 FORTE_trip_multiplexer::scm_anEIWithIndexes[] = {-1, -1, -1, -1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_trip_multiplexer::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdTRIP_1, g_nStringIdTRIP_2, g_nStringIdTRIP_3, g_nStringIdTRIP_4, g_nStringIdTRIP_5, g_nStringIdRESET};

const TForteInt16 FORTE_trip_multiplexer::scm_anEOWithIndexes[] = {-1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_trip_multiplexer::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCB_TRIP, g_nStringIdCB_RESET};

const SFBInterfaceSpec FORTE_trip_multiplexer::scm_stFBInterfaceSpec = {
  7,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  0, 0,  0,  0, 0, 
  0,  0, 0,
  0, 0
};

void FORTE_trip_multiplexer::alg_INITIALISE(void){
	//cout << "alg_INITIALISE\n";
}

void FORTE_trip_multiplexer::alg_TRIP(void){
	//cout << "alg_TRIP\n";
}

void FORTE_trip_multiplexer::alg_RESET(void){
	//cout << "alg_RESET\n";
}

void FORTE_trip_multiplexer::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_trip_multiplexer::enterStateINIT(void){
	m_nECCState = scm_nStateINIT;
	alg_INITIALISE();
	sendOutputEvent( scm_nEventINITOID);
}

void FORTE_trip_multiplexer::enterStateTRIP(void){
	m_nECCState = scm_nStateTRIP;
  	alg_TRIP();
  	sendOutputEvent( scm_nEventCB_TRIPID);
}

void FORTE_trip_multiplexer::enterStateNORMAL(void){
  m_nECCState = scm_nStateNORMAL;
}

void FORTE_trip_multiplexer::enterStateRESET(void){
  m_nECCState = scm_nStateRESET;
  alg_RESET();
  sendOutputEvent( scm_nEventCB_RESETID);
}

void FORTE_trip_multiplexer::executeEvent(int pa_nEIID){
	bool bTransitionCleared;
	do	{
   	bTransitionCleared = true;
    	switch(m_nECCState){
      case scm_nStateSTART:
      	if(scm_nEventINITID == pa_nEIID)
         	enterStateINIT();
        	else
         	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateINIT:
      	if((1))
         	enterStateNORMAL();
        	else
         	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateTRIP:
      	if (scm_nEventRESETID == pa_nEIID)
          	enterStateRESET();
        	else
         	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateNORMAL:
      	if ((scm_nEventTRIP_1ID == pa_nEIID) || (scm_nEventTRIP_2ID == pa_nEIID)
      	    || (scm_nEventTRIP_3ID == pa_nEIID) || (scm_nEventTRIP_4ID == pa_nEIID)
      	    || (scm_nEventTRIP_5ID == pa_nEIID) )
				enterStateTRIP();
        	else
         	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      case scm_nStateRESET:
      	if ((1))
         	enterStateNORMAL();
        	else
         	bTransitionCleared  = false; //no transition cleared
        	break;
        	
      default:
      	DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 4.", m_nECCState.operator TForteUInt16 ());
        	m_nECCState = 0; //0 is always the initial state
        	break;
	}
   pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
	} while(bTransitionCleared);
}


