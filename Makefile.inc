APPL_CXXOBJS += Walker.o LineMonitor.o LineTracer.o Starter.o LineTracerWithStarter.o
SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
# COPTS += -DMAKE_BT_DISABLE
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile
INCLUDES += -I$(ETROBO_HRP3_WORKSPACE)/etroboc_common

endif