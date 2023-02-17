

typedef struct

{

    uint32_t start;

    uint32_t duration;

} delay_t;





typedef enum

{

    DELAY_OK = 0,

    DELAY_ERROR,

    DELAY_EXPIRED,

    DELAY_RUNNING

} delay_ret_t;

delay_ret_t delay_init(delay_t *delay, uint32_t duration);

delay_ret_t delay_get_status(delay_t *delay);

delay_ret_t delay_reset(delay_t *delay);
