/*******************************************************************************
  * Copyright (c) 2017 fortiss GmbH 
  * All rights reserved. This program and the accompanying materials
  * are made available under the terms of the Eclipse Public License v1.0
  * which accompanies this distribution, and is available at
  * http://www.eclipse.org/legal/epl-v10.html
  *
  * Contributors:
  *    Jose Cabral - initial implementation and rework handler infrastructure
  *******************************************************************************/

#include <devexec.h>

#include <timerha.h>
#include <sockhand.h>


const size_t CTimerHandler::mHandlerIdentifier = 0;
const size_t CFDSelectHandler::mHandlerIdentifier = 1;
 

void CDeviceExecution::createHandlers(CDeviceExecution& paDeviceExecution){

  paDeviceExecution.mRegisteredEventHandlers[0].mHandler = CTimerHandler::createTimerHandler(paDeviceExecution);
  paDeviceExecution.mRegisteredEventHandlers[1].mHandler = new CFDSelectHandler(paDeviceExecution);

}
