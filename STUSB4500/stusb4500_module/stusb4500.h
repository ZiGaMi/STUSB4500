//////////////////////////////////////////////////////////////
// 
//	project:		STUSB4500 EVALUATION
//	date:			05.09.2020
//	
//	author:			Ziga Miklosic
//
//////////////////////////////////////////////////////////////

#ifndef _STUSB4500_H_
#define _STUSB4500_H_

//////////////////////////////////////////////////////////////
//	INCLUDES
//////////////////////////////////////////////////////////////
#include "stdint.h"
#include "stdbool.h"

// For float
#include "project_config.h"

//////////////////////////////////////////////////////////////
//	DEFINITIONS
//////////////////////////////////////////////////////////////

// Status
typedef enum
{
	eSTUSB4500_OK 		= 0x00,
	eSTUSB4500_ERROR 	= 0x01,
} stusb4500_status_t;

// PDO number
typedef enum
{
	eSTUSB4500_PDO_1 = 0,
	eSTUSB4500_PDO_2,
	eSTUSB4500_PDO_3,

	eSTUSB4500_PDO_NUM_OF,
} stusb4500_pdo_num_t;

// Role swap
typedef enum
{
	eSTUSB4500_ROLE_SWAP_NOT_SUPPORTED = 0,
	eSTUSB4500_ROLE_SWAP_DEFAULT_USB_POWER,
	eSTUSB4500_ROLE_SWAP_1_5A_5V,
	eSTUSB4500_ROLE_SWAP_3_5A_5V,
} stusb4500_role_swap_t;

// PDO type
typedef enum
{
	eSTUSB4500_PDO_TYPE_FIXED_SUPPLY = 0,
	eSTUSB4500_PDO_TYPE_BATTERY,
	eSTUSB4500_PDO_TYPE_VARIABLE_SUPPLY,
	eSTUSB4500_PDO_TYPE_RESERVED,
} stusb4500_pdo_type_t;

// PDO flags
typedef struct
{
	uint8_t dual_role_data 		: 1;
	uint8_t USB_com_enable		: 1;
	uint8_t unconstrained_power : 1;
	uint8_t high_capability		: 1;
	uint8_t dual_role_power		: 1;
	uint8_t reserved			: 3;
} stusb4500_pdo_flags_t;

// Fixed supply PDO (Power Delivery Object)
typedef struct
{
	float32_t 					current;
	float32_t 					voltage;
	stusb4500_role_swap_t		fast_role_swap;
	stusb4500_pdo_flags_t		flags;
	const stusb4500_pdo_type_t	type;		// Always fixed supply
	stusb4500_pdo_num_t 		num;
} stusb4500_pdo_t;

// Attached mode
typedef enum
{
	eSTUSB4500_RDO_MODE_USB_C = 0,
	eSTUSB4500_RDO_MODE_USB_PD
} stusb4500_rdo_mode_t;

// RDO (Requested Delivery Object)
typedef struct
{
	struct
	{
		float32_t maximum;
		float32_t operating;
	} current;

	stusb4500_rdo_mode_t 	mode;
	uint8_t 				src_pdo;
} stusb4500_rdo_t;

// Device attached
typedef enum
{
	eSTUSB4500_NOT_ATTACHED = 0,
	eSTUSB4500_ATTACHED,
} stusb4500_attach_t;

// CC status
typedef enum
{
	eSTUSB4500_CC_STAT_RESERVED = 0,
	eSTUSB4500_CC_STAT_DEFAULT,
	eSTUSB4500_CC_STAT_PWR_1_5,
	eSTUSB4500_CC_STAT_PWR_3_0,
} stusb4500_cc_stat_t;

// Status
typedef struct
{
	stusb4500_rdo_t 	RDO;
	stusb4500_attach_t	attached;
	stusb4500_cc_stat_t CC1;
	stusb4500_cc_stat_t CC2;
} stusb4500_usb_status_t;


//////////////////////////////////////////////////////////////
//	VARIABLES
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// FUNCTIONS PROTOTYPES
//////////////////////////////////////////////////////////////
stusb4500_status_t 				stusb4500_init			(void);
stusb4500_status_t				stusb4500_hndl			(void);
const stusb4500_usb_status_t * 	stusb4500_get_status	(void);


//////////////////////////////////////////////////////////////
// END OF FILE
//////////////////////////////////////////////////////////////

#endif // _STUSB4500_H_
