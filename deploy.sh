#!/bin/sh

git push origin sources && git subtree push --prefix=public git@github.com:plumbum/plumbum.github.io.git master

