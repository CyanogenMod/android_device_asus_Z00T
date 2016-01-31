$(call inherit-product, device/asus/Z00T/full_Z00T.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

PRODUCT_NAME := cm_Z00T
PRODUCT_BRAND := asus
PRODUCT_MANUFACTURER := asus
PRODUCT_DEVICE := Z00T

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRODUCT_NAME=WW_Z00T \
    BUILD_FINGERPRINT="asus/WW_Z00T/ASUS_Z00T:5.0.2/LRX22G/WW_user_1.16.40.763_20151201:user/release-keys" \
    PRIVATE_BUILD_DESC="Z00T-user 5.0.2 LRX22G WW_user_1.16.40.763_20151201 release-keys"

PRODUCT_GMS_CLIENTID_BASE := android-asus
