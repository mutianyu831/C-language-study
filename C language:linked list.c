#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct roomInfo {
    char roomN[7]; // 客房号
    int price;     // 价格
    int beds;      // 床位数
    char state[5]; // 入住状态
    struct roomInfo* next;
} Room;

// （1）实现函数 int InitRoomInfo(Room **head, int n)
int InitRoomInfo(Room** head, int n) {
    FILE* fp = fopen("room_info.txt", "r");
    if (!fp) {
        return -1;
    }
    Room* current = NULL;
    int count = 0;
    while (count < n && !feof(fp)) {
        Room* newRoom = (Room*)malloc(sizeof(Room));
        if (fscanf(fp, "%s %d %d %s", newRoom->roomN, &newRoom->price, &newRoom->beds, newRoom->state) != 4) {
            free(newRoom);
            break;
        }
        newRoom->next = NULL;
        if (*head == NULL) {
            *head = newRoom;
        }
        else {
            current->next = newRoom;
        }
        current = newRoom;
        count++;
    }
    fclose(fp);
    return count;
}

// （2）实现函数 int CountEmptyRoom(Room *head, int price)
int CountEmptyRoom(Room* head, int price) {
    int count = 0;
    while (head) {
        if (head->price == price && strcmp(head->state, "空闲") == 0) {
            count++;
        }
        head = head->next;
    }
    return count;
}

// （3）实现函数 char* BookRoom(Room *head, int price)
char* BookRoom(Room* head, int price) {
    while (head) {
        if (head->price == price && strcmp(head->state, "空闲") == 0) {
            strcpy(head->state, "预定");
            return head->roomN;
        }
        head = head->next;
    }
    return NULL;
}

// （4）实现函数 Room* delRoom(Room *head, char *roomN)
Room* delRoom(Room* head, char* roomN) {
    Room* prev = NULL, * current = head;
    while (current) {
        if (strcmp(current->roomN, roomN) == 0) {
            if (prev) {
                prev->next = current->next;
            }
            else {
                head = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
    // 更新文件
    FILE* fp = fopen("room_info.txt", "w");
    if (fp) {
        current = head;
        while (current) {
            fprintf(fp, "%s %d %d %s\n", current->roomN, current->price, current->beds, current->state);
            current = current->next;
        }
        fclose(fp);
    }
    return head;
}

// （5）编写主函数，测试以上功能
int main() {
    Room* head = NULL;
    int n = 10; // 假设读取10条记录
    int ret = InitRoomInfo(&head, n);
    if (ret == -1) {
        printf("读取文件失败！\n");
        return -1;
    }
    printf("成功读取了%d条客房信息。\n", ret);

    int price = 200; // 示例价位
    int emptyCount = CountEmptyRoom(head, price);
    printf("价位为%d的空闲房间数量为：%d\n", price, emptyCount);

    char* bookedRoom = BookRoom(head, price);
    if (bookedRoom) {
        printf("成功预订房间：%s\n", bookedRoom);
    }
    else {
        printf("没有价位为%d的空闲房间可预订。\n", price);
    }

    char roomToDelete[7] = "A101"; // 示例房间号
    head = delRoom(head, roomToDelete);
    printf("已删除房间：%s\n", roomToDelete);

    // 释放链表内存
    Room* current = head;
    while (current) {
        Room* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
