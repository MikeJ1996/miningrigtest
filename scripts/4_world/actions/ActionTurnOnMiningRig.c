class ActionSwitchPowerToMiningRig: ActionInteractBase {
    void ActionTurnOnMiningRig() {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_Text = "Turn On";
    }

    override void OnActionInfoUpdate(PlayerBase player, ActionTarget target, ItemBase item) {
        land_mm_mining_rig miningRig = land_mm_mining_rig.Cast(target.GetObject());
        if (miningRig.GetCompEM().IsSwitchedOn())
            m_Text = "Turn Off";
        else
            m_Text = "Turn On";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        land_mm_mining_rig miningRig = land_mm_mining_rig.Cast(target.GetObject());
        if (miningRig)
            return true;
        return false;
    }

    override void OnExecuteServer(ActionData action_data) {
        land_mm_mining_rig miningRig = land_mm_mining_rig.Cast(action_data.m_Target.GetObject());
        if (miningRig) {
            if (!miningRig.GetCompEM().IsSwitchedOn()) {
                if (!miningRig.HasEnergyManager()) {
                    return;
                }

                if (!miningRig.GetCompEM().CanSwitchOn() || !miningRig.GetCompEM().CanWork()) {
                    return;
                }

                if (GetGame().IsServer()) {
                    miningRig.GetCompEM().SwitchOn();
                }
            } else {
                if (GetGame().IsServer()) {
                    miningRig.GetCompEM().SwitchOff();
                }
            }
        }
    }
};