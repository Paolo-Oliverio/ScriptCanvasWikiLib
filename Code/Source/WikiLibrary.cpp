#include "precompiled.h"
#include <WikiLibrary.h>
#include "OnNextTick.h"
#include <ScriptCanvas/Libraries/Libraries.h>

namespace ScriptCanvas
{
    namespace Libraries
    {
        void Wiki::Reflect(AZ::ReflectContext* reflection)
        {
            AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(reflection);
            if (serializeContext)
            {
                serializeContext->Class<Wiki, Library::LibraryDefinition>()
                    ->Version(1)
                    ;

                AZ::EditContext* editContext = serializeContext->GetEditContext();
                if (editContext)
                {
                    editContext->Class<Wiki>("Wiki", "")->
                        ClassElement(AZ::Edit::ClassElements::EditorData, "")->
                        Attribute(AZ::Edit::Attributes::Icon, "Editor/Icons/ScriptCanvas/Debug.png")
                        ;
                }
            }
        }

        void Wiki::InitNodeRegistry(NodeRegistry& nodeRegistry)
        {
            Library::AddNodeToRegistry<Wiki, Nodes::Wiki::OnNextTick>(nodeRegistry);
        }

        AZStd::vector<AZ::ComponentDescriptor*> Wiki::GetComponentDescriptors()
        {
            return AZStd::vector<AZ::ComponentDescriptor*>({
                Nodes::Wiki::OnNextTick::CreateDescriptor(),
            });
        }
    }
}