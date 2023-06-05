cmd_/home/alex/develop/kernel/timer/modules.order := {   echo /home/alex/develop/kernel/timer/t-1.ko; :; } | awk '!x[$$0]++' - > /home/alex/develop/kernel/timer/modules.order
