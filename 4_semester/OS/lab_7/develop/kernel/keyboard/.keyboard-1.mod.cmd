cmd_/home/alex/develop/kernel/keyboard/keyboard-1.mod := printf '%s\n'   keyboard-1.o | awk '!x[$$0]++ { print("/home/alex/develop/kernel/keyboard/"$$0) }' > /home/alex/develop/kernel/keyboard/keyboard-1.mod
