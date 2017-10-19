#include "precompiled.h"

#include "ScriptCanvasWikiSystemComponent.h"

#include <WikiLibrary.h>

namespace ScriptCanvasWiki
{
    void SystemComponent::Init()
    {
        AZ::EnvironmentVariable<ScriptCanvas::NodeRegistry> nodeRegistryVariable = AZ::Environment::FindVariable<ScriptCanvas::NodeRegistry>(ScriptCanvas::s_nodeRegistryName);
        if (nodeRegistryVariable)
        {
            ScriptCanvas::NodeRegistry& nodeRegistry = nodeRegistryVariable.Get();
            ScriptCanvas::Libraries::Wiki::InitNodeRegistry(nodeRegistry);
        }
    }

    SystemComponent::~SystemComponent()
    {

    }

    void SystemComponent::Reflect(AZ::ReflectContext* context)
    {
        ScriptCanvas::Libraries::Wiki::Reflect(context);
        if (auto serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<SystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<SystemComponent>("Script Canvas Wiki", "Script Canvas Wiki System Component")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    ->Attribute(AZ::Edit::Attributes::Category, "Scripting")
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System", 0xc94d118b))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }
}
