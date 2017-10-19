#pragma once

#include <AzCore/Module/Module.h>
#include <AzCore/Module/Environment.h>

namespace ScriptCanvasWiki
{
    class Module
        : public AZ::Module
    {
    public:
        AZ_RTTI(Module, "{95F5CB8E-C24B-450B-9C81-76BC287D6175}", AZ::Module);

        Module();

        AZ::ComponentTypeList GetRequiredSystemComponents() const override;
    };
}