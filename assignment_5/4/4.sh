#!/bin/bash
find . -name *.txt | xargs -I {} cp {} {}.kopi 
