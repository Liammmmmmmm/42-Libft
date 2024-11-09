/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:01:53 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/09 15:00:22 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

/**
 * @brief zero a byte string
 * 
 * The ft_bzero() function erases the data in the n bytes of the memory starting 
 * at the location pointed to by s, by writing zeros (byte containing '\0') 
 * to that area.
 * 
 * @param pointer Pointer to the memory area to be cleared.
 * @param n Number of bytes to set to zero.
 */
void	ft_bzero(void *pointer, size_t n);

/**
 * @brief Scans the first n bytes of memory for the first occurrence of c.
 *
 * The ft_memchr() function scans the initial n bytes of the memory area
 * pointed to by s for the first instance of c. Both c and the bytes of
 * the memory area pointed to by s are interpreted as unsigned char.
 *
 * @param s Pointer to the memory area to be scanned.
 * @param c Character to search for in the memory area.
 * @param n Number of bytes to search.
 * 
 * @return A pointer to the matching byte, or NULL if the character is
 *         not found within the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of two memory areas.
 *
 * The ft_memcmp() function compares the first n bytes (each interpreted
 * as unsigned char) of the memory areas s1 and s2.
 *
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n Number of bytes to compare.
 * 
 * @return An integer less than, equal to, or greater than zero if the first
 *         n bytes of s1 are found to be respectively less than, equal to, or
 *         greater than the first n bytes of s2. For a nonzero return value,
 *         the sign is determined by the sign of the difference between the
 *         first pair of bytes (interpreted as unsigned char). If n is zero,
 *         the return value is zero.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * The ft_memcpy() function copies n bytes from memory area src to
 * memory area dest. The memory areas must not overlap. Use ft_memmove()
 * if the memory areas do overlap.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * 
 * @return A pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * The ft_memmove() function copies n bytes from memory area src to
 * memory area dest. The memory areas may overlap: copying takes place
 * as though the bytes in src are first copied into a temporary array
 * that does not overlap src or dest, and the bytes are then copied from
 * the temporary array to dest.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * 
 * @return A pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Fills memory with a constant byte.
 *
 * The ft_memset() function fills the first n bytes of the memory area
 * pointed to by s with the constant byte c.
 *
 * @param pointer Pointer to the memory area to be filled.
 * @param val The constant byte to fill the memory with.
 * @param n Number of bytes to fill.
 * 
 * @return A pointer to the memory area s.
 */
void	*ft_memset(void *pointer, int val, size_t n);

/**
 * @brief Allocates memory for an array of elements and initializes it to zero.
 *
 * The ft_calloc() function allocates unused space for an array of number
 * elements, each of whose size in bytes is size. The space is initialized
 * to all bits 0.
 *
 * @param number The number of elements to allocate.
 * @param size The size of each element.
 * 
 * @return A pointer to the allocated space, or NULL if the allocation fails.
 */
void	*ft_calloc(size_t number, size_t size);

/**
 * @brief Tests whether a character is alphanumeric.
 *
 * The ft_isalnum() function tests whether the character c is an alphanumeric
 * character, meaning it is either a letter (alphabetic character) or a digit.
 *
 * @param c The character to test, represented as an int. The value should be
 *          representable as an unsigned char. Any other value results in
 *          undefined behavior.
 * 
 * @return A non-zero value if c is an alphanumeric character; 0 otherwise.
 */
int		ft_isalnum(int c);

/**
 * @brief Tests whether a character is alphabetic.
 *
 * The ft_isalpha() function checks whether the character c is an alphabetic
 * character, which includes both uppercase and lowercase letters.
 *
 * @param c The character to test, represented as an int. The value should be
 *          representable as an unsigned char. Any other value results in
 *          undefined behavior.
 * 
 * @return A non-zero value if c is an alphabetic character; 0 otherwise.
 */
int		ft_isalpha(int c);

/**
 * @brief Tests whether a character is a valid ASCII character.
 *
 * The ft_isascii() function checks whether the character c is a 7-bit unsigned
 * char value that fits into the ASCII character set.
 *
 * @param c The character to test, represented as an int. The value should be
 *          representable as an unsigned char. Any other value results in
 *          undefined behavior.
 * 
 * @return A non-zero value if c is a valid ASCII character; 0 otherwise.
 */
int		ft_isascii(int c);

/**
 * @brief Tests whether a character is a digit.
 *
 * The ft_isdigit() function checks whether the character c is a digit
 *
 * @param c The character to test, represented as an int. The value should be
 *          representable as an unsigned char. Any other value results in
 *          undefined behavior.
 * 
 * @return A non-zero value if c is a digit; 0 otherwise.
 */
int		ft_isdigit(int c);

/**
 * @brief Tests whether a character is printable.
 *
 * The ft_isprint() function checks whether the character c is any printable
 * character, including space.
 *
 * @param c The character to test, represented as an int. The value should be
 *          representable as an unsigned char. Any other value results in
 *          undefined behavior.
 * 
 * @return A non-zero value if c is a printable character; 0 otherwise.
 */
int		ft_isprint(int c);




size_t	ft_strlen(const char *str);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);


void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);





typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
