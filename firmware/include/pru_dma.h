#ifndef PRU_DMA_H
#define PRU_DMA_H

#include <stdint.h>
#include <pru_rpmsg.h>
#include <pru_types.h>

#define EVT_FROM_EDMA 			63
#define EVT_TO_ARM_HOST			18
#define EVT_FROM_ARM_HOST		19

#define HOST0_INT			((uint32_t) 1 << 30)
#define HOST1_INT			((uint32_t) 1 << 31)

struct pru_dma_data {
	uint32_t src;
	uint32_t dst;
	uint32_t size;
};

enum pru_dma_direction {
	PRU_DMA_DIR_ARM_TO_PRU,
	PRU_DMA_DIR_PRU_TO_ARM,
};

void pru_dma_init(struct pru_dma_data *dma_data,
			enum pru_dma_direction dir,
			struct fw_rsc_vdev *rpmsg_vdev,
			struct fw_rsc_vdev_vring *rpmsg_vring0,
			struct fw_rsc_vdev_vring *rpmsg_vring1,
			struct fw_rsc_custom_dma_ch *pru_dmas,
			int chan_num);
void pru_dma_wait_host();
void pru_dma_trigger();
void pru_dma_wait();

#endif /* PRU_DMA_H */
