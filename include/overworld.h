#ifndef GUARD_OVERWORLD_H
#define GUARD_OVERWORLD_H

//TODO: ObjectDirection?
enum Direction {
  DIRECTION_DOWN,
  DIRECTION_LEFT,
  DIRECTION_UP,
  DIRECTION_RIGHT
};

enum OverworldLocation {
  LOCATION_CLOCK_TOWER_SQUARE_NORTHWEST,
  LOCATION_CLOCK_TOWER_SQUARE_NORTH,
  LOCATION_CLOCK_TOWER_SQUARE_NORTHEAST,
  LOCATION_CLOCK_TOWER_SQUARE_SOUTHEAST,
  LOCATION_CLOCK_TOWER_SQUARE_SOUTH,
  LOCATION_CLOCK_TOWER_SQUARE_SOUTHWEST,
  LOCATION_CARD_SHOP_OUTSIDE,
  LOCATION_CARD_SHOP_INSIDE,
  LOCATION_PLAYER_HOUSE_OUTSIDE,
  LOCATION_PLAYER_HOUSE_INSIDE,
  LOCATION_CLOCK_TOWER_SQUARE_BACK_ALLEY_NORTH,
  LOCATION_CLOCK_TOWER_SQUARE_BACK_ALLEY_NORTH_EAST,
  LOCATION_KAIBACORP,
  LOCATION_DUEL_MACHINE,
  LOCATION_DOMINO_STATION_TURNSTILES,
  LOCATION_DOMINO_STATION_TRAIN_STATION,
  LOCATION_DUEL_EXPRESS_CARRIAGE_RIGHT,
  LOCATION_DUEL_EXPRESS_CARRIAGE_MIDDLE,
  LOCATION_DUEL_EXPRESS_CARRIAGE_LEFT,
  LOCATION_ITALY_CATACOMBS_MIDDLE,
  LOCATION_EGYPT_EXHIBITION_TRAIN_STATION,
  LOCATION_EGYPT_EXHIBITION_TURNSTILES,
  LOCATION_EGYPT_EXHIBITION_ARTWORK,
  LOCATION_EGYPT_EXHIBITION_MILLENNIUM_GUARDIAN,
  LOCATION_DOMINO_PIER_DOCKS,
  LOCATION_DOMINO_PIER_CASINO_LEFT_ROOM,
  LOCATION_DOMINO_PIER_CASINO_MAIN_ROOM,
  LOCATION_DOMINO_PIER_MILLENNIUM_GUARDIAN,
  LOCATION_ITALY_CATACOMBS_LEFT,
  LOCATION_ITALY_CATACOMBS_RIGHT,
  LOCATION_ITALY_MILLENNIUM_GUARDIAN,
  LOCATION_CHINA_GREAT_WALL_ENTRANCE,
  LOCATION_CHINA_GREAT_WALL,
  LOCATION_CHINA_GREAT_WALL_MILLENNIUM_GUARDIAN,
  LOCATION_CANADA_RUINS_OUTSIDE,
  LOCATION_CANADA_RUINS_INSIDE,
  LOCATION_CANADA_RUINS_MILLENNIUM_GUARDIAN,
  LOCATION_GALAPAGOS_BEACH,
  LOCATION_GALAPAGOS_FOREST,
  LOCATION_GALAPAGOS_TEMPLE,
  LOCATION_PEGASUS_ISLAND_CABLE_CAR_BOTTOM_OUTSIDE,
  LOCATION_PEGASUS_ISLAND_CABLE_CAR_INSIDE,
  LOCATION_PEGASUS_ISLAND_CABLE_CAR_TOP_OUTSIDE,
  LOCATION_PEGASUS_ISLAND_DUNGEON_ENTRANCE,
  LOCATION_PEGASUS_ISLAND_DUNGEON_LAVA_ROOM_SOUTH,
  LOCATION_PEGASUS_ISLAND_DUNGEON_CLIFF,
  LOCATION_PEGASUS_ISLAND_DUNGEON_LAVA_ROOM_NORTH,
  LOCATION_PEGASUS_ISLAND_DUNGEON_BRIDGE,
  LOCATION_PEGASUS_ISLAND_DUNGEON_STAIRCASE,
  LOCATION_PEGASUS_ISLAND_DUNGEON_RUINS,
  LOCATION_PEGASUS_CASTLE_OUTSIDE,
  LOCATION_PEGASUS_CASTLE_HALLWAY,
  LOCATION_PEGASUS_CASTLE_LEFT_ROOM,
  LOCATION_PEGASUS_CASTLE_RIGHT_ROOM,
  LOCATION_PEGASUS_CASTLE_DUEL_ROOM,
  LOCATION_PEGASUS_CASTLE_RESHEF_TABLET_ROOM,
  LOCATION_HALL_OF_ETERNITY,
  LOCATION_KAIBA_LAND,
  LOCATION_CLOCK_TOWER_SQUARE_NORTH_WEST2_TODO,
  LOCATION_EGYPT,
  LOCATION_EGYPT_MARIK_ROOM
};

enum PortraitPosition {
  PORTRAIT_POSITION_LEFT,
  PORTRAIT_POSITION_RIGHT,
  PORTRAIT_POSITION_OFF_SCREEN,
  PORTRAIT_POSITION_AUTO = 8
};

enum Portrait {
  PORTRAIT_NONE
};

//TODO: create PortraitExpression enum for each character

enum Motion {
  MOTION_STATIONARY,
  MOTION_WALKING,
  MOTION_RUNNING
};

enum OverworldBackground {
  OVERWORLD_BACKGROUND_NORMAL,
  OVERWORLD_BACKGROUND_RESHEF,
  OVERWORLD_BACKGROUND_GOEMON_IMPACT
};

void OverworldMain (void);
void sub_804DF5C (int objectId);
void sub_804EB04 (struct OamData* arg0, u8 arg1);
void sub_804EC4C (void);
void sub_804EC64 (void);
void sub_804ECA8 (void);
void OverworldLoadGraphics (void);

//script structs
struct Script
{
    u8* start;
    struct Script* unk4; // script to execute when flag is cleared/selected yes/duel won...
    struct Script* unk8; // script to execute when flag is set/selected no/duel lost...
};

//TODO: rename to ScriptContext?
struct ScriptCtx {
  unsigned short portraitId;
  u32 pointer; // rename to offset?
  u32 unk8; //current glyph offset?
  u8 unkC;
  u8 unkD;
  struct Script currentScript;
  u16 unk1C; //frame counter for text cursor when waiting for user input
  u8 unk1E; //decides the next script to be executed based on certain outcomes
  u16 unk20;
  u8 unk22[0x52];
  u16 unk74;
  u16 unk76;
  u8 unk78;
  u16 unk7A;
  u16 unk7C;
  u16 unk7E;
  u16 unk80;
  u16 unk82;
  u8 unk84;
  u8 unk85;
  u8 unk86;
};

//TODO: change terminology from Map to Location? (struct OverworldLocation)

//overworld structs
struct Map //MapHeader?
{
    u16 id;
    u16 state;
    u16 unk4; //which connection the player came from?
    u8 unk6;
    u8 unk7;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
};

//struct OverworldObject
struct Object
{
    s16 spriteId;
    u8 direction; //facing D L U R
    s16 x; //pos[0]?
    s16 y; //pos[1]?
    s16 unk8;
    u8 unkA;
    u16 unkC;
    u8 unkE;
    u8 unkF;
    struct Script *scriptA;
    struct Script *scriptR;
    unsigned char motionState;
    s16 unk1A;
    u8 unk1C;
    u8 hasShadow : 1;
    u8 facePlayer : 1;
    u8 wander : 1;
    u8 unk1Dl : 1;
    u8 enableBlending : 1;
    u8 unk1E;
};

struct Overworld
{
    struct Map map; //inline instead?
    struct Object objects[15];
    u8 unk1F0;
    u8 unk1F1;
    u8 unk1F2;
    u8 unk1F3;
    struct Script *unk1F4[5];
    struct Script *unk208[5];
    s16 unk21C[15];
    u8 unk23A;
    u16 *unk23C; //collision data
    u8 unk240;
    unsigned short music;
    int unk244;
    int unk248;
    s16 unk24C; // used when the screen shakes due to earthquake effect; it modifies the background and sprite y position
    s16 unk24E; // ^same but x position
    enum OverworldBackground background;
};

struct ObjectData {
  signed short spriteId;
  enum Direction direction;
  unsigned short x;
  unsigned short y;
  struct Script *scriptA;
  struct Script *scriptR;
  u8 hasShadow : 1;
  u8 facePlayer : 1;
  u8 wander : 1;
  u8 unk11;
};

struct MapScript
{
    struct Script *unk0;
    unsigned char unk4; //mapid, map connection
    unsigned char unk5;
};

struct MapData
{
    struct ObjectData objects[16];  //terminated by a -1 (0xFFFF) spriteId
    struct MapScript unk140[5];
    struct MapScript unk168[5];
    struct ObjectData playerInitialState[5]; // num_connections (including world map)
    u16 music;
    u8 unk1F6; //bitfield?
};

extern struct Overworld gOverworld;
extern u16* gMapCollisions[]; //gMapCollisionData
extern struct MapData** gMapData[]; //0xE19274

extern u8* gUnk8E11790[];
extern u16 gUnk08103264[];
extern u16 g8103284[];
extern u16 g81032A2[];
extern struct Script* g8F04040;

void sub_8052088(u8); //implicit declaration?
void sub_804DF5C(int);
void sub_804EF10 (void);
void InitiateScript (struct Script *);
u16 sub_80520E0(u8 x, u8 y);
u32 CheckFlag(u32);


void sub_8053388(struct ScriptCtx *script);
void sub_805339C (void);
void sub_80533BC (void);
void sub_8053404 ();  //TODO: implicit declaration
void sub_8053CF0 (u8 obj, s16 x, s16 y, u16 arg3, struct ScriptCtx* script);
void sub_8053D50(u8, u8, struct ScriptCtx *script);
void sub_8053D88(u8, u8, u8, struct ScriptCtx *script);
void sub_8053E34(u8);
inline void sub_8053E94(struct ScriptCtx* script);


extern const u32 g8E0E4CC[];
extern const u32 g8E0E53C[];

void ClearFlag(u32);
void DuelTrunkMenu(void);
void OverworldSetRegDispcnt2(void);



void sub_805345C(u8, u8, u8, u8, struct ScriptCtx *script);
void sub_8034FE0(void);
void sub_8053520(u8, s16, s16, u16, u8, u8, struct ScriptCtx *script);
void sub_8053984(u8, u8, struct ScriptCtx *script);
void sub_8053A74(u8, u8, struct ScriptCtx *script);
void sub_8053884(u16, u8, struct ScriptCtx *script);
void sub_8054AB0(u8, struct ScriptCtx *script);
void sub_804F218(void);


void sub_8053C18(struct ScriptCtx *script, u8);
unsigned sub_80524A4(u16);
void sub_805339C(void);
void OverworldSetRegDispcnt(void);
void sub_8053B40(u8, u16, struct ScriptCtx *script);
void sub_80512E0(struct ScriptCtx *script, u8);

void PlayOverworldMusic (void);


void sub_804F750(u8);

void sub_80523EC(u16, u16, u16);
void sub_0804F76C(void);
void SetFlag(u32);
void SaveGame(void);
void InitiateScript(struct Script *);
void PlayOverworldMusic(void);
void sub_804F5D8(void);

void sub_8035038(u16);


extern u16 g82AD48C[];
extern const u32 g82AD2D0[];

extern u32 gE0E674[];
extern u32 gE0E754[];

s8 sub_8051E48 (u8, u8, u8);
void sub_804F19C (int);



void sub_804F124 (u8 objectId);
void sub_804F254 (void);
void sub_804F054 (int spriteId, int arg1, u8* dest);
void sub_804F1F4 (void);
void SaveLfsrState (u32);

extern u32 g84C9FBC[];
extern u16 g82AD06C[];
extern u16 g82ADC8C[];
extern u16 g84D0CE0[];
extern u16 g84CFCE0[];
extern u16 g84D04E0[];
extern u32 g84D0EC0[];
extern u16 g84D69D0[];
extern u16 g84D59D0[];
extern u16 g84D61D0[];

#endif // GUARD_OVERWORLD_H
