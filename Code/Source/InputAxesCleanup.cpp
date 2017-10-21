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
#include "InputAxesCleanup.h"


namespace ScriptCanvas
{
    namespace Nodes
    {
        namespace Wiki
        {
			/*InputAxesCleanup::InputAxesCleanup() 
			{

			}*/

			void InputAxesCleanup::OnInputSignal(const SlotId& slotId)
            {
				float x = InputAxesCleanupProperty::GetXIn(this);
				float y = InputAxesCleanupProperty::GetYIn(this);
				float multiplier = InputAxesCleanupProperty::GetMultiplier(this);
				m_x = x * sqrtf(1 - y * y * 0.5f) * multiplier;
				m_y = y * sqrtf(1 - x * x * 0.5f) * multiplier;
				ScriptCanvas::SlotId pslotId = InputAxesCleanupProperty::GetXAxisSlotId(this);
				Datum o(Data::Type::Number(), Datum::eOriginality::Copy);
				o.Set(m_x);
				if (auto* slot = GetSlot(pslotId))
				{
					PushOutput(o, *slot);
				}
				ScriptCanvas::SlotId pslotIdy = InputAxesCleanupProperty::GetYAxisSlotId(this);
				Datum oy(Data::Type::Number(), Datum::eOriginality::Copy);
				oy.Set(m_y);
				if (auto* slot = GetSlot(pslotIdy))
				{
					PushOutput(oy, *slot);
				}
				SignalOutput(GetSlotId("Out"));
            }
		}
    }
}
#include <Source/InputAxesCleanup.generated.cpp>