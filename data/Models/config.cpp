class CfgPatches
{
	class land_mm_mining_rig
	{
		units[] = {"land_mm_mining_rig","land_mm_mining_rig_kit","Gpu","bitcoin_money","bitcoin"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Gear_Tools","DZ_Gear_Crafting","DZ_Gear_Consumables","DZ_Gear_Cultivation","DZ_Characters"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class Container_Base;
	class WoodenCrate;
	class land_mm_mining_rig: Container_Base
	{
		scope = 2;
		displayName = "Mining Rig";
		descriptionShort = "This is a Mining Rig, designed to produce Bitcoins.";
		slopeTolerance = 0.4;
		yawPitchRollLimit[] = {45, 45, 45};
		model = "mm_mining_rig\data\Models\land_mm_mining_rig.p3d";
		weight = 10000;
		physLayer = "item_large";
		itemSize[] = {4, 5};
		class Cargo
		{
			itemsCargoSize[] = {10,5};
			allowOwnedCargoManipulation = 1;
		};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOffWhenInCargo=1;
			energyUsagePerSecond=0.01;
			plugType=1;
			attachmentAction=1;
			updateInterval=60;
		};
		soundImpactType="plastic";
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "seachest_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "seachest_drop_SoundSet";
					id = 898;
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000000;
					healthLevels[] = {{1,{"DZ\gear\camping\data\spotlight.rvmat"}},{0.7,{"DZ\gear\camping\data\spotlight.rvmat"}},{0.5,{"DZ\gear\camping\data\spotlight_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\spotlight_damage.rvmat"}},{0,{"DZ\gear\camping\data\spotlight_destruct.rvmat"}}};
				};
			};
		};
		attachments[] = {"Gpu1","Gpu2","Gpu3","Gpu4","Gpu5","Gpu6","Gpu7","Gpu8","Gpu9","Gpu10","bitcoin"};
		class GUIInventoryAttachmentsProps
		{
			class Gpu
			{
				name = "Gpu";
				description = "";
				attachmentSlots[] = {"Gpu1","Gpu2","Gpu3","Gpu4","Gpu5","Gpu6","Gpu7","Gpu8","Gpu9","Gpu10"};
				icon = "set:dayz_inventory image:cookingequipment";
			};
			class bitcoin
			{
				name = "bitcoin";
				description = "bitcoin slot";
				attachmentSlots[] = {"bitcoin"};
				icon = "set:dayz_inventory image:cookingequipment";
			};
		};
	};
	class land_mm_mining_rig_kit: WoodenCrate
	{
		scope = 2;
		displayName = "Mining Rig Kit";
		descriptionShort = "Mining Rig kit that Deploy the Rig.";
		model = "mm_mining_rig\data\Models\land_mm_mining_rig_kit.p3d";
		weight = 5000;
		physLayer = "item_large";
		itemBehaviour = 2;
		itemSize[] = {5,3};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "seachest_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "seachest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyGpu1_Proxy1: ProxyAttachment
	{
		scope= 2;
		inventorySlot="Gpu1";
		model="mm_mining_rig\data\GPU\Proxies\Gpu1.p3d";
	};
	class ProxyGpu2_Proxy2: ProxyAttachment
	{
		scope= 2;
		inventorySlot="Gpu2";
		model="mm_mining_rig\data\GPU\Proxies\Gpu2.p3d";
	};
	class ProxyGpu3_Proxy3: ProxyAttachment
	{
		scope= 2;
		inventorySlot="Gpu3";
		model="mm_mining_rig\data\GPU\Proxies\Gpu3.p3d";
	};
	class ProxyGpu4_Proxy4: ProxyAttachment
	{
		scope= 2;
		inventorySlot="Gpu4";
		model="mm_mining_rig\data\GPU\Proxies\Gpu4.p3d";
	};
	class ProxyGpu5_Proxy5: ProxyAttachment
	{
		scope= 2;
		inventorySlot="Gpu5";
		model="mm_mining_rig\data\GPU\Proxies\Gpu5.p3d";
	};
	class ProxyGpu6_Proxy6: ProxyAttachment
	{
		scope= 2;
		inventorySlot="Gpu6";
		model="mm_mining_rig\data\GPU\Proxies\Gpu6.p3d";
	};
	class ProxyGpu7_Proxy7: ProxyAttachment
	{
		scope= 2;
		inventorySlot="Gpu7";
		model="mm_mining_rig\data\GPU\Proxies\Gpu7.p3d";
	};
	class ProxyGpu8_Proxy8: ProxyAttachment
	{
		scope= 2;
		inventorySlot="Gpu8";
		model="mm_mining_rig\data\GPU\Proxies\Gpu8.p3d";
	};
	class ProxyGpu9_Proxy9: ProxyAttachment
	{
		scope= 2;
		inventorySlot="Gpu9";
		model="mm_mining_rig\data\GPU\Proxies\Gpu9.p3d";
	};
	class ProxyGpu10_Proxy10: ProxyAttachment
	{
		scope= 2;
		inventorySlot="Gpu10";
		model="mm_mining_rig\data\GPU\Proxies\Gpu10.p3d";
    };
};
class CfgSlots
{
	class Slot_Gpu1
	{
		name = "Gpu1";
		displayName = "AMD GPU";
		selection = "Gpu1";
		ghostIcon = "set:dayz_inventory image:cookingequipment";
		stackMax = 1;
	};
	class Slot_Gpu2
	{
		name = "Gpu2";
		displayName = "AMD GPU";
		selection = "Gpu2";
		ghostIcon = "set:dayz_inventory image:cookingequipment";
		stackMax = 1;
	};
	class Slot_Gpu3
	{
		name = "Gpu3";
		displayName = "AMD GPU";
		selection = "Gpu3";
		ghostIcon = "set:dayz_inventory image:cookingequipment";
		stackMax = 1;
	};
	class Slot_Gpu4
	{
		name = "Gpu4";
		displayName = "AMD GPU";
		selection = "Gpu4";
		ghostIcon = "set:dayz_inventory image:cookingequipment";
		stackMax = 1;
	};
	class Slot_Gpu5
	{
		name = "Gpu5";
		displayName = "AMD GPU";
		selection = "Gpu5";
		ghostIcon = "set:dayz_inventory image:cookingequipment";
		stackMax = 1;
	};
	class Slot_Gpu6
	{
		name = "Gpu6";
		displayName = "AMD GPU";
		selection = "Gpu6";
		ghostIcon = "set:dayz_inventory image:cookingequipment";
		stackMax = 1;
	};
	class Slot_Gpu7
	{
		name = "Gpu7";
		displayName = "AMD GPU";
		selection = "Gpu7";
		ghostIcon = "set:dayz_inventory image:cookingequipment";
		stackMax = 1;
	};
	class Slot_Gpu8
	{
		name = "Gpu8";
		displayName = "AMD GPU";
		selection = "Gpu8";
		ghostIcon = "set:dayz_inventory image:cookingequipment";
		stackMax = 1;
	};
	class Slot_Gpu9
	{
		name = "Gpu9";
		displayName = "AMD GPU";
		selection = "Gpu9";
		ghostIcon = "set:dayz_inventory image:cookingequipment";
		stackMax = 1;
	};
	class Slot_Gpu10
	{
		name = "Gpu10";
		displayName = "AMD GPU";
		selection = "Gpu10";
		ghostIcon = "set:dayz_inventory image:cookingequipment";
		stackMax = 1;
	};
			class Slot_bitcoin
	{
		name = "bitcoin";
		displayName = "bitcoin";
		selection = "bitcoin";
		ghostIcon = "set:dayz_inventory image:cookingequipment";
		stackMax = 10;
	};
};	