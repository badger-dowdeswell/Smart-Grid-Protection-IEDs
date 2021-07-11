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

#ifndef _IED50_51_H_
#define _IED50_51_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_bool.h>
#include <forte_real.h>
#include <forte_string.h>
#include <forte_time.h>
#include <forte_int.h>

class FORTE_IED50_51: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_IED50_51)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &Ipickup_current() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &Icurrent() {
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

  CIEC_STRING &TI() {
    return *static_cast<CIEC_STRING*>(getDI(5));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &trip() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventCLEARID = 2;
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

   FORTE_FB_DATA_ARRAY(3, 6, 1, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_IED50_51){
  };

  virtual ~FORTE_IED50_51(){};

};

#endif //close the ifdef sequence from the beginning of the file

