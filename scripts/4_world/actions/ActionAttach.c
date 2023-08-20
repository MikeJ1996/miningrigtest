class ActionAttachGpu: ActionSingleUseBase
{
    void ActionAttachGpu() {}

    override string GetText()
    {
        return "Attach GPU";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (!player || !target || !item)
            return false;

        EntityAI targetEntity = EntityAI.Cast(target.GetObject());

        if (!targetEntity || !targetEntity.IsInherited(land_mm_mining_rig) || !item)
            return false;

        land_mm_mining_rig miningRig = land_mm_mining_rig.Cast(targetEntity);

        if (!miningRig)
            return false;

        return true;
    }

    override void OnExecuteServer(ActionData action_data)
    {
        PlayerBase player = action_data.m_Player;
        Object targetObject = action_data.m_Target.GetObject();
        ItemBase gpu = ItemBase.Cast(action_data.m_MainItem);
        land_mm_mining_rig miningRig = land_mm_mining_rig.Cast(targetObject);

        if (miningRig && gpu)
        {
            miningRig.AttachGPU(gpu); // Call the AttachGPU function from land_mm_mining_rig
            action_data.m_Player.MessageStatus("You attached the GPU to the mining rig.");
        }
    }
}