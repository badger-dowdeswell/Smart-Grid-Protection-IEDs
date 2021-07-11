/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: trip_multiplexer
 *** Description: Template for a simple Basic Function Block Type
 *** Version: 
 ***     1.0: 2021-02-26/badger - 
 *************************************************************************/

#ifndef _TRIP_MULTIPLEXER_H_
#define _TRIP_MULTIPLEXER_H_

#include <basicfb.h>
#include <iostream>
#include <stdio.h>

class FORTE_trip_multiplexer: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_trip_multiplexer)

private:
  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventTRIP_1ID = 1;
  static const TEventID scm_nEventTRIP_2ID = 2;
  static const TEventID scm_nEventTRIP_3ID = 3;
  static const TEventID scm_nEventTRIP_4ID = 4;
  static const TEventID scm_nEventTRIP_5ID = 5;
  static const TEventID scm_nEventRESETID = 6;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCB_TRIPID = 1;
  static const TEventID scm_nEventCB_RESETID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

	FORTE_BASIC_FB_DATA_ARRAY(3, 0, 0, 0, 0);
   
  void alg_INITIALISE(void);
  void alg_TRIP(void);
  void alg_RESET(void);
  
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateTRIP = 2;
  static const TForteInt16 scm_nStateNORMAL = 3;
  static const TForteInt16 scm_nStateRESET = 4;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateTRIP(void);
  void enterStateNORMAL(void);
  void enterStateRESET(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_trip_multiplexer(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_trip_multiplexer(){};
};
#endif //close the ifdef sequence from the beginning of the file

