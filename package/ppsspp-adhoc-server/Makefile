include $(TOPDIR)/rules.mk

PKG_NAME:=AdhocServer
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/Souler/ppsspp-adhoc-server
PKG_SOURCE_DATE:=2021-09-03
PKG_SOURCE_VERSION:=50a8688167f4190d52c03ea061e458cca8213b6e
#PKG_MIRROR_HASH:=0601b4d7aa5ee096e99388a57cb0701673ab58fccd6ed2984a2abbd4f846e045

PKG_LICENSE:=GPLv2
PKG_LICENSE_FILES:=LICENSE

include $(INCLUDE_DIR)/package.mk

define Package/AdhocServer
  SECTION:=net
  CATEGORY:=Network
  TITLE:=PPSSPP Adhoc Server
  URL:=https://github.com/Souler/ppsspp-adhoc-server
  DEPENDS:= +libsqlite3
endef

define Package/AdhocServer/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/AdhocServer $(1)/usr/bin/AdhocServer

	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/AdhocServer-init $(1)/etc/init.d/AdhocServer
endef

$(eval $(call BuildPackage,AdhocServer))
