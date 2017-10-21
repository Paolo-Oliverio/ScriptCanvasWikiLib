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

#pragma once
#include <ScriptCanvas/CodeGen/CodeGen.h>
#include <ScriptCanvas/Core/Node.h>
#include <AzCore/Component/TickBus.h>
#include <Source/InputAxesCleanup.generated.h>

namespace ScriptCanvas
{
    namespace Nodes
    {
        namespace Wiki
        {
            class InputAxesCleanup : public Node
            {
            public:
				//InputAxesCleanup();
                ScriptCanvas_Node(InputAxesCleanup,
                    ScriptCanvas_Node::Name("InputAxesCleanup", "Input Axes Cleanup")
                    ScriptCanvas_Node::Uuid("{97F4FDD4-A93C-41A2-8F12-07B653C4143A}")
                    ScriptCanvas_Node::Icon("Editor/Icons/ScriptCanvas/Log.png")
                    ScriptCanvas_Node::Category("Input")
                    ScriptCanvas_Node::Version(0)
                );
                void OnInputSignal(const SlotId& slotId) override;
                ScriptCanvas_In(ScriptCanvas_In::Name("In", "Input signal"));
                ScriptCanvas_Out(ScriptCanvas_Out::Name("Out", ""));

				ScriptCanvas_Property(float,
					ScriptCanvas_Property::Name("X In", "The time this node will remain active.")
					ScriptCanvas_Property::Input);
				ScriptCanvas_Property(float,
					ScriptCanvas_Property::Name("Y In", "The time this node will remain active.")
					ScriptCanvas_Property::Input);
				ScriptCanvas_Property(float, ScriptCanvas_Property::Name("Multiplier", "X Axis Value")
					ScriptCanvas_Property::Input
				);

				ScriptCanvas_Property(float, ScriptCanvas_Property::Name("X Axis", "X Axis Value")
					ScriptCanvas_Property::Output
					ScriptCanvas_Property::OutputStorageSpec
					ScriptCanvas_Property::Visibility(false)
					ScriptCanvas_Property::Transient
				);
					
				ScriptCanvas_Property(float, ScriptCanvas_Property::Name("Y Axis", "Y Axis Value")
					ScriptCanvas_Property::Output
					ScriptCanvas_Property::OutputStorageSpec
					ScriptCanvas_Property::Visibility(false)
					ScriptCanvas_Property::Transient
				);
					float m_x, m_y;
            };
        }
    }
}