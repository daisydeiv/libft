#include "libft.h"

int	main(void)
{
	printf("====================================================\n");
	ft_printf("====================================================\n");

	int	test_char = 'c';	
	printf("printf for char = %c\n", test_char);
	ft_printf("my trials and error for char = %c\n", test_char);

	printf("====================================================\n");
	ft_printf("====================================================\n");

	char	*test_str = "Hell is back, and we deserve it";	
	printf("printf for str = %s\n", test_str);
	ft_printf("my trials and error for str = %s\n", test_str);

	printf("====================================================\n");
	ft_printf("====================================================\n");

	int	test_num = INT_MIN;	
	printf("printf for num = %d\n", test_num);
	ft_printf("my trials and error for num = %d\n", test_num);

	printf("====================================================\n");
	ft_printf("====================================================\n");

	unsigned int	test_unsigned = 123456789;	
	printf("printf for num = %u\n", test_unsigned);
	ft_printf("my trials and error for num = %u\n", test_unsigned);

	printf("====================================================\n");
	ft_printf("====================================================\n");

	unsigned int	test_lowhex = 123456789;
	printf("printf for lowhex = %x\n", test_lowhex);
	ft_printf("my trials and errors for lowhex = %x\n", test_lowhex);

	printf("====================================================\n");
	ft_printf("====================================================\n");

	unsigned int	test_uphex = 123456789;
	printf("printf for uphex = %X\n", test_uphex);
	ft_printf("my trials and errors for uphex = %X\n", test_uphex);

	printf("====================================================\n");
	ft_printf("====================================================\n");

	char	*test1 = "test";
	int		test2 = 42;
	void	*test_pointer1 = &test1;
	printf("printf for pointer = %p\n", test_pointer1);
	ft_printf("my trials and errors for pointer = %p\n", test_pointer1);
	void	*test_pointer2 = &test2;
	printf("printf for pointer = %p\n", test_pointer2);
	ft_printf("my trials and errors for pointer = %p\n", test_pointer2);

	printf("====================================================\n");
	ft_printf("====================================================\n");

	printf("printf for percent = %%\n");
	ft_printf("my trials and error for percent = %%\n");

	printf("====================================================\n");
	ft_printf("====================================================\n");

	return(0);
}