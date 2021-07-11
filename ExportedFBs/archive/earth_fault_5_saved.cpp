/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: earth_fault_5
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 3/23/2016/gulzha - nxtControl GmbH - Template
 *************************************************************************/

#include "earth_fault_5.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "earth_fault_5_gen.cpp"
#endif

using std::cout;

DEFINE_FIRMWARE_FB(FORTE_earth_fault_5, g_nStringIdearth_fault_5)

const CStringDictionary::TStringId FORTE_earth_fault_5::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdpickup_voltage, g_nStringIdvoltage};

const CStringDictionary::TStringId FORTE_earth_fault_5::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdINT, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_earth_fault_5::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdtrip};

const CStringDictionary::TStringId FORTE_earth_fault_5::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_earth_fault_5::scm_anEIWithIndexes[] = {0, 3, -1};
const TDataIOID FORTE_earth_fault_5::scm_anEIWith[] = {0, 1, 255, 0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_earth_fault_5::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRESET};

const TDataIOID FORTE_earth_fault_5::scm_anEOWith[] = {0, 1, 255, 0, 1, 255, 1, 255};
const TForteInt16 FORTE_earth_fault_5::scm_anEOWithIndexes[] = {0, 3, 6, -1};
const CStringDictionary::TStringId FORTE_earth_fault_5::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdRESET_OUT};

const CStringDictionary::TStringId FORTE_earth_fault_5::scm_anInternalsNames[] = {g_nStringIdfault, g_nStringIdtime2};

const CStringDictionary::TStringId FORTE_earth_fault_5::scm_anInternalsTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_earth_fault_5::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

const SInternalVarsInformation FORTE_earth_fault_5::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_earth_fault_5::alg_INIT(void){
	cout << "alg_INIT\n";
	trip() = false;
}

void FORTE_earth_fault_5::alg_REQ(void){
	cout << "alg_REQ\n";
	trip() = true;
}

void FORTE_earth_fault_5::alg_RESET_OUT(void){
	cout << "alg_RESET_OUT\n";
	trip() = false;
}

void FORTE_earth_fault_5::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_earth_fault_5::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_earth_fault_5::enterStateSTATE1(void){
  m_nECCState = scm_nStateSTATE1;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_earth_fault_5::enterStateSTATE3(void){
  m_nECCState = scm_nStateSTATE3;
  sendOutputEvent( scm_nEventRESET_OUTID);
}

void FORTE_earth_fault_5::enterStateSTATE5(void){
  m_nECCState = scm_nStateSTATE5;
  sendOutputEvent( scm_nEventRESET_OUTID);
}

void FORTE_earth_fault_5::enterStateSTATE4(void){
  m_nECCState = scm_nStateSTATE4;
}

void FORTE_earth_fault_5::executeEvent(int pa_nEIID){
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
          enterStateSTATE4();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTATE1:
        //if((((REQ) && (((voltage() < pickup_voltage()))))) || (((REQ) && (((voltage() == pickup_voltage()))))))
        if ( (voltage() < pickup_voltage() ) || (voltage() == pickup_voltage() ) )
          enterStateSTATE3();
        else
        if(scm_nEventRESETID == pa_nEIID)
          enterStateSTATE5();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTATE3:
        if((1))
          enterStateSTATE4();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTATE5:
        if((1))
          enterStateSTATE4();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTATE4:
        //if((REQ) && (((voltage() > pickup_voltage()))))
        if (voltage() > pickup_voltage())
          enterStateSTATE1();
        else
        if(scm_nEventRESETID == pa_nEIID)
          enterStateSTATE5();
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


