$(FINAL_COPYMOVE_PDF): $(COPYMOVE_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(COPYMOVE_OUT) $(COPYMOVE_BASE)/slides.tex