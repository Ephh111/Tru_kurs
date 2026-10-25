##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=server
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/home/eph/KURS/server
ProjectPath            :=/home/eph/KURS/server/server
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=eph
Date                   :=25/10/26
CodeLitePath           :=/home/eph/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="server.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lcryptopp -lpthread -lboost_program_options
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/base.cpp$(ObjectSuffix) $(IntermediateDirectory)/logger.cpp$(ObjectSuffix) $(IntermediateDirectory)/calc.cpp$(ObjectSuffix) $(IntermediateDirectory)/communicator.cpp$(ObjectSuffix) $(IntermediateDirectory)/interface.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/base.cpp$(ObjectSuffix): base.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/base.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/base.cpp$(DependSuffix) -MM base.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/eph/KURS/server/server/base.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/base.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/base.cpp$(PreprocessSuffix): base.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/base.cpp$(PreprocessSuffix) base.cpp

$(IntermediateDirectory)/logger.cpp$(ObjectSuffix): logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/logger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/logger.cpp$(DependSuffix) -MM logger.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/eph/KURS/server/server/logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/logger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/logger.cpp$(PreprocessSuffix): logger.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/logger.cpp$(PreprocessSuffix) logger.cpp

$(IntermediateDirectory)/calc.cpp$(ObjectSuffix): calc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/calc.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/calc.cpp$(DependSuffix) -MM calc.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/eph/KURS/server/server/calc.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/calc.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/calc.cpp$(PreprocessSuffix): calc.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/calc.cpp$(PreprocessSuffix) calc.cpp

$(IntermediateDirectory)/communicator.cpp$(ObjectSuffix): communicator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/communicator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/communicator.cpp$(DependSuffix) -MM communicator.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/eph/KURS/server/server/communicator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/communicator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/communicator.cpp$(PreprocessSuffix): communicator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/communicator.cpp$(PreprocessSuffix) communicator.cpp

$(IntermediateDirectory)/interface.cpp$(ObjectSuffix): interface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/interface.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/interface.cpp$(DependSuffix) -MM interface.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/eph/KURS/server/server/interface.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/interface.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/interface.cpp$(PreprocessSuffix): interface.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/interface.cpp$(PreprocessSuffix) interface.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/eph/KURS/server/server/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


