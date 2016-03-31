/**
 * @file
 * @copyright  Copyright 2016 GNSS Sensor Ltd. All right reserved.
 * @author     Sergey Khabarov - sergeykhbr@gmail.com
 * @brief      Plugin library initialization method.
 */

#include "cpurtl.h"

namespace debugger {

extern "C" void plugin_init(void) {
    REGISTER_CLASS(CpuRiscV_RTL);
}

}  // namespace debugger
