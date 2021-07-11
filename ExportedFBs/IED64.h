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

#ifndef _IED64_H_
#define _IED64_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_bool.h>
#include <forte_real.h>
#include <forte_time.h>

class FORTE_IED64: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_IED64)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &pickup_voltage() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &voltage() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_TIME &trip_delay_time() {
    return *static_cast<CIEC_TIME*>(getDI(2));
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

   FORTE_FB_DATA_ARRAY(3, 3, 1, 0);

virtual void setInitialValues();

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_IED64){
  };

  virtual ~FORTE_IED64(){};
};

#endif //close the ifdef sequence from the beginning of the file

