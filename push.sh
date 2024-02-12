#/usr/bin/bash

git add .
# add the clock time of the commit to the message string
# the date format is %Y-%m-%d %H:%M:%S
git commit -m "chore: update $(date)"
git push
