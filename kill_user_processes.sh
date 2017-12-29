#!/bin/bash
myvariable=$(whoami)
ps aux  | grep '$(whoami)' | awk '{print $0}' > pid.txt
#ps aux  | grep "$(whoami)" | awk '{print $0}' > pid.txt
#ps aux  | grep "$myvariable" | awk '{print $0}' > pid.txt
for pid in $(cat pid.txt); do pkill $pid; done

#startx