#pragma once
#include <numbers>
#include <cmath>
#include <array>
#include "utility.h"
#include "auth.hpp"
#include <thread>
#include "overlay.h"
#include <string>
#define COLOUR(x) x/255
using namespace KeyAuth;
std::string name = "CSGO Cheat"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = "jHHXUBClti"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = "eb683e44d0621780d602d6fd1c12a7c3d23eb2c537cbbf98210bf6120524e18b"; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.0"; // leave alone unless you've changed version on website
std::string url = "https://auth.aliencheats.com/api/1.1/"; // change if you're self-hosting
std::string sslPin = "ssl pin key (optional)"; // don't change unless you intend to pin public certificate key. you can get here in the "Pin SHA256" field https://www.ssllabs.com/ssltest/analyze.html?d=keyauth.win&latest. If you do this you need to be aware of when SSL key expires so you can update it
api KeyAuthApp(name, ownerid, secret, version, url, sslPin);

struct Vector3
{
	// constructor
	constexpr Vector3(
		const float x = 0.f,
		const float y = 0.f,
		const float z = 0.f) noexcept :
		x(x), y(y), z(z) { }

	inline static float sqrtf(float number)
	{
		long i;
		float x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long*)&y;
		i = 0x5f3759df - (i >> 1);
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y));
		y = y * (threehalfs - (x2 * y * y));

		return 1 / y;
	}

	// operator overloads
	constexpr const Vector3& operator-(const Vector3& other) const noexcept
	{
		return Vector3{ x - other.x, y - other.y, z - other.z };
	}

	constexpr const Vector3& operator+(const Vector3& other) const noexcept
	{
		return Vector3{ x + other.x, y + other.y, z + other.z };
	}

	constexpr const Vector3& operator/(const float factor) const noexcept
	{
		return Vector3{ x / factor, y / factor, z / factor };
	}

	constexpr const Vector3& operator*(const float factor) const noexcept
	{
		return Vector3{ x * factor, y * factor, z * factor };
	}

	// utils
	constexpr const Vector3& ToAngle() const noexcept
	{
		return Vector3{
			std::atan2(-z, std::hypot(x, y)) * (180.0f / std::numbers::pi_v<float>),
			std::atan2(y, x) * (180.0f / std::numbers::pi_v<float>),
			0.0f };
	}

	constexpr const bool IsZero() const noexcept
	{
		return x == 0.f && y == 0.f && z == 0.f;
	}

	float distancee(Vector3 vec)
	{
		return sqrt(
			pow(vec.x - x, 2) +
			pow(vec.y - y, 2)
		);
	}

	

	// struct data
	float x, y, z;
};
constexpr Vector3 CalculateAngle(
	const Vector3& localPosition,
	const Vector3& enemyPosition,
	const Vector3& viewAngles) noexcept
{
	return ((enemyPosition - localPosition).ToAngle() - viewAngles);
}
struct Vector2
{
	float x = { }, y = { };
};



static const char* kitlenme[] = { "HEAD", "CHEST", "LEG" };
static int selectedkitlenme = 0;
enum WeaponIds
{
	WEAPON_DEAGLE = 1,
	WEAPON_ELITE = 2,
	WEAPON_FIVESEVEN = 3,
	WEAPON_GLOCK = 4,
	WEAPON_AK47 = 7,
	WEAPON_AUG = 8,
	WEAPON_AWP = 9,
	WEAPON_FAMAS = 10,
	WEAPON_G3SG1 = 11,
	WEAPON_GALILAR = 13,
	WEAPON_M249 = 14,
	WEAPON_M4A1 = 16,
	WEAPON_MAC10 = 17,
	WEAPON_P90 = 19,
	WEAPON_MP5SD = 23,
	WEAPON_UMP45 = 24,
	WEAPON_XM1014 = 25,
	WEAPON_BIZON = 26,
	WEAPON_MAG7 = 27,
	WEAPON_NEGEV = 28,
	WEAPON_SAWEDOFF = 29,
	WEAPON_TEC9 = 30,
	WEAPON_TASER = 31,
	WEAPON_HKP2000 = 32,
	WEAPON_MP7 = 33,
	WEAPON_MP9 = 34,
	WEAPON_NOVA = 35,
	WEAPON_P250 = 36,
	WEAPON_SHIELD = 37,
	WEAPON_SCAR20 = 38,
	WEAPON_SG556 = 39,
	WEAPON_SSG08 = 40,
	WEAPON_KNIFEGG = 41,
	WEAPON_KNIFE = 42,
	WEAPON_FLASHBANG = 43,
	WEAPON_HEGRENADE = 44,
	WEAPON_SMOKEGRENADE = 45,
	WEAPON_MOLOTOV = 46,
	WEAPON_DECOY = 47,
	WEAPON_INCGRENADE = 48,
	WEAPON_C4 = 49,
	WEAPON_HEALTHSHOT = 57,
	WEAPON_KNIFE_T = 59,
	WEAPON_M4A1_SILENCER = 60,
	WEAPON_USP_SILENCER = 61,
	WEAPON_CZ75A = 63,
	WEAPON_REVOLVER = 64,
	WEAPON_TAGRENADE = 68,
	WEAPON_FISTS = 69,
	WEAPON_BREACHCHARGE = 70,
	WEAPON_TABLET = 72,
	WEAPON_MELEE = 74,
	WEAPON_AXE = 75,
	WEAPON_HAMMER = 76,
	WEAPON_SPANNER = 78,
	WEAPON_KNIFE_GHOST = 80,
	WEAPON_FIREBOMB = 81,
	WEAPON_DIVERSION = 82,
	WEAPON_FRAG_GRENADE = 83,
	WEAPON_SNOWBALL = 84,
	WEAPON_BUMPMINE = 85,
	WEAPON_BAYONET = 500,
	WEAPON_KNIFE_FLIP = 505,
	WEAPON_KNIFE_GUT = 506,
	WEAPON_KNIFE_KARAMBIT = 507,
	WEAPON_KNIFE_M9_BAYONET = 508,
	WEAPON_KNIFE_TACTICAL = 509,
	WEAPON_KNIFE_FALCHION = 512,
	WEAPON_KNIFE_SURVIVAL_BOWIE = 514,
	WEAPON_KNIFE_BUTTERFLY = 515,
	WEAPON_KNIFE_PUSH = 516,
	WEAPON_KNIFE_URSUS = 519,
	WEAPON_KNIFE_GYPSY_JACKKNIFE = 520,
	WEAPON_KNIFE_STILETTO = 522,
	WEAPON_KNIFE_WIDOWMAKER = 523,
	STUDDED_BLOODHOUND_GLOVES = 5027,
	T_GLOVES = 5028,
	CT_GLOVES = 5029,
	SPORTY_GLOVES = 5030,
	SLICK_GLOVES = 5031,
	LEATHER_HANDWRAPS = 5032,
	MOTORCYCLE_GLOVES = 5033,
	SPECIALIST_GLOVES = 5034,
	STUDDED_HYDRA_GLOVES = 5035,
};


constexpr const int GetWeaponPaint(const short& itemDefinition)
{
	switch (itemDefinition)
	{
	case WEAPON_DEAGLE: return 37; // deagle
	case WEAPON_AUG: return 38; // aug
	case WEAPON_GLOCK: return 38; // glock
	case WEAPON_AK47: return 490; // ak
	case WEAPON_M4A1: return 309; // m4a4
	case WEAPON_AWP: return 475; //awp
	case WEAPON_USP_SILENCER: return 653; // usp
	case WEAPON_FAMAS: return 260; // famas
	case WEAPON_SG556: return 287; // sg 553
	case WEAPON_GALILAR: return 428; // galil ar
	case WEAPON_REVOLVER:  return 38; // revolever
	case WEAPON_P90: return 359; // p90
	case WEAPON_MAG7: return 32; // 
	case WEAPON_G3SG1: return 464; //
	case WEAPON_M249: return 266; // 
	case WEAPON_CZ75A: return 322; //
	case WEAPON_UMP45: return 193; //
	case WEAPON_MAC10: return 38; // 
	case WEAPON_TEC9: return 248; // 
	case WEAPON_HKP2000: return 38; // 
	case WEAPON_SAWEDOFF: return 246; // 
	case WEAPON_MP7: return 11; // 
	case WEAPON_P250: return 168; // 
	case WEAPON_FIVESEVEN: return 3; // 
	case WEAPON_NOVA: return 3; // 
	case WEAPON_NEGEV: return 483; // 
	case WEAPON_SCAR20: return 312; // 
	case WEAPON_MP9: return 403; // 
	case WEAPON_M4A1_SILENCER: return 360; // 
	case WEAPON_ELITE: return 447; // dual beretta
	case WEAPON_BIZON: return 224; // 
	case WEAPON_XM1014: return 370; // 
	case WEAPON_SSG08: return 624; // 
	case WEAPON_MP5SD: return 38; // 

	default: return 0;
	}
}
int kitlenmee = 0;

int realkey;
int keystatus;
int aimkey = 0x06;
bool GetKey(int key)
{
	realkey = key;
	return true;
}
void ChangeKey(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				aimkey = i;
				keystatus = 0;
				return;
			}
		}
	}
}
static const char* keyNames[] = {
	"",
	"Left Mouse",
	"Right Mouse",
	"Cancel",
	"Middle Mouse",
	"Mouse 5",
	"Mouse 4",
	"",
	"Backspace",
	"Tab",
	"",
	"",
	"Clear",
	"Enter",
	"",
	"",
	"Shift",
	"Control",
	"Alt",
	"Pause",
	"Caps",
	"",
	"",
	"",
	"",
	"",
	"",
	"Escape",
	"",
	"",
	"",
	"",
	"Space",
	"Page Up",
	"Page Down",
	"End",
	"Home",
	"Left",
	"Up",
	"Right",
	"Down",
	"",
	"",
	"",
	"Print",
	"Insert",
	"Delete",
	"",
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"A",
	"B",
	"C",
	"D",
	"E",
	"F",
	"G",
	"H",
	"I",
	"J",
	"K",
	"L",
	"M",
	"N",
	"O",
	"P",
	"Q",
	"R",
	"S",
	"T",
	"U",
	"V",
	"W",
	"X",
	"Y",
	"Z",
	"",
	"",
	"",
	"",
	"",
	"Numpad 0",
	"Numpad 1",
	"Numpad 2",
	"Numpad 3",
	"Numpad 4",
	"Numpad 5",
	"Numpad 6",
	"Numpad 7",
	"Numpad 8",
	"Numpad 9",
	"Multiply",
	"Add",
	"",
	"Subtract",
	"Decimal",
	"Divide",
	"F1",
	"F2",
	"F3",
	"F4",
	"F5",
	"F6",
	"F7",
	"F8",
	"F9",
	"F10",
	"F11",
	"F12",
};
static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
{
	const char* const* items = (const char* const*)data;
	if (out_text)
		*out_text = items[idx];
	return true;
}
void HotkeyButton(int aimkey, void* changekey, int status)
{
	const char* preview_value = NULL;
	if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(keyNames))
		Items_ArrayGetter(keyNames, aimkey, &preview_value);

	std::string aimkeys;
	if (preview_value == NULL)
		aimkeys = skCrypt("Select Key");
	else
		aimkeys = preview_value;

	if (status == 1)
	{
		aimkeys = skCrypt("Press key to bind");
	}
	if (ImGui::Button(aimkeys.c_str(), ImVec2(100, 20)))
	{
		if (status == 0)
		{
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
		}
	}
}


bool triggerbot = false;
bool AimBot = false;
bool aimbott = false;
bool silent = false;

int aimbotfov = 60;
int aimbottt = 1.f;

bool Enableesp = false;
bool esp = false;
bool esp2 = false;
bool skeletonesp = false;
bool nameesp = false;
bool headesp = false;
bool Snapline = false;
bool weaponinfo = false;
bool ammoesp = false;
bool HealthBar = false;
bool distanceesp = false;
bool infopanel = false;
bool paintinside = false;
int distanceint = 300;

bool Snipercrosshair = false;
bool triggeralert = false;
bool BunnyHop = false;
bool Glow = false;
bool NoFlash = false;
bool Radar = false;
bool Chams = false;
bool skinchanger = false;

static int widthh = 576;
static int heightt = 350;
static int MenuSayfasi = 1;

float height;
float width;
float middle;
float boxThickness = 2;
float espmetre = 2500;

bool Fov = false;
bool Fovtamiri = false;
int fovv = 90;
ImColor cRainbow;
int tab = 1;

void draw_menu()
{
	auto s = ImVec2{}, p = ImVec2{}, gs = ImVec2{ 620, 485 };
	ImGui::SetNextWindowSize(ImVec2(gs));
	ImGui::SetNextWindowBgAlpha(1.0f);
	ImGui::Begin(skCrypt("ALIEN CHEATS - (ver. 0.0.2)"), NULL, ImGuiWindowFlags_::ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_::ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);
	{

		ImGui::SetCursorPosX(121);
		s = ImVec2(ImGui::GetWindowSize().x - ImGui::GetStyle().WindowPadding.x * 2, ImGui::GetWindowSize().y - ImGui::GetStyle().WindowPadding.y * 2); p = ImVec2(ImGui::GetWindowPos().x + ImGui::GetStyle().WindowPadding.x, ImGui::GetWindowPos().y + ImGui::GetStyle().WindowPadding.y); auto draw = ImGui::GetWindowDrawList();
		draw->AddRectFilled(p, ImVec2(p.x + s.x, p.y + s.y), ImColor(15, 17, 19), 5);
		draw->AddRectFilled(ImVec2(p.x, p.y + 40), ImVec2(p.x + s.x, p.y + s.y), ImColor(18, 20, 21), 5, ImDrawCornerFlags_Bot);

		//draw->AddImage(lg, ImVec2(p.x - 60, p.y - 30), ImVec2(p.x + 110, p.y + 70), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 102));

		ImGui::PushFont(icons);
		auto logo_size = ImGui::CalcTextSize(skCrypt("A"));
		draw->AddText(ImVec2(p.x + 28 - logo_size.x / 2, p.y + 29 - (logo_size.y / 2) + 4), cRainbow, skCrypt("A"));
		ImGui::PopFont();

		ImGui::PushFont(main_font2);
		auto logo_size2 = ImGui::CalcTextSize(skCrypt("A"));
		draw->AddText(ImVec2(p.x + 42 - logo_size2.x / 2, p.y + 29 - logo_size2.y), cRainbow, skCrypt("AlienCheats"));
		ImGui::PopFont();

		ImGui::PushFont(main_font);
		ImGui::BeginGroup();
		ImGui::SameLine(110);
		if (ImGui::tab(skCrypt("AIMBOT"), tab == 1))tab = 1; ImGui::SameLine();
		if (ImGui::tab(skCrypt("Visuals"), tab == 2))tab = 2;
		ImGui::EndGroup();
		ImGui::PopFont();

		if (tab == 1)
		{
			ImGui::PushFont(main_font);
			{//left upper
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(15);
				ImGui::MenuChild(skCrypt("Aimbot"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("AIM"), &AimBot);
					ImGui::Text(skCrypt("")); ImGui::SameLine(); HotkeyButton(aimkey, ChangeKey, keystatus); ImGui::SameLine(); ImGui::Text(skCrypt("Aimkey"));
					ImGui::Checkbox(skCrypt("AimBot"), &aimbott);
					if (aimbott == true)
					{
						silent = false;
					}
					ImGui::Checkbox(skCrypt("Silent"), &silent);
					if (silent == true)
					{
						aimbott = false;
					}
					ImGui::SliderInt("Aimbot Smooth", &aimbottt, 1.0f, 20.f);
					ImGui::SliderInt("Aimbot Fov", &aimbotfov, 1.0f, 360.f);
					ImGui::Combo(("Body##lock"), &selectedkitlenme, kitlenme, IM_ARRAYSIZE(kitlenme));
					if (selectedkitlenme == 0) {
						kitlenmee = 8;
					}
					if (selectedkitlenme == 1) {
						kitlenmee = 5;
					}
					if (selectedkitlenme == 2) {
						kitlenmee = 3;
					}
					ImGui::Checkbox(skCrypt("Trigger Bot"), &triggerbot);
					ImGui::Checkbox(skCrypt("Trigger Alert"), &triggeralert);
					ImGui::Checkbox(skCrypt("Sniper Crosshair"), &Snipercrosshair);
				}	
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			{//right
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(320);
				ImGui::MenuChild(skCrypt(" "), ImVec2(285, 415), false);
				{

				}
				ImGui::EndChild();
				ImGui::EndGroup();
				ImGui::PopFont();
			}
		}
		if (tab == 2)
		{
			ImGui::PushFont(main_font);
			{//left upper
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(15);
				ImGui::MenuChild(skCrypt("ESP"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("Enable ESP"), &Enableesp);
					ImGui::Checkbox(skCrypt("2D Box"), &esp);
					if (esp)
					{
						esp2 = false;
					}
					ImGui::Checkbox(skCrypt("Corner Box"), &esp2);
					if (esp2)
					{
						esp = false;
					}
					ImGui::Checkbox(skCrypt("Name Esp"), &nameesp);
					ImGui::Checkbox(skCrypt("Skeleton"), &skeletonesp);
					ImGui::Checkbox(skCrypt("Snapline"), &Snapline);
					ImGui::Checkbox(skCrypt("Health Bar"), &HealthBar);
					ImGui::Checkbox(skCrypt("Head Esp"), &headesp);
					ImGui::Checkbox(skCrypt("Weapon Info"), &weaponinfo);
					ImGui::Checkbox(skCrypt("Ammo Info"), &ammoesp);
					ImGui::Checkbox(skCrypt("Distance Esp"), &distanceesp);
					ImGui::Checkbox(skCrypt("Info Panel"), &infopanel);
					ImGui::Checkbox(skCrypt("PaintInside"), &paintinside);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			{//right
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(320);
				ImGui::MenuChild(skCrypt("VISUALS"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("Bunny Hop"), &BunnyHop);
					ImGui::Checkbox(skCrypt("No Flash"), &NoFlash);
					ImGui::Checkbox(skCrypt("Glow"), &Glow);
					ImGui::Checkbox(skCrypt("Radar"), &Radar);
					ImGui::Checkbox(skCrypt("Chams"), &Chams);
					ImGui::Checkbox(skCrypt("Skin Changer"), &skinchanger);
					ImGui::Checkbox(skCrypt("Graphic Fov"), &Fov);
					ImGui::SliderInt("Graphic Fov", &fovv, 90.0f, 140.f);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			ImGui::PopFont();
		}
	}
	ImGui::End();
	//ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar;
	//ImGui::SetNextWindowSize(ImVec2(widthh, heightt));
	//ImGui::Begin(skCrypt(AK47"WWW.ALIENCHEATS.COM - CS:GO EXTERNAL - SHOVEN"));

	//ImVec2 curPos = ImGui::GetCursorPos();
	//ImVec2 curWindowPos = ImGui::GetWindowPos();
	//curPos.x += curWindowPos.x;
	//curPos.y += curWindowPos.y;
	//ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(curPos.x, 0), ImVec2(curPos.x + widthh, curPos.y - 7), ImColor(255, 0, 0)); // kýrmýzý bar	//static float flRainbow;

	//ImGui::SetCursorPos(ImVec2(55, 22));
	//ImGui::BeginChild(skCrypt("Sayfa 0"), ImVec2(470.0f, 30.0f));
	//ImGui::SetCursorPos({ 30.f,5.f });
	//ImGui::PushFont(main_font2);
	//if (ImGui::Button(skCrypt("AIM"), { 125.f,20.f }))
	//{
	//	MenuSayfasi = 1;
	//}
	//ImGui::PopFont();
	//ImGui::SetCursorPos({ 170.f,5.f });
	//if (ImGui::Button(skCrypt("MISC"), { 125.f,20.f }))	
	//{
	//	MenuSayfasi = 2;
	//}
	//ImGui::SetCursorPos({ 310.f,5.f });
	//if (ImGui::Button(skCrypt("ESP"), { 125.f,20.f }))
	//{
	//	MenuSayfasi = 3;
	//}
	//ImGui::EndChild();

	//if (MenuSayfasi == 1)
	//{
	//	if (ImGui::CollapsingHeader(skCrypt("Aim")))
	//	{
	//		ImGui::Checkbox(skCrypt("AIM"), &AimBot); ImGui::SameLine();
	//		HotkeyButton(aimkey, ChangeKey, keystatus);
	//		ImGui::Checkbox(skCrypt("AimBot"), &aimbott);
	//		if (aimbott == true)
	//		{
	//			silent = false;
	//		}
	//		ImGui::Checkbox(skCrypt("Silent"), &silent);
	//		if (silent == true)
	//		{
	//			aimbott = false;
	//		}
	//		ImGui::SliderInt("Aimbot Smooth", &aimbottt, 1.0f, 20.f);
	//		ImGui::SliderInt("Aimbot Fov", &aimbotfov, 1.0f, 360.f);
	//		ImGui::Combo(("Body##lock"), &selectedkitlenme, kitlenme, IM_ARRAYSIZE(kitlenme));
	//		if (selectedkitlenme == 0) {
	//			kitlenmee = 8;
	//		}
	//		if (selectedkitlenme == 1) {
	//			kitlenmee = 5;
	//		}
	//		if (selectedkitlenme == 2) {
	//			kitlenmee = 3;
	//		}
	//		ImGui::Checkbox(skCrypt("Trigger Bot"), &triggerbot);
	//		ImGui::Checkbox(skCrypt("Trigger Alert"), &triggeralert);
	//		ImGui::Checkbox(skCrypt("Sniper Crosshair"), &Snipercrosshair);
	//	}
	//}
	//if (MenuSayfasi == 2)
	//{
	//	if (ImGui::CollapsingHeader(skCrypt("Misc")))
	//	{
	//		ImGui::Checkbox(skCrypt("Bunny Hop"), &BunnyHop);
	//		ImGui::Checkbox(skCrypt("No Flash"), &NoFlash);
	//		ImGui::Checkbox(skCrypt("Glow"), &Glow);
	//		ImGui::Checkbox(skCrypt("Radar"), &Radar);
	//		ImGui::Checkbox(skCrypt("Chams"), &Chams);
	//		ImGui::Checkbox(skCrypt("Skin Changer"), &skinchanger);
	//		ImGui::Checkbox(skCrypt("Graphic Fov"), &Fov);
	//		ImGui::SliderInt("Graphic Fov", &fovv, 90.0f, 140.f);

	//	}
	//}
	//if (MenuSayfasi == 3)
	//{
	//	if (ImGui::CollapsingHeader(skCrypt("ESP")))
	//	{
	//		ImGui::Checkbox(skCrypt("Enable ESP"), &Enableesp);
	//		ImGui::Checkbox(skCrypt("Box"), &esp);
	//		ImGui::Checkbox(skCrypt("Name Esp"), &nameesp);
	//		ImGui::Checkbox(skCrypt("Skeleton"), &skeletonesp);
	//		ImGui::Checkbox(skCrypt("Snapline"), &Snapline);
	//		ImGui::Checkbox(skCrypt("Health Bar"), &HealthBar);
	//		ImGui::Checkbox(skCrypt("Head Esp"), &headesp);
	//		ImGui::Checkbox(skCrypt("Weapon Info"), &weaponinfo);
	//		ImGui::Checkbox(skCrypt("Ammo Info"), &ammoesp);
	//		ImGui::Checkbox(skCrypt("Distance Esp"), &distanceesp);
	//		ImGui::Checkbox(skCrypt("Info Panel"), &infopanel);

	//	}
	//}
	//ImGui::End();
}



Memory mem;


DWORD moduleBase_client;
DWORD moduleBase_engine;

float viewMatrix[4][4];
DWORD playerLocal;
DWORD iLocalHp;
DWORD iLocalAr;
DWORD localTeam;
DWORD entTeam;
DWORD pEntity;
DWORD entHp;
DWORD entAr;
DWORD weapon;
Vector3 entPos;
Vector3 screenPos;
FLOAT boxHeight;
FLOAT boxWeight;

DWORD pWeapon;
Vector3 wentPos;
Vector3 wscreenPos;


Vector3 getBonePos(int pTargetIn, int bone)
{
	const int matrix = mem.Read<int>(pTargetIn + hazedumper::netvars::m_dwBoneMatrix);
	return Vector3(
		mem.Read<float>(matrix + 0x30 * bone + 0xC),
		mem.Read<float>(matrix + 0x30 * bone + 0x1C),
		mem.Read<float>(matrix + 0x30 * bone + 0x2C)
	);
}


bool WorldToScreen(Vector3 world, Vector3& screen, float flMatrix[4][4]) {
	float w = 0.f;

	screen.x = flMatrix[0][0] * world.x + flMatrix[0][1] * world.y + flMatrix[0][2] * world.z + flMatrix[0][3];
	screen.y = flMatrix[1][0] * world.x + flMatrix[1][1] * world.y + flMatrix[1][2] * world.z + flMatrix[1][3];
	w = flMatrix[3][0] * world.x + flMatrix[3][1] * world.y + flMatrix[3][2] * world.z + flMatrix[3][3];

	if (w < 0.01f) {
		return false;
	}

	float inw = 1.f / w;

	screen.x *= inw;
	screen.y *= inw;

	int weight = static_cast<int>(Rect.right - Rect.left);
	int height = static_cast<int>(Rect.bottom - Rect.top);

	float x = float(weight / 2);
	float y = float(height / 2);

	x += float(screen.x * x);
	y -= float(screen.y * y);

	screen.x = x + Rect.left;
	screen.y = y + Rect.top;

	return true;
}

static void DrawRectImGui(int x, int y, int w, int h, ImVec4 color, float thickness)
{
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(color), 0, 0, thickness);
}

void DrawLeftProgressBar(int x, int y, int w, int h, int thick, int m_health)
{
	int G = (255 * m_health / 100);
	int R = 255 - G;
	RGBA healthcol = { R, G, 0, 255 };

	DrawFilledRect(x - (w / 2) - 5, y, thick, (h)*m_health / 100, &healthcol);
}

#define danger_cast(type_to_cast_to, what_to_cast) *(type_to_cast_to*)&(what_to_cast)


namespace Screen
{
	static int Width = GetSystemMetrics(SM_CXSCREEN);
	static int Height = GetSystemMetrics(SM_CYSCREEN);
}

namespace Colors
{
	float CrosshairColors[] = { 255.f, 55.f, 55.f, 255.f };
}


namespace crosshair
{
	namespace sizes
	{

		namespace cross
		{
			float length = 4.0f;
			float gap = 1.0f;
		}


	}
}
ImVec2 GetWindowSize() {
	return { (float)GetSystemMetrics(SM_CXSCREEN), (float)GetSystemMetrics(SM_CYSCREEN) };
}
void Crosshair()
{
	auto RGB = ImGui::GetColorU32({ 255, 255, 255, 255 });
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(GetWindowSize().x / 2 + crosshair::sizes::cross::gap + 1, GetWindowSize().y / 2 - 1), ImVec2(GetWindowSize().x / 2 + crosshair::sizes::cross::length + crosshair::sizes::cross::gap + 1, GetWindowSize().y / 2 + 1), RGB);
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(GetWindowSize().x / 2 - crosshair::sizes::cross::gap - 1, GetWindowSize().y / 2 + 1), ImVec2(GetWindowSize().x / 2 - crosshair::sizes::cross::length - crosshair::sizes::cross::gap - 1, GetWindowSize().y / 2 - 1), RGB);
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(GetWindowSize().x / 2 - 1, GetWindowSize().y / 2 + crosshair::sizes::cross::gap + 1), ImVec2(GetWindowSize().x / 2 + 1, GetWindowSize().y / 2 + crosshair::sizes::cross::length + crosshair::sizes::cross::gap + 1), RGB);
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(GetWindowSize().x / 2 + 1, GetWindowSize().y / 2 - crosshair::sizes::cross::gap - 1), ImVec2(GetWindowSize().x / 2 - 1, GetWindowSize().y / 2 - crosshair::sizes::cross::length - crosshair::sizes::cross::gap - 1), RGB);
}

uintptr_t getPlayer(int index) {  //Each player in the game has an index.
	return mem.Read< uintptr_t>(moduleBase_client + hazedumper::signatures::dwEntityList + index * 0x10); //We use index times 0x10 because the distance between each player 0x10.
}
int getTeam(uintptr_t player) {
	return mem.Read<int>(player + hazedumper::netvars::m_iTeamNum);
}

Vector3 entHeadPos;
Vector3 entNeckPos;
Vector3 entNeck2Pos;
Vector3 entNeck3Pos;
Vector3 entNeck4Pos;
Vector3 entArmPos;
Vector3 entArm2Pos;
Vector3 entArm3Pos;
Vector3 entArm4Pos;
Vector3 entArm5Pos;
Vector3 entArm6Pos;
Vector3 entLegPos;
Vector3 entLeg2Pos;

Vector3 screenHeadPos;
Vector3 screenNeckPos;
Vector3 screenNeck2Pos;
Vector3 screenNeck3Pos;
Vector3 screenNeck4Pos;
Vector3 screenArmPos;
Vector3 screenArm2Pos;
Vector3 screenArm3Pos;
Vector3 screenArm4Pos;
Vector3 screenArm5Pos;
Vector3 screenArm6Pos;
Vector3 screenLegPos;
Vector3 screenLeg2Pos;

void DrawLine3(int x1, int y1, int x2, int y2, RGBA* color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), thickness);
}
void DrawBorder(float x, float y, float w, float h, float px, RGBA* BorderColor)
{
	DrawRect(x, (y + h - px), w, px, BorderColor, 1 / 2);
	DrawRect(x, y, px, h, BorderColor, 1 / 2);
	DrawRect(x, y, w, px, BorderColor, 1 / 2);
	DrawRect((x + w - px), y, px, h, BorderColor, 1 / 2);
}

void DrawHealthBarr(float health, Vector3 tempHead, Vector3 tempFeet)
{
	{
		float height = (tempHead.y - tempFeet.y);
		float width = height / 6.0f;
		float Entity_x = tempFeet.x - width;
		float Entity_y = tempFeet.y;
		float flBoxes = std::ceil(health / 10.f);
		float flX = Entity_x + 6; float flY = Entity_y;
		float flHeight = height / 10.f;
		float flMultiplier = 12 / 360.f; flMultiplier *= flBoxes - 1;
		int G = (255 * health / 100);
		int R = 255 - G;
		RGBA healthcol = { R, G, 0, 255 };

		DrawFilledRect(flX, flY, 2, flHeight * 10 + 2, &Col.black);
		DrawFilledRect(flX + 2, flY, 2, flHeight * 10 + 2, &Col.black);

		DrawFilledRect(flX + 1, flY, 2, flHeight * flBoxes + 1, &healthcol);
	}
}
float r = 1.f;
float g = 0.f;
float b = 0.f;


float Calc2D_Distt(const Vector2& Src, const Vector3& Dst) {
	return sqrt(powf(Src.x - Dst.x, 2) + powf(Src.y - Dst.y, 2));
}

float AimFov(DWORD pEntity2)
{
	Vector3 ScreenPos;
	if (!WorldToScreen(getBonePos(pEntity2, 8), ScreenPos, viewMatrix)) return 1000.f;
	return Calc2D_Distt(Vector2(1920 / 2, 1080 / 2), ScreenPos);
}

float distanceToLocal(DWORD64 pEntity) {
	return getBonePos(pEntity, 8).distancee(getBonePos(playerLocal, 8));
}


class Vector4
{
public:
	Vector4()
	{
		x = y = z = w = 0.f;
	}

	Vector4(float fx, float fy, float fz, float fw)
	{
		x = fx;
		y = fy;
		z = fz;
		w = fw;
	}

	float x, y, z, w;


};
double ToRad(double degree)
{
	double pi = 3.14159265359;
	return (degree * (pi / 180));
}
Vector4 ToQuat(Vector3 Euler) {

	double heading = ToRad(Euler.x);
	double attitude = ToRad(Euler.y);
	double bank = ToRad(Euler.z);

	double c1 = cos(heading / 2);
	double s1 = sin(heading / 2);
	double c2 = cos(attitude / 2);
	double s2 = sin(attitude / 2);
	double c3 = cos(bank / 2);
	double s3 = sin(bank / 2);
	double c1c2 = c1 * c2;
	double s1s2 = s1 * s2;
	Vector4 Quat;
	Quat.w = c1c2 * c3 - s1s2 * s3;
	Quat.x = c1c2 * s3 + s1s2 * c3;
	Quat.y = s1 * c2 * c3 + c1 * s2 * s3;
	Quat.z = c1 * s2 * c3 - s1 * c2 * s3;
	Vector4 Quat2;
	Quat2 = { Quat.y, Quat.z, (Quat.x * -1), Quat.w };
	return Quat2;
}

class CInput {
public:
	char pad0[0xAC]; //0x0000
	bool bCameraInThirdPerson; //0x00AD 
	char pad1[2]; //0x00AE
	Vector3 vecCameraOffset; //0x00B0 
	char pad2[0x18]; //0x00BD
	Vector3 angPreviousViewAngles; //0x00D4 
	Vector3 angPreviousViewAnglesTilt; //0x00E0 
	float flLastForwardMove; //0x00EC 
	int nClearInputState; //0x00F0 

	DWORD commands; //0x00F4 
	DWORD VerifiedCommands; //0x00F8 
};
class CUserCmd {
public:
	DWORD Vft;
	DWORD CmdNumber;
	DWORD TickCount;
	Vector3 ViewAngles;
	Vector3 AimDirection;
	FLOAT Forwardmove;
	FLOAT Sidemove;
	FLOAT Upmove;
	DWORD Buttons;
	BYTE Impulse;
private:
	BYTE __pad0x01[0x03];
public:
	DWORD WeaponSelect;
	DWORD WeaponSubtype;
	DWORD RandomSeed;
	WORD MouseDx;
	WORD MouseDy;
	BOOLEAN HasBeenPredicted;
private:
	BYTE __pad0x02[0x1B];
};
class CVerifiedUserCmd {
public:
	CUserCmd Command;
	DWORD CRC;
};

bool SetSendPackets = false;
static void ChangeViewAngles(Vector2 Angles, bool CanShoot, bool controlrecoil) {
	CInput Input;
	DWORD clientState;

	Input = mem.Read<CInput>(moduleBase_engine + hazedumper::signatures::dwInput);
	clientState = mem.Read<std::uintptr_t>(moduleBase_engine + hazedumper::signatures::dwClientState);

	SetSendPackets = false;
	mem.Write<bool>(moduleBase_engine + SetSendPackets, SetSendPackets);

	Vector3 CurrentAngles = mem.Read<Vector3>(clientState + hazedumper::signatures::dwClientState_ViewAngles);

	int DesiredCmd;
	DesiredCmd = mem.Read<int>(clientState + hazedumper::signatures::clientstate_last_outgoing_command);
	DesiredCmd += 2;

	DWORD IncomingUserCmd = Input.commands + (DesiredCmd % 150) * sizeof(CUserCmd);
	DWORD CurrentUserCmd = Input.commands + ((DesiredCmd - 1) % 150) * sizeof(CUserCmd);
	DWORD VerifiedCurrentUserCmd = Input.VerifiedCommands + ((DesiredCmd - 1) % 150) * sizeof(CVerifiedUserCmd);

	int CmdNumber = NULL;

	while (CmdNumber < DesiredCmd)
	{
		CmdNumber = mem.Read<int>(IncomingUserCmd + 0x4);
	}

	CUserCmd CMD;
	CMD = mem.Read<CUserCmd>(CurrentUserCmd);

	Vector2 vPunch;

	auto pLocalPlayer = mem.Read<DWORD>(moduleBase_client + hazedumper::signatures::dwLocalPlayer);
	vPunch = mem.Read<Vector2>(pLocalPlayer + hazedumper::netvars::m_aimPunchAngle);


	if (controlrecoil == true) {
		CMD.ViewAngles.x = (Angles.x) - (vPunch.x * 2);
		CMD.ViewAngles.y = Angles.y - (vPunch.y * 2);
	}
	else {
		CMD.ViewAngles.x = Angles.x;
		CMD.ViewAngles.y = Angles.y;
	}

	if (CanShoot == true) {
		CMD.Buttons |= TRUE;
	}


	//Normalizing again after we set the view punch (with this one here the first one isnt needed)
	while (CMD.ViewAngles.y > 180)
		CMD.ViewAngles.y -= 360;

	while (CMD.ViewAngles.y < -180)
		CMD.ViewAngles.y += 360;

	if (CMD.ViewAngles.x > 89.0f)
		CMD.ViewAngles.x = 89.0f;

	if (CMD.ViewAngles.x < -89.0f)
		CMD.ViewAngles.x = -89.0f;


	//Writing our angles
	mem.Write<CUserCmd>(CurrentUserCmd, CMD);
	//Sleep(1);
	mem.Write<CUserCmd>(VerifiedCurrentUserCmd, CMD);


	//Setting packet sending back to true
	Sleep(1);
	SetSendPackets = true;
	mem.Write<bool>(moduleBase_engine + hazedumper::signatures::dwbSendPackets, SetSendPackets);
}

float to_degree(float radian)
{
	return radian * 180.f / 3.141592f;
}

float Length(Vector3 v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}
static Vector3 CalcAngle(Vector3 LocalPos, Vector3 EnemyPos)
{
	Vector3 dir;

	dir.x = LocalPos.x - EnemyPos.x;
	dir.y = LocalPos.y - EnemyPos.y;
	dir.z = LocalPos.z - EnemyPos.z;

	float Pitch = to_degree(asin(dir.y / Length(dir)));
	float Yaw = to_degree(-atan2(dir.x, -dir.z));


	Vector3 Return;
	Return.x = Pitch;
	Return.y = Yaw;


	return Return;
}

class player_info_t
{
private:
	char __pad[0x10];
public:
	char name[32];
};

enum CSGO_Weapon_ID
{
	none,
	deagle,
	elite,
	fiveseven,
	glock,
	p228,
	usp,
	ak47,
	aug,
	awp,
	famas,
	g3sg1,
	galil,
	galilar,
	m249,
	m3,
	m4a1,
	mac10,
	mp5navy,
	p90,
	scout,
	sg550,
	sg552,
	tmp,
	ump45,
	xm1014,
	bizon,
	mag7,
	negev,
	sawedoff,
	tec9,
	taser,
	hkp2000,
	mp7,
	mp9,
	nova,
	p250,
	scar17,
	scar20,
	sg556,
	ssg08,
	knifegg,
	knife,
	flashbang,
	hegrenade,
	smokegrenade,
	molotov,
	decoy,
	incgrenade,
	c4
};
static void DrawFilledRectImGui(int x, int y, int w, int h, ImVec4 color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(color), 0, 0);
}
void ESP() {
	if (r == 1.f && g >= 0.f && b <= 0.f)
	{
		g += 0.005f;
		b = 0.f;
	}
	if (r <= 1.f && g >= 1.f && b == 0.f)
	{
		g = 1.f;
		r -= 0.005f;
	}
	if (r <= 0.f && g == 1.f && b >= 0.f)
	{
		r = 0.f;
		b += 0.005f;
	}
	if (r == 0.f && g <= 1.f && b >= 1.f)
	{
		b = 1.f;
		g -= 0.005f;
	}
	if (r >= 0.f && g <= 0.f && b == 1.f)
	{
		g = 0.f;
		r += 0.005f;
	}
	if (r >= 1.f && g >= 0.f && b <= 1.f)
	{
		r = 1.f;
		b -= 0.005f;
	}
	playerLocal = mem.Read<DWORD>(moduleBase_client + hazedumper::signatures::dwLocalPlayer);
	iLocalHp = mem.Read<DWORD>(playerLocal + hazedumper::netvars::m_iHealth);
	iLocalAr = mem.Read<DWORD>(playerLocal + hazedumper::netvars::m_ArmorValue);
	//if (!iLocalHp) {
	//	return;
	//}
	localTeam = mem.Read<DWORD>(playerLocal + 0xF4);
	mem.Read(moduleBase_client + hazedumper::signatures::dwViewMatrix, viewMatrix, 64);

	if (Snipercrosshair)
	{
		DWORD pWeaponHandle = mem.Read<DWORD>(playerLocal + hazedumper::netvars::m_hActiveWeapon);
		int pWeaponEnt = pWeaponHandle & 0xFFF;
		DWORD pWeapon = mem.Read<DWORD>(moduleBase_client + hazedumper::signatures::dwEntityList + (pWeaponEnt - 1) * 0x10);
		int id = mem.Read<int>(pWeapon + hazedumper::netvars::m_iItemDefinitionIndex);

		if (id == 9 || id == 40 || id == 11 || id == 38)
		{
			Crosshair();
		}
	}

	for (int i = 0; i <= 32; i++) {
		pEntity = mem.Read<DWORD>(moduleBase_client + hazedumper::signatures::dwEntityList + (i * 0x10));

		if (!pEntity) {
			continue;
		}
		entHp = mem.Read<DWORD>(pEntity + hazedumper::netvars::m_iHealth);
		if (!entHp) {
			continue;
		}
		entAr = mem.Read<DWORD>(pEntity + hazedumper::netvars::m_ArmorValue);
		entTeam = mem.Read<DWORD>(pEntity + hazedumper::netvars::m_iTeamNum);
		if (entTeam == localTeam) {
			continue;
		}
		if (mem.Read<bool>(pEntity + hazedumper::signatures::m_bDormant)) {
			continue;
		}
		entPos = mem.Read<Vector3>(pEntity + hazedumper::netvars::m_vecOrigin);
		entHeadPos = getBonePos(pEntity, 8);
		if (!WorldToScreen(entPos, screenPos, viewMatrix)) {
			continue;
		}
		if (!WorldToScreen(entHeadPos, screenHeadPos, viewMatrix)) {
			continue;
		}
		boxHeight = abs(screenHeadPos.y - screenPos.y);
		boxWeight = boxHeight / 2;
		middle = screenPos.x - (boxWeight / 2.f);

		uintptr_t dwClientState = mem.Read< uintptr_t >(moduleBase_engine + hazedumper::signatures::dwClientState);
		uintptr_t UserInfoTable = mem.Read< uintptr_t >(dwClientState + hazedumper::signatures::dwClientState_PlayerInfo);
		uintptr_t x = mem.Read< std::uintptr_t >(mem.Read< uintptr_t >(UserInfoTable + 0x40) + 0xC);
		player_info_t p = mem.Read< player_info_t >(mem.Read< uintptr_t >(x + 0x28 + 0x34 * i));

		int distance = (int)distanceToLocal(pEntity) / 25;
		std::string dist("[" + std::to_string(distance) + "m]");

		DWORD pWeaponHandle = mem.Read<DWORD>(pEntity + hazedumper::netvars::m_hActiveWeapon);
		int pWeaponEnt = pWeaponHandle & 0xFFF;
		DWORD CWeaponBase = mem.Read<DWORD>(moduleBase_client + hazedumper::signatures::dwEntityList + (-0x10 + (pWeaponEnt * 0x10)));
		int AMMO = mem.Read<DWORD>(CWeaponBase + hazedumper::netvars::m_iClip1);
		std::string wammo = "Ammo: " + std::to_string(AMMO);

		if (infopanel)
		{
			if (AimFov(pEntity) < 25)
			{
				ImGui::SetNextWindowSize(ImVec2(180, 100));
				ImGui::SetNextWindowPos(ImVec2(1670, 1080 / 1080));
				ImGui::Begin(skCrypt("TargetPlayer"), NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

				ImGui::Text("Name:"); ImGui::SameLine();
				ImGui::TextColored(ImColor(255, 255, 0), p.name);

				std::string healthhh(std::to_string(entHp));
				ImGui::Text("Health:");
				ImGui::SameLine();
				int Ger = (255 * entHp / 100);
				int Rer = 255 - Ger;
				ImGui::TextColored(ImColor(Rer, Ger, 0), (healthhh.c_str()));

				std::string Armorrr(std::to_string(entAr));
				ImGui::Text("Armor:");
				ImGui::SameLine();
				int Ger2 = (1 * entAr / 100);
				int Rer2 = 255 - Ger;
				ImGui::TextColored(ImColor(Ger2, Rer2, 255), (Armorrr.c_str()));

				ImGui::Text("Distance:");		ImGui::SameLine();
				ImGui::TextColored(ImColor(236, 236, 236), dist.c_str());


				ImGui::TextColored(ImColor(255, 255, 255), wammo.c_str());
				ImGui::End();
			}
		}	



		if (Enableesp)
		{
			
			if (distance < distanceint)
			{
				if (nameesp)
				{

					DrawString(12, screenHeadPos.x, (screenHeadPos.y), &Col.white, true, true, p.name);
				}
				if (skeletonesp)
				{
					entNeckPos = getBonePos(pEntity, 9);
					if (!WorldToScreen(entNeckPos, screenNeckPos, viewMatrix)) {
						continue;
					}
					entNeck2Pos = getBonePos(pEntity, 7);
					if (!WorldToScreen(entNeck2Pos, screenNeck2Pos, viewMatrix)) {
						continue;
					}
					entNeck3Pos = getBonePos(pEntity, 5);
					if (!WorldToScreen(entNeck3Pos, screenNeck3Pos, viewMatrix)) {
						continue;
					}
					entNeck4Pos = getBonePos(pEntity, 3);
					if (!WorldToScreen(entNeck4Pos, screenNeck4Pos, viewMatrix)) {
						continue;
					}
					entArmPos = getBonePos(pEntity, 11);
					if (!WorldToScreen(entArmPos, screenArmPos, viewMatrix)) {
						continue;
					}
					entArm2Pos = getBonePos(pEntity, 12);
					if (!WorldToScreen(entArm2Pos, screenArm2Pos, viewMatrix)) {
						continue;
					}
					entArm3Pos = getBonePos(pEntity, 13);
					if (!WorldToScreen(entArm3Pos, screenArm3Pos, viewMatrix)) {
						continue;
					}
					entArm4Pos = getBonePos(pEntity, 39);
					if (!WorldToScreen(entArm4Pos, screenArm4Pos, viewMatrix)) {
						continue;
					}
					entArm5Pos = getBonePos(pEntity, 40);
					if (!WorldToScreen(entArm5Pos, screenArm5Pos, viewMatrix)) {
						continue;
					}
					entArm6Pos = getBonePos(pEntity, 41);
					if (!WorldToScreen(entArm6Pos, screenArm6Pos, viewMatrix)) {
						continue;
					}
					entLegPos = getBonePos(pEntity, 74);
					if (!WorldToScreen(entLegPos, screenLegPos, viewMatrix)) {
						continue;
					}
					entLeg2Pos = getBonePos(pEntity, 69);
					if (!WorldToScreen(entLeg2Pos, screenLeg2Pos, viewMatrix)) {
						continue;
					}
					DrawLine(ImVec2(screenHeadPos.x - 2, screenHeadPos.y - 2), ImVec2(screenHeadPos.x, screenHeadPos.y), ImColor(255,255,255), 1.f);
					DrawLine(ImVec2(screenHeadPos.x, screenHeadPos.y), ImVec2(screenNeck2Pos.x, screenNeck2Pos.y), ImColor(255, 255, 255), 1.f);
					DrawLine(ImVec2(screenNeck2Pos.x, screenNeck2Pos.y), ImVec2(screenNeck3Pos.x, screenNeck3Pos.y), ImColor(255, 255, 255), 1.f);
					DrawLine(ImVec2(screenNeck3Pos.x, screenNeck3Pos.y), ImVec2(screenNeck4Pos.x, screenNeck4Pos.y), ImColor(255, 255, 255), 1.f);
					DrawLine(ImVec2(screenHeadPos.x, screenHeadPos.y), ImVec2(screenArmPos.x, screenArmPos.y), ImColor(255, 255, 255), 1.f);
					DrawLine(ImVec2(screenArmPos.x, screenArmPos.y), ImVec2(screenArm2Pos.x, screenArm2Pos.y), ImColor(255, 255, 255), 1.f);
					DrawLine(ImVec2(screenArm2Pos.x, screenArm2Pos.y), ImVec2(screenArm3Pos.x, screenArm3Pos.y), ImColor(255, 255, 255), 1.f);
					DrawLine(ImVec2(screenHeadPos.x, screenHeadPos.y), ImVec2(screenArm4Pos.x, screenArm4Pos.y), ImColor(255, 255, 255), 1.f);
					DrawLine(ImVec2(screenArm4Pos.x, screenArm4Pos.y), ImVec2(screenArm5Pos.x, screenArm5Pos.y), ImColor(255, 255, 255), 1.f);
					DrawLine(ImVec2(screenArm5Pos.x, screenArm5Pos.y), ImVec2(screenArm6Pos.x, screenArm6Pos.y), ImColor(255, 255, 255), 1.f);
					DrawLine(ImVec2(screenNeck4Pos.x, screenNeck4Pos.y), ImVec2(screenLegPos.x, screenLegPos.y), ImColor(255, 255, 255), 1.f);
					DrawLine(ImVec2(screenNeck4Pos.x, screenNeck4Pos.y), ImVec2(screenLeg2Pos.x, screenLeg2Pos.y), ImColor(255, 255, 255), 1.f);
				}	
				if (esp)
				{
					//DrawBox(middle, screenHeadPos.y - 5,	 boxWeight, boxHeight + 5);
					DrawRectImGui(screenPos.x - (boxWeight / 2) - 1, screenHeadPos.y - 1, boxWeight + 2, boxHeight + 2, ImVec4(0.f, 0.f, 0.f, 255.f), 1.0f);
					DrawRectImGui(screenPos.x - (boxWeight / 2), screenHeadPos.y, boxWeight, boxHeight, ImVec4(255.f, 255.f, 255.f, 255.f), 1.f);
					DrawRectImGui(screenPos.x - (boxWeight / 2) + 1, screenHeadPos.y + 1, boxWeight - 2, boxHeight - 2, ImVec4(0.f, 0.f, 0.f, 255.f), 1.0f);
				}
				if (esp2)
				{
					//DrawBox(middle, screenHeadPos.y - 5,	 boxWeight, boxHeight + 5);
					DrawCorneredBox(screenPos.x - (boxWeight / 2) - 1, screenHeadPos.y - 1, boxWeight + 2, boxHeight + 2, ImVec4(0.f, 0.f, 0.f, 255.f), 1.0f);
					DrawCorneredBox(screenPos.x - (boxWeight / 2), screenHeadPos.y, boxWeight, boxHeight, ImVec4(255.f, 255.f, 255.f, 255.f), 1.f);
					DrawCorneredBox(screenPos.x - (boxWeight / 2) + 1, screenHeadPos.y + 1, boxWeight - 2, boxHeight - 2, ImVec4(0.f, 0.f, 0.f, 255.f), 1.0f);
				}
				if (paintinside)
				{
					DrawFilledRectImGui(screenPos.x - (boxWeight / 2), screenHeadPos.y, boxWeight, boxHeight, ImVec4(COLOUR(0.0f), COLOUR(0.0f), COLOUR(0.0f), COLOUR(100.0f)));
				}
				if (headesp)
				{
					ImGui::GetOverlayDrawList()->AddCircle(ImVec2(screenHeadPos.x, screenHeadPos.y), 4, ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 255)), 12, 0);
					ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(screenHeadPos.x, screenHeadPos.y), 3, ImGui::ColorConvertFloat4ToU32(ImVec4(255, 255, 255, 255)), 12);
				}
				if (Snapline)
				{
					DrawLine(ImVec2(GetWindowSize().x / 2, GetWindowSize().y), ImVec2(screenPos.x, screenPos.y), ImGui::ColorConvertFloat4ToU32(ImVec4(0.f, 0.f, 0.f, 255.f)), 1.f); // ASAGIDAN
				}
				if (triggeralert)
				{
					int CrosshairID = mem.Read<int>(playerLocal + hazedumper::netvars::m_iCrosshairId);
					int CrosshairTeam = getTeam(getPlayer(CrosshairID - 1));
					int LocalTeam = getTeam(playerLocal);
					if (CrosshairID > 1 && CrosshairID < 64 && LocalTeam != CrosshairTeam)
					{
						ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), 10, IM_COL32(255, 0, 0, 255), 10000, 1);
					}
				}
				if (weaponinfo)
				{

					DWORD pWeapon = mem.Read<DWORD>(moduleBase_client + hazedumper::signatures::dwEntityList + (pWeaponEnt - 1) * 0x10);
					int id = mem.Read<int>(pWeapon + hazedumper::netvars::m_iItemDefinitionIndex);

					//std::string weaponid = std::to_string(id);
					//DrawString(15, screenPos.x + 1, (screenPos.y + 30), &Col.red, true, false, weaponid.c_str());



					if (ammoesp)
					{
						int G = (255 * AMMO / 30);
						int R = 255 - G;
						RGBA AmmoCol = { R, G, 0, 255 };
						if (id == knife || id == knifegg || id == 59)
						{
						}
						else
						{
							DrawString(15, screenPos.x + 1, (screenPos.y), &AmmoCol, true, false, wammo.c_str());
						}
					}

					ImGui::PushFont(iconfont);
					if (id == deagle)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, DESERTEAGLE);
					}
					if (id == elite)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, DUALBERETTA);
					}
					if (id == fiveseven)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, FIVESEVEN);
					}
					if (id == glock)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, GLOCK18);
					}
					if (id == ak47)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, AK47);
					}
					if (id == aug)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, AUG);
					}
					if (id == awp)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, AWP);
					}
					if (id == famas)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, FAMAS);
					}
					if (id == g3sg1)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, G3SG1);
					}
					if (id == galil)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, GALILAR);
					}
					if (id == galilar)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, GALILAR);
					}
					if (id == m249)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, M249);
					}
					if (id == m4a1)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, M4A1);
					}
					if (id == 262151)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, AK47);
					}
					if (id == 262153)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, AWP);
					}
					if (id == 262160)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, M4A1);
					}
					if (id == 262204)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, M4A1);
					}
					if (id == 262205)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, USPS);
					}
					if (id == mac10)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, MAC10);
					}
					if (id == p90)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, P90);
					}
					if (id == mp5navy)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, MP7);
					}
					if (id == tmp)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, MP7);
					}
					if (id == ump45)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, UMP45);
					}
					if (id == xm1014)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, XM1014);
					}
					if (id == bizon)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, PPBIZON);
					}
					if (id == mag7)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, MAG7);
					}
					if (id == negev)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, NEGEV);
					}
					if (id == sawedoff)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, SAWEDOFF);
					}
					if (id == tec9)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, TEC9);
					}
					if (id == taser)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, TASER);
					}
					if (id == hkp2000)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, P2000);
					}
					if (id == mp7)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, MP7);
					}
					if (id == mp9)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, MP9);
					}
					if (id == nova)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, NOVA);
					}
					if (id == p250)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, P250);
					}
					if (id == scar20)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, SCAR20);
					}
					if (id == sg556)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, SG556);
					}
					if (id == ssg08)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, SSG08);
					}
					if (id == knife)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, KNIFE);
					}
					if (id == knifegg)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, KNIFE);
					}
					if (id == flashbang)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, FLASHBANG);
					}
					if (id == hegrenade)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, GRENADE);
					}
					if (id == smokegrenade)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, SMOKE);
					}
					if (id == molotov)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, MOLOTOV);
					}
					if (id == incgrenade)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, MOLOTOV);
					}
					if (id == decoy)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, DECOY);
					}
					if (id == c4)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, C4);
					}
					if (id == 59)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, KNIFE);
					}
					if (id == 60)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, M4A1);
					}
					if (id == 61)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, USPS);
					}
					if (id == 63)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, CZ75);
					}
					if (id == 64)
					{
						DrawString2(15, screenPos.x - 3, (screenPos.y + 15), ImGui::ColorConvertFloat4ToU32(cRainbow), true, false, R8REVOLVER);
					}
					ImGui::PopFont();
				}
				if (HealthBar)
				{
					if (entHp > 101) entHp = 100;
					float HealthHeightCalc = ((float)entHp / 100) * (float)boxHeight;

					DrawFilledRectImGui(screenPos.x - (boxWeight / 2), screenHeadPos.y, 2, boxHeight, ImVec4(COLOUR(30.0f), COLOUR(30.0f), COLOUR(30.0f), COLOUR(220.0f)));
					DrawFilledRectImGui(screenPos.x - (boxWeight / 2), screenHeadPos.y, 2, HealthHeightCalc, ImVec4(COLOUR(80.0f), COLOUR(220.0f), COLOUR(100.0f), COLOUR(255.0f)));

					//DrawHealthBarr(entHp, screenHeadPos, screenPos);
					//DrawLeftProgressBar(screenHeadPos.x, screenHeadPos.y, boxWeight, boxHeight, 2, entHp);
				}
				if (distanceesp)
				{
					DrawString(12, screenPos.x, screenPos.y + 15, &Col.silverwhite_, true, true, dist.c_str());
				}
			}
		}
	}
}

void style()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowRounding = 5.0f;
	style.WindowBorderSize = 2.0f;

	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.85f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.17f, 0.17f, 0.17f, 0.85f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TableBorderLight] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);
}




void render()
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImVec2 curPos = ImGui::GetCursorPos();
	ImVec2 curWindowPos = ImGui::GetWindowPos();
	curPos.x += curWindowPos.x;
	curPos.y += curWindowPos.y;
	static float flRainbow;
	float flSpeed = 0.0025f;
	flRainbow += flSpeed;
	if (flRainbow > 1.f) flRainbow = 0.f;
	for (int i = 0; i < 485; i++)
	{
		float hue = (1.f / (float)485) * i;
		hue -= flRainbow;
		if (hue < 0.f) hue += 1.f;

		cRainbow = ImColor::HSV(hue, 1.f, 1.f);
		//ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(curPos.x + i, 10), ImVec2(curPos.x + 485, curPos.y - 3), cRainbow);
	}

	if (AimBot)
	{
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), aimbotfov, IM_COL32_WHITE, 10000, 1);
	}

	
	ESP();

	if (GetAsyncKeyState(VK_INSERT) & 1) { showmenu = !showmenu; }

	if (GetAsyncKeyState(VK_END) & 1) { exit(0); }

	if (showmenu) { draw_menu(); }
	ImGui::EndFrame();
	p_Device->SetRenderState(D3DRS_ZENABLE, false);
	p_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	p_Device->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	p_Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (p_Device->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		p_Device->EndScene();
	}

	HRESULT result = p_Device->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && p_Device->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		p_Device->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}
float brightness = 1;

void hiletridi()
{
	while (true)
	{
		if (Chams == true)
		{
			for (int x = 1; x < 32; x++)
			{
				const auto Nesne = mem.Read<std::uintptr_t>(moduleBase_client + hazedumper::signatures::dwEntityList + x * 0x10);
				mem.Write<BYTE>(Nesne + 0x70, r);
				mem.Write<BYTE>(Nesne + 0x71, g);
				mem.Write<BYTE>(Nesne + 0x72, b);
			}
			//Model Brightness
			DWORD thisPtr = (int)(moduleBase_engine + hazedumper::signatures::model_ambient_min - 0x2c);
			DWORD xored = *(DWORD*)&brightness ^ thisPtr;
			brightness = 50000;
			mem.Write<int>(moduleBase_engine + hazedumper::signatures::model_ambient_min, xored);
		}
		else
		{
			brightness = 0;
			DWORD thisPtr = (int)(moduleBase_engine + hazedumper::signatures::model_ambient_min - 0x2c);
			DWORD xored = *(DWORD*)&brightness ^ thisPtr;
			mem.Write<int>(moduleBase_engine + hazedumper::signatures::model_ambient_min, xored);
		}
		if (Radar == true)
		{
			for (int i = 1; i < 64; i++) {
				DWORD dwCurrentEntity = mem.Read<DWORD>(moduleBase_client + hazedumper::signatures::dwEntityList + i * 0x10);
				if (dwCurrentEntity) {
					mem.Write<bool>(dwCurrentEntity + hazedumper::netvars::m_bSpotted, true);
				}
			}
		}
		if (Glow == true)
		{
			if (!playerLocal)
				continue;
			const auto LokayOyuncum_iTeamNum = mem.Read<std::uintptr_t>(playerLocal + hazedumper::netvars::m_iTeamNum);
			const auto dwplayerLocalBayragi = mem.Read<std::uintptr_t>(playerLocal + hazedumper::netvars::m_fFlags);
			const auto dwGlowObjectManager = mem.Read<std::uintptr_t>(moduleBase_client + hazedumper::signatures::dwGlowObjectManager);

			for (auto i = 1; i <= 32; ++i)
			{
				const auto Nesne = mem.Read<std::uintptr_t>(moduleBase_client + hazedumper::signatures::dwEntityList + i * 0x10);
				if (!Nesne)
					continue;
				const auto Gosterge = mem.Read<std::int32_t>(Nesne + hazedumper::netvars::m_iGlowIndex);
				if (mem.Read<std::uintptr_t>(Nesne + hazedumper::netvars::m_iTeamNum) == LokayOyuncum_iTeamNum)
				{
					mem.Write<float>(dwGlowObjectManager + (Gosterge * 0x38) + 0x8, 255); // r
					mem.Write<float>(dwGlowObjectManager + (Gosterge * 0x38) + 0xC, 255); // g
					mem.Write<float>(dwGlowObjectManager + (Gosterge * 0x38) + 0x10, 255); // b
					mem.Write<float>(dwGlowObjectManager + (Gosterge * 0x38) + 0x14, 255); // a
				}
				else
				{
					mem.Write<float>(dwGlowObjectManager + (Gosterge * 0x38) + 0x8, 255); // r
					mem.Write<float>(dwGlowObjectManager + (Gosterge * 0x38) + 0xC, 0); // g
					mem.Write<float>(dwGlowObjectManager + (Gosterge * 0x38) + 0x10, 0); // b
					mem.Write<float>(dwGlowObjectManager + (Gosterge * 0x38) + 0x14, 255); // a
				}

				mem.Write<bool>(dwGlowObjectManager + (Gosterge * 0x38) + 0x28, true);
				mem.Write<bool>(dwGlowObjectManager + (Gosterge * 0x38) + 0x29, false);
			}
		}

		if (BunnyHop)
		{
			const auto playerLocalTeam = mem.Read<std::uintptr_t>(playerLocal + hazedumper::netvars::m_iTeamNum);
			const auto playerLocalFlags = mem.Read<std::uintptr_t>(playerLocal + hazedumper::netvars::m_fFlags);
			if (GetAsyncKeyState(VK_SPACE))
				(playerLocalFlags & (1 << 0)) ?
				mem.Write<std::uintptr_t>(moduleBase_client + hazedumper::signatures::dwForceJump, 6) :
				mem.Write<std::uintptr_t>(moduleBase_client + hazedumper::signatures::dwForceJump, 4);
		}

		if (NoFlash == true)
		{
			if (mem.Read<float>(playerLocal + hazedumper::netvars::m_flFlashMaxAlpha) > 0.0f)
			{
				mem.Write<float>(playerLocal + hazedumper::netvars::m_flFlashMaxAlpha, 0.0f);
			}
		}
		else if (mem.Read<float>(playerLocal + hazedumper::netvars::m_flFlashMaxAlpha) == 0.0f)
		{
			mem.Write<float>(playerLocal + hazedumper::netvars::m_flFlashMaxAlpha, 255.0f);
		}

		if (triggerbot == true)
		{
			int CrosshairID = mem.Read<int>(playerLocal + hazedumper::netvars::m_iCrosshairId);
			int CrosshairTeam = getTeam(getPlayer(CrosshairID - 1));
			int LocalTeam = getTeam(playerLocal);
			if (CrosshairID > 1 && CrosshairID < 64 && LocalTeam != CrosshairTeam)
			{
				mem.Write<BYTE>(moduleBase_client + hazedumper::signatures::dwForceAttack, 5);
				Sleep(15);
				mem.Write<BYTE>(moduleBase_client + hazedumper::signatures::dwForceAttack, 4);
			}
		}
		if (skinchanger)
		{
			const auto weapons = mem.Read<std::array<unsigned long, 8>>(playerLocal + hazedumper::netvars::m_hMyWeapons);

			for (const auto& handle : weapons)
			{
				const auto weapon = mem.Read<uintptr_t>((moduleBase_client + hazedumper::signatures::dwEntityList + (handle & 0xFFF) * 0x10) - 0x10);

				if (!weapon)
					continue;


				const auto paint = GetWeaponPaint(mem.Read<short>(weapon + hazedumper::netvars::m_iItemDefinitionIndex));


				if (paint)
				{
					const bool shouldUpdate = mem.Read<std::int32_t>(weapon + hazedumper::netvars::m_nFallbackPaintKit) != paint;



					mem.Write<std::int32_t>(weapon + hazedumper::netvars::m_iItemIDHigh, -1);
					mem.Write<std::int32_t>(weapon + hazedumper::netvars::m_nFallbackPaintKit, paint);
					mem.Write<float>(weapon + hazedumper::netvars::m_flFallbackWear, 0.1f);
					//mem.Write<std::int32_t>(weapon + offset::m_nFallbackSeed, -1);
					//mem.Write<std::int32_t>(weapon + offset::m_nFallbackStatTrak, 1337);


					if (shouldUpdate)
						mem.Write<std::int32_t>(mem.Read<std::uintptr_t>(moduleBase_engine + hazedumper::signatures::dwClientState) + 0x174, -1);
				}

			}
		}

		if (Fov == true)
		{
			Fovtamiri = false;
			mem.Write<int>(playerLocal + hazedumper::netvars::m_iFOV, fovv);
		}
		else
		{
			if (!Fovtamiri)
			{
				mem.Write<int>(playerLocal + hazedumper::netvars::m_iFOV, 90);
				Sleep(15);
				mem.Write<int>(playerLocal + hazedumper::netvars::m_iFOV, 90);
				Fovtamiri = true;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}




void aimbottridi()
{
	while (true)
	{
		if (AimBot == true)
		{
			const auto localTeam = mem.Read<std::int32_t>(playerLocal + hazedumper::netvars::m_iTeamNum);
			const auto localEyePosition = mem.Read<Vector3>(playerLocal + hazedumper::netvars::m_vecOrigin) + mem.Read<Vector3>(playerLocal + hazedumper::netvars::m_vecViewOffset);
			const auto Input = mem.Read<std::uintptr_t>(moduleBase_engine + hazedumper::signatures::dwInput);
			const auto clientState = mem.Read<std::uintptr_t>(moduleBase_engine + hazedumper::signatures::dwClientState);
			const auto viewAngles = mem.Read<Vector3>(clientState + hazedumper::signatures::dwClientState_ViewAngles);
			const auto aimPunch = mem.Read<Vector3>(playerLocal + hazedumper::netvars::m_aimPunchAngle) * 2;
			auto bestAngle = Vector3{ };
			for (auto i = 1; i <= 32; ++i)
			{
				const auto player = mem.Read<std::uintptr_t>(moduleBase_client + hazedumper::signatures::dwEntityList + i * 0x10);

				if (mem.Read<std::int32_t>(player + hazedumper::netvars::m_iTeamNum) == localTeam)
					continue;
				if (mem.Read<bool>(player + hazedumper::signatures::m_bDormant))
					continue;
				if (mem.Read<std::int32_t>(player + hazedumper::netvars::m_lifeState))
					continue;

				const auto angle = CalculateAngle(localEyePosition, getBonePos(player, kitlenmee), viewAngles + aimPunch);
				bestAngle = angle;

				if (GetAsyncKeyState(aimkey))
				{
					if (AimFov(player) < aimbotfov)
					{
						if (!bestAngle.IsZero())
						{
							/*if (mem.Read<std::int32_t>(player + hazedumper::netvars::m_bSpottedByMask) & (1 << playerLocal))
							{*/
							if (aimbott)
							{
								mem.Write<Vector3>(clientState + hazedumper::signatures::dwClientState_ViewAngles, viewAngles + bestAngle / aimbottt); // smoothing
							}
							if (silent)
							{
								mem.Write<Vector3>(clientState + hazedumper::signatures::dwClientState_ViewAngles, viewAngles + bestAngle / aimbottt); // smoothing
								mem.Write<BYTE>(moduleBase_client + hazedumper::signatures::dwForceAttack, 5);
								Sleep(1);
								mem.Write<BYTE>(moduleBase_client + hazedumper::signatures::dwForceAttack, 4);
								mem.Write<Vector3>(clientState + hazedumper::signatures::dwClientState_ViewAngles, viewAngles / aimbottt); // smoothing
							}
						}
					}
				}
			}
		}	
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

#include "protect/protectmain.h"

int main()
{
	mainprotect();
	SetConsoleTitle(L"WWW.ALIENCHEATS.COM");
	int horizontal = 0, vertical = 0;
	int x = 350, y = 250; //// alta doðru

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	SetConsoleCursorInfo(out, &cursorInfo);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 15;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	system("color 9");
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	HWND hwnd = GetConsoleWindow();
	MoveWindow(hwnd, 0, 0, x, y, TRUE);
	LONG lStyle = GetWindowLong(hwnd, GWL_STYLE);
	lStyle &= ~(WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
	SetWindowLong(hwnd, GWL_STYLE, lStyle);
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(console, &csbi);
	COORD scrollbar = {
		csbi.srWindow.Right - csbi.srWindow.Left + 1,
		csbi.srWindow.Bottom - csbi.srWindow.Top + 1
	};
	if (console == 0)
		throw 0;
	else
		SetConsoleScreenBufferSize(console, scrollbar);
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hwnd, 0, 225, LWA_ALPHA);

	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);


	KeyAuthApp.init();
	std::string key;
	system(("cls"));
	std::cout << ("\n\n  [+] Connecting..");
	std::cout << ("\n\n  [+] License: ");
	std::cin >> key;
	KeyAuthApp.license(key);
	if (!KeyAuthApp.data.success)
	{
		std::cout << ("\n Status: ") + KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}

	::ShowWindow(::GetConsoleWindow(), SW_HIDE);



	HWND Entryhwnd = NULL;
	while (Entryhwnd == NULL)
	{
		printf(skCrypt("[>] waiting for game\n"));
		Sleep(1);
		p_pid = get_pid();
		printf(skCrypt("[>] pid: %d\n"), p_pid);
		Entryhwnd = get_process_wnd(p_pid);
		Sleep(1);
	}
	setup_window();
	init_wndparams(MyWnd);

	if (mem.GetInfoWindow(L"Counter-Strike: Global Offensive - Direct3D 9", procces_id, game));
	moduleBase_client = mem.GetModuleBaseAddress(procces_id, L"client.dll");
	moduleBase_engine = mem.GetModuleBaseAddress(procces_id, L"engine.dll");

	static RECT old_rc;
	ZeroMemory(&Message, sizeof(MSG));
	//::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	style();

	std::thread(hiletridi).detach();
	std::thread(aimbottridi).detach();
	while (Message.message != WM_QUIT)
	{
		if (PeekMessage(&Message, MyWnd, 0, 0, PM_REMOVE)) {
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		HWND hwnd_active = GetForegroundWindow();


		if (hwnd_active == GameWnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(MyWnd, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}
		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(GameWnd, &rc);
		ClientToScreen(GameWnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = GameWnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;
		if (GetAsyncKeyState(0x1)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else io.MouseDown[0] = false;

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom) {

			old_rc = rc;

			Width = rc.right;
			Height = rc.bottom;

			p_Params.BackBufferWidth = Width;
			p_Params.BackBufferHeight = Height;
			SetWindowPos(MyWnd, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			p_Device->Reset(&p_Params);
		}
		render();
		Sleep(10);
	}

	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	cleanup_d3d();
	DestroyWindow(MyWnd);
	return Message.wParam;
}