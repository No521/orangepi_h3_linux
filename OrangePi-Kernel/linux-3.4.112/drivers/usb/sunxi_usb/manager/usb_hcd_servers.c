/*
 * drivers/usb/sunxi_usb/manager/usb_hcd_servers.c
 * (C) Copyright 2010-2015
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * javen, 2011-4-14, create this file
 *
 * usb host contoller driver, service function set.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 */

#include  "../include/sunxi_usb_config.h"
#include  "usb_hcd_servers.h"

#if defined (CONFIG_ARCH_SUN8IW8) || defined (CONFIG_ARCH_SUN8IW7)
#define HCI0_USBC_NO    0
#define HCI1_USBC_NO    1
#define HCI2_USBC_NO    2
#define HCI3_USBC_NO    3
#else
#define HCI0_USBC_NO    1
#define HCI1_USBC_NO    2
#define HCI2_USBC_NO    3
#define HCI3_USBC_NO    4
#endif

int sunxi_usb_disable_ehci(__u32 usbc_no);
int sunxi_usb_enable_ehci(__u32 usbc_no);
int sunxi_usb_disable_ohci(__u32 usbc_no);
int sunxi_usb_enable_ohci(__u32 usbc_no);

int sunxi_usb_disable_hcd(__u32 usbc_no)
{
#ifndef  SUNXI_USB_FPGA
	if (usbc_no == 0) {
#if !defined (CONFIG_ARCH_SUN9IW1) && !defined (CONFIG_ARCH_SUN8IW8) && !defined (CONFIG_ARCH_SUN8IW7)
		#if defined(CONFIG_USB_SUNXI_USB0_OTG) || defined(USB_SUNXI_USB0_HOST_ONLY)
			sunxi_usb_disable_hcd0();
		#endif
#else
#if defined (CONFIG_ARCH_SUN8IW8) || defined (CONFIG_ARCH_SUN8IW7)
		#if defined(CONFIG_USB_SUNXI_EHCI0)
			sunxi_usb_disable_ehci(usbc_no);
		#endif

		#if defined(CONFIG_USB_SUNXI_OHCI0)
			sunxi_usb_disable_ohci(usbc_no);
		#endif
#endif
#endif
	} else if (usbc_no == HCI0_USBC_NO) {
		#if defined(CONFIG_USB_SUNXI_EHCI0)
			sunxi_usb_disable_ehci(usbc_no);
		#endif

		#if defined(CONFIG_USB_SUNXI_OHCI0)
			sunxi_usb_disable_ohci(usbc_no);
		#endif
	} else if (usbc_no == HCI1_USBC_NO) {
		#if defined(CONFIG_USB_SUNXI_EHCI1)
			sunxi_usb_disable_ehci(usbc_no);
		#endif

		#if defined(CONFIG_USB_SUNXI_OHCI1)
			sunxi_usb_disable_ohci(usbc_no);
		#endif
	}else if (usbc_no == HCI2_USBC_NO) {
		#if defined(CONFIG_USB_SUNXI_EHCI2)
			sunxi_usb_disable_ehci(usbc_no);
		#endif

		#if defined(CONFIG_USB_SUNXI_OHCI2)
			sunxi_usb_disable_ohci(usbc_no);
		#endif
	}else if (usbc_no == HCI3_USBC_NO) {
		#if defined(CONFIG_USB_SUNXI_EHCI3)
			sunxi_usb_disable_ehci(usbc_no);
		#endif

		#if defined(CONFIG_USB_SUNXI_OHCI3)
			sunxi_usb_disable_ohci(usbc_no);
		#endif
	} else {
		DMSG_PANIC("ERR: unkown usbc_no(%d)\n", usbc_no);
		return -1;
	}
#endif
	return 0;
}
EXPORT_SYMBOL(sunxi_usb_disable_hcd);

int sunxi_usb_enable_hcd(__u32 usbc_no)
{
#ifndef  SUNXI_USB_FPGA
	if (usbc_no == 0) {
#if !defined (CONFIG_ARCH_SUN9IW1) && !defined (CONFIG_ARCH_SUN8IW8) && !defined (CONFIG_ARCH_SUN8IW7)
		#if defined(CONFIG_USB_SUNXI_USB0_OTG) || defined(USB_SUNXI_USB0_HOST_ONLY)
			sunxi_usb_enable_hcd0();
		#endif
#else
#if defined (CONFIG_ARCH_SUN8IW8) || defined (CONFIG_ARCH_SUN8IW7)
		#if defined(CONFIG_USB_SUNXI_EHCI0)
			sunxi_usb_enable_ehci(usbc_no);
		#endif

		#if defined(CONFIG_USB_SUNXI_OHCI0)
			sunxi_usb_enable_ehci(usbc_no);
		#endif
#endif
#endif
	} else if (usbc_no == HCI0_USBC_NO) {
		#if defined(CONFIG_USB_SUNXI_EHCI0)
			sunxi_usb_enable_ehci(usbc_no);
		#endif

		#if defined(CONFIG_USB_SUNXI_OHCI0)
			sunxi_usb_enable_ohci(usbc_no);
		#endif
	} else if (usbc_no == HCI1_USBC_NO) {
		#if defined(CONFIG_USB_SUNXI_EHCI1)
			sunxi_usb_enable_ehci(usbc_no);
		#endif

		#if defined(CONFIG_USB_SUNXI_OHCI1)
			sunxi_usb_enable_ohci(usbc_no);
		#endif
	}else if (usbc_no == HCI2_USBC_NO) {
		#if defined(CONFIG_USB_SUNXI_EHCI2)
			sunxi_usb_enable_ehci(usbc_no);
		#endif

		#if defined(CONFIG_USB_SUNXI_OHCI2)
			sunxi_usb_enable_ohci(usbc_no);
		#endif
	}else if (usbc_no == HCI3_USBC_NO) {
		#if defined(CONFIG_USB_SUNXI_EHCI3)
			sunxi_usb_enable_ehci(usbc_no);
		#endif

		#if defined(CONFIG_USB_SUNXI_OHCI3)
			sunxi_usb_enable_ohci(usbc_no);
		#endif
	} else {
		DMSG_PANIC("ERR: unkown usbc_no(%d)\n", usbc_no);
		return -1;
	}
#endif
	return 0;
}
EXPORT_SYMBOL(sunxi_usb_enable_hcd);
