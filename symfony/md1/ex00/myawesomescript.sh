#/bin/sh

curl -s $1 2>/dev/null | grep href= | cut -d '"' -f2 
