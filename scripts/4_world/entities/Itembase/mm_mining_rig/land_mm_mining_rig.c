class land_mm_mining_rig : Inventory_Base
{
    private const string SOUND_MiningRig_START = "MiningRig_START_SoundSet";
    private const string SOUND_MiningRig_STOP = "MiningRig_STOP_SoundSet";
    private const string SOUND_MiningRig_MINED = "MiningRig_MINED_SoundSet";

    private EffectSound m_StartSound;
    private EffectSound m_StopSound;
    private EffectSound m_MinedSound;

    private bool m_IsMining = false;
    private bool m_IsDamaged = false;
    private float m_SuccessChance = 0.5;
    private int m_DamageChance = 50;
    private float m_DamagePercent = 0.1;
    private float m_MineInterval = 5.0;

    private ref Timer m_MiningTimer;

    void land_mm_mining_rig()
    {
        RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
        m_MiningTimer = new Timer(CALL_CATEGORY_SYSTEM);
    }

    private void PlayStartSound()
    {
        PlaySoundSet(m_StartSound, SOUND_MiningRig_START, 0.1, 0.1);
    }

    private void PlayStopSound()
    {
        PlaySoundSet(m_StopSound, SOUND_MiningRig_STOP, 0.1, 0.1);
    }

    private void PlayMinedSound()
    {
        PlaySoundSet(m_MinedSound, SOUND_MiningRig_MINED, 0.1, 0.1);
    }

    override void OnWorkStart()
    {
        PlayStartSound();
        StartMining();
    }

    override void OnWork(float consumed_energy)
    {
        super.OnWork(consumed_energy);

        if (m_IsMining && m_MiningTimer)
        {
            m_MiningTimer.Run(m_MineInterval, this, "Mine", null, true);
        }
    }

    override void OnWorkStop()
    {
        PlayStopSound();
        StopMining();
    }

    private void StartMining()
    {
        if (!m_IsMining)
        {
            m_IsMining = true;
            m_MiningTimer.Run(m_MineInterval, this, "Mine", null, true);
        }
    }

    private void StopMining()
    {
        if (m_IsMining)
        {
            m_IsMining = false;
            m_MiningTimer.Stop();
        }
    }

    private void Mine()
    {
        if (GetCompEM().IsWorking() && m_SuccessChance > Math.RandomFloat(0, 1))
        {
            IncrementCoin();
            PlayMinedSound();

            if (Math.RandomInt(0, 100) <= m_DamageChance && !m_IsDamaged)
            {
                DamageGPU();
                m_IsDamaged = true;
            }
        }
    }

    

    void AttachGPU(ItemBase gpu)
    {
        if (gpu && gpu.IsInherited(Gpu) && !GetGame().IsMultiplayer())
        {
            int emptySlotIndex = -1;
            for (int i = 0; i < 10; i++)
            {
                string attachmentSlot = "Gpu" + (i + 1);
                if (!FindAttachmentBySlotName(attachmentSlot))
                {
                    emptySlotIndex = i;
                    break;
                }
            }

            if (emptySlotIndex >= 0)
            {
                string availableAttachmentSlot = "Gpu" + (emptySlotIndex + 1);
                TakeEntityAsAttachmentEx(gpu, availableAttachmentSlot);
                Print("Attached GPU to slot: " + availableAttachmentSlot);
            }
            else
            {
                Print("No empty GPU slots available.");
            }
        }
        else
        {
            Print("Invalid GPU item or multiplayer mode.");
        }
    }
    
private void TakeEntityAsAttachmentEx(EntityAI entity, string slotName)
{
    if (entity && GetInventory())
    {
        InventoryLocation loc = Gpu;
        if (GetInventory().FindFreeLocationFor(entity, FindInventoryLocationType.ANY, loc))
        {
            if (loc.IsValid())
            {
                InventorySlots slotId = Slots.GetSlotIdFromString(Gpu); // Correct placement
                InventoryLocation attachmentLoc = new InventoryLocation;
                attachmentLoc.Copy(loc);
                attachmentLoc.SetParent(GetInventory());
                attachmentLoc.SetAttachment(slotId);
                if (!GetInventory().LocationSyncMoveEntity(attachmentLoc, entity))
                {
                    Error("land_mm_mining_rig: Failed to attach entity to slot: " + slotName);
                }
            }
            else
            {
                Error("land_mm_mining_rig: Failed to get valid location for attachment.");
            }
        }
        else
        {
            Error("land_mm_mining_rig: No free location for attachment.");
        }
    }
}


    private void DamageGPU()
    {
        for (int i = 1; i <= 10; i++)
        {
            string attachmentSlot = "Gpu" + i;
            int slotId = InventorySlots.GetSlotIdFromString(attachmentSlot);
            ItemBase gpuItem = ItemBase.Cast(GetInventory().FindAttachment(slotId));

            if (gpuItem && !gpuItem.IsRuined())
            {
                gpuItem.DecreaseHealth("", "", gpuItem.GetMaxHealth("", "") * m_DamagePercent);
                m_IsDamaged = true;
                return;
            }
        }
    }

    private void IncrementCoin()
    {
        ItemBase bitcoin = ItemBase.Cast(FindAttachmentBySlotName("bitcoin"));
        if (bitcoin)
        {
            bitcoin.AddQuantity(1);
        }
    }

override void SetActions() {
    super.SetActions();
    AddAction(ActionSwitchPowerToMiningRig);
    AddAction(ActionAttachGpu); // Add the ActionAttachGpu action
    // Add other actions if needed
}

    bool CanMine()
    {
        if (!GetCompEM().CanWork())
        {
            return false;
        }
        return true;
    }
}