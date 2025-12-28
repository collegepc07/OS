#include <stdio.h>

int main() {
    int page_table[10];
    int pages, page_size;
    int logical_address, page_no, offset, frame_no, physical_address;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page size: ");
    scanf("%d", &page_size);

    printf("Enter page table (frame number for each page):\n");
    for(int i = 0; i < pages; i++)
        scanf("%d", &page_table[i]);

    printf("Enter logical address: ");
    scanf("%d", &logical_address);

    page_no = logical_address / page_size;
    offset = logical_address % page_size;

    frame_no = page_table[page_no];
    physical_address = frame_no * page_size + offset;

    printf("Physical Address: %d\n", physical_address);
    return 0;
}
