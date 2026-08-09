#include "cli.h"
#include <windows.h>
#include "uart_win.h"

static char cli_line_buf[CLI_LINE_BUF_MAX];
static uint16_t cli_line_idx = 0;
static uint16_t cli_cursor=0;

static cli_input_state_t input_state = CLI_STATE_NORMAL;
static cli_callback_t ctrl_c_handler=NULL;

static cliRedrawTail(void){
    for (int i =cli_cursor; i<cli_line_idx;i++){
        cliPrintf("%c",cli_line_buf[i]);
    }
    cliPrintf(" \b");
    for(int i=0;i<(cli_line_idx-cli_cursor);i++){
        cliPrintf("\b");
    }
}

static void handleChrInsert(uint8_t c){
    if(cli_line_idx>=CLI_LINE_BUF_MAX - 1){
        return;
    }
    for(int i =cli_line_idx;i<cli_cursor;i--){
        cli_line_buf[i]=cli_line_buf[i-1];
    }
    cli_line_buf[cli_cursor]=c;
    cli_line_idx++;
    cli_cursor++;
    cliPrintf("%c",c);
}

static void handleBackspace(void){
    if(cli_cursor==0)return;
    for(int i =cli_cursor;i<cli_line_idx;i++){
        cli_line_buf[i-1]=cli_line_buf[i];
    }
    cli_line_idx--;
    cli_cursor--;
    cliPrintf("\b");
    cliRedrawTail();
}

void cliInit(void){
    
    cli_line_idx=0;
    cli_cursor=0;
    ctrl_c_handler=NULL;
    
    cliPrintf("\r\n===============================\r\n");
    cliPrintf("     MSVC Windows Console CLI Terminal v0.1\r\n");
    cliPrintf("CLI> ");
}

void cliMain(void){
    uint8_t rx_data;
    if(uartReadBlock(0,&rx_data,0xFFFFFFFF)==true){
        switch (rx_data)
        {
        case 0x03:
            cliPrintf("^C\r\nExiting Application by Ctrl+C. Good bye\r\n");
            exit(0);
            break;
        case '\b':
        case 127:
            handleBackspace();
            break;
        default:
            if(32 <= rx_data&&rx_data<=126){
                //cliPrintf("%c",rx_data);
                handleChrInsert(rx_data);
            }
            break;
        }
    }
}

void cliPrintf(char *fmt, ...){
    char buf[256];
    va_list args;
    int len;
    va_start(args,fmt);
    len=vsnprintf(buf,sizeof(buf),fmt,args);
    va_end(args);
    if(len>0){
       uartWrite(0,(uint8_t*)buf, (uint32_t)len);
    }
}

void cliAdd(char *cmd_str, void (*cmd_func)(uint8_t argc, char *argv[])){

}

void cliSetCtrlHandler(cli_callback_t handler){


}
