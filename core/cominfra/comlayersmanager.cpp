/*******************************************************************************
  * Copyright (c) 2010, 2011 ACIN and Profactor GmbH.
  * All rights reserved. This program and the accompanying materials
  * are made available under the terms of the Eclipse Public License v1.0
  * which accompanies this distribution, and is available at
  * http://www.eclipse.org/legal/epl-v10.html
  *
  * Contributors:
  *    Alois Zoitl - initial implementation and rework communication infrastructure
  *    Ingo Hegny - moved encoding of adapter-event-ids to a single point
  *    Michael Hofmann - rework communication infrastructure
  *******************************************************************************/
#include <fortenew.h>
#include "comlayersmanager.h"
#include "basecommfb.h"
#include <string.h>

#include<fbdkasn1layer.h>
#include<ipcomlayer.h>
#include<localcomlayer.h>
#include<rawdatacomlayer.h>


using namespace forte::com_infra;

CComLayer* CComLayersManager::createCommunicationLayer(char *pa_acLayerIdentifier, CComLayer* pa_poUpperLayer, CBaseCommFB * pa_poComFB){
  CComLayer* m_poNewLayer = 0;
  if(0 == strcmp("fbdk", pa_acLayerIdentifier)){
    m_poNewLayer = new CFBDKASN1ComLayer(pa_poUpperLayer, pa_poComFB);
  }
  else if(0 == strcmp("ip", pa_acLayerIdentifier)){
    m_poNewLayer = new CIPComLayer(pa_poUpperLayer, pa_poComFB);
  }
  else if(0 == strcmp("loc", pa_acLayerIdentifier)){
    m_poNewLayer = new CLocalComLayer(pa_poUpperLayer, pa_poComFB);
  }
  else if(0 == strcmp("raw", pa_acLayerIdentifier)){
    m_poNewLayer = new CRawDataComLayer(pa_poUpperLayer, pa_poComFB);
  }


  return m_poNewLayer;
}
