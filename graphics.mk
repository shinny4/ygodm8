CARD_ARTWORK_PNGS := $(wildcard graphics/cards/artwork/*.png)
CARD_ARTWORK_TILES := $(patsubst graphics/cards/artwork/%.png,graphics/cards/artwork/%.8bpp,$(CARD_ARTWORK_PNGS))
CARD_ARTWORK_PALETTES := $(patsubst graphics/cards/artwork/%.png,graphics/cards/artwork/%.gbapal,$(CARD_ARTWORK_PNGS))

CARD_TYPE_PNGS := $(wildcard graphics/cards/types/*.png)
CARD_TYPE_TILES := $(patsubst graphics/cards/types/%.png,graphics/cards/types/%.4bpp,$(CARD_TYPE_PNGS))
CARD_TYPE_PALETTES := $(patsubst graphics/cards/types/%.png,graphics/cards/types/%.gbapal,$(CARD_TYPE_PNGS))

CARD_ATTRIBUTE_PNGS := $(wildcard graphics/cards/attributes/*.png)
CARD_ATTRIBUTE_TILES := $(patsubst graphics/cards/attributes/%.png,graphics/cards/attributes/%.4bpp,$(CARD_ATTRIBUTE_PNGS))
CARD_ATTRIBUTE_PALETTES := $(patsubst graphics/cards/attributes/%.png,graphics/cards/attributes/%.gbapal,$(CARD_ATTRIBUTE_PNGS))

graphics: $(CARD_TYPE_TILES) \
          $(CARD_TYPE_PALETTES) \
          $(CARD_ATTRIBUTE_TILES) \
          $(CARD_ATTRIBUTE_PALETTES) \

%.4bpp: %.png tools
	tools/gbagfx/gbagfx $< $@
%.8bpp: %.png tools
	tools/gbagfx/gbagfx $< $@
%.gbapal: %.png tools
	tools/gbagfx/gbagfx $< $@
