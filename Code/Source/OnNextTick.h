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
#include <Source/OnNextTick.generated.h>

namespace ScriptCanvas
{
    namespace Nodes
    {
        namespace Wiki
        {
            class OnNextTick : public Node, public AZ::TickBus::Handler
            {
            public:
                ScriptCanvas_Node(OnNextTick,
                    ScriptCanvas_Node::Name("On Next Tick", "Trigger on the next tick after activation")
                    ScriptCanvas_Node::Uuid("{6E104641-A738-4A8B-86C2-0FD0F5A84FDB}")
                    ScriptCanvas_Node::Icon("Editor/Icons/ScriptCanvas/Log.png")
                    ScriptCanvas_Node::Category("Utilities")
                    ScriptCanvas_Node::Version(0)
                );
                void OnInputSignal(const SlotId& slotId) override;
                ScriptCanvas_In(ScriptCanvas_In::Name("In", "Input signal"));
                ScriptCanvas_Out(ScriptCanvas_Out::Name("Out", ""));
				virtual void  OnTick(float deltaTime, AZ::ScriptTimePoint time);
            };
        }
    }
}