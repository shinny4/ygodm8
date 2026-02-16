#include "global.h"

// displacement of 1px based on direction
extern s8 g8E0E834[]; //x
extern s8 g8E0E838[]; //y

extern s16 gE0E83C[];
extern s8 gE0E854[]; // how many frames to wait?
extern s8 gE0E865[];

extern const struct {int a, b;} g8105114[][27];

int sub_8056070 (u16);
void sub_804F28C (void);
void sub_804EFE8 (int);

void sub_805345C (u8 obj, u8 direction, u8 distance, u8 arg3, struct ScriptCtx *script) {
  int i;
  script->unk86 = 0;
  sub_8053404(script);
  gOverworld.objects[obj].direction = direction;
  for (i = 0; i < distance; i++) {
    gOverworld.objects[obj].x += g8E0E834[direction];
    gOverworld.objects[obj].y += g8E0E838[direction];
    sub_8052088(obj);
    sub_804F124(obj);
    sub_804DF5C(obj);
    sub_804F254();
    sub_804F254();
  }
  gOverworld.objects[obj].wander = 0;
  if (arg3 == 1)
    gOverworld.objects[obj].wander = 1;
  sub_804F19C(obj);
  sub_804DF5C(obj);
  sub_804F254();
}



void sub_8053520 (u8 obj, s16 x, s16 y, u16 arg3, u8 arg4, u8 arg5_unused, struct ScriptCtx *script) {
  int i;
  switch (arg4) {
    case 0:
      gOverworld.objects[obj].x = x;
      gOverworld.objects[obj].y = y;
      gOverworld.objects[obj].wander = 0;
      sub_8052088(obj);
      sub_804F054(gOverworld.objects[obj].spriteId,
                  gOverworld.objects[obj].direction * 3 + arg3,
                  gBgVram.cbb4 + gUnk08103264[obj] * 32);
      sub_804F218();
      break;
    case 1:
      gOverworld.objects[obj].enableBlending = 1;
      REG_BLDCNT = 0xE40;
      gOverworld.objects[obj].x = x;
      gOverworld.objects[obj].y = y;
      gOverworld.objects[obj].wander = 0;
      sub_8052088(obj);
      sub_804F054(gOverworld.objects[obj].spriteId,
                  gOverworld.objects[obj].direction * 3 + arg3,
                  gBgVram.cbb4 + gUnk08103264[obj] * 32);
      for (i = 16; i >= 0; i--) {
        REG_BLDALPHA = ((i & 31) << 8) | ((16 - i) & 31);
        sub_804F218();
        sub_804F218();
        sub_804F218();
        sub_804F218();
      }
      break;
    case 2:
      gOverworld.objects[obj].x = x;
      gOverworld.objects[obj].y = y;
      gOverworld.objects[obj].wander = 0;
      sub_8052088(obj);
      sub_804F054(gOverworld.objects[obj].spriteId,
                  gOverworld.objects[obj].direction * 3 + arg3,
                  gBgVram.cbb4 + gUnk08103264[obj] * 32);
      for (i = 0; gE0E83C[i] != -1; i++) {
        gOverworld.objects[obj].unkA = gE0E83C[i];
        sub_804F218();
      }
      break;
    case 3:
      gOverworld.objects[obj].x = x;
      gOverworld.objects[obj].y = y;
      gOverworld.objects[obj].wander = 0;
      gOverworld.objects[obj].hasShadow = 1;
      sub_8052088(obj);
      sub_804F054(gOverworld.objects[obj].spriteId,
                  gOverworld.objects[obj].direction * 3 + arg3,
                  gBgVram.cbb4 + gUnk08103264[obj] * 32);
      sub_804F218();
      break;
    case 4:
      gOverworld.objects[obj].x = x;
      gOverworld.objects[obj].y = y;
      gOverworld.objects[obj].wander = 0;
      gOverworld.objects[obj].hasShadow = 0;
      sub_8052088(obj);
      sub_804F054(gOverworld.objects[obj].spriteId,
                  gOverworld.objects[obj].direction * 3 + arg3,
                  gBgVram.cbb4 + gUnk08103264[obj] * 32);
      sub_804F218();
      break;
  }
}

void sub_8053730 (u16 arg0, struct ScriptCtx* script) {
  u16 sp[15][3];
  u8 i;
  script->unk86 = 0;
  sub_8053404(script);
  for (i = 0; i < 15; i++) {
    sp[i][0] = gOverworld.objects[i].x;
    sp[i][1] = gOverworld.objects[i].y;
    sp[i][2] = gOverworld.objects[i].unk8;
  }
  for (i = 0; gE0E854[i] != -1; i++) {
    u8 j;
    u16 mask = 1;

    for (j = 0; j < 15; mask <<= 1, j++)
      if (arg0 & mask) {
        gOverworld.objects[j].x = sp[j][0];
        gOverworld.objects[j].y = sp[j][1];
        gOverworld.objects[j].unk8 = sp[j][2];
      }

    for (j = 0; j < gE0E854[i]; j++)
      sub_804F254();

    i++;

    for (mask = 1, j = 0; j < 15; mask <<= 1, j++)
      if (arg0 & mask) {
        gOverworld.objects[j].x = 0xC0;
        gOverworld.objects[j].y = 0xC0;
        gOverworld.objects[j].unk8 = 0;
      }

    for (j = 0; j < gE0E854[i]; j++)
      sub_804F254();
  }
}

void sub_8053884 (u16 arg0, u8 arg1, struct ScriptCtx* script) {
  int i, ii;
  u16 mask;
  switch (arg1) {
    case 0:
      script->unk86 = 0;
      sub_8053404(script);
      for (mask = 1, i = 0; i < 15; mask <<= 1, i++)
        if (arg0 & mask) {
          gOverworld.objects[i].wander = 0;
          gOverworld.objects[i].hasShadow = 0;
          gOverworld.objects[i].facePlayer = 0;
          gOverworld.objects[i].direction = 4;
          gOverworld.objects[i].unkE = 0;
          sub_804DF5C(i);
        }
      sub_804F254();
      break;
    case 1:
      script->unk86 = 0;
      sub_8053404(script);
      for (ii = 0; gE0E865[ii] != -1; ii++) {
        for (mask = 1, i = 0; i < 15; mask <<= 1, i++)
          if (arg0 & mask)
            gOverworld.objects[i].unkA = gE0E865[ii];
        sub_804F254();
      }
      break;
    case 2:
      sub_8053730(arg0, script);
      break;
  }
}

void sub_8053984 (u8 obj, u8 arg1, struct ScriptCtx* script) {
  int distance, i;
  s16 temp;

  script->unk86 = 0;
  sub_8053404(script);
  temp = arg1;
  if (arg1 > 223) {
    temp = (s8)arg1; // implementation defined?
  }
  gOverworld.objects[obj].direction = 3;
  distance = temp - gOverworld.objects[obj].x;
  if (gOverworld.objects[obj].x > temp) {
    gOverworld.objects[obj].direction = 1;
    distance = gOverworld.objects[obj].x - temp;
  }
  for (i = 0; i < distance; i++) {
    // Paradox brothers sound effect
    if (gOverworld.objects[obj].spriteId == 122 || gOverworld.objects[obj].spriteId == 123)
      if (i % 15 == 0)
        PlayMusic(MUSIC_313);

    gOverworld.objects[obj].x += g8E0E834[gOverworld.objects[obj].direction];
    gOverworld.objects[obj].y += g8E0E838[gOverworld.objects[obj].direction];
    sub_8052088(obj);
    sub_804F124(obj);
    sub_804DF5C(obj);
    sub_804F254();
    sub_804F254();
  }
  gOverworld.objects[obj].wander = 0;
  sub_804F19C(obj);
  sub_804DF5C(obj);
  sub_804F254();
}

void sub_8053A74 (u8 obj, u8 arg1, struct ScriptCtx* script) {
  int distance, i;
  s16 temp;

  script->unk86 = 0;
  sub_8053404(script);

  temp = arg1;
  if (arg1 > 223) {
    temp = (s8)arg1; // implementation defined?
  }
  gOverworld.objects[obj].direction = 0;
  distance = temp - gOverworld.objects[obj].y;
  if (gOverworld.objects[obj].y > temp) {
    gOverworld.objects[obj].direction = 2;
    distance = gOverworld.objects[obj].y - temp;
  }
  for (i = 0; i < distance; i++) {
    gOverworld.objects[obj].x += g8E0E834[gOverworld.objects[obj].direction];
    gOverworld.objects[obj].y += g8E0E838[gOverworld.objects[obj].direction];
    sub_8052088(obj);
    sub_804F124(obj);
    sub_804DF5C(obj);
    sub_804F254();
    sub_804F254();
  }
  gOverworld.objects[obj].wander = 0;
  sub_804F19C(obj);
  sub_804DF5C(obj);
  sub_804F254();
}

void sub_8053B40(u8 reaction, u16 arg1, struct ScriptCtx* script) {
  unsigned i;
  script->unk86 = 0;
  sub_8053404(script);
  for (i = 0; g8105114[reaction][i].a != -1; i++) {
    int j;
    u16 mask;
    for (mask = 1, j = 0; j < 15; mask <<= 1, j++) {
      if (arg1 & mask) {
        gOverworld.objects[j].unk1C = g8105114[reaction][i].a;
        sub_804EFE8(j);
      }
    }
    sub_804F28C();
    for (j = 1; j < g8105114[reaction][i].b; j++)
      sub_804F28C();
  }
}

inline void sub_8053E94 (struct ScriptCtx* script) {
  script->unk1E = 0;
  if (CheckFlag(0x52) && CheckFlag(0x53) &&
      CheckFlag(0x54) && CheckFlag(0x55) && CheckFlag(0x56))
    script->unk1E = 1;
}

inline void sub_8053ED8 (struct ScriptCtx* script) {
  script->unk1E = 0;
  if (sub_8056070(0) == 1)
    script->unk1E = 1;
}

inline void sub_8053EF0 (struct ScriptCtx* script) {
  script->unk1E = 0;
  if (sub_8056070(1) == 1)
    script->unk1E = 1;
}

inline void sub_8053F0C (struct ScriptCtx* script) {
  script->unk1E = 0;
  if (CanAfford(1000) == 1)
    script->unk1E = 1;
}

void sub_8053C18 (struct ScriptCtx* script, u8 arg1) {
  switch (arg1) {
    case 0:
      sub_8053E94(script);
      break;
    case 1:
      sub_8053ED8(script);
      break;
    case 2:
      sub_8053EF0(script);
      break;
    case 3:
      sub_8053F0C(script);
      break;
  }
}

//unused? inline?
void sub_8053CA8 (u8 obj, s16 x, s16 y, struct ScriptCtx* script) {
  script->unk86 = 0;
  sub_8053404(script);
  gOverworld.objects[obj].x = x;
  gOverworld.objects[obj].y = y;
  sub_8052088(obj);
  sub_804DF5C(obj);
  sub_804F218();
}

void sub_8053CF0 (u8 obj, s16 x, s16 y, u16 arg3, struct ScriptCtx* script) {
  gOverworld.objects[obj].x = x;
  gOverworld.objects[obj].y = y;
  gOverworld.objects[obj].wander = 0;
  sub_8052088(obj);
  sub_804F054(gOverworld.objects[obj].spriteId,
              gOverworld.objects[obj].direction * 3 + arg3,
              gBgVram.cbb4 + gUnk08103264[obj] * 32);
  sub_804F218();
}

void sub_8053D50 (u8 obj, u8 arg1, struct ScriptCtx* script) {
  script->unk86 = 0;
  sub_8053404(script);
  gOverworld.objects[obj].spriteId = arg1;
  sub_804DF5C(obj);
  sub_804F1F4();
}

// move object faster (twice the "normal" speed)
void sub_8053D88 (u8 obj, u8 direction, u8 distance, struct ScriptCtx* script) {
  int i;

  script->unk86 = 0;
  sub_8053404(script);
  for (i = 0; i < distance / 2; i++) {
    gOverworld.objects[obj].x += g8E0E834[direction] * 2;
    gOverworld.objects[obj].y += g8E0E838[direction] * 2;
    sub_8052088(obj);
    sub_804DF5C(obj);
    sub_804F254();
  }
  gOverworld.objects[obj].wander = 0;
  sub_804F19C(obj);
  sub_804DF5C(obj);
  sub_804F254();
}

void sub_8053E34 (u8 arg0) {
  int i, temp;
  sub_805339C();
  OverworldSetRegDispcnt();
  REG_BLDCNT = 0xFF;
  REG_WINOUT = 0x3D3E;
  for (i = 0; i < 16; i++) {
    REG_BLDY = i;
    temp = arg0;
    while (--temp != -1)
      sub_804F218();
  }
}
