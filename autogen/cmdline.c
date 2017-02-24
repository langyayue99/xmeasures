/*
  File autogenerated by gengetopt version 2.22.6
  generated with the following command:
  gengetopt --output-dir autogen -i args.ggo --default-optional --unamed-opts=clusterings

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FIX_UNUSED
#define FIX_UNUSED(X) (void) (X) /* avoid warnings for unused params */
#endif

#include <getopt.h>

#include "cmdline.h"

const char *gengetopt_args_info_purpose = "Extrinsic measures evaluation for overlapping multi-resolution clusterings with\npossible unequal node base: F1_gm and NMI.";

const char *gengetopt_args_info_usage = "Usage: xmeasures [OPTIONS] clustering1 clustering2\n\n  clustering  - input file, collection of the clusters to be evaluated.";

const char *gengetopt_args_info_versiontext = "";

const char *gengetopt_args_info_description = "";

const char *gengetopt_args_info_help[] = {
  "  -h, --help              Print help and exit",
  "  -V, --version           Print version and exit",
  "  -m, --membership=FLOAT  average expected membership of the nodes in the\n                            clusters, > 0, typically >= 1  (default=`1')",
  "\n Mode: f1\n  F1 evaluation of the [weighted] average of the greatest (maximal) match by F1\n  or partial probability.\n  F1 evaluates clusters on multiple resolutions and applicable for overlapping\n  clustering only as approximate evaluation.\n  NOTE: unequal node base in clusterings is allowed, but it penalizes the\n  match.",
  "  -f, --f1f1              evaluate F1 of the [weighted] average of the greatest\n                            (maximal) match by F1  (default=off)",
  "  -p, --f1pp              evaluate F1 of the [weighted] average of the greatest\n                            (maximal) match by partial probability.\n                            NOTE: typically F1pp < F1f1 and fits to evaluate\n                            similar collections  (default=off)",
  "  -u, --unweighted        evaluate simple average of the best matches instead\n                            of weighted by the cluster size  (default=off)",
  "\n Mode: nmi\n  NMI (Normalized Mutual Information) evaluation.\n  Standard NMI is evaluated, which is not applicable for overlapping or\n  multi-resolution clustering.\n  NOTE: unequal node base in clusterings is allowed, but automatically\n  syncronized, skipping the nodes belonging to a single collection.",
  "  -n, --nmi               evaluate NMI  (default=off)",
  "  -e, --ln                use ln (exp base) instead of log2 (Shannon entropy,\n                            bits) for the information measuring  (default=off)",
    0
};

typedef enum {ARG_NO
  , ARG_FLAG
  , ARG_FLOAT
} cmdline_parser_arg_type;

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error);


static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->membership_given = 0 ;
  args_info->f1f1_given = 0 ;
  args_info->f1pp_given = 0 ;
  args_info->unweighted_given = 0 ;
  args_info->nmi_given = 0 ;
  args_info->ln_given = 0 ;
  args_info->f1_mode_counter = 0 ;
  args_info->nmi_mode_counter = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  FIX_UNUSED (args_info);
  args_info->membership_arg = 1;
  args_info->membership_orig = NULL;
  args_info->f1f1_flag = 0;
  args_info->f1pp_flag = 0;
  args_info->unweighted_flag = 0;
  args_info->nmi_flag = 0;
  args_info->ln_flag = 0;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{


  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->membership_help = gengetopt_args_info_help[2] ;
  args_info->f1f1_help = gengetopt_args_info_help[4] ;
  args_info->f1pp_help = gengetopt_args_info_help[5] ;
  args_info->unweighted_help = gengetopt_args_info_help[6] ;
  args_info->nmi_help = gengetopt_args_info_help[8] ;
  args_info->ln_help = gengetopt_args_info_help[9] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n",
     (strlen(CMDLINE_PARSER_PACKAGE_NAME) ? CMDLINE_PARSER_PACKAGE_NAME : CMDLINE_PARSER_PACKAGE),
     CMDLINE_PARSER_VERSION);

  if (strlen(gengetopt_args_info_versiontext) > 0)
    printf("\n%s\n", gengetopt_args_info_versiontext);
}

static void print_help_common(void) {
  cmdline_parser_print_version ();

  if (strlen(gengetopt_args_info_purpose) > 0)
    printf("\n%s\n", gengetopt_args_info_purpose);

  if (strlen(gengetopt_args_info_usage) > 0)
    printf("\n%s\n", gengetopt_args_info_usage);

  printf("\n");

  if (strlen(gengetopt_args_info_description) > 0)
    printf("%s\n\n", gengetopt_args_info_description);
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  print_help_common();
  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);

  args_info->inputs = 0;
  args_info->inputs_num = 0;
}

void
cmdline_parser_params_init(struct cmdline_parser_params *params)
{
  if (params)
    { 
      params->override = 0;
      params->initialize = 1;
      params->check_required = 1;
      params->check_ambiguity = 0;
      params->print_errors = 1;
    }
}

struct cmdline_parser_params *
cmdline_parser_params_create(void)
{
  struct cmdline_parser_params *params = 
    (struct cmdline_parser_params *)malloc(sizeof(struct cmdline_parser_params));
  cmdline_parser_params_init(params);  
  return params;
}

static void
free_string_field (char **s)
{
  if (*s)
    {
      free (*s);
      *s = 0;
    }
}


static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{
  unsigned int i;
  free_string_field (&(args_info->membership_orig));
  
  
  for (i = 0; i < args_info->inputs_num; ++i)
    free (args_info->inputs [i]);

  if (args_info->inputs_num)
    free (args_info->inputs);

  clear_given (args_info);
}


static void
write_into_file(FILE *outfile, const char *opt, const char *arg, const char *values[])
{
  FIX_UNUSED (values);
  if (arg) {
    fprintf(outfile, "%s=\"%s\"\n", opt, arg);
  } else {
    fprintf(outfile, "%s\n", opt);
  }
}


int
cmdline_parser_dump(FILE *outfile, struct gengetopt_args_info *args_info)
{
  int i = 0;

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot dump options to stream\n", CMDLINE_PARSER_PACKAGE);
      return EXIT_FAILURE;
    }

  if (args_info->help_given)
    write_into_file(outfile, "help", 0, 0 );
  if (args_info->version_given)
    write_into_file(outfile, "version", 0, 0 );
  if (args_info->membership_given)
    write_into_file(outfile, "membership", args_info->membership_orig, 0);
  if (args_info->f1f1_given)
    write_into_file(outfile, "f1f1", 0, 0 );
  if (args_info->f1pp_given)
    write_into_file(outfile, "f1pp", 0, 0 );
  if (args_info->unweighted_given)
    write_into_file(outfile, "unweighted", 0, 0 );
  if (args_info->nmi_given)
    write_into_file(outfile, "nmi", 0, 0 );
  if (args_info->ln_given)
    write_into_file(outfile, "ln", 0, 0 );
  

  i = EXIT_SUCCESS;
  return i;
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  i = cmdline_parser_dump(outfile, args_info);
  fclose (outfile);

  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}

/** @brief replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = 0;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char **argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser_ext (int argc, char **argv, struct gengetopt_args_info *args_info,
                   struct cmdline_parser_params *params)
{
  int result;
  result = cmdline_parser_internal (argc, argv, args_info, params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser2 (int argc, char **argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;
  struct cmdline_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  result = cmdline_parser_internal (argc, argv, args_info, &params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  FIX_UNUSED (args_info);
  FIX_UNUSED (prog_name);
  return EXIT_SUCCESS;
}


static char *package_name = 0;

/**
 * @brief updates an option
 * @param field the generic pointer to the field to update
 * @param orig_field the pointer to the orig field
 * @param field_given the pointer to the number of occurrence of this option
 * @param prev_given the pointer to the number of occurrence already seen
 * @param value the argument for this option (if null no arg was specified)
 * @param possible_values the possible values for this option (if specified)
 * @param default_value the default value (in case the option only accepts fixed values)
 * @param arg_type the type of this option
 * @param check_ambiguity @see cmdline_parser_params.check_ambiguity
 * @param override @see cmdline_parser_params.override
 * @param no_free whether to free a possible previous value
 * @param multiple_option whether this is a multiple option
 * @param long_opt the corresponding long option
 * @param short_opt the corresponding short option (or '-' if none)
 * @param additional_error possible further error specification
 */
static
int update_arg(void *field, char **orig_field,
               unsigned int *field_given, unsigned int *prev_given, 
               char *value, const char *possible_values[],
               const char *default_value,
               cmdline_parser_arg_type arg_type,
               int check_ambiguity, int override,
               int no_free, int multiple_option,
               const char *long_opt, char short_opt,
               const char *additional_error)
{
  char *stop_char = 0;
  const char *val = value;
  int found;
  FIX_UNUSED (field);

  stop_char = 0;
  found = 0;

  if (!multiple_option && prev_given && (*prev_given || (check_ambiguity && *field_given)))
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: `--%s' (`-%c') option given more than once%s\n", 
               package_name, long_opt, short_opt,
               (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: `--%s' option given more than once%s\n", 
               package_name, long_opt,
               (additional_error ? additional_error : ""));
      return 1; /* failure */
    }

  FIX_UNUSED (default_value);
    
  if (field_given && *field_given && ! override)
    return 0;
  if (prev_given)
    (*prev_given)++;
  if (field_given)
    (*field_given)++;
  if (possible_values)
    val = possible_values[found];

  switch(arg_type) {
  case ARG_FLAG:
    *((int *)field) = !*((int *)field);
    break;
  case ARG_FLOAT:
    if (val) *((float *)field) = (float)strtod (val, &stop_char);
    break;
  default:
    break;
  };

  /* check numeric conversion */
  switch(arg_type) {
  case ARG_FLOAT:
    if (val && !(stop_char && *stop_char == '\0')) {
      fprintf(stderr, "%s: invalid numeric value: %s\n", package_name, val);
      return 1; /* failure */
    }
    break;
  default:
    ;
  };

  /* store the original value */
  switch(arg_type) {
  case ARG_NO:
  case ARG_FLAG:
    break;
  default:
    if (value && orig_field) {
      if (no_free) {
        *orig_field = value;
      } else {
        if (*orig_field)
          free (*orig_field); /* free previous string */
        *orig_field = gengetopt_strdup (value);
      }
    }
  };

  return 0; /* OK */
}


static int check_modes(
  int given1[], const char *options1[],
                       int given2[], const char *options2[])
{
  int i = 0, j = 0, errors = 0;
  
  while (given1[i] >= 0) {
    if (given1[i]) {
      while (given2[j] >= 0) {
        if (given2[j]) {
          ++errors;
          fprintf(stderr, "%s: option %s conflicts with option %s\n",
                  package_name, options1[i], options2[j]);
        }
        ++j;
      }
    }
    ++i;
  }
  
  return errors;
}

int
cmdline_parser_internal (
  int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error_occurred = 0;
  struct gengetopt_args_info local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  package_name = argv[0];
  
  override = params->override;
  initialize = params->initialize;
  check_required = params->check_required;
  check_ambiguity = params->check_ambiguity;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = params->print_errors;
  optopt = '?';

  while (1)
    {
      int option_index = 0;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "membership",	1, NULL, 'm' },
        { "f1f1",	0, NULL, 'f' },
        { "f1pp",	0, NULL, 'p' },
        { "unweighted",	0, NULL, 'u' },
        { "nmi",	0, NULL, 'n' },
        { "ln",	0, NULL, 'e' },
        { 0,  0, 0, 0 }
      };

      c = getopt_long (argc, argv, "hVm:fpune", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cmdline_parser_print_help ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
          cmdline_parser_print_version ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'm':	/* average expected membership of the nodes in the clusters, > 0, typically >= 1.  */
        
        
          if (update_arg( (void *)&(args_info->membership_arg), 
               &(args_info->membership_orig), &(args_info->membership_given),
              &(local_args_info.membership_given), optarg, 0, "1", ARG_FLOAT,
              check_ambiguity, override, 0, 0,
              "membership", 'm',
              additional_error))
            goto failure;
        
          break;
        case 'f':	/* evaluate F1 of the [weighted] average of the greatest (maximal) match by F1.  */
          args_info->f1_mode_counter += 1;
        
        
          if (update_arg((void *)&(args_info->f1f1_flag), 0, &(args_info->f1f1_given),
              &(local_args_info.f1f1_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "f1f1", 'f',
              additional_error))
            goto failure;
        
          break;
        case 'p':	/* evaluate F1 of the [weighted] average of the greatest (maximal) match by partial probability.
        NOTE: typically F1pp < F1f1 and fits to evaluate similar collections.  */
          args_info->f1_mode_counter += 1;
        
        
          if (update_arg((void *)&(args_info->f1pp_flag), 0, &(args_info->f1pp_given),
              &(local_args_info.f1pp_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "f1pp", 'p',
              additional_error))
            goto failure;
        
          break;
        case 'u':	/* evaluate simple average of the best matches instead of weighted by the cluster size.  */
          args_info->f1_mode_counter += 1;
        
        
          if (update_arg((void *)&(args_info->unweighted_flag), 0, &(args_info->unweighted_given),
              &(local_args_info.unweighted_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "unweighted", 'u',
              additional_error))
            goto failure;
        
          break;
        case 'n':	/* evaluate NMI.  */
          args_info->nmi_mode_counter += 1;
        
        
          if (update_arg((void *)&(args_info->nmi_flag), 0, &(args_info->nmi_given),
              &(local_args_info.nmi_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "nmi", 'n',
              additional_error))
            goto failure;
        
          break;
        case 'e':	/* use ln (exp base) instead of log2 (Shannon entropy, bits) for the information measuring.  */
          args_info->nmi_mode_counter += 1;
        
        
          if (update_arg((void *)&(args_info->ln_flag), 0, &(args_info->ln_given),
              &(local_args_info.ln_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "ln", 'e',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */



  if (args_info->f1_mode_counter && args_info->nmi_mode_counter) {
    int f1_given[] = {args_info->f1f1_given, args_info->f1pp_given, args_info->unweighted_given,  -1};
    const char *f1_desc[] = {"--f1f1", "--f1pp", "--unweighted",  0};
    int nmi_given[] = {args_info->nmi_given, args_info->ln_given,  -1};
    const char *nmi_desc[] = {"--nmi", "--ln",  0};
    error_occurred += check_modes(f1_given, f1_desc, nmi_given, nmi_desc);
  }
  

  cmdline_parser_release (&local_args_info);

  if ( error_occurred )
    return (EXIT_FAILURE);

  if (optind < argc)
    {
      int i = 0 ;
      int found_prog_name = 0;
      /* whether program name, i.e., argv[0], is in the remaining args
         (this may happen with some implementations of getopt,
          but surely not with the one included by gengetopt) */

      i = optind;
      while (i < argc)
        if (argv[i++] == argv[0]) {
          found_prog_name = 1;
          break;
        }
      i = 0;

      args_info->inputs_num = argc - optind - found_prog_name;
      args_info->inputs =
        (char **)(malloc ((args_info->inputs_num)*sizeof(char *))) ;
      while (optind < argc)
        if (argv[optind++] != argv[0])
          args_info->inputs[ i++ ] = gengetopt_strdup (argv[optind-1]) ;
    }

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}
