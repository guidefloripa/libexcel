/*
 * Copyright (c) 2010-2011 Devin Smith <devin@devinsmith.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "excel.h"

int main(int argc, char *argv[])
{
  struct wbookctx *wbook;
  struct wsheetctx *sheet;
  struct xl_format *fmt;

  /* Create a new Excel Workbook */
  wbook = wbook_new("merge1.xls", 0);
  sheet = wbook_addworksheet(wbook, NULL);

  /* Set the column width for columns 2 and 3 */
  wsheet_set_column(sheet, 1, 3, 20);
  /* Set the row height for row 2 */
  wsheet_set_row(sheet, 2, 30, NULL);

  fmt = wbook_addformat(wbook);
  fmt_set_merge(fmt);

  xls_writef_string(sheet, 2, 1, "Merged Cells", fmt);
  xls_write_blank(sheet, 2, 2, fmt);
  xls_write_blank(sheet, 2, 3, fmt);

  wbook_close(wbook);
  wbook_destroy(wbook);

  return 0;
}
