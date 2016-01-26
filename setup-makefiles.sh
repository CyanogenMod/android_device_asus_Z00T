#!/bin/sh

set -e

export DEVICE=Z00T
export VENDOR=asus
./../../$VENDOR/msm8916-common/setup-makefiles.sh $@
