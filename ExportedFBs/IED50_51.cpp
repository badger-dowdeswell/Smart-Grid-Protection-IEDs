/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: IED50_51
 *** Description: Overcurrent Protection IED type 50 and 51
 *** Version: 
 ***     1.0: 2021-03-01/badger - null - 
 *************************************************************************/

#include "IED50_51.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "IED50_51_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_IED50_51, g_nStringIdIED50_51)

const CStringDictionary::TStringId FORTE_IED50_51::scm_anDataInputNames[] = {g_nStringIdIpickup_current, g_nStringIdIcurrent, g_nStringIdcurve_type, g_nStringIdtime_dial_setting, g_nStringIdmin_trip_time, g_nStringIdTI};

const CStringDictionary::TStringId FORTE_IED50_51::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdINT, g_nStringIdREAL, g_nStringIdTIME, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_IED50_51::scm_anDataOutputNames[] = {g_nStringIdtrip};

const CStringDictionary::TStringId FORTE_IED50_51::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_IED50_51::scm_anEIWithIndexes[] = {0, 5, -1};
const TDataIOID FORTE_IED50_51::scm_anEIWith[] = {0, 4, 3, 2, 255, 1, 255};
const CStringDictionary::TStringId FORTE_IED50_51::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdCLEAR};

const TDataIOID FORTE_IED50_51::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_IED50_51::scm_anEOWithIndexes[] = {-1, 0, -1, -1};
const CStringDictionary::TStringId FORTE_IED50_51::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdRESET_OUT};

const SFBInterfaceSpec FORTE_IED50_51::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  6,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_IED50_51::scm_astInternalFBs[] = {
  {g_nStringIdovercurrent, g_nStringIdovercurrent},
  {g_nStringIdE_DELAY, g_nStringIdE_DELAY},
};

const SCFB_FBConnectionData FORTE_IED50_51::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCLEAR), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdCLEAR), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdSTART_TIMER), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTART), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdRESET_OUT), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTOP), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdEO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdTIME_UP), 0},
};

const SCFB_FBFannedOutConnectionData FORTE_IED50_51::scm_astFannedOutEventConnections[] = {
  {4, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRESET_OUT), -1},
};

const SCFB_FBConnectionData FORTE_IED50_51::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIpickup_current), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdIpickup_current), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIcurrent), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdcurrent), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdcurve_type), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdcurve_type), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdtime_dial_setting), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdtime_dial_setting), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdmin_trip_time), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdmin_trip_time), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdtrip_time), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdDT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdovercurrent, g_nStringIdtrip), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdtrip), -1},
};

const SCFB_FBNData FORTE_IED50_51::scm_stFBNData = {
  2, scm_astInternalFBs,
  8, scm_astEventConnections,
  1, scm_astFannedOutEventConnections,
  7, scm_astDataConnections,
  0, 0,
  0, 0
};


