#!bin/sh
end=$(($FT_LINE2))
start=$(($FT_LINE2 - $FT_LINE1 + 1))
cat /etc/passwd | sed -e 's/#.*$//' -e '/^ *$/d' | cut -d':' -f 1 | awk 'NR % 2 == 0' | rev | sort -r \
| head -n $end | tail -n $start | tr "\n" ", " | sed -E 's/,$/./'
