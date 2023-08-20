class CfgPatches
{
	class Gpu
	{
		units[] = {"Gpu","land_mm_mining_rig"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Gear_Tools","DZ_Gear_Crafting","DZ_Gear_Consumables","DZ_Gear_Cultivation","DZ_Characters"};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Gpu : Inventory_Base
	{
		scope = 2;
		displayName = "AMD GPU";
		descriptionShort = "This is an AMD GPU that is used for the Mining Rack.";
		model = "mm_mining_rig\data\GPU\GPU.p3d";
		hiddenSelections[] = {"5600XT","Fan1", "Fan2", "GPU_Plate", "GPU_Rad"};
		rotationFlags = 17;
		isMeleeWeapon = 1;
		weight = 400;
		itemSize[] = {2, 2};
		inventorySlot[]= {"Gpu1","Gpu2","Gpu3","Gpu4","Gpu5","Gpu6","Gpu7","Gpu8","Gpu9","Gpu10"};
		quantityBar = 1;
		canBeSplit = 0;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 1;
		varQuantityDestroyOnMin = 1;
		destroyOnEmpty = 1;
		
		class EnergyManager
		{
			hasIcon=1;
			isPassiveDevice = 1; // The GPU doesn't consume energy actively
			energyStorageMax = 1000; // Maximum energy capacity
			energyUsagePerSecond = 0.0; // Energy consumption per second when active (set to 0 for passive devices)
			energyAtSpawn = 1000; // Starting energy value
			reduceMaxEnergyByDamageCoef = 1.0; // Damage does not affect energy capacity
			powerSocketsCount = 0; // GPUs don't have power sockets
			plugType = 0; // No plug type since GPUs are passive devices
			compatiblePlugTypes[] = {}; // No compatible plug types
			
			class PassiveDevices
			{
				class Gpu_Passive
				{
					powerOutput = 30.0; // Energy generation per second
					displayName = "GPU Power Generation"; // Display name for energy generation
					icon = ""; // Icon path for energy generation (if desired)
				};
			};
		};
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "pickUpPaper_SoundSet";
					id = 797;
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 4000;
					healthLevels[] = {
					{1,{"DZ\gear\consumables\data\Loot_Paper.rvmat"}},
					{0.7,{"DZ\gear\consumables\data\Loot_Paper.rvmat"}},
					{0.5,{"DZ\gear\consumables\data\Loot_Paper_damage.rvmat"}},
					{0.3,{"DZ\gear\consumables\data\Loot_Paper_damage.rvmat"}},
					{0,{"DZ\gear\consumables\data\Loot_Paper_destruct.rvmat"}}
				};
			};
		};
	};
};