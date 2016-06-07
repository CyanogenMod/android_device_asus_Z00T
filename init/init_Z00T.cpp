/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#define ISMATCH(a,b)    (!strncmp(a,b,PROP_VALUE_MAX))

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char PRJ_ID[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    FILE *fp = fopen("/proc/apid" , "r");
    fgets(PRJ_ID, sizeof(PRJ_ID), fp);
    pclose(fp);

    /* Common properties */
    property_set("ro.build.product", "Z00T");
    property_set("ro.build.description", "Z00T-user 6.0.1 MMB29P WW_user_21.40.1220.1615_20160517 release-keys");

    if (ISMATCH(PRJ_ID, "0\n")) {
        /* ZE551KL */
        property_set("ro.product.model", "ASUS_Z00TD");
        property_set("ro.product.device", "ASUS_Z00T");
        property_set("ro.product.carrier", "US-ASUS_Z00T-WW_Z00T");
        property_set("ro.build.fingerprint", "asus/WW_Z00T/ASUS_Z00T:6.0.1/MMB29P/WW_user_21.40.1220.1615_20160517:user/release-keys");
    } else if (ISMATCH(PRJ_ID, "1\n")) {
        /* ZE601KL */
        property_set("ro.product.model", "ASUS_Z011D");
        property_set("ro.product.device", "ASUS_Z011");
        property_set("ro.product.carrier", "US-ASUS_Z011-WW_Z011");
        property_set("ro.build.fingerprint", "asus/WW_Z011/ASUS_Z011:6.0.1/MMB29P/WW_user_21.40.1220.1615_20160517:user/release-keys");
    } else if (ISMATCH(PRJ_ID, "2\n")) {
        /* ZX550KL */
        property_set("ro.product.model", "ASUS_Z00CD");
        property_set("ro.product.device", "ASUS_Z00C");
        property_set("ro.product.carrier", "US-ASUS_Z00C-WW_Z00C");
        property_set("ro.build.fingerprint", "asus/WW_Z00C/ASUS_Z00C:6.0.1/MMB29P/WW_user_21.40.1220.1615_20160517:user/release-keys");
    } else if (ISMATCH(PRJ_ID, "3\n")) {
        /* ZD551KL */
        property_set("ro.product.model", "ASUS_Z00UD");
        property_set("ro.product.device", "ASUS_Z00U");
        property_set("ro.product.carrier", "US-ASUS_Z00U-WW_Z00U");
        property_set("ro.build.fingerprint", "asus/WW_Z00U/ASUS_Z00U_1:6.0.1/MMB29P/WW_user_21.40.1220.1615_20160517:user/release-keys");
    }

    property_get("ro.product.device", device);
    INFO("Found project id: %s setting build properties for %s device\n", PRJ_ID, device);
}
