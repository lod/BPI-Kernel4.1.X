/*
 * (C) Copyright 2013 Oliver Schinagl <oliver@schinagl.nl>
 *
 * X-Powers AXP221 Power Management IC driver
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

/* Page 0 addresses */
#define AXP221_CHIP_ID		0x03
#define AXP221_OUTPUT_CTRL1	0x10
#define AXP221_OUTPUT_CTRL1_DCDC0_EN	(1 << 0)
#define AXP221_OUTPUT_CTRL1_DCDC1_EN	(1 << 1)
#define AXP221_OUTPUT_CTRL1_DCDC2_EN	(1 << 2)
#define AXP221_OUTPUT_CTRL1_DCDC3_EN	(1 << 3)
#define AXP221_OUTPUT_CTRL1_DCDC4_EN	(1 << 4)
#define AXP221_OUTPUT_CTRL1_DCDC5_EN	(1 << 5)
#define AXP221_OUTPUT_CTRL1_ALDO1_EN	(1 << 6)
#define AXP221_OUTPUT_CTRL1_ALDO2_EN	(1 << 7)
#define AXP221_OUTPUT_CTRL2	0x12
#define AXP221_OUTPUT_CTRL2_ELDO1_EN	(1 << 0)
#define AXP221_OUTPUT_CTRL2_ELDO2_EN	(1 << 1)
#define AXP221_OUTPUT_CTRL2_ELDO3_EN	(1 << 2)
#define AXP221_OUTPUT_CTRL2_DLDO1_EN	(1 << 3)
#define AXP221_OUTPUT_CTRL2_DLDO2_EN	(1 << 4)
#define AXP221_OUTPUT_CTRL2_DLDO3_EN	(1 << 5)
#define AXP221_OUTPUT_CTRL2_DLDO4_EN	(1 << 6)
#define AXP221_OUTPUT_CTRL2_DCDC1SW_EN	(1 << 7)
#define AXP221_OUTPUT_CTRL3	0x13
#define AXP221_OUTPUT_CTRL3_ALDO3_EN	(1 << 7)
#define AXP221_DLDO1_CTRL	0x15
#define AXP221_DLDO2_CTRL	0x16
#define AXP221_DLDO3_CTRL	0x17
#define AXP221_DLDO4_CTRL	0x18
#define AXP221_ELDO1_CTRL	0x19
#define AXP221_ELDO2_CTRL	0x1a
#define AXP221_ELDO3_CTRL	0x1b
#define AXP221_DCDC1_CTRL	0x21
#define AXP221_DCDC2_CTRL	0x22
#define AXP221_DCDC3_CTRL	0x23
#define AXP221_DCDC4_CTRL	0x24
#define AXP221_DCDC5_CTRL	0x25
#define AXP221_ALDO1_CTRL	0x28
#define AXP221_ALDO2_CTRL	0x29
#define AXP221_ALDO3_CTRL	0x2a
#define AXP221_VBUS_IPSOUT	0x30
#define AXP221_VBUS_IPSOUT_DRIVEBUS	(1 << 2)
#define AXP221_MISC_CTRL	0x8f
#define AXP221_MISC_CTRL_N_VBUSEN_FUNC	(1 << 4)
#ifdef BPI
#else
#define AXP221_GPIO0_CTRL	0x90
#define AXP221_GPIO0_LDO	0x91
#define AXP221_GPIO1_CTRL	0x92
#define AXP221_GPIO1_LDO	0x93
#endif
#define AXP221_PAGE		0xff

/* Page 1 addresses */
#define AXP221_SID		0x20

/* For axp_gpio.c */
#define AXP_POWER_STATUS		0x00
#define AXP_POWER_STATUS_VBUS_PRESENT		(1 << 5)
#define AXP_GPIO0_CTRL			0x90
#define AXP_GPIO1_CTRL			0x92
#define AXP_GPIO_CTRL_OUTPUT_LOW		0x00 /* Drive pin low */
#define AXP_GPIO_CTRL_OUTPUT_HIGH		0x01 /* Drive pin high */
#define AXP_GPIO_CTRL_INPUT			0x02 /* Input */
#define AXP_GPIO_STATE			0x94
#define AXP_GPIO_STATE_OFFSET			0

int axp221_set_dcdc1(unsigned int mvolt);
int axp221_set_dcdc2(unsigned int mvolt);
int axp221_set_dcdc3(unsigned int mvolt);
int axp221_set_dcdc4(unsigned int mvolt);
int axp221_set_dcdc5(unsigned int mvolt);
int axp221_set_dldo1(unsigned int mvolt);
int axp221_set_dldo2(unsigned int mvolt);
int axp221_set_dldo3(unsigned int mvolt);
int axp221_set_dldo4(unsigned int mvolt);
int axp221_set_aldo1(unsigned int mvolt);
int axp221_set_aldo2(unsigned int mvolt);
int axp221_set_aldo3(unsigned int mvolt);
int axp221_set_eldo(int eldo_num, unsigned int mvolt);
#ifdef BPI
#else
int axp221_set_gldo(int gldo_num, unsigned int mvolt);
#endif
int axp221_init(void);
int axp221_get_sid(unsigned int *sid);
