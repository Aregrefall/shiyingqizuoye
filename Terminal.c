#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int is_leap_year(int year)
{
	printf("(judge whether the year is a leap year.)\n");
	if (year == 0)
	{
		return 2;
	}
	else if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Excel()
{
	printf("(make a 9x9 excel.)\n");
	int i, j;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", j, i, j * i);
		}
		printf("\n");
	}
}

void Sum()
{
	printf("(find 2 numbers by those sum.)\n");
	int nums[10] = { 1,4,5,2,11,8,16,3,14,22 };
	int target = 20;

	printf("nums =");
	for (int i = 0; i < 10; i++)
	{
		printf(" %d", nums[i]);
	}
	printf("\n");
	printf("target = %d\n", target);
	printf("index :");
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				printf("[%d,%d]\n", i, j);
				printf("%d + %d = %d\n", nums[i], nums[j], target);
			}
		}
	}
	return;
}

void Swap()
{
	printf("(swap 10 integers from odds to evens,from small to large.)\n");
	printf("(Plus:add new nums and swap so.)\n");
	int n = 10;
	int* arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL)
	{
		return;
	}
	int s;
	printf("Please enter 10 integers:\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	while (getchar() != '\n');
	do
	{
		int* odd = (int*)malloc(n * sizeof(int));
		int* even = (int*)malloc(n * sizeof(int));
		int x = 0;
		int y = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] % 2 != 0)
			{
				odd[x++] = arr[i];
			}
			else
			{
				even[y++] = arr[i];
			}
		}
		int temp;
		for (int i = 0; i < x - 1; i++)
		{
			for (int j = i + 1; j < x; j++)
			{
				if (odd[j] < odd[i])
				{
					temp = odd[i];
					odd[i] = odd[j];
					odd[j] = temp;
				}

			}
		}
		for (int i = 0; i < y - 1; i++)
		{
			for (int j = i + 1; j < y; j++)
			{
				if (even[j] < even[i])
				{
					temp = even[i];
					even[i] = even[j];
					even[j] = temp;
				}

			}
		}
		int t = 0;
		for (int i = 0; i < x; i++)
		{
			arr[t++] = odd[i];
		}
		for (int i = 0; i < y; i++)
		{
			arr[t++] = even[i];
		}
		for (int i = 0; i < n; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		printf("you can enter '1' to enter new number,enter '0' to break: ");
		scanf("%d", &s);
		if (s == 1)
		{
			printf("now you are adding nums,enter '0' to break: ");
			if (n < 100)
			{
				scanf("%d", &arr[n]);
				n++;
			}
			else
			{
				s = 0;
			}
		}
		else if (s == 0)
		{
			while (getchar() != '\n');
			//在改缓冲区时发现这里也是
			return;
		}
	} while (s == 1);
	free(arr);
}

struct Goods 
{
	char name[100];
	float price;
	int number;
};
void find(struct Goods* goods, int size)
{
	char name[100];
	printf("你可以通过输入商品名称来查询单价\n");
	printf("请输入商品名称：\n");
	if (fgets(name, sizeof(name), stdin) == NULL)//这里统一都使用fgets，省去使用scanf后面再清除缓冲区的步骤
	{
		return;
	}
	name[strcspn(name, "\n")] = '\0';
	int found = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(goods[i].name, name) == 0)
		{
			printf("商品：%s 单价：%.1f\n", goods[i].name, goods[i].price);
			found = 1;
			break;
		}
	}
	if (!found)
	{
		printf("%s不存在,如果您想添加新的商品,请输入'add'\n", name);
	}

}
void shop(struct Goods* goods, int size)
{
	printf("请按相应格式输入'商品 数量'，例如'牛奶 3'\n");
	char name[100];
	int number;
	char input[100];
	while (1)
	{
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (sscanf(input, "%s %d", name, &number) == 2)
		{
			int found = 0;
			for (int i = 0; i < size; i++)
			{
				if (strcmp(goods[i].name, name) == 0)
				{
					goods[i].number += number;
					printf("您成功购买了%d个%s!如果想要结束购物，请输入'end'\n", number, name);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				printf("%s不存在,如果您想添加新的商品,请输入'add'\n", name);
			}
		}
		else if (sscanf(input, "%s", name) == 1)
		{
			if (strcmp(name, "end") == 0)
			{
				printf("小票如下： \n");
				printf("商品名 单价 数量\n");
				for (int i = 0; i < size; i++)
				{
					if (goods[i].number > 0)
					{
						printf("%s   %.1f   %d\n", goods[i].name, goods[i].price, goods[i].number);
					}
				}
				float all = 0;
				for (int i = 0; i < size; i++)
				{
					all += goods[i].price * goods[i].number;
				}
				printf("总价   %.1f\n", all);
				printf("谢谢惠顾！ \n");
				return;
			}
			else
			{
				printf("%s不存在,如果您想添加新的商品,请先输入'end'退出shop,再输入'add'添加商品\n", name);
			}
		}
		else
		{
			printf("未知指令！\n");
		}
	}
}
struct Goods* add(struct Goods* goods, int* size, int* capacity)
	//这里使用struct Goods *add而不是void add,方便之后直接返回goods
{
	printf("请按相应格式输入'商品 单价',例如'哈基米南北绿豆浆 2'\n");
	char input[100];
	char name[100];
	float price;
	if (*size >= *capacity)
	{
		int new_capacity = (*capacity == 0) ? 4 : *capacity * 2;
		// 这句代码等价于
		// if(*capacity==0)
		// {
		//    new_capacity=4;
		// }
		// else
		// {
		//    new_capacity=capacity*2;
		// }
		// 这样写更简洁力
		//（其实是为了装x)
		struct Goods* new_goods = realloc(goods, new_capacity * sizeof(struct Goods));
		if (new_goods == NULL)
		{
			printf("内存分配失败！\n");
			return goods;
		}
		*capacity = new_capacity;
		goods = new_goods;
	}
	if (fgets(input, sizeof(input), stdin) == NULL)
	{
		return goods;
	}
	input[strcspn(input, "\n")] = '\0';
	if (sscanf(input, "%s %f", name, &price) == 2)
	{
		for (int i = 0; i < *size; i++)
		{
			if (strcmp(goods[i].name, name) == 0)
			{
				printf("%s已存在,请添加新的商品！\n");
			}
		}
		strcpy(goods[*size].name, name);
		goods[*size].price = price;
		goods[*size].number = 0;
		(*size)++;//这里必须先解应用，不能写成*size++！！！！！
		printf("成功添加商品：%s 单价：%.1f!", name, price);
		return goods;
	}
	else
	{
		printf("未知指令！\n");
		return;
	}
}

void Supermarket_boss()
{
	printf("欢迎来体验超市老板！\n");
	int capacity = 10;
	int size = 10;

	struct Goods* good_goods = malloc(size * sizeof(struct Goods));
	if (good_goods == NULL)
	{
		printf("内存申请失败\n");
		return 1;
	}
	struct Goods* p = good_goods;
	char* names[10] = { "牛奶","面包","方便面","矿泉水","火腿肠","溜溜梅","薄荷糖","豆腐干","辣条","纸巾" };
	float prices[10] = { 3,2,5,1,1.5,5,10,1,0.5,1 };
	for (int i = 0; i < 10; i++)
	{
		strcpy(p->name, names[i]);
		p->price = prices[i];
		p->number = 0;
		p++;
	}
	p = good_goods;

	char input[100];
	while (1)
	{
		printf("(试输入'find'或'shop'或'add'或'exit'来执行查找商品、购物、添加商品和退出的功能)\n");
		printf(">");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "find") == 0)
		{
			find(good_goods, size);
		}
		else if (strcmp(input, "shop") == 0)
		{
			shop(good_goods, size);
		}
		else if (strcmp(input, "add") == 0)
		{
			good_goods = add(good_goods, &size, &capacity);
			//接受new_goods,所以直接传地址
		}
		else if (strcmp(input, "exit") == 0)
		{
			break;
		}
		else
		{
			printf("未知指令: %s\n", input);
		}
	}
	free(good_goods);
	good_goods = NULL;
}



void help()
{
	printf("do - implement the program\n");
	printf("list - list all commands\n");
	printf("help - show the function of all commands\n");
	printf("exit - exit the shell\n");
}

void list()
{
	printf("do\nlist\nhelp\nexit\n");
}

void Do(char* name)
{
	if (strcmp(name, "Sum") == 0)
	{
		Sum();
	}
	else if (strcmp(name, "Swap") == 0)
	{
		Swap();
	}
	else if (strcmp(name, "is_leap_year") == 0)
	{
		printf("Please enter year:");
		int year;
		if (scanf("%d", &year) == 1)
		{
			int ret = is_leap_year(year);
			if (ret == 1)
			{
				printf("%d is leap year.\n", year);
			}
			else
			{
				printf("%d is not leap year.\n", year);
			}
			while (getchar() != '\n');
			//如果没有这行代码就会导致在输入年份后串到command else里面
			//（为了找哪里没有清空缓冲区找了半天）
		}
		else
		{
			printf("Error!Please enter a integer.\n");
			while (getchar() != '\n');
		}
	}
	else if (strcmp(name, "Excel") == 0)
	{
		Excel();
	}
	else if (strcmp(name, "Supermarket_boss") == 0)
	{
		Supermarket_boss();
	}
	else
	{
		printf("Unknown program: %s\n", name);
	}
}

void command(char* input)
{
	char com[20] = { 0 };//com存储指令，也就是commands
	char arg[20] = { 0 };//arg存储do函数后的变量，也就是programs
	int items = sscanf(input, "%19s %19s", com, arg);
	//若com与arg均存在，则items=2；若存在其一，则items=1
	//这里19是考虑到有'\0'的存在，防止缓冲区溢出
	if (items == 0)
	{
		return;
	}
	if (strcmp(com, "do") == 0)
	{
		if (items == 2)
		{
			Do(arg);
		}
		else
		{
			printf("Unknown program\n");
		}
	}
	else if (strcmp(com, "list") == 0)
	{
		list();
	}
	else if (strcmp(com, "help") == 0)
	{
		help();
	}
	else if (strcmp(com, "exit") == 0)
	{
		printf("Goodbye! :) \n");
		exit(0);
	}
	else
	{
		printf("Unknown command: %s\n", com);
		printf("Please use 'help' to see available commands.\n");
	}
}

int main()
{
	char input[100];
	while (1)
	{
		printf("(zw83) > ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		command(input);
	}
	return 0;
}