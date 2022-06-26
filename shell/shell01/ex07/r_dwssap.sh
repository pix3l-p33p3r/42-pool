# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    r_dwssap.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elel-yak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 11:59:07 by elel-yak          #+#    #+#              #
#    Updated: 2022/06/25 12:00:19 by elel-yak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cat /etc/passwd | sed '/^#/d' | awk 'NR % 2 == 0 {print $0}' | awk -F ":" '{  print $1 }' | rev | sort -fnr | awk -v FT_LINE1="$FT_LINE1" -v FT_LINE2="$FT_LINE2"  'NR >= FT_LINE1 && NR <= FT_LINE2 { print $0 }' | tr '\n' ' '  | sed 's+ +, +g' | sed 's+, $+.+g' | tr -d '\n'
