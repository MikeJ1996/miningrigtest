modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert(ActionSwitchPowerToMiningRig);
        actions.Insert(ActionAttachGpu); // Use the correct action name here
        
        // Add any other custom actions you have
    }
}