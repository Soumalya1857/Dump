#!/bin/bash

echo -e "********** Adding all changes to github **********\n"
git add .

echo -e "\n********** Committing all changes with message **********\n"
git commit -m "changes dumped"

echo -e "\n********** Pushing changes to origin/master of dump **********\n"
git push origin master

echo -e "\n********** Done...happy coding !!! **********"