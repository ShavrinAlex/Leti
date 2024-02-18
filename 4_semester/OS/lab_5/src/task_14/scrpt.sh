#!/bin/bash
client_amount=$1
for (( counter=0; counter<client_amount; counter++ ))
do
	echo `gnome-terminal -- sh -c "bash -c \"./client client_$counter; exec bash\""`
done
