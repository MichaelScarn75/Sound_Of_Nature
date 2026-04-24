#include <stddef.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "MinHook.h"

typedef uint32_t AkUniqueID;
typedef uint32_t AkPlayingID;
typedef uint64_t AkGameObjectID;
typedef int32_t AKRESULT;

typedef struct Config {
    BOOL enabled;
    BOOL verbose_log;
    BOOL enable_player_voice_hooks;
    BOOL enable_mark_hotkey;
    uint32_t mark_hotkey_virtual_key;
    BOOL chain_post_event_relay;
    BOOL mute_bike_driving_sound;
    BOOL mute_get_off_bike;
    BOOL mute_bike_retracts_after_get_off;
    BOOL mute_get_on_bike;
    BOOL mute_get_on_bike_left_side;
    BOOL mute_get_on_bike_right_side;
    BOOL mute_get_on_bike_law_and_order_ding_ding;
    BOOL mute_run_get_on_bike_right_and_front_side;
    BOOL mute_run_get_on_bike_left_side;
    BOOL mute_armor_activated_on_bike_mount_1;
    BOOL mute_armor_activated_on_bike_mount_2;
    BOOL mute_armor_activated_on_bike_mount_3;
    BOOL mute_armor_activated_on_bike_mount_4;
    BOOL mute_armor_deactivated_on_bike_unmount_1;
    BOOL mute_armor_deactivated_on_bike_unmount_2;
    BOOL mute_get_on_car_front_side;
    BOOL mute_get_on_armored_car_left_side;
    BOOL mute_get_on_armored_car_right_side;
    BOOL mute_get_on_non_armored_car_left_side;
    BOOL mute_get_on_non_armored_car_right_side;
    BOOL mute_get_on_car_law_and_order_ding_ding;
    BOOL mute_loud_noise_after_get_on_car;
    BOOL mute_car_retracts_after_get_off_1;
    BOOL mute_car_retracts_after_get_off_2;
    BOOL mute_beeping_noise_while_driving_car;
    BOOL mute_suspension_noise_while_driving_car;
    BOOL mute_command_prompt_appears;
    BOOL mute_skeleton;
    BOOL mute_loud_HEADOUT;
    BOOL mute_get_on_attached_floating_carrier;
    BOOL mute_get_on_detached_floating_carrier;
    BOOL mute_get_off_floating_carrier;
    BOOL mute_floating_carrier_drive_sound;
    BOOL mute_two_floating_carrier_drive_sound;
    BOOL mute_floating_carrier_squeak_noise;
    BOOL mute_get_on_coffin_board;
    BOOL mute_get_off_coffin_board;
    BOOL mute_main_menu_button_hover;
    BOOL mute_setting_tab_click;
    BOOL mute_setting_option_previous_value_and_slider;
    BOOL mute_setting_option_next_value;
    BOOL mute_setting_menu_click;
    BOOL mute_setting_menu_return;
    BOOL mute_load_save_menu_hover;
    BOOL mute_load_save_menu_return;
    BOOL mute_esc_open_system_menu;
    BOOL mute_esc_close_system_menu;
    BOOL mute_setting_menu_back_to_system_menu;
    BOOL mute_use_terminal;
    BOOL mute_use_terminal_prompt_spin;
    BOOL mute_enter_facility_bang;
    BOOL mute_enter_facility_scan;
    BOOL mute_facility_shut_down_bang;
    BOOL mute_enter_private_room;
    BOOL mute_rest_in_shelter;
    BOOL mute_open_pause_menu;
    BOOL mute_close_pause_menu;
    BOOL mute_terminal_selection;
    BOOL mute_open_map;
    BOOL mute_flood_or_bushfire_warning_in_map;
    BOOL mute_cargo_management_selection;
    BOOL mute_placement_options;
    BOOL mute_map_facility_hover;
    BOOL mute_qpid_enter_and_return_orders;
    BOOL mute_route_simulation_in_orders;
    BOOL mute_hover_on_orders;
    BOOL mute_switch_map_info;
    BOOL mute_place_marker_on_map;
    BOOL mute_zoomming_in_and_out_in_map;
    BOOL mute_pan_around_the_map;
    BOOL mute_wear_clothes;
    BOOL mute_wear_hats;
    BOOL mute_wear_glasses;
    BOOL mute_take_off_glasses;
    BOOL mute_wear_BB;
    BOOL mute_wear_mask;
    BOOL mute_change_cosmetics_color;
    BOOL mute_fabricate_vehicle;
    BOOL mute_claim_material_menu;
    BOOL mute_notification_yellow;
    BOOL mute_notification_white;
    BOOL mute_sam_breathing;
} Config;

typedef AkPlayingID(__cdecl *PostEventIdFn)(
    AkUniqueID event_id,
    AkGameObjectID game_object_id,
    uint32_t callback_mask,
    void *callback,
    void *cookie,
    uint32_t external_source_count,
    void *external_sources,
    uint32_t playing_id);
typedef AkUniqueID(__cdecl *GetIdFromStringAFn)(const char *name);
typedef AkUniqueID(__cdecl *GetIdFromStringWFn)(const wchar_t *name);
typedef AkPlayingID(__cdecl *PostEventNameAFn)(
    const char *event_name,
    AkGameObjectID game_object_id,
    uint32_t callback_mask,
    void *callback,
    void *cookie,
    uint32_t external_source_count,
    void *external_sources,
    uint32_t playing_id);
typedef AkPlayingID(__cdecl *PostEventNameWFn)(
    const wchar_t *event_name,
    AkGameObjectID game_object_id,
    uint32_t callback_mask,
    void *callback,
    void *cookie,
    uint32_t external_source_count,
    void *external_sources,
    uint32_t playing_id);
typedef AKRESULT(__cdecl *SetStateAFn)(const char *group_name, const char *state_name);
typedef AKRESULT(__cdecl *SetStateWFn)(const wchar_t *group_name, const wchar_t *state_name);
typedef AKRESULT(__cdecl *SetStateIdFn)(AkUniqueID group_id, AkUniqueID state_id);
typedef AKRESULT(__cdecl *SetSwitchAFn)(const char *group_name, const char *state_name, AkGameObjectID game_object_id);
typedef AKRESULT(__cdecl *SetSwitchWFn)(const wchar_t *group_name, const wchar_t *state_name, AkGameObjectID game_object_id);
typedef AKRESULT(__cdecl *SetSwitchIdFn)(AkUniqueID group_id, AkUniqueID state_id, AkGameObjectID game_object_id);
typedef AKRESULT(__cdecl *PostTriggerAFn)(const char *trigger_name, AkGameObjectID game_object_id);
typedef AKRESULT(__cdecl *PostTriggerWFn)(const wchar_t *trigger_name, AkGameObjectID game_object_id);
typedef AKRESULT(__cdecl *PostTriggerIdFn)(AkUniqueID trigger_id, AkGameObjectID game_object_id);
typedef AKRESULT(__cdecl *SetRtpcValueAFn)(const char *rtpc_name, float value, AkGameObjectID game_object_id, int32_t interpolation_time_ms, int32_t fade_curve, BOOL bypass_game_param);
typedef AKRESULT(__cdecl *SetRtpcValueWFn)(const wchar_t *rtpc_name, float value, AkGameObjectID game_object_id, int32_t interpolation_time_ms, int32_t fade_curve, BOOL bypass_game_param);
typedef AKRESULT(__cdecl *SetRtpcValueIdFn)(AkUniqueID rtpc_id, float value, AkGameObjectID game_object_id, int32_t interpolation_time_ms, int32_t fade_curve, BOOL bypass_game_param);
typedef uintptr_t(__fastcall *GenericVoiceFn5)(
    const void *arg1,
    uintptr_t arg2,
    uintptr_t arg3,
    uintptr_t arg4,
    uintptr_t arg5);
typedef uintptr_t(__fastcall *GenericVoiceFn7)(
    const void *arg1,
    uintptr_t arg2,
    uintptr_t arg3,
    uintptr_t arg4,
    uintptr_t arg5,
    uintptr_t arg6,
    uintptr_t arg7);

static HMODULE g_self_module = NULL;
static CRITICAL_SECTION g_log_lock;
static CRITICAL_SECTION g_trace_lock;
static Config g_cfg;
static char g_ini_path[MAX_PATH];
static char g_log_path[MAX_PATH];
static BOOL g_hooks_installed = FALSE;
static volatile BOOL g_mark_hotkey_thread_running = FALSE;

static PostEventIdFn g_real_post_event_id = NULL;
static GetIdFromStringAFn g_real_get_id_from_string_a = NULL;
static GetIdFromStringWFn g_real_get_id_from_string_w = NULL;
static PostEventNameAFn g_real_post_event_name_a = NULL;
static PostEventNameWFn g_real_post_event_name_w = NULL;
static SetStateAFn g_real_set_state_a = NULL;
static SetStateWFn g_real_set_state_w = NULL;
static SetStateIdFn g_real_set_state_id = NULL;
static SetSwitchAFn g_real_set_switch_a = NULL;
static SetSwitchWFn g_real_set_switch_w = NULL;
static SetSwitchIdFn g_real_set_switch_id = NULL;
static PostTriggerAFn g_real_post_trigger_a = NULL;
static PostTriggerWFn g_real_post_trigger_w = NULL;
static PostTriggerIdFn g_real_post_trigger_id = NULL;
static SetRtpcValueAFn g_real_set_rtpc_value_a = NULL;
static SetRtpcValueWFn g_real_set_rtpc_value_w = NULL;
static SetRtpcValueIdFn g_real_set_rtpc_value_id = NULL;
static GenericVoiceFn5 g_real_play_voice_impl = NULL;
static GenericVoiceFn7 g_real_play_voice_with_sentence_impl = NULL;
static GenericVoiceFn7 g_real_play_voice_with_sentence_randomly_impl = NULL;

static const char *k_build_tag = "public-release-v1.2";

static const char *k_export_post_event_id =
    "?PostEvent@SoundEngine@AK@@YAII_KIP6AXW4AkCallbackType@@PEAUAkCallbackInfo@@@ZPEAXIPEAUAkExternalSourceInfo@@I@Z";
static const char *k_export_get_id_from_string_a =
    "?GetIDFromString@SoundEngine@AK@@YAIPEBD@Z";
static const char *k_export_get_id_from_string_w =
    "?GetIDFromString@SoundEngine@AK@@YAIPEB_W@Z";
static const char *k_export_post_event_name_a =
    "?PostEvent@SoundEngine@AK@@YAIPEBD_KIP6AXW4AkCallbackType@@PEAUAkCallbackInfo@@@ZPEAXIPEAUAkExternalSourceInfo@@I@Z";
static const char *k_export_post_event_name_w =
    "?PostEvent@SoundEngine@AK@@YAIPEB_W_KIP6AXW4AkCallbackType@@PEAUAkCallbackInfo@@@ZPEAXIPEAUAkExternalSourceInfo@@I@Z";
static const char *k_export_set_state_a =
    "?SetState@SoundEngine@AK@@YA?AW4AKRESULT@@PEBD0@Z";
static const char *k_export_set_state_w =
    "?SetState@SoundEngine@AK@@YA?AW4AKRESULT@@PEB_W0@Z";
static const char *k_export_set_state_id =
    "?SetState@SoundEngine@AK@@YA?AW4AKRESULT@@II@Z";
static const char *k_export_set_switch_a =
    "?SetSwitch@SoundEngine@AK@@YA?AW4AKRESULT@@PEBD0_K@Z";
static const char *k_export_set_switch_w =
    "?SetSwitch@SoundEngine@AK@@YA?AW4AKRESULT@@PEB_W0_K@Z";
static const char *k_export_set_switch_id =
    "?SetSwitch@SoundEngine@AK@@YA?AW4AKRESULT@@II_K@Z";
static const char *k_export_post_trigger_a =
    "?PostTrigger@SoundEngine@AK@@YA?AW4AKRESULT@@PEBD_K@Z";
static const char *k_export_post_trigger_w =
    "?PostTrigger@SoundEngine@AK@@YA?AW4AKRESULT@@PEB_W_K@Z";
static const char *k_export_post_trigger_id =
    "?PostTrigger@SoundEngine@AK@@YA?AW4AKRESULT@@I_K@Z";
static const char *k_export_set_rtpc_value_a =
    "?SetRTPCValue@SoundEngine@AK@@YA?AW4AKRESULT@@PEBDM_KHW4AkCurveInterpolation@@_N@Z";
static const char *k_export_set_rtpc_value_w =
    "?SetRTPCValue@SoundEngine@AK@@YA?AW4AKRESULT@@PEB_WM_KHW4AkCurveInterpolation@@_N@Z";
static const char *k_export_set_rtpc_value_id =
    "?SetRTPCValue@SoundEngine@AK@@YA?AW4AKRESULT@@IM_KHW4AkCurveInterpolation@@_N@Z";

static const uintptr_t k_rva_play_voice_impl = 0x00D8B390u;
static const uintptr_t k_rva_play_voice_with_sentence_impl = 0x00D8B5B0u;
static const uintptr_t k_rva_play_voice_with_sentence_randomly_impl = 0x00D8B870u;

/*
 * These IDs are the currently confirmed Wwise voice events.
 * They are blocked directly without any heuristic windows or runtime learning.
 */

static AkUniqueID* g_blocked = NULL;
static size_t g_blocked_count = 0;

static const AkUniqueID mute_bike_driving_sound[] = {560195744u};
static const AkUniqueID mute_get_off_bike[] = {1459707057u};
static const AkUniqueID mute_bike_retracts_after_get_off[] = {2927771336u};
static const AkUniqueID mute_get_on_bike[] = {1926977457u};
static const AkUniqueID mute_get_on_bike_left_side[] = 
{
    2695390141u,
    2394382850u,
    3414479536u,
    1986506869u,
    821000358u,
    1338907192u,
    444017931u,
    2715474440u,
    3610115111u,
    1926977457u,
    880458741u,
    3919766094u,
    1502884745u
};
static const AkUniqueID mute_get_on_bike_right_side[] = 
{
    2695390141u,
    444017931u,
    2715474440u,
    3610115111u,
    880458741u,
    1926977457u,
    3919766094u,
    1502884759u
};
static const AkUniqueID mute_get_on_bike_law_and_order_ding_ding[] = {1502884739u};
static const AkUniqueID mute_run_get_on_bike_right_and_front_side[] = 
{
    4223857948u,
    4114772966u,
    339706116u,
    43800831u,
    4185420502u,
    1197881676u,
    417957110u,
    4268017148u,
    1304435119u,
    3897075427u,
    3316121526u,
    1279378066u,
    3102406090u,
    2417186760u,
    1526289975u,
    2599554367u,
    1084626322u,
    3774752747u,
    4015941358u
};
static const AkUniqueID mute_run_get_on_bike_left_side[] = 
{
    2695390141u,
    1222235457u,
    3955373966u,
    4156393369u,
    1338907192u,
    4161553576u,
    2582923240u,
    3319722272u,
    4114772966u,
    3773876168u,
    339706116u,
    2567676718u,
    1808469513u,
    4223857948u,
    2795108589u,
    77658627u,
    860197806u,
    221286236u,
    2599990357u,
    2115478403u,
    777940461u,
    4154749010u,
    444017931u,
    2715474440u,
    3610115111u,
    1926977457u,
    880458741u,
    3919766094u,
    1064086609u,
    2597338696u,
    4015941358u,
    3540071294u
};
static const AkUniqueID mute_armor_activated_on_bike_mount_1[] = {2281185168u};
static const AkUniqueID mute_armor_activated_on_bike_mount_2[] = {1409497247u};
static const AkUniqueID mute_armor_activated_on_bike_mount_3[] = {4094584434u};
static const AkUniqueID mute_armor_activated_on_bike_mount_4[] = {1520456362u};
static const AkUniqueID mute_armor_deactivated_on_bike_unmount_1[] = {591947656u};
static const AkUniqueID mute_armor_deactivated_on_bike_unmount_2[] = {1494342936u};
static const AkUniqueID mute_get_on_car_front_side[] = {2447662917u};
static const AkUniqueID mute_get_on_armored_car_left_side[] = {387213036u};
static const AkUniqueID mute_get_on_armored_car_right_side[] = {387213042u};
static const AkUniqueID mute_get_on_non_armored_car_left_side[] = {2447662927u};
static const AkUniqueID mute_get_on_non_armored_car_right_side[] = {2447662929u};
static const AkUniqueID mute_get_on_car_law_and_order_ding_ding[] = {3274402134u};
static const AkUniqueID mute_loud_noise_after_get_on_car[] = {3486631158u};
static const AkUniqueID mute_car_retracts_after_get_off_1[] = {2139458619u};
static const AkUniqueID mute_car_retracts_after_get_off_2[] = {1822691130u};
static const AkUniqueID mute_beeping_noise_while_driving_car[] = {996224677u};
static const AkUniqueID mute_suspension_noise_while_driving_car[] = 
{
    926343045u,
    377816033u,
    3858348756u,
    2575482772u,
    307201841u,
    778969128u,
    2684990178u,
    1384627326u,
    359280819u,
    307201847u,
    3607620153u,
    3610172769u,
    3723815996u,
    868087032u,
    476545153u,
    2056588759u,
    2039319535u,
    1113767062u
};
static const AkUniqueID mute_command_prompt_appears[] = {4154749010u};
static const AkUniqueID mute_skeleton[] = 
{
    334832419u,
    77658627u,
    860197806u,
    2599990357u,
    2115478403u,
    777940461u,
    1731316122u,
    2260357319u,
    4208302398u,
    1808469513u,
    4223857948u
};
static const AkUniqueID mute_loud_HEADOUT[] = 
{
    2483290443u,
    1268992403u,
    263052418u
};
static const AkUniqueID mute_get_on_attached_floating_carrier[] = 
{
    1747066416u
};
static const AkUniqueID mute_get_on_detached_floating_carrier[] = 
{
    1231113891u
};
static const AkUniqueID mute_get_off_floating_carrier[] = 
{
    632656462u
};
static const AkUniqueID mute_floating_carrier_drive_sound[] = 
{
    3355914873u
};
static const AkUniqueID mute_two_floating_carrier_drive_sound[] = 
{
    3945424578u
};
static const AkUniqueID mute_floating_carrier_squeak_noise[] = 
{
    1567498544u,
    946948326u
};
static const AkUniqueID mute_get_on_coffin_board[] = 
{
    516503854u
};
static const AkUniqueID mute_get_off_coffin_board[] = 
{
    910830388u,
    738955545u
};
static const AkUniqueID mute_main_menu_button_hover[] =
{
    2070267753u,
    1137822087u
};
static const AkUniqueID mute_setting_tab_click[] =
{
    915399611u
};
static const AkUniqueID mute_setting_option_previous_value_and_slider[] =
{
    3163658288u
};
static const AkUniqueID mute_setting_option_next_value[] =
{
    3778102407u
};
static const AkUniqueID mute_setting_menu_click[] =
{
    3532501407u,
    723131124u
};
static const AkUniqueID mute_setting_menu_return[] =
{
    1005221178u,
    2231428062u
};
static const AkUniqueID mute_load_save_menu_hover[] =
{
    2147876058u
};
static const AkUniqueID mute_load_save_menu_return[] =
{
    950340443u
};
static const AkUniqueID mute_esc_open_system_menu[] =
{
    865275807u
};
static const AkUniqueID mute_esc_close_system_menu[] =
{
    3569950978u
};
static const AkUniqueID mute_setting_menu_back_to_system_menu[] =
{
    991791339u
};
static const AkUniqueID mute_use_terminal[] =
{
    2707867662u
};
static const AkUniqueID mute_use_terminal_prompt_spin[] =
{
    2715474440u,
    2715474442u,
    2715474443u,
    2715474444u,
    2715474445u
};
static const AkUniqueID mute_enter_facility_bang[] =
{
    2720010562u,
    2720010561u,
    2720010560u,
    2720010567u
};
static const AkUniqueID mute_enter_facility_scan[] =
{
    2184015236u,
    2208794130u,
    1111526780u,
    2661789847u,
    1926586171u,
    1904916743u,
    629566067u
};
static const AkUniqueID mute_facility_shut_down_bang[] =
{
    167690906u
};
static const AkUniqueID mute_enter_private_room[] =
{
    180688690u
};
static const AkUniqueID mute_rest_in_shelter[] =
{
    739855082u 
};
static const AkUniqueID mute_open_pause_menu[] =
{
    1272080071u
};
static const AkUniqueID mute_close_pause_menu[] =
{
    1555678938u,
};
static const AkUniqueID mute_terminal_selection[] =
{
    3510403665u
};
static const AkUniqueID mute_open_map[] =
{
    1395297620u
};
static const AkUniqueID mute_flood_or_bushfire_warning_in_map[] =
{
    2936542795u,
    810404280u 
};
static const AkUniqueID mute_cargo_management_selection[] =
{
    2073984788u,
    868510127u,
    3712952287u,
    3537078332u,
    1045856687u
};
static const AkUniqueID mute_placement_options[] =
{
    2697499513u,
    3750735517u,
    2370980422u,
    2033295672u,
    1318596166u,
    1674371413u,
    4174348335u,
    3190491779u,
    2940240412u,
    3918104627u
};
static const AkUniqueID mute_map_facility_hover[] =
{
    4136087566u
};
static const AkUniqueID mute_qpid_enter_and_return_orders[] =
{
    102775411u,
    964832389u,
    3517219138u,
    3952328711u
};
static const AkUniqueID mute_route_simulation_in_orders[] =
{
    701450156u,
    332342612u,
    810404280u,
    852448669u
};
static const AkUniqueID mute_hover_on_orders[] =
{
    415080345u
};
static const AkUniqueID mute_switch_map_info[] =
{
    3952025241u
};
static const AkUniqueID mute_place_marker_on_map[] =
{
    3030815226u,
    3435181501u
};
static const AkUniqueID mute_zoomming_in_and_out_in_map[] =
{
    399841250u,
    1109766744u,
    1885089791u
};
static const AkUniqueID mute_pan_around_the_map[] =
{
    3896968560u,
    3957150253u
};
static const AkUniqueID mute_wear_clothes[] =
{
    1928788144u
};
static const AkUniqueID mute_wear_hats[] =
{
    1430582278u
};
static const AkUniqueID mute_wear_glasses[] =
{
    930962484u
};
static const AkUniqueID mute_take_off_glasses[] =
{
    1777752120u
};
static const AkUniqueID mute_wear_BB[] =
{
    406607417u
};
static const AkUniqueID mute_wear_mask[] =
{
    770438339u
};
static const AkUniqueID mute_change_cosmetics_color[] =
{
    1676408000u
};
static const AkUniqueID mute_fabricate_vehicle[] =
{
    713030780u,
    191922392u
};
static const AkUniqueID mute_claim_material_menu[] =
{
    509841768u,
    913490515u,
    1670932874u,
    3468270857u,
    1793364560u,
    4177125866u,
    2240337728u,
    990015723u
};
static const AkUniqueID mute_notification_yellow[] =
{
    466973018u
};
static const AkUniqueID mute_notification_white[] =
{
    3413927717u
};
static const AkUniqueID mute_sam_breathing[] =
{
    4251155871u 
};


/*
 * These hashes are the currently confirmed PlayerVoice entries.
 * Blocking here catches random chatter before it reaches the Wwise layer.
 */
static const uint32_t k_blocked_voice_hashes[] = {
};

void appendArray(const AkUniqueID* array, size_t arrayCount)
{
    AkUniqueID* newMem = realloc(g_blocked, (g_blocked_count + arrayCount) * sizeof(AkUniqueID));

    if (!newMem)
    {
        return;
    }

    memcpy(newMem + g_blocked_count, array, arrayCount * sizeof(AkUniqueID));

    g_blocked = newMem;
    g_blocked_count += arrayCount;
}

static const char *k_default_ini =
"SoundOfNature public release config."
"Enabled=1 to enable sound of nature mod."
"Set VerboseLog=1 only when collecting debug logs."
"EnablePlayerVoiceHooks=0 is recommended after game updates."
"Press F10 while reproducing a sound to insert MARK lines into the log."
"\n"
"[General]\n"
"Enabled=1\n"
"VerboseLog=0\n"
"EnablePlayerVoiceHooks=0\n"
"EnableMarkHotkey=0\n"
"MarkHotkeyVirtualKey=121\n"
"ChainPostEventRelay=1\n"
"Mute_bike_driving_sound=1\n"
"Mute_get_off_bike=1\n"
"Mute_bike_retracts_after_get_off=1\n"
"Mute_get_on_bike=1\n"
"Mute_get_on_bike_left_side=1\n"
"Mute_get_on_bike_right_side=1\n"
"Mute_get_on_bike_law_and_order_ding_ding=1\n"
"Mute_run_get_on_bike_right_and_front_side=1\n"
"Mute_run_get_on_bike_left_side=1\n"
"Mute_armor_activated_on_bike_mount_1=1\n"
"Mute_armor_activated_on_bike_mount_2=1\n"
"Mute_armor_activated_on_bike_mount_3=1\n"
"Mute_armor_activated_on_bike_mount_4=1\n"
"Mute_armor_deactivated_on_bike_unmount_1=1\n"
"Mute_armor_deactivated_on_bike_unmount_2=1\n"
"Mute_get_on_car_front_side=1\n"
"Mute_get_on_armored_car_left_side=1\n"
"Mute_get_on_armored_car_right_side=1\n"
"Mute_get_on_non_armored_car_left_side=1\n"
"Mute_get_on_non_armored_car_right_side=1\n"
"Mute_get_on_car_law_and_order_ding_ding=1\n"
"Mute_loud_noise_after_get_on_car=1\n"
"Mute_car_retracts_after_get_off_1=1\n"
"Mute_car_retracts_after_get_off_2=1\n"
"Mute_beeping_noise_while_driving_car=1\n"
"Mute_suspension_noise_while_driving_car=1\n"
"Mute_command_prompt_appears=1\n"
"Mute_skeleton=1\n"
"Mute_loud_HEADOUT=1\n"
"Mute_get_on_attached_floating_carrier=1\n"
"Mute_get_on_detached_floating_carrier=1\n"
"Mute_get_off_floating_carrier=1\n"
"Mute_floating_carrier_drive_sound=1\n"
"Mute_two_floating_carrier_drive_sound=1\n"
"Mute_floating_carrier_squeak_noise=1\n"
"Mute_get_on_coffin_board=1\n"
"Mute_get_off_coffin_board=1\n"
"Mute_main_menu_button_hover=1\n"
"Mute_setting_tab_click=1\n"
"Mute_setting_option_previous_value_and_slider=1\n"
"Mute_setting_option_next_value=1\n"
"Mute_setting_menu_click=1\n"
"Mute_setting_menu_return=1\n"
"Mute_load_save_menu_hover=1\n"
"Mute_load_save_menu_return=1\n"
"Mute_esc_open_system_menu=1\n"
"Mute_esc_close_system_menu=1\n"
"Mute_setting_menu_back_to_system_menu=1\n"
"Mute_use_terminal=1\n"
"Mute_use_terminal_prompt_spin=1\n"
"Mute_enter_facility_bang=1\n"
"Mute_enter_facility_scan=1\n"
"Mute_facility_shut_down_bang=1\n"
"Mute_enter_private_room=1\n"
"Mute_rest_in_shelter=1\n"
"Mute_open_pause_menu=1\n"
"Mute_close_pause_menu=1\n"
"Mute_terminal_selection=1\n"
"Mute_open_map=1\n"
"Mute_flood_or_bushfire_warning_in_map=1\n"
"Mute_cargo_management_selection=1\n"
"Mute_placement_options=1\n"
"Mute_map_facility_hover=1\n"
"Mute_qpid_enter_and_return_orders=1\n"
"Mute_route_simulation_in_orders=1\n"
"Mute_hover_on_orders=1\n"
"Mute_switch_map_info=1\n"
"Mute_place_marker_on_map=1\n"
"Mute_zoomming_in_and_out_in_map=1\n"
"Mute_pan_around_the_map=1\n"
"Mute_wear_clothes=1\n"
"Mute_wear_hats=1\n"
"Mute_wear_glasses=1\n"
"Mute_take_off_glasses=1\n"
"Mute_wear_BB=1\n"
"Mute_wear_mask=1\n"
"Mute_change_cosmetics_color=1\n"
"Mute_fabricate_vehicle=1\n"
"Mute_claim_material_menu=1\n"
"Mute_notification_yellow=1\n"
"Mute_notification_white=1\n"
"Mute_sam_breathing=1\n"
;

static uint32_t g_seen_trace_hashes[4096];
static size_t g_seen_trace_count = 0;
static AkUniqueID g_traced_event_ids[1024];
static size_t g_traced_event_id_count = 0;

static void join_path(char *buffer, size_t buffer_size, const char *dir, const char *file_name)
{
    if (buffer == NULL || buffer_size == 0) {
        return;
    }

    if (dir == NULL || dir[0] == '\0') {
        snprintf(buffer, buffer_size, "%s", file_name != NULL ? file_name : "");
        return;
    }

    snprintf(buffer, buffer_size, "%s\\%s", dir, file_name != NULL ? file_name : "");
}

static void init_paths(void)
{
    char module_path[MAX_PATH];
    char *last_slash = NULL;

    module_path[0] = '\0';
    if (g_self_module == NULL) {
        return;
    }

    GetModuleFileNameA(g_self_module, module_path, MAX_PATH);
    module_path[MAX_PATH - 1] = '\0';

    last_slash = strrchr(module_path, '\\');
    if (last_slash != NULL) {
        *last_slash = '\0';
    }

    join_path(g_ini_path, sizeof(g_ini_path), module_path, "SoundOfNature.ini");
    join_path(g_log_path, sizeof(g_log_path), module_path, "SoundOfNature.log");
}

static void ensure_default_ini(void)
{
    HANDLE file = INVALID_HANDLE_VALUE;
    DWORD written = 0;

    if (g_ini_path[0] == '\0' || GetFileAttributesA(g_ini_path) != INVALID_FILE_ATTRIBUTES) {
        return;
    }

    file = CreateFileA(
        g_ini_path,
        GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        CREATE_NEW,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (file == INVALID_HANDLE_VALUE) {
        return;
    }

    WriteFile(file, k_default_ini, (DWORD)strlen(k_default_ini), &written, NULL);
    CloseHandle(file);
}

static void load_config(void)
{
    ZeroMemory(&g_cfg, sizeof(g_cfg));
    g_cfg.enabled = TRUE;
    g_cfg.verbose_log = FALSE;
    g_cfg.enable_player_voice_hooks = FALSE;
    g_cfg.enable_mark_hotkey = TRUE;
    g_cfg.mark_hotkey_virtual_key = 121u;
    g_cfg.chain_post_event_relay = TRUE;
    g_cfg.mute_bike_driving_sound = TRUE;
    g_cfg.mute_get_off_bike = TRUE;
    g_cfg.mute_bike_retracts_after_get_off = TRUE;
    g_cfg.mute_get_on_bike = TRUE;
    g_cfg.mute_get_on_bike_left_side = TRUE;
    g_cfg.mute_get_on_bike_right_side = TRUE;
    g_cfg.mute_get_on_bike_law_and_order_ding_ding = TRUE;
    g_cfg.mute_run_get_on_bike_right_and_front_side = TRUE;
    g_cfg.mute_run_get_on_bike_left_side = TRUE;
    g_cfg.mute_armor_activated_on_bike_mount_1 = TRUE;
    g_cfg.mute_armor_activated_on_bike_mount_2 = TRUE;
    g_cfg.mute_armor_activated_on_bike_mount_3 = TRUE;
    g_cfg.mute_armor_activated_on_bike_mount_4 = TRUE;
    g_cfg.mute_armor_deactivated_on_bike_unmount_1 = TRUE;
    g_cfg.mute_armor_deactivated_on_bike_unmount_2 = TRUE;
    g_cfg.mute_get_on_car_front_side = TRUE;
    g_cfg.mute_get_on_armored_car_left_side = TRUE;
    g_cfg.mute_get_on_armored_car_right_side = TRUE;
    g_cfg.mute_get_on_non_armored_car_left_side = TRUE;
    g_cfg.mute_get_on_non_armored_car_right_side = TRUE;
    g_cfg.mute_get_on_car_law_and_order_ding_ding = TRUE;
    g_cfg.mute_loud_noise_after_get_on_car = TRUE;
    g_cfg.mute_car_retracts_after_get_off_1 = TRUE;
    g_cfg.mute_car_retracts_after_get_off_2 = TRUE;
    g_cfg.mute_beeping_noise_while_driving_car = TRUE;
    g_cfg.mute_suspension_noise_while_driving_car = TRUE;
    g_cfg.mute_command_prompt_appears = TRUE;
    g_cfg.mute_skeleton = TRUE;
    g_cfg.mute_loud_HEADOUT = TRUE;
    g_cfg.mute_get_on_attached_floating_carrier = TRUE;
    g_cfg.mute_get_on_detached_floating_carrier = TRUE;
    g_cfg.mute_get_off_floating_carrier = TRUE;
    g_cfg.mute_floating_carrier_drive_sound = TRUE;
    g_cfg.mute_two_floating_carrier_drive_sound = TRUE;
    g_cfg.mute_floating_carrier_squeak_noise = TRUE;
    g_cfg.mute_get_on_coffin_board = TRUE;
    g_cfg.mute_get_off_coffin_board = TRUE;
    g_cfg.mute_main_menu_button_hover = TRUE;
    g_cfg.mute_setting_tab_click = TRUE;
    g_cfg.mute_setting_option_previous_value_and_slider = TRUE;
    g_cfg.mute_setting_option_next_value = TRUE;
    g_cfg.mute_setting_menu_click = TRUE;
    g_cfg.mute_setting_menu_return = TRUE;
    g_cfg.mute_load_save_menu_hover = TRUE;
    g_cfg.mute_load_save_menu_return = TRUE;
    g_cfg.mute_esc_open_system_menu = TRUE;
    g_cfg.mute_esc_close_system_menu = TRUE;
    g_cfg.mute_setting_menu_back_to_system_menu = TRUE;
    g_cfg.mute_use_terminal = TRUE;
    g_cfg.mute_use_terminal_prompt_spin = TRUE;
    g_cfg.mute_enter_facility_bang = TRUE;
    g_cfg.mute_enter_facility_scan = TRUE;
    g_cfg.mute_facility_shut_down_bang = TRUE;
    g_cfg.mute_enter_private_room = TRUE;
    g_cfg.mute_rest_in_shelter = TRUE;
    g_cfg.mute_open_pause_menu = TRUE;
    g_cfg.mute_close_pause_menu = TRUE;
    g_cfg.mute_terminal_selection = TRUE;
    g_cfg.mute_open_map = TRUE;
    g_cfg.mute_flood_or_bushfire_warning_in_map = TRUE;
    g_cfg.mute_cargo_management_selection = TRUE;
    g_cfg.mute_placement_options = TRUE;
    g_cfg.mute_map_facility_hover = TRUE;
    g_cfg.mute_qpid_enter_and_return_orders = TRUE;
    g_cfg.mute_route_simulation_in_orders = TRUE;
    g_cfg.mute_hover_on_orders = TRUE;
    g_cfg.mute_switch_map_info = TRUE;
    g_cfg.mute_place_marker_on_map = TRUE;
    g_cfg.mute_zoomming_in_and_out_in_map = TRUE;
    g_cfg.mute_pan_around_the_map = TRUE;
    g_cfg.mute_wear_clothes = TRUE;
    g_cfg.mute_wear_hats = TRUE;
    g_cfg.mute_wear_glasses = TRUE;
    g_cfg.mute_take_off_glasses = TRUE;
    g_cfg.mute_wear_BB = TRUE;
    g_cfg.mute_wear_mask = TRUE;
    g_cfg.mute_change_cosmetics_color = TRUE;
    g_cfg.mute_fabricate_vehicle = TRUE;
    g_cfg.mute_claim_material_menu = TRUE;
    g_cfg.mute_notification_yellow = TRUE;
    g_cfg.mute_notification_white = TRUE;
    g_cfg.mute_sam_breathing = TRUE;

    ensure_default_ini();

    g_cfg.enabled = GetPrivateProfileIntA("General", "Enabled", g_cfg.enabled, g_ini_path) != 0;
    g_cfg.verbose_log = GetPrivateProfileIntA("General", "VerboseLog", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.enable_player_voice_hooks = GetPrivateProfileIntA("General", "EnablePlayerVoiceHooks", g_cfg.enable_player_voice_hooks, g_ini_path) != 0;
    g_cfg.enable_mark_hotkey = GetPrivateProfileIntA("General", "EnableMarkHotkey", g_cfg.enable_mark_hotkey, g_ini_path) != 0;
    g_cfg.mark_hotkey_virtual_key = (uint32_t)GetPrivateProfileIntA("General", "MarkHotkeyVirtualKey", (int)g_cfg.mark_hotkey_virtual_key, g_ini_path);
    g_cfg.chain_post_event_relay = GetPrivateProfileIntA("General", "ChainPostEventRelay", g_cfg.chain_post_event_relay, g_ini_path) != 0;
    g_cfg.mute_bike_driving_sound = GetPrivateProfileIntA("General", "Mute_bike_driving_sound", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_off_bike = GetPrivateProfileIntA("General", "Mute_get_off_bike", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_bike_retracts_after_get_off = GetPrivateProfileIntA("General", "Mute_bike_retracts_after_get_off", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_bike = GetPrivateProfileIntA("General", "Mute_get_on_bike", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_bike_left_side = GetPrivateProfileIntA("General", "Mute_get_on_bike_left_side", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_bike_right_side = GetPrivateProfileIntA("General", "Mute_get_on_bike_right_side", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_bike_law_and_order_ding_ding = GetPrivateProfileIntA("General", "Mute_get_on_bike_law_and_order_ding_ding", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_run_get_on_bike_right_and_front_side = GetPrivateProfileIntA("General", "Mute_run_get_on_bike_right_and_front_side", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_run_get_on_bike_left_side = GetPrivateProfileIntA("General", "Mute_run_get_on_bike_left_side", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_armor_activated_on_bike_mount_1 = GetPrivateProfileIntA("General", "Mute_armor_activated_on_bike_mount_1", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_armor_activated_on_bike_mount_2 = GetPrivateProfileIntA("General", "Mute_armor_activated_on_bike_mount_2", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_armor_activated_on_bike_mount_3 = GetPrivateProfileIntA("General", "Mute_armor_activated_on_bike_mount_3", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_armor_activated_on_bike_mount_4 = GetPrivateProfileIntA("General", "Mute_armor_activated_on_bike_mount_4", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_armor_deactivated_on_bike_unmount_1 = GetPrivateProfileIntA("General", "Mute_armor_deactivated_on_bike_unmount_1", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_armor_deactivated_on_bike_unmount_2 = GetPrivateProfileIntA("General", "Mute_armor_deactivated_on_bike_unmount_2", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_car_front_side = GetPrivateProfileIntA("General", "Mute_get_on_car_front_side", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_armored_car_left_side = GetPrivateProfileIntA("General", "Mute_get_on_armored_car_left_side", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_armored_car_right_side = GetPrivateProfileIntA("General", "Mute_get_on_armored_car_right_side", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_non_armored_car_left_side = GetPrivateProfileIntA("General", "Mute_get_on_non_armored_car_left_side", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_non_armored_car_right_side = GetPrivateProfileIntA("General", "Mute_get_on_non_armored_car_right_side", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_car_law_and_order_ding_ding = GetPrivateProfileIntA("General", "Mute_get_on_car_law_and_order_ding_ding", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_loud_noise_after_get_on_car = GetPrivateProfileIntA("General", "Mute_loud_noise_after_get_on_car", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_car_retracts_after_get_off_1 = GetPrivateProfileIntA("General", "Mute_car_retracts_after_get_off_1", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_car_retracts_after_get_off_2 = GetPrivateProfileIntA("General", "Mute_car_retracts_after_get_off_2", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_beeping_noise_while_driving_car = GetPrivateProfileIntA("General", "Mute_beeping_noise_while_driving_car", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_suspension_noise_while_driving_car = GetPrivateProfileIntA("General", "Mute_suspension_noise_while_driving_car", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_command_prompt_appears = GetPrivateProfileIntA("General", "Mute_command_prompt_appears", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_skeleton = GetPrivateProfileIntA("General", "Mute_skeleton", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_loud_HEADOUT = GetPrivateProfileIntA("General", "Mute_loud_HEADOUT", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_attached_floating_carrier = GetPrivateProfileIntA("General", "Mute_get_on_attached_floating_carrier", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_detached_floating_carrier = GetPrivateProfileIntA("General", "Mute_get_on_detached_floating_carrier", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_off_floating_carrier = GetPrivateProfileIntA("General", "Mute_get_off_floating_carrier", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_floating_carrier_drive_sound = GetPrivateProfileIntA("General", "Mute_floating_carrier_drive_sound", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_two_floating_carrier_drive_sound = GetPrivateProfileIntA("General", "Mute_two_floating_carrier_drive_sound", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_floating_carrier_squeak_noise = GetPrivateProfileIntA("General", "Mute_floating_carrier_squeak_noise", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_on_coffin_board = GetPrivateProfileIntA("General", "Mute_get_on_coffin_board", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_get_off_coffin_board = GetPrivateProfileIntA("General", "Mute_get_off_coffin_board", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_main_menu_button_hover = GetPrivateProfileIntA("General", "Mute_main_menu_button_hover", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_setting_tab_click = GetPrivateProfileIntA("General", "Mute_setting_tab_click", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_setting_option_previous_value_and_slider = GetPrivateProfileIntA("General", "Mute_setting_option_previous_value_and_slider", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_setting_option_next_value = GetPrivateProfileIntA("General", "Mute_setting_option_next_value", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_setting_menu_click = GetPrivateProfileIntA("General", "Mute_setting_menu_click", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_setting_menu_return = GetPrivateProfileIntA("General", "Mute_setting_menu_return", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_load_save_menu_hover = GetPrivateProfileIntA("General", "Mute_load_save_menu_hover", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_load_save_menu_return = GetPrivateProfileIntA("General", "Mute_load_save_menu_return", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_esc_open_system_menu = GetPrivateProfileIntA("General", "Mute_esc_open_system_menu", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_esc_close_system_menu = GetPrivateProfileIntA("General", "Mute_esc_close_system_menu", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_setting_menu_back_to_system_menu = GetPrivateProfileIntA("General", "Mute_setting_menu_back_to_system_menu", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_use_terminal = GetPrivateProfileIntA("General", "Mute_use_terminal", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_use_terminal_prompt_spin = GetPrivateProfileIntA("General", "Mute_use_terminal_prompt_spin", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_enter_facility_bang = GetPrivateProfileIntA("General", "Mute_enter_facility_bang", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_enter_facility_scan = GetPrivateProfileIntA("General", "Mute_enter_facility_scan", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_facility_shut_down_bang = GetPrivateProfileIntA("General", "Mute_facility_shut_down_bang", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_enter_private_room = GetPrivateProfileIntA("General", "Mute_enter_private_room", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_rest_in_shelter = GetPrivateProfileIntA("General", "Mute_rest_in_shelter", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_open_pause_menu = GetPrivateProfileIntA("General", "Mute_open_pause_menu", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_close_pause_menu = GetPrivateProfileIntA("General", "Mute_get_off_coffin_board", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_terminal_selection = GetPrivateProfileIntA("General", "Mute_terminal_selection", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_open_map = GetPrivateProfileIntA("General", "Mute_open_map", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_flood_or_bushfire_warning_in_map = GetPrivateProfileIntA("General", "Mute_flood_or_bushfire_warning_in_map", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_cargo_management_selection = GetPrivateProfileIntA("General", "Mute_cargo_management_selection", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_placement_options = GetPrivateProfileIntA("General", "Mute_placement_options", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_map_facility_hover = GetPrivateProfileIntA("General", "Mute_map_facility_hover", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_qpid_enter_and_return_orders = GetPrivateProfileIntA("General", "Mute_qpid_enter_and_return_orders", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_route_simulation_in_orders = GetPrivateProfileIntA("General", "Mute_route_simulation_in_orders", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_hover_on_orders = GetPrivateProfileIntA("General", "Mute_hover_on_orders", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_switch_map_info = GetPrivateProfileIntA("General", "Mute_switch_map_info", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_place_marker_on_map = GetPrivateProfileIntA("General", "Mute_place_marker_on_map", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_zoomming_in_and_out_in_map = GetPrivateProfileIntA("General", "Mute_zoomming_in_and_out_in_map", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_pan_around_the_map = GetPrivateProfileIntA("General", "Mute_pan_around_the_map", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_wear_clothes = GetPrivateProfileIntA("General", "Mute_wear_clothes", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_wear_hats = GetPrivateProfileIntA("General", "Mute_wear_hats", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_wear_glasses = GetPrivateProfileIntA("General", "Mute_wear_glasses", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_take_off_glasses = GetPrivateProfileIntA("General", "Mute_take_off_glasses", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_wear_BB = GetPrivateProfileIntA("General", "Mute_wear_BB", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_wear_mask = GetPrivateProfileIntA("General", "Mute_wear_mask", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_change_cosmetics_color = GetPrivateProfileIntA("General", "Mute_change_cosmetics_color", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_fabricate_vehicle = GetPrivateProfileIntA("General", "Mute_fabricate_vehicle", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_claim_material_menu = GetPrivateProfileIntA("General", "Mute_claim_material_menu", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_notification_yellow = GetPrivateProfileIntA("General", "Mute_notification_yellow", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_notification_white = GetPrivateProfileIntA("General", "Mute_notification_white", g_cfg.verbose_log, g_ini_path) != 0;
    g_cfg.mute_sam_breathing = GetPrivateProfileIntA("General", "Mute_sam_breathing", g_cfg.verbose_log, g_ini_path) != 0;




    if (g_cfg.mute_bike_driving_sound)
    {
        appendArray(mute_bike_driving_sound, sizeof(mute_bike_driving_sound) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_off_bike)
    {
        appendArray(mute_get_off_bike, sizeof(mute_get_off_bike) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_bike_retracts_after_get_off)
    {
        appendArray(mute_bike_retracts_after_get_off, sizeof(mute_bike_retracts_after_get_off) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_bike)
    {
        appendArray(mute_get_on_bike, sizeof(mute_get_on_bike) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_bike_left_side)
    {
        appendArray(mute_get_on_bike_left_side, sizeof(mute_get_on_bike_left_side) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_bike_right_side)
    {
        appendArray(mute_get_on_bike_right_side, sizeof(mute_get_on_bike_right_side) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_bike_law_and_order_ding_ding)
    {
        appendArray(mute_get_on_bike_law_and_order_ding_ding, sizeof(mute_get_on_bike_law_and_order_ding_ding) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_run_get_on_bike_right_and_front_side)
    {
        appendArray(mute_run_get_on_bike_right_and_front_side, sizeof(mute_run_get_on_bike_right_and_front_side) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_run_get_on_bike_left_side)
    {
        appendArray(mute_run_get_on_bike_left_side, sizeof(mute_run_get_on_bike_left_side) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_armor_activated_on_bike_mount_1)
    {
        appendArray(mute_armor_activated_on_bike_mount_1, sizeof(mute_armor_activated_on_bike_mount_1) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_armor_activated_on_bike_mount_2)
    {
        appendArray(mute_armor_activated_on_bike_mount_2, sizeof(mute_armor_activated_on_bike_mount_2) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_armor_activated_on_bike_mount_3)
    {
        appendArray(mute_armor_activated_on_bike_mount_3, sizeof(mute_armor_activated_on_bike_mount_3) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_armor_activated_on_bike_mount_4)
    {
        appendArray(mute_armor_activated_on_bike_mount_4, sizeof(mute_armor_activated_on_bike_mount_4) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_armor_deactivated_on_bike_unmount_1)
    {
        appendArray(mute_armor_deactivated_on_bike_unmount_1, sizeof(mute_armor_deactivated_on_bike_unmount_1) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_armor_deactivated_on_bike_unmount_2)
    {
        appendArray(mute_armor_deactivated_on_bike_unmount_2, sizeof(mute_armor_deactivated_on_bike_unmount_2) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_car_front_side)
    {
        appendArray(mute_get_on_car_front_side, sizeof(mute_get_on_car_front_side) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_armored_car_left_side)
    {
        appendArray(mute_get_on_armored_car_left_side, sizeof(mute_get_on_armored_car_left_side) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_armored_car_right_side)
    {
        appendArray(mute_get_on_armored_car_right_side, sizeof(mute_get_on_armored_car_right_side) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_non_armored_car_left_side)
    {
        appendArray(mute_get_on_non_armored_car_left_side, sizeof(mute_get_on_non_armored_car_left_side) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_non_armored_car_right_side)
    {
        appendArray(mute_get_on_non_armored_car_right_side, sizeof(mute_get_on_non_armored_car_right_side) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_car_law_and_order_ding_ding)
    {
        appendArray(mute_get_on_car_law_and_order_ding_ding, sizeof(mute_get_on_car_law_and_order_ding_ding) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_loud_noise_after_get_on_car)
    {
        appendArray(mute_loud_noise_after_get_on_car, sizeof(mute_loud_noise_after_get_on_car) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_car_retracts_after_get_off_1)
    {
        appendArray(mute_car_retracts_after_get_off_1, sizeof(mute_car_retracts_after_get_off_1) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_car_retracts_after_get_off_2)
    {
        appendArray(mute_car_retracts_after_get_off_2, sizeof(mute_car_retracts_after_get_off_2) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_beeping_noise_while_driving_car)
    {
        appendArray(mute_beeping_noise_while_driving_car, sizeof(mute_beeping_noise_while_driving_car) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_suspension_noise_while_driving_car)
    {
        appendArray(mute_suspension_noise_while_driving_car, sizeof(mute_suspension_noise_while_driving_car) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_command_prompt_appears)
    {
        appendArray(mute_command_prompt_appears, sizeof(mute_command_prompt_appears) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_skeleton)
    {
        appendArray(mute_skeleton, sizeof(mute_skeleton) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_loud_HEADOUT)
    {
        appendArray(mute_loud_HEADOUT, sizeof(mute_loud_HEADOUT) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_attached_floating_carrier)
    {
        appendArray(mute_get_on_attached_floating_carrier, sizeof(mute_get_on_attached_floating_carrier) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_detached_floating_carrier)
    {
        appendArray(mute_get_on_detached_floating_carrier, sizeof(mute_get_on_detached_floating_carrier) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_off_floating_carrier)
    {
        appendArray(mute_get_off_floating_carrier, sizeof(mute_get_off_floating_carrier) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_floating_carrier_drive_sound)
    {
        appendArray(mute_floating_carrier_drive_sound, sizeof(mute_floating_carrier_drive_sound) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_two_floating_carrier_drive_sound)
    {
        appendArray(mute_two_floating_carrier_drive_sound, sizeof(mute_two_floating_carrier_drive_sound) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_floating_carrier_squeak_noise)
    {
        appendArray(mute_floating_carrier_squeak_noise, sizeof(mute_floating_carrier_squeak_noise) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_on_coffin_board)
    {
        appendArray(mute_get_on_coffin_board, sizeof(mute_get_on_coffin_board) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_get_off_coffin_board)
    {
        appendArray(mute_get_off_coffin_board, sizeof(mute_get_off_coffin_board) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_main_menu_button_hover)
    {
        appendArray(mute_main_menu_button_hover, sizeof(mute_main_menu_button_hover) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_setting_tab_click)
    {
        appendArray(mute_setting_tab_click, sizeof(mute_setting_tab_click) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_setting_option_previous_value_and_slider)
    {
        appendArray(mute_setting_option_previous_value_and_slider, sizeof(mute_setting_option_previous_value_and_slider) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_setting_option_next_value)
    {
        appendArray(mute_setting_option_next_value, sizeof(mute_setting_option_next_value) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_setting_menu_click)
    {
        appendArray(mute_setting_menu_click, sizeof(mute_setting_menu_click) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_setting_menu_return)
    {
        appendArray(mute_setting_menu_return, sizeof(mute_setting_menu_return) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_load_save_menu_hover)
    {
        appendArray(mute_load_save_menu_hover, sizeof(mute_load_save_menu_hover) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_load_save_menu_return)
    {
        appendArray(mute_load_save_menu_return, sizeof(mute_load_save_menu_return) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_esc_open_system_menu)
    {
        appendArray(mute_esc_open_system_menu, sizeof(mute_esc_open_system_menu) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_esc_close_system_menu)
    {
        appendArray(mute_esc_close_system_menu, sizeof(mute_esc_close_system_menu) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_setting_menu_back_to_system_menu)
    {
        appendArray(mute_setting_menu_back_to_system_menu, sizeof(mute_setting_menu_back_to_system_menu) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_use_terminal)
    {
        appendArray(mute_use_terminal, sizeof(mute_use_terminal) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_use_terminal_prompt_spin)
    {
        appendArray(mute_use_terminal_prompt_spin, sizeof(mute_use_terminal_prompt_spin) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_enter_facility_bang)
    {
        appendArray(mute_enter_facility_bang, sizeof(mute_enter_facility_bang) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_enter_facility_scan)
    {
        appendArray(mute_enter_facility_scan, sizeof(mute_enter_facility_scan) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_facility_shut_down_bang)
    {
        appendArray(mute_facility_shut_down_bang, sizeof(mute_facility_shut_down_bang) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_enter_private_room)
    {
        appendArray(mute_enter_private_room, sizeof(mute_enter_private_room) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_rest_in_shelter)
    {
        appendArray(mute_rest_in_shelter, sizeof(mute_rest_in_shelter) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_open_pause_menu)
    {
        appendArray(mute_open_pause_menu, sizeof(mute_open_pause_menu) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_close_pause_menu)
    {
        appendArray(mute_close_pause_menu, sizeof(mute_close_pause_menu) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_terminal_selection)
    {
        appendArray(mute_terminal_selection, sizeof(mute_terminal_selection) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_open_map)
    {
        appendArray(mute_open_map, sizeof(mute_open_map) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_flood_or_bushfire_warning_in_map)
    {
        appendArray(mute_flood_or_bushfire_warning_in_map, sizeof(mute_flood_or_bushfire_warning_in_map) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_cargo_management_selection)
    {
        appendArray(mute_cargo_management_selection, sizeof(mute_cargo_management_selection) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_placement_options)
    {
        appendArray(mute_placement_options, sizeof(mute_placement_options) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_map_facility_hover)
    {
        appendArray(mute_map_facility_hover, sizeof(mute_map_facility_hover) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_qpid_enter_and_return_orders)
    {
        appendArray(mute_qpid_enter_and_return_orders, sizeof(mute_qpid_enter_and_return_orders) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_route_simulation_in_orders)
    {
        appendArray(mute_route_simulation_in_orders, sizeof(mute_route_simulation_in_orders) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_hover_on_orders)
    {
        appendArray(mute_hover_on_orders, sizeof(mute_hover_on_orders) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_switch_map_info)
    {
        appendArray(mute_switch_map_info, sizeof(mute_switch_map_info) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_place_marker_on_map)
    {
        appendArray(mute_place_marker_on_map, sizeof(mute_place_marker_on_map) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_zoomming_in_and_out_in_map)
    {
        appendArray(mute_zoomming_in_and_out_in_map, sizeof(mute_zoomming_in_and_out_in_map) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_pan_around_the_map)
    {
        appendArray(mute_pan_around_the_map, sizeof(mute_pan_around_the_map) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_wear_clothes)
    {
        appendArray(mute_wear_clothes, sizeof(mute_wear_clothes) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_wear_hats)
    {
        appendArray(mute_wear_hats, sizeof(mute_wear_hats) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_wear_glasses)
    {
        appendArray(mute_wear_glasses, sizeof(mute_wear_glasses) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_take_off_glasses)
    {
        appendArray(mute_take_off_glasses, sizeof(mute_take_off_glasses) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_wear_BB)
    {
        appendArray(mute_wear_BB, sizeof(mute_wear_BB) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_wear_mask)
    {
        appendArray(mute_wear_mask, sizeof(mute_wear_mask) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_change_cosmetics_color)
    {
        appendArray(mute_change_cosmetics_color, sizeof(mute_change_cosmetics_color) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_fabricate_vehicle)
    {
        appendArray(mute_fabricate_vehicle, sizeof(mute_fabricate_vehicle) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_claim_material_menu)
    {
        appendArray(mute_claim_material_menu, sizeof(mute_claim_material_menu) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_notification_yellow)
    {
        appendArray(mute_notification_yellow, sizeof(mute_notification_yellow) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_notification_white)
    {
        appendArray(mute_notification_white, sizeof(mute_notification_white) / sizeof(AkUniqueID));
    }
    if (g_cfg.mute_sam_breathing)
    {
        appendArray(mute_sam_breathing, sizeof(mute_sam_breathing) / sizeof(AkUniqueID));
    }
}

static void write_log_v(const char *fmt, va_list args)
{
    char message[1024];
    char line[1200];
    SYSTEMTIME st;
    HANDLE file;
    DWORD written = 0;
    int message_len;
    int line_len;

    if (g_log_path[0] == '\0' || fmt == NULL) {
        return;
    }

    message_len = vsnprintf(message, sizeof(message), fmt, args);
    if (message_len < 0) {
        return;
    }

    GetLocalTime(&st);
    line_len = snprintf(
        line,
        sizeof(line),
        "[%04u-%02u-%02u %02u:%02u:%02u.%03u] %s\r\n",
        (unsigned int)st.wYear,
        (unsigned int)st.wMonth,
        (unsigned int)st.wDay,
        (unsigned int)st.wHour,
        (unsigned int)st.wMinute,
        (unsigned int)st.wSecond,
        (unsigned int)st.wMilliseconds,
        message);
    if (line_len <= 0) {
        return;
    }

    EnterCriticalSection(&g_log_lock);
    file = CreateFileA(
        g_log_path,
        FILE_APPEND_DATA,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (file != INVALID_HANDLE_VALUE) {
        WriteFile(file, line, (DWORD)line_len, &written, NULL);
        CloseHandle(file);
    }
    LeaveCriticalSection(&g_log_lock);
}

static void log_line(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    write_log_v(fmt, args);
    va_end(args);
}

static void log_verbose(const char *fmt, ...)
{
    va_list args;

    if (!g_cfg.verbose_log) {
        return;
    }

    va_start(args, fmt);
    write_log_v(fmt, args);
    va_end(args);
}

static const char *virtual_key_name(uint32_t virtual_key)
{
    switch (virtual_key) {
    case VK_F1: return "F1";
    case VK_F2: return "F2";
    case VK_F3: return "F3";
    case VK_F4: return "F4";
    case VK_F5: return "F5";
    case VK_F6: return "F6";
    case VK_F7: return "F7";
    case VK_F8: return "F8";
    case VK_F9: return "F9";
    case VK_F10: return "F10";
    case VK_F11: return "F11";
    case VK_F12: return "F12";
    default: return "custom";
    }
}

static DWORD WINAPI mark_hotkey_thread_proc(LPVOID parameter)
{
    BOOL last_down = FALSE;
    uint32_t virtual_key = (uint32_t)(uintptr_t)parameter;

    g_mark_hotkey_thread_running = TRUE;
    log_line(
        "Mark hotkey thread started: key=%s vk=%u",
        virtual_key_name(virtual_key),
        (unsigned int)virtual_key);

    for (;;) {
        BOOL is_down = (GetAsyncKeyState((int)virtual_key) & 0x8000) != 0;
        if (is_down && !last_down) {
            log_line(
                "MARK key=%s vk=%u tick=%llu",
                virtual_key_name(virtual_key),
                (unsigned int)virtual_key,
                (unsigned long long)GetTickCount64());
        }

        last_down = is_down;
        Sleep(25);
    }
}

static char ascii_tolower_char(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return (char)(ch - 'A' + 'a');
    }
    return ch;
}

static BOOL contains_case_insensitive(const char *text, const char *needle)
{
    size_t text_index;
    size_t needle_index;

    if (text == NULL || needle == NULL || needle[0] == '\0') {
        return FALSE;
    }

    for (text_index = 0; text[text_index] != '\0'; ++text_index) {
        for (needle_index = 0;; ++needle_index) {
            char text_ch = ascii_tolower_char(text[text_index + needle_index]);
            char needle_ch = ascii_tolower_char(needle[needle_index]);

            if (needle_ch == '\0') {
                return TRUE;
            }
            if (text_ch == '\0' || text_ch != needle_ch) {
                break;
            }
        }
    }

    return FALSE;
}

static size_t copy_ascii_text(const char *src, char *dst, size_t dst_size)
{
    size_t i = 0;

    if (dst == NULL || dst_size == 0) {
        return 0;
    }

    dst[0] = '\0';
    if (src == NULL) {
        return 0;
    }

    while (src[i] != '\0' && i + 1 < dst_size) {
        unsigned char ch = (unsigned char)src[i];
        if (ch < 0x20 || ch > 0x7e) {
            dst[0] = '\0';
            return 0;
        }
        dst[i] = (char)ch;
        ++i;
    }

    if (i == 0 || src[i] != '\0') {
        dst[0] = '\0';
        return 0;
    }

    dst[i] = '\0';
    return i;
}

static size_t copy_ascii_wide_text(const wchar_t *src, char *dst, size_t dst_size)
{
    size_t i = 0;

    if (dst == NULL || dst_size == 0) {
        return 0;
    }

    dst[0] = '\0';
    if (src == NULL) {
        return 0;
    }

    while (src[i] != L'\0' && i + 1 < dst_size) {
        wchar_t ch = src[i];
        if (ch < 0x20 || ch > 0x7e) {
            dst[0] = '\0';
            return 0;
        }
        dst[i] = (char)ch;
        ++i;
    }

    if (i == 0 || src[i] != L'\0') {
        dst[0] = '\0';
        return 0;
    }

    dst[i] = '\0';
    return i;
}

static BOOL has_trace_keyword(const char *text)
{
    static const char *k_keywords[] = {
        "dollman",
        "talk",
        "voice",
        "radio",
        "balance",
        "stagger",
        "fall",
        "slip",
        "trip",
        "shake",
        "wobble",
        "cargo",
        "playervoice"
    };
    size_t i;

    if (text == NULL || text[0] == '\0') {
        return FALSE;
    }

    for (i = 0; i < sizeof(k_keywords) / sizeof(k_keywords[0]); ++i) {
        if (contains_case_insensitive(text, k_keywords[i])) {
            return TRUE;
        }
    }

    return FALSE;
}

static uint32_t hash_trace_key(const char *kind, const char *value1, const char *value2);
static BOOL reserve_trace_key(uint32_t trace_hash);

static void trace_numeric_once(const char *kind, AkUniqueID value1, AkUniqueID value2, AkGameObjectID game_object_id, float rtpc_value)
{
    char buffer1[32];
    char buffer2[32];

    if (!g_cfg.verbose_log) {
        return;
    }

    snprintf(buffer1, sizeof(buffer1), "%u", (unsigned int)value1);
    snprintf(buffer2, sizeof(buffer2), "%u", (unsigned int)value2);
    if (reserve_trace_key(hash_trace_key(kind, buffer1, buffer2))) {
        log_verbose(
            "Trace %s a=%u b=%u gameObject=0x%llx value=%.3f",
            kind,
            (unsigned int)value1,
            (unsigned int)value2,
            (unsigned long long)game_object_id,
            (double)rtpc_value);
    }
}

static uint32_t hash_trace_key(const char *kind, const char *value1, const char *value2)
{
    uint32_t hash = 2166136261u;
    const char *parts[3];
    size_t part_index;
    size_t char_index;

    parts[0] = kind != NULL ? kind : "";
    parts[1] = value1 != NULL ? value1 : "";
    parts[2] = value2 != NULL ? value2 : "";

    for (part_index = 0; part_index < 3; ++part_index) {
        for (char_index = 0; parts[part_index][char_index] != '\0'; ++char_index) {
            hash ^= (uint8_t)parts[part_index][char_index];
            hash *= 16777619u;
        }
        hash ^= (uint8_t)'|';
        hash *= 16777619u;
    }

    return hash;
}

static BOOL reserve_trace_key(uint32_t trace_hash)
{
    size_t i;
    BOOL should_log = FALSE;

    EnterCriticalSection(&g_trace_lock);
    for (i = 0; i < g_seen_trace_count; ++i) {
        if (g_seen_trace_hashes[i] == trace_hash) {
            LeaveCriticalSection(&g_trace_lock);
            return FALSE;
        }
    }

    if (g_seen_trace_count < sizeof(g_seen_trace_hashes) / sizeof(g_seen_trace_hashes[0])) {
        g_seen_trace_hashes[g_seen_trace_count++] = trace_hash;
        should_log = TRUE;
    }
    LeaveCriticalSection(&g_trace_lock);
    return should_log;
}

static void remember_traced_event_id(AkUniqueID event_id)
{
    size_t i;

    if (event_id == 0) {
        return;
    }

    EnterCriticalSection(&g_trace_lock);
    for (i = 0; i < g_traced_event_id_count; ++i) {
        if (g_traced_event_ids[i] == event_id) {
            LeaveCriticalSection(&g_trace_lock);
            return;
        }
    }

    if (g_traced_event_id_count < sizeof(g_traced_event_ids) / sizeof(g_traced_event_ids[0])) {
        g_traced_event_ids[g_traced_event_id_count++] = event_id;
    }
    LeaveCriticalSection(&g_trace_lock);
}

static BOOL is_traced_event_id(AkUniqueID event_id)
{
    size_t i;
    BOOL found = FALSE;

    if (event_id == 0) {
        return FALSE;
    }

    EnterCriticalSection(&g_trace_lock);
    for (i = 0; i < g_traced_event_id_count; ++i) {
        if (g_traced_event_ids[i] == event_id) {
            found = TRUE;
            break;
        }
    }
    LeaveCriticalSection(&g_trace_lock);
    return found;
}

static void trace_name_id_once(const char *kind, const char *name, AkUniqueID event_id)
{
    if (!g_cfg.verbose_log || name == NULL || name[0] == '\0') {
        return;
    }

    if (reserve_trace_key(hash_trace_key(kind, name, NULL))) {
        log_verbose("Trace %s name=%s id=%u", kind, name, (unsigned int)event_id);
    }
    remember_traced_event_id(event_id);
}

static void trace_name_once(const char *kind, const char *name, AkGameObjectID game_object_id)
{
    if (!g_cfg.verbose_log || name == NULL || name[0] == '\0') {
        return;
    }

    if (reserve_trace_key(hash_trace_key(kind, name, NULL))) {
        log_verbose(
            "Trace %s name=%s gameObject=0x%llx",
            kind,
            name,
            (unsigned long long)game_object_id);
    }
}

static void trace_pair_once(const char *kind, const char *value1, const char *value2, AkGameObjectID game_object_id)
{
    if (!g_cfg.verbose_log || ((value1 == NULL || value1[0] == '\0') && (value2 == NULL || value2[0] == '\0'))) {
        return;
    }

    if (reserve_trace_key(hash_trace_key(kind, value1, value2))) {
        log_verbose(
            "Trace %s a=%s b=%s gameObject=0x%llx",
            kind,
            value1 != NULL ? value1 : "(null)",
            value2 != NULL ? value2 : "(null)",
            (unsigned long long)game_object_id);
    }
}

static void trace_single_once(const char *kind, const char *value, AkGameObjectID game_object_id)
{
    if (!g_cfg.verbose_log || value == NULL || value[0] == '\0') {
        return;
    }

    if (reserve_trace_key(hash_trace_key(kind, value, NULL))) {
        log_verbose(
            "Trace %s name=%s gameObject=0x%llx",
            kind,
            value,
            (unsigned long long)game_object_id);
    }
}

static BOOL should_block_event_id(AkUniqueID event_id)
{
    for (size_t i = 0; i < g_blocked_count; ++i)
    {
        if (g_blocked[i] == event_id)
        {
            return TRUE;
        }
    }

    return FALSE;
}

static BOOL should_block_voice_hash(uint32_t hash_value)
{
    size_t i;

    if (hash_value == 0) {
        return FALSE;
    }

    for (i = 0; i < sizeof(k_blocked_voice_hashes) / sizeof(k_blocked_voice_hashes[0]); ++i) {
        if (k_blocked_voice_hashes[i] == hash_value) {
            return TRUE;
        }
    }

    return FALSE;
}

static void *resolve_export(const char *name)
{
    HMODULE exe_module = GetModuleHandleW(NULL);

    if (exe_module == NULL || name == NULL || name[0] == '\0') {
        return NULL;
    }

    return (void *)GetProcAddress(exe_module, name);
}

static void *resolve_rva(uintptr_t rva)
{
    HMODULE exe_module = GetModuleHandleW(NULL);

    if (exe_module == NULL || rva == 0) {
        return NULL;
    }

    return (void *)((uintptr_t)exe_module + rva);
}

static AkPlayingID __cdecl hook_post_event_id(
    AkUniqueID event_id,
    AkGameObjectID game_object_id,
    uint32_t callback_mask,
    void *callback,
    void *cookie,
    uint32_t external_source_count,
    void *external_sources,
    uint32_t playing_id);

static BOOL install_hook(void *target, void *detour, void **original, const char *label);

/*
 * True if every byte in [ptr, ptr+min_bytes) lies in committed memory that is executable.
 * Walks VirtualQuery regions so a small span crossing a page boundary still succeeds.
 */
static BOOL executable_code_span_readable(const void *ptr, SIZE_T min_bytes)
{
    const uint8_t *p = (const uint8_t *)ptr;
    const uint8_t *need_end;

    if (ptr == NULL || min_bytes == 0) {
        return FALSE;
    }

    need_end = p + min_bytes;
    if (need_end < p) {
        return FALSE;
    }

    while (p < need_end) {
        MEMORY_BASIC_INFORMATION mbi;
        const uint8_t *region_end;

        if (VirtualQuery(p, &mbi, sizeof(mbi)) < sizeof(mbi)) {
            return FALSE;
        }
        if (mbi.State != MEM_COMMIT) {
            return FALSE;
        }
        if (!(mbi.Protect &
                (PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY))) {
            return FALSE;
        }

        region_end = (const uint8_t *)mbi.BaseAddress + mbi.RegionSize;
        if (region_end <= p) {
            return FALSE;
        }

        if (region_end >= need_end) {
            return TRUE;
        }

        p = region_end;
    }

    return TRUE;
}

static BOOL peer_dollman_mute_module_loaded(void)
{
    if (GetModuleHandleA("DollmanMute.asi") != NULL) {
        return TRUE;
    }
    if (GetModuleHandleW(L"DollmanMute.asi") != NULL) {
        return TRUE;
    }
    return FALSE;
}

static BOOL post_event_bytes_look_minhook_patched(const uint8_t *p)
{
    if (p == NULL) {
        return FALSE;
    }
    return p[0] == 0xE9u || p[0] == 0xEBu;
}

static void *follow_minhook_jmp_from_postevent(void *post_va)
{
    uint8_t *p = (uint8_t *)post_va;
    int step;

    for (step = 0; step < 4; ++step) {
        if (!executable_code_span_readable(p, 8)) {
            return NULL;
        }
        if (p[0] == 0xEBu) {
            int8_t rel8;

            if (!executable_code_span_readable(p, 2)) {
                return NULL;
            }
            rel8 = (int8_t)p[1];
            p = p + 2 + (ptrdiff_t)rel8;
            continue;
        }
        if (p[0] == 0xE9u) {
            int32_t rel32;

            if (!executable_code_span_readable(p, 5)) {
                return NULL;
            }
            memcpy(&rel32, p + 1, sizeof(rel32));
            return p + 5 + (ptrdiff_t)rel32;
        }
        return NULL;
    }

    return NULL;
}

static BOOL relay_bytes_look_minhook_x64(const uint8_t *p)
{
    if (p == NULL) {
        return FALSE;
    }
    /* JMP [RIP+disp32] — tail of MinHook x64 relay before user detour */
    return p[0] == 0xFFu && p[1] == 0x25u;
}

static BOOL install_post_event_id_hook(void)
{
    void *post_va;
    void *relay_va;
    const uint8_t *probe;
    DWORD t0;
    DWORD wait_cap_ms;
    const DWORD peer_step_ms = 25u;
    BOOL logged_wait = FALSE;
    BOOL peer_present;

    post_va = resolve_export(k_export_post_event_id);
    if (post_va == NULL) {
        log_line("Skip hook PostEventID: export not found");
        return FALSE;
    }

    peer_present = peer_dollman_mute_module_loaded();
    /*
     * Long wait if DollmanMute is already mapped; short grace if not (covers SON loading before
     * Dollman's DllMain registers the module).
     */
    wait_cap_ms = peer_present ? 5000u : 400u;
    t0 = GetTickCount();

    for (;;) {
        if (!executable_code_span_readable(post_va, 8)) {
            log_line("Skip hook PostEventID: PostEvent VA not readable as code");
            return FALSE;
        }

        probe = (const uint8_t *)post_va;

        if (post_event_bytes_look_minhook_patched(probe)) {
            if (!g_cfg.chain_post_event_relay) {
                log_line(
                    "PostEvent is already patched (another mod hooks it). Enable ChainPostEventRelay=1 to chain on its "
                    "MinHook relay, or load SoundOfNature before that mod.");
                return FALSE;
            }

            relay_va = follow_minhook_jmp_from_postevent(post_va);
            if (relay_va == NULL) {
                log_line("PostEvent looks hooked but relay decode failed; cannot chain");
                return FALSE;
            }

            if (!executable_code_span_readable(relay_va, 16)) {
                log_line("Decoded relay %p is not in executable memory", relay_va);
                return FALSE;
            }

            if (relay_bytes_look_minhook_x64((const uint8_t *)relay_va)) {
                log_line(
                    "PostEvent pre-hooked; chaining on MinHook relay at %p (SoundOfNature filters first, then peer mod)",
                    relay_va);
            } else {
                log_line(
                    "PostEvent pre-hooked; chaining at relay %p without FF25 signature (unusual; may break on updates)",
                    relay_va);
            }

            return install_hook(relay_va, hook_post_event_id, (void **)&g_real_post_event_id, "PostEventID_RelayChain");
        }

        /*
         * PostEvent is still the original prologue. Another ASI may patch it on a worker thread
         * after we load; if DollmanMute is present and chaining is on, wait before claiming PostEvent.
         */
        if (g_cfg.chain_post_event_relay) {
            DWORD elapsed = GetTickCount() - t0;
            if (elapsed < wait_cap_ms) {
                if (!logged_wait) {
                    if (peer_present) {
                        log_line(
                            "PostEvent not patched yet while DollmanMute.asi is loaded; waiting up to %ums for it to "
                            "hook (init thread race)",
                            (unsigned int)wait_cap_ms);
                    } else {
                        log_line(
                            "PostEvent not patched yet; waiting up to %ums for another mod to hook first (relay chain)",
                            (unsigned int)wait_cap_ms);
                    }
                    logged_wait = TRUE;
                }
                Sleep(peer_step_ms);
                continue;
            }
            if (peer_present) {
                log_line(
                    "PostEvent still unpatched after %ums with DollmanMute present; hooking PostEvent directly (peer "
                    "may have failed to hook)",
                    (unsigned int)wait_cap_ms);
            }
        }

        return install_hook(post_va, hook_post_event_id, (void **)&g_real_post_event_id, "PostEventID");
    }
}

static BOOL install_hook(void *target, void *detour, void **original, const char *label)
{
    MH_STATUS status;

    if (target == NULL) {
        log_line("Skip hook %s: target not found", label != NULL ? label : "(unknown)");
        return FALSE;
    }

    status = MH_CreateHook(target, detour, original);
    if (status != MH_OK && status != MH_ERROR_ALREADY_CREATED) {
        log_line("Failed to create hook %s: %d", label != NULL ? label : "(unknown)", (int)status);
        return FALSE;
    }

    status = MH_EnableHook(target);
    if (status != MH_OK && status != MH_ERROR_ENABLED) {
        log_line("Failed to enable hook %s: %d", label != NULL ? label : "(unknown)", (int)status);
        return FALSE;
    }

    log_line("Hooked %s at %p", label != NULL ? label : "(unknown)", target);
    return TRUE;
}

static BOOL install_export_hook(const char *export_name, void *detour, void **original, const char *label)
{
    return install_hook(resolve_export(export_name), detour, original, label);
}

static BOOL install_rva_hook(uintptr_t rva, void *detour, void **original, const char *label)
{
    return install_hook(resolve_rva(rva), detour, original, label);
}

static AkPlayingID __cdecl hook_post_event_id(
    AkUniqueID event_id,
    AkGameObjectID game_object_id,
    uint32_t callback_mask,
    void *callback,
    void *cookie,
    uint32_t external_source_count,
    void *external_sources,
    uint32_t playing_id)
{
    BOOL blocked = g_cfg.enabled && should_block_event_id(event_id);

    if (g_cfg.verbose_log) {
        log_verbose(
            "%s PostEventID eventId=%u gameObject=0x%llx externalSources=%u",
            is_traced_event_id(event_id) ? "Trace" : "Seen",
            event_id,
            (unsigned long long)game_object_id,
            (unsigned int)external_source_count);
    }

    if (blocked) {
        log_verbose(
            "Blocked PostEventID eventId=%u gameObject=0x%llx externalSources=%u",
            event_id,
            (unsigned long long)game_object_id,
            (unsigned int)external_source_count);
        return 0;
    }

    return g_real_post_event_id(
        event_id,
        game_object_id,
        callback_mask,
        callback,
        cookie,
        external_source_count,
        external_sources,
        playing_id);
}

static AkUniqueID __cdecl hook_get_id_from_string_a(const char *name)
{
    char text[160];
    AkUniqueID event_id;

    event_id = g_real_get_id_from_string_a(name);
    if (copy_ascii_text(name, text, sizeof(text)) != 0) {
        trace_name_id_once("GetIDFromStringA", text, event_id);
    }
    return event_id;
}

static AkUniqueID __cdecl hook_get_id_from_string_w(const wchar_t *name)
{
    char text[160];
    AkUniqueID event_id;

    event_id = g_real_get_id_from_string_w(name);
    if (copy_ascii_wide_text(name, text, sizeof(text)) != 0) {
        trace_name_id_once("GetIDFromStringW", text, event_id);
    }
    return event_id;
}

static AkPlayingID __cdecl hook_post_event_name_a(
    const char *event_name,
    AkGameObjectID game_object_id,
    uint32_t callback_mask,
    void *callback,
    void *cookie,
    uint32_t external_source_count,
    void *external_sources,
    uint32_t playing_id)
{
    char text[160];

    if (copy_ascii_text(event_name, text, sizeof(text)) != 0) {
        trace_name_once("PostEventA", text, game_object_id);
    }

    return g_real_post_event_name_a(
        event_name,
        game_object_id,
        callback_mask,
        callback,
        cookie,
        external_source_count,
        external_sources,
        playing_id);
}

static AkPlayingID __cdecl hook_post_event_name_w(
    const wchar_t *event_name,
    AkGameObjectID game_object_id,
    uint32_t callback_mask,
    void *callback,
    void *cookie,
    uint32_t external_source_count,
    void *external_sources,
    uint32_t playing_id)
{
    char text[160];

    if (copy_ascii_wide_text(event_name, text, sizeof(text)) != 0) {
        trace_name_once("PostEventW", text, game_object_id);
    }

    return g_real_post_event_name_w(
        event_name,
        game_object_id,
        callback_mask,
        callback,
        cookie,
        external_source_count,
        external_sources,
        playing_id);
}

static AKRESULT __cdecl hook_set_state_a(const char *group_name, const char *state_name)
{
    char group_text[160];
    char state_text[160];

    if (copy_ascii_text(group_name, group_text, sizeof(group_text)) != 0 &&
        copy_ascii_text(state_name, state_text, sizeof(state_text)) != 0) {
        trace_pair_once("SetStateA", group_text, state_text, 0);
    }

    return g_real_set_state_a(group_name, state_name);
}

static AKRESULT __cdecl hook_set_state_w(const wchar_t *group_name, const wchar_t *state_name)
{
    char group_text[160];
    char state_text[160];

    if (copy_ascii_wide_text(group_name, group_text, sizeof(group_text)) != 0 &&
        copy_ascii_wide_text(state_name, state_text, sizeof(state_text)) != 0) {
        trace_pair_once("SetStateW", group_text, state_text, 0);
    }

    return g_real_set_state_w(group_name, state_name);
}

static AKRESULT __cdecl hook_set_state_id(AkUniqueID group_id, AkUniqueID state_id)
{
    trace_numeric_once("SetStateID", group_id, state_id, 0, 0.0f);
    return g_real_set_state_id(group_id, state_id);
}

static AKRESULT __cdecl hook_set_switch_a(const char *group_name, const char *state_name, AkGameObjectID game_object_id)
{
    char group_text[160];
    char state_text[160];

    if (copy_ascii_text(group_name, group_text, sizeof(group_text)) != 0 &&
        copy_ascii_text(state_name, state_text, sizeof(state_text)) != 0) {
        trace_pair_once("SetSwitchA", group_text, state_text, game_object_id);
    }

    return g_real_set_switch_a(group_name, state_name, game_object_id);
}

static AKRESULT __cdecl hook_set_switch_w(const wchar_t *group_name, const wchar_t *state_name, AkGameObjectID game_object_id)
{
    char group_text[160];
    char state_text[160];

    if (copy_ascii_wide_text(group_name, group_text, sizeof(group_text)) != 0 &&
        copy_ascii_wide_text(state_name, state_text, sizeof(state_text)) != 0) {
        trace_pair_once("SetSwitchW", group_text, state_text, game_object_id);
    }

    return g_real_set_switch_w(group_name, state_name, game_object_id);
}

static AKRESULT __cdecl hook_set_switch_id(AkUniqueID group_id, AkUniqueID state_id, AkGameObjectID game_object_id)
{
    trace_numeric_once("SetSwitchID", group_id, state_id, game_object_id, 0.0f);
    return g_real_set_switch_id(group_id, state_id, game_object_id);
}

static AKRESULT __cdecl hook_post_trigger_a(const char *trigger_name, AkGameObjectID game_object_id)
{
    char text[160];

    if (copy_ascii_text(trigger_name, text, sizeof(text)) != 0) {
        trace_single_once("PostTriggerA", text, game_object_id);
    }

    return g_real_post_trigger_a(trigger_name, game_object_id);
}

static AKRESULT __cdecl hook_post_trigger_w(const wchar_t *trigger_name, AkGameObjectID game_object_id)
{
    char text[160];

    if (copy_ascii_wide_text(trigger_name, text, sizeof(text)) != 0) {
        trace_single_once("PostTriggerW", text, game_object_id);
    }

    return g_real_post_trigger_w(trigger_name, game_object_id);
}

static AKRESULT __cdecl hook_post_trigger_id(AkUniqueID trigger_id, AkGameObjectID game_object_id)
{
    trace_numeric_once("PostTriggerID", trigger_id, 0, game_object_id, 0.0f);
    return g_real_post_trigger_id(trigger_id, game_object_id);
}

static AKRESULT __cdecl hook_set_rtpc_value_a(const char *rtpc_name, float value, AkGameObjectID game_object_id, int32_t interpolation_time_ms, int32_t fade_curve, BOOL bypass_game_param)
{
    char text[160];
    (void)interpolation_time_ms;
    (void)fade_curve;
    (void)bypass_game_param;

    if (copy_ascii_text(rtpc_name, text, sizeof(text)) != 0) {
        trace_single_once("SetRTPCA", text, game_object_id);
        if (reserve_trace_key(hash_trace_key("SetRTPCAValue", text, NULL))) {
            log_verbose("Trace SetRTPCAValue name=%s gameObject=0x%llx value=%.3f", text, (unsigned long long)game_object_id, (double)value);
        }
    }

    return g_real_set_rtpc_value_a(rtpc_name, value, game_object_id, interpolation_time_ms, fade_curve, bypass_game_param);
}

static AKRESULT __cdecl hook_set_rtpc_value_w(const wchar_t *rtpc_name, float value, AkGameObjectID game_object_id, int32_t interpolation_time_ms, int32_t fade_curve, BOOL bypass_game_param)
{
    char text[160];
    (void)interpolation_time_ms;
    (void)fade_curve;
    (void)bypass_game_param;

    if (copy_ascii_wide_text(rtpc_name, text, sizeof(text)) != 0) {
        trace_single_once("SetRTPCW", text, game_object_id);
        if (reserve_trace_key(hash_trace_key("SetRTPCWValue", text, NULL))) {
            log_verbose("Trace SetRTPCWValue name=%s gameObject=0x%llx value=%.3f", text, (unsigned long long)game_object_id, (double)value);
        }
    }

    return g_real_set_rtpc_value_w(rtpc_name, value, game_object_id, interpolation_time_ms, fade_curve, bypass_game_param);
}

static AKRESULT __cdecl hook_set_rtpc_value_id(AkUniqueID rtpc_id, float value, AkGameObjectID game_object_id, int32_t interpolation_time_ms, int32_t fade_curve, BOOL bypass_game_param)
{
    (void)interpolation_time_ms;
    (void)fade_curve;
    (void)bypass_game_param;
    trace_numeric_once("SetRTPCID", rtpc_id, 0, game_object_id, value);
    return g_real_set_rtpc_value_id(rtpc_id, value, game_object_id, interpolation_time_ms, fade_curve, bypass_game_param);
}

static uintptr_t __fastcall hook_play_voice_impl(
    const void *arg1,
    uintptr_t arg2,
    uintptr_t arg3,
    uintptr_t arg4,
    uintptr_t arg5)
{
    uint32_t hash_value = (uint32_t)arg2;
    (void)arg1;
    (void)arg3;
    (void)arg4;
    (void)arg5;

    if (g_cfg.enabled && should_block_voice_hash(hash_value)) {
        log_verbose("Blocked PlayerVoice.Play hash=0x%08x", (unsigned int)hash_value);
        return 0;
    }

    return g_real_play_voice_impl(arg1, arg2, arg3, arg4, arg5);
}

static uintptr_t __fastcall hook_play_voice_with_sentence_impl(
    const void *arg1,
    uintptr_t arg2,
    uintptr_t arg3,
    uintptr_t arg4,
    uintptr_t arg5,
    uintptr_t arg6,
    uintptr_t arg7)
{
    uint32_t hash_value = (uint32_t)arg2;
    (void)arg1;
    (void)arg3;
    (void)arg4;
    (void)arg5;
    (void)arg6;
    (void)arg7;

    if (g_cfg.enabled && should_block_voice_hash(hash_value)) {
        log_verbose("Blocked PlayerVoice.PlayWithSentence hash=0x%08x", (unsigned int)hash_value);
        return 0;
    }

    return g_real_play_voice_with_sentence_impl(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

static uintptr_t __fastcall hook_play_voice_with_sentence_randomly_impl(
    const void *arg1,
    uintptr_t arg2,
    uintptr_t arg3,
    uintptr_t arg4,
    uintptr_t arg5,
    uintptr_t arg6,
    uintptr_t arg7)
{
    uint32_t hash_value = (uint32_t)arg2;
    (void)arg1;
    (void)arg3;
    (void)arg4;
    (void)arg5;
    (void)arg6;
    (void)arg7;

    if (g_cfg.enabled && should_block_voice_hash(hash_value)) {
        log_verbose("Blocked PlayerVoice.PlayWithSentenceRandomly hash=0x%08x", (unsigned int)hash_value);
        return 0;
    }

    return g_real_play_voice_with_sentence_randomly_impl(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

static DWORD WINAPI initialize_thread_proc(LPVOID parameter)
{
    MH_STATUS status;
    unsigned int hook_count = 0;

    (void)parameter;

    init_paths();
    load_config();

    log_line("SoundOfNature build: %s", k_build_tag);
    log_line(
        "SoundOfNature init start: enabled=%d verbose=%d playerVoiceHooks=%d markHotkey=%d vk=%u chainRelay=%d",
        g_cfg.enabled,
        g_cfg.verbose_log,
        g_cfg.enable_player_voice_hooks,
        g_cfg.enable_mark_hotkey,
        (unsigned int)g_cfg.mark_hotkey_virtual_key,
        (int)g_cfg.chain_post_event_relay);
    log_line(
    "mute_bike_driving_sound=%d \
    mute_get_off_bike=%d \
    mute_bike_retracts_after_get_off=%d \
    mute_get_on_bike=%d \
    mute_get_on_bike_left_side=%d \
    mute_get_on_bike_right_side=%d \
    mute_get_on_bike_law_and_order_ding_ding=%d \
    mute_run_get_on_bike_right_and_front_side=%d \
    mute_run_get_on_bike_left_side=%d \
    mute_armor_activated_on_bike_mount_1=%d \
    mute_armor_activated_on_bike_mount_2=%d \
    mute_armor_activated_on_bike_mount_3=%d \
    mute_armor_activated_on_bike_mount_4=%d \
    mute_armor_deactivated_on_bike_unmount_1=%d \
    mute_armor_deactivated_on_bike_unmount_2=%d \
    mute_get_on_car_front_side=%d \
    mute_get_on_armored_car_left_side=%d \
    mute_get_on_armored_car_right_side=%d \
    mute_get_on_non_armored_car_left_side=%d \
    mute_get_on_non_armored_car_right_side=%d \
    mute_get_on_car_law_and_order_ding_ding=%d \
    mute_loud_noise_after_get_on_car=%d \
    mute_car_retracts_after_get_off_1=%d \
    mute_car_retracts_after_get_off_2=%d \
    mute_beeping_noise_while_driving_car=%d \
    mute_suspension_noise_while_driving_car=%d \
    mute_command_prompt_appears=%d \
    mute_skeleton=%d \
    mute_loud_HEADOUT=%d \
    mute_get_on_attached_floating_carrier=%d \
    mute_get_on_detached_floating_carrier=%d \
    mute_get_off_floating_carrier=%d \
    mute_floating_carrier_drive_sound=%d \
    mute_two_floating_carrier_drive_sound=%d \
    mute_floating_carrier_squeak_noise=%d \
    mute_get_on_coffin_board=%d \
    mute_get_off_coffin_board=%d \
    mute_main_menu_button_hover=%d \
    mute_setting_tab_click=%d \
    mute_setting_option_previous_value_and_slider=%d \
    mute_setting_option_next_value=%d \
    mute_setting_menu_click=%d \
    mute_setting_menu_return=%d \
    mute_load_save_menu_hover=%d \
    mute_load_save_menu_return=%d \
    mute_esc_open_system_menu=%d \
    mute_esc_close_system_menu=%d \
    mute_setting_menu_back_to_system_menu=%d \
    mute_use_terminal=%d \
    mute_use_terminal_prompt_spin=%d \
    mute_enter_facility_bang=%d \
    mute_enter_facility_scan=%d \
    mute_facility_shut_down_bang=%d \
    mute_enter_private_room=%d \
    mute_rest_in_shelter=%d \
    mute_open_pause_menu=%d \
    mute_close_pause_menu=%d \
    mute_terminal_selection=%d \
    mute_open_map=%d \
    mute_flood_or_bushfire_warning_in_map=%d \
    mute_cargo_management_selection=%d \
    mute_placement_options=%d \
    mute_map_facility_hover=%d \
    mute_qpid_enter_and_return_orders=%d \
    mute_route_simulation_in_orders=%d \
    mute_hover_on_orders=%d \
    mute_switch_map_info=%d \
    mute_place_marker_on_map=%d \
    mute_zoomming_in_and_out_in_map=%d \
    mute_pan_around_the_map=%d \
    mute_wear_clothes=%d \
    mute_wear_hats=%d \
    mute_wear_glasses=%d \
    mute_take_off_glasses=%d \
    mute_wear_BB=%d \
    mute_wear_mask=%d \
    mute_change_cosmetics_color=%d \
    mute_fabricate_vehicle=%d \
    mute_claim_material_menu=%d \
    mute_notification_yellow=%d \
    mute_notification_white=%d \
    mute_sam_breathing=%d ",

    g_cfg.mute_bike_driving_sound,
    g_cfg.mute_get_off_bike,
    g_cfg.mute_bike_retracts_after_get_off,
    g_cfg.mute_get_on_bike,
    g_cfg.mute_get_on_bike_left_side,
    g_cfg.mute_get_on_bike_right_side,
    g_cfg.mute_get_on_bike_law_and_order_ding_ding,
    g_cfg.mute_run_get_on_bike_right_and_front_side,
    g_cfg.mute_run_get_on_bike_left_side,
    g_cfg.mute_armor_activated_on_bike_mount_1,
    g_cfg.mute_armor_activated_on_bike_mount_2,
    g_cfg.mute_armor_activated_on_bike_mount_3,
    g_cfg.mute_armor_activated_on_bike_mount_4,
    g_cfg.mute_armor_deactivated_on_bike_unmount_1,
    g_cfg.mute_armor_deactivated_on_bike_unmount_2,
    g_cfg.mute_get_on_car_front_side,
    g_cfg.mute_get_on_armored_car_left_side,
    g_cfg.mute_get_on_armored_car_right_side,
    g_cfg.mute_get_on_non_armored_car_left_side,
    g_cfg.mute_get_on_non_armored_car_right_side,
    g_cfg.mute_get_on_car_law_and_order_ding_ding,
    g_cfg.mute_loud_noise_after_get_on_car,
    g_cfg.mute_car_retracts_after_get_off_1,
    g_cfg.mute_car_retracts_after_get_off_2,
    g_cfg.mute_beeping_noise_while_driving_car,
    g_cfg.mute_suspension_noise_while_driving_car,
    g_cfg.mute_command_prompt_appears,
    g_cfg.mute_skeleton,
    g_cfg.mute_loud_HEADOUT,
    g_cfg.mute_get_on_attached_floating_carrier,
    g_cfg.mute_get_on_detached_floating_carrier,
    g_cfg.mute_get_off_floating_carrier,
    g_cfg.mute_floating_carrier_drive_sound,
    g_cfg.mute_two_floating_carrier_drive_sound,
    g_cfg.mute_floating_carrier_squeak_noise,
    g_cfg.mute_get_on_coffin_board,
    g_cfg.mute_get_off_coffin_board,
    g_cfg.mute_main_menu_button_hover,
    g_cfg.mute_setting_tab_click,
    g_cfg.mute_setting_option_previous_value_and_slider,
    g_cfg.mute_setting_option_next_value,
    g_cfg.mute_setting_menu_click,
    g_cfg.mute_setting_menu_return,
    g_cfg.mute_load_save_menu_hover,
    g_cfg.mute_load_save_menu_return,
    g_cfg.mute_esc_open_system_menu,
    g_cfg.mute_esc_close_system_menu,
    g_cfg.mute_setting_menu_back_to_system_menu,
    g_cfg.mute_use_terminal,
    g_cfg.mute_use_terminal_prompt_spin,
    g_cfg.mute_enter_facility_bang,
    g_cfg.mute_enter_facility_scan,
    g_cfg.mute_facility_shut_down_bang,
    g_cfg.mute_enter_private_room,
    g_cfg.mute_rest_in_shelter,
    g_cfg.mute_open_pause_menu,
    g_cfg.mute_close_pause_menu,
    g_cfg.mute_terminal_selection,
    g_cfg.mute_open_map,
    g_cfg.mute_flood_or_bushfire_warning_in_map,
    g_cfg.mute_cargo_management_selection,
    g_cfg.mute_placement_options,
    g_cfg.mute_map_facility_hover,
    g_cfg.mute_qpid_enter_and_return_orders,
    g_cfg.mute_route_simulation_in_orders,
    g_cfg.mute_hover_on_orders,
    g_cfg.mute_switch_map_info,
    g_cfg.mute_place_marker_on_map,
    g_cfg.mute_zoomming_in_and_out_in_map,
    g_cfg.mute_pan_around_the_map,
    g_cfg.mute_wear_clothes,
    g_cfg.mute_wear_hats,
    g_cfg.mute_wear_glasses,
    g_cfg.mute_take_off_glasses,
    g_cfg.mute_wear_BB,
    g_cfg.mute_wear_mask,
    g_cfg.mute_change_cosmetics_color,
    g_cfg.mute_fabricate_vehicle,
    g_cfg.mute_claim_material_menu,
    g_cfg.mute_notification_yellow,
    g_cfg.mute_notification_white,
    g_cfg.mute_sam_breathing);

    log_line("count: %d", g_blocked_count);

    status = MH_Initialize();
    if (status != MH_OK && status != MH_ERROR_ALREADY_INITIALIZED) {
        log_line("MH_Initialize failed: %d", (int)status);
        return 0;
    }

    if (install_post_event_id_hook()) {
        ++hook_count;
    }
    if (g_cfg.verbose_log) {
        if (install_export_hook(k_export_get_id_from_string_a, hook_get_id_from_string_a, (void **)&g_real_get_id_from_string_a, "GetIDFromStringA")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_get_id_from_string_w, hook_get_id_from_string_w, (void **)&g_real_get_id_from_string_w, "GetIDFromStringW")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_post_event_name_a, hook_post_event_name_a, (void **)&g_real_post_event_name_a, "PostEventA")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_post_event_name_w, hook_post_event_name_w, (void **)&g_real_post_event_name_w, "PostEventW")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_set_state_a, hook_set_state_a, (void **)&g_real_set_state_a, "SetStateA")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_set_state_w, hook_set_state_w, (void **)&g_real_set_state_w, "SetStateW")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_set_state_id, hook_set_state_id, (void **)&g_real_set_state_id, "SetStateID")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_set_switch_a, hook_set_switch_a, (void **)&g_real_set_switch_a, "SetSwitchA")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_set_switch_w, hook_set_switch_w, (void **)&g_real_set_switch_w, "SetSwitchW")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_set_switch_id, hook_set_switch_id, (void **)&g_real_set_switch_id, "SetSwitchID")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_post_trigger_a, hook_post_trigger_a, (void **)&g_real_post_trigger_a, "PostTriggerA")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_post_trigger_w, hook_post_trigger_w, (void **)&g_real_post_trigger_w, "PostTriggerW")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_post_trigger_id, hook_post_trigger_id, (void **)&g_real_post_trigger_id, "PostTriggerID")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_set_rtpc_value_a, hook_set_rtpc_value_a, (void **)&g_real_set_rtpc_value_a, "SetRTPCA")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_set_rtpc_value_w, hook_set_rtpc_value_w, (void **)&g_real_set_rtpc_value_w, "SetRTPCW")) {
            ++hook_count;
        }
        if (install_export_hook(k_export_set_rtpc_value_id, hook_set_rtpc_value_id, (void **)&g_real_set_rtpc_value_id, "SetRTPCID")) {
            ++hook_count;
        }
    } else {
        log_line("Wwise name trace hooks disabled because VerboseLog=0");
    }
    if (g_cfg.enable_player_voice_hooks) {
        if (install_rva_hook(k_rva_play_voice_impl, hook_play_voice_impl, (void **)&g_real_play_voice_impl, "PlayVoiceImpl")) {
            ++hook_count;
        }
        if (install_rva_hook(k_rva_play_voice_with_sentence_impl, hook_play_voice_with_sentence_impl, (void **)&g_real_play_voice_with_sentence_impl, "PlayVoiceWithSentenceImpl")) {
            ++hook_count;
        }
        if (install_rva_hook(k_rva_play_voice_with_sentence_randomly_impl, hook_play_voice_with_sentence_randomly_impl, (void **)&g_real_play_voice_with_sentence_randomly_impl, "PlayVoiceWithSentenceRandomlyImpl")) {
            ++hook_count;
        }
    } else {
        log_line("PlayerVoice hooks disabled by config; using PostEventID compatibility mode");
    }

    g_hooks_installed = hook_count != 0;
    log_line("SoundOfNature init complete: hooks=%u", hook_count);

    if (g_cfg.enable_mark_hotkey && g_cfg.mark_hotkey_virtual_key != 0 && !g_mark_hotkey_thread_running) {
        HANDLE mark_thread = CreateThread(
            NULL,
            0,
            mark_hotkey_thread_proc,
            (LPVOID)(uintptr_t)g_cfg.mark_hotkey_virtual_key,
            0,
            NULL);
        if (mark_thread != NULL) {
            CloseHandle(mark_thread);
        } else {
            log_line("Failed to start mark hotkey thread");
        }
    }

    return 0;
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
    HANDLE thread_handle;

    (void)reserved;

    if (reason != DLL_PROCESS_ATTACH) {
        return TRUE;
    }

    g_self_module = instance;
    InitializeCriticalSection(&g_log_lock);
    InitializeCriticalSection(&g_trace_lock);
    DisableThreadLibraryCalls(instance);

    thread_handle = CreateThread(NULL, 0, initialize_thread_proc, NULL, 0, NULL);
    if (thread_handle != NULL) {
        CloseHandle(thread_handle);
    }

    return TRUE;
}
