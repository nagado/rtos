#include <LPC17xx.h>
//#include <LPC177x_8x.h>


typedef unsigned int Uint32;

const Uint32 gpio_base = 0x20098000;

Uint32* gpio_dir1 = (Uint32*) (gpio_base + 0x20);
Uint32* gpio_set1 = (Uint32*) (gpio_base + 0x38);
Uint32* gpio_clr1 = (Uint32*) (gpio_base + 0x3c);

Uint32* gpio_dir0 = (Uint32*) (gpio_base + 0x00);
Uint32* gpio_set0 = (Uint32*) (gpio_base + 0x18);
Uint32* gpio_clr0 = (Uint32*) (gpio_base + 0x1c);

Uint32* gpio_dir4 = (Uint32*) (gpio_base + 0x80);
Uint32* gpio_set4 = (Uint32*) (gpio_base + 0x98);
Uint32* gpio_clr4 = (Uint32*) (gpio_base + 0x9c);


void sleep()
{
	for(int i = 0; i < 5000000; ++i) ;
}

int main()
{
		const Uint32 led_mask1 =  1 << 14;
	  const Uint32 led_mask2 =  1 << 16;
	  const Uint32 led_mask3 =  1 << 13;
	  const Uint32 led_mask4 =  1 << 27;
		
  	*gpio_dir1 = 0;
	  *gpio_set1 = 0;
	  *gpio_clr1 = 0;

    *gpio_dir0 = 0;
    *gpio_set0 = 0;
    *gpio_clr0 = 0;

    *gpio_dir4 = 0;
    *gpio_set4 = 0;
    *gpio_clr4 = 0;
	
		*gpio_dir1 |= led_mask1;
		*gpio_dir0 |= led_mask2;
	  *gpio_dir1 |= led_mask3;
		*gpio_dir4 |= led_mask4;
	
		for(;;)
		{
			*gpio_clr0 |= led_mask2;
			*gpio_clr4 |= led_mask4;
			*gpio_set1 |= led_mask1;
			sleep();
		  *gpio_clr1 |= led_mask1;
			*gpio_set0 |= led_mask2;
			sleep();
			*gpio_clr0 |= led_mask2;
			*gpio_set1 |= led_mask3;
			sleep();
			*gpio_clr1 |= led_mask3;		
			*gpio_set4 |= led_mask4;
			sleep();
			*gpio_clr4 |= led_mask4;
			*gpio_set1 |= led_mask1;
			*gpio_set1 |= led_mask3;
			sleep();
			*gpio_clr1 |= led_mask1;
			*gpio_clr1 |= led_mask3;
			*gpio_set0 |= led_mask2;
			*gpio_set4 |= led_mask4;
			sleep();
		}
}
