modded class Hologram
{
	override string ProjectionBasedOnParent()
	{
		land_mm_mining_rig_kit item_in_hands = land_mm_mining_rig.Cast(m_Player.GetHumanInventory().GetEntityInHands());

		if (item_in_hands)
		{
			return item_in_hands.land_mm_mining_rig_Holo();
		}

		return super.ProjectionBasedOnParent();
	}

	override void EvaluateCollision(ItemBase action_item = null)
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());

		if (item_in_hands && item_in_hands.IsInherited(land_mm_mining_rig))
		{
			SetIsColliding(false);
			return;
		}

		super.EvaluateCollision();
	}
}