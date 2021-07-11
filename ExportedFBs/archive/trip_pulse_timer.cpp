/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: trip_pulse_timer
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 11/29/2016/gulzha - nxtControl GmbH - Template
 *************************************************************************/

#include "trip_pulse_timer.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "trip_pulse_timer_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_trip_pulse_timer, g_nStringIdtrip_pulse_timer)

const CStringDictionary::TStringId FORTE_trip_pulse_timer::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdoperate};

const CStringDictionary::TStringId FORTE_trip_pulse_timer::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_trip_pulse_timer::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdoperate_out};

const CStringDictionary::TStringId FORTE_trip_pulse_timer::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_trip_pulse_timer::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_trip_pulse_timer::scm_anEIWith[] = {0, 255, 0, 1, 255};
const CStringDictionary::TStringId FORTE_trip_pulse_timer::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdtrip};

const TDataIOID FORTE_trip_pulse_timer::scm_anEOWith[] = {0, 255, 1, 255};
const TForteInt16 FORTE_trip_pulse_timer::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_trip_pulse_timer::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdtrip_out};

const SFBInterfaceSpec FORTE_trip_pulse_timer::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

using std::cout;
using std::string;
using std::to_string;

void FORTE_trip_pulse_timer::alg_INIT(void){
	cout << "trip_pulse_timer\n";
	operate() = false;
	operate_out() = false;
}

void FORTE_trip_pulse_timer::alg_REQ(void){
}

void FORTE_trip_pulse_timer::alg_trip(void){
	operate_out() = operate();
}

void FORTE_trip_pulse_timer::alg_reset(void){
	operate_out() = false;
}

void FORTE_trip_pulse_timer::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_trip_pulse_timer::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_trip_pulse_timer::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
}

void FORTE_trip_pulse_timer::enterStateSTATE1(void){
  m_nECCState = scm_nStateSTATE1;
  alg_trip();
  sendOutputEvent( scm_nEventtrip_outID);
}

void FORTE_trip_pulse_timer::executeEvent(int pa_nEIID){
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
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(scm_nEventtripID == pa_nEIID)
          enterStateSTATE1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTATE1:
        if((1))
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 3.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


