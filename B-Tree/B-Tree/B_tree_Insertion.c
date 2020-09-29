// B_tree_Insertion.c

#include "functions.h"

int B_tree_Insertion(nptr_pck package, char CompName[], char from)
{
	nodeptr* Root	  = package->Root;
	nodeptr  temp_ptr = package->temp_ptr;
	nodeptr  new_Root = package->new_Root;
	nodeptr  curr	  = *Root;

	stack   stk		 = NULL;
	stack   temp_stk = NULL;
	stk_pck stk_SET  = (stk_pck)malloc(sizeof(stk_pck_rec));
	
	big_node bnode;
	
	bool found = FALSE;

	int split_count = 0;

	int i = 0;
	int k = 0;

	stk_SET->stk		  = &stk;
	stk_SET->temp_stk = &temp_stk;

	// B-tree가 비어있는 특수한 상황
	if (*Root == NULL) {
		*Root = (/* Fill your code */)malloc(sizeof(/* Fill your code */));

		for (int j = 0; j < PTR_NUM; j++) {
			(*Root)->ptr[j] = NULL;
		}	// for (j)

		strcpy((*Root)->rec[0].name, CompName);
		(*Root)->rec[0].leng = strlen(CompName);
		(*Root)->fill_cnt = 1;
		return split_count;
	}	// if

	// B-tree에 존재 여부 확인 
	found = leaf_n_del_node_finding(&curr, CompName, stk_SET, 'l');

	if (found == TRUE) {
		if (from == 'u') {
			printf("%s 레코드가 B-tree에 이미 존재합니다.\n", CompName);
		}	//	if ()
		return FALSE;
	}	// if ()

	temp_ptr = NULL;

	while (1) {
		if (curr->fill_cnt < REC_NUM) {
			// curr node is not full
			for (i = 0; i < curr->fill_cnt; i++) {
				if (strcmp(CompName, curr->rec[i].name) < 0) { break; }
			}	// for (i)

			for (int j = curr->fill_cnt; j > i; j--) {
				curr->ptr[j + 1]  = /* Fill your code */;
				strcpy(curr->rec[j].name, /* Fill your code */);
				curr->rec[j].leng = /* Fill your code */;
			}	// for (j)

			strcpy(curr->rec[i].name, /* Fill your code */);
			curr->rec[i].leng = strlen(/* Fill your code */);
			curr->ptr[i + 1]  = /* Fill your code */;
			curr->fill_cnt++;
			return split_count;
		}	// if ()

		else {
			// curr node is full. thus it must be split into two nodes.
			if (from == 'u') { split_count++; }

			for (i = 0; i < REC_NUM; i++) {
				if (strcmp(CompName, curr->rec[i].name) < 0) { break; }
			}	// for (i)

			bnode.ptr[0] = /* Fill your code */;
			for (k = 0; k < i; k++) {
				strcpy(bnode.rec[k].name, /* Fill your code */;
				bnode.rec[k].leng = /* Fill your code */;
				bnode.ptr[k + 1]  = /* Fill your code */;
			}	// for (k)

			strcpy(bnode.rec[k].name, /* Fill your code */);
			bnode.rec[k].leng = strlen(/* Fill your code */);
			bnode.ptr[k + 1]  = /* Fill your code */;
			k++;

			while (i < REC_NUM) {
				strcpy(bnode.rec[k].name, /* Fill your code */;
				bnode.rec[k].leng = /* Fill your code */;
				bnode.ptr[k + 1]  = /* Fill your code */;
				k++;
				i++;
			}	// while (i)

			// move first half of bnode to curr and second half to newly allocated node
			for (i = 0; i < CAPACITY_ORDER; i++) {
				curr->ptr[i]		  = /* Fill your code */;
				strcpy(curr->rec[i].name, /* Fill your code */);
				curr->rec[i].leng = /* Fill your code */;
			}	// for (i)
				curr->ptr[i]		  = /* Fill your code */;
			// [CAPACITY_ORDER]번째 이상 정리
			for (int l = CAPACITY_ORDER; l < REC_NUM; l++) {
				strcpy(curr->rec[l].name, "");
				curr->rec[l].leng = 0;
				curr->ptr[l + 1]  = NULL;
			}	// for (l)

				curr->fill_cnt	  = CAPACITY_ORDER;

			temp_ptr = (/* Fill your code */)malloc(sizeof(/* Fill your code */));
			for (i = 0; i < CAPACITY_ORDER; i++) {
				temp_ptr->ptr[i]		  = /* Fill your code */;
				strcpy(temp_ptr->rec[i].name, /* Fill your code */);
				temp_ptr->rec[i].leng = /* Fill your code */;
			}	// for (i)
				temp_ptr->ptr[i]		  = /* Fill your code */;

			for (int m = CAPACITY_ORDER + 1; m < PTR_NUM; m++) {
				temp_ptr->ptr[m]		  = NULL;
			}	// for (m)

				temp_ptr->fill_cnt	  = CAPACITY_ORDER;

			strcpy(CompName, bnode.rec[CAPACITY_ORDER].name);

			if (stk) { stk_pop(&stk, &curr); }
			else {
				// curr은 root와 같다.
				// 새로운 root node를 만든다.
				new_Root		 = (/* Fill your code */)malloc(sizeof(/* Fill your code */));
				new_Root->ptr[0] = /* Fill your code */;
				new_Root->ptr[1] = /* Fill your code */;

				for (int j = 2; j < PTR_NUM; j++) {
				new_Root->ptr[j] = NULL;
				}	// for (j)

				strcpy(new_Root->rec[0].name, /* Fill your code */);
				new_Root->rec[0].leng = strlen(/* Fill your code */);
				new_Root->fill_cnt	  = /* Fill your code */;
				*Root = (/* Fill your code */);

				return split_count;
			}	// else

		}	// else
	} // while (1)
}