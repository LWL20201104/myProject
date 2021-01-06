#include <stdlib.h>
#include <stdio.h>

//交换n1和n2两个位置的值
void swap(int* in_data, int n1, int n2) {
	int tmp = in_data[n1];
	in_data[n1] = in_data[n2];
	in_data[n2] = tmp;
}

void insert_sort(int* in_data, int len) {
	printf("插入排序结果: ");
	for (int i = 1; i < len; i++) {
		for (int j = i; j > 0; j--) {
			if (in_data[j] < in_data[j - 1])
				swap(in_data, j, j - 1);
			else
				break;
		}
	}
	for (int i = 0; i < len; i++) {
		printf("%d ", in_data[i]);
	}
	printf("\n\n\n");
}

void bubble_sort(int* in_data, int len) {
	printf("冒泡排序结果: ");
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < len - i; j++) { //大数往下沉，小数往上浮
			if (in_data[j] > in_data[j + 1])
				swap(in_data, j, j + 1);
		}
	}
	for (int i = 0; i < len; i++) {
		printf("%d ", in_data[i]);
	}
	printf("\n\n\n");
}

void qk_sort(int* in_data, int left, int right) {
	if (left >= right) 
		return;

	int tmp_l = left;
	int tmp_r = right + 1;
	int index = tmp_l + 1;
	while (index != tmp_r) {
		if (in_data[index] > in_data[left]) //大于基准值的移动到右边
			swap(in_data, index, --tmp_r);
		else if (in_data[index] < in_data[left]) //小于基准值的移动到左边
			swap(in_data, index++, ++tmp_l);
		else  //等于基准值的移动到中间
			index++;
	}
	swap(in_data, left, tmp_l--);
	qk_sort(in_data, left, tmp_l);
	qk_sort(in_data, tmp_r, right);
}

void quick_sort(int* in_data, int len) {
	printf("快速排序结果: ");
	qk_sort(in_data, 0, len - 1);
	for (int i = 0; i < len; i++) {
		printf("%d ", in_data[i]);
	}
	printf("\n\n\n");
}

void select_sort(int* in_data, int len) {
	printf("选择排序结果: ");
	for (int i = 0; i < len; i++) {
		int index = i;
		for (int j = i + 1; j < len; j++) { //循环结束后，找到i - (len - 1)范围内的最小值
			if (in_data[index] > in_data[j])
				index = j;
		}
		if (index != i)
			swap(in_data, index, i);
	}
	for (int i = 0; i < len; i++) {
		printf("%d ", in_data[i]);
	}
	printf("\n\n\n");
}

void mg_sort(int* in_data, int left, int right) {
	if (left >= right)
		return;

	int mid = left + ((right - left) >> 1);
	mg_sort(in_data, left, mid); //左半部分排序
	mg_sort(in_data, mid + 1, right); //右半部分排序
	
	int index = 0;
	int tmp_l = left;
	int tmp_r = mid + 1;
	int* tmp = malloc((right - left + 1) * sizeof(int)); //暂时存储排序的数据
	while (tmp_l <= mid && tmp_r <= right) { //左半部分排序完成的数据和右半部分排序完成的数据合并
		if (in_data[tmp_l] < in_data[tmp_r])
			tmp[index++] = in_data[tmp_l++];
		else 
			tmp[index++] = in_data[tmp_r++];
	}
	while (tmp_l <= mid) { //合并剩余的部分追加到临时数组后面
		tmp[index++] = in_data[tmp_l++];
	}
	while (tmp_r <= right) { //合并剩余的部分追加到临时数组后面
		tmp[index++] = in_data[tmp_r++];
	}
	index = 0;
	while (left <= right) { //排序完成的数据写回到原始数组
		in_data[left++] = tmp[index++];
	}
	free(tmp);
}

void merge_sort(int* in_data, int len) {
	printf("归并排序结果: ");
	mg_sort(in_data, 0, len - 1);
	for (int i = 0; i < len; i++) {
		printf("%d ", in_data[i]);
	}
	printf("\n\n\n");
}

int main() {
	printf("******** 排序算法演示系统 ********\n\n");
	int is_stop = 0;
	int in_num  = 0;
	while (is_stop == 0) {
		if (in_num != 0) {
			printf("是否开始新的一轮(0-开始 1-结束): ");
			scanf("%d", &is_stop);
			if (is_stop != 0) {
				return 1;
			}
			printf("\n\n\n");
		}
		//输入待排序数据长度
		printf("请输入待排序的数据长度: ");
		scanf("%d", &in_num);
		if (in_num <= 0)
			return 1;
		int* in_data = malloc(in_num * sizeof(int));
		//输入待排序数据
		printf("\n请输入待排序的%d个数据: ", in_num);
		for (int i = 0; i < in_num; i++) {
			scanf("%d", &in_data[i]);
		}
		//排序菜单
		printf("\n");
		printf("        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("        ┃           算法选择菜单           ┃\n");
		printf("        ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
		printf("        ┃            0-插入排序            ┃\n");
		printf("        ┃            1-冒泡排序            ┃\n");
		printf("        ┃            2-快速排序            ┃\n");
		printf("        ┃            3-选择排序            ┃\n");
		printf("        ┃            4-归并排序            ┃\n");
		printf("        ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
		printf("        ┃            5-退出程序            ┃\n");
		printf("        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");

		printf("你的选择是: ");
		int alg_num = -1;
		scanf("%d", &alg_num);
		switch (alg_num) {
		case 0:
			insert_sort(in_data, in_num);
			free(in_data);
			break;
		case 1:
			bubble_sort(in_data, in_num);
			free(in_data);
			break;
		case 2:
			quick_sort(in_data, in_num);
			free(in_data);
			break;
		case 3:
			select_sort(in_data, in_num);
			free(in_data);
			break;
		case 4:
			merge_sort(in_data, in_num);
			free(in_data);
			break;
		case 5:
			is_stop = 1;
			free(in_data);
			break;
		default:
			printf("没有对应的排序算法\n");
			break;
		}
	}

	return 0;
}