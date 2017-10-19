/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/

#include "precompiled.h"
#include "OnNextTick.h"

namespace ScriptCanvas
{
    namespace Nodes
    {
        namespace Wiki
        {
			void OnNextTick::OnInputSignal(const SlotId& slotId)
            {
				AZ::TickBus::Handler::BusConnect();
            }

			void OnNextTick::OnTick(float deltaTime, AZ::ScriptTimePoint time)
			{
				AZ::TickBus::Handler::BusDisconnect();
				SignalOutput(GetSlotId("Out"));
			}

		}
    }
}

#include <Source/OnNextTick.generated.cpp>
