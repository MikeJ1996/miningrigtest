class CfgPatches
{
	class mm_mining_rig
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Gear_Tools","DZ_Gear_Crafting","DZ_Gear_Consumables","DZ_Weapons_Ammunition","DZ_Gear_Cultivation","DZ_Characters","bitcoin_money","bitcoin"};
	};
};
class CfgMods
{
	class mm_mining_rig
	{
		dir = "mm_mining_rig";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "mm_mining_rig";
		credits = "";
		author = "MikeJ";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
        dependencies[] = {"Game","World"};
        class defs
        {   
			class gameScriptModule
			{
				value = "";
				files[] = {"mm_mining_rig/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"mm_mining_rig/scripts/4_World"};
			};
		};
	};
};
