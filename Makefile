BUILD_DIR= build
FINAL_DIR= final

LATEXMK=latexmk -pdf -file-line-error -halt-on-error -outdir=$(FINAL_DIR) 

CONFIG_INPUT=config/config-lst.tex \
	     config/config-tc.tex \
	     config/footline.tex \
	     config/packages.tex \
	     config/config-lab.tex \
	     $(BUILD_DIR)/date.tex

LOGOS=\
logos/arcos.png \
logos/uc3m.png

include guide/Makefile.def
include 01-intro/Makefile.def
include 02-fundcap/Makefile.def
include 03-copymove/Makefile.def
include 04-memmgmt/Makefile.def
include 06-generic/Makefile.def
include 07-stl/Makefile.def
include 08-libs/Makefile.def
include 10-conc/Makefile.def
include 11-sincr/Makefile.def
include 12-atomic/Makefile.def
include lab1-tdu/Makefile.def
include lab2-smartptr/Makefile.def
include lab3-generic/Makefile.def

ALL_PARTS= \
$(GUIDE_PARTS) \
$(INTRO_PARTS) \
$(FUNDCAP_PARTS) \
$(COPYMOVE_PARTS) \
$(MEMMGMT_PARTS) \
$(GENERIC_PARTS) \
$(STL_PARTS) \
$(CONC_PARTS) \
$(SINCR_PARTS) \
$(ATOMIC_PARTS) \
$(LIBS_PARTS) \
$(LAB1_TDU_PARTS) \
$(LAB2_SMARTPTR_PARTS) \
$(LAB3_GENERIC_PARTS) \

ALL_SLIDES_FINAL_PDF= \
$(FINAL_DIR)/$(INTRO_PDF) \
$(FINAL_DIR)/$(FUNDCAP_PDF) \
$(FINAL_DIR)/$(COPYMOVE_PDF) \
$(FINAL_DIR)/$(MEMMGMT_PDF) \
$(FINAL_DIR)/$(GENERIC_PDF) \
$(FINAL_DIR)/$(STL_PDF) \
$(FINAL_DIR)/$(CONC_PDF) \
$(FINAL_DIR)/$(SINCR_PDF) \
$(FINAL_DIR)/$(ATOMIC_PDF) \
$(FINAL_DIR)/$(LIBS_PDF) \
$(FINAL_DIR)/$(LAB1_TDU_PDF) \
$(FINAL_DIR)/$(LAB2_SMARTPTR_PDF) \
$(FINAL_DIR)/$(LAB3_GENERIC_PDF) \

ALL_FINAL_PDF=\
$(FINAL_DIR) \
$(ALL_SLIDES_FINAL_PDF) \
$(GUIDE_FINAL_PDF) \

all:	$(ALL_FINAL_PDF)

clean:
	rm -Rf $(BUILD_DIR)
	rm -Rf $(FINAL_DIR)

build:
	mkdir $(BUILD_DIR)

updatevers:	$(BUILD_DIR)
	git log -1 --format=%ad --date=format:'\date{%d de %B de %Y}' > $(BUILD_DIR)/date.tex

$(FINAL_DIR):
	mkdir $(FINAL_DIR)

include guide/Makefile.mk
include 01-intro/Makefile.mk
include 02-fundcap/Makefile.mk
include 03-copymove/Makefile.mk
include 04-memmgmt/Makefile.mk
include 06-generic/Makefile.mk
include 07-stl/Makefile.mk
include 08-libs/Makefile.mk
include 10-conc/Makefile.mk
include 11-sincr/Makefile.mk
include 12-atomic/Makefile.mk
include lab1-tdu/Makefile.mk
include lab2-smartptr/Makefile.mk
include lab3-generic/Makefile.mk
