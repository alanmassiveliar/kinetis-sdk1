USBD_CLASS_PHDC_DIR := $(USBD_CLASS_ROOT)/phdc

SOURCES += $(wildcard $(USBD_CLASS_PHDC_DIR)/*.c)
INCLUDES += $(USBD_CLASS_PHDC_DIR)