/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: VOLTAGE_A_TO_D
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     1.0: 2021-07-01/Badger - AUT EMSOFT - 
 *************************************************************************/

#include "VOLTAGE_A_TO_D.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "VOLTAGE_A_TO_D_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_VOLTAGE_A_TO_D, g_nStringIdVOLTAGE_A_TO_D)

const CStringDictionary::TStringId FORTE_VOLTAGE_A_TO_D::scm_anDataInputNames[] = {g_nStringIdvoltage};

const CStringDictionary::TStringId FORTE_VOLTAGE_A_TO_D::scm_anDataInputTypeIds[] = {g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_VOLTAGE_A_TO_D::scm_anDataOutputNames[] = {g_nStringIdVRMS};

const CStringDictionary::TStringId FORTE_VOLTAGE_A_TO_D::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_VOLTAGE_A_TO_D::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_VOLTAGE_A_TO_D::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_VOLTAGE_A_TO_D::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_VOLTAGE_A_TO_D::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_VOLTAGE_A_TO_D::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_VOLTAGE_A_TO_D::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_VOLTAGE_A_TO_D::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

using std::cout;

//
// executeEvent()
// ==============
void FORTE_VOLTAGE_A_TO_D::executeEvent(int pa_nEIID){
	switch(pa_nEIID){
   case scm_nEventINITID:
   	break;
   	
	case scm_nEventREQID:
		cout << "\nFORTE_VOLTAGE_A_TO_D CNF\n";
		VRMS() = voltage();
		sendOutputEvent(scm_nEventCNFID);
   	break;
	}
}



