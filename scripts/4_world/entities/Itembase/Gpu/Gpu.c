class Gpu : ItemBase
{
    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionAttachGpu);
    }
}