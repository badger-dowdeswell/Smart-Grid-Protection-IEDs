/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: trip_timer
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 11/29/2016/gulzha - nxtControl GmbH - Template
 *************************************************************************/

#include "trip_timer.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "trip_timer_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_trip_timer, g_nStringIdtrip_timer)

const CStringDictionary::TStringId FORTE_trip_timer::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdtime, g_nStringIdoperate_in};

const CStringDictionary::TStringId FORTE_trip_timer::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_trip_timer::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdtime_out, g_nStringIdoperate};

const CStringDictionary::TStringId FORTE_trip_timer::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdBOOL};

const TForteInt16 FORTE_trip_timer::scm_anEIWithIndexes[] = {0, 2, -1, 6};
const TDataIOID FORTE_trip_timer::scm_anEIWith[] = {0, 255, 0, 1, 2, 255, 1, 255};
const CStringDictionary::TStringId FORTE_trip_timer::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdtrip, g_nStringIdtripTimer_Q, g_nStringIdstop_trip_timer};

const TDataIOID FORTE_trip_timer::scm_anEOWith[] = {0, 255, 0, 2, 255, 1, 255};
const TForteInt16 FORTE_trip_timer::scm_anEOWithIndexes[] = {0, 2, 5, -1, -1};
const CStringDictionary::TStringId FORTE_trip_timer::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdtrip_out, g_nStringIdtrip_timer_start, g_nStringIdstop_timer};

const SFBInterfaceSpec FORTE_trip_timer::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

using std::cout;
using std::string;
using std::to_string;

void FORTE_trip_timer::alg_INIT(void){
	cout << "trip_timer\n";
	operate() = false;
	operate_in() = false;
}

void FORTE_trip_timer::alg_REQ(void){
}

void FORTE_trip_timer::alg_trip_timer_start(void){
	time_out() = time();
}

void FORTE_trip_timer::alg_reset_pulse_internal(void){
	operate() = false;
	time_out() = 0;
}

void FORTE_trip_timer::alg_trip_pulse_timer(void){
}

void FORTE_trip_timer::alg_Trip(void){
	// operate := TRUE;
	operate() = operate_in();
}

void FORTE_trip_timer::alg_setVar(void){
}

void FORTE_trip_timer::enterStateSTART(void){
	m_nECCState = scm_nStateSTART;
}

void FORTE_trip_timer::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_trip_timer::enterStateSample(void){
  m_nECCState = scm_nStateSample;
}

void FORTE_trip_timer::enterStatetmrTripPulse(void){
  m_nECCState = scm_nStatetmrTripPulse;
  alg_Trip();
  sendOutputEvent(scm_nEventtrip_outID);
}

void FORTE_trip_timer::enterStateStartTimer(void){
  m_nECCState = scm_nStateStartTimer;
  alg_trip_timer_start();
  sendOutputEvent( scm_nEventtrip_timer_startID);
}

void FORTE_trip_timer::enterStateSTATE2(void){
  m_nECCState = scm_nStateSTATE2;
  sendOutputEvent( scm_nEventstop_timerID);
}

void FORTE_trip_timer::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
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
          enterStateSample();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSample:
        if(scm_nEventtripTimer_QID == pa_nEIID)
          enterStatetmrTripPulse();
        else
        if(scm_nEventtripID == pa_nEIID)
          enterStateStartTimer();
        else
        if(scm_nEventstop_trip_timerID == pa_nEIID)
          enterStateSTATE2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatetmrTripPulse:
        if((1))
          enterStateSample();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateStartTimer:
        if((1))
          enterStateSample();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTATE2:
        if((1))
          enterStateSample();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


