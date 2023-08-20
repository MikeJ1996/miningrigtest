class land_mm_mining_rig_kit: Container_Base
{
	void land_mm_mining_rig_kit()
	{
		
	}
    override bool CanPutInCargo(EntityAI parent)
    {
        return false;
    }
    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }
	string GetConstructionKitType()
	{
		return "land_mm_mining_rig";
	}
};