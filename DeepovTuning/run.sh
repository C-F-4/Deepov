#!/bin/bash

#********************************************************************
# Set evaluation variables

ROUND=100
ENGINE="Deepov"
OPPONENT="Deepov"

# Set options

#********************************************************************
# Tune time divider test
./tuner.py ./Deepov ./Deepov -d ../ -r 14 -v \
		-n timeDivider --bounds 1 100 10 1
		#-n timeDivider --bounds 1,100,5,1
#********************************************************************
#********************************************************************
#********************************************************************
#********************************************************************
#********************************************************************
#********************************************************************
#********************************************************************