$(FINAL_LIBS_PDF): $(LIBS_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -shell-escape -jobname=$(LIBS_OUT) $(LIBS_BASE)/slides.tex
