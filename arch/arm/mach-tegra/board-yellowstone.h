/*
 * arch/arm/mach-tegra/board-ardbeg.h
 *
 * Copyright (c) 2014, NVIDIA Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _MACH_TEGRA_BOARD_ARDBEG_H
#define _MACH_TEGRA_BOARD_ARDBEG_H

#include <mach/gpio-tegra.h>
#include <mach/irqs.h>
#include "gpio-names.h"

int ardbeg_emc_init(void);
int ardbeg_display_init(void);
int ardbeg_panel_init(void);
int ardbeg_sdhci_init(void);
void arbdeg_sata_clk_gate(void);
int ardbeg_sensors_init(void);
int ardbeg_regulator_init(void);
int ardbeg_suspend_init(void);
int ardbeg_pmon_init(void);
int ardbeg_rail_alignment_init(void);
int ardbeg_soctherm_init(void);
int ardbeg_edp_init(void);
void shield_new_sysedp_init(void);
void shield_sysedp_dynamic_capping_init(void);
void shield_sysedp_batmon_init(void);

/* generated soc_therm OC interrupts */
#define TEGRA_SOC_OC_IRQ_BASE	TEGRA_NR_IRQS
#define TEGRA_SOC_OC_NUM_IRQ	TEGRA_SOC_OC_IRQ_MAX

#define PALMAS_TEGRA_GPIO_BASE	TEGRA_NR_GPIOS
#define PALMAS_TEGRA_IRQ_BASE	(TEGRA_SOC_OC_IRQ_BASE + TEGRA_SOC_OC_NUM_IRQ)

#define CAM_RSTN TEGRA_GPIO_PBB3
#define CAM1_RSTN TEGRA_GPIO_PCC1
#define CAM2_RSTN TEGRA_GPIO_PCC2
#define CAM_FLASH_STROBE TEGRA_GPIO_PBB4
#define CAM2_PWDN TEGRA_GPIO_PBB6
#define CAM1_PWDN TEGRA_GPIO_PBB5
#define CAM_AF_PWDN TEGRA_GPIO_PBB7
#define CAM_BOARD_E1806

#ifndef CCI_IO
#define FCAM_PWDN TEGRA_GPIO_PBB4
#endif

/* Modem related GPIOs */
#define MODEM_EN		TEGRA_GPIO_PS4
#define MDM_RST			TEGRA_GPIO_PS3
#define MDM_COLDBOOT		TEGRA_GPIO_PO5
#define MDM_SAR0		TEGRA_GPIO_PG2

/* Baseband IDs */
enum tegra_bb_type {
	TEGRA_BB_BRUCE = 1,
	TEGRA_BB_HSIC_HUB = 6,
};

#define UTMI1_PORT_OWNER_XUSB   0x1
#define UTMI2_PORT_OWNER_XUSB   0x2
#define HSIC1_PORT_OWNER_XUSB   0x4
#define HSIC2_PORT_OWNER_XUSB   0x8

/* Touchscreen definitions */
#define TOUCH_GPIO_IRQ_RAYDIUM_SPI	TEGRA_GPIO_PK2 //TEGRA_GPIO_PK2 for nfc I2C_REQ DVT1-2 TEST
#define TOUCH_GPIO_RST_RAYDIUM_SPI	TEGRA_GPIO_PK4
#define TOUCH_SPI_ID			0	/*SPI 1 on ardbeg_interposer*/
#define TOUCH_SPI_CS			0	/*CS  0 on ardbeg_interposer*/
#define NORRIN_TOUCH_SPI_ID			2	/*SPI 2 on Norrin*/
#define NORRIN_TOUCH_SPI_CS			1	/*CS  1 on Norrin*/

#define TOUCH_GPIO_SDN_MAXIM_STI_SPI	TEGRA_GPIO_PK1
#define TOUCH_GPIO_IRQ_MAXIM_STI_SPI	TEGRA_GPIO_PK2 //TEGRA_GPIO_PK2 for nfc I2C_REQ DVT1-2 TEST
#define TOUCH_GPIO_RST_MAXIM_STI_SPI	TEGRA_GPIO_PK4

/* Audio-related GPIOs */
/*Same GPIO's used for T114(Interposer) and T124*/
/*Below GPIO's are same for Laguna and Ardbeg*/
#define TEGRA_GPIO_CDC_IRQ	TEGRA_GPIO_PH4
// #define TEGRA_GPIO_HP_DET		TEGRA_GPIO_PR7
#define TEGRA_GPIO_HP_DET		TEGRA_GPIO_PH4

/*LDO_EN signal is required only for RT5639 and not for RT5645,
on Laguna the LDO_EN signal comes from a GPIO expander and
this is exposed as a fixed regulator directly handeled from
machine driver of rt5639 and for ardebeg we use the below tegra
GPIO, also the GPIO is same for T114 interposer and T124*/
#define TEGRA_GPIO_LDO_EN	TEGRA_GPIO_PR2

/*GPIOs used by board panel file */
#define DSI_PANEL_RST_GPIO      TEGRA_GPIO_PH3
#define DSI_PANEL_BL_PWM_GPIO   TEGRA_GPIO_PH1

/* HDMI Hotplug detection pin */
#define ardbeg_hdmi_hpd	TEGRA_GPIO_PN7

/* I2C related GPIOs */
/* Same for interposer and t124 */
#define TEGRA_GPIO_I2C1_SCL	TEGRA_GPIO_PC4
#define TEGRA_GPIO_I2C1_SDA	TEGRA_GPIO_PC5
#define TEGRA_GPIO_I2C2_SCL	TEGRA_GPIO_PT5
#define TEGRA_GPIO_I2C2_SDA	TEGRA_GPIO_PT6
#define TEGRA_GPIO_I2C3_SCL	TEGRA_GPIO_PBB1
#define TEGRA_GPIO_I2C3_SDA	TEGRA_GPIO_PBB2
#define TEGRA_GPIO_I2C4_SCL	TEGRA_GPIO_PV4
#define TEGRA_GPIO_I2C4_SDA	TEGRA_GPIO_PV5
#define TEGRA_GPIO_I2C5_SCL	TEGRA_GPIO_PZ6
#define TEGRA_GPIO_I2C5_SDA	TEGRA_GPIO_PZ7

/* YellowStone specific */
int yellowstone_regulator_init(void);
int yellowstone_fixed_regulator_init(void);
int yellowstone_edp_init(void);
void yellowstone_new_sysedp_init(void);
void yellowstone_sysedp_dynamic_capping_init(void);

int yellowstone_p1761_pmon_init(void);

/* SATA Specific */

#define CLK_RST_CNTRL_RST_DEV_W_SET 0x7000E438
#define CLK_RST_CNTRL_RST_DEV_V_SET 0x7000E430
#define SET_CEC_RST 0x100

#endif
