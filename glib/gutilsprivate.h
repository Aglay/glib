/*
 * Copyright © 2018 Endless Mobile, Inc.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Philip Withnall <withnall@endlessm.com>
 */

#ifndef __G_UTILS_PRIVATE_H__
#define __G_UTILS_PRIVATE_H__

#include "glibconfig.h"
#include "gtypes.h"
#include "gtestutils.h"

G_BEGIN_DECLS

GLIB_AVAILABLE_IN_2_60
void g_set_user_dirs (const gchar *first_dir_type,
                      ...) G_GNUC_NULL_TERMINATED;

GLIB_AVAILABLE_IN_2_76
char * g_find_program_for_path (const char *program,
                                const char *path,
                                const char *working_dir);

/* Returns the smallest power of 2 greater than or equal to n,
 * or 0 if such power does not fit in a gsize
 */
static inline gsize
g_nearest_pow (gsize num)
{
  gsize n = num - 1;

  g_assert (num > 0 && num <= G_MAXSIZE / 2);

  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
#if GLIB_SIZEOF_SIZE_T == 8
  n |= n >> 32;
#endif

  return n + 1;
}

void _g_unset_cached_tmp_dir (void);

G_END_DECLS

#endif /* __G_UTILS_PRIVATE_H__ */
