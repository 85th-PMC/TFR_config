class CfgPatches
{
	class tfar_core
	{
		name="TFAR - Core";
		units[]=
		{
			"tfar_ModuleTaskForceRadioEnforceUsage",
			"tfar_ModuleTaskForceRadio",
			"tfar_ModuleTaskForceRadioFrequencies"
		};
		weapons[]={};
		requiredVersion=1.62;
		requiredAddons[]=
		{
			"A3_Modules_F",
			"A3_UI_F",
			"cba_main",
			"cba_ui",
			"cba_xeh",
			"cba_settings",
			"A3_Soft_F_Offroad_01"
		};
		author="Task Force Arrowhead Radio Team";
	};
	class task_force_radio
	{
		name="TFAR - Legacy Compatibility";
		units[]={};
		weapons[]={};
		requiredVersion=1.62;
		requiredAddons[]={};
		author="Task Force Arrowhead Radio Team";
	};
	class task_force_radio_items
	{
		name="TFAR - Legacy Compatibility";
		units[]={};
		weapons[]={};
		requiredVersion=1.62;
		requiredAddons[]={};
		author="Task Force Arrowhead Radio Team";
	};
};
class CfgMods
{
	class tfar
	{
		dir="@task_force_radio";
		name="Task Force Arrowhead Radio";
		tooltip="Task Force Arrowhead Radio";
		overview="Task Force Arrowhead Radio";
		picture="\z\tfar\addons\core\task_force_arrowhead_logo.paa";
		contentBrowserPicture="\z\tfar\addons\core\task_force_arrowhead_logo.paa";
		logo="\z\tfar\addons\core\task_force_arrowhead_logo.paa";
		logoOver="\z\tfar\addons\core\task_force_arrowhead_logo.paa";
		logoSmall="\z\tfar\addons\core\task_force_arrowhead_logo.paa";
		hidePicture=0;
		hideName=1;
		requiresRestart=0;
		action="https://github.com/michail-nikolaev/task-force-arma-3-radio";
		actionName="Website";
		description="War is not only about moving, waiting and engaging targets. It is also about communication. Task Force Arrowhead Radio provides a way to dramatically increase gameplay realism and atmosphere by seamless integration with TeamSpeak.";
	};
};
class CfgSettings
{
	class CBA
	{
		class Versioning
		{
			class TFAR
			{
				main_addon="tfar_core";
				class Dependencies
				{
					CBA[]=
					{
						"cba_main",
						{3,1,0},
						"true"
					};
				};
			};
		};
	};
};
class CfgEditorCategories
{
	class TFAR
	{
		displayName="TFAR";
	};
};
class CfgUIGrids
{
	class IGUI
	{
		class Presets
		{
			class Arma3
			{
				class Variables
				{
					grid_TFAR_Volume[]=
					{
						
						{
							"0.95 * safezoneW + safezoneX",
							"0.95 * safezoneH + safezoneY",
							"(4 * (1 * (((safezoneW / safezoneH) min 1.2) / 50)))",
							"(4 * (1 * (((safezoneW / safezoneH) min 1.2) / 50)))"
						},
						"(1 * (((safezoneW / safezoneH) min 1.2) / 50))",
						"(1 * (((safezoneW / safezoneH) min 1.2) / 50))"
					};
				};
			};
		};
		class Variables
		{
			class grid_TFAR_Volume
			{
				displayName="TFAR volume Indicator";
				description="TFAR Volume Indicator";
				preview="\z\tfar\addons\core\ui\tfar_volume_normal.paa";
				saveToProfile[]={0,1,2,3};
				canResize=1;
			};
		};
	};
};
class Cfg3DEN
{
	class Object
	{
		class AttributeCategories
		{
			class TFAR_core_attributes
			{
				displayName="TFAR Options";
				collapsed=1;
				class Attributes
				{
					class TFAR_CuratorCamEars
					{
						property="TFAR_CuratorCamEars";
						control="Checkbox";
						displayName="Hear Camera when in Curator interface";
						tooltip="Hear voice from Curator Camera when in Curator interface";
						expression="if (_value) then {_this setVariable ['TFAR_curatorCamEars',_value]};";
						typeName="BOOL";
						condition="objectBrain";
						defaultValue="false";
					};
				};
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class tfar_core
	{
		init="call compile preProcessFileLineNumbers '\z\tfar\addons\core\XEH_preStart.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class tfar_core
	{
		init="call compile preProcessFileLineNumbers '\z\tfar\addons\core\XEH_preInit.sqf'";
		disableModuload=1;
	};
};
class Extended_PostInit_EventHandlers
{
	class tfar_core
	{
		init="call compile preProcessFileLineNumbers '\z\tfar\addons\core\XEH_postInit.sqf'";
		disableModuload=1;
	};
};
class Extended_DisplayLoad_EventHandlers
{
	class RscDisplayArsenal
	{
		TFAR_ArsenalOpened="'PreOpen' call TFAR_fnc_onArsenal";
	};
	class RscDisplayCurator
	{
		TFAR_CuratorInterfaceOpened="[_this select 0, 'Open'] call TFAR_fnc_onCuratorInterface";
	};
	class RscDisplayEGSpectator
	{
		TFAR_RscDisplayEGSpectator="[player, true] call TFAR_fnc_forceSpectator;";
	};
};
class Extended_DisplayUnload_EventHandlers
{
	class RscDisplayMission
	{
		TFAR_MissionEnded="call TFAR_fnc_onMissionEnd";
	};
	class RscDisplayCurator
	{
		TFAR_CuratorInterfaceOpened="[_this select 0, 'Close'] call TFAR_fnc_onCuratorInterface";
	};
};
class RscListBox;
class RscDisplayArsenal
{
	class Controls
	{
		class ListBackpack: RscListBox
		{
			onLoad="'PrePreOpen' call TFAR_fnc_onArsenal";
		};
	};
};
class RscBackPicture
{
	access=0;
	type=0;
	idc=-1;
	style=48;
	colorBackground[]={0,0,0,0};
	colorText[]={1,1,1,1};
	font="TahomaB";
	sizeEx=0;
	lineSpacing=0;
	text="";
	fixedWidth=0;
	shadow=0;
	x=0;
	y=0;
	w=0.2;
	h=0.15000001;
};
class RscEditLCD
{
	access=0;
	type=2;
	x=0;
	y=0;
	h=0.039999999;
	w=0.2;
	colorBackground[]={0,0,0,0};
	colorText[]={0,0,0,1};
	colorDisabled[]={1,1,1,0.25};
	colorSelection[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",
		1
	};
	autocomplete="";
	text="";
	size="0.2 * (0.7 / (getResolution select 5))";
	style="0x00 + 0x40 + 0x200";
	font="TFAR_font_segments";
	shadow=1;
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2) * (0.7 / (getResolution select 5))";
};
class HiddenButton
{
	access=0;
	type=1;
	text="";
	colorText[]={0,0,0,1};
	colorDisabled[]={0,0,0,0};
	colorBackground[]={0,0,0,0};
	colorBackgroundDisabled[]={0,0,0,0};
	colorBackgroundActive[]={0,0,0,0};
	colorFocused[]={0,0,0,0};
	colorShadow[]={0,0,0,0};
	colorBorder[]={0,0,0,0};
	soundEnter[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEnter",
		0.090000004,
		1
	};
	soundPush[]=
	{
		"\z\tfar\addons\core\sounds\softPush",
		0.5,
		1
	};
	soundClick[]=
	{
		"\z\tfar\addons\core\sounds\softClick",
		0.5,
		1
	};
	soundEscape[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.090000004,
		1
	};
	style=2;
	x=0;
	y=0;
	w=0.095588997;
	h=0.039216001;
	shadow=2;
	font="PuristaMedium";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	offsetX=0.003;
	offsetY=0.003;
	offsetPressedX=0.0020000001;
	offsetPressedY=0.0020000001;
	borderSize=0;
};
class HiddenRotator: HiddenButton
{
	soundPush[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.5,
		1
	};
	soundClick[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.5,
		1
	};
};
class HiddenFlip: HiddenButton
{
	soundPush[]=
	{
		"\z\tfar\addons\core\sounds\switchPush",
		0.5,
		1
	};
	soundClick[]=
	{
		"\z\tfar\addons\core\sounds\switchClick",
		0.5,
		1
	};
};
class RscStructuredText;
class RscPictureKeepAspect;
class RscTitles
{
	class RscTaskForceHint
	{
		idd=30040;
		onLoad="uiNamespace setVariable ['TFAR_Hint_Display', _this select 0]";
		onUnload="uiNamespace setVariable ['TFAR_Hint_Display', displayNull]";
		fadeIn=0.2;
		fadeOut=0.2;
		movingEnable=0;
		duration="10e10";
		name="RscTaskForceHint";
		class controls
		{
			class InformationText: RscStructuredText
			{
				idc=1100;
				text="";
				x="0.85 * safezoneW + safezoneX";
				y="0.9 * safezoneH + safezoneY";
				w="0.15 * safezoneW";
				h="0.1 * safezoneH";
				colorText[]={1,1,1,1};
				colorBackground[]={0.1,0.1,0.1,0.5};
				sizeEx=1;
				size="( ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * (0.55 / (getResolution select 5)))";
			};
		};
	};
	class tfar_core_HUDVolumeIndicatorRsc
	{
		idd=-1;
		movingEnable=1;
		duration=9999999;
		fadein=0;
		fadeout=0;
		onLoad="uiNamespace setVariable [""tfar_core_HUDVolumeIndicatorRscDisplay"",_this select 0];";
		class controls
		{
			class VolumeIndicator: RscPictureKeepAspect
			{
				idc=1112;
				text="\z\tfar\addons\core\ui\tfar_volume_normal.paa";
				x="(profilenamespace getvariable [""IGUI_grid_TFAR_Volume_X"", 0.95 * safezoneW + safezoneX])";
				y="(profilenamespace getvariable [""IGUI_grid_TFAR_Volume_Y"", 0.95 * safezoneH + safezoneY])";
				w="(profilenamespace getvariable [""IGUI_grid_TFAR_Volume_W"",  1 * (((safezoneW / safezoneH) min 1.2) / 50)])";
				h="(profilenamespace getvariable [""IGUI_grid_TFAR_Volume_W"",  1 * (((safezoneW / safezoneH) min 1.2) / 50)])";
			};
		};
	};
};
class CfgSounds
{
	class TFAR_rotatorPush
	{
		name="TFAR - Rotator Switch (Push)";
		sound[]=
		{
			"\z\tfar\addons\core\sounds\hardPush.wss",
			0.5,
			1
		};
		titles[]={};
	};
	class TFAR_rotatorClick
	{
		name="TFAR - Rotator Switch (Click)";
		sound[]=
		{
			"\A3\ui_f\data\sound\RscButton\soundEscape.wss",
			0.5,
			1
		};
		titles[]={};
	};
};
class CfgFontFamilies
{
	class TFAR_font_dots
	{
		fonts[]=
		{
			"\z\tfar\addons\core\fonts\dots\dots36"
		};
		spaceWidth=0.60000002;
		spacing=0.15000001;
	};
	class TFAR_font_segments
	{
		fonts[]=
		{
			"\z\tfar\addons\core\fonts\segments\segments46"
		};
		spaceWidth=0.80000001;
		spacing=0.30000001;
	};
};
class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class ArgumentsBaseUnits
		{
			class Units;
		};
		class ModuleDescription
		{
			class AnyBrain;
		};
	};
	class TFAR_ModuleTaskForceRadioEnforceUsage: Module_F
	{
		scope=2;
		author="Task Force Arrowhead Radio Team";
		displayName="$STR_TFAR_Mod_EnforceUsage";
		category="TFAR";
		function="TFAR_fnc_initialiseEnforceUsageModule";
		functionPriority=1;
		isGlobal=1;
		isTriggerActivated=0;
		class Arguments
		{
			class TeamLeaderRadio
			{
				displayName="$STR_TFAR_Mod_GiveTLradio";
				description="$STR_TFAR_Mod_GiveTLradioTT";
				typeName="BOOL";
				defaultValue=0;
			};
			class RiflemanRadio
			{
				displayName="$STR_TFAR_Mod_GiveRiflemanRadio";
				description="$STR_TFAR_Mod_GiveRiflemanRadioTT";
				typeName="BOOL";
				defaultValue=0;
			};
			class terrain_interception_coefficient
			{
				displayName="$STR_TFAR_Mod_TerrainInterceptionCoefficient";
				description="$STR_TFAR_Mod_TerrainInterceptionCoefficientTT";
				typeName="NUMBER";
				defaultValue=7;
			};
			class radio_channel_name
			{
				displayName="$STR_TFAR_Mod_ChannelName";
				description="$STR_TFAR_Mod_ChannelNameTT";
				typeName="TEXT";
				defaultValue="TaskForceRadio";
			};
			class radio_channel_password
			{
				displayName="$STR_TFAR_Mod_ChannelPassword";
				description="$STR_TFAR_Mod_ChannelPasswordTT";
				typeName="TEXT";
				defaultValue="123";
			};
			class same_sw_frequencies_for_side
			{
				displayName="$STR_TFAR_Mod_SameSWFrequencies";
				description="$STR_TFAR_Mod_SameSWFrequenciesTT";
				typeName="BOOL";
				defaultValue=0;
			};
			class same_lr_frequencies_for_side
			{
				displayName="$STR_TFAR_Mod_SameLrFrequencies";
				description="$STR_TFAR_Mod_SameLrFrequenciesTT";
				typeName="BOOL";
				defaultValue=0;
			};
			class full_duplex
			{
				displayName="$STR_TFAR_Mod_FullDuplex";
				description="$STR_TFAR_Mod_FullDuplexDescription";
				typeName="BOOL";
				defaultValue=1;
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="$STR_TFAR_Mod_EnforceUsage_Description";
		};
	};
	class TFAR_ModuleTaskForceRadio: Module_F
	{
		scope=2;
		author="Task Force Arrowhead Radio Team";
		displayName="$STR_TFAR_Mod_SideRadio";
		category="TFAR";
		function="TFAR_fnc_initialiseBaseModule";
		functionPriority=2;
		isGlobal=1;
		class Arguments: ArgumentsBaseUnits
		{
			class Units: Units
			{
			};
			class Encryption
			{
				displayName="$STR_TFAR_Mod_EncryptionCode";
				description="$STR_TFAR_Mod_EncryptionCode";
				typeName="TEXT";
				defaultValue="DSH&G^G";
			};
			class LRradio
			{
				displayName="$STR_TFAR_Mod_LR_Radio";
				description="$STR_TFAR_Mod_LR_RadioTT";
				typeName="TEXT";
				defaultValue="";
			};
			class Radio
			{
				displayName="$STR_TFAR_Mod_PR_Radio";
				description="$STR_TFAR_Mod_PR_RadioTT";
				typeName="TEXT";
				defaultValue="TFAR_anprc154";
			};
			class RiflemanRadio
			{
				displayName="$STR_TFAR_Mod_Rifle_Radio";
				description="$STR_TFAR_Mod_Rifle_RadioTT";
				typeName="TEXT";
				defaultValue="TFAR_rf7800str";
			};
			class PrFreq
			{
				displayName="$STR_TFAR_Mod_PRFrequency";
				description="$STR_TFAR_Mod_PRFrequencyTT";
				typeName="TEXT";
				defaultValue="[""70.2"",""127.1""]";
			};
			class LrFreq
			{
				displayName="$STR_TFAR_Mod_LRFrequency";
				description="$STR_TFAR_Mod_LRFrequencyTT";
				typeName="TEXT";
				defaultValue="[""54.2"",""73.1""]";
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="$STR_TFAR_Mod_SideRadio_Description";
			sync[]=
			{
				"AnyPerson"
			};
		};
	};
	class TFAR_ModuleTaskForceRadioFrequencies: Module_F
	{
		scope=2;
		author="Task Force Arrowhead Radio Team";
		displayName="$STR_TFAR_Mod_Frequencies";
		category="TFAR";
		function="TFAR_fnc_initialiseFreqModule";
		functionPriority=0;
		isGlobal=1;
		isTriggerActivated=1;
		class Arguments: ArgumentsBaseUnits
		{
			class Units: Units
			{
			};
			class PrFreq
			{
				displayName="$STR_TFAR_Mod_PRFrequency";
				description="$STR_TFAR_Mod_PRFrequencyTT";
				typeName="TEXT";
				defaultValue="[""70.2"",""127.1""]";
			};
			class LrFreq
			{
				displayName="$STR_TFAR_Mod_LRFrequency";
				description="$STR_TFAR_Mod_LRFrequencyTT";
				typeName="TEXT";
				defaultValue="[""54.2"",""73.1""]";
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="$STR_TFAR_Mod_Frequencies_Description";
			sync[]=
			{
				"AnyPerson"
			};
		};
	};
	class All;
	class AllVehicles: All
	{
		tf_hasLRradio=0;
		tf_isolatedAmount=0;
	};
	class Air: AllVehicles
	{
		tf_hasLRradio=1;
		tf_isolatedAmount=0.1;
	};
	class Land;
	class LandVehicle: Land
	{
		tf_range=30000;
		class ACE_SelfActions;
	};
	class Car: LandVehicle
	{
		tf_isolatedAmount=0.1;
	};
	class Tank: LandVehicle
	{
		tf_hasLRradio=1;
		tf_isolatedAmount=1;
		class ACE_SelfActions: ACE_SelfActions
		{
			class TFAR_IntercomChannel
			{
				displayName="Intercom Channel";
				condition="true";
				statement="";
				icon="";
				class TFAR_IntercomChannel_1
				{
					displayName="Cargo";
					condition="true";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],0,true];";
				};
				class TFAR_IntercomChannel_2
				{
					displayName="Crew";
					condition="true";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],1,true];";
				};
			};
		};
		TFAR_hasIntercom=1;
	};
	class Helicopter;
	class ParachuteBase: Helicopter
	{
		tf_hasLRradio=0;
		tf_isolatedAmount=0;
	};
	class Helicopter_Base_F;
	class Heli_Attack_02_base_F: Helicopter_Base_F
	{
		tf_isolatedAmount=0.69999999;
	};
	class Heli_Attack_01_base_F: Helicopter_Base_F
	{
		tf_isolatedAmount=0.69999999;
	};
	class Helicopter_Base_H;
	class Heli_Light_02_base_F: Helicopter_Base_H
	{
		tf_isolatedAmount=0.69999999;
	};
	class Heli_Transport_01_base_F: Helicopter_Base_H
	{
		tf_isolatedAmount=0.30000001;
	};
	class Heli_Transport_02_base_F: Helicopter_Base_H
	{
		tf_isolatedAmount=0.80000001;
	};
	class Car_F;
	class Wheeled_Apc_F: Car_F
	{
		tf_hasLRradio=1;
		tf_isolatedAmount=0.60000002;
	};
	class MRAP_01_base_F: Car_F
	{
		tf_hasLRradio=1;
		tf_isolatedAmount=0.69999999;
	};
	class MRAP_02_base_F: Car_F
	{
		tf_hasLRradio=1;
		tf_isolatedAmount=0.69999999;
	};
	class MRAP_03_base_F: Car_F
	{
		tf_hasLRradio=1;
		tf_isolatedAmount=0.69999999;
	};
	class Truck_F;
	class Truck_01_base_F: Truck_F
	{
		tf_hasLRradio=1;
		tf_isolatedAmount=0.40000001;
	};
	class Truck_02_base_F: Truck_F
	{
		tf_hasLRradio=1;
		tf_isolatedAmount=0.40000001;
	};
	class Truck_03_base_F: Truck_F
	{
		tf_hasLRradio=1;
		tf_isolatedAmount=0.40000001;
	};
	class Offroad_01_military_base_F;
	class Offroad_01_armed_base_F: Offroad_01_military_base_F
	{
		tf_hasLRradio=1;
		tf_isolatedAmount=0.25;
	};
	class Boat_F;
	class SDV_01_base_F: Boat_F
	{
		tf_hasLRradio=1;
		tf_isolatedAmount=0.1;
	};
	class Boat_Armed_01_base_F: Boat_F
	{
		tf_hasLRradio=1;
		tf_isolatedAmount=0.1;
	};
	class Boat_Civil_01_base_F;
	class C_Boat_Civil_01_police_F: Boat_Civil_01_base_F
	{
		tf_hasLRradio=1;
	};
	class C_Boat_Civil_01_rescue_F: Boat_Civil_01_base_F
	{
		tf_hasLRradio=1;
	};
};
