#include <iostream>
#include <fstream>
#include <vector>
#include "../rapidjson/document.h"
using namespace std;
using namespace rapidjson;

// TODO: Document the convention for auto-generated symbols and names (defines, card art paths, etc.)

/*
  This program should generate:
    constants/card_ids.h (card_id.h?)
    card_data.c arrays
    equip spells file
    card graphics files (paths to big and mini card art)
*/

static vector<string> sEnglishNames;
static vector<string> sSanitizedEnglishNames;
static vector<string> sFrenchNames;
static vector<string> sGermanNames;
static vector<string> sItalianNames;
static vector<string> sSpanishNames;
static vector<string> sTypes;
static vector<string> sColors;
static vector<unsigned> sDeckCosts;
static vector<unsigned> sNumStars;
static vector<string> sAttributes;
static vector<unsigned> sAttacks;
static vector<unsigned> sDefenses;

struct EquipSpell {
  string name;
  vector<string> targets;
};

static vector<EquipSpell> sEquipSpells;

static void ParseJson ();
static void SanitizeEnglishNames ();
static void GenerateCardEnumFile ();
static void GenerateCardDataFile ();
static void GenerateEquipSpellFile ();
static void GenerateCardArtworksFile ();

int main () {
  ParseJson();
  SanitizeEnglishNames();
  //GenerateCardEnumFile();
  //GenerateCardDataFile();
  //GenerateEquipSpellFile();
  //GenerateCardArtworksFile();
}

// TODO: handle errors for missing object members that are expected to be present
static void ParseJson() {
  const char * cardJson = "[{\
    \"english\": \"Blue-Eyes White Dragon\",\
    \"french\": \"Dragon blanc aux yeux bleus\",\
    \"german\": \"Blauugiger w. Drache\",\
    \"italian\": \"Drago Bianco Occhi Blu\",\
    \"spanish\": \"Dragn blanco azul - ojos\",\
    \"type\": \"CARD_TYPE_DRAGON\",\
    \"color\": \"CARD_COLOR_NORMAL_MONSTER\",\
    \"deck_cost\": 95,\
    \"num_stars\": 8,\
    \"attribute\": \"CARD_ATTRIBUTE_LIGHT\",\
    \"attack\": 3000,\
    \"defense\": 2500\
  }]";
  Document document;
  document.Parse(cardJson);
  for (auto & card : document.GetArray()) {
    sEnglishNames.push_back(card["english"].GetString());
    sFrenchNames.push_back(card.FindMember("french")->value.GetString());
    sGermanNames.push_back(card.FindMember("german")->value.GetString());
    sItalianNames.push_back(card.FindMember("italian")->value.GetString());
    sSpanishNames.push_back(card.FindMember("spanish")->value.GetString());
    sTypes.push_back(card.FindMember("type")->value.GetString());
    sColors.push_back(card.FindMember("color")->value.GetString());
    sDeckCosts.push_back(card.FindMember("deck_cost")->value.GetUint());
    sNumStars.push_back(card.FindMember("num_stars")->value.GetUint());
    sAttributes.push_back(card.FindMember("attribute")->value.GetString());
    sAttacks.push_back(card.FindMember("attack")->value.GetUint());
    sDefenses.push_back(card.FindMember("defense")->value.GetUint());
    auto memberEquipTargets = card.FindMember("equip_targets");
    if (memberEquipTargets != card.MemberEnd()) {
      EquipSpell equipSpell;
      equipSpell.name = card["english"].GetString();
      vector<string> targets;
      for (auto & equipTarget : memberEquipTargets->value.GetArray())
        targets.push_back(equipTarget.GetString());
      equipSpell.targets = targets;
      sEquipSpells.push_back(equipSpell);
    }
  }
}


//TODO: handle card names that start with a digit
//Current method: manually map the original name to a target name
//Other possible methods: auto-convert the number into word
//but this is complex for big numbers (e.g. 30, 000-Year White Turtle)
static struct {
  string originalName;
  string targetName;
} sDigitPrefixedNames[] = {
  {"30, 000-Year White Turtle", "Thirty thousand-Year White Turtle"},
  {"7 Colored Fish", "Seven Colored Fish"},
  {"7 Completed", "Seven Completed"}
};

string ConvertDigitPrefixedName (string name) {
  for (auto & digitName : sDigitPrefixedNames)
    if (digitName.originalName == name)
      return digitName.targetName;
  return "UNMAPPED_DIGIT_NAME";
  // TODO: handle error. i.e. the case where a mapping from original to target name hasn't been defined in the array above
  //cerr <<
  //possible exit()?
};

static void SanitizeEnglishNames () {
  for (string englishName : sEnglishNames) {
    string sanitizedName = "";
    if (isdigit(englishName[0]))
      sanitizedName = ConvertDigitPrefixedName(englishName);
    else {
      for (unsigned i = 0; i < englishName.length(); i++) {
        switch (englishName[i]) {
          case '\'':
            break;
          case ' ':
          case '-':
          case '.':
            sanitizedName += '_';
            break;
          default:
            sanitizedName += englishName[i];
            break;
        }
      }
    }
    sSanitizedEnglishNames.push_back(sanitizedName);
  }
}

// TODO: output header guards
static void GenerateCardEnumFile () {
  ofstream cardEnumFile;
  cardEnumFile.open("constants/cards.h");
  if (!cardEnumFile.is_open()) {
    cerr << "Error: unable to open cards.h\n";
    return;
  }
  cardEnumFile << "// DO NOT MODIFY THIS FILE! It is auto-generated from card.json\n";
  cardEnumFile << "enum Card {\n";
  for (string & sanitizedName : sSanitizedEnglishNames) {
    cardEnumFile << "  ";
    for (unsigned i = 0; i < sanitizedName.length(); i++)
      cardEnumFile << static_cast<unsigned char>(toupper(sanitizedName[i]));
    cardEnumFile << ",\n";
  }
  cardEnumFile.close();
}

static void GenerateCardDataFile (void) {
  ofstream cardDataFile;
  cardDataFile.open("../../src/card_data.c");
  if (!cardDataFile.is_open()) {
    cerr << "Error: unable to open card_data.c\n";
    return;
  }
  cardDataFile << "const unsigned short gCardDefenses[] = {\n";
  for (auto & defense : sDefenses)
    cardDataFile << "  " << defense << ",\n";
  cardDataFile << "};\n\n";
  cardDataFile << "const unsigned short gCardAttacks[] = {\n";
  for (auto & attack : sAttacks)
    cardDataFile << "  " << attack << ",\n";
  cardDataFile << "};\n\n";
  cardDataFile << "const unsigned gCardDeckCosts[] = {\n";
  for (auto & cost : sDeckCosts)
    cardDataFile << "  " << cost << ",\n";
  cardDataFile << "};\n\n";
  cardDataFile << "const enum CardAttribute gCardAttributes[] = {\n";
  for (auto & attribute : sAttributes)
    cardDataFile << "  " << attribute << ",\n";
  cardDataFile << "};\n\n";
  cardDataFile << "const unsigned char gCardNumStars[] = {\n";
  for (auto & numStars : sNumStars)
    cardDataFile << "  " << numStars << ",\n";
  cardDataFile << "};\n\n";
  cardDataFile << "const enum CardType gCardTypes[] = {\n";
  for (auto & type : sTypes)
    cardDataFile << "  " << type << ",\n";
  cardDataFile << "};\n\n";
  cardDataFile << "const enum CardColor gCardColors[] = {\n";
  for (auto & color : sColors)
    cardDataFile << "  " << color << ",\n";
  cardDataFile << "};\n\n";
  cardDataFile.close();
}

static void GenerateEquipSpellFile () {
  ofstream equipSpellFile;
  equipSpellFile.open("../../src/equip_spell.c");
  if (!equipSpellFile.is_open()) {
    cerr << "Error: unable to open equip_spell.c\n";
    return;
  }
  equipSpellFile.close();
}

static void GenerateCardArtworksFile () {
  ofstream cardArtworksFile;
  cardArtworksFile.open("../../src/card_artworks.c");
  if (!cardArtworksFile.is_open()) {
    cerr << "Error: unable to open card_artworks.c\n";
    return;
  }
  cardArtworksFile << "// DO NOT MODIFY THIS FILE! It is auto-generated from card.json\n";
  for (string & sanitizedName : sSanitizedEnglishNames) {
    cardArtworksFile << "static const unsigned char s";
    //TODO: just output s0, s1 etc... since they're auto generated?
    for (unsigned i = 0; i < sanitizedName.length(); i++)
      if (sanitizedName[i] != '_')
        cardArtworksFile << sanitizedName[i];
    cardArtworksFile << "[] = INCBIN_U8(graphics/cards/";
    for (unsigned i = 0; i < sanitizedName.length(); i++)
      cardArtworksFile << static_cast<unsigned char>(tolower(sanitizedName[i]));
    cardArtworksFile << ".huff);\n";
  }
  cardArtworksFile.close();
}
