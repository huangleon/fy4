 // more.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//  
#include <ansi.h>
#define MAX_MSG_BUFFER 15000
#define DISPLAY_LINES 40 
void more(string cmd, string *text, int line) {
        int i,j; 
        switch(cmd) {
                case "":
                        for(i=line + DISPLAY_LINES; line<sizeof(text) && line<i; line++)
                                write(text[line] + "\n");
                        if( line>=sizeof(text) ) return;
                        break; 
/*
                case "b":
                        line = line - DISPLAY_LINES - DISPLAY_LINES;
                        if(line<-DISPLAY_LINES) return;
                        for(i=line + DISPLAY_LINES; line < i;line++)
                                write(text[line]+"\n");
                        break;
*/ 
                case "q":
                default:
                        return;
        } 
        printf("== δ����� " HIY "%d%%" NOR " == (ENTER ������һҳ��q �뿪)",
                line*100/sizeof(text)); 
        input_to("more", text, line);
} 
void start_more(string cmd, string msg, int offset) {
        int index, line, size;
        string tmp; 
        if (!msg || msg == "")
                return; 
        if (cmd == "q")
                return; 
        size = sizeof(msg);
   if (!offset && size < MAX_MSG_BUFFER) {
                more("", explode(msg, "\n"), 0);
                return;
        } 
    for (index = line = 0; index + offset < size; index++) {
                if (msg[offset + index] == '\n') {
                        if (line++ >= DISPLAY_LINES - 1) {
                                if (index > MAX_MSG_BUFFER)
                                        index = MAX_MSG_BUFFER; 
                                tmp = msg[offset .. offset + index - 1];
                                more("", explode(tmp, "\n"), 0); 
                                printf("== δ����� " HIY "%d%%" NOR " == (ENTER ������һҳ��q �뿪)",
                                        (offset + index) * 100 / size); 
                                input_to("start_more", msg, offset + index); 
                return;
                        }
                }
        } 
        if (index > 0) {
                if (index > MAX_MSG_BUFFER)
                        index = MAX_MSG_BUFFER; 
                tmp = msg[offset .. offset + index - 1];
                more("", explode(tmp, "\n"), 0);
        }
}       
