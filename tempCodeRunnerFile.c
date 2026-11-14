
// struct node *merge_sll(struct node* start1,struct node* start2)
// {
//     if(start1==NULL) return start2;
//     if(start2==NULL) return start1;

//     if(start1->data<start2->data)
//     {
//         start1->next=merge_sll(start1->next,start2);
//         return start1;
//     }
//     else
//     {
//         start2->data=merge_sll(start1,start2->data);
//         return start2;
//     }
// }