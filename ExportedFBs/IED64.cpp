/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: IED64
 *** Description: Composite Function Block Type
 *** Version: 
 ***     1.0: 24.02.2021/badger - AUT - Redesign of the earth fault IED 
 ***                                    from Gulnara's original design.
 *************************************************************************/

#include "IED64.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "IED64_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_IED64, g_nStringIdIED64)

const CStringDictionary::TStringId FORTE_IED64::scm_anDataInputNames[] = {g_nStringIdpickup_voltage, g_nStringIdvoltage, g_nStringIdtrip_delay_time};

const CStringDictionary::TStringId FORTE_IED64::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdTIME};

const CStringDictionary::TStringId FORTE_IED64::scm_anDataOutputNames[] = {g_nStringIdtrip};

const CStringDictionary::TStringId FORTE_IED64::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_IED64::scm_anEIWithIndexes[] = {0, 2, -1};
const TDataIOID FORTE_IED64::scm_anEIWith[] = {0, 255, 1, 255};
const CStringDictionary::TStringId FORTE_IED64::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdCLEAR};

const TDataIOID FORTE_IED64::scm_anEOWith[] = {0, 255, 0, 255, 0, 255};
const TForteInt16 FORTE_IED64::scm_anEOWithIndexes[] = {0, 2, 4, -1};
const CStringDictionary::TStringId FORTE_IED64::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdRESET_OUT};

const SFBInterfaceSpec FORTE_IED64::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_IED64::setInitialValues(){
  pickup_voltage() = 0;
  voltage() = 0;
  trip() = false;
}


const SCFB_FBInstanceData FORTE_IED64::scm_astInternalFBs[] = {
  {g_nStringIdE_DELAY, g_nStringIdE_DELAY},
  {g_nStringIdearth_fault, g_nStringIdearth_fault},
};

const SCFB_FBConnectionData FORTE_IED64::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdearth_fault, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdearth_fault, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdEO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdearth_fault, g_nStringIdTIME_UP), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCLEAR), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdearth_fault, g_nStringIdCLEAR), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdearth_fault, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdearth_fault, g_nStringIdSTART_TIMER), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTART), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdearth_fault, g_nStringIdRESET_OUT), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTOP), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdearth_fault, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_IED64::scm_astFannedOutEventConnections[] = {
  {6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdRESET_OUT), -1},
};

const SCFB_FBConnectionData FORTE_IED64::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdtrip_delay_time), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdDT), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdpickup_voltage), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdearth_fault, g_nStringIdpickup_voltage), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdvoltage), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdearth_fault, g_nStringIdvoltage), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdearth_fault, g_nStringIdtrip), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdtrip), -1},
};

const SCFB_FBNData FORTE_IED64::scm_stFBNData = {
  2, scm_astInternalFBs,
  8, scm_astEventConnections,
  1, scm_astFannedOutEventConnections,
  4, scm_astDataConnections,
  0, 0,
  0, 0
};


