#!/bin/sh

cd `dirname $0`
java -cp data:squat.jar jp.towersquest.squat.Main > /dev/null 2>&1
