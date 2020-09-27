#!/bin/bash
LRED="\033[1;31m"
RED="\033[0;31m"
YELLOW="\033[1;33m"
CYAN="\033[0;36m"
NC="\033[0m"
SPF_REGEX="(?:include:)([\w\.\-]+)"

recursive_spf_lookup() {
	for address in $1;
	do

		printf "Looking up $RED$address$NC\n"
		spf=`nslookup -type=txt $address | grep -oP "v=spf1 .+"` 		

		# Prints out IP adresses found
		for addr in $spf;
		do
			if [[ $addr != *"ip"* ]]; then	
				continue
			fi
			printf "$YELLOW$addr$NC\n"
		done

		# Checks for more includes, and searches look them up
		spf_address=`echo $spf | grep -oP -e $SPF_REGEX | cut -c 9-`
		recursive_spf_lookup "$spf_address" | sed 's/^/  /'
	done
}

# MX
echo "Checking mail exchanger for $1"
dig=`dig mx $1 +short | cut -c 3-`

for address in $dig;
do
	host=`host $address`
	echo -e "$LRED$host$NC\n" | sed 's/^/  /'
done

#SPF
spf=`nslookup -type=txt $1`
spf_log=$spf

if [[ $spf_log == *"v=spf1"* ]]; then
	echo "$1 bruker SPF"
	spf_address=`echo $spf_log | grep -o -P -e "$SPF_REGEX" | cut -c 9-`
	# echo "$spf_address"

	recursive_spf_lookup "$spf_address" | sed 's/^/  /'
else
	echo "$1 bruker ikke SPF"
fi

