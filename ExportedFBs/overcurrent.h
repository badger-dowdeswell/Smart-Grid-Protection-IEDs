/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: overcurrent
 *** Description: Template for a simple Basic Function Block Type
 *** Version: 
 ***     1.0: 2021-02-27/badger - null - 
 *************************************************************************/

#ifndef _OVERCURRENT_H_
#define _OVERCURRENT_H_

#include <iostream>
#include <stdio.h>

#include "../Library/Mathlib.h"

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_real.h>
#include <forte_time.h>
#include <forte_int.h>

class FORTE_overcurrent: public CBasicFB{
	DECLARE_FIRMWARE_FB(FORTE_overcurrent)

private:
static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  CIEC_REAL &Ipickup_current() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &current() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_INT &curve_type() {
    return *static_cast<CIEC_INT*>(getDI(2));
  };

  CIEC_REAL &time_dial_setting() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_TIME &min_trip_time() {
    return *static_cast<CIEC_TIME*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &trip() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_TIME &trip_time() {
    return *static_cast<CIEC_TIME*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventRESETID = 2;
  static const TEventID scm_nEventTIME_UPID = 3;
  static const TEventID scm_nEventCLEARID = 4;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventSTART_TIMERID = 2;
  static const TEventID scm_nEventRESET_OUTID = 3;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(4, 5, 2, 0, 0);
  void alg_INIT(void);
  void alg_START_TIMER(void);
  void alg_RESET(void);
  void alg_TRIP(void);
  static const TForteInt16 scm_nStateNORMAL = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateFAULT = 2;
  static const TForteInt16 scm_nStateSTART_TIMER = 3;
  static const TForteInt16 scm_nStateTRIP = 4;
  static const TForteInt16 scm_nStateRESET = 5;

  void enterStateNORMAL(void);
  void enterStateINIT(void);
  void enterStateFAULT(void);
  void enterStateSTART_TIMER(void);
  void enterStateTRIP(void);
  void enterStateRESET(void);

  virtual void executeEvent(int pa_nEIID);
  	
  	bool fault = false;
  
  	Mathlib mathlib; 
  
  	//
   // ANSI Time Overcurrent Curves
   // ============================
	// Overcurrent trip times are determined either
	// by specifying a fixed-time to trip after a 
	// overcurrent is detected, or by applying
	// an appropriate algorithm. 
	//
	// The curve is specified by setting the 
	// curve_type input parameter on the IED87 
	// function block.
  	//
  	enum ANSI_Time_Curves {
		CURVE_TYPE_SHORT_TIME = 0,          // Fixed time specified in milliseconds.		                        
		CURVE_TYPE_NORMAL_INVERSE = 1,      // Normal-inverse curve   
		CURVE_TYPE_VERY_INVERSE = 2,        // Steep expotential curve 
		CURVE_TYPE_EXTREME_INVERSE = 3,     // Variation of the Very Inverse curve
		CURVE_TYPE_LONG_TIME_INVERSE = 4,   // Slow-rising expotential with sharp 
		                                    // high-current slope
		CURVE_TYPE_SHORT_TIME_INVERSE = 5   // Tracks better for shorter time intervals.
	};
	
	//CIEC_TIME calc_trip_time(int time_curve, CIEC_TIME min_trip_time);
	CIEC_TIME calcInverseOvercurrent(int curveType, double Ipickup, double Icurrent, double timeDialSetting); 
		
public:
  	FORTE_overcurrent(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
                     CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
                     0, m_anFBConnData, m_anFBVarsData){
   };

   virtual ~FORTE_overcurrent(){};
};
#endif //close the ifdef sequence from the beginning of the file

