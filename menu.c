
/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  YangXuan                                                             */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/13                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by YangXuan, 2014/09/13
 *
 */



#include<stdio.h>
#include<stdlib.h>

#define DESC_LEN 1024
#define CMD_MAX_LEN 128

/* data struct and its operation */
typedef struct DataNode
{
    char      *cmd;
    char      *desc; 
    struct    DataNode *next;
} tDataNode;


tDataNode * FindCmd(tDataNode *head, char *cmd)
{
    tDataNode *tmp = head;
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }  
    while(tmp != NULL)
    {
        if(!strcmp(tmp->cmd, cmd))
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}
        
int ShowAllCmd(tDataNode *head)
{
    tDataNode *tmp = head;
    printf("Menu List:\n");
    while(tmp != NULL)
    {
        printf("%s - %s\n", tmp->cmd, tmp->desc); 
        tmp = tmp->next;
    }
    return 0;
}

/* menu program */
static tDataNode head[] =
{
    {"help", "this is help cmd!", &head[1]},
    {"version", "menu program v1.0", NULL}
};  

main()
{                                                                                    
    /* cmd line begins */ 
    while(1)
    { 
  	char cmd[CMD_MAX_LEN];
  	tDataNode  *tmp = NULL; 
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tmp = FindCmd(head, cmd);
        if(tmp == NULL)
        {
            printf("This is a wrong cmd number!\n");
            continue;
        }
        printf("%s - %s\n", tmp->cmd, tmp->desc);
        if(tmp->cmd == "help")
        { 
            ShowAllCmd(head);
	}
    }
} 
