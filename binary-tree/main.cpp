#include <stdlib.h>
#include <stdio.h>

struct node {
    int key;
    struct node * left;
    struct node * right;
};

struct node * tree = NULL;

void ins(struct node **tree, int key) {
    struct node * cur_node = *tree;

    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    while (cur_node != NULL) {
        if (key < cur_node->key) {
            if (cur_node->left == NULL) {
                cur_node->left = new_node;
                return;
            }
            else {
                cur_node = cur_node->left;
            }
        }
        else {
            if (cur_node->right == NULL) {
                cur_node->right = new_node;
                return;
            }
            else {
                cur_node = cur_node->right;
            }
        }
    }

    *tree = new_node;
}

struct node * bstmin(struct node * cur_node) {
    while (cur_node->left != NULL) {
        cur_node = cur_node->left;
    }
    return cur_node;
}

struct node * bstmax(struct node * cur_node) {
    while (cur_node->right != NULL) {
        cur_node = cur_node->right;
    }
    return cur_node;
}

struct node ** find(struct node ** ptree, int key) {
    struct node ** pnode = ptree;
    struct node * cur_node = *pnode;

    while (cur_node != NULL && cur_node->key != key) {
        if (key < cur_node->key) {
            pnode = &(cur_node->left);
            cur_node = cur_node->left;
        }
        else {
            pnode = &(cur_node->right);
            cur_node = cur_node->right;
        }
    }

    return pnode;
}

void del(struct node ** tree, int key) {
    struct node ** del_link = find(tree, key);

    if ((*del_link) != NULL) {
        struct node * left_branch = (*del_link)->left;
        struct node * right_branch = (*del_link)->right;

        if (left_branch == NULL && right_branch == NULL) {
            free(*del_link);
            *del_link = NULL;
        }
        else if (left_branch == NULL) {
            free(*del_link);
            *del_link = right_branch;
        }
        else if (right_branch == NULL) {
            free(*del_link);
            *del_link = left_branch;
        }
        else {
            struct node * move_to_node = bstmin(right_branch);
            move_to_node->left = left_branch;
            free(*del_link);
            *del_link = right_branch;
        }
    }
}

void print(struct node * cur_node) {
    if (cur_node == NULL) {
        printf("NULL");
        return;
    }
    printf("(");
    printf("%d", cur_node->key);
    printf(",");
    print(cur_node->left);
    printf(",");
    print(cur_node->right);
    printf(")");
}

int main() {
    ins(&tree, 100);
    ins(&tree, 90);
    ins(&tree, 250);
    ins(&tree, 80);
    ins(&tree, 85);
    ins(&tree, 200);
    ins(&tree, 300);
    ins(&tree, 110);
    ins(&tree, 240);
    ins(&tree, 260);
    ins(&tree, 310);
    del(&tree, 250);
    print(tree);
}