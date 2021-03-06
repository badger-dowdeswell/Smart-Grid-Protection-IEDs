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

#ifndef _VOLTAGE_A_TO_D_H_
#define _VOLTAGE_A_TO_D_H_

#include <iostream>
#include <stdio.h>

#include <funcbloc.h>
#include <forte_real.h>

class FORTE_VOLTAGE_A_TO_D: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_VOLTAGE_A_TO_D)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  CIEC_REAL &voltage() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  CIEC_REAL &VRMS() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 1, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_VOLTAGE_A_TO_D){
  };

  virtual ~FORTE_VOLTAGE_A_TO_D(){};

};

#endif //close the ifdef sequence from the beginning of the file

