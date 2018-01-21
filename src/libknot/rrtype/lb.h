#pragma once

#include "libknot/rdataset.h"
#include "contrib/wire.h"

static inline
const knot_dname_t *knot_lb_name(const knot_rdataset_t *rrs)
{
	KNOT_RDATASET_CHECK(rrs, 0, return NULL);
	uint8_t location_len = *(knot_rdata_offset(rrs, 0, 2));
	return knot_rdata_offset(rrs, 0, 2 + 1 + location_len);
}

static inline
const char *knot_lb_location(const knot_rdataset_t *rrs)
{
	KNOT_RDATASET_CHECK(rrs, 0, return NULL);
	return knot_rdata_offset(rrs, 0, 2);
}

static inline
const uint16_t *knot_lb_weight(const knot_rdataset_t *rrs)
{
	KNOT_RDATASET_CHECK(rrs, 0, return NULL);
	return wire_read_u16(knot_rdata_offset(rrs, 0, 0));
}
