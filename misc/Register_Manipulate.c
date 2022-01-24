/* Volume register is at address 0x80008000
Bits 0..10 are the gain. Bit 11 is mute. Bits 12-15 should not be changed.
  
Implement the functions below with appropriate prototypes.
set_volume(level)
get_volume()
toggle_mute()

Please design this with code maintainability in mind as we might like to move
this to another platform later
*/

enum ReturnStatusEnum{
    SUCCESS=0,
    OPERATION_FAILED=1
};

static const uint32_t VOLUME_REGISTER = 0x80008000;
static const uint16_t MUTE_MASK = 0x800;
static const uint16_t LEVEL_MASK = 0x7FF;

// Set the volume to the register
ReturnStatusEnum set_volume( uint16_t level ){
    // Limit for volume register
    if(level >= ( 2<<11 )){
        return OPERATION_FAILED;
    }

    level &= mask;

    return write_level( level);
}

// Write to the address register
ReturnStatusEnum write_level( const uint16_t level ){
    uint32_t* volume_register = (uint32_t*)VOLUME_REGISTER;  // *volume_register: 0x000F, level: 0
    *volume_register = ( ~LEVEL_MASK & (*volume_register) ) | level;
    return SUCCESS;
}

//Grab the volume register value from the register address
ReturnStatusEnum get_volume( uint16_t* level ){
    const uint16_t temp = *((uint32_t*)VOLUME_REGISTER);
    *level = LEVEL_MASK & temp;
    
    return SUCCESS;
}

// Toggle mute on the volume register
ReturnStatusEnum toggle_mute( ){
    uint32_t* volume_register = (uint32_t *)VOLUME_REGISTER;
    const uint32_t mute_mask = 0x800;
    *volume_register = ( *volume_register & ~mute_mask ) | ~(*volume_register & mute_mask);
    
    return SUCCESS;
}
