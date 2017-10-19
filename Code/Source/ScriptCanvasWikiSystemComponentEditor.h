#pragma once

#include <AzCore/Component/Component.h>

#include <CryCommon/IRenderer.h>
#include <CrySystemBus.h>

struct ISystem;

namespace ScriptCanvasWiki
{
    class SystemComponent
        : public AZ::Component
        , public IRenderDebugListener
        , private CrySystemEventBus::Handler
    {
    public:
        AZ_COMPONENT(SystemComponent, "{6A83B0E7-EB47-48B5-910D-4881E429AC9D}");

        static void Reflect(AZ::ReflectContext* context);

        SystemComponent() = default;
        ~SystemComponent() override;
        void Init() override;

        void Activate() override;
        void Deactivate() override;

        // IRenderDebugListener
        void OnDebugDraw() override;

    private:

        ISystem* m_system;

        // CrySystemEventBus
        void OnCrySystemInitialized(ISystem& system, const SSystemInitParams& systemInitParams) override;
        void OnCrySystemShutdown(ISystem& system) override;

    };
}