//////////////////////////////////////////////////////////////
// 
//	project:		STUSB4500 EVALUATION
//	date:			05.09.2020
//	
//	author:			Ziga Miklosic
//
//////////////////////////////////////////////////////////////

#ifndef _STUSB4500_LOW_IF_H_
#define _STUSB4500_LOW_IF_H_

//////////////////////////////////////////////////////////////
//	INCLUDES
//////////////////////////////////////////////////////////////
#include "stdint.h"
#include "stdbool.h"

#include "stusb4500.h"
#include "stusb4500_regdef.h"

//////////////////////////////////////////////////////////////
//	DEFINITIONS
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
//	VARIABLES
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// FUNCTIONS PROTOTYPES
//////////////////////////////////////////////////////////////
stusb4500_status_t stusb4500_low_if_init			(void);
stusb4500_status_t stusb4500_low_if_write_register	(const stusb4500_addr_t addr, const uint8_t * p_tx_data, const uint32_t size);
stusb4500_status_t stusb4500_low_if_read_register	(const stusb4500_addr_t addr, uint8_t * p_rx_data, const uint32_t size);


//////////////////////////////////////////////////////////////
// END OF FILE
//////////////////////////////////////////////////////////////

#endif // _STUSB4500_LOW_IF_H_
