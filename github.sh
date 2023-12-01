#!/bin/bash

echo "Adding all changes to github...."
git add .

echo "Committing all changes with message...."
git commit -m "changes dumped"

echo "Pushing changes to origin/master of dump..."
git push origin master

echo "Done...happy coding !!!"