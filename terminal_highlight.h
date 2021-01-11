/*
 * Extracted data definition for Terminal highlighting
 */

#ifndef PUTTY_TERMINAL_HL_H
#define PUTTY_TERMINAL_HL_H

#define PCRE_STATIC
#include <pcre.h>

/* Maximum length of a Terminal line, this will avoid dynamic memory allocation */
#define HL_MAX_LINE 512
/* Initialize all the stuff */
static void hl_init(char *hl_pats[]);
/* Process line */
static void hl_process_line(Terminal *term, termline *line);
/* RE array */
static pcre **hl_re;
/* RE extras array */
static pcre_extra **hl_rec;
/* Statically scoped number of patterns */
static int hl_pats_num;

/* Storage for RE patterns of interest */
static char *hl_pats[] = {
   /* lime */
   "\\b(establish|started|done|true|yes|ok|healthy?|accept|allow|enable?|"
      "connect|success(full?y?)?|succeed)(ed)?\\b",

   /* pink */
   "(?-i)\\s(localhost\\d*|"
      "\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})(:\\d+)?\\s",

   /* todo */
   "\\b(caught signal \\d+|cannot|(connection (to (remote host|[a-z0-9.]+) )"
      "?)?(closed|terminated|stopped|not responding)|exited|no more \\w+ "
      "available|unexpected|(command |binary |file )?not found|(o)+ps|"
      "out of (space|memory)|low (memory|disk)|unknown|disabled?|deprecated|"
      "refused|disconnect(ed|ion)?|attention|warn(ings?)?|alerts?|"
      "\\([w?]{2}\\)|could not|unable to)\\b",

   /* white */
   "\\s\\#\\w+|\\[log_id:\\s+\\d+\\]",

   /* coal */
   "\\[\\d+\\(\\d+\\s+nb_truck_\\d+\\)\\]|\\b\\d{4}-\\d{2}-\\d{2}\\s\\d{2}:"
      "\\d{2}:\\S+\\s+\\S+\\s+xtremapp(-\\w+)?:\\s+",

   /* lightblue */
   "\\b(\\d{4}-\\d{2}-\\d{2}\\s\\d{2}:\\d{2}:\\S+)",

   /* cyan */
   "\\b(launch|check|load|creat|build|important|boot|starting|notice|"
      "info(rmation(al)?)?|note)(ing)?\\b",

   /* umber */
   "\\b((false|bad|wrong|incorrect|improper|invalid|unsupported|bad)( file|"
      " memory)? (descriptor|alloc(ation)?|addr(ess)?|owner(ship)?|arg(ument)"
      "?|param(eter)?|setting|length|filename)|not properly|improperly|"
      "(operation |connection |authentication |access |permission )?(denied|"
      "disallowed|not allowed|refused|problem|failed|failure|not permitted)|"
      "no \\w+( \\w+)? found|invalid|unsupported|not supported|"
      "seg(mentation )?fault|corruption|corrupted|corrupt|overflow|underrun|"
      "not ok|unimplemented|unsuccessfull|not implemented|errors?)\\b",

   /* alert */
   "\\b(kernel (bug|panic)|fatal|crit([\\s>]\\d{4}-\\d{2}-\\d{2}\\s+\\S+)?|"
      "fail(ical|ing|ure|ed)?)\\b",

   /* sky */
   "(?-i)\\s[MXRCDP]\\d{0,2}\\s",

   0
};

typedef struct hl_opts {
   unsigned char
      /* Enabled bit */
      bg, fg,
      /* Set of colors 0..255 */
      bg_r, bg_g, bg_b, fg_r, fg_g, fg_b;
} hl_opts_t;

/* Storage for RE options, each option corresponds to hl_pats[] */
static hl_opts_t hl_opts[] = {
   /* lime */
   {0, 1, 0x00, 0x00, 0x00, 0x55, 0xFF, 0x55},

   /* pink */
   {0, 1, 0x00, 0x00, 0x00, 0xFF, 0x55, 0xFF},

   /* todo */
   {1, 1, 0xBB, 0xBB, 0x00, 0x01, 0x01, 0x01},

   /* white */
   {0, 1, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF},

   /* coal */
   {0, 1, 0x00, 0x00, 0x00, 0x55, 0x55, 0x55},

   /* lightblue */
   {0, 1, 0x00, 0x00, 0x00, 0x00, 0xBB, 0xBB},

   /* cyan */
   {0, 1, 0x00, 0x00, 0x00, 0x55, 0xFF, 0xFF},

   /* umber */
   {0, 1, 0x00, 0x00, 0x00, 0xFF, 0x55, 0x55},

   /* alert */
   {1, 1, 0xBB, 0x00, 0x00, 0xFF, 0xFF, 0x55},

   /* sky */
   {0, 1, 0x00, 0x00, 0x00, 0x55, 0x55, 0xFF}

   /* 0 */
};

#endif
