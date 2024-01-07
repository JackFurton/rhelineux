#!/usr/bin/env bash

set -euo pipefail
IFS=$'\n\t'

string="bissantwigga"

echo "I am in $(pwd)"

function get_name() {
    echo "zogit"
}

echo "You are $(get_name)"

if [[ -z "$string" ]]; then
    echo "the string was empty!"
elif [[ -n "$string" ]]; then
    echo "the string is not empty!"
fi

for i in {1..5}; do
    echo "Welcome $i"
done

for i in /etc/rc.*; do
    echo "$i"
done

for ((i = 0 ; i < 50 ; i++)) do
    echo "$i"
done

while read -r line; do
    echo "$line"
done <file.txt

declare -A sounds

sounds[dog]="bark"
sounds[cow]="moo"
sounds[bird]="tweet"
sounds[wolf]="howl"

echo "${sounds[dog]}"
echo "${sounds[@]}"
echo "${!sounds[@]}"
echo "${#sounds[@]}"

for val in "${sounds[@]}"; do
    echo "$val"
done

for key in "${!sounds[@]}"; do
    echo "$key"
done
