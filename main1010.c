
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <pthread.h>

#define BBT_HTTP_HOST_NAME	"www.baidu.com"
#define BBT_HTTP_TIME_PATH	"/"

#define	BBT_HTTP_TIMEOUT_S	2
#define TCP_BUFFSIZE	        14600


int bbtGetIpByHostname(char *host_name, char *first_ip)
{
    char **pptr;
    const char *first;
    struct hostent *hptr;
    char str[32] = {'\0'}; 
 
    /* 调用gethostbyname()。结果存在hptr结构中 */
    if((hptr = gethostbyname(host_name)) == NULL)
    {
        printf(" gethostbyname error for host:%s", host_name);
        return -1;
    }

    /* 根据地址类型，将地址打出来 */
    switch(hptr->h_addrtype)
    {

        case AF_INET:
        case AF_INET6:

            pptr=hptr->h_addr_list;
            /* 将刚才得到的所有地址都打出来。其中调用了inet_ntop()函数 */
            for(; *pptr!=NULL; pptr++)
                printf(" address:%s", inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
            first = inet_ntop(hptr->h_addrtype, hptr->h_addr, str, sizeof(str));
            // ESP_LOGI(TAG, first address: %s\n", first);
            if(first)
                memcpy(first_ip, str, 32);
            break;

        default:
            printf("unknown address type");
            break;

    }

    return 0;
}

int socket_open_http(char *host_name, char *ip_out)
{
    int socketId;
    struct sockaddr_in serv_addr;
    int status;

    if (bbtGetIpByHostname(host_name, ip_out))
        return -1;
 
    socketId = socket(AF_INET, SOCK_STREAM, 0);

    if((int)socketId < 0)
    {
       printf("Create a socket failed!");
       return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    
    unsigned long net_ip = inet_addr(ip_out);
    if(net_ip == INADDR_NONE) {
        printf("net_ip failed!");
        return -1;
    }
    serv_addr.sin_addr.s_addr = net_ip;
    serv_addr.sin_port = htons(80);   // 端口默认80
    serv_addr.sin_family = AF_INET;

    status = connect(socketId, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if(status!=0) {
        printf("Connecting failed!");
        close(socketId);
        return -1;
    }
    printf("connect sucess");
    
    return socketId;

}

 
int main1010(void)
{
	 char http_ip[32] = {0};
		int http_skt = socket_open_http(BBT_HTTP_HOST_NAME, http_ip);
		if (http_skt <= 0)
			return -1;
	
		//这里控制模块的请求时间，设置tcp收发超时，如果没有要求可以不设置 
		struct timeval timeout = {BBT_HTTP_TIMEOUT_S, 0}; 
		//设置发送超时
		setsockopt(http_skt, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(struct timeval));
		//设置接收超时
		setsockopt(http_skt, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(struct timeval));
		
		char *http_request;
		const char *GET_TIME =
			"GET %s HTTP/1.1\r\n"
			"Host: %s:%d\r\n"
			"\r\n";
	
		// 合成请求报文
		int get_len = asprintf(&http_request, GET_TIME, BBT_HTTP_TIME_PATH, http_ip, 80);
		if (get_len < 0) {
			printf("GET request buffer error");
			goto GET_TIME_ERR;
		}
		// 发送报文
		int send_len = send(http_skt, http_request, get_len, 0);
		free(http_request);
		if (send_len < 0) 
			goto GET_TIME_ERR;
	 
		// 接收响应（这里假设一包能收完）
		char tcp_buf[TCP_BUFFSIZE] = {0};
		memset(tcp_buf, 0x00, TCP_BUFFSIZE);
		int buff_len = recv(http_skt, tcp_buf, TCP_BUFFSIZE, 0);
		if (buff_len < 0) { 
			printf("receive data error!");
			goto GET_TIME_ERR;			
		}
	
		// 释放socket
		close(http_skt);
	
		printf("tcp_buf = \n%s\n", tcp_buf);
	
		/* 处理tcp_buf中的响应报文 */
		/* 可以以"\n"取行，一直取到一个只有2个字节的即"\r\n" ，下一行就是主体*/
	
		return 0;
	
	GET_TIME_ERR:
	
		close(http_skt);
		return -1;
}

