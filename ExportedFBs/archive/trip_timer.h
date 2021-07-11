/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: trip_timer
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 11/29/2016/gulzha - nxtControl GmbH - Template
 *************************************************************************/

#ifndef _TRIP_TIMER_H_
#define _TRIP_TIMER_H_

#include <iostream>
#include <stdio.h>

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_real.h>

class FORTE_trip_timer: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_trip_timer)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_REAL &time() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_BOOL &operate_in() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_REAL &time_out() {
    return *static_cast<CIEC_REAL*>(getDO(1));
  };

  CIEC_BOOL &operate() {
    return *static_cast<CIEC_BOOL*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventtripID = 1;
  static const TEventID scm_nEventtripTimer_QID = 2;
  static const TEventID scm_nEventstop_trip_timerID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventtrip_outID = 1;
  static const TEventID scm_nEventtrip_timer_startID = 2;
  static const TEventID scm_nEventstop_timerID = 3;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(4, 3, 3, 0, 0);
  void alg_INIT(void);
  void alg_REQ(void);
  void alg_trip_timer_start(void);
  void alg_reset_pulse_internal(void);
  void alg_trip_pulse_timer(void);
  void alg_Trip(void);
  void alg_setVar(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateSample = 2;
  static const TForteInt16 scm_nStatetmrTripPulse = 3;
  static const TForteInt16 scm_nStateStartTimer = 4;
  static const TForteInt16 scm_nStateSTATE2 = 5;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateSample(void);
  void enterStatetmrTripPulse(void);
  void enterStateStartTimer(void);
  void enterStateSTATE2(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_trip_timer(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_trip_timer(){};

};

#endif //close the ifdef sequence from the beginning of the file

