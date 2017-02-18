/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:00:53 by myoung            #+#    #+#             */
/*   Updated: 2017/02/18 11:20:19 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int					listen_fd;
	int					conn_fd;
	struct sockaddr_in	serv_addr;
	char				send_buff[1024];

	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&serv_addr, sizeof(serv_addr));
	bzero(send_buff, sizeof(send_buff));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5000);
	bind(listen_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	listen(listen_fd, 10);
	while (42)
	{
		conn_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL);
		write(conn_fd, "pong\npong\n", 10);
		close(conn_fd);
	}
}
