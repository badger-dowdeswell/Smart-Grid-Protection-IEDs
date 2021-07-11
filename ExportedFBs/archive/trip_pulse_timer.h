/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: trip_pulse_timer
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 11/29/2016/gulzha - nxtControl GmbH - Template
 *************************************************************************/

#ifndef _TRIP_PULSE_TIMER_H_
#define _TRIP_PULSE_TIMER_H_

#include <iostream>
#include <stdio.h>

#include <basicfb.h>
#include <forte_bool.h>

class FORTE_trip_pulse_timer: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_trip_pulse_timer)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_BOOL &operate() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_BOOL &operate_out() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventtripID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventtrip_outID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(2, 2, 2, 0, 0);
  void alg_INIT(void);
  void alg_REQ(void);
  void alg_trip(void);
  void alg_reset(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateREQ = 2;
  static const TForteInt16 scm_nStateSTATE1 = 3;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateREQ(void);
  void enterStateSTATE1(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_trip_pulse_timer(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_trip_pulse_timer(){};

};

#endif //close the ifdef sequence from the beginning of the file

