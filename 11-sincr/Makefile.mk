$(FINAL_SINCR_PDF): $(SINCR_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(SINCR_OUT) $(SINCR_BASE)/slides.tex
