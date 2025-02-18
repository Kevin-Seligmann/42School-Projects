#!bin/sh
find -E . -regex '.*\.sh' | rev | cut -d'/' -f 1 | rev | cut -d'.' -f 1
