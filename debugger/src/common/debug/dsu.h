/**
 *  Copyright 2018 Sergey Khabarov, sergeykhbr@gmail.com
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * @details    DSU supports both types of transaction: blocking and
 *             non-blocking it allows to interact with SystemC in the
 *             same manner as with the Functional model.
 * @note       CPU Functional model must implement non-blocking interface
 */

#ifndef __DEBUGGER_COMMON_DEBUG_DSU_H__
#define __DEBUGGER_COMMON_DEBUG_DSU_H__

#include <iclass.h>
#include <iservice.h>
#include "coreservices/imemop.h"
#include "coreservices/ireset.h"
#include "coreservices/icpugen.h"
#include "coreservices/idsugen.h"
#include "coreservices/iwire.h"
#include "dsu_regs.h"

namespace debugger {

class DSU : public RegMemBankGeneric,
            public DsuRegisters,
            public IDsuGeneric {
 public:
    explicit DSU(const char *name);
    virtual ~DSU();

    /** IService interface */
    virtual void postinitService() override;

    /** IDsuGeneric */
    virtual void incrementRdAccess(int mst_id);
    virtual void incrementWrAccess(int mst_id);
    void raiseMissaccess(uint64_t adr);
    void softReset(bool val);
    void setCpuContext(unsigned n);

 private:
    AttributeType cpu_;
    AttributeType irqctrl_;
    AttributeType icpulist_;

    ICpuGeneric *icpu_context_;     // current cpu context
    IWire *iirq_;
};

DECLARE_CLASS(DSU)

}  // namespace debugger

#endif  // __DEBUGGER_COMMON_DEBUG_DSU_H__
