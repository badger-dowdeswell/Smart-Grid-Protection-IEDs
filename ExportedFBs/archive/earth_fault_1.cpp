/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: earth_fault_1
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 3/23/2016/gulzha - nxtControl GmbH - template
 *************************************************************************/

#include "earth_fault_1.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "earth_fault_1_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_earth_fault_1, g_nStringIdearth_fault_1)

const CStringDictionary::TStringId FORTE_earth_fault_1::scm_anDataInputNames[] = {g_nStringIdvoltage, g_nStringIdpickup_voltage, g_nStringIdDT2, g_nStringIdDT1};

const CStringDictionary::TStringId FORTE_earth_fault_1::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdINT, g_nStringIdTIME, g_nStringIdTIME};

const CStringDictionary::TStringId FORTE_earth_fault_1::scm_anDataOutputNames[] = {g_nStringIdtrip};

const CStringDictionary::TStringId FORTE_earth_fault_1::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_earth_fault_1::scm_anEIWithIndexes[] = {0, 5, -1, -1};
const TDataIOID FORTE_earth_fault_1::scm_anEIWith[] = {1, 0, 3, 2, 255, 1, 0, 255};
const CStringDictionary::TStringId FORTE_earth_fault_1::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRESET, g_nStringIdCLEAR};

const TDataIOID FORTE_earth_fault_1::scm_anEOWith[] = {0, 255, 0, 255, 0, 255};
const TForteInt16 FORTE_earth_fault_1::scm_anEOWithIndexes[] = {0, 2, 4, -1};
const CStringDictionary::TStringId FORTE_earth_fault_1::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdRESET_OUT};

const SFBInterfaceSpec FORTE_earth_fault_1::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_earth_fault_1::scm_astInternalFBs[] = {
  {g_nStringIdFB2, g_nStringIdE_DELAY},
  {g_nStringIdFB3, g_nStringIdE_DELAY},
  {g_nStringIdFB1, g_nStringIdearth_fault},
};

const SCFB_FBParameter FORTE_earth_fault_1::scm_astParamters[] = {
  {2, g_nStringIdQI, "TRUE"},
};

const SCFB_FBConnectionData FORTE_earth_fault_1::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdSTART_TIMER), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB2, g_nStringIdSTART), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdRESET_OUT), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB2, g_nStringIdSTOP), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdSTART_TIMER_2), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB3, g_nStringIdSTART), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB2, g_nStringIdEO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdTIME_UP), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB3, g_nStringIdEO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdTIME_UP_2), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdINIT), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdINITO), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRESET), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdRESET), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCLEAR), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdCLEAR), 2},
};

const SCFB_FBFannedOutConnectionData FORTE_earth_fault_1::scm_astFannedOutEventConnections[] = {
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB3, g_nStringIdSTOP), 1},
  {1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRESET_OUT), -1},
};

const SCFB_FBConnectionData FORTE_earth_fault_1::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdpickup_voltage), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdpickup_voltage), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdvoltage), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdvoltage), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB1, g_nStringIdtrip), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdtrip), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdDT1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB2, g_nStringIdDT), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdDT2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdFB3, g_nStringIdDT), 1},
};

const SCFB_FBNData FORTE_earth_fault_1::scm_stFBNData = {
  3, scm_astInternalFBs,
  11, scm_astEventConnections,
  2, scm_astFannedOutEventConnections,
  5, scm_astDataConnections,
  0, 0,
  1, scm_astParamters
};


