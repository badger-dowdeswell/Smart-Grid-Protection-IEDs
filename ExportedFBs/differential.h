/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: differential
 *** Description: Restrained differential protection device
 *** Version: 
 ***     1.0: 2021-03-23/Badger - AUT EMSOFT - 
 *************************************************************************/

#ifndef _DIFFERENTIAL_H_
#define _DIFFERENTIAL_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_real.h>
#include <forte_time.h>

#include <iostream>
#include <stdio.h>

class FORTE_differential: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_differential)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  CIEC_TIME &poll_time() {
    return *static_cast<CIEC_TIME*>(getDI(0));
  };

  CIEC_REAL &differential_percentage() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &Icurrent_1() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &Icurrent_2() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_TIME &poll_time_set() {
    return *static_cast<CIEC_TIME*>(getDO(0));
  };

  CIEC_BOOL &trip() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventRESETID = 2;
  static const TEventID scm_nEventPOLLID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventSTART_POLLID = 2;
  static const TEventID scm_nEventSTOP_POLLID = 3;
  static const TEventID scm_nEventRESET_OUTID = 4;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(5, 4, 2, 0, 0);
  void alg_initialize(void);
  void alg_START_TIMER(void);
  void alg_REQ(void);
  void alg_POLL(void);
  void alg_RESET(void);
  void alg_TRIP(void);
  
  bool alg_differential(CIEC_REAL differential_percentage, CIEC_REAL Icurrent_1, CIEC_REAL Icurrent_2);
  
  static const TForteInt16 scm_nStateNORMAL = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateREQ = 2;
  static const TForteInt16 scm_nStatePOLL = 3;
  static const TForteInt16 scm_nStateTRIP = 4;
  static const TForteInt16 scm_nStateRESET = 5;

  void enterStateNORMAL(void);
  void enterStateInit(void);
  void enterStateREQ(void);
  void enterStatePOLL(void);
  void enterStateTRIP(void);
  void enterStateRESET(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_differential(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_differential(){};

};

#endif //close the ifdef sequence from the beginning of the file

