APPL_CXXOBJS += Color.o Run.o LinetraceRun.o NoLinetraceRun.o Scenario.o LinetraceScenario.o PID.o RunningDistance.o Tripmeter.o UserInterface.o
SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile
INCLUDES += -I$(ETROBO_HRP3_WORKSPACE)/etroboc_common

endif
