$(call inherit-product, device/asus/Z00T/full_Z00T.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

PRODUCT_RELEASE_NAME := Z00T
PRODUCT_NAME := cm_Z00T

PRODUCT_GMS_CLIENTID_BASE := android-asus
