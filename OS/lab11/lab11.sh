#!/bin/bash

if [ `who | grep -i "$1" | wc -l` -gt 0 ]; then
	exit 0
else
	exit -1
fi

