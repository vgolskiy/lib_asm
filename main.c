/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:13:34 by mskinner          #+#    #+#             */
/*   Updated: 2020/10/10 19:50:27 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int		ft_strlen(char *s);
char	*ft_strcpy(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
int		ft_write(int fd, const void *s, size_t len);
int		ft_read(int fd, const void *s, size_t len);
char	*ft_strdup(char *s);

int main() {
	char	*s;
	int		i;
	int		len;
	int		fd;

	printf("\t---FT_STRLEN VERIFICATION---\n");

	printf("empty string:\n");
    printf("MY: %d\n", ft_strlen(""));
	printf("LB: %lu\n", strlen(""));

	printf("\nmiddle string:\n");
    printf("MY: %d\n", ft_strlen("Hello, World!"));
	printf("LB: %lu\n", strlen("Hello, World!"));

	printf("\nlong string:\n");
	char buf[150] = "nasm -f macho64 ft_strlen.s && gcc main.c ft_strlen.o && ./a.out";
    printf("MY: %d\n", ft_strlen(buf));
	printf("%s\n", buf);
	printf("LB: %lu\n", strlen(buf));
	
	len = 65535;
	s = (char *)malloc((len + 1) * sizeof(char));
	i = -1;
	while (++i < (len + 1))
		s[i] = '\0';
	i = -1;
	while (++i < len)
		s[i] = 'a';
    printf("MY: %d\n", ft_strlen(s));
	printf("LB: %lu\n", strlen(s));
	free(s);


	printf("\n\n\t---FT_STRCPY VERIFICATION------\n");

	printf("empty string:\n");
	printf("MY: |%s|\n", ft_strcpy(buf, ""));
	printf("MY: |%s|\n", buf);

	printf("\nmiddle string:\n");
	printf("MY: |%s|\n", ft_strcpy(buf, "Hello, world!"));
	printf("MY: |%s|\n", buf);
	
	printf("\nlong string:\n");
	printf("MY: |%s|\n", ft_strcpy(buf, "heyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyhey"));
	printf("MY: |%s|\n", buf);

	printf("\nempty string:\n");
	printf("LB: |%s|\n", strcpy(buf, ""));
	printf("LB: |%s|\n", buf);

	printf("\nmiddle string:\n");
	printf("LB: |%s|\n", strcpy(buf, "Hello, world!"));
	printf("LB: |%s|\n", buf);
	
	printf("\nlong string:\n");
	printf("LB: |%s|\n", strcpy(buf, "heyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyhey"));
	printf("LB: |%s|\n", buf);


	printf("\n\n\t---FT_STRCMP VERIFICATION------\n");

	printf("empty string:\n");
	printf("MY: |%d|\n", ft_strcmp("", ""));
	printf("LB: |%d|\n", strcmp("", ""));

	printf("\nmiddle string:\n");
	printf("H vs H\n");
	printf("MY: |%d|\n", ft_strcmp("H", "H"));
	printf("LB: |%d|\n", strcmp("H", "H"));

	printf("\nHello, world! vs Hello, world!\n");
	printf("MY: |%d|\n", ft_strcmp("Hello, world!", "Hello, world!"));
	printf("LB: |%d|\n", strcmp("Hello, world!", "Hello, world!"));
	
	printf("\nHello, man! vs Hello, world!\n");
	printf("MY: |%d|\n", ft_strcmp("Hello, man!", "Hello, world!"));
	printf("LB: |%d|\n", strcmp("Hello, man!", "Hello, world!"));

	printf("\nHello, world! vs Hello, man!\n");
	printf("MY: |%d|\n", ft_strcmp("Hello, world!", "Hello, man!"));
	printf("LB: |%d|\n", strcmp("Hello, world!", "Hello, man!"));


	printf("\n\n\t---FT_WRITE VERIFICATION------\n");

	printf("empty string:\n");
	printf("MY: |%d|\n", ft_write(1, "", ft_strlen("")));
	printf("LB: |%zd|\n", write(1, "", strlen("")));

	printf("\nmiddle string:\n");
	printf("MY: |%d|\n", ft_write(1, "Hello, world!", ft_strlen("Hello, world!")));
	printf("LB: |%zd|\n", write(1, "Hello, world!", strlen("Hello, world!")));
	
	printf("\nlong string:\n");
	printf("MY: |%d|\n", ft_write(1, "heyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyhey", ft_strlen("heyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyhey")));
	printf("LB: |%zd|\n", write(1, "heyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyhey", strlen("heyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyhey")));

	fd = open("testing.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	printf("\nsave long string to file:\n");
	printf("MY: |%d|\n", ft_write(fd, "heyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyhey", ft_strlen("heyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyhey")));
	close(fd);

	printf("error string:\n");
	printf("MY: |%d|\n", ft_write(1, NULL, 1));
	printf("MY: errno %d error msg is: %s\n", errno, strerror(errno));
	printf("LB: |%zd|\n", write(1, NULL, 1));
	printf("LB: errno %d error msg is: %s\n", errno, strerror(errno));

	printf("MY: |%d|\n", ft_write(100, "test", ft_strlen("test")));
	printf("errno %d error msg is: %s\n", errno, strerror(errno));
	printf("LB: |%zd|\n", write(100, "test", strlen("test")));
	printf("LB: errno %d error msg is: %s\n", errno, strerror(errno));


	printf("\n\n\t---FT_READ VERIFICATION------\n");

	char buffer[100];
	char buffer2[100];
	printf("STDIN:\n");
	i = ft_read(0, buffer, 100);
	buffer[i] = '\0';
	printf("MY: return value %d string: |%s|\n", i, buffer);
	i = read(0, buffer2, 100);
	buffer2[i] = '\0';
	printf("LB: return value %d string: |%s|\n", i, buffer2);

	printf("read string:\n");
	char buf2[150];
	char buf3[150];
	int	returned;
	fd = open("testing.txt", O_RDONLY);
	returned = ft_read(fd, buf2, 100);
	buf2[returned] = '\0';
	printf("MY: read return %d and string: %s\n", returned, buf2);

	returned = ft_read(fd, buf2, 100);
	buf2[returned] = '\0';
	printf("MY: read return %d and string: %s\n", returned, buf2);
	close(fd);

	fd = open("testing.txt", O_RDONLY);	
	returned = read(fd, buf3, 100);
	buf3[returned] = '\0';
	printf("LB: read return %d and string: %s\n", returned, buf3);

	returned = read(fd, buf3, 100);
	buf3[returned] = '\0';
	printf("LB: read return %d and string: %s\n", returned, buf3);
	close(fd);
	
	printf("read error:\n");
	printf("MY: |%d|\n", ft_read(100, buf, 1));
	printf("MY: errno %d error msg is: %s\n", errno, strerror(errno));
	printf("LB: |%zd|\n", write(100, buf, 1));
	printf("LB: errno %d error msg is: %s\n", errno, strerror(errno));


	printf("\n\n\t---FT_STRDUP VERIFICATION------\n");

	printf("empty string:\n");
	s = ft_strdup("");
	printf("|%s|\n", s);

	printf("\nmiddle string:\n");
	s = ft_strdup("Hello, world!");
	printf("|%s|\n", s);
	
	printf("\nlong string:\n");
	s = ft_strdup("heyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyheyhey");
	printf("|%s|\n", s);

    return 0;
}