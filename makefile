all: brume katabasis rats recits

.PHONY: brume
brume:
	$(MAKE) z8 -C brume

.PHONY: katabasis
katabasis:
	$(MAKE) z8 -C katabasis

.PHONY: rats
rats:
	$(MAKE) z8 -C rats

.PHONY: recits
recits:
	$(MAKE) z8 -C recits

clean:
	find -name "*.z5" -o -name "*.z8" -delete
