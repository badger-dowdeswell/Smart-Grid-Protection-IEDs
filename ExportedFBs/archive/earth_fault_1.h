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

#ifndef _EARTH_FAULT_1_H_
#define _EARTH_FAULT_1_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_bool.h>
#include <forte_real.h>
#include <forte_time.h>
#include <forte_int.h>

class FORTE_earth_fault_1: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_earth_fault_1)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &voltage() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_INT &pickup_voltage() {
    return *static_cast<CIEC_INT*>(getDI(1));
  };

  CIEC_TIME &DT2() {
    return *static_cast<CIEC_TIME*>(getDI(2));
  };

  CIEC_TIME &DT1() {
    return *static_cast<CIEC_TIME*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &trip() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventRESETID = 2;
  static const TEventID scm_nEventCLEARID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventRESET_OUTID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(3, 4, 1, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBParameter scm_astParamters[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_earth_fault_1){
  };

  virtual ~FORTE_earth_fault_1(){};

};

#endif //close the ifdef sequence from the beginning of the file

