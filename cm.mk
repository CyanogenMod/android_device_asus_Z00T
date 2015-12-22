$(call inherit-product, device/asus/Z00T/full_Z00T.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

PRODUCT_RELEASE_NAME := z00t
PRODUCT_NAME := cm_z00t

PRODUCT_GMS_CLIENTID_BASE := android-asus
