#include "global.h"

unsigned char g2020DC8; //where the player came from
unsigned char g2020DCC; //where the player is going
unsigned char g2020DD0; //world map state (how many places are unlocked)

static void LoadWorldMapGfx (unsigned char, unsigned char);

/*static*/ const unsigned char gWorldMapTiles[] = INCBIN_U8("src/world_map/world_map.lz");
/*static*/ const unsigned short gWorldMapPalette[] = INCBIN_U16("src/world_map/world_map.gbapal");
/*static*/ const unsigned short gWorldMapTilemap[][30] = INCBIN_U16("src/world_map/world_map.tilemap");

/*static*/ const unsigned char sClockTowerSquareTiles[] = INCBIN_U8("src/world_map/locations/clock_tower_square.8bpp");
/*static*/ const unsigned char sDominoStationTiles[] = INCBIN_U8("src/world_map/locations/domino_station.8bpp");
/*static*/ const unsigned char sEgyptExhibitionTiles[] = INCBIN_U8("src/world_map/locations/egypt_exhibition.8bpp");
/*static*/ const unsigned char sDominoPierTiles[] = INCBIN_U8("src/world_map/locations/domino_pier.8bpp");
/*static*/ const unsigned char sItalyTiles[] = INCBIN_U8("src/world_map/locations/italy.8bpp");
/*static*/ const unsigned char sChinaTiles[] = INCBIN_U8("src/world_map/locations/china.8bpp");
/*static*/ const unsigned char sCanadaTiles[] = INCBIN_U8("src/world_map/locations/canada.8bpp");
/*static*/ const unsigned char sGalapagosTiles[] = INCBIN_U8("src/world_map/locations/galapagos.8bpp");
/*static*/ const unsigned char sPegasusIslandTiles[] = INCBIN_U8("src/world_map/locations/pegasus_island.8bpp");
/*static*/ const unsigned char sDungeonTiles[] = INCBIN_U8("src/world_map/locations/dungeon.8bpp");
/*static*/ const unsigned char sPegasusCastleTiles[] = INCBIN_U8("src/world_map/locations/pegasus_castle.8bpp");
/*static*/ const unsigned char sHallOfEternityTiles[] = INCBIN_U8("src/world_map/locations/hall_of_eternity.8bpp");
/*static*/ const unsigned char sEgyptTiles[] = INCBIN_U8("src/world_map/locations/egypt.8bpp");

/*static*/ const unsigned short sClockTowerSquarePalette[] = INCBIN_U16("src/world_map/locations/clock_tower_square.gbapal");
/*static*/ const unsigned short sDominoStationPalette[] = INCBIN_U16("src/world_map/locations/domino_station.gbapal");
/*static*/ const unsigned short sEgyptExhibitionPalette[] = INCBIN_U16("src/world_map/locations/egypt_exhibition.gbapal");
/*static*/ const unsigned short sDominoPierPalette[] = INCBIN_U16("src/world_map/locations/domino_pier.gbapal");
/*static*/ const unsigned short sItalyPalette[] = INCBIN_U16("src/world_map/locations/italy.gbapal");
/*static*/ const unsigned short sChinaPalette[] = INCBIN_U16("src/world_map/locations/china.gbapal");
/*static*/ const unsigned short sCanadaPalette[] = INCBIN_U16("src/world_map/locations/canada.gbapal");
/*static*/ const unsigned short sGalapagosPalette[] = INCBIN_U16("src/world_map/locations/galapagos.gbapal");
/*static*/ const unsigned short sPegasusIslandPalette[] = INCBIN_U16("src/world_map/locations/pegasus_island.gbapal");
/*static*/ const unsigned short sDungeonPalette[] = INCBIN_U16("src/world_map/locations/dungeon.gbapal");
/*static*/ const unsigned short sPegasusCastlePalette[] = INCBIN_U16("src/world_map/locations/pegasus_castle.gbapal");
/*static*/ const unsigned short sHallOfEternityPalette[] = INCBIN_U16("src/world_map/locations/hall_of_eternity.gbapal");
/*static*/ const unsigned short sEgyptPalette[] = INCBIN_U16("src/world_map/locations/egypt.gbapal");



/*static*/extern const unsigned short sTextPalette[32]; // = {0, 0x7bde} TODO: RGB(30, 30, 30)? text palette
/*static*/extern const unsigned short sCursorPalette[];

struct OamD {u16 attr0, attr1, attr2;};

struct Unk8DF76F8 {
  unsigned char unk0;
  unsigned char unk1;
  struct OamD * unk4; // (cursor sprites)
};
/*
static CONST_DATA struct OamD gUnk_8DF7598 {
  .attr0 = 
};

static const struct Unk8DF76F8 gUnk_80741F8[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7598},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF75A0},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF75A8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF75B0},
  0
};

static const struct Unk8DF76F8 gUnk_8074220[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF75B8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF75C0},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF75C8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF75D0},
  0
};

static const struct Unk8DF76F8 gUnk_8074248[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF75D8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF75E0},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF75E8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF75F0},
  0
};

static const struct Unk8DF76F8 gUnk_8074270[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF75F8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7600},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7608},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7610},
  0
};

static const struct Unk8DF76F8 gUnk_8074298[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7618},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7620},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7628},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7630},
  0
};

static const struct Unk8DF76F8 gUnk_80742C0[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7638},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7640},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7648},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7650},
  0
};

static const struct Unk8DF76F8 gUnk_80742E8[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7658},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7660},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7668},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7670},
  0
};

static const struct Unk8DF76F8 gUnk_8074310[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7678},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7680},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7688},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7690},
  0
};

static const struct Unk8DF76F8 gUnk_8074338[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7698},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76A0},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76A8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76B0},
  0
};

static const struct Unk8DF76F8 gUnk_8074360[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7698},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76A0},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76A8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76B0},
  0
};

static const struct Unk8DF76F8 gUnk_8074388[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF7698},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76A0},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76A8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76B0},
  0
};

static const struct Unk8DF76F8 gUnk_80743B0[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76B8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76C0},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76C8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76D0},
  0
};

static const struct Unk8DF76F8 gUnk_80743D8[] = {
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76D8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76E0},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76E8},
  {.unk0 = 10, unk1 = 1, unk4 = gUnk_8DF76F0},
  0
};
*/
extern const struct Unk8DF76F8 * CONST_DATA gUnk_8DF76F8[];

extern const unsigned short gUnk_8074400[]; //location indicator palette


extern union OamUnion {
  unsigned short oamU16[4];
  unsigned long oamU32[2];
  struct OamData oamStruct;
} gOamBuffer[];

void sub_80055D8 (void);


extern u16 gPressedButtons;
extern u16 gNewButtons;

extern u16 gUnk_8DF79F8[];
extern CONST_DATA unsigned char gUnk_8DF7A18[];

extern struct Unk_8DF7A28 {
  u16 unk0;
  unsigned char filler2[0x21];
  unsigned char unk23;
  unsigned char unk24;
} * gUnk_8DF7A28;

extern unsigned char gSharedMem[];

extern u32 gUnk_80746F8[];

extern u16 gUnk_8073BA0[][30]; //bg 2 tilemap; the bg used for location text
extern unsigned char sText_ClockTowerSquare[];
extern unsigned char sText_DominoStation[];
extern unsigned char sText_EgyptExhibition[];
extern unsigned char sText_DominoPier[];
extern unsigned char sText_Italy[];
extern unsigned char sText_China[];
extern unsigned char sText_Canada[];
extern unsigned char sText_Galapagos[];
extern unsigned char sText_PegasusIsland[];
extern unsigned char sText_Dungeon[];
extern unsigned char sText_PegasusCastle[];
extern unsigned char sText_HallOfEternity[];






unsigned char sub_80056CC(unsigned char);
void sub_80054C4(unsigned char);
void sub_80056AC (void);
void sub_80052E4 (unsigned char);
void sub_800521C (unsigned char);
void sub_80056F8 (void);
void sub_8005590 (void);
void ClearGraphicsBuffers (void);

enum WorldMapLocation {
  WORLD_MAP_LOCATION_CLOCK_TOWER_SQUARE,
  WORLD_MAP_LOCATION_DOMINO_STATION,
  WORLD_MAP_LOCATION_EGYPT_EXHIBITION,
  WORLD_MAP_LOCATION_DOMINO_PIER,
  WORLD_MAP_LOCATION_ITALY,
  WORLD_MAP_LOCATION_CHINA,
  WORLD_MAP_LOCATION_CANADA,
  WORLD_MAP_LOCATION_GALAPAGOS,
  WORLD_MAP_LOCATION_PEGASUS_ISLAND,
  WORLD_MAP_LOCATION_DUNGEON,
  WORLD_MAP_LOCATION_PEGASUS_CASTLE,
  WORLD_MAP_LOCATION_HALL_OF_ETERNITY,
  WORLD_MAP_LOCATION_EGYPT,
  WORLD_MAP_NUM_LOCATIONS //TODO: there are 3 unused locations
};

enum WorldMapUnlockedLocation {
  WORLD_MAP_UNLOCKED_LOCATION_DOMINO_STATION,
  WORLD_MAP_UNLOCKED_LOCATION_EGYPT_EXHIBITION,
  WORLD_MAP_UNLOCKED_LOCATION_DOMINO_PIER,
  WORLD_MAP_UNLOCKED_LOCATION_ITALY,
  WORLD_MAP_UNLOCKED_LOCATION_CHINA,
  WORLD_MAP_UNLOCKED_LOCATION_CANADA,
  WORLD_MAP_UNLOCKED_LOCATION_GALAPAGOS,
  WORLD_MAP_UNLOCKED_LOCATION_PEGASUS_ISLAND,
  WORLD_MAP_UNLOCKED_LOCATION_DUNGEON,
  WORLD_MAP_UNLOCKED_LOCATION_PEGASUS_CASTLE,
  WORLD_MAP_UNLOCKED_LOCATION_HALL_OF_ETERNITY,
  WORLD_MAP_UNLOCKED_LOCATION_EGYPT
};
/*
void WorldMapMain (void) {
  unsigned char selectedLocation = sub_80056CC(g2020DC8);
  const unsigned char latestUnlockedLocation = g2020DD0 % 16; //TODO: % NUM_LOCATIONS, there are 13 true locations, 3 unused
  LoadWorldMapGfx(selectedLocation, latestUnlockedLocation);
  PlayMusic(MUSIC_WORLD_MAP);
  while (!(gNewButtons & (A_BUTTON | B_BUTTON))) {
    if (gPressedButtons & 0xF0) {
      if (gUnk_8DF7A28->unk0 & 0x60)
        do {
          if (selectedLocation)
            selectedLocation--;
          else
            selectedLocation = WORLD_MAP_NUM_LOCATIONS - 1;
          PlayMusic(SFX_MOVE_CURSOR);
        } while (!(gUnk_8DF79F8[latestUnlockedLocation] >> gUnk_8DF7A18[selectedLocation] & 1));
      else if (gUnk_8DF7A28->unk0 & 0x90)
        do {
          if (selectedLocation < WORLD_MAP_NUM_LOCATIONS - 1)
            selectedLocation++;
          else
            selectedLocation = 0;
          PlayMusic(SFX_MOVE_CURSOR);
        } while (!(gUnk_8DF79F8[latestUnlockedLocation] >> gUnk_8DF7A18[selectedLocation] & 1));
      sub_80054C4(gUnk_8DF7A18[selectedLocation]);
    }
    sub_80056AC();
    sub_800521C(gUnk_8DF7A18[selectedLocation]);
    sub_80052E4(latestUnlockedLocation);
    LoadOam();
    LoadPalettes();
    WaitForVBlank();
    sub_8005590();
  }
  PlayMusic(SFX_SELECT);
  sub_80056F8();
  ClearGraphicsBuffers();
  LoadOam();
  LoadPalettes();
  LoadVRAM();
  DisableDisplay();
  g2020DCC = gUnk_8DF7A18[selectedLocation];
} */

NAKED
void WorldMapMain (void) {
  asm_unified("push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	ldr r0, _08004E90\n\
	ldrb r0, [r0]\n\
	bl sub_80056CC\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	ldr r0, _08004E94\n\
	ldrb r0, [r0]\n\
	movs r7, #0xf\n\
	ands r7, r0\n\
	adds r0, r4, #0\n\
	adds r1, r7, #0\n\
	bl LoadWorldMapGfx\n\
	movs r0, #3\n\
	bl PlayMusic\n\
	ldr r6, _08004E98\n\
	ldr r0, _08004E9C\n\
	mov r8, r0\n\
	b _08004F4A\n\
	.align 2, 0\n\
_08004E90: .4byte 0x02020DC8\n\
_08004E94: .4byte 0x02020DD0\n\
_08004E98: .4byte gUnk_8DF7A18\n\
_08004E9C: .4byte gUnk_8DF79F8\n\
_08004EA0:\n\
	ldr r0, _08004ECC\n\
	ldrh r1, [r0]\n\
	movs r0, #0xf0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08004F28\n\
	ldr r0, _08004ED0\n\
	ldr r0, [r0]\n\
	ldrh r1, [r0]\n\
	movs r0, #0x60\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08004EEE\n\
	lsls r0, r7, #1\n\
	mov r1, r8\n\
	adds r5, r0, r1\n\
_08004EC0:\n\
	cmp r4, #0\n\
	beq _08004ED4\n\
	subs r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	b _08004ED6\n\
	.align 2, 0\n\
_08004ECC: .4byte gPressedButtons\n\
_08004ED0: .4byte gUnk_8DF7A28\n\
_08004ED4:\n\
	movs r4, #0xc\n\
_08004ED6:\n\
	movs r0, #0x36\n\
	bl PlayMusic\n\
	ldrh r0, [r5]\n\
	adds r1, r4, r6\n\
	ldrb r1, [r1]\n\
	asrs r0, r1\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08004EC0\n\
	b _08004F20\n\
_08004EEE:\n\
	movs r0, #0x90\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08004F20\n\
	lsls r0, r7, #1\n\
	mov r1, r8\n\
	adds r5, r0, r1\n\
_08004EFC:\n\
	cmp r4, #0xb\n\
	bhi _08004F08\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	b _08004F0A\n\
_08004F08:\n\
	movs r4, #0\n\
_08004F0A:\n\
	movs r0, #0x36\n\
	bl PlayMusic\n\
	ldrh r0, [r5]\n\
	adds r1, r4, r6\n\
	ldrb r1, [r1]\n\
	asrs r0, r1\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08004EFC\n\
_08004F20:\n\
	adds r0, r4, r6\n\
	ldrb r0, [r0]\n\
	bl sub_80054C4\n\
_08004F28:\n\
	bl sub_80056AC\n\
	adds r0, r4, r6\n\
	ldrb r0, [r0]\n\
	bl sub_800521C\n\
	adds r0, r7, #0\n\
	bl sub_80052E4\n\
	bl LoadOam\n\
	bl LoadPalettes\n\
	bl WaitForVBlank\n\
	bl sub_8005590\n\
_08004F4A:\n\
	ldr r0, _08004F88\n\
	ldrh r1, [r0]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08004EA0\n\
	movs r0, #0x37\n\
	bl PlayMusic\n\
	bl sub_80056F8\n\
	bl ClearGraphicsBuffers\n\
	bl LoadOam\n\
	bl LoadPalettes\n\
	bl LoadVRAM\n\
	bl DisableDisplay\n\
	ldr r0, _08004F8C\n\
	adds r1, r4, r6\n\
	ldrb r1, [r1]\n\
	strb r1, [r0]\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08004F88: .4byte gNewButtons\n\
_08004F8C: .4byte 0x02020DCC");
}

static void LoadWorldMapGfx (unsigned char arg0, unsigned char arg1) {
  unsigned short i;
  for (i = 0; i < 0x4314; i++)
    gSharedMem[i] = 0;
  ClearGraphicsBuffers();
  LoadOam();
  LoadPalettes();
  LoadVRAM();
  DisableDisplay();
  LZ77UnCompWram(gWorldMapTiles, gVramBuffer); //TODO: gbagfx says Destination buffer overflow when decompressing
  for (i = 0; i < 20; i++)
    DmaCopy16(3, gWorldMapTilemap[i], gVramBuffer + 0x9800 + i * 64, 60);
  for (i = 0; i < 2; i++)
    DmaCopy16(3, gUnk_8073BA0[i], gVramBuffer + 0xA014 + i * 64, 60); //bg 2 tilemap: location text
  for (i = 0; i < 6; i++)
    CpuCopy16(sClockTowerSquareTiles + i * 640, gVramBuffer + 0x10000 + i * 0x400, 640); //location clock tower square tiles
  LZ77UnCompWram(gUnk_80746F8, gVramBuffer + 0x14000); // cursor tiles

  // Location names
  CopyStringTilesToVRAMBuffer(gVramBuffer + 0xC020, sText_ClockTowerSquare, 0x901);
  CopyStringTilesToVRAMBuffer(gVramBuffer + 0xC520, sText_DominoStation, 0x901);
  CopyStringTilesToVRAMBuffer(gVramBuffer + 0xCA20, sText_EgyptExhibition, 0x901);
  CopyStringTilesToVRAMBuffer(gVramBuffer + 0xCF20, sText_DominoPier, 0x901);
  CopyStringTilesToVRAMBuffer(gVramBuffer + 0xD420, sText_Italy, 0x901);
  CopyStringTilesToVRAMBuffer(gVramBuffer + 0xD920, sText_China, 0x901);
  CopyStringTilesToVRAMBuffer(gVramBuffer + 0xDE20, sText_Canada, 0x901);
  CopyStringTilesToVRAMBuffer(gVramBuffer + 0xE320, sText_Galapagos, 0x901);
  CopyStringTilesToVRAMBuffer(gVramBuffer + 0xE820, sText_PegasusIsland, 0x901);
  CopyStringTilesToVRAMBuffer(gVramBuffer + 0xED20, sText_Dungeon, 0x901);
  CopyStringTilesToVRAMBuffer(gVramBuffer + 0xF220, sText_PegasusCastle, 0x901);
  CopyStringTilesToVRAMBuffer(gVramBuffer + 0xF720, sText_HallOfEternity, 0x901);

  CpuCopy16(gWorldMapPalette, gPaletteBuffer, 0x180);
  CpuCopy16(sTextPalette, gPaletteBuffer + 0xF0, 0x20);
  CpuCopy16(sClockTowerSquarePalette, gPaletteBuffer + 0x100, 0x100);
  CpuCopy16(sCursorPalette, gPaletteBuffer + 0x180, 0x20);
  CpuCopy16(gUnk_8074400, gPaletteBuffer + 0x190, 0x20);

  SetVBlankCallback(sub_80055D8);
  sub_80054C4(gUnk_8DF7A18[arg0]);
  sub_80056AC();
  sub_800521C(gUnk_8DF7A18[arg0]);
  sub_80052E4(arg1);
  LoadOam();
  LoadVRAM();
  LoadPalettes();
  WaitForVBlank();
}

/*gUnk_8DF7A18[] = {
  
};*/
/*
//cursor sprites
void sub_800521C (unsigned char arg0) {
  union OamUnion* oam;
  //const struct Unk8DF76F8 * temp;
  if (gUnk_8DF7A28->unk23 == gUnk_8DF76F8[arg0][gUnk_8DF7A28->unk24].unk0) {
    gUnk_8DF7A28->unk23 = 0;
    gUnk_8DF7A28->unk24++;
    if (gUnk_8DF7A28->unk24 > 3)
      gUnk_8DF7A28->unk24 = 0;
  }
  else
    gUnk_8DF7A28->unk23++;

  //TODO: macro?
  //OAM_REGULAR_U32_1(X, Y, 
  //OAM_REGULAR_U32_2(
  //visible sprite
  oam = gOamBuffer + 2;
  //temp = gUnk_8DF76F8[arg0];
  oam[0].oamU32[0] = ((gUnk_8DF76F8[arg0][gUnk_8DF7A28->unk24].unk4->attr1 & 0x1FF) << 16) |
           (gUnk_8DF76F8[arg0][gUnk_8DF7A28->unk24].unk4->attr0 & 0xFF) |
           0x80000000;
  oam[0].oamU32[1] = gUnk_8DF76F8[arg0][gUnk_8DF7A28->unk24].unk4->attr2 | 0x208;

  //window sprite
  oam[1].oamU32[0] = ((gUnk_8DF76F8[arg0][gUnk_8DF7A28->unk24].unk4->attr1 & 0x1FF) << 16) |
           (gUnk_8DF76F8[arg0][gUnk_8DF7A28->unk24].unk4->attr0 & 0xFF) |
           0x80000800;
  oam[1].oamU32[1] = gUnk_8DF76F8[arg0][gUnk_8DF7A28->unk24].unk4->attr2 | 0x208;
}*/

/*
unsigned char sub_80056CC (unsigned char arg0) {
  unsigned char i;
  for (i = 0; i < WORLD_MAP_NUM_LOCATIONS; i++)
    if (gUnk_8DF7A18[i] == arg0)
      return i;
}
*/
