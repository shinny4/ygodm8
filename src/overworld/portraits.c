#include "global.h"

//TODO: teeth clenched -> agitated?
//1:Happy/Smiling/Laughing
//5:Teeth Clenched/Grinding(agitated?) (exceptions: rebecca and monkey robot don't show teeth)

static const unsigned char sNoneTiles[] = INCBIN_U8("src/overworld/portraits/none_neutral.lz");
static const unsigned char sYugiNeutralTiles[] = INCBIN_U8("src/overworld/portraits/yugi_neutral.lz");
static const unsigned char sYugiHappyTiles[] = INCBIN_U8("src/overworld/portraits/yugi_happy.lz");
static const unsigned char sYugiSadTiles[] = INCBIN_U8("src/overworld/portraits/yugi_sad.lz");
static const unsigned char sYugiSurprisedTiles[] = INCBIN_U8("src/overworld/portraits/yugi_surprised.lz");
static const unsigned char sAtemNeutralTiles[] = INCBIN_U8("src/overworld/portraits/atem_neutral.lz");
static const unsigned char sAtemHappyTiles[] = INCBIN_U8("src/overworld/portraits/atem_happy.lz");
static const unsigned char sAtemAngryTiles[] = INCBIN_U8("src/overworld/portraits/atem_angry.lz");
static const unsigned char sSetoNeutralTiles[] = INCBIN_U8("src/overworld/portraits/seto_neutral.lz");
static const unsigned char sSetoHappyTiles[] = INCBIN_U8("src/overworld/portraits/seto_happy.lz");
static const unsigned char sSetoAngryTiles[] = INCBIN_U8("src/overworld/portraits/seto_angry.lz");
static const unsigned char sSetoSadTiles[] = INCBIN_U8("src/overworld/portraits/seto_sad.lz");
static const unsigned char sSetoClenchedTeethTiles[] = INCBIN_U8("src/overworld/portraits/seto_clenched_teeth.lz");
static const unsigned char sSetoSurprisedTiles[] = INCBIN_U8("src/overworld/portraits/seto_surprised.lz");
static const unsigned char sJoeyNeutralTiles[] = INCBIN_U8("src/overworld/portraits/joey_neutral.lz");
static const unsigned char sJoeyAngryTiles[] = INCBIN_U8("src/overworld/portraits/joey_angry.lz");
static const unsigned char sJoeySadTiles[] = INCBIN_U8("src/overworld/portraits/joey_sad.lz");
static const unsigned char sJoeyClenchedTeethTiles[] = INCBIN_U8("src/overworld/portraits/joey_clenched_teeth.lz");
static const unsigned char sJoeySweatDropTiles[] = INCBIN_U8("src/overworld/portraits/joey_sweat_drop.lz");
static const unsigned char sPegasusNeutralTiles[] = INCBIN_U8("src/overworld/portraits/pegasus_neutral.lz");
static const unsigned char sPegasusHappyTiles[] = INCBIN_U8("src/overworld/portraits/pegasus_happy.lz");
static const unsigned char sPegasusSadTiles[] = INCBIN_U8("src/overworld/portraits/pegasus_sad.lz");
static const unsigned char sPegasusDefeatedTiles[] = INCBIN_U8("src/overworld/portraits/pegasus_defeated.lz");
static const unsigned char sPegasusClenchedTeethTiles[] = INCBIN_U8("src/overworld/portraits/pegasus_clenched_teeth.lz");
static const unsigned char sPegasusSurprisedTiles[] = INCBIN_U8("src/overworld/portraits/pegasus_surprised.lz");
static const unsigned char sMaiNeutralTiles[] = INCBIN_U8("src/overworld/portraits/mai_neutral.lz");
static const unsigned char sMaiAngryTiles[] = INCBIN_U8("src/overworld/portraits/mai_angry.lz");
static const unsigned char sMaiSweatDropTiles[] = INCBIN_U8("src/overworld/portraits/mai_sweat_drop.lz");
static const unsigned char sTeaNeutralTiles[] = INCBIN_U8("src/overworld/portraits/tea_neutral.lz");
static const unsigned char sTeaSadTiles[] = INCBIN_U8("src/overworld/portraits/tea_sad.lz");
static const unsigned char sTeaSurprisedTiles[] = INCBIN_U8("src/overworld/portraits/tea_surprised.lz");
static const unsigned char sTeaSweatDropTiles[] = INCBIN_U8("src/overworld/portraits/tea_sweat_drop.lz");
static const unsigned char sSolomonNeutralTiles[] = INCBIN_U8("src/overworld/portraits/solomon_neutral.lz");
static const unsigned char sTristanNeutralTiles[] = INCBIN_U8("src/overworld/portraits/tristan_neutral.lz");
static const unsigned char sTristanHappyTiles[] = INCBIN_U8("src/overworld/portraits/tristan_happy.lz");
static const unsigned char sTristanAngryTiles[] = INCBIN_U8("src/overworld/portraits/tristan_angry.lz");
static const unsigned char sTristanDefeatedTiles[] = INCBIN_U8("src/overworld/portraits/tristan_defeated.lz");
static const unsigned char sTristanClenchedTeethTiles[] = INCBIN_U8("src/overworld/portraits/tristan_clenched_teeth.lz");
static const unsigned char sTristanSurprisedTiles[] = INCBIN_U8("src/overworld/portraits/tristan_surprised.lz");
static const unsigned char sMokubaNeutralTiles[] = INCBIN_U8("src/overworld/portraits/mokuba_neutral.lz");
static const unsigned char sMokubaAngryTiles[] = INCBIN_U8("src/overworld/portraits/mokuba_angry.lz");
static const unsigned char sMokubaSadTiles[] = INCBIN_U8("src/overworld/portraits/mokuba_sad.lz");
static const unsigned char sMokubaSurprisedTiles[] = INCBIN_U8("src/overworld/portraits/mokuba_surprised.lz");
static const unsigned char sMokubaPossessedTiles[] = INCBIN_U8("src/overworld/portraits/mokuba_possessed.lz");
static const unsigned char sRexNeutralTiles[] = INCBIN_U8("src/overworld/portraits/rex_neutral.lz");
static const unsigned char sRexAngryTiles[] = INCBIN_U8("src/overworld/portraits/rex_angry.lz");
static const unsigned char sRexSurprisedTiles[] = INCBIN_U8("src/overworld/portraits/rex_surprised.lz");
static const unsigned char sMakoNeutralTiles[] = INCBIN_U8("src/overworld/portraits/mako_neutral.lz");
static const unsigned char sMakoHappyTiles[] = INCBIN_U8("src/overworld/portraits/mako_happy.lz");
static const unsigned char sMakoSweatDropTiles[] = INCBIN_U8("src/overworld/portraits/mako_sweat_drop.lz");
static const unsigned char sWeevilNeutralTiles[] = INCBIN_U8("src/overworld/portraits/weevil_neutral.lz");
static const unsigned char sWeevilHappyTiles[] = INCBIN_U8("src/overworld/portraits/weevil_happy.lz");
static const unsigned char sEspaNeutralTiles[] = INCBIN_U8("src/overworld/portraits/espa_neutral.lz");
static const unsigned char sEspaAngryTiles[] = INCBIN_U8("src/overworld/portraits/espa_angry.lz");
static const unsigned char sEspaSweatDropTiles[] = INCBIN_U8("src/overworld/portraits/espa_sweat_drop.lz");
static const unsigned char sEspaClosedEyesTiles[] = INCBIN_U8("src/overworld/portraits/espa_closed_eyes.lz");
static const unsigned char sBonzNeutralTiles[] = INCBIN_U8("src/overworld/portraits/bonz_neutral.lz");
static const unsigned char sIshizuNeutralTiles[] = INCBIN_U8("src/overworld/portraits/ishizu_neutral.lz");
static const unsigned char sIshizuHappyTiles[] = INCBIN_U8("src/overworld/portraits/ishizu_happy.lz");
static const unsigned char sIshizuSurprisedTiles[] = INCBIN_U8("src/overworld/portraits/ishizu_surprised.lz");
static const unsigned char sShadiNeutralTiles[] = INCBIN_U8("src/overworld/portraits/shadi_neutral.lz");
static const unsigned char sMimicOfDoomNeutralTiles[] = INCBIN_U8("src/overworld/portraits/mimic_of_doom_neutral.lz");
static const unsigned char sMimicOfDoomDefeatedTiles[] = INCBIN_U8("src/overworld/portraits/mimic_of_doom_defeated.lz");
static const unsigned char sPanikNeutralTiles[] = INCBIN_U8("src/overworld/portraits/panik_neutral.lz");
static const unsigned char sPanikDefeatedTiles[] = INCBIN_U8("src/overworld/portraits/panik_defeated.lz");
static const unsigned char sBanditKeithNeutralTiles[] = INCBIN_U8("src/overworld/portraits/bandit_keith_neutral.lz");
static const unsigned char sBanditKeithDefeatedTiles[] = INCBIN_U8("src/overworld/portraits/bandit_keith_defeated.lz");
static const unsigned char sBanditKeithSurprisedTiles[] = INCBIN_U8("src/overworld/portraits/bandit_keith_surprised.lz");
static const unsigned char sBanditKeithPossessedTiles[] = INCBIN_U8("src/overworld/portraits/bandit_keith_possessed.lz");
static const unsigned char sStringsNeutralTiles[] = INCBIN_U8("src/overworld/portraits/strings_neutral.lz");
static const unsigned char sSeekerNeutralTiles[] = INCBIN_U8("src/overworld/portraits/seeker_neutral.lz");
static const unsigned char sSeekerDefeatedTiles[] = INCBIN_U8("src/overworld/portraits/seeker_defeated.lz");
static const unsigned char sArkanaNeutralTiles[] = INCBIN_U8("src/overworld/portraits/arkana_neutral.lz");
static const unsigned char sArkanaDefeatedTiles[] = INCBIN_U8("src/overworld/portraits/arkana_defeated.lz");
static const unsigned char sArkanaSurprisedTiles[] = INCBIN_U8("src/overworld/portraits/arkana_surprised.lz");
static const unsigned char sParaNeutralTiles[] = INCBIN_U8("src/overworld/portraits/para_neutral.lz");
static const unsigned char sParaHappyTiles[] = INCBIN_U8("src/overworld/portraits/para_happy.lz");
static const unsigned char sParaDefeatedTiles[] = INCBIN_U8("src/overworld/portraits/para_defeated.lz");
static const unsigned char sDoxNeutralTiles[] = INCBIN_U8("src/overworld/portraits/dox_neutral.lz");
static const unsigned char sDoxHappyTiles[] = INCBIN_U8("src/overworld/portraits/dox_happy.lz");
static const unsigned char sDoxDefeatedTiles[] = INCBIN_U8("src/overworld/portraits/dox_defeated.lz");
static const unsigned char sLumisNeutralTiles[] = INCBIN_U8("src/overworld/portraits/lumis_neutral.lz");
static const unsigned char sLumisDefeatedTiles[] = INCBIN_U8("src/overworld/portraits/lumis_defeated.lz");
static const unsigned char sUmbraNeutralTiles[] = INCBIN_U8("src/overworld/portraits/umbra_neutral.lz");
static const unsigned char sPuppeteerOfDoomNeutralTiles[] = INCBIN_U8("src/overworld/portraits/puppeteer_of_doom_neutral.lz");
static const unsigned char sJeanClaudeMagnumNeutralTiles[] = INCBIN_U8("src/overworld/portraits/jean_claude_magnum_neutral.lz");
static const unsigned char sJeanClaudeMagnumSadTiles[] = INCBIN_U8("src/overworld/portraits/jean_claude_magnum_sad.lz");
static const unsigned char sRolandNeutralTiles[] = INCBIN_U8("src/overworld/portraits/roland_neutral.lz");
static const unsigned char sDukeNeutralTiles[] = INCBIN_U8("src/overworld/portraits/duke_neutral.lz");
static const unsigned char sDukeSadTiles[] = INCBIN_U8("src/overworld/portraits/duke_sad.lz");
static const unsigned char sDukeClenchedTeethTiles[] = INCBIN_U8("src/overworld/portraits/duke_clenched_teeth.lz");
static const unsigned char sSerenityNeutralTiles[] = INCBIN_U8("src/overworld/portraits/serenity_neutral.lz");
static const unsigned char sSerenityAngryTiles[] = INCBIN_U8("src/overworld/portraits/serenity_angry.lz");
static const unsigned char sSerenitySadTiles[] = INCBIN_U8("src/overworld/portraits/serenity_sad.lz");
static const unsigned char sSerenitySurprisedTiles[] = INCBIN_U8("src/overworld/portraits/serenity_surprised.lz");
static const unsigned char sYamiMarikNeutralTiles[] = INCBIN_U8("src/overworld/portraits/yami_marik_neutral.lz");
static const unsigned char sYamiBakuraNeutralTiles[] = INCBIN_U8("src/overworld/portraits/yami_bakura_neutral.lz");
static const unsigned char sParadoxNeutralTiles[] = INCBIN_U8("src/overworld/portraits/paradox_neutral.lz");
static const unsigned char sNoahNeutralTiles[] = INCBIN_U8("src/overworld/portraits/noah_neutral.lz");
static const unsigned char sEvilJoeyNeutralTiles[] = INCBIN_U8("src/overworld/portraits/evil_joey_neutral.lz");
static const unsigned char sMonkeyRobotNeutralTiles[] = INCBIN_U8("src/overworld/portraits/monkey_robot_neutral.lz");
static const unsigned char sMonkeyRobotAngryTiles[] = INCBIN_U8("src/overworld/portraits/monkey_robot_angry.lz");
static const unsigned char sMonkeyRobotClenchedTeethTiles[] = INCBIN_U8("src/overworld/portraits/monkey_robot_clenched_teeth.lz"); // TODO
static const unsigned char sMonkeyRobotSurprisedTiles[] = INCBIN_U8("src/overworld/portraits/monkey_robot_surprised.lz");
static const unsigned char sRebeccaNeutralTiles[] = INCBIN_U8("src/overworld/portraits/rebecca_neutral.lz");
static const unsigned char sRebeccaClenchedTeethTiles[] = INCBIN_U8("src/overworld/portraits/rebecca_clenched_teeth.lz"); //TODO
static const unsigned char sTeddyNeutralTiles[] = INCBIN_U8("src/overworld/portraits/teddy_neutral.lz");
static const unsigned char sNightmarePenguinNeutralTiles[] = INCBIN_U8("src/overworld/portraits/nightmare_penguin_neutral.lz");
static const unsigned char sDeepseaWarriorNeutralTiles[] = INCBIN_U8("src/overworld/portraits/deepsea_warrior_neutral.lz");
static const unsigned char sRoboticKnightNeutralTiles[] = INCBIN_U8("src/overworld/portraits/robotic_knight_neutral.lz");
static const unsigned char sJinzoNeutralTiles[] = INCBIN_U8("src/overworld/portraits/jinzo_neutral.lz");
static const unsigned char sJudgeManNeutralTiles[] = INCBIN_U8("src/overworld/portraits/judge_man_neutral.lz");
static const unsigned char sMillenniumGuardianNeutralTiles[] = INCBIN_U8("src/overworld/portraits/millennium_guardian_neutral.lz");
static const unsigned char sKaibamanNeutralTiles[] = INCBIN_U8("src/overworld/portraits/kaibaman_neutral.lz");
static const unsigned char sMarikNeutralTiles[] = INCBIN_U8("src/overworld/portraits/marik_neutral.lz");
static const unsigned char sNeoGhoulNeutralTiles[] = INCBIN_U8("src/overworld/portraits/neo_ghoul_neutral.lz");
static const unsigned char sChevalierNeutralTiles[] = INCBIN_U8("src/overworld/portraits/chevalier_neutral.lz");
static const unsigned char sOdionNeutralTiles[] = INCBIN_U8("src/overworld/portraits/odion_neutral.lz");

static const unsigned char * CONST_DATA sNonePortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sNoneTiles
};

static const unsigned char * CONST_DATA sYugiPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sYugiNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sYugiHappyTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sYugiNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sYugiSadTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sYugiNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sYugiNeutralTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sYugiSurprisedTiles
};

static const unsigned char * CONST_DATA sAtemPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sAtemNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sAtemHappyTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sAtemAngryTiles
};

static const unsigned char * CONST_DATA sSetoPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sSetoNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sSetoHappyTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sSetoAngryTiles,
  [PORTRAIT_EXPRESSION_SAD] = sSetoSadTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sSetoNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sSetoClenchedTeethTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sSetoSurprisedTiles
};

static const unsigned char * CONST_DATA sJoeyPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sJoeyNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sJoeyNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sJoeyAngryTiles,
  [PORTRAIT_EXPRESSION_SAD] = sJoeySadTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sJoeyNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sJoeyClenchedTeethTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sJoeyNeutralTiles,
  [PORTRAIT_EXPRESSION_SWEAT_DROP] = sJoeySweatDropTiles
};

static const unsigned char * CONST_DATA sPegasusPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sPegasusNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sPegasusHappyTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sPegasusNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sPegasusSadTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sPegasusDefeatedTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sPegasusClenchedTeethTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sPegasusSurprisedTiles
};

static const unsigned char * CONST_DATA sMaiPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sMaiNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sMaiNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sMaiAngryTiles,
  [PORTRAIT_EXPRESSION_SAD] = sMaiNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sMaiNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sMaiNeutralTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sMaiNeutralTiles,
  [PORTRAIT_EXPRESSION_SWEAT_DROP] = sMaiSweatDropTiles
};

static const unsigned char * CONST_DATA sTeaPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sTeaNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sTeaNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sTeaNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sTeaSadTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sTeaNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sTeaNeutralTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sTeaSurprisedTiles,
  [PORTRAIT_EXPRESSION_SWEAT_DROP] = sTeaSweatDropTiles
};

static const unsigned char * CONST_DATA sSolomonPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sSolomonNeutralTiles
};

static const unsigned char * CONST_DATA sTristanPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sTristanNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sTristanHappyTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sTristanAngryTiles,
  [PORTRAIT_EXPRESSION_SAD] = sTristanNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sTristanDefeatedTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sTristanClenchedTeethTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sTristanSurprisedTiles
};

static const unsigned char * CONST_DATA sMokubaPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sMokubaNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sMokubaNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sMokubaAngryTiles,
  [PORTRAIT_EXPRESSION_SAD] = sMokubaSadTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sMokubaNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sMokubaNeutralTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sMokubaSurprisedTiles,
  [PORTRAIT_EXPRESSION_SWEAT_DROP] = sMokubaNeutralTiles,
  [PORTRAIT_EXPRESSION_POSSESSED] = sMokubaPossessedTiles
};

static const unsigned char * CONST_DATA sRexPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sRexNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sRexNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sRexAngryTiles,
  [PORTRAIT_EXPRESSION_SAD] = sRexNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sRexNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sRexNeutralTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sRexSurprisedTiles
};

static const unsigned char * CONST_DATA sMakoPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sMakoNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sMakoHappyTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sMakoNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sMakoNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sMakoNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sMakoNeutralTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sMakoNeutralTiles,
  [PORTRAIT_EXPRESSION_SWEAT_DROP] = sMakoSweatDropTiles
};

static const unsigned char * CONST_DATA sWeevilPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sWeevilNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sWeevilHappyTiles
};

static const unsigned char * CONST_DATA sEspaPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sEspaNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sEspaNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sEspaAngryTiles,
  [PORTRAIT_EXPRESSION_SAD] = sEspaNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sEspaNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sEspaNeutralTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sEspaNeutralTiles,
  [PORTRAIT_EXPRESSION_SWEAT_DROP] = sEspaSweatDropTiles,
  [PORTRAIT_EXPRESSION_POSSESSED] = sEspaNeutralTiles,
  [PORTRAIT_EXPRESSION_CLOSED_EYES] = sEspaClosedEyesTiles
};

static const unsigned char * CONST_DATA sBonzPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sBonzNeutralTiles
};

static const unsigned char * CONST_DATA sIshizuPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sIshizuNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sIshizuHappyTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sIshizuNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sIshizuNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sIshizuNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sIshizuNeutralTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sIshizuSurprisedTiles
};

static const unsigned char * CONST_DATA sShadiPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sShadiNeutralTiles
};

static const unsigned char * CONST_DATA sMimicOfDoomPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sMimicOfDoomNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sMimicOfDoomNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sMimicOfDoomNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sMimicOfDoomNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sMimicOfDoomDefeatedTiles
};

static const unsigned char * CONST_DATA sPanikPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sPanikNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sPanikNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sPanikNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sPanikNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sPanikDefeatedTiles
};

static const unsigned char * CONST_DATA sBanditKeithPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sBanditKeithNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sBanditKeithNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sBanditKeithNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sBanditKeithNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sBanditKeithDefeatedTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sBanditKeithNeutralTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sBanditKeithSurprisedTiles,
  [PORTRAIT_EXPRESSION_SWEAT_DROP] = sBanditKeithNeutralTiles,
  [PORTRAIT_EXPRESSION_POSSESSED] = sBanditKeithPossessedTiles
};

static const unsigned char * CONST_DATA sStringsPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sStringsNeutralTiles
};

static const unsigned char * CONST_DATA sSeekerPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sSeekerNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sSeekerNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sSeekerNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sSeekerNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sSeekerDefeatedTiles
};

static const unsigned char * CONST_DATA sArkanaPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sArkanaNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sArkanaNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sArkanaNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sArkanaNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sArkanaDefeatedTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sArkanaNeutralTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sArkanaSurprisedTiles
};

static const unsigned char * CONST_DATA sParaPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sParaNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sParaHappyTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sParaNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sParaNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sParaDefeatedTiles
};

static const unsigned char * CONST_DATA sDoxPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sDoxNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sDoxHappyTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sDoxNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sDoxNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sDoxDefeatedTiles
};

static const unsigned char * CONST_DATA sLumisPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sLumisNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sLumisNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sLumisNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sLumisNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sLumisDefeatedTiles
};

static const unsigned char * CONST_DATA sUmbraPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sUmbraNeutralTiles
};

static const unsigned char * CONST_DATA sPuppeteerOfDoomPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sPuppeteerOfDoomNeutralTiles
};

static const unsigned char * CONST_DATA sJeanClaudeMagnumPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sJeanClaudeMagnumNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sJeanClaudeMagnumNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sJeanClaudeMagnumNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sJeanClaudeMagnumSadTiles
};

static const unsigned char * CONST_DATA sRolandPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sRolandNeutralTiles
};

static const unsigned char * CONST_DATA sDukePortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sDukeNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sDukeNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sDukeNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sDukeSadTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sDukeNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sDukeClenchedTeethTiles
};

static const unsigned char * CONST_DATA sSerenityPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sSerenityNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sSerenityNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sSerenityAngryTiles,
  [PORTRAIT_EXPRESSION_SAD] = sSerenitySadTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sSerenityNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sSerenityNeutralTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sSerenitySurprisedTiles
};

static const unsigned char * CONST_DATA sYamiMarikPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sYamiMarikNeutralTiles
};

static const unsigned char * CONST_DATA sYamiBakuraPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sYamiBakuraNeutralTiles
};

static const unsigned char * CONST_DATA sParadoxPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sParadoxNeutralTiles
};

static const unsigned char * CONST_DATA sNoahPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sNoahNeutralTiles
};

static const unsigned char * CONST_DATA sEvilJoeyPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sEvilJoeyNeutralTiles
};

static const unsigned char * CONST_DATA sMonkeyRobotPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sMonkeyRobotNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sMonkeyRobotNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sMonkeyRobotAngryTiles,
  [PORTRAIT_EXPRESSION_SAD] = sMonkeyRobotNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sMonkeyRobotNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sMonkeyRobotClenchedTeethTiles,
  [PORTRAIT_EXPRESSION_SURPRISED] = sMonkeyRobotSurprisedTiles
};

static const unsigned char * CONST_DATA sRebeccaPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sRebeccaNeutralTiles,
  [PORTRAIT_EXPRESSION_HAPPY] = sRebeccaNeutralTiles,
  [PORTRAIT_EXPRESSION_ANGRY] = sRebeccaNeutralTiles,
  [PORTRAIT_EXPRESSION_SAD] = sRebeccaNeutralTiles,
  [PORTRAIT_EXPRESSION_DEFEATED] = sRebeccaNeutralTiles,
  [PORTRAIT_EXPRESSION_CLENCHED_TEETH] = sRebeccaClenchedTeethTiles
};

static const unsigned char * CONST_DATA sTeddyPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sTeddyNeutralTiles
};

static const unsigned char * CONST_DATA sNightmarePenguinPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sNightmarePenguinNeutralTiles
};

static const unsigned char * CONST_DATA sDeepseaWarriorPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sDeepseaWarriorNeutralTiles
};

static const unsigned char * CONST_DATA sRoboticKnightPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sRoboticKnightNeutralTiles
};

static const unsigned char * CONST_DATA sJinzoPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sJinzoNeutralTiles
};

static const unsigned char * CONST_DATA sJudgeManPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sJudgeManNeutralTiles
};

static const unsigned char * CONST_DATA sMillenniumGuardianPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sMillenniumGuardianNeutralTiles
};

static const unsigned char * CONST_DATA sKaibamanPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sKaibamanNeutralTiles
};

static const unsigned char * CONST_DATA sMarikPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sMarikNeutralTiles
};

static const unsigned char * CONST_DATA sNeoGhoulPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sNeoGhoulNeutralTiles
};

static const unsigned char * CONST_DATA sChevalierPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sChevalierNeutralTiles
};

static const unsigned char * CONST_DATA sOdionPortraits[] = {
  [PORTRAIT_EXPRESSION_NEUTRAL] = sOdionNeutralTiles
};

const unsigned char * const * CONST_DATA gPortraits[] = {
  [PORTRAIT_NONE] = sNonePortraits,
  [PORTRAIT_YUGI] = sYugiPortraits,
  [PORTRAIT_ATEM] = sAtemPortraits,
  [PORTRAIT_SETO] = sSetoPortraits,
  [PORTRAIT_JOEY] = sJoeyPortraits,
  [PORTRAIT_PEGASUS] = sPegasusPortraits,
  [PORTRAIT_MAI] = sMaiPortraits,
  [PORTRAIT_TEA] = sTeaPortraits,
  [PORTRAIT_SOLOMON] = sSolomonPortraits,
  [PORTRAIT_TRISTAN] = sTristanPortraits,
  [PORTRAIT_MOKUBA] = sMokubaPortraits,
  [PORTRAIT_REX] = sRexPortraits,
  [PORTRAIT_MAKO] = sMakoPortraits,
  [PORTRAIT_WEEVIL] = sWeevilPortraits,
  [PORTRAIT_ESPA] = sEspaPortraits,
  [PORTRAIT_BONZ] = sBonzPortraits,
  [PORTRAIT_ISHIZU] = sIshizuPortraits,
  [PORTRAIT_SHADI] = sShadiPortraits,
  [PORTRAIT_MIMIC_OF_DOOM] = sMimicOfDoomPortraits,
  [PORTRAIT_PANIK] = sPanikPortraits,
  [PORTRAIT_BANDIT_KEITH] = sBanditKeithPortraits,
  [PORTRAIT_STRINGS] = sStringsPortraits,
  [PORTRAIT_SEEKER] = sSeekerPortraits,
  [PORTRAIT_ARKANA] = sArkanaPortraits,
  [PORTRAIT_PARA] = sParaPortraits,
  [PORTRAIT_DOX] = sDoxPortraits,
  [PORTRAIT_LUMIS] = sLumisPortraits,
  [PORTRAIT_UMBRA] = sUmbraPortraits,
  [PORTRAIT_PUPPETEER_OF_DOOM] = sPuppeteerOfDoomPortraits,
  [PORTRAIT_JEAN_CLAUDE_MAGNUM] = sJeanClaudeMagnumPortraits,
  [PORTRAIT_ROLAND] = sRolandPortraits,
  [PORTRAIT_DUKE] = sDukePortraits,
  [PORTRAIT_SERENITY] = sSerenityPortraits,
  [PORTRAIT_YAMI_MARIK] = sYamiMarikPortraits,
  [PORTRAIT_YAMI_BAKURA] = sYamiBakuraPortraits,
  [PORTRAIT_PARADOX] = sParadoxPortraits,
  [PORTRAIT_NOAH] = sNoahPortraits,
  [PORTRAIT_EVIL_JOEY] = sEvilJoeyPortraits,
  [PORTRAIT_MONKEY_ROBOT] = sMonkeyRobotPortraits,
  [PORTRAIT_REBECCA] = sRebeccaPortraits,
  [PORTRAIT_TEDDY] = sTeddyPortraits,
  [PORTRAIT_NIGHTMARE_PENGUIN] = sNightmarePenguinPortraits,
  [PORTRAIT_DEEPSEA_WARRIOR] = sDeepseaWarriorPortraits,
  [PORTRAIT_ROBOTIC_KNIGHT] = sRoboticKnightPortraits,
  [PORTRAIT_JINZO] = sJinzoPortraits,
  [PORTRAIT_JUDGE_MAN] = sJudgeManPortraits,
  [PORTRAIT_MILLENNIUM_GUARDIAN] = sMillenniumGuardianPortraits,
  [PORTRAIT_KAIBAMAN] = sKaibamanPortraits,
  [PORTRAIT_MARIK] = sMarikPortraits,
  [PORTRAIT_NEO_GHOUL] = sNeoGhoulPortraits,
  [PORTRAIT_CHEVALIER] = sChevalierPortraits,
  [PORTRAIT_ODION] = sOdionPortraits
};

static const unsigned short sNonePalette[] = INCBIN_U16("src/overworld/portraits/none.gbapal");
static const unsigned short sYugiPalette[] = INCBIN_U16("src/overworld/portraits/yugi.gbapal");
static const unsigned short sAtemPalette[] = INCBIN_U16("src/overworld/portraits/atem.gbapal");
static const unsigned short sSetoPalette[] = INCBIN_U16("src/overworld/portraits/seto.gbapal");
static const unsigned short sJoeyPalette[] = INCBIN_U16("src/overworld/portraits/joey.gbapal");
static const unsigned short sPegasusPalette[] = INCBIN_U16("src/overworld/portraits/pegasus.gbapal");
static const unsigned short sMaiPalette[] = INCBIN_U16("src/overworld/portraits/mai.gbapal");
static const unsigned short sTeaPalette[] = INCBIN_U16("src/overworld/portraits/tea.gbapal");
static const unsigned short sSolomonPalette[] = INCBIN_U16("src/overworld/portraits/solomon.gbapal");
static const unsigned short sTristanPalette[] = INCBIN_U16("src/overworld/portraits/tristan.gbapal");
static const unsigned short sMokubaPalette[] = INCBIN_U16("src/overworld/portraits/mokuba.gbapal");
static const unsigned short sRexPalette[] = INCBIN_U16("src/overworld/portraits/rex.gbapal");
static const unsigned short sMakoPalette[] = INCBIN_U16("src/overworld/portraits/mako.gbapal");
static const unsigned short sWeevilPalette[] = INCBIN_U16("src/overworld/portraits/weevil.gbapal");
static const unsigned short sEspaPalette[] = INCBIN_U16("src/overworld/portraits/espa.gbapal");
static const unsigned short sBonzPalette[] = INCBIN_U16("src/overworld/portraits/bonz.gbapal");
static const unsigned short sIshizuPalette[] = INCBIN_U16("src/overworld/portraits/ishizu.gbapal");
static const unsigned short sShadiPalette[] = INCBIN_U16("src/overworld/portraits/shadi.gbapal");
static const unsigned short sMimicOfDoomPalette[] = INCBIN_U16("src/overworld/portraits/mimic_of_doom.gbapal");
static const unsigned short sPanikPalette[] = INCBIN_U16("src/overworld/portraits/panik.gbapal");
static const unsigned short sBanditKeithPalette[] = INCBIN_U16("src/overworld/portraits/bandit_keith.gbapal");
static const unsigned short sStringsPalette[] = INCBIN_U16("src/overworld/portraits/strings.gbapal");
static const unsigned short sSeekerPalette[] = INCBIN_U16("src/overworld/portraits/seeker.gbapal");
static const unsigned short sArkanaPalette[] = INCBIN_U16("src/overworld/portraits/arkana.gbapal");
static const unsigned short sParaPalette[] = INCBIN_U16("src/overworld/portraits/para.gbapal");
static const unsigned short sDoxPalette[] = INCBIN_U16("src/overworld/portraits/dox.gbapal");
static const unsigned short sLumisPalette[] = INCBIN_U16("src/overworld/portraits/lumis.gbapal");
static const unsigned short sUmbraPalette[] = INCBIN_U16("src/overworld/portraits/umbra.gbapal");
static const unsigned short sPuppeteerOfDoomPalette[] = INCBIN_U16("src/overworld/portraits/puppeteer_of_doom.gbapal");
static const unsigned short sJeanClaudeMagnumPalette[] = INCBIN_U16("src/overworld/portraits/jean_claude_magnum.gbapal");
static const unsigned short sRolandPalette[] = INCBIN_U16("src/overworld/portraits/roland.gbapal");
static const unsigned short sDukePalette[] = INCBIN_U16("src/overworld/portraits/duke.gbapal");
static const unsigned short sSerenityPalette[] = INCBIN_U16("src/overworld/portraits/serenity.gbapal");
static const unsigned short sYamiMarikPalette[] = INCBIN_U16("src/overworld/portraits/yami_marik.gbapal");
static const unsigned short sYamiBakuraPalette[] = INCBIN_U16("src/overworld/portraits/yami_bakura.gbapal");
static const unsigned short sParadoxPalette[] = INCBIN_U16("src/overworld/portraits/paradox.gbapal");
static const unsigned short sNoahPalette[] = INCBIN_U16("src/overworld/portraits/noah.gbapal");
static const unsigned short sEvilJoeyPalette[] = INCBIN_U16("src/overworld/portraits/evil_joey.gbapal");
static const unsigned short sMonkeyRobotPalette[] = INCBIN_U16("src/overworld/portraits/monkey_robot.gbapal");
static const unsigned short sRebeccaPalette[] = INCBIN_U16("src/overworld/portraits/rebecca.gbapal");
static const unsigned short sTeddyPalette[] = INCBIN_U16("src/overworld/portraits/teddy.gbapal");
static const unsigned short sNightmarePenguinPalette[] = INCBIN_U16("src/overworld/portraits/nightmare_penguin.gbapal");
static const unsigned short sDeepseaWarriorPalette[] = INCBIN_U16("src/overworld/portraits/deepsea_warrior.gbapal");
static const unsigned short sRoboticKnightPalette[] = INCBIN_U16("src/overworld/portraits/robotic_knight.gbapal");
static const unsigned short sJinzoPalette[] = INCBIN_U16("src/overworld/portraits/jinzo.gbapal");
static const unsigned short sJudgeManPalette[] = INCBIN_U16("src/overworld/portraits/judge_man.gbapal");
static const unsigned short sMillenniumGuardianPalette[] = INCBIN_U16("src/overworld/portraits/millennium_guardian.gbapal");
static const unsigned short sKaibamanPalette[] = INCBIN_U16("src/overworld/portraits/kaibaman.gbapal");
static const unsigned short sMarikPalette[] = INCBIN_U16("src/overworld/portraits/marik.gbapal");
static const unsigned short sNeoGhoulPalette[] = INCBIN_U16("src/overworld/portraits/neo_ghoul.gbapal");
static const unsigned short sChevalierPalette[] = INCBIN_U16("src/overworld/portraits/chevalier.gbapal");
static const unsigned short sOdionPalette[] = INCBIN_U16("src/overworld/portraits/odion.gbapal");

static const unsigned short * CONST_DATA sNonePalettes[] = {
  sNonePalette
};

static const unsigned short * CONST_DATA sYugiPalettes[] = {
  sYugiPalette
};

static const unsigned short * CONST_DATA sAtemPalettes[] = {
  sAtemPalette
};

static const unsigned short * CONST_DATA sSetoPalettes[] = {
  sSetoPalette
};

static const unsigned short * CONST_DATA sJoeyPalettes[] = {
  sJoeyPalette
};

static const unsigned short * CONST_DATA sPegasusPalettes[] = {
  sPegasusPalette
};

static const unsigned short * CONST_DATA sMaiPalettes[] = {
  sMaiPalette
};

static const unsigned short * CONST_DATA sTeaPalettes[] = {
  sTeaPalette
};

static const unsigned short * CONST_DATA sSolomonPalettes[] = {
  sSolomonPalette
};

static const unsigned short * CONST_DATA sTristanPalettes[] = {
  sTristanPalette
};

static const unsigned short * CONST_DATA sMokubaPalettes[] = {
  sMokubaPalette
};

static const unsigned short * CONST_DATA sRexPalettes[] = {
  sRexPalette
};

static const unsigned short * CONST_DATA sMakoPalettes[] = {
  sMakoPalette
};

static const unsigned short * CONST_DATA sWeevilPalettes[] = {
  sWeevilPalette
};

static const unsigned short * CONST_DATA sEspaPalettes[] = {
  sEspaPalette
};

static const unsigned short * CONST_DATA sBonzPalettes[] = {
  sBonzPalette
};

static const unsigned short * CONST_DATA sIshizuPalettes[] = {
  sIshizuPalette
};

static const unsigned short * CONST_DATA sShadiPalettes[] = {
  sShadiPalette
};

static const unsigned short * CONST_DATA sMimicOfDoomPalettes[] = {
  sMimicOfDoomPalette
};

static const unsigned short * CONST_DATA sPanikPalettes[] = {
  sPanikPalette
};

static const unsigned short * CONST_DATA sBanditKeithPalettes[] = {
  sBanditKeithPalette
};

static const unsigned short * CONST_DATA sStringsPalettes[] = {
  sStringsPalette
};

static const unsigned short * CONST_DATA sSeekerPalettes[] = {
  sSeekerPalette
};

static const unsigned short * CONST_DATA sArkanaPalettes[] = {
  sArkanaPalette
};

static const unsigned short * CONST_DATA sParaPalettes[] = {
  sParaPalette
};

static const unsigned short * CONST_DATA sDoxPalettes[] = {
  sDoxPalette
};

static const unsigned short * CONST_DATA sLumisPalettes[] = {
  sLumisPalette
};

static const unsigned short * CONST_DATA sUmbraPalettes[] = {
  sUmbraPalette
};

static const unsigned short * CONST_DATA sPuppeteerOfDoomPalettes[] = {
  sPuppeteerOfDoomPalette
};

static const unsigned short * CONST_DATA sJeanClaudeMagnumPalettes[] = {
  sJeanClaudeMagnumPalette
};

static const unsigned short * CONST_DATA sRolandPalettes[] = {
  sRolandPalette
};

static const unsigned short * CONST_DATA sDukePalettes[] = {
  sDukePalette
};

static const unsigned short * CONST_DATA sSerenityPalettes[] = {
  sSerenityPalette
};

static const unsigned short * CONST_DATA sYamiMarikPalettes[] = {
  sYamiMarikPalette
};

static const unsigned short * CONST_DATA sYamiBakuraPalettes[] = {
  sYamiBakuraPalette
};

static const unsigned short * CONST_DATA sParadoxPalettes[] = {
  sParadoxPalette
};

static const unsigned short * CONST_DATA sNoahPalettes[] = {
  sNoahPalette
};

static const unsigned short * CONST_DATA sEvilJoeyPalettes[] = {
  sEvilJoeyPalette
};

static const unsigned short * CONST_DATA sMonkeyRobotPalettes[] = {
  sMonkeyRobotPalette
};

static const unsigned short * CONST_DATA sRebeccaPalettes[] = {
  sRebeccaPalette
};

static const unsigned short * CONST_DATA sTeddyPalettes[] = {
  sTeddyPalette
};

static const unsigned short * CONST_DATA sNightmarePenguinPalettes[] = {
  sNightmarePenguinPalette
};

static const unsigned short * CONST_DATA sDeepseaWarriorPalettes[] = {
  sDeepseaWarriorPalette
};

static const unsigned short * CONST_DATA sRoboticKnightPalettes[] = {
  sRoboticKnightPalette
};

static const unsigned short * CONST_DATA sJinzoPalettes[] = {
  sJinzoPalette
};

static const unsigned short * CONST_DATA sJudgeManPalettes[] = {
  sJudgeManPalette
};

static const unsigned short * CONST_DATA sMillenniumGuardianPalettes[] = {
  sMillenniumGuardianPalette
};

static const unsigned short * CONST_DATA sKaibamanPalettes[] = {
  sKaibamanPalette
};

static const unsigned short * CONST_DATA sMarikPalettes[] = {
  sMarikPalette
};

static const unsigned short * CONST_DATA sNeoGhoulPalettes[] = {
  sNeoGhoulPalette
};

static const unsigned short * CONST_DATA sChevalierPalettes[] = {
  sChevalierPalette
};

static const unsigned short * CONST_DATA sOdionPalettes[] = {
  sOdionPalette
};

const unsigned short * const * CONST_DATA gPortraitPalettes[] = {
  [PORTRAIT_NONE] = sNonePalettes,
  [PORTRAIT_YUGI] = sYugiPalettes,
  [PORTRAIT_ATEM] = sAtemPalettes,
  [PORTRAIT_SETO] = sSetoPalettes,
  [PORTRAIT_JOEY] = sJoeyPalettes,
  [PORTRAIT_PEGASUS] = sPegasusPalettes,
  [PORTRAIT_MAI] = sMaiPalettes,
  [PORTRAIT_TEA] = sTeaPalettes,
  [PORTRAIT_SOLOMON] = sSolomonPalettes,
  [PORTRAIT_TRISTAN] = sTristanPalettes,
  [PORTRAIT_MOKUBA] = sMokubaPalettes,
  [PORTRAIT_REX] = sRexPalettes,
  [PORTRAIT_MAKO] = sMakoPalettes,
  [PORTRAIT_WEEVIL] = sWeevilPalettes,
  [PORTRAIT_ESPA] = sEspaPalettes,
  [PORTRAIT_BONZ] = sBonzPalettes,
  [PORTRAIT_ISHIZU] = sIshizuPalettes,
  [PORTRAIT_SHADI] = sShadiPalettes,
  [PORTRAIT_MIMIC_OF_DOOM] = sMimicOfDoomPalettes,
  [PORTRAIT_PANIK] = sPanikPalettes,
  [PORTRAIT_BANDIT_KEITH] = sBanditKeithPalettes,
  [PORTRAIT_STRINGS] = sStringsPalettes,
  [PORTRAIT_SEEKER] = sSeekerPalettes,
  [PORTRAIT_ARKANA] = sArkanaPalettes,
  [PORTRAIT_PARA] = sParaPalettes,
  [PORTRAIT_DOX] = sDoxPalettes,
  [PORTRAIT_LUMIS] = sLumisPalettes,
  [PORTRAIT_UMBRA] = sUmbraPalettes,
  [PORTRAIT_PUPPETEER_OF_DOOM] = sPuppeteerOfDoomPalettes,
  [PORTRAIT_JEAN_CLAUDE_MAGNUM] = sJeanClaudeMagnumPalettes,
  [PORTRAIT_ROLAND] = sRolandPalettes,
  [PORTRAIT_DUKE] = sDukePalettes,
  [PORTRAIT_SERENITY] = sSerenityPalettes,
  [PORTRAIT_YAMI_MARIK] = sYamiMarikPalettes,
  [PORTRAIT_YAMI_BAKURA] = sYamiBakuraPalettes,
  [PORTRAIT_PARADOX] = sParadoxPalettes,
  [PORTRAIT_NOAH] = sNoahPalettes,
  [PORTRAIT_EVIL_JOEY] = sEvilJoeyPalettes,
  [PORTRAIT_MONKEY_ROBOT] = sMonkeyRobotPalettes,
  [PORTRAIT_REBECCA] = sRebeccaPalettes,
  [PORTRAIT_TEDDY] = sTeddyPalettes,
  [PORTRAIT_NIGHTMARE_PENGUIN] = sNightmarePenguinPalettes,
  [PORTRAIT_DEEPSEA_WARRIOR] = sDeepseaWarriorPalettes,
  [PORTRAIT_ROBOTIC_KNIGHT] = sRoboticKnightPalettes,
  [PORTRAIT_JINZO] = sJinzoPalettes,
  [PORTRAIT_JUDGE_MAN] = sJudgeManPalettes,
  [PORTRAIT_MILLENNIUM_GUARDIAN] = sMillenniumGuardianPalettes,
  [PORTRAIT_KAIBAMAN] = sKaibamanPalettes,
  [PORTRAIT_MARIK] = sMarikPalettes,
  [PORTRAIT_NEO_GHOUL] = sNeoGhoulPalettes,
  [PORTRAIT_CHEVALIER] = sChevalierPalettes,
  [PORTRAIT_ODION] = sOdionPalettes
};
