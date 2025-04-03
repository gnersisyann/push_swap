#include "includes/push_swap.h"
#include "includes/stack.h"
#include <stdio.h>

/**
 * @brief Главная функция программы push_swap
 *
 * @param argc Количество аргументов
 * @param argv Массив строк аргументов
 * @return int Код возврата (0 при успешном завершении)
 */
int	main(int argc, char **argv)
{
	t_stack st;

	if (argc < 2)
		return (0);

	// Валидация входных данных
	validate_input(argc, argv);

	// Инициализация стека
	init_stack(&st, argc, argv);

	// Вывод содержимого стека (для отладки)
	for (int i = 0; i < st.size; ++i)
	{
		printf("%d ", st.data[i]);
	}
	printf("\nSIZE->%d", st.size);
	printf("\nTOP->%d", st.top);
	printf("\nBOTTOM->%d\n", st.bottom);

	// Очистка памяти
	if (st.data)
		free(st.data);

	return (0);
}