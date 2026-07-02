CARD_ARTWORK_PNGS := $(wildcard graphics/cards/artwork/*.png)
CARD_ARTWORK_TILES := $(patsubst graphics/cards/artwork/%.png,graphics/cards/artwork/%.8bpp,$(CARD_ARTWORK_PNGS))
CARD_ARTWORK_TILES_COMPRESSED := $(patsubst graphics/cards/artwork/%.png,graphics/cards/artwork/%.huff,$(CARD_ARTWORK_PNGS))
CARD_ARTWORK_PALETTES := $(patsubst graphics/cards/artwork/%.png,graphics/cards/artwork/%.gbapal,$(CARD_ARTWORK_PNGS))

CARD_TYPE_PNGS := $(wildcard graphics/cards/types/*.png)
CARD_TYPE_TILES := $(patsubst graphics/cards/types/%.png,graphics/cards/types/%.4bpp,$(CARD_TYPE_PNGS))
CARD_TYPE_PALETTES := $(patsubst graphics/cards/types/%.png,graphics/cards/types/%.gbapal,$(CARD_TYPE_PNGS))

CARD_ATTRIBUTE_PNGS := $(wildcard graphics/cards/attributes/*.png)
CARD_ATTRIBUTE_TILES := $(patsubst graphics/cards/attributes/%.png,graphics/cards/attributes/%.4bpp,$(CARD_ATTRIBUTE_PNGS))
CARD_ATTRIBUTE_PALETTES := $(patsubst graphics/cards/attributes/%.png,graphics/cards/attributes/%.gbapal,$(CARD_ATTRIBUTE_PNGS))

OVERWORLD_ENTITY_PNGS := $(wildcard src/overworld/entities/*.png)
OVERWORLD_ENTITY_TILES := $(patsubst src/overworld/entities/%.png,src/overworld/entities/%.4bpp,$(OVERWORLD_ENTITY_PNGS))

PORTRAIT_PNGS := $(wildcard src/overworld/portraits/*.png)
PORTRAIT_TILES := $(patsubst src/overworld/portraits/%.png,src/overworld/portraits/%.8bpp,$(PORTRAIT_PNGS))
PORTRAIT_TILES_COMPRESSED := $(patsubst src/overworld/portraits/%.png,src/overworld/portraits/%.lz,$(PORTRAIT_PNGS))
PORTRAIT_PALETTES := $(patsubst src/overworld/portraits/%_neutral.png,src/overworld/portraits/%.gbapal,$(PORTRAIT_PNGS))

WORLD_MAP_LOCATION_PNGS := $(wildcard src/world_map/locations/*.png)
WORLD_MAP_LOCATION_TILES := $(patsubst src/world_map/locations/%.png,src/world_map/locations/%.8bpp,$(WORLD_MAP_LOCATION_PNGS))
WORLD_MAP_LOCATION_PALETTES := $(patsubst src/world_map/locations/%.png,src/world_map/locations/%.gbapal,$(WORLD_MAP_LOCATION_PNGS))

graphics-rules: $(CARD_TYPE_TILES) $(CARD_TYPE_PALETTES) \
                $(CARD_ATTRIBUTE_TILES) $(CARD_ATTRIBUTE_PALETTES) \
                $(CARD_ARTWORK_TILES) $(CARD_ARTWORK_TILES_COMPRESSED) $(CARD_ARTWORK_PALETTES) \
                $(OVERWORLD_ENTITY_TILES) src/overworld/entities/palette.gbapal \
                $(PORTRAIT_TILES) $(PORTRAIT_TILES_COMPRESSED) $(PORTRAIT_PALETTES) \
                $(WORLD_MAP_LOCATION_TILES) $(WORLD_MAP_LOCATION_PALETTES) src/world_map/world_map.gbapal

src/overworld/portraits/%.8bpp: src/overworld/portraits/%.png | tools-rules
	tools/gbagfx/gbagfx $< $@ -pal_offset 12

src/overworld/portraits/%.lz: src/overworld/portraits/%.8bpp | tools-rules
	tools/gbagfx/gbagfx $< $@ -search 1

src/overworld/portraits/%.gbapal: src/overworld/portraits/%_neutral.png | tools-rules
	tools/gbagfx/gbagfx $< $@


clean-graphics:
	rm -f graphics/cards/artwork/*.8bpp
	rm -f graphics/cards/artwork/*.huff
	rm -f graphics/cards/artwork/*.gbapal
	rm -f graphics/cards/attributes/*.4bpp
	rm -f graphics/cards/attributes/*.gbapal
	rm -f graphics/cards/types/*.4bpp
	rm -f graphics/cards/types/*.gbapal
	rm -f src/overworld/entities/*.4bpp
	rm -f src/overworld/entities/*.gbapal
	rm -f src/overworld/portraits/*.8bpp
	rm -f src/overworld/portraits/*.lz
	rm -f src/overworld/portraits/*.gbapal
	rm -f src/card_artworks.c
	rm -f src/world_map/world_map.gbapal
	rm -f src/world_map/locations/*.8bpp
	rm -f src/world_map/locations/*.gbapal

%.4bpp: %.png | tools-rules
	tools/gbagfx/gbagfx $< $@
%.8bpp: %.png | tools-rules
	tools/gbagfx/gbagfx $< $@
%.gbapal: %.png | tools-rules
	tools/gbagfx/gbagfx $< $@
graphics/cards/artwork/%.huff: graphics/cards/artwork/%.8bpp
	tools/gbagfx/gbagfx $< $@ -ygodm -depth 8

