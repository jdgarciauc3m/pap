$(FINAL_CONC_PDF): $(CONC_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(CONC_OUT) $(CONC_BASE)/slides.tex
