void _myrtos_exception_handler()
{
  for(; ;) ;
}

typedef unsigned int uint32;

void sleep()
{
  int i;

  for(i = 0; i < 1000000; ++i) ;
}

void _myrtos_reset(void)
{
  uint32 gpio_base = 0x20098000;
  uint32* gpio_dir1 = (uint32*) (gpio_base + 0x20);
  uint32* gpio_set1 = (uint32*) (gpio_base + 0x38);
  uint32* gpio_clr1 = (uint32*) (gpio_base + 0x3c);

  uint32 led_mask = 1 << 14;
  *gpio_dir1 = led_mask;

  for(; ;)
  {
    *gpio_set1 = led_mask;
    sleep();
    *gpio_clr1 = led_mask;
    sleep();
  }
}

void main()
{
  for(; ;) ;
}
