cmd_/home/alex/develop/kernel/keyboard/modules.order := {   echo /home/alex/develop/kernel/keyboard/keyboard-1.ko; :; } | awk '!x[$$0]++' - > /home/alex/develop/kernel/keyboard/modules.order
