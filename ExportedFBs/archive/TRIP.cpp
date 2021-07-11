/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: TRIP
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 7/6/2016/gulzha - nxtControl GmbH - Template
 *************************************************************************/

#include "TRIP.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "TRIP_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_TRIP, g_nStringIdTRIP)

const CStringDictionary::TStringId FORTE_TRIP::scm_anDataInputNames[] = {g_nStringIdQI};

const CStringDictionary::TStringId FORTE_TRIP::scm_anDataInputTypeIds[] = {g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_TRIP::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdOPERATE};

const CStringDictionary::TStringId FORTE_TRIP::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_TRIP::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_TRIP::scm_anEIWith[] = {0, 255, 0, 255};
const CStringDictionary::TStringId FORTE_TRIP::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_TRIP::scm_anEOWith[] = {0, 255, 0, 1, 255};
const TForteInt16 FORTE_TRIP::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_TRIP::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_TRIP::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_TRIP::setInitialValues(){
  OPERATE() = true;
}

void FORTE_TRIP::alg_INIT(void){
;
}

void FORTE_TRIP::alg_REQ(void){
;
OPERATE() = true;
}


void FORTE_TRIP::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_TRIP::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_TRIP::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_TRIP::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if((1))
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if((1))
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 2.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


