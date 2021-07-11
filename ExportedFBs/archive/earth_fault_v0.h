/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: earth_fault
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 3/23/2016/gulzha - nxtControl GmbH - Template
 ***     1.0: 22/02/2021/Badger - 4diac - Refactored and migrated to 4diac
 *************************************************************************/

#ifndef _EARTH_FAULT_H_
#define _EARTH_FAULT_H_

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_real.h>
#include <forte_int.h>

#include "../Library/Mathlib.h"

class FORTE_earth_fault: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_earth_fault)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  CIEC_REAL &pickup_voltage() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &voltage() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  CIEC_BOOL &trip() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventRESETID = 2;
  static const TEventID scm_nEventTIME_UPID = 3;
  static const TEventID scm_nEventCLEARID = 4;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TEventID scm_nEventSTART_TIMERID = 1;
  static const TEventID scm_nEventRESET_OUTID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  
  CIEC_BOOL &fault() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(3, 2, 1, 1, 0);
  void alg_INIT(void);
  void alg_REQ(void);
  void alg_RESET(void);
  void alg_START_TIMER(void);
  void alg_TRIP(void);
  static const TForteInt16 scm_nStateNORMAL = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateFAULT = 2;
  static const TForteInt16 scm_nStateTRIP = 3;
  static const TForteInt16 scm_nStateRESET = 4;
  static const TForteInt16 scm_nStateSTART_TIMER = 5;

  void enterStateNORMAL(void);
  void enterStateINIT(void);
  void enterStateFAULT(void);
  void enterStateTRIP(void);
  void enterStateRESET(void);
  void enterStateSTART_TIMER(void);

  virtual void executeEvent(int pa_nEIID);
  
  Mathlib mathlib; 

public:
  FORTE_earth_fault(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_earth_fault(){};
};
#endif //close the ifdef sequence from the beginning of the file

