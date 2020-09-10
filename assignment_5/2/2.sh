#/bin/bash
find ~/. -atime -7 -size +10k ! -name '*.tar.gz' ! -name '*.zip' | xargs -I {} tar -czvf {}.tar.gz {}
