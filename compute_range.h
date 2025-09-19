#ifndef COMPUTE_RANGE_H
#define COMPUTE_RANGE_H

// Floats don't have signed or unsigned variants.
// They represent both positive and negative floating numbers.
// People can tell you a variety of reasons of why this is:
// - some say there was never a need for unsigned float support
//   as floats have a large enough margin to represent large numbers
//   with acceptable precision.
// - hardware doesn't support unsigned float operations. CPU literally
//   wasn't designed for this.
// - the IEEE-754 standard for floating point arithmetic doesn't specify
//   support for unsigned floats, and thats what most programming languages
//   follow.

// Pass in sizeof() your data type.
void compute_srange(int byte_size);
void compute_urange(int byte_size);

#endif
